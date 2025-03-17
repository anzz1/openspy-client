// game_worldshift.h

#ifndef __GAME_WORLDSHIFT_H
#define __GAME_WORLDSHIFT_H

#include "include/global.h"
#include "iathook/iathook.h"

LPHOSTENT __stdcall hk_gethostbyname(const char* name);

LPHOSTENT __stdcall worldshift_hk_gethostbyname(const char* name) {
  if (name && !__strcmp(name, "worldshift-game.com"))
    return ogethostbyname("motd.openspy.net");
  else
    return hk_gethostbyname(name);
}

// Disable HTTPS
__forceinline static void worldshift_disable_https() {
  BYTE* ptr = 0;
  BYTE search[] = {0xC7,0x46,0x28,0x01,0x00,0x00,0x00,0x83,0xC7,0x08};

  ptr = find_pattern_mem(0, search, search + 9, TRUE);
  if (ptr)
    write_mem(ptr+3, "\0", 1);
}

__noinline static void patch_worldshift() {
  HOOK_FUNC(0, gethostbyname, worldshift_hk_gethostbyname, "ws2_32.dll", 52, TRUE);
  worldshift_disable_https();
  gs_replace_pubkey(0);
}

#endif // __GAME_WORLDSHIFT_H
