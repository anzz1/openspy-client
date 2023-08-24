// game_thug2.h

#ifndef __GAME_THUG2_H
#define __GAME_THUG2_H

#include "include/global.h"

__forceinline static void thug2_hook_gs() {
  BYTE* ptr = 0;
  BYTE search[] = "www.thug2online.com/";
  while (ptr = find_pattern_mem(0, search, search + 19, FALSE))
    write_mem(ptr, "thmods.com/motd.dat", 20);
}

__noinline static void patch_thug2() {
  thug2_hook_gs();
}

#endif // __GAME_THUG2_H
