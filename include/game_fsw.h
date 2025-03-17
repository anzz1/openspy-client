// game_fsw.h

#ifndef __GAME_FSW_H
#define __GAME_FSW_H

#include "include/global.h"
#include "iathook/iathook.h"

static GUID fsw_guid = {0x2F585210, 0x0B63, 0x49B1, {0xB5, 0xF6, 0x04, 0x09, 0xE9, 0xA3, 0xAA, 0xC7}};

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

// Steam and GOG versions have replaced '%s.available.gamespy.com' with '%s.availa.nordicgames.at'

__forceinline static int fsw_gs_copy_string(char* dst, const char* src) {
  if (__stristr(src, ".availa.nordicgames.at")) {
    char* p;
    __strncpy(dst, src, 511);
    if (p = __stristr(dst, ".availa.nordicgames.at")) {
      __strcpy(p, ".available.openspy.net");
    }
    return 1;
  }
  return 0;
}

LPHOSTENT __stdcall fsw_hk_gethostbyname(const char* name) {
  char s[512];
  if (name && fsw_gs_copy_string(s, name))
    return ogethostbyname(s);
  else
    return hk_gethostbyname(name);
}

__forceinline static void fsw_hook_gs() {
  HMODULE hmod = GetModuleHandleA("FSW.dll");
  if (hmod) {
    HOOK_FUNC(hmod, gethostbyname, fsw_hk_gethostbyname, "ws2_32.dll", 52, TRUE);
    HOOK_FUNC(hmod, bind, hk_bind, "ws2_32.dll", 2, TRUE);
  }
}

__noinline static void patch_fsw() {
  fsw_hook_gs();
}

#endif // __GAME_FSW_H
