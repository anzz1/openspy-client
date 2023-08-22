// game_sam.h

#ifndef __GAME_SAM_H
#define __GAME_SAM_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void sam_hook_gs() {
  HMODULE hmod = GetModuleHandleA("Engine.dll");
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
  hmod = GetModuleHandleA("Core.dll");
  if (hmod) {
    hmod = GetModuleHandleA("OnlineGS.dll");
    if (!hmod)
      hmod = LoadLibraryA("OnlineGS.dll");
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
}

__noinline static void patch_sam() {
  sam_hook_gs();
}

#endif // __GAME_SAM_H
