// game_halo.h

#ifndef __GAME_HALO_H
#define __GAME_HALO_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static int halo_gs_copy_string(char* dst, const char* src) {
  if (__stristr(src, "hosthpc.com")) {
    char* p;
    __strncpy(dst, src, 511);
    while (p = __stristr(dst, "hosthpc.com")) {
      p[0] = 'o';
      p[1] = 'p';
      p[2] = 'e';
      p[3] = 'n';
      p[4] = 's';
      p[5] = 'p';
      p[6] = 'y';
      p[8] = 'n';
      p[9] = 'e';
      p[10] = 't';
    }
    return 1;
  }
  return 0;
}

LPHOSTENT __stdcall halo_hk_gethostbyname(const char* name) {
  char s[512];
  if (halo_gs_copy_string(s, name))
    return ogethostbyname(s);
  else
    return hk_gethostbyname(name);
}

void* __stdcall halo_hk_GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
  if (MAKEINTRESOURCEA(lpProcName) == MAKEINTRESOURCEA(52)) {
    HMODULE hm = GetModuleHandleA("ws2_32.dll");
    if (hModule == hm) {
      if (!ogethostbyname)
        ogethostbyname = (gethostbyname_fn)detour_iat_func(0, "gethostbyname", (void*)halo_hk_gethostbyname, "ws2_32.dll", 52, TRUE);
      if (!ogethostbyname)
        ogethostbyname = (gethostbyname_fn)GetProcAddress(hModule, MAKEINTRESOURCEA(52));
      if (ogethostbyname)
        return (void*)halo_hk_gethostbyname;
    } else {
      hm = GetModuleHandleA("wsock32.dll");
      if (hModule == hm) {
        if (!ogethostbyname)
          ogethostbyname = (gethostbyname_fn)detour_iat_func(0, "gethostbyname", (void*)halo_hk_gethostbyname, "wsock32.dll", 52, TRUE);
        if (!ogethostbyname)
          ogethostbyname = (gethostbyname_fn)GetProcAddress(hModule, MAKEINTRESOURCEA(52));
        if (ogethostbyname)
          return (void*)halo_hk_gethostbyname;
      }
    }
  } else if (MAKEINTRESOURCEA(lpProcName) == MAKEINTRESOURCEA(2)) {
    HMODULE hm = GetModuleHandleA("ws2_32.dll");
    if (hModule == hm) {
      if (!obind)
        obind = (bind_fn)detour_iat_func(0, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);
      if (!obind)
        obind = (bind_fn)GetProcAddress(hModule, MAKEINTRESOURCEA(2));
      if (obind)
        return (void*)hk_bind;
    } else {
      hm = GetModuleHandleA("wsock32.dll");
      if (hModule == hm) {
        if (!obind)
          obind = (bind_fn)detour_iat_func(0, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
        if (!obind)
          obind = (bind_fn)GetProcAddress(hModule, MAKEINTRESOURCEA(2));
        if (obind)
          return (void*)hk_bind;
      }
    }
  }
  return GetProcAddress(hModule, lpProcName);
}

__forceinline static void halo_hook_gs() {
  if (ogethostbyname)
    detour_iat_func(0, "gethostbyname", (void*)halo_hk_gethostbyname, "ws2_32.dll", 52, TRUE);
  else
    ogethostbyname = (gethostbyname_fn)detour_iat_func(0, "gethostbyname", (void*)halo_hk_gethostbyname, "ws2_32.dll", 52, TRUE);

  if (ogethostbyname)
    detour_iat_func(0, "gethostbyname", (void*)halo_hk_gethostbyname, "wsock32.dll", 52, TRUE);
  else
    ogethostbyname = (gethostbyname_fn)detour_iat_func(0, "gethostbyname", (void*)halo_hk_gethostbyname, "wsock32.dll", 52, TRUE);

  detour_iat_func(0, "GetProcAddress", (void*)halo_hk_GetProcAddress, "kernel32.dll", 0, TRUE);
}

static void patch_halo() {
  halo_hook_gs();
}

#endif // __GAME_HALO_H
