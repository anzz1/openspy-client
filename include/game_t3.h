// game_t3.h

#ifndef __GAME_T3_H
#define __GAME_T3_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void t3_hook_mod(HMODULE mod) {
    if (ogethostbyname)
      detour_iat_func(mod, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(mod, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);

    if (ogethostbyname)
      detour_iat_func(mod, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(mod, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(mod, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(mod, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);

    if (obind)
      detour_iat_func(mod, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(mod, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
}

HMODULE __stdcall t3_hk_LoadLibraryA(LPCSTR lpLibFileName) {
  HMODULE mod = 0;
  const char* name = __strrchr(lpLibFileName, '\\');
  if (name)
    name++;
  else
    name = lpLibFileName;

  mod = oLoadLibraryA(lpLibFileName);
  if (mod && (!__stricmp(name, "ai.dll")))
    t3_hook_mod(mod);

  return mod;
}

__forceinline static void t3_hook_gs() {
  HMODULE mod;

  t3_hook_mod(0);

  if (oLoadLibraryA)
    detour_iat_func(0, "LoadLibraryA", (void*)t3_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);
  else
    oLoadLibraryA = (LoadLibraryA_fn)detour_iat_func(0, "LoadLibraryA", (void*)t3_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);

  mod = GetModuleHandleA("ai.dll");
  if (mod)
    t3_hook_mod(mod);
}

__noinline static void patch_t3() {
  t3_hook_gs();
}

#endif // __GAME_T3_H
