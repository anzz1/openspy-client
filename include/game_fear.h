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
//  - test more versions than v1.8
//  - purge any remaining key validations as clients are still checked for valid keys locally
//

__forceinline static void fear_patch_gs_offline(ULONG_PTR addr) {
  BYTE* ptr = 0;
  BYTE search[] = {0x5D,0x33,0xC0,0x5B,0x83,0xC4,0x40,0xC3,0x5F,0x5E,0x5D,0xB8,0x03,0x00,0x00,0x00,0x5B,0x83,0xC4,0x40,0xC3};

  ptr = find_pattern_mem(addr, search, search + 20);
  if (ptr)
    write_mem(ptr+12, "\0", 1);
}

__forceinline static void fear_disable_pb_srv(ULONG_PTR addr) {
  BYTE* ptr = 0;
  BYTE search[] = {0x8B,0xC8,0xFF,0x52,0x04,0xE8,0x49,0x19,0x08,0x00,0x8A,0x88,0xC1,0x07,0x00,0x00};
  BYTE patch[] = {0x90,0x90,0x90};

  ptr = find_pattern_mem(addr, search, search + 15);
  if (ptr)
    write_mem(ptr+2, patch, sizeof(patch));
}

__forceinline static void fear_disable_pb_cli() {
  BYTE match[] = {0x1E,0xFF,0x80,0xFF,0xAD,0x8B,0x4B,0x26,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00};

  if(!__memcmp((void*)0x0056EAD8, match, sizeof(match))) {
    write_mem((void*)0x0056EAEC, "\0", 1);
  }
}

__forceinline static void fear_disable_key_request(ULONG_PTR addr) {
  BYTE* ptr = 0;
  BYTE search[] = {0x8A,0x88,0x74,0x07,0x00,0x00,0x84,0xC9,0x75,0x1F,0x8B,0x0D};
  BYTE patch[] = {0x90,0x90,0xEB};

  ptr = find_pattern_mem(addr, search, search + 11);
  if (ptr)
    write_mem(ptr+6, patch, sizeof(patch));
}

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

  // GameClient.dll/GameServer.dll are extracted to "%LOCALAPPDATA%\Temp\Gam????.tmp" from "FEARE_?.Arch00"
  if (mod) {
    name = GetModExpName(mod);
    if (name) {
      if (!__strcmp(name, "GameClient.dll")) {
        if (oGetPrivateProfileStringA)
          detour_iat_func(mod, "GetPrivateProfileStringA", (void*)fear_hk_GetPrivateProfileStringA, "kernel32.dll", 0, FALSE);
        else
          oGetPrivateProfileStringA = (GetPrivateProfileStringA_fn)detour_iat_func(mod, "GetPrivateProfileStringA", (void*)fear_hk_GetPrivateProfileStringA, "kernel32.dll", 0, FALSE);
      } else if (!__strcmp(name, "GameServer.dll")) {
        fear_disable_pb_srv((ULONG_PTR)mod);
        fear_disable_key_request((ULONG_PTR)mod);
      }
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

    fear_patch_gs_offline((ULONG_PTR)server);
  }
}

static void patch_fear_srv() {
  fear_hook_gs();
}

static void patch_fear_cli() {
  fear_hook_gs();
  fear_patch_gs_offline(0);
  fear_disable_pb_cli();
}

#endif // __GAME_FEAR_H
