// game_swrc.h

#ifndef __GAME_SWRC_H
#define __GAME_SWRC_H

#include "include/global.h"
#include "include/shared.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void swrc_hook_gs() {
  HMODULE hmod = GetModuleHandleA("GameSpyMgr.dll");
  if (hmod) {
    HOOK_FUNC(hmod, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(hmod, bind, hk_bind, "wsock32.dll", 2, TRUE);
  }
}

__noinline static void patch_swrc() {
  swrc_hook_gs();
  ue2_patch_ipdrv();
}

#endif // __GAME_SWRC_H
