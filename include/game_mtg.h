// game_mtg.h

#ifndef __GAME_MTG_H
#define __GAME_MTG_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);
HANDLE __stdcall hk_WSAAsyncGetHostByName(HWND hWnd, unsigned int wMsg, const char *name, char *buf, int buflen);

__forceinline static void mtg_hook_gs() {
  HMODULE replayunit = GetModuleHandleA("ReplayUnit.dll");
  if (replayunit) {
    if (ogethostbyname)
      detour_iat_func(replayunit, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(replayunit, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(replayunit, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(replayunit, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);

    if (oWSAAsyncGetHostByName)
      detour_iat_func(0, "WSAAsyncGetHostByName", (void*)hk_WSAAsyncGetHostByName, "ws2_32.dll", 103, TRUE);
    else
      oWSAAsyncGetHostByName = (WSAAsyncGetHostByName_fn)detour_iat_func(0, "WSAAsyncGetHostByName", (void*)hk_WSAAsyncGetHostByName, "ws2_32.dll", 103, TRUE);
  }
}

static void patch_mtg() {
  mtg_hook_gs();
}

#endif // __GAME_MTG_H
