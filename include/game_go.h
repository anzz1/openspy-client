// game_go.h

#ifndef __GAME_GO_H
#define __GAME_GO_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void go_hook_mod(HMODULE mod) {
  if (ogethostbyname)
    detour_iat_func(mod, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);
  else
    ogethostbyname = (gethostbyname_fn)detour_iat_func(mod, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);

  if (obind)
    detour_iat_func(mod, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
  else
    obind = (bind_fn)detour_iat_func(mod, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
}

HMODULE __stdcall go_hk_LoadLibraryA(LPCSTR lpLibFileName) {
  HMODULE mod = 0;
  const char* name = __strrchr(lpLibFileName, '\\');
  if (name)
    name++;
  else
    name = lpLibFileName;

  mod = oLoadLibraryA(lpLibFileName);
  if (mod && (!__stricmp(name, "cshell.dll") || !__stricmp(name, "object.lto")))
    go_hook_mod(mod);

  return mod;
}

__forceinline static void go_hook_gs() {
  HMODULE mod;

  if (oLoadLibraryA)
    detour_iat_func(0, "LoadLibraryA", (void*)go_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);
  else
    oLoadLibraryA = (LoadLibraryA_fn)detour_iat_func(0, "LoadLibraryA", (void*)go_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);

  mod = GetModuleHandleA("server.dll");
  if (mod) {
    go_hook_mod(mod);
    if (oLoadLibraryA)
      detour_iat_func(mod, "LoadLibraryA", (void*)go_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);
    else
      oLoadLibraryA = (LoadLibraryA_fn)detour_iat_func(mod, "LoadLibraryA", (void*)go_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);
  }

  mod = GetModuleHandleA("cshell.dll");
  if (mod)
    go_hook_mod(mod);

  mod = GetModuleHandleA("object.lto");
  if (mod)
    go_hook_mod(mod);
}

// Allow multiple instances (f.ex. dedicated server & game at the same time)
__forceinline static void go_patch_multi_instance() {
  BYTE* ptr = 0;
  BYTE search[] = {0xA3,0xC0,0x44,0x53,0x00,0xFF,0x15,0x38,0x81,0x51,0x00,0x3D,0xB7,0x00,0x00,0x00,0x75,0x1B,0x53};
  BYTE patch[] = {0x90,0x90,0x90,0x90,0x90,0xEB};

  ptr = find_pattern_mem(0, search, search + 18, TRUE);
  if (ptr)
    write_mem(ptr+11, patch, sizeof(patch));
}

__noinline static void patch_go() {
  go_hook_gs();
  go_patch_multi_instance();
}

#endif // __GAME_GO_H
