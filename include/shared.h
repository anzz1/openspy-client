// shared.h

#ifndef __SHARED_H
#define __SHARED_H

#include "include/global.h"

static const char* sDInput = "dinput8.dll";
static const char* sDSound = "dsound.dll";
static const char* pModName = 0;

typedef long (__stdcall *DllRegisterServer_fn)(void);
DllRegisterServer_fn oDllRegisterServer = 0;

typedef long (__stdcall *DllUnregisterServer_fn)(void);
DllUnregisterServer_fn oDllUnregisterServer = 0;

typedef long (__stdcall *DllGetClassObject_fn)(REFCLSID rclsid, REFIID riid, LPVOID *ppv);
DllGetClassObject_fn oDllGetClassObject = 0;

long __stdcall p_DllCanUnloadNow(void) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DllCanUnloadNow=p_DllCanUnloadNow")
#else
  #pragma comment(linker, "/EXPORT:DllCanUnloadNow=_p_DllCanUnloadNow@0")
#endif

  return 1;
}

long __stdcall p_DllRegisterServer(void) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DllRegisterServer=p_DllRegisterServer")
#else
  #pragma comment(linker, "/EXPORT:DllRegisterServer=_p_DllRegisterServer@0")
#endif

  if (pModName == sDInput) {
    if (!oDllRegisterServer)
      oDllRegisterServer = GetSysProc(sDInput, "DllRegisterServer");
    if (oDllRegisterServer)
      return oDllRegisterServer();
  }

  return 1;
}

long __stdcall p_DllUnregisterServer(void) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DllUnregisterServer=p_DllUnregisterServer")
#else
  #pragma comment(linker, "/EXPORT:DllUnregisterServer=_p_DllUnregisterServer@0")
#endif

  if (pModName == sDInput) {
    if (!oDllUnregisterServer)
      oDllUnregisterServer = GetSysProc(sDInput, "DllUnregisterServer");
    if (oDllUnregisterServer)
      return oDllUnregisterServer();
  }

  return 1;
}

long __stdcall p_DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DllGetClassObject=p_DllGetClassObject")
#else
  #pragma comment(linker, "/EXPORT:DllGetClassObject=_p_DllGetClassObject@12")
#endif

  if (pModName) {
    if (!oDllGetClassObject)
      oDllGetClassObject = GetSysProc(pModName, "DllGetClassObject");
    if (oDllGetClassObject)
      return oDllGetClassObject(rclsid, riid, ppv);
  }

  return 1;
}

#endif // __SHARED_H

