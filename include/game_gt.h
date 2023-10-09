// game_gt.h

#ifndef __GAME_GT_H
#define __GAME_GT_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void gt_hook_gs() {
  HMODULE hmod = GetModuleHandleA("cloakntengine.dll");
  if (hmod) {
    HOOK_FUNC(hmod, gethostbyname, hk_gethostbyname, "ws2_32.dll", 52, TRUE);
    HOOK_FUNC(hmod, bind, hk_bind, "ws2_32.dll", 2, TRUE);
  }
}

__noinline static void patch_gt() {
  gt_hook_gs();
}

#endif // __GAME_GT_H
