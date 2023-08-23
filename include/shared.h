// shared.h

#ifndef __SHARED_H
#define __SHARED_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

static const char* sDInput = "dinput.dll";
static const char* sDInput8 = "dinput8.dll";
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

  if (pModName == sDInput || pModName == sDInput8) {
    if (!oDllRegisterServer)
      oDllRegisterServer = GetSysProc(pModName, "DllRegisterServer");
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

  if (pModName == sDInput || pModName == sDInput8) {
    if (!oDllUnregisterServer)
      oDllUnregisterServer = GetSysProc(pModName, "DllUnregisterServer");
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

#ifndef _WIN64
__noinline static void ue2_patch_ipdrv() {
  HMODULE ipdrv = LoadLibraryA("IpDrv.dll");
  if (ipdrv) {
    // disable auth
    WORD search[] = {0x53,0x8B,0x5D,0x08,0x56,0x57,0x89,0x65,0xF0,0x53,0x8B,0xF9,0xC7,0x45,0xFC,0x00,0x00,0x00,0x00,0xE8,_ANY,_ANY,_ANY,_ANY,0x8B,0xF0,0x85,0xF6,0x0F,0x84};
    BYTE patch[] = {0x90,0x90,0x90,0xE9};
    BYTE* ptr = 0;
    GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ipdrv, &ipdrv);

    HOOK_FUNC(ipdrv, gethostbyname, hk_gethostbyname, "wsock32.dll", 52, TRUE);
    HOOK_FUNC(ipdrv, bind, hk_bind, "wsock32.dll", 2, TRUE);

    ptr = find_pattern_mem_wildcard((ULONG_PTR)ipdrv, search, search + 29, TRUE);
    if (ptr)
      write_mem(ptr+26, patch, 4);
  }
}
#endif // _WIN64

#endif // __SHARED_H
