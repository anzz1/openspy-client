// game_ut3.h

#ifndef __GAME_UT3_H
#define __GAME_UT3_H

#include "include/global.h"

// GSMD5Print
__forceinline static void ut3_patch_gsmd5print() {
  BYTE patch[] = {0x55,0x8B,0xEC,0x8B,0x55,0x0C,0x33,0xC0,0x56,0x8B,0x75,0x08,0x0F,0x1F,0x40,0x00,0x0F,0xB6,0x0C,0x30,0xC1,0xE9,0x04,0x0F,0xB6,0x89,0x50,0xA4,0xB4,0x01,0x88,0x0C,0x42,0x0F,0xB6,0x0C,0x30,0x83,0xE1,0x0F,0x0F,0xB6,0x89,0x50,0xA4,0xB4,0x01,0x88,0x4C,0x42,0x01,0x40,0x83,0xF8,0x10,0x72,0xD7,0xC6,0x42,0x20,0x00,0x5E,0x5D,0xC3};
  write_mem(0x01243A50, patch, sizeof(patch));
}

// Strings
__forceinline static void ut3_patch_strings() {
	write_mem((void*)0x01D2AE70, "gpsp.openspy.net", 17);
	write_mem((void*)0x01D2A738, "gpcm.openspy.net", 17);
	write_mem((void*)0x01D27DB8, "%s.available.openspy.net", 25);
	write_mem((void*)0x01D2E18C, "%s.ms%d.openspy.net", 20);
	write_mem((void*)0x01B3D338, "http://%s.sake.openspy.net/SakeStorageServer/StorageServer.asmx", 64);
	write_mem((void*)0x01D27CA0, "http://%s.sake.openspy.net/SakeStorageServer/StorageServer.asmx", 64);
	write_mem((void*)0x01B3D3E8, "http://%s.comp.pubsvs.openspy.net/CompetitionService/CompetitionService.asmx", 77);
	write_mem((void*)0x01D27AD0, "http://%s.comp.pubsvs.openspy.net/CompetitionService/CompetitionService.asmx", 77);
	write_mem((void*)0x01D29634, "%s.master.openspy.net", 22);
	write_mem((void*)0x01D27E90, "http://motd.openspy.net/motd/motd.asp", 22);
	write_mem((void*)0x01D27E28, "http://motd.openspy.net/motd/vercheck.asp", 42);
	write_mem((void*)0x01D27F08, "http://motd.openspy.net/motd/vercheck.asp", 42);
	write_mem((void*)0x01D27380, "http://%s.auth.pubsvs.openspy.net/AuthService/AuthService.asmx\x00", 64);
}

__forceinline static void patch_ut3() {
  ut3_patch_gsmd5print();
  ut3_patch_strings();
  gs_replace_pubkey();
}

#endif // __GAME_UT3_H
