// game_bond.h

#ifndef __GAME_BOND_H
#define __GAME_BOND_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void bond_hook_gs() {
  HMODULE engine = GetModuleHandleA("engine.dll");
  if (!engine)
    engine = LoadLibraryA("engine.dll");
  if (engine) {
    HOOK_FUNC(engine, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(engine, bind, hk_bind, "wsock32.dll", 2, TRUE);
  }
}

__noinline static void patch_bond() {
  bond_hook_gs();
}

#endif // __GAME_BOND_H
