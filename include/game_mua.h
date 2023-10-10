// game_mua.h

#ifndef __GAME_MUA_H
#define __GAME_MUA_H

#include "include/global.h"

static char mua_key[] = "SOFTWARE\\Activision\\Marvel Ultimate Alliance\\Settings\\Display";
static GUID mua_guid = {0xA5B4AF14, 0xA34F, 0x4677, {0xBE, 0x65, 0x95, 0x52, 0xDC, 0x25, 0x6D, 0x3A}};

// missing registry key causes crash on startup
__forceinline static void mua_create_key() {
  CreateRegKey(HKEY_CURRENT_USER, mua_key);
}

__noinline static void patch_mua() {
  mua_create_key();
}

#endif // __GAME_MUA_H
