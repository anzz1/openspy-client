// game_nolf.h

#ifndef __GAME_NOLF_H
#define __GAME_NOLF_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void nolf_srv_hook_gs() {
  HMODULE mod = GetModuleHandleA("server.dll");
  if (mod) {
    HOOK_FUNC(mod, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(mod, bind, hk_bind, "wsock32.dll", 2, TRUE);
  }
}

__noinline static void patch_nolf_srv() {
  nolf_srv_hook_gs();
}

#endif // __GAME_NOLF_H
