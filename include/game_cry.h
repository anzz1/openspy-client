// game_cry.h

#ifndef __GAME_CRY_H
#define __GAME_CRY_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void cry_hook_gs() {
  HMODULE crynet = GetModuleHandleA("CryNetwork.dll");
  if (crynet) {
    if (ogethostbyname)
      detour_iat_func(crynet, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(crynet, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(crynet, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(crynet, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
  }
}

static void patch_cry() {
  cry_hook_gs();
}

#endif // __GAME_CRY_H
