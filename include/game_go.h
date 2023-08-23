// game_go.h

#ifndef __GAME_GO_H
#define __GAME_GO_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

HMODULE __stdcall go_hk_LoadLibraryA(LPCSTR lpLibFileName) {
  HMODULE mod = 0;
  const char* name = __strrchr(lpLibFileName, '\\');
  if (name)
    name++;
  else
    name = lpLibFileName;

  mod = oLoadLibraryA(lpLibFileName);
  if (mod && (!__stricmp(name, "cshell.dll") || !__stricmp(name, "object.lto"))) {
    HOOK_FUNC(mod, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(mod, bind, hk_bind, "wsock32.dll", 2, TRUE);
  }

  return mod;
}

__forceinline static void go_hook_gs() {
  HMODULE mod;

  HOOK_FUNC(0, LoadLibraryA, go_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);

  mod = GetModuleHandleA("server.dll");
  if (mod) {
    HOOK_FUNC(mod, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(mod, bind, hk_bind, "wsock32.dll", 2, TRUE);
    HOOK_FUNC(mod, LoadLibraryA, go_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);
  }

  mod = GetModuleHandleA("cshell.dll");
  if (mod) {
    HOOK_FUNC(mod, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(mod, bind, hk_bind, "wsock32.dll", 2, TRUE);
  }

  mod = GetModuleHandleA("object.lto");
  if (mod) {
    HOOK_FUNC(mod, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(mod, bind, hk_bind, "wsock32.dll", 2, TRUE);
  }
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
