// game_aowht.h

#ifndef __GAME_AOWHT_H
#define __GAME_AOWHT_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void aowht_hook_gs() {
  HMODULE gsdll = LoadLibraryA("GameSpyDLL.dll");
  if (gsdll) {
    if (ogethostbyname)
      detour_iat_func(gsdll, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(gsdll, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(gsdll, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(gsdll, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);

    GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)gsdll, &gsdll);
  }
}

__noinline static void patch_aowht() {
  aowht_hook_gs();
}

#endif // __GAME_AOWHT_H
