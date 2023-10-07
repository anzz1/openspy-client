// game_xml2.h

#ifndef __GAME_XML2_H
#define __GAME_XML2_H

#include "include/global.h"

static char xml2_key[] = "SOFTWARE\\Activision\\X-Men Legends 2\\Settings\\Display";

// missing registry key causes crash on startup
__forceinline static void xml2_create_key() {
  CreateRegKey(HKEY_CURRENT_USER, xml2_key);
}

__noinline static void patch_xml2() {
  xml2_create_key();
}

#endif // __GAME_XML2_H
