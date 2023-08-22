// dinput_dll.h

#ifndef __DINPUT_DLL_H
#define __DINPUT_DLL_H

#include "include/global.h"
#include "include/shared.h"

typedef long (__stdcall *DirectInputCreateA_fn)(HINSTANCE hinst, DWORD dwVersion, /* LPDIRECTINPUTA* */ LPVOID *lplpDirectInput, /* LPUNKNOWN */ LPVOID punkOuter);
DirectInputCreateA_fn oDirectInputCreateA = 0;
typedef long (__stdcall *DirectInputCreateEx_fn)(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, /* LPUNKNOWN */ LPVOID punkOuter);
DirectInputCreateEx_fn oDirectInputCreateEx = 0;
typedef long (__stdcall *DirectInputCreateW_fn)(HINSTANCE hinst, DWORD dwVersion, /* LPDIRECTINPUTW* */ LPVOID *lplpDirectInput, /* LPUNKNOWN */ LPVOID punkOuter);
DirectInputCreateW_fn oDirectInputCreateW = 0;

long __stdcall p_DirectInputCreateA(HINSTANCE hinst, DWORD dwVersion, /* LPDIRECTINPUTA* */ LPVOID *lplpDirectInput, /* LPUNKNOWN */ LPVOID punkOuter) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectInputCreateA=p_DirectInputCreateA")
#else
  #pragma comment(linker, "/EXPORT:DirectInputCreateA=_p_DirectInputCreateA@16")
#endif

  if (!oDirectInputCreateA)
    oDirectInputCreateA = GetSysProc(sDInput, "DirectInputCreateA");
  if (oDirectInputCreateA)
    return oDirectInputCreateA(hinst, dwVersion, lplpDirectInput, punkOuter);

  return 1;
}

long __stdcall p_DirectInputCreateEx(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID *ppvOut, /* LPUNKNOWN */ LPVOID punkOuter) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectInputCreateEx=p_DirectInputCreateEx")
#else
  #pragma comment(linker, "/EXPORT:DirectInputCreateEx=_p_DirectInputCreateEx@20")
#endif

  if (!oDirectInputCreateEx)
    oDirectInputCreateEx = GetSysProc(sDInput, "DirectInputCreateEx");
  if (oDirectInputCreateEx)
    return oDirectInputCreateEx(hinst, dwVersion, riidltf, ppvOut, punkOuter);

  return 1;
}

long __stdcall p_DirectInputCreateW(HINSTANCE hinst, DWORD dwVersion, /* LPDIRECTINPUTW* */ LPVOID *lplpDirectInput, /* LPUNKNOWN */ LPVOID punkOuter) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectInputCreateW=p_DirectInputCreateW")
#else
  #pragma comment(linker, "/EXPORT:DirectInputCreateW=_p_DirectInputCreateW@16")
#endif

  if (!oDirectInputCreateW)
    oDirectInputCreateW = GetSysProc(sDInput, "DirectInputCreateW");
  if (oDirectInputCreateW)
    return oDirectInputCreateW(hinst, dwVersion, lplpDirectInput, punkOuter);

  return 1;
}

__noinline static void dinput_hook() {
  HMODULE hm;
  hm = LoadSysMod(sDInput);
  if (hm) {
    pModName = sDInput;
    oDirectInputCreateA = (DirectInputCreateA_fn)GetProcAddress(hm,"DirectInputCreateA");
    oDirectInputCreateEx = (DirectInputCreateEx_fn)GetProcAddress(hm,"DirectInputCreateEx");
    oDirectInputCreateW = (DirectInputCreateW_fn)GetProcAddress(hm,"DirectInputCreateW");
    oDllGetClassObject = (DllGetClassObject_fn)GetProcAddress(hm,"DllGetClassObject");
    oDllRegisterServer = (DllRegisterServer_fn)GetProcAddress(hm,"DllRegisterServer");
    oDllUnregisterServer = (DllUnregisterServer_fn)GetProcAddress(hm,"DllUnregisterServer");
    if (oDirectInputCreateA)
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oDirectInputCreateA, &hm);
  }
}

#endif // __DINPUT_DLL_H

