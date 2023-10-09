// game_sof2.h

#ifndef __GAME_SOF2_H
#define __GAME_SOF2_H

#include "include/global.h"
#include "iathook/iathook.h"

LPHOSTENT __stdcall hk_gethostbyname(const char* name);

LPHOSTENT __stdcall sof2_hk_gethostbyname(const char* name) {
  if (name && !__strcmp(name, "master.sof2.ravensoft.com"))
    return ogethostbyname("master.openspy.net");
  else
    return hk_gethostbyname(name);
}

__forceinline static void sof2_hook_gs() {
  HOOK_FUNC(0, gethostbyname, sof2_hk_gethostbyname, "ws2_32.dll", 52, TRUE);
  HOOK_FUNC(0, gethostbyname, sof2_hk_gethostbyname, "wsock32.dll", 52, TRUE);
}

// GOG v1.3 extra patch
__forceinline static void sof2_patch_gog() {
  patch_if_match((void*)0x0055A9AC, "localhost 2.ravensoft.com", "master.openspy.net", 25, 19);
}

__noinline static void patch_sof2() {
  sof2_hook_gs();
  sof2_patch_gog();
}

#endif // __GAME_SOF2_H
