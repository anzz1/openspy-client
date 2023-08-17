// game_pk.h

#ifndef __GAME_PK_H
#define __GAME_PK_H

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen); 
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

// todo: 
//   - find by pattern to accept multiple versions, replace E8 XX XX XX XX with func ptr
//   - incomplete, some rdtsc crashes fixed when PC fast but still get Djibout'd from servers when PC uptime is too long (2147483647/1000/60/60/24) = ~25d
//   - probably a million of other crashes too, game seems very buggy

__forceinline static void pk_fix_rdtsc_div(HMODULE engine) {
  BYTE aulldiv_sig[] = {0x53,0x56,0x8B,0x44,0x24,0x18,0x0B,0xC0,0x75,0x18,0x8B,0x4C,0x24,0x14};

  // check _aulldiv is at right place
  if (!__memcmp((void*)((DWORD)engine+0x002881C0), aulldiv_sig, sizeof(aulldiv_sig))) {
    BYTE match1[] = {0x33,0xC0,0x33,0xD2,0x0F,0x31,0xF7,0x74,0x24,0x04,0x89,0x04,0x24,0x8B,0x04,0x24,0x83,0xC4,0x08,0xC3,0xCC,0xCC};
    BYTE patch1[] = {0x33,0xD2,0x52,0x50,0x33,0xC0,0x0F,0x31,0x52,0x50,0xE8,0x24,0x6D,0x28,0x00,0x89,0x04,0x24,0x83,0xC4,0x08,0xC3};
    BYTE match2[] = {0x89,0x44,0x24,0x2C,0xD9,0x6C,0x24,0x18,0x33,0xC0,0x33,0xD2,0x0F,0x31,0xF7,0x74,0x24,0x2C,0x89,0x44,0x24,0x28,0x8B,0x4C,0x24,0x28,0x89,0x4E,0x04};
    BYTE patch2[] = {0xD9,0x6C,0x24,0x18,0x33,0xD2,0x52,0x50,0x33,0xC0,0x0F,0x31,0x52,0x50,0xE8,0x18,0xA1,0x18,0x00,0x89,0x44,0x24,0x28,0x89,0x46,0x04,0x90,0x90,0x90};

    patch_if_match((void*)((DWORD)engine+0x0000148D), match1, patch1, sizeof(match1), sizeof(patch1));
    patch_if_match((void*)((DWORD)engine+0x000FE095), match2, patch2, sizeof(match2), sizeof(patch2));
  }
}

// Enable GameSpy
static __int64 ragdolldata = (1i64 << 36);
long __stdcall pk_hk_RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
  long ret = oRegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);

  if (ret && lpValueName && !__strncmp(lpValueName, "RagdollData", 11)) {
    if (lpData) {
      char hex[5];
      switch (lpValueName[11]) {
        case 48:
          *(unsigned long*)lpData = (*(unsigned long*)h2hex((short)(((ragdolldata & 0xFFF) << 4) | (ragdolldata & 0xF)),hex) ^ 0x38F49EE9);
          break;
        case 49:
          *(unsigned long*)lpData = (*(unsigned long*)h2hex((short)(ragdolldata >> 12),hex) ^ 0x36614A8B);
          break;
        case 50:
          *(unsigned long*)lpData = (*(unsigned long*)h2hex((short)((ragdolldata % 0xFFFFi64) ^ (short)0x9249),hex) ^ 0x399E29A5);
          break;
        case 51:
          *(unsigned long*)lpData = (*(unsigned long*)h2hex((short)((ragdolldata >> 28) | (ragdolldata & 0xF000)),hex) ^ 0x3ADE68AF);
          break;
        default:
          return ret;
      }
    }
    if (lpType) *lpType = REG_DWORD;
    if (lpcbData) *lpcbData = 4;
    SetLastError(0);
    return 0;
  }
  return ret;
}

__forceinline static void pk_hook_gs(HMODULE engine) {
  //ragdolldata = (DWORD)(GetTickCount() ^ 0xC4FEB4B3) | ((0xFFi64 & GetTickCount()) << 32) | (1i64 << 36);
  ragdolldata = (__rdtsc() & 0xFFFFFFFFFFi64) | (1i64 << 36);
  oRegQueryValueExA = (RegQueryValueExA_fn)detour_iat_func(engine, "RegQueryValueExA", (void*)pk_hk_RegQueryValueExA, 0, 0, TRUE);

  if (ogethostbyname)
    detour_iat_func(engine, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);
  else
    ogethostbyname = (gethostbyname_fn)detour_iat_func(engine, "gethostbyname", (void*)hk_gethostbyname, "ws2_32.dll", 52, TRUE);

  if (obind)
    detour_iat_func(engine, "bind", (void*)hk_bind, "ws2_32.dll", 2, TRUE);
  else
    obind = (bind_fn)detour_iat_func(engine, "bind", (void*)hk_bind, "ws2_32", 2, TRUE);
}

static void patch_pk() {
  HMODULE engine = GetModuleHandleA("Engine.dll");
  if (engine) {
    pk_hook_gs(engine);
    pk_fix_rdtsc_div(engine);
  }
}

__declspec(naked) void _alldiv()
{
  __asm {
    push    edi
    push    esi
    push    ebx
    xor     edi,edi
    mov     eax,dword ptr [esp+14h]
    or      eax,eax
    jge     L1
    inc     edi
    mov     edx,dword ptr [esp+10h]
    neg     eax
    neg     edx
    sbb     eax,0
    mov     dword ptr [esp+14h],eax
    mov     dword ptr [esp+10h],edx
L1:
    mov     eax,dword ptr [esp+1Ch]
    or      eax,eax
    jge     L2
    inc     edi
    mov     edx,dword ptr [esp+18h]
    neg     eax
    neg     edx
    sbb     eax,0
    mov     dword ptr [esp+1Ch],eax
    mov     dword ptr [esp+18h],edx
L2:
    or      eax,eax
    jne     L3
    mov     ecx,dword ptr [esp+18h]
    mov     eax,dword ptr [esp+14h]
    xor     edx,edx
    div     ecx
    mov     ebx,eax
    mov     eax,dword ptr [esp+10h]
    div     ecx
    mov     edx,ebx
    jmp     L4
L3:
    mov     ebx,eax
    mov     ecx,dword ptr [esp+18h]
    mov     edx,dword ptr [esp+14h]
    mov     eax,dword ptr [esp+10h]
L5:
    shr     ebx,1
    rcr     ecx,1
    shr     edx,1
    rcr     eax,1
    or      ebx,ebx
    jne     L5
    div     ecx
    mov     esi,eax
    mul     dword ptr [esp+1Ch]
    mov     ecx,eax
    mov     eax,dword ptr [esp+18h]
    mul     esi
    add     edx,ecx
    jb      L6
    cmp     edx,dword ptr [esp+14h]
    ja      L6
    jb      L7
    cmp     eax,dword ptr [esp+10h]
    jbe     L7
L6:
    dec     esi
L7:
    xor     edx,edx
    mov     eax,esi
L4:
    dec     edi
    jne     L8
    neg     edx
    neg     eax
    sbb     edx,0
L8:
    pop     ebx
    pop     esi
    pop     edi
    ret     10h
  }
}

#endif // __GAME_PK_H
