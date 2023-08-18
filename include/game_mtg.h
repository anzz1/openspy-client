// game_mtg.h

#ifndef __GAME_MTG_H
#define __GAME_MTG_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);
HANDLE __stdcall hk_WSAAsyncGetHostByName(HWND hWnd, unsigned int wMsg, const char *name, char *buf, int buflen);

// Enable GameSpy
long __stdcall mtg_hk_RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult) {
  if(!__strcmp(lpSubKey, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0C88C4A1-A9D7-4C28-8F06-4C2048765193}")) {
    if (phkResult) *phkResult = (HKEY)0xF5C0FFEE;
    SetLastError(0);
    return 0;
  }

  return oRegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult);
}

long __stdcall mtg_hk_RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
  if (lpValueName && !__strcmp(lpValueName, "CDKEY")) {
    if (lpType) *lpType = REG_SZ;
    if (lpData) __strcpy(lpData, "8DEV-NG6A-3B26-2EKL-LJWY-LNNB");
    if (lpcbData) *lpcbData = 30;
    SetLastError(0);
    return 0;
  }
  return oRegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}

long __stdcall mtg_hk_RegCloseKey(HKEY hKey) {
  if(hKey == (HKEY)0xF5C0FFEE) {
    SetLastError(0);
    return 0;
  }

  return oRegCloseKey(hKey);
}

__forceinline static void mtg_hook_gs() {
  HMODULE mod = GetModuleHandleA("ReplayUnit.dll");
  if (mod) {
    if (ogethostbyname)
      detour_iat_func(mod, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(mod, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(mod, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(mod, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);

    if (oWSAAsyncGetHostByName)
      detour_iat_func(0, "WSAAsyncGetHostByName", (void*)hk_WSAAsyncGetHostByName, "ws2_32.dll", 103, TRUE);
    else
      oWSAAsyncGetHostByName = (WSAAsyncGetHostByName_fn)detour_iat_func(0, "WSAAsyncGetHostByName", (void*)hk_WSAAsyncGetHostByName, "ws2_32.dll", 103, TRUE);
  }
  mod = GetModuleHandleA("GameSpy.dll");
  if (mod) {
    if (oRegOpenKeyExA)
      detour_iat_func(mod, "RegOpenKeyExA", (void*)mtg_hk_RegOpenKeyExA, 0, 0, TRUE);
    else
      oRegOpenKeyExA = (RegOpenKeyExA_fn)detour_iat_func(mod, "RegOpenKeyExA", (void*)mtg_hk_RegOpenKeyExA, 0, 0, TRUE);

    if (oRegQueryValueExA)
      detour_iat_func(mod, "RegQueryValueExA", (void*)mtg_hk_RegQueryValueExA, 0, 0, TRUE);
    else
      oRegQueryValueExA = (RegQueryValueExA_fn)detour_iat_func(mod, "RegQueryValueExA", (void*)mtg_hk_RegQueryValueExA, 0, 0, TRUE);

    if (oRegCloseKey)
      detour_iat_func(mod, "RegCloseKey", (void*)mtg_hk_RegCloseKey, 0, 0, TRUE);
    else
      oRegCloseKey = (RegCloseKey_fn)detour_iat_func(mod, "RegCloseKey", (void*)mtg_hk_RegCloseKey, 0, 0, TRUE);
  }
}

static void patch_mtg() {
  mtg_hook_gs();
}

#endif // __GAME_MTG_H
