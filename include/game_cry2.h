// game_cry2.h

#ifndef __GAME_CRY2_H
#define __GAME_CRY2_H

#include "include/global.h"

// Disable HTTPS
__forceinline static void cry2_disable_https() {
  BYTE* ptr = 0;
  BYTE search[] = {0xC7,0x46,0x28,0x01,0x00,0x00,0x00,0x83,0xC3,0x08};

  ptr = find_pattern_mem(0, search, search + 9, TRUE);
  if (ptr)
    write_mem(ptr+3, "\0", 1);
}

__noinline static void patch_cry2() {
  cry2_disable_https();
  gs_replace_pubkey(0);
}

#endif // __GAME_CRY2_H
