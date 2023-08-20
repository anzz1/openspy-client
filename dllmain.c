// dllmain.c

/*
 * OpenSpy Client
 * https://github.com/anzz1/openspy-client
 *
 */

#include "include/global.h"
#include "include/version_dll.h"
#include "include/dinput_dll.h"
#include "include/dinput8_dll.h"
#include "include/dsound_dll.h"

#include "include/game_cry.h"
#ifndef _WIN64
  #include "include/game_sr2.h"
  #include "include/game_cmr5.h"
  #include "include/game_ut3.h"
  #include "include/game_pk.h"
  #include "include/game_vc2.h"
  #include "include/game_halo.h"
  #include "include/game_aowht.h"
  #include "include/game_swrc.h"
  #include "include/game_fear.h"
  #include "include/game_sam.h"
  #include "include/game_bond.h"
  #include "include/game_dh2k.h"
  #include "include/game_go.h"
  #include "include/game_t3.h"
  #include "include/game_mvau.h"
  #include "include/game_mtg.h"
#endif // !_WIN64

#include "include/picoupnp.h"
#include "iathook/iathook.h"

// Redirect all bind() to 0.0.0.0
static int force_bind_ip = 1;

typedef HINTERNET (__stdcall *InternetOpenUrlA_fn)(HINTERNET hInternet, LPCSTR lpszUrl, LPCSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwFlags, DWORD_PTR dwContext);
InternetOpenUrlA_fn oInternetOpenUrlA = 0;

unsigned long __stdcall portMapThread(void* param) {
  UPNP_AddPortMapping((unsigned short)param, (unsigned long)param >> 16);
  return 0;
}

int __stdcall hk_bind(SOCKET s, struct sockaddr *addr, int namelen) {
  int ret, type;
  int len = sizeof(int);

  if (addr->sa_family != AF_INET)
    return obind(s, addr, namelen);

  // Bind to 0.0.0.0 (any)
  if (force_bind_ip && (*(unsigned long*)(&addr->sa_data[2]) != 0))
    *(unsigned long*)(&addr->sa_data[2]) = 0;

  getsockopt(s, SOL_SOCKET, SO_TYPE, (char*)&type, &len);
  ret = obind(s, addr, namelen);

  if (type == SOCK_STREAM || type == SOCK_DGRAM) {
    unsigned long param = (unsigned long)ntohs(*(unsigned short*)(addr->sa_data));
    if (param == 0) {
      struct sockaddr_in sin;
      int addrlen = sizeof(struct sockaddr_in);
      if(getsockname(s, (struct sockaddr *)&sin, &addrlen) || sin.sin_family != AF_INET || addrlen != sizeof(struct sockaddr_in))
        return ret;
      param = (unsigned long)ntohs(sin.sin_port);
    }
    param |= ((type == SOCK_STREAM ? IPPROTO_TCP : IPPROTO_UDP) << 16);
    CloseHandle(CreateThread(0, 0, portMapThread, (void*)param, 0, 0));
  }

  return ret;
}

LPHOSTENT __stdcall hk_gethostbyname(const char* name) {
  char s[512];
  if (name && gs_copy_string(s, name))
    return ogethostbyname(s);
  else
    return ogethostbyname(name);
}

HANDLE __stdcall hk_WSAAsyncGetHostByName(HWND hWnd, unsigned int wMsg, const char *name, char *buf, int buflen) {
  char s[512];
  if (name && gs_copy_string(s, name))
    return oWSAAsyncGetHostByName(hWnd, wMsg, s, buf, buflen);
  else
    return oWSAAsyncGetHostByName(hWnd, wMsg, name, buf, buflen);
}

HINTERNET __stdcall hk_InternetOpenUrlA(HINTERNET hInternet, LPCSTR lpszUrl, LPCSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwFlags, DWORD_PTR dwContext) {
  char s[512];
  if (lpszUrl && gs_copy_string(s, lpszUrl))
    return oInternetOpenUrlA(hInternet, s, lpszHeaders, dwHeadersLength, dwFlags, dwContext);
  else
    return oInternetOpenUrlA(hInternet, lpszUrl, lpszHeaders, dwHeadersLength, dwFlags, dwContext);
}

static char* securom_msg = "mshta.exe vbscript:Execute(\"msgbox \"\"Your game executable is infested with SecuROM.\"\" & chr(10) & \"\"Process was exit to prevent damage to your operating system.\"\",0,\"\"Notice\"\":close\")";
__forceinline static int securom_check(HMODULE hModule) {
    PIMAGE_DOS_HEADER img_dos_headers;
    PIMAGE_NT_HEADERS img_nt_headers;
    PIMAGE_SECTION_HEADER img_sec_header;
    unsigned int n;
    char path[512];
    char* p;

    if (GetModuleFileNameA(hModule, path, 511)) {
      path[511] = 0;
      p = __strrchr(path, '\\');
      if (p && p-path < 485) {
        __strcpy(++p, "disable_securom_guard.txt");
        if (FileExistsA(path))
          return 0;
      }
    }

    img_dos_headers = (PIMAGE_DOS_HEADER)GetModuleHandleA(0);
    if (img_dos_headers->e_magic != IMAGE_DOS_SIGNATURE)
      return 0;
    img_nt_headers = (PIMAGE_NT_HEADERS)((size_t)img_dos_headers + img_dos_headers->e_lfanew);
    if (img_nt_headers->Signature != IMAGE_NT_SIGNATURE)
      return 0;
    if (img_nt_headers->FileHeader.SizeOfOptionalHeader < 4) // OptionalHeader.Magic
      return 0;
    if (img_nt_headers->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR_MAGIC)
      return 0;

    img_sec_header = (PIMAGE_SECTION_HEADER)((size_t)img_nt_headers + sizeof(img_nt_headers->Signature) + sizeof(img_nt_headers->FileHeader) + img_nt_headers->FileHeader.SizeOfOptionalHeader);
    for (n = 0; n < img_nt_headers->FileHeader.NumberOfSections; n++, img_sec_header++) {
      if (img_sec_header->Name && !__strncmp(img_sec_header->Name, ".securom", 8)) {
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        memset(&si, 0, sizeof(STARTUPINFO));
        memset(&pi, 0, sizeof(PROCESS_INFORMATION));
        if(CreateProcessA(0, securom_msg, 0, 0, 0, 0, 0, 0, &si, &pi)) {
          CloseHandle(pi.hThread);
          CloseHandle(pi.hProcess);
        }
        ExitProcess(1);
        return 1;
      }
    }
    return 0;
}

static int initialized = 0;
int __stdcall DllMain(HINSTANCE hInstDLL, DWORD dwReason, LPVOID lpReserved) {
  if (dwReason == DLL_PROCESS_ATTACH && !initialized) {
    HMODULE hm = 0;
    char* p = 0;
    char s[512];

    initialized = 1;
    DisableThreadLibraryCalls(hInstDLL);

    // Pin this module to memory
    GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)&p_DirectInput8Create, &hm);

    // SecuROM guard
    if (securom_check(hm))
      return 1;

    // Load system directory to memory
    InitSysDir();

    // Proxy DLL feature
    if (GetModuleFileNameA(hm, s, 511)) {
      s[511] = 0;
      p = __strrchr(s, '\\');
      if (p) {
        p++;
        if (!__stricmp(p, sDInput)) // dinput.dll
          dinput_hook();
        else if (!__stricmp(p, sDInput8)) // dinput8.dll
          dinput8_hook();
        else if (!__stricmp(p, sDSound)) // dsound.dll
          dsound_hook();
        else if (!__stricmp(p, sVersion)) // version.dll
          version_hook();
      }
    }

    // Hook API calls
    ogethostbyname = (gethostbyname_fn)detour_iat_func(0, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);
    if (ogethostbyname)
      detour_iat_func(0, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);
    else
      ogethostbyname = (gethostbyname_fn)detour_iat_func(0, "gethostbyname", (void*)hk_gethostbyname, "wsock32.dll", 52, TRUE);

    oWSAAsyncGetHostByName = (WSAAsyncGetHostByName_fn)detour_iat_func(0, "WSAAsyncGetHostByName", (void*)hk_WSAAsyncGetHostByName, "ws2_32.dll", 103, TRUE);
    if (oWSAAsyncGetHostByName)
      detour_iat_func(0, "WSAAsyncGetHostByName", (void*)hk_WSAAsyncGetHostByName, "wsock32.dll", 103, TRUE);
    else
      oWSAAsyncGetHostByName = (WSAAsyncGetHostByName_fn)detour_iat_func(0, "WSAAsyncGetHostByName", (void*)hk_WSAAsyncGetHostByName, "wsock32.dll", 103, TRUE);

    obind = (bind_fn)detour_iat_func(0, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);
    if (obind)
      detour_iat_func(0, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);
    else
      obind = (bind_fn)detour_iat_func(0, "bind", (void*)hk_bind, "wsock32.dll", 2, TRUE);

    oInternetOpenUrlA = (InternetOpenUrlA_fn)detour_iat_func(0, "InternetOpenUrlA", (void*)hk_InternetOpenUrlA, "wininet.dll", 0, TRUE);

    // Per-game patches
    if (GetModuleFileNameA(0, s, 511)) {
      s[511] = 0;
      p = __strrchr(s, '\\');
      if (p) {
        p++;
#ifdef _WIN64
        if (!__stricmp(p, "crysis.exe") || !__stricmp(p, "crysis64.exe") || !__stricmp(p, "crysisdedicatedserver.exe") || !__stricmp(p, "crysiswarsdedicatedserver.exe") || !__stricmp(p, "crysisheadlessserver.exe")) { // Crysis / Crysis Wars (64-bit)
          force_bind_ip = 0;
          patch_cry();
        }
#else // !_WIN64
        if (!__stricmp(p, "sr2_pc.exe")) { // Saints Row 2
          patch_sr2();
        } else if (!__stricmp(p, "cmr5.exe")) { // Colin McRae Rally 2005
          patch_cmr5();
        } else if (!__stricmp(p, "crysis.exe") || !__stricmp(p, "crysisdedicatedserver.exe") || !__stricmp(p, "crysiswarsdedicatedserver.exe") || !__stricmp(p, "crysisheadlessserver.exe")) { // Crysis / Crysis Wars (32-bit)
          force_bind_ip = 0;
          patch_cry();
        } else if (!__stricmp(p, "ut3.exe")) { // Unreal Tournament 3
          patch_ut3();
        } else if (!__stricmp(p, "painkiller.exe")) { // Painkiller
          patch_pk();
        } else if (!__stricmp(p, "halo.exe")) { // Halo CE
          patch_halo();
        } else if (!__stricmp(p, "actofwar_hightreason.exe")) { // Act of War - High Treason
          patch_aowht();
        } else if (!__stricmp(p, "dh2004.exe") || !__stricmp(p, "dh2005.exe")) { // Deer Hunter 2004 / 2005
          patch_dh2k();
        } else if (!__stricmp(p, "globalops.exe") || !__stricmp(p, "goserver.exe")) { // Global Operations
          patch_go();
        } else if (!__stricmp(p, "t3.exe")) { // Terminator 3
          patch_t3();
        } else if (!__stricmp(p, "mxvsatv.exe")) { // MX vs. ATV Unleashed
          patch_mvau();
        } else if (!__stricmp(p, "mtgbattlegrounds.exe")) { // Magic: The Gathering - Battlegrounds
          patch_mtg();
        } else if (!__stricmp(p, "serioussam.exe") || !__stricmp(p, "sam2.exe") || !__stricmp(p, "dedicatedserver.exe")) { // Serious Sam 1 & 2
          force_bind_ip = 0;
          patch_sam();
        } else if (!__stricmp(p, "swrepubliccommando.exe")) { // Star Wars - Republic Commando
          force_bind_ip = 0;
          patch_swrc();
        } else if (!__stricmp(p, "vietcong2.exe") || !__stricmp(p, "vc2ded.exe")) { // Vietcong 2
          force_bind_ip = 0;
          patch_vc2();
        } else if (!__stricmp(p, "fearmp.exe")) { // FEAR (Client)
          force_bind_ip = 0;
          patch_fear_cli();
        } else if (!__stricmp(p, "fearserver.exe")) { // FEAR (Server)
          force_bind_ip = 0;
          patch_fear_srv();
        } else if (!__stricmp(p, "bond.exe") || !__stricmp(p, "bond_ded.exe")) { // James Bond - Nightfire
          force_bind_ip = 0;
          patch_bond();
        } else if (!__stricmp(p, "fear2.exe")) { // FEAR 2
          gs_replace_pubkey(0);
        }
#endif // _WIN64 || !_WIN64
      }
    }
  }

  return TRUE;
}
