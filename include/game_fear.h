// game_fear.h

#ifndef __GAME_FEAR_H
#define __GAME_FEAR_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

// TODO
//
// client: 
//   not currently working with unmodified retail latest v1.08, as fearmp.exe is protected by SecuROM v7.24.0009 which fks us
//   should work with securom removed, but untested
//
// server:
//   server works fine when connected to internet and masterserver is online, but we still need to patch "Unable to use the selected network service"
//   error to allow offline LAN play
//

__forceinline static void fearserver_hook_gs() {
  HMODULE server = GetModuleHandleA("EngineServer.dll");
  if (server) {
    if (ogethostbyname)
      detour_iat_func(server, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(server, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(server, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(server, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
  }
}

static void patch_fearserver() {
  fearserver_hook_gs();
}

#endif // __GAME_FEAR_H
