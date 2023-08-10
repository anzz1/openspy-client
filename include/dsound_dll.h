// dsound_dll.h

#ifndef __DSOUND_DLL_H
#define __DSOUND_DLL_H

#include "include/global.h"
#include "include/shared.h"

typedef long (__stdcall *DirectSoundCaptureCreate_fn)(LPGUID lpGUID, LPVOID /* LPDIRECTSOUNDCAPTURE */ *lplpDSC, /* LPUNKNOWN */ LPVOID punkOuter);
DirectSoundCaptureCreate_fn oDirectSoundCaptureCreate = 0;

typedef long (__stdcall *DirectSoundCaptureCreate8_fn)(LPCGUID lpcGUID, LPVOID /* LPDIRECTSOUNDCAPTURE8 */ *lplpDSC, /* LPUNKNOWN */ LPVOID punkOuter);
DirectSoundCaptureCreate8_fn oDirectSoundCaptureCreate8 = 0;

typedef long (__stdcall *DirectSoundCaptureEnumerateA_fn)(LPVOID /* LPDSENUMCALLBACK */ lpDSEnumCallback, LPVOID lpContext);
DirectSoundCaptureEnumerateA_fn oDirectSoundCaptureEnumerateA = 0;

typedef long (__stdcall *DirectSoundCaptureEnumerateW_fn)(LPVOID /* LPDSENUMCALLBACK */ lpDSEnumCallback, LPVOID lpContext);
DirectSoundCaptureEnumerateW_fn oDirectSoundCaptureEnumerateW = 0;

typedef long (__stdcall *DirectSoundCreate_fn)(LPGUID lpGuid, LPVOID /* LPDIRECTSOUND */ *ppDS, /* LPUNKNOWN */ LPVOID pUnkOuter);
DirectSoundCreate_fn oDirectSoundCreate = 0;

typedef long (__stdcall *DirectSoundCreate8_fn)(LPCGUID lpcGuidDevice, LPVOID /* LPDIRECTSOUND8 */ *ppDS8, /* LPUNKNOWN */ LPVOID pUnkOuter);
DirectSoundCreate8_fn oDirectSoundCreate8 = 0;

typedef long (__stdcall *DirectSoundEnumerateA_fn)(LPVOID /* LPDSENUMCALLBACK */ lpDSEnumCallback, LPVOID lpContext);
DirectSoundEnumerateA_fn oDirectSoundEnumerateA = 0;

typedef long (__stdcall *DirectSoundEnumerateW_fn)(LPVOID /* LPDSENUMCALLBACK */ lpDSEnumCallback, LPVOID lpContext);
DirectSoundEnumerateW_fn oDirectSoundEnumerateW = 0;

typedef long (__stdcall *DirectSoundFullDuplexCreate_fn)(LPCGUID pcGuidCaptureDevice, LPCGUID pcGuidRenderDevice, LPVOID /* LPCDSCBUFFERDESC */ pcDSCBufferDesc, LPVOID /* LPCDSBUFFERDESC */ pcDSBufferDesc, HWND hWnd, DWORD dwLevel, LPVOID /* LPDIRECTSOUNDFULLDUPLEX */ *ppDSFD, LPVOID /* LPDIRECTSOUNDCAPTUREBUFFER8 */ *ppDSCBuffer8, LPVOID /* LPDIRECTSOUNDBUFFER8 */ *ppDSBuffer8, /* LPUNKNOWN */ LPVOID pUnkOuter);
DirectSoundFullDuplexCreate_fn oDirectSoundFullDuplexCreate = 0;

typedef long (__stdcall *GetDeviceID_fn)(LPCGUID pGuidSrc, LPGUID pGuidDest);
GetDeviceID_fn oGetDeviceID = 0;

long __stdcall p_DirectSoundCaptureCreate(LPGUID lpGUID, LPVOID *lplpDSC, /* LPUNKNOWN */ LPVOID punkOuter) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectSoundCaptureCreate=p_DirectSoundCaptureCreate")
#else
  #pragma comment(linker, "/EXPORT:DirectSoundCaptureCreate=_p_DirectSoundCaptureCreate@12")
#endif

  if (!oDirectSoundCaptureCreate)
    oDirectSoundCaptureCreate = GetSysProc(sDSound, "DirectSoundCaptureCreate");
  if (oDirectSoundCaptureCreate)
    return oDirectSoundCaptureCreate(lpGUID, lplpDSC, punkOuter);

  return 0x80004001; // DSERR_UNSUPPORTED
}

long __stdcall p_DirectSoundCaptureCreate8(LPCGUID lpcGUID, LPVOID *lplpDSC, /* LPUNKNOWN */ LPVOID punkOuter) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectSoundCaptureCreate8=p_DirectSoundCaptureCreate8")
#else
  #pragma comment(linker, "/EXPORT:DirectSoundCaptureCreate8=_p_DirectSoundCaptureCreate8@12")
#endif

  if (!oDirectSoundCaptureCreate8)
    oDirectSoundCaptureCreate8 = GetSysProc(sDSound, "DirectSoundCaptureCreate8");
  if (oDirectSoundCaptureCreate8)
    return oDirectSoundCaptureCreate8(lpcGUID, lplpDSC, punkOuter);

  return 0x80004001; // DSERR_UNSUPPORTED
}

long __stdcall p_DirectSoundCaptureEnumerateA(LPVOID lpDSEnumCallback, LPVOID lpContext) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectSoundCaptureEnumerateA=p_DirectSoundCaptureEnumerateA")
#else
  #pragma comment(linker, "/EXPORT:DirectSoundCaptureEnumerateA=_p_DirectSoundCaptureEnumerateA@8")
#endif

  if (!oDirectSoundCaptureEnumerateA)
    oDirectSoundCaptureEnumerateA = GetSysProc(sDSound, "DirectSoundCaptureEnumerateA");
  if (oDirectSoundCaptureEnumerateA)
    return oDirectSoundCaptureEnumerateA(lpDSEnumCallback, lpContext);

  return 0x80004001; // DSERR_UNSUPPORTED
}

long __stdcall p_DirectSoundCaptureEnumerateW(LPVOID lpDSEnumCallback, LPVOID lpContext) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectSoundCaptureEnumerateW=p_DirectSoundCaptureEnumerateW")
#else
  #pragma comment(linker, "/EXPORT:DirectSoundCaptureEnumerateW=_p_DirectSoundCaptureEnumerateW@8")
#endif

  if (!oDirectSoundCaptureEnumerateW)
    oDirectSoundCaptureEnumerateW = GetSysProc(sDSound, "DirectSoundCaptureEnumerateW");
  if (oDirectSoundCaptureEnumerateW)
    return oDirectSoundCaptureEnumerateW(lpDSEnumCallback, lpContext);

  return 0x80004001; // DSERR_UNSUPPORTED
}

long __stdcall p_DirectSoundCreate(LPGUID lpGuid, LPVOID *ppDS, /* LPUNKNOWN */ LPVOID pUnkOuter) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectSoundCreate=p_DirectSoundCreate")
#else
  #pragma comment(linker, "/EXPORT:DirectSoundCreate=_p_DirectSoundCreate@12")
#endif

  if (!oDirectSoundCreate)
    oDirectSoundCreate = GetSysProc(sDSound, "DirectSoundCreate");
  if (oDirectSoundCreate)
    return oDirectSoundCreate(lpGuid, ppDS, pUnkOuter);

  return 0x80004001; // DSERR_UNSUPPORTED
}

long __stdcall p_DirectSoundCreate8(LPCGUID lpcGuidDevice, LPVOID *ppDS8, /* LPUNKNOWN */ LPVOID pUnkOuter) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectSoundCreate8=p_DirectSoundCreate8")
#else
  #pragma comment(linker, "/EXPORT:DirectSoundCreate8=_p_DirectSoundCreate8@12")
#endif

  if (!oDirectSoundCreate8)
    oDirectSoundCreate8 = GetSysProc(sDSound, "DirectSoundCreate8");
  if (oDirectSoundCreate8)
    return oDirectSoundCreate8(lpcGuidDevice, ppDS8, pUnkOuter);

  return 0x80004001; // DSERR_UNSUPPORTED
}

long __stdcall p_DirectSoundEnumerateA(LPVOID lpDSEnumCallback, LPVOID lpContext) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectSoundEnumerateA=p_DirectSoundEnumerateA")
#else
  #pragma comment(linker, "/EXPORT:DirectSoundEnumerateA=_p_DirectSoundEnumerateA@8")
#endif

  if (!oDirectSoundEnumerateA)
    oDirectSoundEnumerateA = GetSysProc(sDSound, "DirectSoundEnumerateA");
  if (oDirectSoundEnumerateA)
    return oDirectSoundEnumerateA(lpDSEnumCallback, lpContext);

  return 0x80004001; // DSERR_UNSUPPORTED
}

long __stdcall p_DirectSoundEnumerateW(LPVOID lpDSEnumCallback, LPVOID lpContext) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectSoundEnumerateW=p_DirectSoundEnumerateW")
#else
  #pragma comment(linker, "/EXPORT:DirectSoundEnumerateW=_p_DirectSoundEnumerateW@8")
#endif

  if (!oDirectSoundEnumerateW)
    oDirectSoundEnumerateW = GetSysProc(sDSound, "DirectSoundEnumerateW");
  if (oDirectSoundEnumerateW)
    return oDirectSoundEnumerateW(lpDSEnumCallback, lpContext);

  return 0x80004001; // DSERR_UNSUPPORTED
}

long __stdcall p_DirectSoundFullDuplexCreate(LPCGUID pcGuidCaptureDevice, LPCGUID pcGuidRenderDevice, LPVOID pcDSCBufferDesc, LPVOID pcDSBufferDesc, HWND hWnd, DWORD dwLevel, LPVOID *ppDSFD, LPVOID *ppDSCBuffer8, LPVOID *ppDSBuffer8, /* LPUNKNOWN */ LPVOID pUnkOuter) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DirectSoundFullDuplexCreate=p_DirectSoundFullDuplexCreate")
#else
  #pragma comment(linker, "/EXPORT:DirectSoundFullDuplexCreate=_p_DirectSoundFullDuplexCreate@40")
#endif

  if (!oDirectSoundFullDuplexCreate)
    oDirectSoundFullDuplexCreate = GetSysProc(sDSound, "DirectSoundFullDuplexCreate");
  if (oDirectSoundFullDuplexCreate)
    return oDirectSoundFullDuplexCreate(pcGuidCaptureDevice, pcGuidRenderDevice, pcDSCBufferDesc, pcDSBufferDesc, hWnd, dwLevel, ppDSFD, ppDSCBuffer8, ppDSBuffer8, pUnkOuter);

  return 0x80004001; // DSERR_UNSUPPORTED
}

long __stdcall p_GetDeviceID(LPCGUID pGuidSrc, LPGUID pGuidDest) {
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetDeviceID=p_GetDeviceID")
#else
  #pragma comment(linker, "/EXPORT:GetDeviceID=_p_GetDeviceID@8")
#endif

  if (!oGetDeviceID)
    oGetDeviceID = GetSysProc(sDSound, "GetDeviceID");
  if (oGetDeviceID)
    return oGetDeviceID(pGuidSrc, pGuidDest);

  return 0x80004001; // DSERR_UNSUPPORTED
}

__forceinline static void dsound_hook() {
  HMODULE hm;
  hm = LoadSysMod(sDSound);
  if (hm) {
    pModName = sDSound;
    oDirectSoundCaptureCreate = (DirectSoundCaptureCreate_fn)GetProcAddress(hm,"DirectSoundCaptureCreate");
    oDirectSoundCaptureCreate8 = (DirectSoundCaptureCreate8_fn)GetProcAddress(hm,"DirectSoundCaptureCreate8");
    oDirectSoundCaptureEnumerateA = (DirectSoundCaptureEnumerateA_fn)GetProcAddress(hm,"DirectSoundCaptureEnumerateA");
    oDirectSoundCaptureEnumerateW = (DirectSoundCaptureEnumerateW_fn)GetProcAddress(hm,"DirectSoundCaptureEnumerateW");
    oDirectSoundCreate = (DirectSoundCreate_fn)GetProcAddress(hm,"DirectSoundCreate");
    oDirectSoundCreate8 = (DirectSoundCreate8_fn)GetProcAddress(hm,"DirectSoundCreate8");
    oDirectSoundEnumerateA = (DirectSoundEnumerateA_fn)GetProcAddress(hm,"DirectSoundEnumerateA");
    oDirectSoundEnumerateW = (DirectSoundEnumerateW_fn)GetProcAddress(hm,"DirectSoundEnumerateW");
    oDirectSoundFullDuplexCreate = (DirectSoundFullDuplexCreate_fn)GetProcAddress(hm,"DirectSoundFullDuplexCreate");
    oGetDeviceID = (GetDeviceID_fn)GetProcAddress(hm,"GetDeviceID");
    oDllGetClassObject = (DllGetClassObject_fn)GetProcAddress(hm,"DllGetClassObject");
    if (oDirectSoundCreate)
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oDirectSoundCreate, &hm);
  }
}

#endif // __DSOUND_DLL_H

