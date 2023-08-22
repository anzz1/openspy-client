// game_dh2k.h

#ifndef __GAME_DH2K_H
#define __GAME_DH2K_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void dh2k_hook_gs() {
  HMODULE aspen = GetModuleHandleA("Aspen.dll");
  if (aspen) {
    if (ogethostbyname)
      detour_iat_func(aspen, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(aspen, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(aspen, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(aspen, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
  }
}

__noinline static void patch_dh2k() {
  dh2k_hook_gs();
}

#endif // __GAME_DH2K_H
