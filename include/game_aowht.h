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
    HOOK_FUNC(gsdll, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(gsdll, bind, hk_bind, "wsock32.dll", 2, TRUE);

    GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)gsdll, &gsdll);
  }
}

__noinline static void patch_aowht() {
  aowht_hook_gs();
}

#endif // __GAME_AOWHT_H
