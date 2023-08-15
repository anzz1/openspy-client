// game_fear.h

#ifndef __GAME_FEAR_H
#define __GAME_FEAR_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

typedef HMODULE (__stdcall *LoadLibraryA_fn)(LPCSTR lpLibFileName);
LoadLibraryA_fn oLoadLibraryA = 0;
typedef DWORD (__stdcall *GetPrivateProfileStringA_fn)(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName);
GetPrivateProfileStringA_fn oGetPrivateProfileStringA = 0;

// TODO
//
// server:
//   server works fine when connected to internet and masterserver is online, but we still need to patch "Unable to use the selected network service"
//   error to allow offline LAN play
//

DWORD __stdcall fear_hk_GetPrivateProfileStringA(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName) {
  if (lpAppName && lpKeyName && !__strcmp(lpAppName, "FEAR") && !__strcmp(lpKeyName, "CDKey")) {
    if (lpFileName && __strstr(lpFileName, "FEARCombat"))
      __strcpy(lpReturnedString, "LER7-BAB6-JYX5-BYX6-6324"); // Generic MPFREE
    else
      __strcpy(lpReturnedString, "NAS3-XUS9-SER5-JET6-5558"); // Generic Retail
    SetLastError(0);
    return 24;
  }
  return oGetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName);
}

HMODULE __stdcall fear_hk_LoadLibraryA(LPCSTR lpLibFileName) {
  HMODULE mod = 0;
  const char* name = __strrchr(lpLibFileName, '\\');
  if (name)
    name++;
  else
    name = lpLibFileName;

  // Disable PunkBuster
  if (!__stricmp(name, "pbag.dll") || !__stricmp(name, "pbags.dll") ||
      !__stricmp(name, "pbcl.dll") || !__stricmp(name, "pbcls.dll") ||
      !__stricmp(name, "pbsv.dll")) {
    SetLastError(ERROR_MOD_NOT_FOUND);
    return 0;
  }

  mod = oLoadLibraryA(lpLibFileName);

  // GameClient.dll is extracted to "%LOCALAPPDATA%\Temp\Gam????.tmp" from "FEARE_?.Arch00"
  if (mod) {
    name = GetModExpName(mod);
    if (name && !__strcmp(name, "GameClient.dll")) {
      if (oGetPrivateProfileStringA)
        detour_iat_func(mod, "GetPrivateProfileStringA", (void*)fear_hk_GetPrivateProfileStringA, "kernel32.dll", 0, FALSE);
      else
        oGetPrivateProfileStringA = (GetPrivateProfileStringA_fn)detour_iat_func(mod, "GetPrivateProfileStringA", (void*)fear_hk_GetPrivateProfileStringA, "kernel32.dll", 0, FALSE);
    }
  }
  return mod;
}

LPHOSTENT __stdcall fear_hk_gethostbyname(const char* name) {
  if (!__strcmp(name, "www.whatisfear.com"))
    return ogethostbyname("motd.openspy.net");
  else
    return hk_gethostbyname(name);
}

__forceinline static void fear_hook_gs() {
  HMODULE server;

  if (ogethostbyname)
    detour_iat_func(0, "gethostbyname", (void*)fear_hk_gethostbyname, "wsock32.dll", 52, TRUE);
  else
    ogethostbyname = (gethostbyname_fn)detour_iat_func(0, "gethostbyname", (void*)fear_hk_gethostbyname, "wsock32.dll", 52, TRUE);

  if (oLoadLibraryA)
    detour_iat_func(0, "LoadLibraryA", (void*)fear_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);
  else
    oLoadLibraryA = (LoadLibraryA_fn)detour_iat_func(0, "LoadLibraryA", (void*)fear_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);

  server = GetModuleHandleA("EngineServer.dll");
  if (server) {
    if (ogethostbyname)
      detour_iat_func(server, "gethostbyname", (void*)fear_hk_gethostbyname, "wsock32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(server, "gethostbyname", (void*)fear_hk_gethostbyname, "wsock32.dll", 52, TRUE);

    if (obind)
      detour_iat_func(server, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(server, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);

    if (oLoadLibraryA)
      detour_iat_func(server, "LoadLibraryA", (void*)fear_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);
    else
      oLoadLibraryA = (LoadLibraryA_fn)detour_iat_func(server, "LoadLibraryA", (void*)fear_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);
  }
}

static void patch_fear() {
  fear_hook_gs();
}

#endif // __GAME_FEAR_H
