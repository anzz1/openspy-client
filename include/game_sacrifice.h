// game_sacrifice.h

#ifndef __GAME_SACRIFICE_H
#define __GAME_SACRIFICE_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

HMODULE __stdcall sacrifice_hk_LoadLibraryA(LPCSTR lpLibFileName) {
  HMODULE mod = 0;
  const char* name = __strrchr(lpLibFileName, '\\');
  if (name)
    name++;
  else
    name = lpLibFileName;

  mod = oLoadLibraryA(lpLibFileName);
  if (mod && (!__stricmp(name, "gamespy.dll"))) {
    HOOK_FUNC(mod, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(mod, bind, hk_bind, "wsock32.dll", 2, TRUE);
  }

  return mod;
}

__forceinline static void sacrifice_hook_gs() {
  HMODULE mod = GetModuleHandleA("share.dll");
  if (mod) {
    HOOK_FUNC(mod, LoadLibraryA, sacrifice_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);
  }
}

__noinline static void patch_sacrifice() {
  sacrifice_hook_gs();
}

#endif // __GAME_SACRIFICE_H
