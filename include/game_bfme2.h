// game_bfme2.h

#ifndef __GAME_BFME2_H
#define __GAME_BFME2_H

#include "include/global.h"
#include "iathook/iathook.h"

LPHOSTENT __stdcall hk_gethostbyname(const char* name);

LPHOSTENT __stdcall bfme2_hk_gethostbyname(const char* name) {
  if (name && !__strcmp(name, "servserv.generals.ea.com"))
    return ogethostbyname("motd.openspy.net");
  else if (name && !__strcmp(name, "bfme2.fesl.ea.com"))
    return ogethostbyname("bfme2.fesl.openspy.net");
  else
    return hk_gethostbyname(name);
}

__forceinline static void bfme2_hook_gs() {
  HOOK_FUNC(0, gethostbyname, bfme2_hk_gethostbyname, "ws2_32.dll", 0, TRUE); // OFT missing
  HOOK_FUNC(0, gethostbyname, bfme2_hk_gethostbyname, "wsock32.dll", 0, TRUE); // OFT missing
}

__noinline static void patch_bfme2() {
  bfme2_hook_gs();
}

#endif // __GAME_BFME2_H
