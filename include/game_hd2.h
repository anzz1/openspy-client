// game_hd2.h

#ifndef __GAME_HD2_H
#define __GAME_HD2_H

#include "include/global.h"
#include "include/shared.h"
#include "iathook/iathook.h"

__noinline static void patch_hd2() {
  detour_iat_func(0, "GetProcAddress", (void*)hk_GetProcAddress, "kernel32.dll", 0, FALSE);
}

#endif // __GAME_HD2_H
