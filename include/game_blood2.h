// game_blood2.h

#ifndef __GAME_BLOOD2_H
#define __GAME_BLOOD2_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void blood2_hook_mod(HMODULE mod) {
  HOOK_FUNC(mod, gethostbyname, hk_gethostbyname, "ws2_32.dll", 52, TRUE);
  HOOK_FUNC(mod, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
  HOOK_FUNC(mod, bind, hk_bind, "ws2_32.dll", 2, TRUE);
  HOOK_FUNC(mod, bind, hk_bind, "wsock32.dll", 2, TRUE);
}

HMODULE __stdcall blood2_hk_LoadLibraryA(LPCSTR lpLibFileName) {
  HMODULE mod = 0;
  const char* name = __strrchr(lpLibFileName, '\\');
  if (name)
    name++;
  else
    name = lpLibFileName;

  mod = oLoadLibraryA(lpLibFileName);
  if (mod && (!__stricmp(name, "server.dll")))
    blood2_hook_mod(mod);

  return mod;
}

__forceinline static void blood2_hook_gs() {
  HMODULE mod;

  blood2_hook_mod(0);
  HOOK_FUNC(0, LoadLibraryA, blood2_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);

  mod = GetModuleHandleA("server.dll");
  if (mod)
    blood2_hook_mod(mod);
}

__noinline static void patch_blood2() {
  blood2_hook_gs();
}

#endif // __GAME_BLOOD2_H
