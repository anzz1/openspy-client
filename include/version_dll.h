// version_dll.h

#ifndef __VERSION_DLL_H
#define __VERSION_DLL_H

#include "include/global.h"

static const char* sVersion = "version.dll";

typedef BOOL (__stdcall *GetFileVersionInfoA_fn)(LPCSTR lptstrFilename, DWORD dwHandle,DWORD dwLen, LPVOID lpData);
GetFileVersionInfoA_fn oGetFileVersionInfoA = 0;

typedef int (__stdcall *GetFileVersionInfoByHandle_fn)(int hMem, LPCWSTR lpFileName, int v2, int v3);
GetFileVersionInfoByHandle_fn oGetFileVersionInfoByHandle = 0;

typedef BOOL(__stdcall *GetFileVersionInfoExA_fn)(DWORD dwFlags, LPCSTR lpwstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData);
GetFileVersionInfoExA_fn oGetFileVersionInfoExA = 0;

typedef BOOL (__stdcall *GetFileVersionInfoExW_fn)(DWORD dwFlags, LPCWSTR lpwstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData);
GetFileVersionInfoExW_fn oGetFileVersionInfoExW = 0;

typedef DWORD (__stdcall *GetFileVersionInfoSizeA_fn)(LPCSTR lptstrFilename, LPDWORD lpdwHandle);
GetFileVersionInfoSizeA_fn oGetFileVersionInfoSizeA = 0;

typedef DWORD (__stdcall *GetFileVersionInfoSizeExA_fn)(DWORD dwFlags, LPCSTR lpwstrFilename, LPDWORD lpdwHandle);
GetFileVersionInfoSizeExA_fn oGetFileVersionInfoSizeExA = 0;

typedef DWORD (__stdcall *GetFileVersionInfoSizeExW_fn)(DWORD dwFlags, LPCWSTR lpwstrFilename, LPDWORD lpdwHandle);
GetFileVersionInfoSizeExW_fn oGetFileVersionInfoSizeExW = 0;

typedef DWORD (__stdcall *GetFileVersionInfoSizeW_fn)(LPCWSTR lptstrFilename, LPDWORD lpdwHandle);
GetFileVersionInfoSizeW_fn oGetFileVersionInfoSizeW = 0;

typedef BOOL (__stdcall *GetFileVersionInfoW_fn)(LPCWSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData);
GetFileVersionInfoW_fn oGetFileVersionInfoW = 0;

typedef DWORD (__stdcall *VerFindFileA_fn)(DWORD uFlags, LPCSTR szFileName, LPCSTR szWinDir, LPCSTR szAppDir, LPSTR szCurDir, PUINT lpuCurDirLen, LPSTR szDestDir, PUINT lpuDestDirLen);
VerFindFileA_fn oVerFindFileA = 0;

typedef DWORD (__stdcall *VerFindFileW_fn)(DWORD uFlags, LPCWSTR szFileName, LPCWSTR szWinDir, LPCWSTR szAppDir, LPWSTR szCurDir, PUINT lpuCurDirLen, LPWSTR szDestDir, PUINT lpuDestDirLen);
VerFindFileW_fn oVerFindFileW = 0;

typedef DWORD (__stdcall *VerInstallFileA_fn)(DWORD uFlags, LPCSTR szSrcFileName, LPCSTR szDestFileName, LPCSTR szSrcDir, LPCSTR szDestDir, LPCSTR szCurDir, LPSTR szTmpFile, PUINT lpuTmpFileLen);
VerInstallFileA_fn oVerInstallFileA = 0;

typedef DWORD (__stdcall *VerInstallFileW_fn)(DWORD uFlags, LPCWSTR szSrcFileName, LPCWSTR szDestFileName, LPCWSTR szSrcDir, LPCWSTR szDestDir, LPCWSTR szCurDir, LPWSTR szTmpFile, PUINT lpuTmpFileLen);
VerInstallFileW_fn oVerInstallFileW = 0;

typedef DWORD (__stdcall *VerLanguageNameA_fn)(DWORD wLang, LPSTR szLang, DWORD cchLang);
VerLanguageNameA_fn oVerLanguageNameA = 0;

typedef DWORD (__stdcall *VerLanguageNameW_fn)(DWORD wLang, LPWSTR szLang, DWORD cchLang);
VerLanguageNameW_fn oVerLanguageNameW = 0;

typedef BOOL (__stdcall *VerQueryValueA_fn)(LPCVOID pBlock, LPCSTR lpSubBlock, LPVOID * lplpBuffer, PUINT puLen);
VerQueryValueA_fn oVerQueryValueA = 0;

typedef BOOL (__stdcall *VerQueryValueW_fn)(LPCVOID pBlock, LPCWSTR lpSubBlock, LPVOID * lplpBuffer, PUINT puLen);
VerQueryValueW_fn oVerQueryValueW = 0;

BOOL __stdcall p_GetFileVersionInfoA(LPCSTR lptstrFilename, DWORD dwHandle,DWORD dwLen, LPVOID lpData)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoA=p_GetFileVersionInfoA")
#else
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoA=_p_GetFileVersionInfoA@16")
#endif

  if (!oGetFileVersionInfoA) {
    oGetFileVersionInfoA = GetSysProc(sVersion, "GetFileVersionInfoA");
    if (oGetFileVersionInfoA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoA, &hm);
    } else {
      oGetFileVersionInfoA = (void*)-1;
    }
  }
  if (oGetFileVersionInfoA != (void*)-1)
    return oGetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData);

  return FALSE;
}

int __stdcall p_GetFileVersionInfoByHandle(int hMem, LPCWSTR lpFileName, int v2, int v3)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoByHandle=p_GetFileVersionInfoByHandle")
#else
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoByHandle=_p_GetFileVersionInfoByHandle@16")
#endif

  if (!oGetFileVersionInfoByHandle) {
    oGetFileVersionInfoByHandle = GetSysProc(sVersion, "GetFileVersionInfoByHandle");
    if (oGetFileVersionInfoByHandle) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoByHandle, &hm);
    } else {
      oGetFileVersionInfoByHandle = (void*)-1;
    }
  }
  if (oGetFileVersionInfoByHandle != (void*)-1)
    return oGetFileVersionInfoByHandle(hMem, lpFileName, v2, v3);

  return 0;
}

BOOL __stdcall p_GetFileVersionInfoExA(DWORD dwFlags, LPCSTR lpwstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoExA=p_GetFileVersionInfoExA")
#else
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoExA=_p_GetFileVersionInfoExA@20")
#endif

  if (!oGetFileVersionInfoExA) {
    oGetFileVersionInfoExA = GetSysProc(sVersion, "GetFileVersionInfoExA");
    if (oGetFileVersionInfoExA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoExA, &hm);
    } else {
      oGetFileVersionInfoExA = (void*)-1;
    }
  }
  if (oGetFileVersionInfoExA != (void*)-1)
    return oGetFileVersionInfoExA(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);

  return FALSE;
}

BOOL __stdcall p_GetFileVersionInfoExW(DWORD dwFlags, LPCWSTR lpwstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoExW=p_GetFileVersionInfoExW")
#else
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoExW=_p_GetFileVersionInfoExW@20")
#endif

  if (!oGetFileVersionInfoExW) {
    oGetFileVersionInfoExW = GetSysProc(sVersion, "GetFileVersionInfoExW");
    if (oGetFileVersionInfoExW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoExW, &hm);
    } else {
      oGetFileVersionInfoExW = (void*)-1;
    }
  }
  if (oGetFileVersionInfoExW != (void*)-1)
    return oGetFileVersionInfoExW(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);

  return FALSE;
}

DWORD __stdcall p_GetFileVersionInfoSizeA(LPCSTR lptstrFilename, LPDWORD lpdwHandle)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeA=p_GetFileVersionInfoSizeA")
#else
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeA=_p_GetFileVersionInfoSizeA@8")
#endif

  if (!oGetFileVersionInfoSizeA) {
    oGetFileVersionInfoSizeA = GetSysProc(sVersion, "GetFileVersionInfoSizeA");
    if (oGetFileVersionInfoSizeA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoSizeA, &hm);
    } else {
      oGetFileVersionInfoSizeA = (void*)-1;
    }
  }
  if (oGetFileVersionInfoSizeA != (void*)-1)
    return oGetFileVersionInfoSizeA(lptstrFilename, lpdwHandle);

  return 0;
}

DWORD __stdcall p_GetFileVersionInfoSizeExA(DWORD dwFlags, LPCSTR lpwstrFilename, LPDWORD lpdwHandle)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExA=p_GetFileVersionInfoSizeExA")
#else
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExA=_p_GetFileVersionInfoSizeExA@12")
#endif

  if (!oGetFileVersionInfoSizeExA) {
    oGetFileVersionInfoSizeExA = GetSysProc(sVersion, "GetFileVersionInfoSizeExA");
    if (oGetFileVersionInfoSizeExA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoSizeExA, &hm);
    } else {
      oGetFileVersionInfoSizeExA = (void*)-1;
    }
  }
  if (oGetFileVersionInfoSizeExA != (void*)-1)
    return oGetFileVersionInfoSizeExA(dwFlags, lpwstrFilename, lpdwHandle);

  return 0;
}

DWORD __stdcall p_GetFileVersionInfoSizeExW(DWORD dwFlags, LPCWSTR lpwstrFilename, LPDWORD lpdwHandle)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExW=p_GetFileVersionInfoSizeExW")
#else
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExW=_p_GetFileVersionInfoSizeExW@12")
#endif

  if (!oGetFileVersionInfoSizeExW) {
    oGetFileVersionInfoSizeExW = GetSysProc(sVersion, "GetFileVersionInfoSizeExW");
    if (oGetFileVersionInfoSizeExW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoSizeExW, &hm);
    } else {
      oGetFileVersionInfoSizeExW = (void*)-1;
    }
  }
  if (oGetFileVersionInfoSizeExW != (void*)-1)
    return oGetFileVersionInfoSizeExW(dwFlags, lpwstrFilename, lpdwHandle);

  return 0;
}

DWORD __stdcall p_GetFileVersionInfoSizeW(LPCWSTR lptstrFilename, LPDWORD lpdwHandle)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=p_GetFileVersionInfoSizeW")
#else
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=_p_GetFileVersionInfoSizeW@8")
#endif

  if (!oGetFileVersionInfoSizeW) {
    oGetFileVersionInfoSizeW = GetSysProc(sVersion, "GetFileVersionInfoSizeW");
    if (oGetFileVersionInfoSizeW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoSizeW, &hm);
    } else {
      oGetFileVersionInfoSizeW = (void*)-1;
    }
  }
  if (oGetFileVersionInfoSizeW != (void*)-1)
    return oGetFileVersionInfoSizeW(lptstrFilename, lpdwHandle);

  return 0;
}

BOOL __stdcall p_GetFileVersionInfoW(LPCWSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoW=p_GetFileVersionInfoW")
#else
  #pragma comment(linker, "/EXPORT:GetFileVersionInfoW=_p_GetFileVersionInfoW@16")
#endif

  if (!oGetFileVersionInfoW) {
    oGetFileVersionInfoW = GetSysProc(sVersion, "GetFileVersionInfoW");
    if (oGetFileVersionInfoW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoW, &hm);
    } else {
      oGetFileVersionInfoW = (void*)-1;
    }
  }
  if (oGetFileVersionInfoW != (void*)-1)
    return oGetFileVersionInfoW(lptstrFilename, dwHandle, dwLen, lpData);

  return FALSE;
}

DWORD __stdcall p_VerFindFileA(DWORD uFlags, LPCSTR szFileName, LPCSTR szWinDir, LPCSTR szAppDir, LPSTR szCurDir, PUINT lpuCurDirLen, LPSTR szDestDir, PUINT lpuDestDirLen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:VerFindFileA=p_VerFindFileA")
#else
  #pragma comment(linker, "/EXPORT:VerFindFileA=_p_VerFindFileA@32")
#endif

  if (!oVerFindFileA) {
    oVerFindFileA = GetSysProc(sVersion, "VerFindFileA");
    if (oVerFindFileA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oVerFindFileA, &hm);
    } else {
      oVerFindFileA = (void*)-1;
    }
  }
  if (oVerFindFileA != (void*)-1)
    return oVerFindFileA(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen);

  return 0;
}

DWORD __stdcall p_VerFindFileW(DWORD uFlags, LPCWSTR szFileName, LPCWSTR szWinDir, LPCWSTR szAppDir, LPWSTR szCurDir, PUINT lpuCurDirLen, LPWSTR szDestDir, PUINT lpuDestDirLen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:VerFindFileW=p_VerFindFileW")
#else
  #pragma comment(linker, "/EXPORT:VerFindFileW=_p_VerFindFileW@32")
#endif

  if (!oVerFindFileW) {
    oVerFindFileW = GetSysProc(sVersion, "VerFindFileW");
    if (oVerFindFileW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oVerFindFileW, &hm);
    } else {
      oVerFindFileW = (void*)-1;
    }
  }
  if (oVerFindFileW != (void*)-1)
    return oVerFindFileW(uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen, szDestDir, lpuDestDirLen);

  return 0;
}

DWORD __stdcall p_VerInstallFileA(DWORD uFlags, LPCSTR szSrcFileName, LPCSTR szDestFileName, LPCSTR szSrcDir, LPCSTR szDestDir, LPCSTR szCurDir, LPSTR szTmpFile, PUINT lpuTmpFileLen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:VerInstallFileA=p_VerInstallFileA")
#else
  #pragma comment(linker, "/EXPORT:VerInstallFileA=_p_VerInstallFileA@32")
#endif

  if (!oVerInstallFileA) {
    oVerInstallFileA = GetSysProc(sVersion, "VerInstallFileA");
    if (oVerInstallFileA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oVerInstallFileA, &hm);
    } else {
      oVerInstallFileA = (void*)-1;
    }
  }
  if (oVerInstallFileA != (void*)-1)
    return oVerInstallFileA(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen);

  return 0;
}

DWORD __stdcall p_VerInstallFileW(DWORD uFlags, LPCWSTR szSrcFileName, LPCWSTR szDestFileName, LPCWSTR szSrcDir, LPCWSTR szDestDir, LPCWSTR szCurDir, LPWSTR szTmpFile, PUINT lpuTmpFileLen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:VerInstallFileW=p_VerInstallFileW")
#else
  #pragma comment(linker, "/EXPORT:VerInstallFileW=_p_VerInstallFileW@32")
#endif

  if (!oVerInstallFileW) {
    oVerInstallFileW = GetSysProc(sVersion, "VerInstallFileW");
    if (oVerInstallFileW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oVerInstallFileW, &hm);
    } else {
      oVerInstallFileW = (void*)-1;
    }
  }
  if (oVerInstallFileW != (void*)-1)
    return oVerInstallFileW(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, lpuTmpFileLen);

  return 0;
}

DWORD __stdcall p_VerLanguageNameA(DWORD wLang, LPSTR szLang, DWORD cchLang)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:VerLanguageNameA=p_VerLanguageNameA")
#else
  #pragma comment(linker, "/EXPORT:VerLanguageNameA=_p_VerLanguageNameA@12")
#endif

  if (!oVerLanguageNameA) {
    oVerLanguageNameA = GetSysProc(sVersion, "VerLanguageNameA");
    if (oVerLanguageNameA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oVerLanguageNameA, &hm);
    } else {
      oVerLanguageNameA = (void*)-1;
    }
  }
  if (oVerLanguageNameA != (void*)-1)
    return oVerLanguageNameA(wLang, szLang, cchLang);

  return 0;
}

DWORD __stdcall p_VerLanguageNameW(DWORD wLang, LPWSTR szLang, DWORD cchLang)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:VerLanguageNameW=p_VerLanguageNameW")
#else
  #pragma comment(linker, "/EXPORT:VerLanguageNameW=_p_VerLanguageNameW@12")
#endif

  if (!oVerLanguageNameW) {
    oVerLanguageNameW = GetSysProc(sVersion, "VerLanguageNameW");
    if (oVerLanguageNameW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oVerLanguageNameW, &hm);
    } else {
      oVerLanguageNameW = (void*)-1;
    }
  }
  if (oVerLanguageNameW != (void*)-1)
    return oVerLanguageNameW(wLang, szLang, cchLang);

  return 0;
}

BOOL __stdcall p_VerQueryValueA(LPCVOID pBlock, LPCSTR lpSubBlock, LPVOID* lplpBuffer, PUINT puLen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:VerQueryValueA=p_VerQueryValueA")
#else
  #pragma comment(linker, "/EXPORT:VerQueryValueA=_p_VerQueryValueA@16")
#endif

  if (!oVerQueryValueA) {
    oVerQueryValueA = GetSysProc(sVersion, "VerQueryValueA");
    if (oVerQueryValueA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oVerQueryValueA, &hm);
    } else {
      oVerQueryValueA = (void*)-1;
    }
  }
  if (oVerQueryValueA != (void*)-1)
    return oVerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen);

  return FALSE;
}

BOOL __stdcall p_VerQueryValueW(LPCVOID pBlock, LPCWSTR lpSubBlock, LPVOID * lplpBuffer, PUINT puLen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:VerQueryValueW=p_VerQueryValueW")
#else
  #pragma comment(linker, "/EXPORT:VerQueryValueW=_p_VerQueryValueW@16")
#endif

  if (!oVerQueryValueW) {
    oVerQueryValueW = GetSysProc(sVersion, "VerQueryValueW");
    if (oVerQueryValueW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oVerQueryValueW, &hm);
    } else {
      oVerQueryValueW = (void*)-1;
    }
  }
  if (oVerQueryValueW != (void*)-1)
    return oVerQueryValueW(pBlock, lpSubBlock, lplpBuffer, puLen);

  return FALSE;
}

__noinline static void version_hook() {
#ifndef DLL_PROXY_DELAY_LOAD
  HMODULE hm = LoadSysMod(sVersion);
  if (hm) {
    oGetFileVersionInfoA = (GetFileVersionInfoA_fn)GetProcAddress(hm,"GetFileVersionInfoA");
    oGetFileVersionInfoByHandle = (GetFileVersionInfoByHandle_fn)GetProcAddress(hm,"GetFileVersionInfoByHandle");
    oGetFileVersionInfoExA = (GetFileVersionInfoExA_fn)GetProcAddress(hm,"GetFileVersionInfoExA");
    oGetFileVersionInfoExW = (GetFileVersionInfoExW_fn)GetProcAddress(hm,"GetFileVersionInfoExW");
    oGetFileVersionInfoSizeA = (GetFileVersionInfoSizeA_fn)GetProcAddress(hm,"GetFileVersionInfoSizeA");
    oGetFileVersionInfoSizeExA = (GetFileVersionInfoSizeExA_fn)GetProcAddress(hm,"GetFileVersionInfoSizeExA");
    oGetFileVersionInfoSizeExW = (GetFileVersionInfoSizeExW_fn)GetProcAddress(hm,"GetFileVersionInfoSizeExW");
    oGetFileVersionInfoSizeW = (GetFileVersionInfoSizeW_fn)GetProcAddress(hm,"GetFileVersionInfoSizeW");
    oGetFileVersionInfoW = (GetFileVersionInfoW_fn)GetProcAddress(hm,"GetFileVersionInfoW");
    oVerFindFileA = (VerFindFileA_fn)GetProcAddress(hm,"VerFindFileA");
    oVerFindFileW = (VerFindFileW_fn)GetProcAddress(hm,"VerFindFileW");
    oVerInstallFileA = (VerInstallFileA_fn)GetProcAddress(hm,"VerInstallFileA");
    oVerInstallFileW = (VerInstallFileW_fn)GetProcAddress(hm,"VerInstallFileW");
    oVerLanguageNameA = (VerLanguageNameA_fn)GetProcAddress(hm,"VerLanguageNameA");
    oVerLanguageNameW = (VerLanguageNameW_fn)GetProcAddress(hm,"VerLanguageNameW");
    oVerQueryValueA = (VerQueryValueA_fn)GetProcAddress(hm,"VerQueryValueA");
    oVerQueryValueW = (VerQueryValueW_fn)GetProcAddress(hm,"VerQueryValueW");
    if (oGetFileVersionInfoA)
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetFileVersionInfoA, &hm);
  }
#endif // !DLL_PROXY_DELAY_LOAD
}

#endif // __VERSION_DLL_H

