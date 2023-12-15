// game_bf2142.h

#ifndef __GAME_BF2142_H
#define __GAME_BF2142_H

#include "include/global.h"

__forceinline static void bf2142_disable_cert_validation(void) {
  WORD search[] = {0x81,_ANY,0xEE,0x0F,0x00,0x00,0x83,_ANY,0x15,0x8B};
  BYTE patch[] = {0xB8,0x15,0x00,0x00,0x00};

  BYTE* ptr = find_pattern_mem_wildcard(0, search, search + 9, TRUE);
  if (ptr)
    write_mem(ptr+6, patch, 5);
}

__forceinline static void bf2142_patch_error_neg_206(void) {
  BYTE search[] = {0xFF,0x50,0x14,0x8A,0x46,0x18,0x84,0xC0,0x74,0x29};
  BYTE patch[] = {0xEB,0x2E,0x90};

  BYTE* ptr = find_pattern_mem(0, search, search + 9, TRUE);
  if (ptr)
    write_mem(ptr+3, patch, 3);
}

__forceinline static void bf2142_fix_delete_soldier_hang(void) {
  BYTE search[] = {0xFF,0x15,0xCC,0xD0,0x90,0x00,0x85,0xC0,0x0F,0x85,0x9D,0xFE,0xFF,0xFF};

  BYTE* ptr = find_pattern_mem(0, search, search + 13, TRUE);
  if (ptr)
    nop_mem(ptr+8, 6);
}

__noinline static void patch_bf2142() {
  bf2142_disable_cert_validation();
  bf2142_patch_error_neg_206();
  bf2142_fix_delete_soldier_hang();
}

#endif // __GAME_BF2142_H
