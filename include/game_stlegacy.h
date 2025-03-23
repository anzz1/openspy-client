// game_stlegacy.h

#ifndef __GAME_STLEGACY_H
#define __GAME_STLEGACY_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void stlegacy_hook_gs(HMODULE mod) {
  HOOK_FUNC(0, gethostbyname, hk_gethostbyname, "ws2_32.dll", 52, TRUE);
  HOOK_FUNC(mod, gethostbyname, hk_gethostbyname, "ws2_32.dll", 52, TRUE);
  HOOK_FUNC(mod, bind, hk_bind, "ws2_32.dll", 2, TRUE);
}

// net voice init crashes game - disable it
__forceinline static void stlegacy_disable_net_voice(HMODULE mod) {
  WORD search1[] = {0x83,0xC4,0x04,0x8B,0x46,0x08,0x05,0xD4,0x00,0x00,0x00,0x50,0xFF,0x15,_ANY,_ANY,_ANY,_ANY,0xE8,_ANY,_ANY,_ANY,_ANY,0x8A,0x48,0x28,0x84,0xC9,0x0F,0x84};
  BYTE patch1[] = {0xE9};
  WORD search2[] = {0x64,0x89,0x25,0x00,0x00,0x00,0x00,0x51,0xA1,_ANY,_ANY,_ANY,_ANY,0x85,0xC0,0x75,0x47,0x56,0x6A,0x44};
  BYTE patch2[] = {0xEB,0x3F};
  WORD search3[] = {0x83,0xC4,0x10,0xC3,0x33,0xC0,0xA3,_ANY,_ANY,_ANY,_ANY,0x5E,0x8B,0x4C,0x24,0x04};

  BYTE* ptr = find_pattern_mem_wildcard((ULONG_PTR)mod, search1, search1 + 29, TRUE);
  if (ptr) {
    nop_mem(ptr+18, 11);
    write_mem(ptr+29, patch1, 1);
  }

  ptr = find_pattern_mem_wildcard((ULONG_PTR)mod, search2, search2 + 19, TRUE);
  if (ptr) {
    write_mem(ptr+15, patch2, 2);
    ptr = find_pattern_mem_wildcard((ULONG_PTR)mod, search3, search3 + 15, TRUE);
    if (ptr)
      nop_mem(ptr+11, 1);
  }
}

__noinline static void patch_stlegacy() {
  HMODULE mod = GetModuleHandleA("NetworkManager.dll");
  if (mod) {
    stlegacy_hook_gs(mod);
    stlegacy_disable_net_voice(mod);
  }
}

#endif // __GAME_STLEGACY_H
