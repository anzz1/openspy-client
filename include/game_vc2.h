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
    if (ogethostbyname)
      detour_iat_func(hmod, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(hmod, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(hmod, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(hmod, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);
  }
  hmod = GetModuleHandleA("logs.dll");
  if (hmod) {
    if (ogethostbyname)
      detour_iat_func(hmod, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(hmod, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(hmod, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(hmod, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
  }
}

static void patch_vc2() {
  vc2_hook_gs();
}

#endif // __GAME_VC2_H
