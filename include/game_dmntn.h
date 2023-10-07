// game_dmntn.h

#ifndef __GAME_DMNTN_H
#define __GAME_DMNTN_H

#include "include/global.h"

// Disable HTTPS
__forceinline static void dmntn_disable_https() {
  BYTE* ptr = 0;
  BYTE search[] = {0xC7,0x41,0x28,0x01,0x00,0x00,0x00,0x8B,0x55,0xFC};
  ptr = find_pattern_mem(0, search, search + 9, TRUE);
  if (ptr)
    write_mem(ptr+3, "\0", 1);
}

__noinline static void patch_dmntn() {
  dmntn_disable_https();
  gs_replace_pubkey(0);
}

#endif // __GAME_DMNTN_H
