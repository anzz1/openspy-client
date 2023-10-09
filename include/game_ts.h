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

// fix crash on cpus with more than 8C/8T
__forceinline static void ts_hook_corelimit() {
  HOOK_FUNC(0, GetSystemInfo, ts_hk_GetSystemInfo, "kernel32.dll", 0, FALSE);
  HOOK_FUNC(0, GetProcessAffinityMask, ts_hk_GetProcessAffinityMask, "kernel32.dll", 0, FALSE);
}

__noinline static void patch_ts() {
  ts_hook_corelimit();
}

#endif // __GAME_FEAR_H
