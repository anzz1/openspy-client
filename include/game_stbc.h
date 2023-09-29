// game_stbc.h

#ifndef __GAME_STBC_H
#define __GAME_STBC_H

#include "include/global.h"
#include "iathook/iathook.h"

LPHOSTENT __stdcall hk_gethostbyname(const char* name);

LPHOSTENT __stdcall stbc_hk_gethostbyname(const char* name) {
  if (name && !__strcmp(name, "stbridgecmnd01.activision.com"))
    return ogethostbyname("master.openspy.net");
  else
    return hk_gethostbyname(name);
}

__noinline static void patch_stbc() {
  HOOK_FUNC(0, gethostbyname, stbc_hk_gethostbyname, "wsock32.dll", 52, TRUE);
}

#endif // __GAME_STBC_H
