// dinput8_dll.h

#ifndef __DINPUT8_DLL_H
#define __DINPUT8_DLL_H

#include "include/global.h"
#include "include/shared.h"

typedef long (__stdcall *DirectInput8Create_fn)(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, /* LPUNKNOWN */ LPVOID punkOuter);
DirectInput8Create_fn oDirectInput8Create = 0;

long __stdcall p_DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID *ppvOut, /* LPUNKNOWN */ LPVOID punkOuter) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectInput8Create=p_DirectInput8Create")
#else
  #pragma comment(linker, "/EXPORT:DirectInput8Create=_p_DirectInput8Create@20")
#endif

  if (!oDirectInput8Create) {
    oDirectInput8Create = GetSysProc(sDInput8, "DirectInput8Create");
    if (oDirectInput8Create) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oDirectInput8Create, &hm);
    } else {
      oDirectInput8Create = (void*)-1;
    }
  }
  if (oDirectInput8Create != (void*)-1)
    return oDirectInput8Create(hinst, dwVersion, riidltf, ppvOut, punkOuter);

  return 0x80004005; // DIERR_GENERIC (E_FAIL)
}

__noinline static void dinput8_hook() {
  pModName = sDInput8;
#ifndef DLL_PROXY_DELAY_LOAD
  HMODULE hm = LoadSysMod(sDInput8);
  if (hm) {
    oDirectInput8Create = (DirectInput8Create_fn)GetProcAddress(hm,"DirectInput8Create");
    oDllGetClassObject = (DllGetClassObject_fn)GetProcAddress(hm,"DllGetClassObject");
    oDllRegisterServer = (DllRegisterServer_fn)GetProcAddress(hm,"DllRegisterServer");
    oDllUnregisterServer = (DllUnregisterServer_fn)GetProcAddress(hm,"DllUnregisterServer");
    if (oDirectInput8Create)
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oDirectInput8Create, &hm);
  }
#endif // !DLL_PROXY_DELAY_LOAD
}

#endif // __DINPUT8_DLL_H

