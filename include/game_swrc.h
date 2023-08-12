// game_swrc.h

#ifndef __GAME_SWRC_H
#define __GAME_SWRC_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void swrc_disable_auth(ULONG_PTR addr) {
  BYTE* ptr = 0;

  BYTE search[] = {0x8B,0xF9,0xC7,0x45,0xFC,0x00,0x00,0x00,0x00,0xE8,0x8D,0xED,0xFF,0xFF,0x8B,0xF0,0x85,0xF6,0x0F,0x84,0xC5,0x00,0x00,0x00,0xA1};
  BYTE patch[] = {0x90,0x90,0x90,0xE9};

  ptr = find_pattern_mem(addr, search, search + 24);
  if (ptr)
    write_mem(ptr+16, patch, 4);
}

__forceinline static void swrc_hook_gs() {
  HMODULE hmod = GetModuleHandleA("GameSpyMgr.dll");
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
  hmod = LoadLibraryA("IpDrv.dll");
  if (hmod) {
    if (ogethostbyname)
      detour_iat_func(hmod, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(hmod, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(hmod, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(hmod, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);

    GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)hmod, &hmod);
    swrc_disable_auth((ULONG_PTR)hmod);
  }
}

static void patch_swrc() {
  swrc_hook_gs();
}

#endif // __GAME_SWRC_H
