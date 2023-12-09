// game_ts.h

#ifndef __GAME_TS_H
#define __GAME_TS_H

#include "include/global.h"
#include "iathook/iathook.h"

typedef void (__stdcall *GetSystemInfo_fn)(LPSYSTEM_INFO lpSystemInfo);
GetSystemInfo_fn oGetSystemInfo = 0;

typedef BOOL (__stdcall *GetProcessAffinityMask_fn)(HANDLE hProcess, PDWORD_PTR lpProcessAffinityMask, PDWORD_PTR lpSystemAffinityMask);
GetProcessAffinityMask_fn oGetProcessAffinityMask = 0;

void __stdcall ts_hk_GetSystemInfo(LPSYSTEM_INFO lpSystemInfo) {
  oGetSystemInfo(lpSystemInfo);
  lpSystemInfo->dwActiveProcessorMask &= 0xFF;
  if (lpSystemInfo->dwNumberOfProcessors > 8) lpSystemInfo->dwNumberOfProcessors = 8;
}

BOOL __stdcall ts_hk_GetProcessAffinityMask(HANDLE hProcess, PDWORD_PTR lpProcessAffinityMask, PDWORD_PTR lpSystemAffinityMask) {
  if (oGetProcessAffinityMask(hProcess, lpProcessAffinityMask, lpSystemAffinityMask)) {
    *lpProcessAffinityMask &= 0xFF;
    *lpSystemAffinityMask &= 0xFF;
    return TRUE;
  }
  return FALSE;
}

// Enable GameSpy
long __stdcall ts_hk_RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult) {
  if(!__strcmp(lpSubKey, "SOFTWARE\\Sierra Entertainment\\TimeShift\\1.00.000")) {
    if (phkResult) *phkResult = (HKEY)0xF5C0FFEE;
    SetLastError(0);
    return 0;
  }

  return oRegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult);
}

long __stdcall ts_hk_RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
  if (lpValueName && !__strcmp(lpValueName, "CDKey")) {
    if (lpType) *lpType = REG_SZ;
    if (lpData) __strcpy(lpData, "DAW5-ZYB5-XYB5-LAW3-8385");
    if (lpcbData) *lpcbData = 25;
    SetLastError(0);
    return 0;
  }
  return oRegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}

long __stdcall ts_hk_RegCloseKey(HKEY hKey) {
  if(hKey == (HKEY)0xF5C0FFEE) {
    SetLastError(0);
    return 0;
  }

  return oRegCloseKey(hKey);
}

// fix crash on cpus with more than 8C/8T
__forceinline static void ts_hook_corelimit() {
  HOOK_FUNC(0, GetSystemInfo, ts_hk_GetSystemInfo, "kernel32.dll", 0, FALSE);
  HOOK_FUNC(0, GetProcessAffinityMask, ts_hk_GetProcessAffinityMask, "kernel32.dll", 0, FALSE);
}

__forceinline static void ts_hook_gs() {
  HOOK_FUNC(0, RegOpenKeyExA, ts_hk_RegOpenKeyExA, 0, 0, TRUE);
  HOOK_FUNC(0, RegQueryValueExA, ts_hk_RegQueryValueExA, 0, 0, TRUE);
  HOOK_FUNC(0, RegCloseKey, ts_hk_RegCloseKey, 0, 0, TRUE);
}

__noinline static void patch_ts() {
  ts_hook_corelimit();
  ts_hook_gs();
}

#endif // __GAME_TS_H
