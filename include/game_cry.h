// game_cry.h

#ifndef __GAME_CRY_H
#define __GAME_CRY_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

__forceinline static void cry_skip_intro(HMODULE crygame) {
#ifdef _WIN64
  WORD search[] = {0x48,0x8B,0x05,_ANY,_ANY,_ANY,_ANY,0x83,0xB8,_ANY,_ANY,0x00,0x00,0x01,0x75};

  BYTE* ptr = find_pattern_mem_wildcard((ULONG_PTR)crygame, search, search + 14, TRUE);
  if (ptr)
    nop_mem(ptr, 16);
#else
  BYTE search[] = {0x33,0xF6,0x89,0x77,0x70,0x8B,0x0D,0xD0,0x6F,0x2A,0x39,0x83,0xB9,0xD0,0x02,0x00,0x00,0x01,0x5E,0x75,0x0A};

  BYTE* ptr = find_pattern_mem((ULONG_PTR)crygame, search, search + 20, TRUE);
  if (ptr) {
    nop_mem(ptr+5, 13);
    nop_mem(ptr+19, 2);
  }
#endif
}

__forceinline static void cry_skip_key_check(HMODULE crynet) {
#ifdef _WIN64
  BYTE search[] = {0x4C,0x8B,0x43,0x10,0x4D,0x85,0xC0,0x74,0x42,0x66,0x66,0x90,0x49,0x8B,0x38,0x48,0x8D,0x4C,0x24,0x40};

  BYTE* ptr = find_pattern_mem((ULONG_PTR)crynet, search, search + 19, TRUE);
  if (ptr)
    nop_mem(ptr+4, 71);
#else
  BYTE search[] = {0x75,0x0C,0x46,0x46,0x40,0x40,0x3A,0xCB,0x75,0xE6,0x33,0xC0,0xEB,0x05,0x1B,0xC0,0x83,0xD8,0xFF,0x3B,0xC3,0x74,0x09,0x8B,0x7F,0x04,0x3B,0xFB,0x75,0xCA,0xEB,0x0B,0x8D,0x7D,0xDC};

  BYTE* ptr = find_pattern_mem((ULONG_PTR)crynet, search, search + 34, TRUE);
  if (ptr)
    nop_mem(ptr+19, 4);
#endif
}

__forceinline static void cry_allow_extras(HMODULE crynet) {
#ifdef _WIN64
  BYTE search[] = {0xC7,0x83,0x60,0xFA,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x48,0x89,0x8B,0x68,0xFA,0x00,0x00,0x44,0x88,0xA3,0x70,0xFA,0x00,0x00,0x44,0x89};
  BYTE patch[] = {0xC6,0x83,0x70,0xFA,0x00,0x00,0x01};

  BYTE* ptr = find_pattern_mem((ULONG_PTR)crynet, search, search + 25, TRUE);
  if (ptr)
    write_mem(ptr+17, patch, sizeof(patch));
#else
  BYTE search[] = {0x89,0x93,0xC4,0xF3,0x00,0x00,0xC6,0x83,0xC8,0xF3,0x00,0x00,0x00,0x89,0xBB,0xCC,0xF3,0x00,0x00,0x89,0xB3,0xD0,0xF3,0x00,0x00,0x89,0xB3,0xD4,0xF3,0x00,0x00,0x89};
  BYTE patch[] = {0xC6,0x83,0xC8,0xF3,0x00,0x00,0x01};

  BYTE* ptr = find_pattern_mem((ULONG_PTR)crynet, search, search + 31, TRUE);
  if (ptr)
    write_mem(ptr+6, patch, sizeof(patch));
#endif
}

__forceinline static void cry_allow_connect_no_account(HMODULE crynet) {
#ifdef _WIN64
  BYTE search[] = {0xBA,0x01,0x00,0x00,0x00,0x48,0x8B,0xCF,0xFF,0x10,0x40,0x84,0xED,0x0F,0x85,0x96,0x00,0x00,0x00,0x48,0x83,0xC3,0x10,0x48,0x3B,0x5C,0x24,0x40,0x0F,0x85};

  BYTE* ptr = find_pattern_mem((ULONG_PTR)crynet, search, search + 29, TRUE);
  if (ptr)
    nop_mem(ptr+10, 24);
#else
  BYTE search[] = {0x84,0xDB,0x75,0x2E,0x83,0xC7,0x0C,0x3B,0x7C,0x24,0x1C,0x75,0x9D,0x8B,0x75,0x10,0x85,0xF6,0x51,0x8B,0xC4,0x89,0x30,0x74,0x05,0xE8};

  BYTE* ptr = find_pattern_mem((ULONG_PTR)crynet, search, search + 25, TRUE);
  if (ptr)
    nop_mem(ptr, 13);
#endif
}

#ifdef _WIN64
__forceinline static void cry_remove_securom(HMODULE crysystem) {
  WORD search[] = {0x84,0xC0,0x75,0x16,0xE8,_ANY,_ANY,_ANY,_ANY,0x85,0xC0,0x74,0x0D,0xBA,0x1F,0x00,0x08,0x00,0x33,0xC9,0xFF};

  BYTE* ptr = find_pattern_mem_wildcard((ULONG_PTR)crysystem, search, search + 20, TRUE);
  if (ptr)
    nop_mem(ptr+4, 22);
}
#endif

__forceinline static void cry_hook_gs(HMODULE crynet) {
  HOOK_FUNC(crynet, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
  HOOK_FUNC(crynet, bind, hk_bind, "wsock32.dll", 2, TRUE);

  gs_replace_pubkey((ULONG_PTR)crynet);
}

HMODULE __stdcall cry_hk_LoadLibraryA(LPCSTR lpLibFileName) {
  HMODULE mod = 0;
  const char* name = __strrchr(lpLibFileName, '\\');
  if (name)
    name++;
  else
    name = lpLibFileName;

  mod = oLoadLibraryA(lpLibFileName);
  if (mod) {
    if (!__stricmp(name, "crygame.dll")) {
      if (skip_intro)
        cry_skip_intro(mod);
    }
    else if (!__stricmp(name, "crynetwork.dll")) {
      cry_hook_gs(mod);
      cry_skip_key_check(mod);
      cry_allow_connect_no_account(mod);
    }
#ifdef _WIN64
    else if (!__stricmp(name, "crysystem.dll")) {
      cry_remove_securom(mod);
    }
#endif
  }

  return mod;
}

__noinline static void patch_cry() {
  HMODULE mod;

  HOOK_FUNC(0, LoadLibraryA, cry_hk_LoadLibraryA, "kernel32.dll", 0, FALSE);

  mod = GetModuleHandleA("CryGame.dll");
  if (mod) {
    if (skip_intro)
      cry_skip_intro(mod);
  }
  mod = GetModuleHandleA("CryNetwork.dll");
  if (mod) {
    cry_hook_gs(mod);
    cry_skip_key_check(mod);
    cry_allow_connect_no_account(mod);
  }
#ifdef _WIN64
  mod = GetModuleHandleA("CrySystem.dll");
  if (mod) {
    cry_remove_securom(mod);
  }
#endif
}

#endif // __GAME_CRY_H
