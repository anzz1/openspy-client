// game_sta2.h

#ifndef __GAME_STA2_H
#define __GAME_STA2_H

/* According to the game's "NetHelp.txt", the following ports are required:

        DirectPlay 8 Ports

        2300..2400 UDP inbound and outbound
        6073       TCP inbound and outbound

        GameSpy Ports

        80      TCP, outbound
        6500    UDP, inbound
        6667    TCP, outbound
        13139   UDP, inbound and outbound
        27900   UDP, inbound and outbound
        28900   TCP, outbound
        29900   TCP, outbound
        29901   TCP, outbound

The documentation stating port 6073 as TCP seems to be an error. 6073/udp gets dynamically mapped by picoupnp,
and according to Microsoft documentation [MC-DPLHP], the standard assignment for directplay8 uses 6073/udp.

NAT-PMP is used to map the GameSpy ports, and UPNP is used to map the DirectPlay ports, so both must be enabled on the host's router.
Clients do not seem to need to have port forwarding in place to be able to join a game and play.

Port 27900 is stated to be required but is not automatically mapped, and does not seem to be required for multiplayer functionality.
Even with a manually created NAT rule for 27900/udp, there are no hits.

~ Ligushka 2/7/2025
*/

#include "include/global.h"
#include "iathook/iathook.h"

int __stdcall hk_bind(SOCKET s, struct sockaddr* addr, int namelen);
LPHOSTENT __stdcall hk_gethostbyname(const char* name);

LPHOSTENT __stdcall sta2_hk_gethostbyname(const char* name) {
    // The game's "gamespy.cfg" specifies this server address several times, to "re-direct through activision".
    // Any other GameSpy references are handled by openspy-client's globally hooked gethostbyname function.
    if (name && !__strcmp(name, "STArmada2.activision.com")) 
        return ogethostbyname("master.openspy.net");
    // Speed up the lobby connection by avoiding a DNS lookup timeout by redirecting away from defunct MOTD domain to OpenSpy's.
    else if (name && !__strcmp(name, "www.armada2.com")) 
        return ogethostbyname("motd.openspy.net");
    else
        return hk_gethostbyname(name);
}

__forceinline static void sta2_hook_gs(HMODULE mod) {
    HOOK_FUNC(0, gethostbyname, sta2_hk_gethostbyname, "ws2_32.dll", 52, TRUE); // the only call to gethostbyname in armada2.exe is in Transport::GetLocalIPAddresses, so this may not be needed
    HOOK_FUNC(mod, gethostbyname, sta2_hk_gethostbyname, "ws2_32.dll", 52, TRUE);
    HOOK_FUNC(mod, bind, hk_bind, "ws2_32.dll", 2, TRUE);
}

// DirectPlay Voice initialization crashes the game on modern operating systems, just like Star Trek: Legacy.
// Even the GOG version still needs this, since their bypasses are only for TCP/IP LAN games.
__forceinline static void sta2_disable_net_voice(HMODULE mod) {

    // in Network::DirectPlay::GameCreate, nop call to Network::Lobby::GetVoiceSettings and jz -> jmp past the voice check
    BYTE search[] = { 0xE8, 0xF8, 0x04, 0x01, 0x00, 0x8A, 0x48, 0x28 };
    BYTE patch[] = { 0xE9, 0xA4, 0x00, 0x00 };

    // nop call to Network::Lobby::GetVoiceSettings
    WORD search2[] = { _ANY, _ANY, _ANY, _ANY, 0x00, 0x8A, 0x48, 0x28, 0x51 };

    // jnz -> jmp in Network::Lobby::GetVoiceSettings
    BYTE search3[] = { 0x85, 0xC0, 0x75, 0x34, 0x56, 0x6A, 0x44, 0xE8 };
    BYTE patch3[] = { 0xEB }; // jnz -> jmp

    // jnz -> jmp in Network::Lobby::GetVoiceSettingsAvailable to always return 0
    BYTE search4[] = { 0x74, 0x5E, 0x56, 0x8B, 0x35, 0x14 };

    BYTE* ptr = find_pattern_mem((ULONG_PTR)mod, search, search + 7, TRUE);
    if (ptr)
        nop_mem(ptr, 10);
    write_mem(ptr + 10, patch, 4);

    ptr = find_pattern_mem_wildcard((ULONG_PTR)mod, search2, search2 + 8, TRUE);
    if (ptr)
        nop_mem(ptr, 8);

    ptr = find_pattern_mem((ULONG_PTR)mod, search3, search3 + 7, TRUE);
    if (ptr)
        write_mem(ptr + 2, patch3, 1);

    ptr = find_pattern_mem((ULONG_PTR)mod, search4, search4 + 5, TRUE);
    if (ptr)
        write_mem(ptr, patch3, 1);
}

// Fix crash in Program::SystemOpen when the system path environment variable is too long.
// Crash affects versions 1.1, 1.0, and demo.
// Patched in GOG version and community "Patch Project 1.2.5".
__forceinline static void sta2_fix_path_crash() {
    BYTE search[] = { 0x85, 0xC0, 0x74, 0x3F, 0x68 };
    BYTE patch[] = { 0xEB };

    BYTE* ptr = find_pattern_mem(0, search, search + 4, TRUE);
    if (ptr)
        write_mem(ptr + 2, patch, 1);
}

// GOG version patches out a portion of this condition check of the return value of Transport::GetStatus in order to prevent entering the GameSpy lobby altogether.
__forceinline static void sta2_gog_restore_state_check() {
    BYTE search[] = { 0x83, 0xF8, 0x16, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x83, 0xF8, 0x3A, 0x0F, 0x8D, 0x94, 0x00 };
    BYTE patch[] = { 0x0F, 0x8E, 0x9D, 0x00, 0x00, 0x00 };

    BYTE* ptr = find_pattern_mem(0, search, search + 15, TRUE);
    if (ptr)
        write_mem(ptr + 3, patch, 6);
}

__noinline static void patch_sta2() {
    sta2_fix_path_crash();

    HMODULE mod = GetModuleHandleA("NetworkManager.dll");
    if (mod) {
        sta2_hook_gs(mod);
        sta2_disable_net_voice(mod);
        sta2_gog_restore_state_check();
    }
}

#endif // __GAME_STA2_H
