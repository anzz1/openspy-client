// game_rof.h

#ifndef __GAME_ROF_H
#define __GAME_ROF_H

#include "include/global.h"

// BETA
//
// Build 0.0704.1001.0000.13.0
//

__forceinline static void rof_patch_update_check() {
  BYTE match1[] = {0x0F,0x84,0xAB,0x00,0x00,0x00,0xBE,0x01,0x00,0x00,0x00,0x56,0x68,0x21,0xE4,0x3B};
  BYTE match2[] = {0x0F,0x85,0x86,0x01,0x00,0x00,0xD1,0xE8,0x83,0xE0,0x01,0x89,0x44,0x24,0x24,0x0F};
  BYTE patch[] = {0x90,0xE9};
  patch_if_match((void*)0x00C635E4, match1, patch, sizeof(match1), sizeof(patch));
  patch_if_match((void*)0x00CA9C0C, match2, patch, sizeof(match2), sizeof(patch));
}

__forceinline static void rof_skip_news() {
  BYTE match1[] = {0xE8,0x98,0x31,0x00,0x00};
  BYTE match2[] = {0xE8,0xF4,0x01,0x00,0x00};
  BYTE match3[] = {0xE8,0xBB,0x00,0x00,0x00};
  if(!__memcmp((void*)0x00CA9B63, match1, sizeof(match1)))
    nop_mem((void*)0x00CA9B63, sizeof(match1));
  if(!__memcmp((void*)0x00CDF977, match2, sizeof(match2)))
    nop_mem((void*)0x00CDF977, sizeof(match2));
  if(!__memcmp((void*)0x00CDFAB0, match3, sizeof(match3)))
    nop_mem((void*)0x00CDFAB0, sizeof(match3));
}

#if 0
__forceinline static void rof_gs_sdk_patches() {
  BYTE match1[] = {0x68,0x93,0x08,0x00,0x00,0x68,0x3C,0x49};
  BYTE patch[] = {0xE9,0x69,0x01,0x00};
  patch_if_match((void*)0x00E05D93, match1, patch, sizeof(match1), sizeof(patch));
}
#endif

__noinline static void patch_rof() {
  rof_patch_update_check();
  rof_skip_news();
}

#endif // __GAME_ROF_H
