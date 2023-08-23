// game_sr2.h

#ifndef __GAME_SR2_H
#define __GAME_SR2_H

#include "include/global.h"
#include "iathook/iathook.h"

HANDLE __stdcall hk_WSAAsyncGetHostByName(HWND hWnd, unsigned int wMsg, const char *name, char *buf, int buflen);

typedef void (__stdcall *WSASetLastError_fn)(int iError);
WSASetLastError_fn oWSASetLastError;

// Disable ad server
HANDLE __stdcall sr2_hk_WSAAsyncGetHostByName(HWND hWnd, unsigned int wMsg, const char *name, char *buf, int buflen) {
  if (!__strcmp(name, "master10.doublefusion.com")) {
    if (oWSASetLastError)
      oWSASetLastError(10050); // WSAENETDOWN
    return 0;
  }
  else
    return hk_WSAAsyncGetHostByName(hWnd, wMsg, name, buf, buflen);
}
__forceinline static void sr2_disable_ads() {
  HMODULE dfengine = GetModuleHandleA("dfengine.dll");
  if (dfengine) {
    HMODULE ws = GetModuleHandleA("ws2_32.dll");
    if (!ws)
      ws = GetModuleHandleA("wsock32.dll");
    if (ws)
      oWSASetLastError = (WSASetLastError_fn)GetProcAddress(ws, MAKEINTRESOURCEA(112));

    HOOK_FUNC(dfengine, WSAAsyncGetHostByName, sr2_hk_WSAAsyncGetHostByName, "ws2_32.dll", 103, TRUE);
  }
}

// Disable HTTPS
__forceinline static void sr2_disable_https() {
  BYTE* ptr = 0;
  BYTE search[] = {0xC7,0x46,0x28,0x01,0x00,0x00,0x00,0x83,0xC7,0x08};

  ptr = find_pattern_mem(0, search, search + 9, TRUE);
  if (ptr)
    write_mem(ptr+3, "\0", 1);
}

__noinline static void patch_sr2() {
  sr2_disable_ads();
  sr2_disable_https();
  gs_replace_pubkey(0);
}

#endif // __GAME_SR2_H
