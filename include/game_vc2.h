// game_vc2.h

#ifndef __GAME_VC2_H
#define __GAME_VC2_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void vc2_hook_gs() {
  HMODULE hmod = GetModuleHandleA("game.dll");
  if (hmod) {
    HOOK_FUNC(hmod, gethostbyname, hk_gethostbyname, "ws2_32.dll", 52, TRUE);
    HOOK_FUNC(hmod, bind, hk_bind, "ws2_32.dll", 2, TRUE);
  }
  hmod = GetModuleHandleA("logs.dll");
  if (hmod) {
    HOOK_FUNC(hmod, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(hmod, bind, hk_bind, "wsock32.dll", 2, TRUE);
  }
}

__noinline static void patch_vc2() {
  vc2_hook_gs();
}

#endif // __GAME_VC2_H
