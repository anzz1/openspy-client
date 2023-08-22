// game_mvau.h

#ifndef __GAME_MVAU_H
#define __GAME_MVAU_H

#include "include/global.h"

__forceinline static void mvau_disable_wnd_check() {
  BYTE* ptr = 0;

  BYTE search[] = {0x39,0x5C,0x24,0x08,0x74,0x06,0x53,0xE8};
  BYTE patch[] = {0x90,0x90,0x90,0x90,0xEB};

  ptr = find_pattern_mem(0, search, search + 7, TRUE);
  if (ptr)
    write_mem(ptr, patch, 5);
}

__noinline static void patch_mvau() {
  mvau_disable_wnd_check();
}

#endif // __GAME_MVAU_H
