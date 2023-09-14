// winmm_dll.h

#ifndef __WINMM_DLL_H
#define __WINMM_DLL_H

#include "include/global.h"

static const char* sWinmm = "winmm.dll";

#ifndef _JOYSTICKAPI_H_
typedef LPVOID LPJOYCAPSA;
typedef LPVOID LPJOYCAPSW;
typedef LPVOID LPJOYINFO;
typedef LPVOID LPJOYINFOEX;
#endif

#ifndef _MCIAPI_H_
typedef UINT (CALLBACK *YIELDPROC)(UINT mciId, DWORD dwYieldData);
#endif

#ifndef _MMEAPI_H_
typedef LPVOID LPAUXCAPSA;
typedef LPVOID LPAUXCAPSW;
typedef LPVOID LPMIDIHDR;
typedef LPVOID LPMIDIINCAPSA;
typedef LPVOID LPMIDIINCAPSW;
typedef LPVOID LPMIDIOUTCAPSA;
typedef LPVOID LPMIDIOUTCAPSW;
typedef LPVOID LPMIXERCAPSA;
typedef LPVOID LPMIXERCAPSW;
typedef LPVOID LPMIXERCONTROLDETAILS;
typedef LPVOID LPMIXERLINEA;
typedef LPVOID LPMIXERLINEW;
typedef LPVOID LPMIXERLINECONTROLSA;
typedef LPVOID LPMIXERLINECONTROLSW;
typedef LPVOID LPMMTIME;
typedef LPVOID LPTASKCALLBACK;
typedef LPCVOID LPCWAVEFORMATEX;
typedef LPVOID LPWAVEHDR;
typedef LPVOID LPWAVEINCAPSA;
typedef LPVOID LPWAVEINCAPSW;
typedef LPVOID LPWAVEOUTCAPSA;
typedef LPVOID LPWAVEOUTCAPSW;
#endif

#ifndef _MMISCAPI_H_
typedef DWORD (__stdcall *DRIVERMSGPROC)(DWORD, DWORD, DWORD_PTR, DWORD_PTR, DWORD_PTR);
typedef DWORD FOURCC;
typedef LPCVOID LPCMMIOINFO;
typedef LPVOID LPMMCKINFO;
typedef LPVOID LPMMIOINFO;
typedef LPVOID LPMMIOPROC;
#endif

#ifndef _MMISCAPI2_H_
typedef LPVOID LPTIMECALLBACK;
#endif

#ifndef _TIMERAPI_H_
typedef LPVOID LPTIMECAPS;
#endif

typedef LONG_PTR (__stdcall *CloseDriver_fn)(HANDLE hDriver, LONG_PTR lParam1, LONG_PTR lParam2);
CloseDriver_fn oCloseDriver = 0;

typedef LONG_PTR (__stdcall *DefDriverProc_fn)(DWORD_PTR dwDriverIdentifier, HANDLE hDriver, UINT uMsg, LONG_PTR lParam1, LONG_PTR lParam2);
DefDriverProc_fn oDefDriverProc = 0;

typedef BOOL (__stdcall *DriverCallback_fn)(DWORD_PTR dwCallback, DWORD dwFlags, HANDLE hDevice, DWORD dwMsg, DWORD_PTR dwUser, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
DriverCallback_fn oDriverCallback = 0;

typedef HMODULE (__stdcall *DrvGetModuleHandle_fn)(HANDLE hDriver);
DrvGetModuleHandle_fn oDrvGetModuleHandle = 0;

typedef HMODULE (__stdcall *GetDriverModuleHandle_fn)(HANDLE hDriver);
GetDriverModuleHandle_fn oGetDriverModuleHandle = 0;

#ifndef _WIN64
typedef DWORD (__stdcall *NotifyCallbackData_fn)(DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3, DWORD_PTR dw4, DWORD_PTR dw5);
NotifyCallbackData_fn oNotifyCallbackData = 0;
#endif // !_WIN64

typedef HANDLE (__stdcall *OpenDriver_fn)(LPCWSTR lpDriverName, LPCWSTR lpSectionName, LONG_PTR lParam);
OpenDriver_fn oOpenDriver = 0;

typedef BOOL (__stdcall *PlaySoundA_fn)(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
PlaySoundA_fn oPlaySound = 0;
PlaySoundA_fn oPlaySoundA = 0;

typedef BOOL (__stdcall *PlaySoundW_fn)(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound);
PlaySoundW_fn oPlaySoundW = 0;

typedef LONG_PTR (__stdcall *SendDriverMessage_fn)(HANDLE hDriver, UINT message, LONG_PTR lParam1, LONG_PTR lParam2);
SendDriverMessage_fn oSendDriverMessage = 0;

#ifndef _WIN64
typedef DWORD (__stdcall *WOW32DriverCallback_fn)(DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3, DWORD_PTR dw4, DWORD_PTR dw5, DWORD_PTR dw6, DWORD_PTR dw7);
WOW32DriverCallback_fn oWOW32DriverCallback = 0;

typedef DWORD (__stdcall *WOW32ResolveMultiMediaHandle_fn)(DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3, DWORD_PTR dw4, DWORD_PTR dw5, DWORD_PTR dw6);
WOW32ResolveMultiMediaHandle_fn oWOW32ResolveMultiMediaHandle = 0;
#endif // !_WIN64

typedef void (__stdcall *WOWAppExit_fn)(LPVOID pUnk);
WOWAppExit_fn oWOWAppExit = 0;

#ifndef _WIN64
typedef UINT (__stdcall *aux32Message_fn)(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3);
aux32Message_fn oaux32Message = 0;
#endif // !_WIN64

typedef UINT (__stdcall *auxGetDevCapsA_fn)(UINT_PTR uDeviceID, LPAUXCAPSA pac, UINT cbac);
auxGetDevCapsA_fn oauxGetDevCapsA = 0;

typedef UINT (__stdcall *auxGetDevCapsW_fn)(UINT_PTR uDeviceID, LPAUXCAPSW pac, UINT cbac);
auxGetDevCapsW_fn oauxGetDevCapsW = 0;

typedef UINT (__stdcall *auxGetNumDevs_fn)(void);
auxGetNumDevs_fn oauxGetNumDevs = 0;

typedef UINT (__stdcall *auxGetVolume_fn)(UINT uDeviceID, LPDWORD pdwVolume);
auxGetVolume_fn oauxGetVolume = 0;

typedef UINT (__stdcall *auxOutMessage_fn)(UINT uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
auxOutMessage_fn oauxOutMessage = 0;

typedef UINT (__stdcall *auxSetVolume_fn)(UINT uDeviceID, DWORD dwVolume);
auxSetVolume_fn oauxSetVolume = 0;

#ifndef _WIN64
typedef UINT (__stdcall *joy32Message_fn)(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3);
joy32Message_fn ojoy32Message = 0;
#endif // !_WIN64

typedef UINT (__stdcall *joyConfigChanged_fn)(DWORD dwFlags);
joyConfigChanged_fn ojoyConfigChanged = 0;

typedef UINT (__stdcall *joyGetDevCapsA_fn)(UINT_PTR uJoyID, LPJOYCAPSA pjc, UINT cbjc);
joyGetDevCapsA_fn ojoyGetDevCapsA = 0;

typedef UINT (__stdcall *joyGetDevCapsW_fn)(UINT_PTR uJoyID, LPJOYCAPSW pjc, UINT cbjc);
joyGetDevCapsW_fn ojoyGetDevCapsW = 0;

typedef UINT (__stdcall *joyGetNumDevs_fn)(void);
joyGetNumDevs_fn ojoyGetNumDevs = 0;

typedef UINT (__stdcall *joyGetPos_fn)(UINT uJoyID, LPJOYINFO pji);
joyGetPos_fn ojoyGetPos = 0;

typedef UINT (__stdcall *joyGetPosEx_fn)(UINT uJoyID, LPJOYINFOEX pji);
joyGetPosEx_fn ojoyGetPosEx = 0;

typedef UINT (__stdcall *joyGetThreshold_fn)(UINT uJoyID, LPUINT puThreshold);
joyGetThreshold_fn ojoyGetThreshold = 0;

typedef UINT (__stdcall *joyReleaseCapture_fn)(UINT uJoyID);
joyReleaseCapture_fn ojoyReleaseCapture = 0;

typedef UINT (__stdcall *joySetCapture_fn)(HWND hwnd, UINT uJoyID, UINT uPeriod, BOOL fChanged);
joySetCapture_fn ojoySetCapture = 0;

typedef UINT (__stdcall *joySetThreshold_fn)(UINT uJoyID, UINT uThreshold);
joySetThreshold_fn ojoySetThreshold = 0;

#ifndef _WIN64
typedef UINT (__stdcall *mci32Message_fn)(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3);
mci32Message_fn omci32Message = 0;
#endif // !_WIN64

typedef BOOL (__stdcall *mciDriverNotify_fn)(HWND hWndCallBack, UINT uDevID, UINT uStatus);
mciDriverNotify_fn omciDriverNotify = 0;

typedef UINT (__stdcall *mciDriverYield_fn)(UINT uDeviceID);
mciDriverYield_fn omciDriverYield = 0;

typedef BOOL (__stdcall *mciExecute_fn)(LPCSTR pszCommand);
mciExecute_fn omciExecute = 0;

typedef BOOL (__stdcall *mciFreeCommandResource_fn)(UINT uTable);
mciFreeCommandResource_fn omciFreeCommandResource = 0;

typedef HANDLE (__stdcall *mciGetCreatorTask_fn)(UINT IDDevice);
mciGetCreatorTask_fn omciGetCreatorTask = 0;

typedef UINT (__stdcall *mciGetDeviceIDA_fn)(LPCSTR lpstrName);
mciGetDeviceIDA_fn omciGetDeviceIDA = 0;

typedef UINT (__stdcall *mciGetDeviceIDFromElementIDA_fn)(DWORD dwElementID, LPCSTR lpStrType);
mciGetDeviceIDFromElementIDA_fn omciGetDeviceIDFromElementIDA = 0;

typedef UINT (__stdcall *mciGetDeviceIDFromElementIDW_fn)(DWORD dwElementID, LPCWSTR lpStrType);
mciGetDeviceIDFromElementIDW_fn omciGetDeviceIDFromElementIDW = 0;

typedef UINT (__stdcall *mciGetDeviceIDW_fn)(LPCWSTR lpstrName);
mciGetDeviceIDW_fn omciGetDeviceIDW = 0;

typedef DWORD_PTR (__stdcall *mciGetDriverData_fn)(UINT IDDevice);
mciGetDriverData_fn omciGetDriverData = 0;

typedef BOOL (__stdcall *mciGetErrorStringA_fn)(DWORD fdwError, LPSTR lpszErrorText, UINT cchErrorText);
mciGetErrorStringA_fn omciGetErrorStringA = 0;

typedef BOOL (__stdcall *mciGetErrorStringW_fn)(DWORD fdwError, LPWSTR lpszErrorText, UINT cchErrorText);
mciGetErrorStringW_fn omciGetErrorStringW = 0;

typedef YIELDPROC (__stdcall *mciGetYieldProc_fn)(UINT IDDevice, LPDWORD lpdwYieldData);
mciGetYieldProc_fn omciGetYieldProc = 0;

typedef UINT (__stdcall *mciLoadCommandResource_fn)(HINSTANCE hInstance, LPCWSTR lpResName, UINT wType);
mciLoadCommandResource_fn omciLoadCommandResource = 0;

typedef DWORD (__stdcall *mciSendCommandA_fn)(UINT IDDevice, UINT uMsg, DWORD_PTR fdwCommand, DWORD_PTR dwParam);
mciSendCommandA_fn omciSendCommandA = 0;

typedef DWORD (__stdcall *mciSendCommandW_fn)(UINT IDDevice, UINT uMsg, DWORD_PTR fdwCommand, DWORD_PTR dwParam);
mciSendCommandW_fn omciSendCommandW = 0;

typedef DWORD (__stdcall *mciSendStringA_fn)(LPCSTR lpszCommand, LPSTR lpszReturnString, UINT cchReturn, HWND hwndCallback);
mciSendStringA_fn omciSendStringA = 0;

typedef DWORD (__stdcall *mciSendStringW_fn)(LPCWSTR lpszCommand, LPWSTR lpszReturnString, UINT cchReturn, HWND hwndCallback);
mciSendStringW_fn omciSendStringW = 0;

typedef BOOL (__stdcall *mciSetDriverData_fn)(UINT IDDevice, DWORD_PTR data);
mciSetDriverData_fn omciSetDriverData = 0;

typedef BOOL (__stdcall *mciSetYieldProc_fn)(UINT IDDevice, YIELDPROC yp, DWORD dwYieldData);
mciSetYieldProc_fn omciSetYieldProc = 0;

#ifndef _WIN64
typedef UINT (__stdcall *mid32Message_fn)(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3);
mid32Message_fn omid32Message = 0;
#endif // !_WIN64

typedef UINT (__stdcall *midiConnect_fn)(HANDLE hmi, HANDLE hmo, LPVOID lpReserved);
midiConnect_fn omidiConnect = 0;

typedef UINT (__stdcall *midiDisconnect_fn)(HANDLE hmi, HANDLE hmo, LPVOID lpReserved);
midiDisconnect_fn omidiDisconnect = 0;

typedef UINT (__stdcall *midiInAddBuffer_fn)(HANDLE hmi, LPMIDIHDR pmh, UINT cbmh);
midiInAddBuffer_fn omidiInAddBuffer = 0;

typedef UINT (__stdcall *midiInClose_fn)(HANDLE hmi);
midiInClose_fn omidiInClose = 0;

typedef UINT (__stdcall *midiInGetDevCapsA_fn)(UINT_PTR uDeviceID, LPMIDIINCAPSA pmic, UINT cbmic);
midiInGetDevCapsA_fn omidiInGetDevCapsA = 0;

typedef UINT (__stdcall *midiInGetDevCapsW_fn)(UINT_PTR uDeviceID, LPMIDIINCAPSW pmic, UINT cbmic);
midiInGetDevCapsW_fn omidiInGetDevCapsW = 0;

typedef UINT (__stdcall *midiInGetErrorTextA_fn)(UINT mmrError, LPSTR pszText, UINT cchText);
midiInGetErrorTextA_fn omidiInGetErrorTextA = 0;

typedef UINT (__stdcall *midiInGetErrorTextW_fn)(UINT mmrError, LPWSTR pszText, UINT cchText);
midiInGetErrorTextW_fn omidiInGetErrorTextW = 0;

typedef UINT (__stdcall *midiInGetID_fn)(HANDLE hmi, LPUINT puDeviceID);
midiInGetID_fn omidiInGetID = 0;

typedef UINT (__stdcall *midiInGetNumDevs_fn)(void);
midiInGetNumDevs_fn omidiInGetNumDevs = 0;

typedef UINT (__stdcall *midiInMessage_fn)(HANDLE hmi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
midiInMessage_fn omidiInMessage = 0;

typedef UINT (__stdcall *midiInOpen_fn)(LPHANDLE phmi, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
midiInOpen_fn omidiInOpen = 0;

typedef UINT (__stdcall *midiInPrepareHeader_fn)(HANDLE hmi, LPMIDIHDR pmh, UINT cbmh);
midiInPrepareHeader_fn omidiInPrepareHeader = 0;

typedef UINT (__stdcall *midiInReset_fn)(HANDLE hmi);
midiInReset_fn omidiInReset = 0;

typedef UINT (__stdcall *midiInStart_fn)(HANDLE hmi);
midiInStart_fn omidiInStart = 0;

typedef UINT (__stdcall *midiInStop_fn)(HANDLE hmi);
midiInStop_fn omidiInStop = 0;

typedef UINT (__stdcall *midiInUnprepareHeader_fn)(HANDLE hmi, LPMIDIHDR pmh, UINT cbmh);
midiInUnprepareHeader_fn omidiInUnprepareHeader = 0;

typedef UINT (__stdcall *midiOutCacheDrumPatches_fn)(HANDLE hmo, UINT uPatch, LPWORD pwkya, UINT fuCache);
midiOutCacheDrumPatches_fn omidiOutCacheDrumPatches = 0;

typedef UINT (__stdcall *midiOutCachePatches_fn)(HANDLE hmo, UINT uBank, LPWORD pwpa, UINT fuCache);
midiOutCachePatches_fn omidiOutCachePatches = 0;

typedef UINT (__stdcall *midiOutClose_fn)(HANDLE hmo);
midiOutClose_fn omidiOutClose = 0;

typedef UINT (__stdcall *midiOutGetDevCapsA_fn)(UINT_PTR uDeviceID, LPMIDIOUTCAPSA pmoc, UINT cbmoc);
midiOutGetDevCapsA_fn omidiOutGetDevCapsA = 0;

typedef UINT (__stdcall *midiOutGetDevCapsW_fn)(UINT_PTR uDeviceID, LPMIDIOUTCAPSW pmoc, UINT cbmoc);
midiOutGetDevCapsW_fn omidiOutGetDevCapsW = 0;

typedef UINT (__stdcall *midiOutGetErrorTextA_fn)(UINT mmrError, LPSTR pszText, UINT cchText);
midiOutGetErrorTextA_fn omidiOutGetErrorTextA = 0;

typedef UINT (__stdcall *midiOutGetErrorTextW_fn)(UINT mmrError, LPWSTR pszText, UINT cchText);
midiOutGetErrorTextW_fn omidiOutGetErrorTextW = 0;

typedef UINT (__stdcall *midiOutGetID_fn)(HANDLE hmo, LPUINT puDeviceID);
midiOutGetID_fn omidiOutGetID = 0;

typedef UINT (__stdcall *midiOutGetNumDevs_fn)(void);
midiOutGetNumDevs_fn omidiOutGetNumDevs = 0;

typedef UINT (__stdcall *midiOutGetVolume_fn)(HANDLE hmo, LPDWORD pdwVolume);
midiOutGetVolume_fn omidiOutGetVolume = 0;

typedef UINT (__stdcall *midiOutLongMsg_fn)(HANDLE hmo, LPMIDIHDR pmh, UINT cbmh);
midiOutLongMsg_fn omidiOutLongMsg = 0;

typedef UINT (__stdcall *midiOutMessage_fn)(HANDLE hmo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
midiOutMessage_fn omidiOutMessage = 0;

typedef UINT (__stdcall *midiOutOpen_fn)(LPHANDLE phmo, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
midiOutOpen_fn omidiOutOpen = 0;

typedef UINT (__stdcall *midiOutPrepareHeader_fn)(HANDLE hmo, LPMIDIHDR pmh, UINT cbmh);
midiOutPrepareHeader_fn omidiOutPrepareHeader = 0;

typedef UINT (__stdcall *midiOutReset_fn)(HANDLE hmo);
midiOutReset_fn omidiOutReset = 0;

typedef UINT (__stdcall *midiOutSetVolume_fn)(HANDLE hmo, DWORD dwVolume);
midiOutSetVolume_fn omidiOutSetVolume = 0;

typedef UINT (__stdcall *midiOutShortMsg_fn)(HANDLE hmo, DWORD dwMsg);
midiOutShortMsg_fn omidiOutShortMsg = 0;

typedef UINT (__stdcall *midiOutUnprepareHeader_fn)(HANDLE hmo, LPMIDIHDR pmh, UINT cbmh);
midiOutUnprepareHeader_fn omidiOutUnprepareHeader = 0;

typedef UINT (__stdcall *midiStreamClose_fn)(HANDLE hms);
midiStreamClose_fn omidiStreamClose = 0;

typedef UINT (__stdcall *midiStreamOpen_fn)(LPHANDLE phms, LPUINT puDeviceID, DWORD cMidi, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
midiStreamOpen_fn omidiStreamOpen = 0;

typedef UINT (__stdcall *midiStreamOut_fn)(HANDLE hms, LPMIDIHDR pmh, UINT cbmh);
midiStreamOut_fn omidiStreamOut = 0;

typedef UINT (__stdcall *midiStreamPause_fn)(HANDLE hms);
midiStreamPause_fn omidiStreamPause = 0;

typedef UINT (__stdcall *midiStreamPosition_fn)(HANDLE hms, LPMMTIME lpmmt, UINT cbmmt);
midiStreamPosition_fn omidiStreamPosition = 0;

typedef UINT (__stdcall *midiStreamProperty_fn)(HANDLE hms, LPBYTE lppropdata, DWORD dwProperty);
midiStreamProperty_fn omidiStreamProperty = 0;

typedef UINT (__stdcall *midiStreamRestart_fn)(HANDLE hms);
midiStreamRestart_fn omidiStreamRestart = 0;

typedef UINT (__stdcall *midiStreamStop_fn)(HANDLE hms);
midiStreamStop_fn omidiStreamStop = 0;

typedef UINT (__stdcall *mixerClose_fn)(HANDLE hmx);
mixerClose_fn omixerClose = 0;

typedef UINT (__stdcall *mixerGetControlDetailsA_fn)(HANDLE hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fwDetails);
mixerGetControlDetailsA_fn omixerGetControlDetailsA = 0;

typedef UINT (__stdcall *mixerGetControlDetailsW_fn)(HANDLE hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fwDetails);
mixerGetControlDetailsW_fn omixerGetControlDetailsW = 0;

typedef UINT (__stdcall *mixerGetDevCapsA_fn)(UINT_PTR uMxId, LPMIXERCAPSA pmxcaps, UINT cbmxcaps);
mixerGetDevCapsA_fn omixerGetDevCapsA = 0;

typedef UINT (__stdcall *mixerGetDevCapsW_fn)(UINT_PTR uMxId, LPMIXERCAPSW pmxcaps, UINT cbmxcaps);
mixerGetDevCapsW_fn omixerGetDevCapsW = 0;

typedef UINT (__stdcall *mixerGetID_fn)(HANDLE hmxobj, LPUINT puMxId, DWORD fdwId);
mixerGetID_fn omixerGetID = 0;

typedef UINT (__stdcall *mixerGetLineControlsA_fn)(HANDLE hmxobj, LPMIXERLINECONTROLSA pmxlc, DWORD fdwControls);
mixerGetLineControlsA_fn omixerGetLineControlsA = 0;

typedef UINT (__stdcall *mixerGetLineControlsW_fn)(HANDLE hmxobj, LPMIXERLINECONTROLSW pmxlc, DWORD fdwControls);
mixerGetLineControlsW_fn omixerGetLineControlsW = 0;

typedef UINT (__stdcall *mixerGetLineInfoA_fn)(HANDLE hmxobj, LPMIXERLINEA pmxl, DWORD fdwInfo);
mixerGetLineInfoA_fn omixerGetLineInfoA = 0;

typedef UINT (__stdcall *mixerGetLineInfoW_fn)(HANDLE hmxobj, LPMIXERLINEW pmxl, DWORD fdwInfo);
mixerGetLineInfoW_fn omixerGetLineInfoW = 0;

typedef UINT (__stdcall *mixerGetNumDevs_fn)(void);
mixerGetNumDevs_fn omixerGetNumDevs = 0;

typedef DWORD (__stdcall *mixerMessage_fn)(HANDLE hmx, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
mixerMessage_fn omixerMessage = 0;

typedef UINT (__stdcall *mixerOpen_fn)(LPHANDLE phmx, UINT uMxId, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
mixerOpen_fn omixerOpen = 0;

typedef UINT (__stdcall *mixerSetControlDetails_fn)(HANDLE hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);
mixerSetControlDetails_fn omixerSetControlDetails = 0;

typedef UINT (__stdcall *mmDrvInstall_fn)(HANDLE hDriver, LPCWSTR wszDrvEntry, DRIVERMSGPROC drvMessage, UINT wFlags);
mmDrvInstall_fn ommDrvInstall = 0;

typedef DWORD (__stdcall *mmGetCurrentTask_fn)(void);
mmGetCurrentTask_fn ommGetCurrentTask = 0;

typedef void (__stdcall *mmTaskBlock_fn)(DWORD h);
mmTaskBlock_fn ommTaskBlock = 0;

typedef UINT (__stdcall *mmTaskCreate_fn)(LPTASKCALLBACK lpfn, LPHANDLE lph, DWORD_PTR dwInst);
mmTaskCreate_fn ommTaskCreate = 0;

typedef BOOL (__stdcall *mmTaskSignal_fn)(DWORD h);
mmTaskSignal_fn ommTaskSignal = 0;

typedef void (__stdcall *mmTaskYield_fn)(void);
mmTaskYield_fn ommTaskYield = 0;

typedef UINT (__stdcall *mmioAdvance_fn)(HANDLE hmmio, LPMMIOINFO pmmioinfo, UINT fuAdvance);
mmioAdvance_fn ommioAdvance = 0;

typedef UINT (__stdcall *mmioAscend_fn)(HANDLE hmmio, LPMMCKINFO pmmcki, UINT fuAscend);
mmioAscend_fn ommioAscend = 0;

typedef UINT (__stdcall *mmioClose_fn)(HANDLE hmmio, UINT fuClose);
mmioClose_fn ommioClose = 0;

typedef UINT (__stdcall *mmioCreateChunk_fn)(HANDLE hmmio, LPMMCKINFO pmmcki, UINT fuCreate);
mmioCreateChunk_fn ommioCreateChunk = 0;

typedef UINT (__stdcall *mmioDescend_fn)(HANDLE hmmio, LPMMCKINFO pmmcki, const LPMMCKINFO pmmckiParent, UINT fuDescend);
mmioDescend_fn ommioDescend = 0;

typedef UINT (__stdcall *mmioFlush_fn)(HANDLE hmmio, UINT fuFlush);
mmioFlush_fn ommioFlush = 0;

typedef UINT (__stdcall *mmioGetInfo_fn)(HANDLE hmmio, LPMMIOINFO pmmioinfo, UINT fuInfo);
mmioGetInfo_fn ommioGetInfo = 0;

typedef LPMMIOPROC (__stdcall *mmioInstallIOProcA_fn)(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
mmioInstallIOProcA_fn ommioInstallIOProcA = 0;

typedef LPMMIOPROC (__stdcall *mmioInstallIOProcW_fn)(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
mmioInstallIOProcW_fn ommioInstallIOProcW = 0;

typedef HANDLE (__stdcall *mmioOpenA_fn)(LPSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
mmioOpenA_fn ommioOpenA = 0;

typedef HANDLE (__stdcall *mmioOpenW_fn)(LPWSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
mmioOpenW_fn ommioOpenW = 0;

typedef LONG (__stdcall *mmioRead_fn)(HANDLE hmmio, LPSTR pch, LONG cch);
mmioRead_fn ommioRead = 0;

typedef UINT (__stdcall *mmioRenameA_fn)(LPCSTR pszFileName, LPCSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);
mmioRenameA_fn ommioRenameA = 0;

typedef UINT (__stdcall *mmioRenameW_fn)(LPCWSTR pszFileName, LPCWSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);
mmioRenameW_fn ommioRenameW = 0;

typedef LONG (__stdcall *mmioSeek_fn)(HANDLE hmmio, LONG lOffset, int iOrigin);
mmioSeek_fn ommioSeek = 0;

typedef LONG_PTR (__stdcall *mmioSendMessage_fn)(HANDLE hmmio, UINT uMsg, LONG_PTR lParam1, LONG_PTR lParam2);
mmioSendMessage_fn ommioSendMessage = 0;

typedef UINT (__stdcall *mmioSetBuffer_fn)(HANDLE hmmio, LPSTR pchBuffer, LONG cchBuffer, UINT fuBuffer);
mmioSetBuffer_fn ommioSetBuffer = 0;

typedef UINT (__stdcall *mmioSetInfo_fn)(HANDLE hmmio, LPCMMIOINFO pmmioinfo, UINT fuInfo);
mmioSetInfo_fn ommioSetInfo = 0;

typedef FOURCC (__stdcall *mmioStringToFOURCCA_fn)(LPCSTR sz, UINT uFlags);
mmioStringToFOURCCA_fn ommioStringToFOURCCA = 0;

typedef FOURCC (__stdcall *mmioStringToFOURCCW_fn)(LPCWSTR sz, UINT uFlags);
mmioStringToFOURCCW_fn ommioStringToFOURCCW = 0;

typedef LONG (__stdcall *mmioWrite_fn)(HANDLE hmmio, LPCSTR pch, LONG cch);
mmioWrite_fn ommioWrite = 0;

typedef UINT (__stdcall *mmsystemGetVersion_fn)(void);
mmsystemGetVersion_fn ommsystemGetVersion = 0;

#ifndef _WIN64
typedef UINT (__stdcall *mod32Message_fn)(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3);
mod32Message_fn omod32Message = 0;

typedef UINT (__stdcall *mxd32Message_fn)(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3);
mxd32Message_fn omxd32Message = 0;
#endif // !_WIN64

typedef BOOL (__stdcall *sndPlaySoundA_fn)(LPCSTR lpszSound, UINT fuSound);
sndPlaySoundA_fn osndPlaySoundA = 0;

typedef BOOL (__stdcall *sndPlaySoundW_fn)(LPCWSTR lpszSound, UINT fuSound);
sndPlaySoundW_fn osndPlaySoundW = 0;

#ifndef _WIN64
typedef UINT (__stdcall *tid32Message_fn)(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3);
tid32Message_fn otid32Message = 0;
#endif // !_WIN64

typedef UINT (__stdcall *timeBeginPeriod_fn)(UINT uPeriod);
timeBeginPeriod_fn otimeBeginPeriod = 0;

typedef UINT (__stdcall *timeEndPeriod_fn)(UINT uPeriod);
timeEndPeriod_fn otimeEndPeriod = 0;

typedef UINT (__stdcall *timeGetDevCaps_fn)(LPTIMECAPS ptc, UINT cbtc);
timeGetDevCaps_fn otimeGetDevCaps = 0;

typedef UINT (__stdcall *timeGetSystemTime_fn)(LPMMTIME pmmt, UINT cbmmt);
timeGetSystemTime_fn otimeGetSystemTime = 0;

typedef DWORD (__stdcall *timeGetTime_fn)(void);
timeGetTime_fn otimeGetTime = 0;

typedef UINT (__stdcall *timeKillEvent_fn)(UINT uTimerID);
timeKillEvent_fn otimeKillEvent = 0;

typedef UINT (__stdcall *timeSetEvent_fn)(UINT uDelay, UINT uResolution, LPTIMECALLBACK lpTimeProc, DWORD_PTR dwUser, UINT fuEvent);
timeSetEvent_fn otimeSetEvent = 0;

typedef UINT (__stdcall *waveInAddBuffer_fn)(HANDLE hwi, LPWAVEHDR pwh, UINT cbwh);
waveInAddBuffer_fn owaveInAddBuffer = 0;

typedef UINT (__stdcall *waveInClose_fn)(HANDLE hwi);
waveInClose_fn owaveInClose = 0;

typedef UINT (__stdcall *waveInGetDevCapsA_fn)(UINT uDeviceID, LPWAVEINCAPSA pwic, UINT cbwic);
waveInGetDevCapsA_fn owaveInGetDevCapsA = 0;

typedef UINT (__stdcall *waveInGetDevCapsW_fn)(UINT uDeviceID, LPWAVEINCAPSW pwic, UINT cbwic);
waveInGetDevCapsW_fn owaveInGetDevCapsW = 0;

typedef UINT (__stdcall *waveInGetErrorTextA_fn)(UINT mmrError, LPSTR pszText, UINT cchText);
waveInGetErrorTextA_fn owaveInGetErrorTextA = 0;

typedef UINT (__stdcall *waveInGetErrorTextW_fn)(UINT mmrError, LPWSTR pszText, UINT cchText);
waveInGetErrorTextW_fn owaveInGetErrorTextW = 0;

typedef UINT (__stdcall *waveInGetID_fn)(HANDLE hwi, LPUINT puDeviceID);
waveInGetID_fn owaveInGetID = 0;

typedef UINT (__stdcall *waveInGetNumDevs_fn)(void);
waveInGetNumDevs_fn owaveInGetNumDevs = 0;

typedef UINT (__stdcall *waveInGetPosition_fn)(HANDLE hwi, LPMMTIME pmmt, UINT cbmmt);
waveInGetPosition_fn owaveInGetPosition = 0;

typedef UINT (__stdcall *waveInMessage_fn)(HANDLE hwi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
waveInMessage_fn owaveInMessage = 0;

typedef UINT (__stdcall *waveInOpen_fn)(LPHANDLE phwi, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
waveInOpen_fn owaveInOpen = 0;

typedef UINT (__stdcall *waveInPrepareHeader_fn)(HANDLE hwi, LPWAVEHDR pwh, UINT cbwh);
waveInPrepareHeader_fn owaveInPrepareHeader = 0;

typedef UINT (__stdcall *waveInReset_fn)(HANDLE hwi);
waveInReset_fn owaveInReset = 0;

typedef UINT (__stdcall *waveInStart_fn)(HANDLE hwi);
waveInStart_fn owaveInStart = 0;

typedef UINT (__stdcall *waveInStop_fn)(HANDLE hwi);
waveInStop_fn owaveInStop = 0;

typedef UINT (__stdcall *waveInUnprepareHeader_fn)(HANDLE hwi, LPWAVEHDR pwh, UINT cbwh);
waveInUnprepareHeader_fn owaveInUnprepareHeader = 0;

typedef UINT (__stdcall *waveOutBreakLoop_fn)(HANDLE hwo);
waveOutBreakLoop_fn owaveOutBreakLoop = 0;

typedef UINT (__stdcall *waveOutClose_fn)(HANDLE hwo);
waveOutClose_fn owaveOutClose = 0;

typedef UINT (__stdcall *waveOutGetDevCapsA_fn)(UINT uDeviceID, LPWAVEOUTCAPSA pwoc, UINT cbwoc);
waveOutGetDevCapsA_fn owaveOutGetDevCapsA = 0;

typedef UINT (__stdcall *waveOutGetDevCapsW_fn)(UINT uDeviceID, LPWAVEOUTCAPSW pwoc, UINT cbwoc);
waveOutGetDevCapsW_fn owaveOutGetDevCapsW = 0;

typedef UINT (__stdcall *waveOutGetErrorTextA_fn)(UINT mmrError, LPSTR pszText, UINT cchText);
waveOutGetErrorTextA_fn owaveOutGetErrorTextA = 0;

typedef UINT (__stdcall *waveOutGetErrorTextW_fn)(UINT mmrError, LPWSTR pszText, UINT cchText);
waveOutGetErrorTextW_fn owaveOutGetErrorTextW = 0;

typedef UINT (__stdcall *waveOutGetID_fn)(HANDLE hwo, LPUINT puDeviceID);
waveOutGetID_fn owaveOutGetID = 0;

typedef UINT (__stdcall *waveOutGetNumDevs_fn)(void);
waveOutGetNumDevs_fn owaveOutGetNumDevs = 0;

typedef UINT (__stdcall *waveOutGetPitch_fn)(HANDLE hwo, LPDWORD pdwPitch);
waveOutGetPitch_fn owaveOutGetPitch = 0;

typedef UINT (__stdcall *waveOutGetPlaybackRate_fn)(HANDLE hwo, LPDWORD pdwRate);
waveOutGetPlaybackRate_fn owaveOutGetPlaybackRate = 0;

typedef UINT (__stdcall *waveOutGetPosition_fn)(HANDLE hwo, LPMMTIME pmmt, UINT cbmmt);
waveOutGetPosition_fn owaveOutGetPosition = 0;

typedef UINT (__stdcall *waveOutGetVolume_fn)(HANDLE hwo, LPDWORD pdwVolume);
waveOutGetVolume_fn owaveOutGetVolume = 0;

typedef UINT (__stdcall *waveOutMessage_fn)(HANDLE hwo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
waveOutMessage_fn owaveOutMessage = 0;

typedef UINT (__stdcall *waveOutOpen_fn)(LPHANDLE phwo, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
waveOutOpen_fn owaveOutOpen = 0;

typedef UINT (__stdcall *waveOutPause_fn)(HANDLE hwo);
waveOutPause_fn owaveOutPause = 0;

typedef UINT (__stdcall *waveOutPrepareHeader_fn)(HANDLE hwo, LPWAVEHDR pwh, UINT cbwh);
waveOutPrepareHeader_fn owaveOutPrepareHeader = 0;

typedef UINT (__stdcall *waveOutReset_fn)(HANDLE hwo);
waveOutReset_fn owaveOutReset = 0;

typedef UINT (__stdcall *waveOutRestart_fn)(HANDLE hwo);
waveOutRestart_fn owaveOutRestart = 0;

typedef UINT (__stdcall *waveOutSetPitch_fn)(HANDLE hwo, DWORD dwPitch);
waveOutSetPitch_fn owaveOutSetPitch = 0;

typedef UINT (__stdcall *waveOutSetPlaybackRate_fn)(HANDLE hwo, DWORD dwRate);
waveOutSetPlaybackRate_fn owaveOutSetPlaybackRate = 0;

typedef UINT (__stdcall *waveOutSetVolume_fn)(HANDLE hwo, DWORD dwVolume);
waveOutSetVolume_fn owaveOutSetVolume = 0;

typedef UINT (__stdcall *waveOutUnprepareHeader_fn)(HANDLE hwo, LPWAVEHDR pwh, UINT cbwh);
waveOutUnprepareHeader_fn owaveOutUnprepareHeader = 0;

typedef UINT (__stdcall *waveOutWrite_fn)(HANDLE hwo, LPWAVEHDR pwh, UINT cbwh);
waveOutWrite_fn owaveOutWrite = 0;

#ifndef _WIN64
typedef UINT (__stdcall *wid32Message_fn)(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3);
wid32Message_fn owid32Message = 0;

typedef UINT (__stdcall *wod32Message_fn)(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3);
wod32Message_fn owod32Message = 0;
#endif // !_WIN64

////

#if 0
PlaySoundA_fn oNONAMEPlaySoundA = 0;
BOOL __stdcall p_NONAMEPlaySoundA(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:p_NONAMEPlaySoundA,@2,NONAME")
#else
  #pragma comment(linker, "/EXPORT:_p_NONAMEPlaySoundA@12,@2,NONAME")
#endif

  if (!oNONAMEPlaySoundA) {
    oNONAMEPlaySoundA = GetSysProc(sWinmm, MAKEINTRESOURCE(2));
    if (oNONAMEPlaySoundA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oNONAMEPlaySoundA, &hm);
    } else {
      oNONAMEPlaySoundA = (void*)-1;
    }
  }
  if (oNONAMEPlaySoundA != (void*)-1)
    return oNONAMEPlaySoundA(pszSound, hmod, fdwSound);

  return FALSE;
}
#endif

LONG_PTR __stdcall p_CloseDriver(HANDLE hDriver, LONG_PTR lParam1, LONG_PTR lParam2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:CloseDriver=p_CloseDriver")
#else
  #pragma comment(linker, "/EXPORT:CloseDriver=_p_CloseDriver@12")
#endif

  if (!oCloseDriver) {
    oCloseDriver = GetSysProc(sWinmm, "CloseDriver");
    if (oCloseDriver) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oCloseDriver, &hm);
    } else {
      oCloseDriver = (void*)-1;
    }
  }
  if (oCloseDriver != (void*)-1)
    return oCloseDriver(hDriver, lParam1, lParam2);

  return 0;
}

LONG_PTR __stdcall p_DefDriverProc(DWORD_PTR dwDriverIdentifier, HANDLE hDriver, UINT uMsg, LONG_PTR lParam1, LONG_PTR lParam2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DefDriverProc=p_DefDriverProc")
#else
  #pragma comment(linker, "/EXPORT:DefDriverProc=_p_DefDriverProc@20")
#endif

  if (!oDefDriverProc) {
    oDefDriverProc = GetSysProc(sWinmm, "DefDriverProc");
    if (oDefDriverProc) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oDefDriverProc, &hm);
    } else {
      oDefDriverProc = (void*)-1;
    }
  }
  if (oDefDriverProc != (void*)-1)
    return oDefDriverProc(dwDriverIdentifier, hDriver, uMsg, lParam1, lParam2);

  return 0;
}

BOOL __stdcall p_DriverCallback(DWORD_PTR dwCallback, DWORD dwFlags, HANDLE hDevice, DWORD dwMsg, DWORD_PTR dwUser, DWORD_PTR dwParam1, DWORD_PTR dwParam2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DriverCallback=p_DriverCallback")
#else
  #pragma comment(linker, "/EXPORT:DriverCallback=_p_DriverCallback@28")
#endif

  if (!oDriverCallback) {
    oDriverCallback = GetSysProc(sWinmm, "DriverCallback");
    if (oDriverCallback) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oDriverCallback, &hm);
    } else {
      oDriverCallback = (void*)-1;
    }
  }
  if (oDriverCallback != (void*)-1)
    return oDriverCallback(dwCallback, dwFlags, hDevice, dwMsg, dwUser, dwParam1, dwParam2);

  return FALSE;
}

HMODULE __stdcall p_DrvGetModuleHandle(HANDLE hDriver)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:DrvGetModuleHandle=p_DrvGetModuleHandle")
#else
  #pragma comment(linker, "/EXPORT:DrvGetModuleHandle=_p_DrvGetModuleHandle@4")
#endif

  if (!oDrvGetModuleHandle) {
    oDrvGetModuleHandle = GetSysProc(sWinmm, "DrvGetModuleHandle");
    if (oDrvGetModuleHandle) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oDrvGetModuleHandle, &hm);
    } else {
      oDrvGetModuleHandle = (void*)-1;
    }
  }
  if (oDrvGetModuleHandle != (void*)-1)
    return oDrvGetModuleHandle(hDriver);

  return NULL;
}

HMODULE __stdcall p_GetDriverModuleHandle(HANDLE hDriver)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:GetDriverModuleHandle=p_GetDriverModuleHandle")
#else
  #pragma comment(linker, "/EXPORT:GetDriverModuleHandle=_p_GetDriverModuleHandle@4")
#endif

  if (!oGetDriverModuleHandle) {
    oGetDriverModuleHandle = GetSysProc(sWinmm, "GetDriverModuleHandle");
    if (oGetDriverModuleHandle) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oGetDriverModuleHandle, &hm);
    } else {
      oGetDriverModuleHandle = (void*)-1;
    }
  }
  if (oGetDriverModuleHandle != (void*)-1)
    return oGetDriverModuleHandle(hDriver);

  return NULL;
}

#ifndef _WIN64
DWORD __stdcall p_NotifyCallbackData(DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3, DWORD_PTR dw4, DWORD_PTR dw5)
{
  #pragma comment(linker, "/EXPORT:NotifyCallbackData=_p_NotifyCallbackData@20")

  if (!oNotifyCallbackData) {
    oNotifyCallbackData = GetSysProc(sWinmm, "NotifyCallbackData");
    if (oNotifyCallbackData) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oNotifyCallbackData, &hm);
    } else {
      oNotifyCallbackData = (void*)-1;
    }
  }
  if (oNotifyCallbackData != (void*)-1)
    return oNotifyCallbackData(dw1, dw2, dw3, dw4, dw5);

  return 0;
}
#endif // !_WIN64

HANDLE __stdcall p_OpenDriver(LPCWSTR lpDriverName, LPCWSTR lpSectionName, LONG_PTR lParam)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:OpenDriver=p_OpenDriver")
#else
  #pragma comment(linker, "/EXPORT:OpenDriver=_p_OpenDriver@12")
#endif

  if (!oOpenDriver) {
    oOpenDriver = GetSysProc(sWinmm, "OpenDriver");
    if (oOpenDriver) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oOpenDriver, &hm);
    } else {
      oOpenDriver = (void*)-1;
    }
  }
  if (oOpenDriver != (void*)-1)
    return oOpenDriver(lpDriverName, lpSectionName, lParam);

  return 0;
}

BOOL __stdcall p_PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:PlaySound=p_PlaySound")
#else
  #pragma comment(linker, "/EXPORT:PlaySound=_p_PlaySound@12")
#endif

  if (!oPlaySound) {
    oPlaySound = GetSysProc(sWinmm, "PlaySound");
    if (oPlaySound) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oPlaySound, &hm);
    } else {
      oPlaySound = (void*)-1;
    }
  }
  if (oPlaySound != (void*)-1)
    return oPlaySound(pszSound, hmod, fdwSound);

  return FALSE;
}

BOOL __stdcall p_PlaySoundA(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:PlaySoundA=p_PlaySoundA")
#else
  #pragma comment(linker, "/EXPORT:PlaySoundA=_p_PlaySoundA@12")
#endif

  if (!oPlaySoundA) {
    oPlaySoundA = GetSysProc(sWinmm, "PlaySoundA");
    if (oPlaySoundA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oPlaySoundA, &hm);
    } else {
      oPlaySoundA = (void*)-1;
    }
  }
  if (oPlaySoundA != (void*)-1)
    return oPlaySoundA(pszSound, hmod, fdwSound);

  return FALSE;
}

BOOL __stdcall p_PlaySoundW(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:PlaySoundW=p_PlaySoundW")
#else
  #pragma comment(linker, "/EXPORT:PlaySoundW=_p_PlaySoundW@12")
#endif

  if (!oPlaySoundW) {
    oPlaySoundW = GetSysProc(sWinmm, "PlaySoundW");
    if (oPlaySoundW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oPlaySoundW, &hm);
    } else {
      oPlaySoundW = (void*)-1;
    }
  }
  if (oPlaySoundW != (void*)-1)
    return oPlaySoundW(pszSound, hmod, fdwSound);

  return FALSE;
}


LONG_PTR __stdcall p_SendDriverMessage(HANDLE hDriver, UINT message, LONG_PTR lParam1, LONG_PTR lParam2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:SendDriverMessage=p_SendDriverMessage")
#else
  #pragma comment(linker, "/EXPORT:SendDriverMessage=_p_SendDriverMessage@16")
#endif

  if (!oSendDriverMessage) {
    oSendDriverMessage = GetSysProc(sWinmm, "SendDriverMessage");
    if (oSendDriverMessage) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oSendDriverMessage, &hm);
    } else {
      oSendDriverMessage = (void*)-1;
    }
  }
  if (oSendDriverMessage != (void*)-1)
    return oSendDriverMessage(hDriver, message, lParam1, lParam2);

  return 0;
}

#ifndef _WIN64
DWORD __stdcall p_WOW32DriverCallback(DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3, DWORD_PTR dw4, DWORD_PTR dw5, DWORD_PTR dw6, DWORD_PTR dw7)
{
  #pragma comment(linker, "/EXPORT:WOW32DriverCallback=_p_WOW32DriverCallback@28")

  if (!oWOW32DriverCallback) {
    oWOW32DriverCallback = GetSysProc(sWinmm, "WOW32DriverCallback");
    if (oWOW32DriverCallback) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oWOW32DriverCallback, &hm);
    } else {
      oWOW32DriverCallback = (void*)-1;
    }
  }
  if (oWOW32DriverCallback != (void*)-1)
    return oWOW32DriverCallback(dw1, dw2, dw3, dw4, dw5, dw6, dw7);

  return 0;
}

DWORD __stdcall p_WOW32ResolveMultiMediaHandle(DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3, DWORD_PTR dw4, DWORD_PTR dw5, DWORD_PTR dw6)
{
  #pragma comment(linker, "/EXPORT:WOW32ResolveMultiMediaHandle=_p_WOW32ResolveMultiMediaHandle@24")

  if (!oWOW32ResolveMultiMediaHandle) {
    oWOW32ResolveMultiMediaHandle = GetSysProc(sWinmm, "WOW32ResolveMultiMediaHandle");
    if (oWOW32ResolveMultiMediaHandle) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oWOW32ResolveMultiMediaHandle, &hm);
    } else {
      oWOW32ResolveMultiMediaHandle = (void*)-1;
    }
  }
  if (oWOW32ResolveMultiMediaHandle != (void*)-1)
    return oWOW32ResolveMultiMediaHandle(dw1, dw2, dw3, dw4, dw5, dw6);

  return 0;
}
#endif // !_WIN64

void __stdcall p_WOWAppExit(LPVOID pUnk)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:WOWAppExit=p_WOWAppExit")
#else
  #pragma comment(linker, "/EXPORT:WOWAppExit=_p_WOWAppExit@4")
#endif

  if (!oWOWAppExit) {
    oWOWAppExit = GetSysProc(sWinmm, "WOWAppExit");
    if (oWOWAppExit) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oWOWAppExit, &hm);
    } else {
      oWOWAppExit = (void*)-1;
    }
  }
  if (oWOWAppExit != (void*)-1)
    oWOWAppExit(pUnk);
}

#ifndef _WIN64
UINT __stdcall p_aux32Message(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3)
{
  #pragma comment(linker, "/EXPORT:aux32Message=_p_aux32Message@20")

  if (!oaux32Message) {
    oaux32Message = GetSysProc(sWinmm, "aux32Message");
    if (oaux32Message) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oaux32Message, &hm);
    } else {
      oaux32Message = (void*)-1;
    }
  }
  if (oaux32Message != (void*)-1)
    return oaux32Message(uDeviceID, uMsg, dw1, dw2, dw3);

  return 10; // MMSYSERR_NOTSUPPORTED
}
#endif // !_WIN64

UINT __stdcall p_auxGetDevCapsA(UINT_PTR uDeviceID, LPAUXCAPSA pac, UINT cbac)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:auxGetDevCapsA=p_auxGetDevCapsA")
#else
  #pragma comment(linker, "/EXPORT:auxGetDevCapsA=_p_auxGetDevCapsA@12")
#endif

  if (!oauxGetDevCapsA) {
    oauxGetDevCapsA = GetSysProc(sWinmm, "auxGetDevCapsA");
    if (oauxGetDevCapsA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oauxGetDevCapsA, &hm);
    } else {
      oauxGetDevCapsA = (void*)-1;
    }
  }
  if (oauxGetDevCapsA != (void*)-1)
    return oauxGetDevCapsA(uDeviceID, pac, cbac);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_auxGetDevCapsW(UINT_PTR uDeviceID, LPAUXCAPSW pac, UINT cbac)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:auxGetDevCapsW=p_auxGetDevCapsW")
#else
  #pragma comment(linker, "/EXPORT:auxGetDevCapsW=_p_auxGetDevCapsW@12")
#endif

  if (!oauxGetDevCapsW) {
    oauxGetDevCapsW = GetSysProc(sWinmm, "auxGetDevCapsW");
    if (oauxGetDevCapsW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oauxGetDevCapsW, &hm);
    } else {
      oauxGetDevCapsW = (void*)-1;
    }
  }
  if (oauxGetDevCapsW != (void*)-1)
    return oauxGetDevCapsW(uDeviceID, pac, cbac);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_auxGetNumDevs(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:auxGetNumDevs=p_auxGetNumDevs")
#else
  #pragma comment(linker, "/EXPORT:auxGetNumDevs=_p_auxGetNumDevs@0")
#endif

  if (!oauxGetNumDevs) {
    oauxGetNumDevs = GetSysProc(sWinmm, "auxGetNumDevs");
    if (oauxGetNumDevs) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oauxGetNumDevs, &hm);
    } else {
      oauxGetNumDevs = (void*)-1;
    }
  }
  if (oauxGetNumDevs != (void*)-1)
    return oauxGetNumDevs();

  return 0;
}

UINT __stdcall p_auxGetVolume(UINT uDeviceID, LPDWORD pdwVolume)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:auxGetVolume=p_auxGetVolume")
#else
  #pragma comment(linker, "/EXPORT:auxGetVolume=_p_auxGetVolume@8")
#endif

  if (!oauxGetVolume) {
    oauxGetVolume = GetSysProc(sWinmm, "auxGetVolume");
    if (oauxGetVolume) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oauxGetVolume, &hm);
    } else {
      oauxGetVolume = (void*)-1;
    }
  }
  if (oauxGetVolume != (void*)-1)
    return oauxGetVolume(uDeviceID, pdwVolume);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_auxOutMessage(UINT uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:auxOutMessage=p_auxOutMessage")
#else
  #pragma comment(linker, "/EXPORT:auxOutMessage=_p_auxOutMessage@16")
#endif

  if (!oauxOutMessage) {
    oauxOutMessage = GetSysProc(sWinmm, "auxOutMessage");
    if (oauxOutMessage) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oauxOutMessage, &hm);
    } else {
      oauxOutMessage = (void*)-1;
    }
  }
  if (oauxOutMessage != (void*)-1)
    return oauxOutMessage(uDeviceID, uMsg, dw1, dw2);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_auxSetVolume(UINT uDeviceID, DWORD dwVolume)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:auxSetVolume=p_auxSetVolume")
#else
  #pragma comment(linker, "/EXPORT:auxSetVolume=_p_auxSetVolume@8")
#endif

  if (!oauxSetVolume) {
    oauxSetVolume = GetSysProc(sWinmm, "auxSetVolume");
    if (oauxSetVolume) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oauxSetVolume, &hm);
    } else {
      oauxSetVolume = (void*)-1;
    }
  }
  if (oauxSetVolume != (void*)-1)
    return oauxSetVolume(uDeviceID, dwVolume);

  return 10; // MMSYSERR_NOTSUPPORTED
}

#ifndef _WIN64
UINT __stdcall p_joy32Message(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3)
{
  #pragma comment(linker, "/EXPORT:joy32Message=_p_joy32Message@20")

  if (!ojoy32Message) {
    ojoy32Message = GetSysProc(sWinmm, "joy32Message");
    if (ojoy32Message) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoy32Message, &hm);
    } else {
      ojoy32Message = (void*)-1;
    }
  }
  if (ojoy32Message != (void*)-1)
    return ojoy32Message(uDeviceID, uMsg, dw1, dw2, dw3);

  return 10; // MMSYSERR_NOTSUPPORTED
}
#endif // !_WIN64

UINT __stdcall p_joyConfigChanged(DWORD dwFlags)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joyConfigChanged=p_joyConfigChanged")
#else
  #pragma comment(linker, "/EXPORT:joyConfigChanged=_p_joyConfigChanged@4")
#endif

  if (!ojoyConfigChanged) {
    ojoyConfigChanged = GetSysProc(sWinmm, "joyConfigChanged");
    if (ojoyConfigChanged) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoyConfigChanged, &hm);
    } else {
      ojoyConfigChanged = (void*)-1;
    }
  }
  if (ojoyConfigChanged != (void*)-1)
    return ojoyConfigChanged(dwFlags);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_joyGetDevCapsA(UINT_PTR uJoyID, LPJOYCAPSA pjc, UINT cbjc)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joyGetDevCapsA=p_joyGetDevCapsA")
#else
  #pragma comment(linker, "/EXPORT:joyGetDevCapsA=_p_joyGetDevCapsA@12")
#endif

  if (!ojoyGetDevCapsA) {
    ojoyGetDevCapsA = GetSysProc(sWinmm, "joyGetDevCapsA");
    if (ojoyGetDevCapsA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoyGetDevCapsA, &hm);
    } else {
      ojoyGetDevCapsA = (void*)-1;
    }
  }
  if (ojoyGetDevCapsA != (void*)-1)
    return ojoyGetDevCapsA(uJoyID, pjc, cbjc);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_joyGetDevCapsW(UINT_PTR uJoyID, LPJOYCAPSW pjc, UINT cbjc)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joyGetDevCapsW=p_joyGetDevCapsW")
#else
  #pragma comment(linker, "/EXPORT:joyGetDevCapsW=_p_joyGetDevCapsW@12")
#endif

  if (!ojoyGetDevCapsW) {
    ojoyGetDevCapsW = GetSysProc(sWinmm, "joyGetDevCapsW");
    if (ojoyGetDevCapsW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoyGetDevCapsW, &hm);
    } else {
      ojoyGetDevCapsW = (void*)-1;
    }
  }
  if (ojoyGetDevCapsW != (void*)-1)
    return ojoyGetDevCapsW(uJoyID, pjc, cbjc);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_joyGetNumDevs(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joyGetNumDevs=p_joyGetNumDevs")
#else
  #pragma comment(linker, "/EXPORT:joyGetNumDevs=_p_joyGetNumDevs@0")
#endif

  if (!ojoyGetNumDevs) {
    ojoyGetNumDevs = GetSysProc(sWinmm, "joyGetNumDevs");
    if (ojoyGetNumDevs) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoyGetNumDevs, &hm);
    } else {
      ojoyGetNumDevs = (void*)-1;
    }
  }
  if (ojoyGetNumDevs != (void*)-1)
    return ojoyGetNumDevs();

  return 0;
}

UINT __stdcall p_joyGetPos(UINT uJoyID, LPJOYINFO pji)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joyGetPos=p_joyGetPos")
#else
  #pragma comment(linker, "/EXPORT:joyGetPos=_p_joyGetPos@8")
#endif

  if (!ojoyGetPos) {
    ojoyGetPos = GetSysProc(sWinmm, "joyGetPos");
    if (ojoyGetPos) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoyGetPos, &hm);
    } else {
      ojoyGetPos = (void*)-1;
    }
  }
  if (ojoyGetPos != (void*)-1)
    return ojoyGetPos(uJoyID, pji);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_joyGetPosEx(UINT uJoyID, LPJOYINFOEX pji)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joyGetPosEx=p_joyGetPosEx")
#else
  #pragma comment(linker, "/EXPORT:joyGetPosEx=_p_joyGetPosEx@8")
#endif

  if (!ojoyGetPosEx) {
    ojoyGetPosEx = GetSysProc(sWinmm, "joyGetPosEx");
    if (ojoyGetPosEx) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoyGetPosEx, &hm);
    } else {
      ojoyGetPosEx = (void*)-1;
    }
  }
  if (ojoyGetPosEx != (void*)-1)
    return ojoyGetPosEx(uJoyID, pji);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_joyGetThreshold(UINT uJoyID, LPUINT puThreshold)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joyGetThreshold=p_joyGetThreshold")
#else
  #pragma comment(linker, "/EXPORT:joyGetThreshold=_p_joyGetThreshold@8")
#endif

  if (!ojoyGetThreshold) {
    ojoyGetThreshold = GetSysProc(sWinmm, "joyGetThreshold");
    if (ojoyGetThreshold) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoyGetThreshold, &hm);
    } else {
      ojoyGetThreshold = (void*)-1;
    }
  }
  if (ojoyGetThreshold != (void*)-1)
    return ojoyGetThreshold(uJoyID, puThreshold);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_joyReleaseCapture(UINT uJoyID)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joyReleaseCapture=p_joyReleaseCapture")
#else
  #pragma comment(linker, "/EXPORT:joyReleaseCapture=_p_joyReleaseCapture@4")
#endif

  if (!ojoyReleaseCapture) {
    ojoyReleaseCapture = GetSysProc(sWinmm, "joyReleaseCapture");
    if (ojoyReleaseCapture) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoyReleaseCapture, &hm);
    } else {
      ojoyReleaseCapture = (void*)-1;
    }
  }
  if (ojoyReleaseCapture != (void*)-1)
    return ojoyReleaseCapture(uJoyID);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_joySetCapture(HWND hwnd, UINT uJoyID, UINT uPeriod, BOOL fChanged)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joySetCapture=p_joySetCapture")
#else
  #pragma comment(linker, "/EXPORT:joySetCapture=_p_joySetCapture@16")
#endif

  if (!ojoySetCapture) {
    ojoySetCapture = GetSysProc(sWinmm, "joySetCapture");
    if (ojoySetCapture) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoySetCapture, &hm);
    } else {
      ojoySetCapture = (void*)-1;
    }
  }
  if (ojoySetCapture != (void*)-1)
    return ojoySetCapture(hwnd, uJoyID, uPeriod, fChanged);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_joySetThreshold(UINT uJoyID, UINT uThreshold)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:joySetThreshold=p_joySetThreshold")
#else
  #pragma comment(linker, "/EXPORT:joySetThreshold=_p_joySetThreshold@8")
#endif

  if (!ojoySetThreshold) {
    ojoySetThreshold = GetSysProc(sWinmm, "joySetThreshold");
    if (ojoySetThreshold) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ojoySetThreshold, &hm);
    } else {
      ojoySetThreshold = (void*)-1;
    }
  }
  if (ojoySetThreshold != (void*)-1)
    return ojoySetThreshold(uJoyID, uThreshold);

  return 10; // MMSYSERR_NOTSUPPORTED
}

#ifndef _WIN64
UINT __stdcall p_mci32Message(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3)
{
  #pragma comment(linker, "/EXPORT:mci32Message=_p_mci32Message@20")

  if (!omci32Message) {
    omci32Message = GetSysProc(sWinmm, "mci32Message");
    if (omci32Message) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omci32Message, &hm);
    } else {
      omci32Message = (void*)-1;
    }
  }
  if (omci32Message != (void*)-1)
    return omci32Message(uDeviceID, uMsg, dw1, dw2, dw3);

  return 10; // MMSYSERR_NOTSUPPORTED
}
#endif // !_WIN64


BOOL __stdcall p_mciDriverNotify(HWND hWndCallBack, UINT uDevID, UINT uStatus)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciDriverNotify=p_mciDriverNotify")
#else
  #pragma comment(linker, "/EXPORT:mciDriverNotify=_p_mciDriverNotify@12")
#endif

  if (!omciDriverNotify) {
    omciDriverNotify = GetSysProc(sWinmm, "mciDriverNotify");
    if (omciDriverNotify) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciDriverNotify, &hm);
    } else {
      omciDriverNotify = (void*)-1;
    }
  }
  if (omciDriverNotify != (void*)-1)
    return omciDriverNotify(hWndCallBack, uDevID, uStatus);

  return FALSE;
}

UINT __stdcall p_mciDriverYield(UINT uDeviceID)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciDriverYield=p_mciDriverYield")
#else
  #pragma comment(linker, "/EXPORT:mciDriverYield=_p_mciDriverYield@4")
#endif

  if (!omciDriverYield) {
    omciDriverYield = GetSysProc(sWinmm, "mciDriverYield");
    if (omciDriverYield) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciDriverYield, &hm);
    } else {
      omciDriverYield = (void*)-1;
    }
  }
  if (omciDriverYield != (void*)-1)
    return omciDriverYield(uDeviceID);

  return 0;
}

BOOL __stdcall p_mciExecute(LPCSTR pszCommand)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciExecute=p_mciExecute")
#else
  #pragma comment(linker, "/EXPORT:mciExecute=_p_mciExecute@4")
#endif

  if (!omciExecute) {
    omciExecute = GetSysProc(sWinmm, "mciExecute");
    if (omciExecute) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciExecute, &hm);
    } else {
      omciExecute = (void*)-1;
    }
  }
  if (omciExecute != (void*)-1)
    return omciExecute(pszCommand);

  return FALSE;
}

BOOL __stdcall p_mciFreeCommandResource(UINT uTable)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciFreeCommandResource=p_mciFreeCommandResource")
#else
  #pragma comment(linker, "/EXPORT:mciFreeCommandResource=_p_mciFreeCommandResource@4")
#endif

  if (!omciFreeCommandResource) {
    omciFreeCommandResource = GetSysProc(sWinmm, "mciFreeCommandResource");
    if (omciFreeCommandResource) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciFreeCommandResource, &hm);
    } else {
      omciFreeCommandResource = (void*)-1;
    }
  }
  if (omciFreeCommandResource != (void*)-1)
    return omciFreeCommandResource(uTable);

  return FALSE;
}

HANDLE __stdcall p_mciGetCreatorTask(UINT IDDevice)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciGetCreatorTask=p_mciGetCreatorTask")
#else
  #pragma comment(linker, "/EXPORT:mciGetCreatorTask=_p_mciGetCreatorTask@4")
#endif

  if (!omciGetCreatorTask) {
    omciGetCreatorTask = GetSysProc(sWinmm, "mciGetCreatorTask");
    if (omciGetCreatorTask) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciGetCreatorTask, &hm);
    } else {
      omciGetCreatorTask = (void*)-1;
    }
  }
  if (omciGetCreatorTask != (void*)-1)
    return omciGetCreatorTask(IDDevice);

  return NULL;
}

UINT __stdcall p_mciGetDeviceIDA(LPCSTR lpstrName)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciGetDeviceIDA=p_mciGetDeviceIDA")
#else
  #pragma comment(linker, "/EXPORT:mciGetDeviceIDA=_p_mciGetDeviceIDA@4")
#endif

  if (!omciGetDeviceIDA) {
    omciGetDeviceIDA = GetSysProc(sWinmm, "mciGetDeviceIDA");
    if (omciGetDeviceIDA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciGetDeviceIDA, &hm);
    } else {
      omciGetDeviceIDA = (void*)-1;
    }
  }
  if (omciGetDeviceIDA != (void*)-1)
    return omciGetDeviceIDA(lpstrName);

  return 0;
}

UINT __stdcall p_mciGetDeviceIDFromElementIDA(DWORD dwElementID, LPCSTR lpStrType)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=p_mciGetDeviceIDFromElementIDA")
#else
  #pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=_p_mciGetDeviceIDFromElementIDA@8")
#endif

  if (!omciGetDeviceIDFromElementIDA) {
    omciGetDeviceIDFromElementIDA = GetSysProc(sWinmm, "mciGetDeviceIDFromElementIDA");
    if (omciGetDeviceIDFromElementIDA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciGetDeviceIDFromElementIDA, &hm);
    } else {
      omciGetDeviceIDFromElementIDA = (void*)-1;
    }
  }
  if (omciGetDeviceIDFromElementIDA != (void*)-1)
    return omciGetDeviceIDFromElementIDA(dwElementID, lpStrType);

  return 0;
}

UINT __stdcall p_mciGetDeviceIDFromElementIDW(DWORD dwElementID, LPCWSTR lpStrType)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=p_mciGetDeviceIDFromElementIDW")
#else
  #pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=_p_mciGetDeviceIDFromElementIDW@8")
#endif

  if (!omciGetDeviceIDFromElementIDW) {
    omciGetDeviceIDFromElementIDW = GetSysProc(sWinmm, "mciGetDeviceIDFromElementIDW");
    if (omciGetDeviceIDFromElementIDW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciGetDeviceIDFromElementIDW, &hm);
    } else {
      omciGetDeviceIDFromElementIDW = (void*)-1;
    }
  }
  if (omciGetDeviceIDFromElementIDW != (void*)-1)
    return omciGetDeviceIDFromElementIDW(dwElementID, lpStrType);

  return 0;
}

UINT __stdcall p_mciGetDeviceIDW(LPCWSTR lpstrName)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciGetDeviceIDW=p_mciGetDeviceIDW")
#else
  #pragma comment(linker, "/EXPORT:mciGetDeviceIDW=_p_mciGetDeviceIDW@4")
#endif

  if (!omciGetDeviceIDW) {
    omciGetDeviceIDW = GetSysProc(sWinmm, "mciGetDeviceIDW");
    if (omciGetDeviceIDW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciGetDeviceIDW, &hm);
    } else {
      omciGetDeviceIDW = (void*)-1;
    }
  }
  if (omciGetDeviceIDW != (void*)-1)
    return omciGetDeviceIDW(lpstrName);

  return 0;
}

DWORD_PTR __stdcall p_mciGetDriverData(UINT uDeviceID)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciGetDriverData=p_mciGetDriverData")
#else
  #pragma comment(linker, "/EXPORT:mciGetDriverData=_p_mciGetDriverData@4")
#endif

  if (!omciGetDriverData) {
    omciGetDriverData = GetSysProc(sWinmm, "mciGetDriverData");
    if (omciGetDriverData) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciGetDriverData, &hm);
    } else {
      omciGetDriverData = (void*)-1;
    }
  }
  if (omciGetDriverData != (void*)-1)
    return omciGetDriverData(uDeviceID);

  return 0;
}

BOOL __stdcall p_mciGetErrorStringA(DWORD fdwError, LPSTR lpszErrorText, UINT cchErrorText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciGetErrorStringA=p_mciGetErrorStringA")
#else
  #pragma comment(linker, "/EXPORT:mciGetErrorStringA=_p_mciGetErrorStringA@12")
#endif

  if (!omciGetErrorStringA) {
    omciGetErrorStringA = GetSysProc(sWinmm, "mciGetErrorStringA");
    if (omciGetErrorStringA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciGetErrorStringA, &hm);
    } else {
      omciGetErrorStringA = (void*)-1;
    }
  }
  if (omciGetErrorStringA != (void*)-1)
    return omciGetErrorStringA(fdwError, lpszErrorText, cchErrorText);

  return FALSE;
}

BOOL __stdcall p_mciGetErrorStringW(DWORD fdwError, LPWSTR lpszErrorText, UINT cchErrorText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciGetErrorStringW=p_mciGetErrorStringW")
#else
  #pragma comment(linker, "/EXPORT:mciGetErrorStringW=_p_mciGetErrorStringW@12")
#endif

  if (!omciGetErrorStringW) {
    omciGetErrorStringW = GetSysProc(sWinmm, "mciGetErrorStringW");
    if (omciGetErrorStringW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciGetErrorStringW, &hm);
    } else {
      omciGetErrorStringW = (void*)-1;
    }
  }
  if (omciGetErrorStringW != (void*)-1)
    return omciGetErrorStringW(fdwError, lpszErrorText, cchErrorText);

  return FALSE;
}

YIELDPROC __stdcall p_mciGetYieldProc(UINT IDDevice, LPDWORD lpdwYieldData)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciGetYieldProc=p_mciGetYieldProc")
#else
  #pragma comment(linker, "/EXPORT:mciGetYieldProc=_p_mciGetYieldProc@8")
#endif

  if (!omciGetYieldProc) {
    omciGetYieldProc = GetSysProc(sWinmm, "mciGetYieldProc");
    if (omciGetYieldProc) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciGetYieldProc, &hm);
    } else {
      omciGetYieldProc = (void*)-1;
    }
  }
  if (omciGetYieldProc != (void*)-1)
    return omciGetYieldProc(IDDevice, lpdwYieldData);

  return NULL;
}

UINT __stdcall p_mciLoadCommandResource(HINSTANCE hInstance, LPCWSTR lpResName, UINT wType)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciLoadCommandResource=p_mciLoadCommandResource")
#else
  #pragma comment(linker, "/EXPORT:mciLoadCommandResource=_p_mciLoadCommandResource@12")
#endif

  if (!omciLoadCommandResource) {
    omciLoadCommandResource = GetSysProc(sWinmm, "mciLoadCommandResource");
    if (omciLoadCommandResource) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciLoadCommandResource, &hm);
    } else {
      omciLoadCommandResource = (void*)-1;
    }
  }
  if (omciLoadCommandResource != (void*)-1)
    return omciLoadCommandResource(hInstance, lpResName, wType);

  return (UINT)-1;
}

DWORD __stdcall p_mciSendCommandA(UINT IDDevice, UINT uMsg, DWORD_PTR fdwCommand, DWORD_PTR dwParam)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciSendCommandA=p_mciSendCommandA")
#else
  #pragma comment(linker, "/EXPORT:mciSendCommandA=_p_mciSendCommandA@16")
#endif

  if (!omciSendCommandA) {
    omciSendCommandA = GetSysProc(sWinmm, "mciSendCommandA");
    if (omciSendCommandA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciSendCommandA, &hm);
    } else {
      omciSendCommandA = (void*)-1;
    }
  }
  if (omciSendCommandA != (void*)-1)
    return omciSendCommandA(IDDevice, uMsg, fdwCommand, dwParam);

  return 274; // MCIERR_UNSUPPORTED_FUNCTION
}

DWORD __stdcall p_mciSendCommandW(UINT IDDevice, UINT uMsg, DWORD_PTR fdwCommand, DWORD_PTR dwParam)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciSendCommandW=p_mciSendCommandW")
#else
  #pragma comment(linker, "/EXPORT:mciSendCommandW=_p_mciSendCommandW@16")
#endif

  if (!omciSendCommandW) {
    omciSendCommandW = GetSysProc(sWinmm, "mciSendCommandW");
    if (omciSendCommandW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciSendCommandW, &hm);
    } else {
      omciSendCommandW = (void*)-1;
    }
  }
  if (omciSendCommandW != (void*)-1)
    return omciSendCommandW(IDDevice, uMsg, fdwCommand, dwParam);

  return 274; // MCIERR_UNSUPPORTED_FUNCTION
}

DWORD __stdcall p_mciSendStringA(LPCSTR lpszCommand, LPSTR lpszReturnString, UINT cchReturn, HWND hwndCallback)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciSendStringA=p_mciSendStringA")
#else
  #pragma comment(linker, "/EXPORT:mciSendStringA=_p_mciSendStringA@16")
#endif

  if (!omciSendStringA) {
    omciSendStringA = GetSysProc(sWinmm, "mciSendStringA");
    if (omciSendStringA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciSendStringA, &hm);
    } else {
      omciSendStringA = (void*)-1;
    }
  }
  if (omciSendStringA != (void*)-1)
    return omciSendStringA(lpszCommand, lpszReturnString, cchReturn, hwndCallback);

  return 274; // MCIERR_UNSUPPORTED_FUNCTION
}

DWORD __stdcall p_mciSendStringW(LPCWSTR lpszCommand, LPWSTR lpszReturnString, UINT cchReturn, HWND hwndCallback)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciSendStringW=p_mciSendStringW")
#else
  #pragma comment(linker, "/EXPORT:mciSendStringW=_p_mciSendStringW@16")
#endif

  if (!omciSendStringW) {
    omciSendStringW = GetSysProc(sWinmm, "mciSendStringW");
    if (omciSendStringW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciSendStringW, &hm);
    } else {
      omciSendStringW = (void*)-1;
    }
  }
  if (omciSendStringW != (void*)-1)
    return omciSendStringW(lpszCommand, lpszReturnString, cchReturn, hwndCallback);

  return 274; // MCIERR_UNSUPPORTED_FUNCTION
}

BOOL __stdcall p_mciSetDriverData(UINT uDeviceID, DWORD_PTR data)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciSetDriverData=p_mciSetDriverData")
#else
  #pragma comment(linker, "/EXPORT:mciSetDriverData=_p_mciSetDriverData@8")
#endif

  if (!omciSetDriverData) {
    omciSetDriverData = GetSysProc(sWinmm, "mciSetDriverData");
    if (omciSetDriverData) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciSetDriverData, &hm);
    } else {
      omciSetDriverData = (void*)-1;
    }
  }
  if (omciSetDriverData != (void*)-1)
    return omciSetDriverData(uDeviceID, data);

  return FALSE;
}

BOOL __stdcall p_mciSetYieldProc(UINT IDDevice, YIELDPROC yp, DWORD dwYieldData)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mciSetYieldProc=p_mciSetYieldProc")
#else
  #pragma comment(linker, "/EXPORT:mciSetYieldProc=_p_mciSetYieldProc@12")
#endif

  if (!omciSetYieldProc) {
    omciSetYieldProc = GetSysProc(sWinmm, "mciSetYieldProc");
    if (omciSetYieldProc) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omciSetYieldProc, &hm);
    } else {
      omciSetYieldProc = (void*)-1;
    }
  }
  if (omciSetYieldProc != (void*)-1)
    return omciSetYieldProc(IDDevice, yp, dwYieldData);

  return FALSE;
}

#ifndef _WIN64
UINT __stdcall p_mid32Message(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3)
{
  #pragma comment(linker, "/EXPORT:mid32Message=_p_mid32Message@20")

  if (!omid32Message) {
    omid32Message = GetSysProc(sWinmm, "mid32Message");
    if (omid32Message) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omid32Message, &hm);
    } else {
      omid32Message = (void*)-1;
    }
  }
  if (omid32Message != (void*)-1)
    return omid32Message(uDeviceID, uMsg, dw1, dw2, dw3);

  return 10; // MMSYSERR_NOTSUPPORTED
}
#endif // !_WIN64

UINT __stdcall p_midiConnect(HANDLE hmi, HANDLE hmo, LPVOID lpReserved)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiConnect=p_midiConnect")
#else
  #pragma comment(linker, "/EXPORT:midiConnect=_p_midiConnect@12")
#endif

  if (!omidiConnect) {
    omidiConnect = GetSysProc(sWinmm, "midiConnect");
    if (omidiConnect) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiConnect, &hm);
    } else {
      omidiConnect = (void*)-1;
    }
  }
  if (omidiConnect != (void*)-1)
    return omidiConnect(hmi, hmo, lpReserved);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiDisconnect(HANDLE hmi, HANDLE hmo, LPVOID lpReserved)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiDisconnect=p_midiDisconnect")
#else
  #pragma comment(linker, "/EXPORT:midiDisconnect=_p_midiDisconnect@12")
#endif

  if (!omidiDisconnect) {
    omidiDisconnect = GetSysProc(sWinmm, "midiDisconnect");
    if (omidiDisconnect) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiDisconnect, &hm);
    } else {
      omidiDisconnect = (void*)-1;
    }
  }
  if (omidiDisconnect != (void*)-1)
    return omidiDisconnect(hmi, hmo, lpReserved);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInAddBuffer(HANDLE hmi, LPMIDIHDR pmh, UINT cbmh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInAddBuffer=p_midiInAddBuffer")
#else
  #pragma comment(linker, "/EXPORT:midiInAddBuffer=_p_midiInAddBuffer@12")
#endif

  if (!omidiInAddBuffer) {
    omidiInAddBuffer = GetSysProc(sWinmm, "midiInAddBuffer");
    if (omidiInAddBuffer) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInAddBuffer, &hm);
    } else {
      omidiInAddBuffer = (void*)-1;
    }
  }
  if (omidiInAddBuffer != (void*)-1)
    return omidiInAddBuffer(hmi, pmh, cbmh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInClose(HANDLE hmi)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInClose=p_midiInClose")
#else
  #pragma comment(linker, "/EXPORT:midiInClose=_p_midiInClose@4")
#endif

  if (!omidiInClose) {
    omidiInClose = GetSysProc(sWinmm, "midiInClose");
    if (omidiInClose) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInClose, &hm);
    } else {
      omidiInClose = (void*)-1;
    }
  }
  if (omidiInClose != (void*)-1)
    return omidiInClose(hmi);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInGetDevCapsA(UINT_PTR uDeviceID, LPMIDIINCAPSA pmic, UINT cbmic)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInGetDevCapsA=p_midiInGetDevCapsA")
#else
  #pragma comment(linker, "/EXPORT:midiInGetDevCapsA=_p_midiInGetDevCapsA@12")
#endif

  if (!omidiInGetDevCapsA) {
    omidiInGetDevCapsA = GetSysProc(sWinmm, "midiInGetDevCapsA");
    if (omidiInGetDevCapsA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInGetDevCapsA, &hm);
    } else {
      omidiInGetDevCapsA = (void*)-1;
    }
  }
  if (omidiInGetDevCapsA != (void*)-1)
    return omidiInGetDevCapsA(uDeviceID, pmic, cbmic);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInGetDevCapsW(UINT_PTR uDeviceID, LPMIDIINCAPSW pmic, UINT cbmic)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInGetDevCapsW=p_midiInGetDevCapsW")
#else
  #pragma comment(linker, "/EXPORT:midiInGetDevCapsW=_p_midiInGetDevCapsW@12")
#endif

  if (!omidiInGetDevCapsW) {
    omidiInGetDevCapsW = GetSysProc(sWinmm, "midiInGetDevCapsW");
    if (omidiInGetDevCapsW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInGetDevCapsW, &hm);
    } else {
      omidiInGetDevCapsW = (void*)-1;
    }
  }
  if (omidiInGetDevCapsW != (void*)-1)
    return omidiInGetDevCapsW(uDeviceID, pmic, cbmic);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInGetErrorTextA(UINT mmrError, LPSTR pszText, UINT cchText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInGetErrorTextA=p_midiInGetErrorTextA")
#else
  #pragma comment(linker, "/EXPORT:midiInGetErrorTextA=_p_midiInGetErrorTextA@12")
#endif

  if (!omidiInGetErrorTextA) {
    omidiInGetErrorTextA = GetSysProc(sWinmm, "midiInGetErrorTextA");
    if (omidiInGetErrorTextA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInGetErrorTextA, &hm);
    } else {
      omidiInGetErrorTextA = (void*)-1;
    }
  }
  if (omidiInGetErrorTextA != (void*)-1)
    return omidiInGetErrorTextA(mmrError, pszText, cchText);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInGetErrorTextW(UINT mmrError, LPWSTR pszText, UINT cchText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInGetErrorTextW=p_midiInGetErrorTextW")
#else
  #pragma comment(linker, "/EXPORT:midiInGetErrorTextW=_p_midiInGetErrorTextW@12")
#endif

  if (!omidiInGetErrorTextW) {
    omidiInGetErrorTextW = GetSysProc(sWinmm, "midiInGetErrorTextW");
    if (omidiInGetErrorTextW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInGetErrorTextW, &hm);
    } else {
      omidiInGetErrorTextW = (void*)-1;
    }
  }
  if (omidiInGetErrorTextW != (void*)-1)
    return omidiInGetErrorTextW(mmrError, pszText, cchText);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInGetID(HANDLE hmi, LPUINT puDeviceID)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInGetID=p_midiInGetID")
#else
  #pragma comment(linker, "/EXPORT:midiInGetID=_p_midiInGetID@8")
#endif

  if (!omidiInGetID) {
    omidiInGetID = GetSysProc(sWinmm, "midiInGetID");
    if (omidiInGetID) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInGetID, &hm);
    } else {
      omidiInGetID = (void*)-1;
    }
  }
  if (omidiInGetID != (void*)-1)
    return omidiInGetID(hmi, puDeviceID);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInGetNumDevs(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInGetNumDevs=p_midiInGetNumDevs")
#else
  #pragma comment(linker, "/EXPORT:midiInGetNumDevs=_p_midiInGetNumDevs@0")
#endif

  if (!omidiInGetNumDevs) {
    omidiInGetNumDevs = GetSysProc(sWinmm, "midiInGetNumDevs");
    if (omidiInGetNumDevs) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInGetNumDevs, &hm);
    } else {
      omidiInGetNumDevs = (void*)-1;
    }
  }
  if (omidiInGetNumDevs != (void*)-1)
    return omidiInGetNumDevs();

  return 0;
}

UINT __stdcall p_midiInMessage(HANDLE hmi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInMessage=p_midiInMessage")
#else
  #pragma comment(linker, "/EXPORT:midiInMessage=_p_midiInMessage@16")
#endif

  if (!omidiInMessage) {
    omidiInMessage = GetSysProc(sWinmm, "midiInMessage");
    if (omidiInMessage) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInMessage, &hm);
    } else {
      omidiInMessage = (void*)-1;
    }
  }
  if (omidiInMessage != (void*)-1)
    return omidiInMessage(hmi, uMsg, dw1, dw2);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInOpen(LPHANDLE phmi, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInOpen=p_midiInOpen")
#else
  #pragma comment(linker, "/EXPORT:midiInOpen=_p_midiInOpen@20")
#endif

  if (!omidiInOpen) {
    omidiInOpen = GetSysProc(sWinmm, "midiInOpen");
    if (omidiInOpen) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInOpen, &hm);
    } else {
      omidiInOpen = (void*)-1;
    }
  }
  if (omidiInOpen != (void*)-1)
    return omidiInOpen(phmi, uDeviceID, dwCallback, dwInstance, fdwOpen);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInPrepareHeader(HANDLE hmi, LPMIDIHDR pmh, UINT cbmh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInPrepareHeader=p_midiInPrepareHeader")
#else
  #pragma comment(linker, "/EXPORT:midiInPrepareHeader=_p_midiInPrepareHeader@12")
#endif

  if (!omidiInPrepareHeader) {
    omidiInPrepareHeader = GetSysProc(sWinmm, "midiInPrepareHeader");
    if (omidiInPrepareHeader) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInPrepareHeader, &hm);
    } else {
      omidiInPrepareHeader = (void*)-1;
    }
  }
  if (omidiInPrepareHeader != (void*)-1)
    return omidiInPrepareHeader(hmi, pmh, cbmh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInReset(HANDLE hmi)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInReset=p_midiInReset")
#else
  #pragma comment(linker, "/EXPORT:midiInReset=_p_midiInReset@4")
#endif

  if (!omidiInReset) {
    omidiInReset = GetSysProc(sWinmm, "midiInReset");
    if (omidiInReset) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInReset, &hm);
    } else {
      omidiInReset = (void*)-1;
    }
  }
  if (omidiInReset != (void*)-1)
    return omidiInReset(hmi);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInStart(HANDLE hmi)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInStart=p_midiInStart")
#else
  #pragma comment(linker, "/EXPORT:midiInStart=_p_midiInStart@4")
#endif

  if (!omidiInStart) {
    omidiInStart = GetSysProc(sWinmm, "midiInStart");
    if (omidiInStart) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInStart, &hm);
    } else {
      omidiInStart = (void*)-1;
    }
  }
  if (omidiInStart != (void*)-1)
    return omidiInStart(hmi);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInStop(HANDLE hmi)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInStop=p_midiInStop")
#else
  #pragma comment(linker, "/EXPORT:midiInStop=_p_midiInStop@4")
#endif

  if (!omidiInStop) {
    omidiInStop = GetSysProc(sWinmm, "midiInStop");
    if (omidiInStop) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInStop, &hm);
    } else {
      omidiInStop = (void*)-1;
    }
  }
  if (omidiInStop != (void*)-1)
    return omidiInStop(hmi);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiInUnprepareHeader(HANDLE hmi, LPMIDIHDR pmh, UINT cbmh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiInUnprepareHeader=p_midiInUnprepareHeader")
#else
  #pragma comment(linker, "/EXPORT:midiInUnprepareHeader=_p_midiInUnprepareHeader@12")
#endif

  if (!omidiInUnprepareHeader) {
    omidiInUnprepareHeader = GetSysProc(sWinmm, "midiInUnprepareHeader");
    if (omidiInUnprepareHeader) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiInUnprepareHeader, &hm);
    } else {
      omidiInUnprepareHeader = (void*)-1;
    }
  }
  if (omidiInUnprepareHeader != (void*)-1)
    return omidiInUnprepareHeader(hmi, pmh, cbmh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutCacheDrumPatches(HANDLE hmo, UINT uPatch, LPWORD pwkya, UINT fuCache)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=p_midiOutCacheDrumPatches")
#else
  #pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=_p_midiOutCacheDrumPatches@16")
#endif

  if (!omidiOutCacheDrumPatches) {
    omidiOutCacheDrumPatches = GetSysProc(sWinmm, "midiOutCacheDrumPatches");
    if (omidiOutCacheDrumPatches) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutCacheDrumPatches, &hm);
    } else {
      omidiOutCacheDrumPatches = (void*)-1;
    }
  }
  if (omidiOutCacheDrumPatches != (void*)-1)
    return omidiOutCacheDrumPatches(hmo, uPatch, pwkya, fuCache);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutCachePatches(HANDLE hmo, UINT uBank, LPWORD pwpa, UINT fuCache)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutCachePatches=p_midiOutCachePatches")
#else
  #pragma comment(linker, "/EXPORT:midiOutCachePatches=_p_midiOutCachePatches@16")
#endif

  if (!omidiOutCachePatches) {
    omidiOutCachePatches = GetSysProc(sWinmm, "midiOutCachePatches");
    if (omidiOutCachePatches) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutCachePatches, &hm);
    } else {
      omidiOutCachePatches = (void*)-1;
    }
  }
  if (omidiOutCachePatches != (void*)-1)
    return omidiOutCachePatches(hmo, uBank, pwpa, fuCache);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutClose(HANDLE hmo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutClose=p_midiOutClose")
#else
  #pragma comment(linker, "/EXPORT:midiOutClose=_p_midiOutClose@4")
#endif

  if (!omidiOutClose) {
    omidiOutClose = GetSysProc(sWinmm, "midiOutClose");
    if (omidiOutClose) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutClose, &hm);
    } else {
      omidiOutClose = (void*)-1;
    }
  }
  if (omidiOutClose != (void*)-1)
    return omidiOutClose(hmo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutGetDevCapsA(UINT_PTR uDeviceID, LPMIDIOUTCAPSA pmoc, UINT cbmoc)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=p_midiOutGetDevCapsA")
#else
  #pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=_p_midiOutGetDevCapsA@12")
#endif

  if (!omidiOutGetDevCapsA) {
    omidiOutGetDevCapsA = GetSysProc(sWinmm, "midiOutGetDevCapsA");
    if (omidiOutGetDevCapsA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutGetDevCapsA, &hm);
    } else {
      omidiOutGetDevCapsA = (void*)-1;
    }
  }
  if (omidiOutGetDevCapsA != (void*)-1)
    return omidiOutGetDevCapsA(uDeviceID, pmoc, cbmoc);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutGetDevCapsW(UINT_PTR uDeviceID, LPMIDIOUTCAPSW pmoc, UINT cbmoc)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=p_midiOutGetDevCapsW")
#else
  #pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=_p_midiOutGetDevCapsW@12")
#endif

  if (!omidiOutGetDevCapsW) {
    omidiOutGetDevCapsW = GetSysProc(sWinmm, "midiOutGetDevCapsW");
    if (omidiOutGetDevCapsW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutGetDevCapsW, &hm);
    } else {
      omidiOutGetDevCapsW = (void*)-1;
    }
  }
  if (omidiOutGetDevCapsW != (void*)-1)
    return omidiOutGetDevCapsW(uDeviceID, pmoc, cbmoc);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutGetErrorTextA(UINT mmrError, LPSTR pszText, UINT cchText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=p_midiOutGetErrorTextA")
#else
  #pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=_p_midiOutGetErrorTextA@12")
#endif

  if (!omidiOutGetErrorTextA) {
    omidiOutGetErrorTextA = GetSysProc(sWinmm, "midiOutGetErrorTextA");
    if (omidiOutGetErrorTextA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutGetErrorTextA, &hm);
    } else {
      omidiOutGetErrorTextA = (void*)-1;
    }
  }
  if (omidiOutGetErrorTextA != (void*)-1)
    return omidiOutGetErrorTextA(mmrError, pszText, cchText);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutGetErrorTextW(UINT mmrError, LPWSTR pszText, UINT cchText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=p_midiOutGetErrorTextW")
#else
  #pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=_p_midiOutGetErrorTextW@12")
#endif

  if (!omidiOutGetErrorTextW) {
    omidiOutGetErrorTextW = GetSysProc(sWinmm, "midiOutGetErrorTextW");
    if (omidiOutGetErrorTextW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutGetErrorTextW, &hm);
    } else {
      omidiOutGetErrorTextW = (void*)-1;
    }
  }
  if (omidiOutGetErrorTextW != (void*)-1)
    return omidiOutGetErrorTextW(mmrError, pszText, cchText);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutGetID(HANDLE hmo, LPUINT puDeviceID)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutGetID=p_midiOutGetID")
#else
  #pragma comment(linker, "/EXPORT:midiOutGetID=_p_midiOutGetID@8")
#endif

  if (!omidiOutGetID) {
    omidiOutGetID = GetSysProc(sWinmm, "midiOutGetID");
    if (omidiOutGetID) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutGetID, &hm);
    } else {
      omidiOutGetID = (void*)-1;
    }
  }
  if (omidiOutGetID != (void*)-1)
    return omidiOutGetID(hmo, puDeviceID);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutGetNumDevs(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutGetNumDevs=p_midiOutGetNumDevs")
#else
  #pragma comment(linker, "/EXPORT:midiOutGetNumDevs=_p_midiOutGetNumDevs@0")
#endif

  if (!omidiOutGetNumDevs) {
    omidiOutGetNumDevs = GetSysProc(sWinmm, "midiOutGetNumDevs");
    if (omidiOutGetNumDevs) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutGetNumDevs, &hm);
    } else {
      omidiOutGetNumDevs = (void*)-1;
    }
  }
  if (omidiOutGetNumDevs != (void*)-1)
    return omidiOutGetNumDevs();

  return 0;
}

UINT __stdcall p_midiOutGetVolume(HANDLE hmo, LPDWORD pdwVolume)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutGetVolume=p_midiOutGetVolume")
#else
  #pragma comment(linker, "/EXPORT:midiOutGetVolume=_p_midiOutGetVolume@8")
#endif

  if (!omidiOutGetVolume) {
    omidiOutGetVolume = GetSysProc(sWinmm, "midiOutGetVolume");
    if (omidiOutGetVolume) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutGetVolume, &hm);
    } else {
      omidiOutGetVolume = (void*)-1;
    }
  }
  if (omidiOutGetVolume != (void*)-1)
    return omidiOutGetVolume(hmo, pdwVolume);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutLongMsg(HANDLE hmo, LPMIDIHDR pmh, UINT cbmh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutLongMsg=p_midiOutLongMsg")
#else
  #pragma comment(linker, "/EXPORT:midiOutLongMsg=_p_midiOutLongMsg@12")
#endif

  if (!omidiOutLongMsg) {
    omidiOutLongMsg = GetSysProc(sWinmm, "midiOutLongMsg");
    if (omidiOutLongMsg) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutLongMsg, &hm);
    } else {
      omidiOutLongMsg = (void*)-1;
    }
  }
  if (omidiOutLongMsg != (void*)-1)
    return omidiOutLongMsg(hmo, pmh, cbmh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutMessage(HANDLE hmo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutMessage=p_midiOutMessage")
#else
  #pragma comment(linker, "/EXPORT:midiOutMessage=_p_midiOutMessage@16")
#endif

  if (!omidiOutMessage) {
    omidiOutMessage = GetSysProc(sWinmm, "midiOutMessage");
    if (omidiOutMessage) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutMessage, &hm);
    } else {
      omidiOutMessage = (void*)-1;
    }
  }
  if (omidiOutMessage != (void*)-1)
    return omidiOutMessage(hmo, uMsg, dw1, dw2);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutOpen(LPHANDLE phmo, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutOpen=p_midiOutOpen")
#else
  #pragma comment(linker, "/EXPORT:midiOutOpen=_p_midiOutOpen@20")
#endif

  if (!omidiOutOpen) {
    omidiOutOpen = GetSysProc(sWinmm, "midiOutOpen");
    if (omidiOutOpen) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutOpen, &hm);
    } else {
      omidiOutOpen = (void*)-1;
    }
  }
  if (omidiOutOpen != (void*)-1)
    return omidiOutOpen(phmo, uDeviceID, dwCallback, dwInstance, fdwOpen);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutPrepareHeader(HANDLE hmo, LPMIDIHDR pmh, UINT cbmh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutPrepareHeader=p_midiOutPrepareHeader")
#else
  #pragma comment(linker, "/EXPORT:midiOutPrepareHeader=_p_midiOutPrepareHeader@12")
#endif

  if (!omidiOutPrepareHeader) {
    omidiOutPrepareHeader = GetSysProc(sWinmm, "midiOutPrepareHeader");
    if (omidiOutPrepareHeader) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutPrepareHeader, &hm);
    } else {
      omidiOutPrepareHeader = (void*)-1;
    }
  }
  if (omidiOutPrepareHeader != (void*)-1)
    return omidiOutPrepareHeader(hmo, pmh, cbmh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutReset(HANDLE hmo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutReset=p_midiOutReset")
#else
  #pragma comment(linker, "/EXPORT:midiOutReset=_p_midiOutReset@4")
#endif

  if (!omidiOutReset) {
    omidiOutReset = GetSysProc(sWinmm, "midiOutReset");
    if (omidiOutReset) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutReset, &hm);
    } else {
      omidiOutReset = (void*)-1;
    }
  }
  if (omidiOutReset != (void*)-1)
    return omidiOutReset(hmo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutSetVolume(HANDLE hmo, DWORD dwVolume)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutSetVolume=p_midiOutSetVolume")
#else
  #pragma comment(linker, "/EXPORT:midiOutSetVolume=_p_midiOutSetVolume@8")
#endif

  if (!omidiOutSetVolume) {
    omidiOutSetVolume = GetSysProc(sWinmm, "midiOutSetVolume");
    if (omidiOutSetVolume) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutSetVolume, &hm);
    } else {
      omidiOutSetVolume = (void*)-1;
    }
  }
  if (omidiOutSetVolume != (void*)-1)
    return omidiOutSetVolume(hmo, dwVolume);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutShortMsg(HANDLE hmo, DWORD dwMsg)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutShortMsg=p_midiOutShortMsg")
#else
  #pragma comment(linker, "/EXPORT:midiOutShortMsg=_p_midiOutShortMsg@8")
#endif

  if (!omidiOutShortMsg) {
    omidiOutShortMsg = GetSysProc(sWinmm, "midiOutShortMsg");
    if (omidiOutShortMsg) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutShortMsg, &hm);
    } else {
      omidiOutShortMsg = (void*)-1;
    }
  }
  if (omidiOutShortMsg != (void*)-1)
    return omidiOutShortMsg(hmo, dwMsg);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiOutUnprepareHeader(HANDLE hmo, LPMIDIHDR pmh, UINT cbmh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=p_midiOutUnprepareHeader")
#else
  #pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=_p_midiOutUnprepareHeader@12")
#endif

  if (!omidiOutUnprepareHeader) {
    omidiOutUnprepareHeader = GetSysProc(sWinmm, "midiOutUnprepareHeader");
    if (omidiOutUnprepareHeader) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiOutUnprepareHeader, &hm);
    } else {
      omidiOutUnprepareHeader = (void*)-1;
    }
  }
  if (omidiOutUnprepareHeader != (void*)-1)
    return omidiOutUnprepareHeader(hmo, pmh, cbmh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiStreamClose(HANDLE hms)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiStreamClose=p_midiStreamClose")
#else
  #pragma comment(linker, "/EXPORT:midiStreamClose=_p_midiStreamClose@4")
#endif

  if (!omidiStreamClose) {
    omidiStreamClose = GetSysProc(sWinmm, "midiStreamClose");
    if (omidiStreamClose) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiStreamClose, &hm);
    } else {
      omidiStreamClose = (void*)-1;
    }
  }
  if (omidiStreamClose != (void*)-1)
    return omidiStreamClose(hms);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiStreamOpen(LPHANDLE phms, LPUINT puDeviceID, DWORD cMidi, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiStreamOpen=p_midiStreamOpen")
#else
  #pragma comment(linker, "/EXPORT:midiStreamOpen=_p_midiStreamOpen@24")
#endif

  if (!omidiStreamOpen) {
    omidiStreamOpen = GetSysProc(sWinmm, "midiStreamOpen");
    if (omidiStreamOpen) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiStreamOpen, &hm);
    } else {
      omidiStreamOpen = (void*)-1;
    }
  }
  if (omidiStreamOpen != (void*)-1)
    return omidiStreamOpen(phms, puDeviceID, cMidi, dwCallback, dwInstance, fdwOpen);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiStreamOut(HANDLE hms, LPMIDIHDR pmh, UINT cbmh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiStreamOut=p_midiStreamOut")
#else
  #pragma comment(linker, "/EXPORT:midiStreamOut=_p_midiStreamOut@12")
#endif

  if (!omidiStreamOut) {
    omidiStreamOut = GetSysProc(sWinmm, "midiStreamOut");
    if (omidiStreamOut) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiStreamOut, &hm);
    } else {
      omidiStreamOut = (void*)-1;
    }
  }
  if (omidiStreamOut != (void*)-1)
    return omidiStreamOut(hms, pmh, cbmh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiStreamPause(HANDLE hms)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiStreamPause=p_midiStreamPause")
#else
  #pragma comment(linker, "/EXPORT:midiStreamPause=_p_midiStreamPause@4")
#endif

  if (!omidiStreamPause) {
    omidiStreamPause = GetSysProc(sWinmm, "midiStreamPause");
    if (omidiStreamPause) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiStreamPause, &hm);
    } else {
      omidiStreamPause = (void*)-1;
    }
  }
  if (omidiStreamPause != (void*)-1)
    return omidiStreamPause(hms);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiStreamPosition(HANDLE hms, LPMMTIME lpmmt, UINT cbmmt)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiStreamPosition=p_midiStreamPosition")
#else
  #pragma comment(linker, "/EXPORT:midiStreamPosition=_p_midiStreamPosition@12")
#endif

  if (!omidiStreamPosition) {
    omidiStreamPosition = GetSysProc(sWinmm, "midiStreamPosition");
    if (omidiStreamPosition) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiStreamPosition, &hm);
    } else {
      omidiStreamPosition = (void*)-1;
    }
  }
  if (omidiStreamPosition != (void*)-1)
    return omidiStreamPosition(hms, lpmmt, cbmmt);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiStreamProperty(HANDLE hms, LPBYTE lppropdata, DWORD dwProperty)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiStreamProperty=p_midiStreamProperty")
#else
  #pragma comment(linker, "/EXPORT:midiStreamProperty=_p_midiStreamProperty@12")
#endif

  if (!omidiStreamProperty) {
    omidiStreamProperty = GetSysProc(sWinmm, "midiStreamProperty");
    if (omidiStreamProperty) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiStreamProperty, &hm);
    } else {
      omidiStreamProperty = (void*)-1;
    }
  }
  if (omidiStreamProperty != (void*)-1)
    return omidiStreamProperty(hms, lppropdata, dwProperty);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiStreamRestart(HANDLE hms)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiStreamRestart=p_midiStreamRestart")
#else
  #pragma comment(linker, "/EXPORT:midiStreamRestart=_p_midiStreamRestart@4")
#endif

  if (!omidiStreamRestart) {
    omidiStreamRestart = GetSysProc(sWinmm, "midiStreamRestart");
    if (omidiStreamRestart) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiStreamRestart, &hm);
    } else {
      omidiStreamRestart = (void*)-1;
    }
  }
  if (omidiStreamRestart != (void*)-1)
    return omidiStreamRestart(hms);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_midiStreamStop(HANDLE hms)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:midiStreamStop=p_midiStreamStop")
#else
  #pragma comment(linker, "/EXPORT:midiStreamStop=_p_midiStreamStop@4")
#endif

  if (!omidiStreamStop) {
    omidiStreamStop = GetSysProc(sWinmm, "midiStreamStop");
    if (omidiStreamStop) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omidiStreamStop, &hm);
    } else {
      omidiStreamStop = (void*)-1;
    }
  }
  if (omidiStreamStop != (void*)-1)
    return omidiStreamStop(hms);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerClose(HANDLE hmx)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerClose=p_mixerClose")
#else
  #pragma comment(linker, "/EXPORT:mixerClose=_p_mixerClose@4")
#endif

  if (!omixerClose) {
    omixerClose = GetSysProc(sWinmm, "mixerClose");
    if (omixerClose) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerClose, &hm);
    } else {
      omixerClose = (void*)-1;
    }
  }
  if (omixerClose != (void*)-1)
    return omixerClose(hmx);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetControlDetailsA(HANDLE hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fwDetails)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=p_mixerGetControlDetailsA")
#else
  #pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=_p_mixerGetControlDetailsA@12")
#endif

  if (!omixerGetControlDetailsA) {
    omixerGetControlDetailsA = GetSysProc(sWinmm, "mixerGetControlDetailsA");
    if (omixerGetControlDetailsA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetControlDetailsA, &hm);
    } else {
      omixerGetControlDetailsA = (void*)-1;
    }
  }
  if (omixerGetControlDetailsA != (void*)-1)
    return omixerGetControlDetailsA(hmxobj, pmxcd, fwDetails);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetControlDetailsW(HANDLE hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fwDetails)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=p_mixerGetControlDetailsW")
#else
  #pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=_p_mixerGetControlDetailsW@12")
#endif

  if (!omixerGetControlDetailsW) {
    omixerGetControlDetailsW = GetSysProc(sWinmm, "mixerGetControlDetailsW");
    if (omixerGetControlDetailsW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetControlDetailsW, &hm);
    } else {
      omixerGetControlDetailsW = (void*)-1;
    }
  }
  if (omixerGetControlDetailsW != (void*)-1)
    return omixerGetControlDetailsW(hmxobj, pmxcd, fwDetails);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetDevCapsA(UINT_PTR uMxId, LPMIXERCAPSA pmxcaps, UINT cbmxcaps)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetDevCapsA=p_mixerGetDevCapsA")
#else
  #pragma comment(linker, "/EXPORT:mixerGetDevCapsA=_p_mixerGetDevCapsA@12")
#endif

  if (!omixerGetDevCapsA) {
    omixerGetDevCapsA = GetSysProc(sWinmm, "mixerGetDevCapsA");
    if (omixerGetDevCapsA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetDevCapsA, &hm);
    } else {
      omixerGetDevCapsA = (void*)-1;
    }
  }
  if (omixerGetDevCapsA != (void*)-1)
    return omixerGetDevCapsA(uMxId, pmxcaps, cbmxcaps);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetDevCapsW(UINT_PTR uMxId, LPMIXERCAPSW pmxcaps, UINT cbmxcaps)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetDevCapsW=p_mixerGetDevCapsW")
#else
  #pragma comment(linker, "/EXPORT:mixerGetDevCapsW=_p_mixerGetDevCapsW@12")
#endif

  if (!omixerGetDevCapsW) {
    omixerGetDevCapsW = GetSysProc(sWinmm, "mixerGetDevCapsW");
    if (omixerGetDevCapsW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetDevCapsW, &hm);
    } else {
      omixerGetDevCapsW = (void*)-1;
    }
  }
  if (omixerGetDevCapsW != (void*)-1)
    return omixerGetDevCapsW(uMxId, pmxcaps, cbmxcaps);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetID(HANDLE hmxobj, LPUINT puMxId, DWORD fdwId)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetID=p_mixerGetID")
#else
  #pragma comment(linker, "/EXPORT:mixerGetID=_p_mixerGetID@12")
#endif

  if (!omixerGetID) {
    omixerGetID = GetSysProc(sWinmm, "mixerGetID");
    if (omixerGetID) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetID, &hm);
    } else {
      omixerGetID = (void*)-1;
    }
  }
  if (omixerGetID != (void*)-1)
    return omixerGetID(hmxobj, puMxId, fdwId);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetLineControlsA(HANDLE hmxobj, LPMIXERLINECONTROLSA pmxlc, DWORD fdwControls)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetLineControlsA=p_mixerGetLineControlsA")
#else
  #pragma comment(linker, "/EXPORT:mixerGetLineControlsA=_p_mixerGetLineControlsA@12")
#endif

  if (!omixerGetLineControlsA) {
    omixerGetLineControlsA = GetSysProc(sWinmm, "mixerGetLineControlsA");
    if (omixerGetLineControlsA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetLineControlsA, &hm);
    } else {
      omixerGetLineControlsA = (void*)-1;
    }
  }
  if (omixerGetLineControlsA != (void*)-1)
    return omixerGetLineControlsA(hmxobj, pmxlc, fdwControls);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetLineControlsW(HANDLE hmxobj, LPMIXERLINECONTROLSW pmxlc, DWORD fdwControls)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetLineControlsW=p_mixerGetLineControlsW")
#else
  #pragma comment(linker, "/EXPORT:mixerGetLineControlsW=_p_mixerGetLineControlsW@12")
#endif

  if (!omixerGetLineControlsW) {
    omixerGetLineControlsW = GetSysProc(sWinmm, "mixerGetLineControlsW");
    if (omixerGetLineControlsW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetLineControlsW, &hm);
    } else {
      omixerGetLineControlsW = (void*)-1;
    }
  }
  if (omixerGetLineControlsW != (void*)-1)
    return omixerGetLineControlsW(hmxobj, pmxlc, fdwControls);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetLineInfoA(HANDLE hmxobj, LPMIXERLINEA pmxl, DWORD fdwInfo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetLineInfoA=p_mixerGetLineInfoA")
#else
  #pragma comment(linker, "/EXPORT:mixerGetLineInfoA=_p_mixerGetLineInfoA@12")
#endif

  if (!omixerGetLineInfoA) {
    omixerGetLineInfoA = GetSysProc(sWinmm, "mixerGetLineInfoA");
    if (omixerGetLineInfoA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetLineInfoA, &hm);
    } else {
      omixerGetLineInfoA = (void*)-1;
    }
  }
  if (omixerGetLineInfoA != (void*)-1)
    return omixerGetLineInfoA(hmxobj, pmxl, fdwInfo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetLineInfoW(HANDLE hmxobj, LPMIXERLINEW pmxl, DWORD fdwInfo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetLineInfoW=p_mixerGetLineInfoW")
#else
  #pragma comment(linker, "/EXPORT:mixerGetLineInfoW=_p_mixerGetLineInfoW@12")
#endif

  if (!omixerGetLineInfoW) {
    omixerGetLineInfoW = GetSysProc(sWinmm, "mixerGetLineInfoW");
    if (omixerGetLineInfoW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetLineInfoW, &hm);
    } else {
      omixerGetLineInfoW = (void*)-1;
    }
  }
  if (omixerGetLineInfoW != (void*)-1)
    return omixerGetLineInfoW(hmxobj, pmxl, fdwInfo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerGetNumDevs(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerGetNumDevs=p_mixerGetNumDevs")
#else
  #pragma comment(linker, "/EXPORT:mixerGetNumDevs=_p_mixerGetNumDevs@0")
#endif

  if (!omixerGetNumDevs) {
    omixerGetNumDevs = GetSysProc(sWinmm, "mixerGetNumDevs");
    if (omixerGetNumDevs) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerGetNumDevs, &hm);
    } else {
      omixerGetNumDevs = (void*)-1;
    }
  }
  if (omixerGetNumDevs != (void*)-1)
    return omixerGetNumDevs();

  return 0;
}

DWORD __stdcall p_mixerMessage(HANDLE hmx, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerMessage=p_mixerMessage")
#else
  #pragma comment(linker, "/EXPORT:mixerMessage=_p_mixerMessage@16")
#endif

  if (!omixerMessage) {
    omixerMessage = GetSysProc(sWinmm, "mixerMessage");
    if (omixerMessage) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerMessage, &hm);
    } else {
      omixerMessage = (void*)-1;
    }
  }
  if (omixerMessage != (void*)-1)
    return omixerMessage(hmx, uMsg, dwParam1, dwParam2);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerOpen(LPHANDLE phmx, UINT uMxId, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerOpen=p_mixerOpen")
#else
  #pragma comment(linker, "/EXPORT:mixerOpen=_p_mixerOpen@20")
#endif

  if (!omixerOpen) {
    omixerOpen = GetSysProc(sWinmm, "mixerOpen");
    if (omixerOpen) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerOpen, &hm);
    } else {
      omixerOpen = (void*)-1;
    }
  }
  if (omixerOpen != (void*)-1)
    return omixerOpen(phmx, uMxId, dwCallback, dwInstance, fdwOpen);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mixerSetControlDetails(HANDLE hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mixerSetControlDetails=p_mixerSetControlDetails")
#else
  #pragma comment(linker, "/EXPORT:mixerSetControlDetails=_p_mixerSetControlDetails@12")
#endif

  if (!omixerSetControlDetails) {
    omixerSetControlDetails = GetSysProc(sWinmm, "mixerSetControlDetails");
    if (omixerSetControlDetails) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omixerSetControlDetails, &hm);
    } else {
      omixerSetControlDetails = (void*)-1;
    }
  }
  if (omixerSetControlDetails != (void*)-1)
    return omixerSetControlDetails(hmxobj, pmxcd, fdwDetails);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mmDrvInstall(HANDLE hDriver, LPCWSTR wszDrvEntry, DRIVERMSGPROC drvMessage, UINT wFlags)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmDrvInstall=p_mmDrvInstall")
#else
  #pragma comment(linker, "/EXPORT:mmDrvInstall=_p_mmDrvInstall@16")
#endif

  if (!ommDrvInstall) {
    ommDrvInstall = GetSysProc(sWinmm, "mmDrvInstall");
    if (ommDrvInstall) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommDrvInstall, &hm);
    } else {
      ommDrvInstall = (void*)-1;
    }
  }
  if (ommDrvInstall != (void*)-1)
    return ommDrvInstall(hDriver, wszDrvEntry, drvMessage, wFlags);

  return 0;
}

DWORD __stdcall p_mmGetCurrentTask(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmGetCurrentTask=p_mmGetCurrentTask")
#else
  #pragma comment(linker, "/EXPORT:mmGetCurrentTask=_p_mmGetCurrentTask@0")
#endif

  if (!ommGetCurrentTask) {
    ommGetCurrentTask = GetSysProc(sWinmm, "mmGetCurrentTask");
    if (ommGetCurrentTask) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommGetCurrentTask, &hm);
    } else {
      ommGetCurrentTask = (void*)-1;
    }
  }
  if (ommGetCurrentTask != (void*)-1)
    return ommGetCurrentTask();

  return 0;
}

void __stdcall p_mmTaskBlock(DWORD h)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmTaskBlock=p_mmTaskBlock")
#else
  #pragma comment(linker, "/EXPORT:mmTaskBlock=_p_mmTaskBlock@4")
#endif

  if (!ommTaskBlock) {
    ommTaskBlock = GetSysProc(sWinmm, "mmTaskBlock");
    if (ommTaskBlock) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommTaskBlock, &hm);
    } else {
      ommTaskBlock = (void*)-1;
    }
  }
  if (ommTaskBlock != (void*)-1)
    ommTaskBlock(h);
}

UINT __stdcall p_mmTaskCreate(LPTASKCALLBACK lpfn, LPHANDLE lph, DWORD_PTR dwInst)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmTaskCreate=p_mmTaskCreate")
#else
  #pragma comment(linker, "/EXPORT:mmTaskCreate=_p_mmTaskCreate@12")
#endif

  if (!ommTaskCreate) {
    ommTaskCreate = GetSysProc(sWinmm, "mmTaskCreate");
    if (ommTaskCreate) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommTaskCreate, &hm);
    } else {
      ommTaskCreate = (void*)-1;
    }
  }
  if (ommTaskCreate != (void*)-1)
    return ommTaskCreate(lpfn, lph, dwInst);

  return 2;
}

BOOL __stdcall p_mmTaskSignal(DWORD h)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmTaskSignal=p_mmTaskSignal")
#else
  #pragma comment(linker, "/EXPORT:mmTaskSignal=_p_mmTaskSignal@4")
#endif

  if (!ommTaskSignal) {
    ommTaskSignal = GetSysProc(sWinmm, "mmTaskSignal");
    if (ommTaskSignal) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommTaskSignal, &hm);
    } else {
      ommTaskSignal = (void*)-1;
    }
  }
  if (ommTaskSignal != (void*)-1)
    return ommTaskSignal(h);

  return FALSE;
}

void __stdcall p_mmTaskYield(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmTaskYield=p_mmTaskYield")
#else
  #pragma comment(linker, "/EXPORT:mmTaskYield=_p_mmTaskYield@0")
#endif

  if (!ommTaskYield) {
    ommTaskYield = GetSysProc(sWinmm, "mmTaskYield");
    if (ommTaskYield) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommTaskYield, &hm);
    } else {
      ommTaskYield = (void*)-1;
    }
  }
  if (ommTaskYield != (void*)-1)
    ommTaskYield();
}

UINT __stdcall p_mmioAdvance(HANDLE hmmio, LPMMIOINFO pmmioinfo, UINT fuAdvance)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioAdvance=p_mmioAdvance")
#else
  #pragma comment(linker, "/EXPORT:mmioAdvance=_p_mmioAdvance@12")
#endif

  if (!ommioAdvance) {
    ommioAdvance = GetSysProc(sWinmm, "mmioAdvance");
    if (ommioAdvance) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioAdvance, &hm);
    } else {
      ommioAdvance = (void*)-1;
    }
  }
  if (ommioAdvance != (void*)-1)
    return ommioAdvance(hmmio, pmmioinfo, fuAdvance);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mmioAscend(HANDLE hmmio, LPMMCKINFO pmmcki, UINT fuAscend)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioAscend=p_mmioAscend")
#else
  #pragma comment(linker, "/EXPORT:mmioAscend=_p_mmioAscend@12")
#endif

  if (!ommioAscend) {
    ommioAscend = GetSysProc(sWinmm, "mmioAscend");
    if (ommioAscend) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioAscend, &hm);
    } else {
      ommioAscend = (void*)-1;
    }
  }
  if (ommioAscend != (void*)-1)
    return ommioAscend(hmmio, pmmcki, fuAscend);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mmioClose(HANDLE hmmio, UINT fuClose)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioClose=p_mmioClose")
#else
  #pragma comment(linker, "/EXPORT:mmioClose=_p_mmioClose@8")
#endif

  if (!ommioClose) {
    ommioClose = GetSysProc(sWinmm, "mmioClose");
    if (ommioClose) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioClose, &hm);
    } else {
      ommioClose = (void*)-1;
    }
  }
  if (ommioClose != (void*)-1)
    return ommioClose(hmmio, fuClose);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mmioCreateChunk(HANDLE hmmio, LPMMCKINFO pmmcki, UINT fuCreate)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioCreateChunk=p_mmioCreateChunk")
#else
  #pragma comment(linker, "/EXPORT:mmioCreateChunk=_p_mmioCreateChunk@12")
#endif

  if (!ommioCreateChunk) {
    ommioCreateChunk = GetSysProc(sWinmm, "mmioCreateChunk");
    if (ommioCreateChunk) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioCreateChunk, &hm);
    } else {
      ommioCreateChunk = (void*)-1;
    }
  }
  if (ommioCreateChunk != (void*)-1)
    return ommioCreateChunk(hmmio, pmmcki, fuCreate);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mmioDescend(HANDLE hmmio, LPMMCKINFO pmmcki, const LPMMCKINFO pmmckiParent, UINT fuDescend)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioDescend=p_mmioDescend")
#else
  #pragma comment(linker, "/EXPORT:mmioDescend=_p_mmioDescend@16")
#endif

  if (!ommioDescend) {
    ommioDescend = GetSysProc(sWinmm, "mmioDescend");
    if (ommioDescend) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioDescend, &hm);
    } else {
      ommioDescend = (void*)-1;
    }
  }
  if (ommioDescend != (void*)-1)
    return ommioDescend(hmmio, pmmcki, pmmckiParent, fuDescend);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mmioFlush(HANDLE hmmio, UINT fuFlush)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioFlush=p_mmioFlush")
#else
  #pragma comment(linker, "/EXPORT:mmioFlush=_p_mmioFlush@8")
#endif

  if (!ommioFlush) {
    ommioFlush = GetSysProc(sWinmm, "mmioFlush");
    if (ommioFlush) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioFlush, &hm);
    } else {
      ommioFlush = (void*)-1;
    }
  }
  if (ommioFlush != (void*)-1)
    return ommioFlush(hmmio, fuFlush);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mmioGetInfo(HANDLE hmmio, LPMMIOINFO pmmioinfo, UINT fuInfo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioGetInfo=p_mmioGetInfo")
#else
  #pragma comment(linker, "/EXPORT:mmioGetInfo=_p_mmioGetInfo@12")
#endif

  if (!ommioGetInfo) {
    ommioGetInfo = GetSysProc(sWinmm, "mmioGetInfo");
    if (ommioGetInfo) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioGetInfo, &hm);
    } else {
      ommioGetInfo = (void*)-1;
    }
  }
  if (ommioGetInfo != (void*)-1)
    return ommioGetInfo(hmmio, pmmioinfo, fuInfo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

LPMMIOPROC __stdcall p_mmioInstallIOProcA(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioInstallIOProcA=p_mmioInstallIOProcA")
#else
  #pragma comment(linker, "/EXPORT:mmioInstallIOProcA=_p_mmioInstallIOProcA@12")
#endif

  if (!ommioInstallIOProcA) {
    ommioInstallIOProcA = GetSysProc(sWinmm, "mmioInstallIOProcA");
    if (ommioInstallIOProcA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioInstallIOProcA, &hm);
    } else {
      ommioInstallIOProcA = (void*)-1;
    }
  }
  if (ommioInstallIOProcA != (void*)-1)
    return ommioInstallIOProcA(fccIOProc, pIOProc, dwFlags);

  return NULL;
}

LPMMIOPROC __stdcall p_mmioInstallIOProcW(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioInstallIOProcW=p_mmioInstallIOProcW")
#else
  #pragma comment(linker, "/EXPORT:mmioInstallIOProcW=_p_mmioInstallIOProcW@12")
#endif

  if (!ommioInstallIOProcW) {
    ommioInstallIOProcW = GetSysProc(sWinmm, "mmioInstallIOProcW");
    if (ommioInstallIOProcW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioInstallIOProcW, &hm);
    } else {
      ommioInstallIOProcW = (void*)-1;
    }
  }
  if (ommioInstallIOProcW != (void*)-1)
    return ommioInstallIOProcW(fccIOProc, pIOProc, dwFlags);

  return NULL;
}

HANDLE __stdcall p_mmioOpenA(LPSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioOpenA=p_mmioOpenA")
#else
  #pragma comment(linker, "/EXPORT:mmioOpenA=_p_mmioOpenA@12")
#endif

  if (!ommioOpenA) {
    ommioOpenA = GetSysProc(sWinmm, "mmioOpenA");
    if (ommioOpenA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioOpenA, &hm);
    } else {
      ommioOpenA = (void*)-1;
    }
  }
  if (ommioOpenA != (void*)-1)
    return ommioOpenA(pszFileName, pmmioinfo, fdwOpen);

  if (pmmioinfo)
    *(UINT*)((UINT_PTR)pmmioinfo+3*sizeof(void*)) = 10; // MMSYSERR_NOTSUPPORTED

  return NULL;
}

HANDLE __stdcall p_mmioOpenW(LPWSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioOpenW=p_mmioOpenW")
#else
  #pragma comment(linker, "/EXPORT:mmioOpenW=_p_mmioOpenW@12")
#endif

  if (!ommioOpenW) {
    ommioOpenW = GetSysProc(sWinmm, "mmioOpenW");
    if (ommioOpenW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioOpenW, &hm);
    } else {
      ommioOpenW = (void*)-1;
    }
  }
  if (ommioOpenW != (void*)-1)
    return ommioOpenW(pszFileName, pmmioinfo, fdwOpen);

  if (pmmioinfo)
    *(UINT*)((UINT_PTR)pmmioinfo+3*sizeof(void*)) = 10; // MMSYSERR_NOTSUPPORTED

  return NULL;
}

LONG __stdcall p_mmioRead(HANDLE hmmio, LPSTR pch, LONG cch)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioRead=p_mmioRead")
#else
  #pragma comment(linker, "/EXPORT:mmioRead=_p_mmioRead@12")
#endif

  if (!ommioRead) {
    ommioRead = GetSysProc(sWinmm, "mmioRead");
    if (ommioRead) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioRead, &hm);
    } else {
      ommioRead = (void*)-1;
    }
  }
  if (ommioRead != (void*)-1)
    return ommioRead(hmmio, pch, cch);

  return -1;
}

UINT __stdcall p_mmioRenameA(LPCSTR pszFileName, LPCSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioRenameA=p_mmioRenameA")
#else
  #pragma comment(linker, "/EXPORT:mmioRenameA=_p_mmioRenameA@16")
#endif

  if (!ommioRenameA) {
    ommioRenameA = GetSysProc(sWinmm, "mmioRenameA");
    if (ommioRenameA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioRenameA, &hm);
    } else {
      ommioRenameA = (void*)-1;
    }
  }
  if (ommioRenameA != (void*)-1)
    return ommioRenameA(pszFileName, pszNewFileName, pmmioinfo, fdwRename);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mmioRenameW(LPCWSTR pszFileName, LPCWSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioRenameW=p_mmioRenameW")
#else
  #pragma comment(linker, "/EXPORT:mmioRenameW=_p_mmioRenameW@16")
#endif

  if (!ommioRenameW) {
    ommioRenameW = GetSysProc(sWinmm, "mmioRenameW");
    if (ommioRenameW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioRenameW, &hm);
    } else {
      ommioRenameW = (void*)-1;
    }
  }
  if (ommioRenameW != (void*)-1)
    return ommioRenameW(pszFileName, pszNewFileName, pmmioinfo, fdwRename);

  return 10; // MMSYSERR_NOTSUPPORTED
}

LONG __stdcall p_mmioSeek(HANDLE hmmio, LONG lOffset, int iOrigin)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioSeek=p_mmioSeek")
#else
  #pragma comment(linker, "/EXPORT:mmioSeek=_p_mmioSeek@12")
#endif

  if (!ommioSeek) {
    ommioSeek = GetSysProc(sWinmm, "mmioSeek");
    if (ommioSeek) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioSeek, &hm);
    } else {
      ommioSeek = (void*)-1;
    }
  }
  if (ommioSeek != (void*)-1)
    return ommioSeek(hmmio, lOffset, iOrigin);

  return -1;
}

LONG_PTR __stdcall p_mmioSendMessage(HANDLE hmmio, UINT uMsg, LONG_PTR lParam1, LONG_PTR lParam2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioSendMessage=p_mmioSendMessage")
#else
  #pragma comment(linker, "/EXPORT:mmioSendMessage=_p_mmioSendMessage@16")
#endif

  if (!ommioSendMessage) {
    ommioSendMessage = GetSysProc(sWinmm, "mmioSendMessage");
    if (ommioSendMessage) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioSendMessage, &hm);
    } else {
      ommioSendMessage = (void*)-1;
    }
  }
  if (ommioSendMessage != (void*)-1)
    return ommioSendMessage(hmmio, uMsg, lParam1, lParam2);

  return 0;
}

UINT __stdcall p_mmioSetBuffer(HANDLE hmmio, LPSTR pchBuffer, LONG cchBuffer, UINT fuBuffer)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioSetBuffer=p_mmioSetBuffer")
#else
  #pragma comment(linker, "/EXPORT:mmioSetBuffer=_p_mmioSetBuffer@16")
#endif

  if (!ommioSetBuffer) {
    ommioSetBuffer = GetSysProc(sWinmm, "mmioSetBuffer");
    if (ommioSetBuffer) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioSetBuffer, &hm);
    } else {
      ommioSetBuffer = (void*)-1;
    }
  }
  if (ommioSetBuffer != (void*)-1)
    return ommioSetBuffer(hmmio, pchBuffer, cchBuffer, fuBuffer);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mmioSetInfo(HANDLE hmmio, LPCMMIOINFO pmmioinfo, UINT fuInfo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioSetInfo=p_mmioSetInfo")
#else
  #pragma comment(linker, "/EXPORT:mmioSetInfo=_p_mmioSetInfo@12")
#endif

  if (!ommioSetInfo) {
    ommioSetInfo = GetSysProc(sWinmm, "mmioSetInfo");
    if (ommioSetInfo) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioSetInfo, &hm);
    } else {
      ommioSetInfo = (void*)-1;
    }
  }
  if (ommioSetInfo != (void*)-1)
    return ommioSetInfo(hmmio, pmmioinfo, fuInfo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

FOURCC __stdcall p_mmioStringToFOURCCA(LPCSTR sz, UINT uFlags)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=p_mmioStringToFOURCCA")
#else
  #pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=_p_mmioStringToFOURCCA@8")
#endif

  if (!ommioStringToFOURCCA) {
    ommioStringToFOURCCA = GetSysProc(sWinmm, "mmioStringToFOURCCA");
    if (ommioStringToFOURCCA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioStringToFOURCCA, &hm);
    } else {
      ommioStringToFOURCCA = (void*)-1;
    }
  }
  if (ommioStringToFOURCCA != (void*)-1)
    return ommioStringToFOURCCA(sz, uFlags);

  return 0;
}

FOURCC __stdcall p_mmioStringToFOURCCW(LPCWSTR sz, UINT uFlags)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=p_mmioStringToFOURCCW")
#else
  #pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=_p_mmioStringToFOURCCW@8")
#endif

  if (!ommioStringToFOURCCW) {
    ommioStringToFOURCCW = GetSysProc(sWinmm, "mmioStringToFOURCCW");
    if (ommioStringToFOURCCW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioStringToFOURCCW, &hm);
    } else {
      ommioStringToFOURCCW = (void*)-1;
    }
  }
  if (ommioStringToFOURCCW != (void*)-1)
    return ommioStringToFOURCCW(sz, uFlags);

  return 0;
}

LONG __stdcall p_mmioWrite(HANDLE hmmio, LPCSTR pch, LONG cch)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmioWrite=p_mmioWrite")
#else
  #pragma comment(linker, "/EXPORT:mmioWrite=_p_mmioWrite@12")
#endif

  if (!ommioWrite) {
    ommioWrite = GetSysProc(sWinmm, "mmioWrite");
    if (ommioWrite) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommioWrite, &hm);
    } else {
      ommioWrite = (void*)-1;
    }
  }
  if (ommioWrite != (void*)-1)
    return ommioWrite(hmmio, pch, cch);

  return -1;
}

UINT __stdcall p_mmsystemGetVersion(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:mmsystemGetVersion=p_mmsystemGetVersion")
#else
  #pragma comment(linker, "/EXPORT:mmsystemGetVersion=_p_mmsystemGetVersion@0")
#endif

  if (!ommsystemGetVersion) {
    ommsystemGetVersion = GetSysProc(sWinmm, "mmsystemGetVersion");
    if (ommsystemGetVersion) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)ommsystemGetVersion, &hm);
    } else {
      ommsystemGetVersion = (void*)-1;
    }
  }
  if (ommsystemGetVersion != (void*)-1)
    return ommsystemGetVersion();

  return 0;
}

#ifndef _WIN64
UINT __stdcall p_mod32Message(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3)
{
  #pragma comment(linker, "/EXPORT:mod32Message=_p_mod32Message@20")

  if (!omod32Message) {
    omod32Message = GetSysProc(sWinmm, "mod32Message");
    if (omod32Message) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omod32Message, &hm);
    } else {
      omod32Message = (void*)-1;
    }
  }
  if (omod32Message != (void*)-1)
    return omod32Message(uDeviceID, uMsg, dw1, dw2, dw3);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_mxd32Message(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3)
{
  #pragma comment(linker, "/EXPORT:mxd32Message=_p_mxd32Message@20")

  if (!omxd32Message) {
    omxd32Message = GetSysProc(sWinmm, "mxd32Message");
    if (omxd32Message) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)omxd32Message, &hm);
    } else {
      omxd32Message = (void*)-1;
    }
  }
  if (omxd32Message != (void*)-1)
    return omxd32Message(uDeviceID, uMsg, dw1, dw2, dw3);

  return 10; // MMSYSERR_NOTSUPPORTED
}
#endif // !_WIN64

BOOL __stdcall p_sndPlaySoundA(LPCSTR lpszSound, UINT fuSound)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:sndPlaySoundA=p_sndPlaySoundA")
#else
  #pragma comment(linker, "/EXPORT:sndPlaySoundA=_p_sndPlaySoundA@8")
#endif

  if (!osndPlaySoundA) {
    osndPlaySoundA = GetSysProc(sWinmm, "sndPlaySoundA");
    if (osndPlaySoundA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)osndPlaySoundA, &hm);
    } else {
      osndPlaySoundA = (void*)-1;
    }
  }
  if (osndPlaySoundA != (void*)-1)
    return osndPlaySoundA(lpszSound, fuSound);

  return FALSE;
}

BOOL __stdcall p_sndPlaySoundW(LPCWSTR lpszSound, UINT fuSound)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:sndPlaySoundW=p_sndPlaySoundW")
#else
  #pragma comment(linker, "/EXPORT:sndPlaySoundW=_p_sndPlaySoundW@8")
#endif

  if (!osndPlaySoundW) {
    osndPlaySoundW = GetSysProc(sWinmm, "sndPlaySoundW");
    if (osndPlaySoundW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)osndPlaySoundW, &hm);
    } else {
      osndPlaySoundW = (void*)-1;
    }
  }
  if (osndPlaySoundW != (void*)-1)
    return osndPlaySoundW(lpszSound, fuSound);

  return FALSE;
}

#ifndef _WIN64
UINT __stdcall p_tid32Message(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3)
{
  #pragma comment(linker, "/EXPORT:tid32Message=_p_tid32Message@20")

  if (!otid32Message) {
    otid32Message = GetSysProc(sWinmm, "tid32Message");
    if (otid32Message) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)otid32Message, &hm);
    } else {
      otid32Message = (void*)-1;
    }
  }
  if (otid32Message != (void*)-1)
    return otid32Message(uDeviceID, uMsg, dw1, dw2, dw3);

  return 10; // MMSYSERR_NOTSUPPORTED
}
#endif // !_WIN64

UINT __stdcall p_timeBeginPeriod(UINT uPeriod)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:timeBeginPeriod=p_timeBeginPeriod")
#else
  #pragma comment(linker, "/EXPORT:timeBeginPeriod=_p_timeBeginPeriod@4")
#endif

  if (!otimeBeginPeriod) {
    otimeBeginPeriod = GetSysProc(sWinmm, "timeBeginPeriod");
    if (otimeBeginPeriod) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)otimeBeginPeriod, &hm);
    } else {
      otimeBeginPeriod = (void*)-1;
    }
  }
  if (otimeBeginPeriod != (void*)-1)
    return otimeBeginPeriod(uPeriod);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_timeEndPeriod(UINT uPeriod)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:timeEndPeriod=p_timeEndPeriod")
#else
  #pragma comment(linker, "/EXPORT:timeEndPeriod=_p_timeEndPeriod@4")
#endif

  if (!otimeEndPeriod) {
    otimeEndPeriod = GetSysProc(sWinmm, "timeEndPeriod");
    if (otimeEndPeriod) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)otimeEndPeriod, &hm);
    } else {
      otimeEndPeriod = (void*)-1;
    }
  }
  if (otimeEndPeriod != (void*)-1)
    return otimeEndPeriod(uPeriod);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:timeGetDevCaps=p_timeGetDevCaps")
#else
  #pragma comment(linker, "/EXPORT:timeGetDevCaps=_p_timeGetDevCaps@8")
#endif

  if (!otimeGetDevCaps) {
    otimeGetDevCaps = GetSysProc(sWinmm, "timeGetDevCaps");
    if (otimeGetDevCaps) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)otimeGetDevCaps, &hm);
    } else {
      otimeGetDevCaps = (void*)-1;
    }
  }
  if (otimeGetDevCaps != (void*)-1)
    return otimeGetDevCaps(ptc, cbtc);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_timeGetSystemTime(LPMMTIME pmmt, UINT cbmmt)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:timeGetSystemTime=p_timeGetSystemTime")
#else
  #pragma comment(linker, "/EXPORT:timeGetSystemTime=_p_timeGetSystemTime@8")
#endif

  if (!otimeGetSystemTime) {
    otimeGetSystemTime = GetSysProc(sWinmm, "timeGetSystemTime");
    if (otimeGetSystemTime) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)otimeGetSystemTime, &hm);
    } else {
      otimeGetSystemTime = (void*)-1;
    }
  }
  if (otimeGetSystemTime != (void*)-1)
    return otimeGetSystemTime(pmmt, cbmmt);

  return 10; // MMSYSERR_NOTSUPPORTED
}

DWORD __stdcall p_timeGetTime(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:timeGetTime=p_timeGetTime")
#else
  #pragma comment(linker, "/EXPORT:timeGetTime=_p_timeGetTime@0")
#endif

  if (!otimeGetTime) {
    otimeGetTime = GetSysProc(sWinmm, "timeGetTime");
    if (otimeGetTime) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)otimeGetTime, &hm);
    } else {
      otimeGetTime = (void*)-1;
    }
  }
  if (otimeGetTime != (void*)-1)
    return otimeGetTime();

  return 0;
}

UINT __stdcall p_timeKillEvent(UINT uTimerID)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:timeKillEvent=p_timeKillEvent")
#else
  #pragma comment(linker, "/EXPORT:timeKillEvent=_p_timeKillEvent@4")
#endif

  if (!otimeKillEvent) {
    otimeKillEvent = GetSysProc(sWinmm, "timeKillEvent");
    if (otimeKillEvent) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)otimeKillEvent, &hm);
    } else {
      otimeKillEvent = (void*)-1;
    }
  }
  if (otimeKillEvent != (void*)-1)
    return otimeKillEvent(uTimerID);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_timeSetEvent(UINT uDelay, UINT uResolution, LPTIMECALLBACK lpTimeProc, DWORD_PTR dwUser, UINT fuEvent)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:timeSetEvent=p_timeSetEvent")
#else
  #pragma comment(linker, "/EXPORT:timeSetEvent=_p_timeSetEvent@20")
#endif

  if (!otimeSetEvent) {
    otimeSetEvent = GetSysProc(sWinmm, "timeSetEvent");
    if (otimeSetEvent) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)otimeSetEvent, &hm);
    } else {
      otimeSetEvent = (void*)-1;
    }
  }
  if (otimeSetEvent != (void*)-1)
    return otimeSetEvent(uDelay, uResolution, lpTimeProc, dwUser, fuEvent);

  return 10; // MMSYSERR_NOTSUPPORTED
}


UINT __stdcall p_waveInAddBuffer(HANDLE hwi, LPWAVEHDR pwh, UINT cbwh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInAddBuffer=p_waveInAddBuffer")
#else
  #pragma comment(linker, "/EXPORT:waveInAddBuffer=_p_waveInAddBuffer@12")
#endif

  if (!owaveInAddBuffer) {
    owaveInAddBuffer = GetSysProc(sWinmm, "waveInAddBuffer");
    if (owaveInAddBuffer) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInAddBuffer, &hm);
    } else {
      owaveInAddBuffer = (void*)-1;
    }
  }
  if (owaveInAddBuffer != (void*)-1)
    return owaveInAddBuffer(hwi, pwh, cbwh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInClose(HANDLE hwi)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInClose=p_waveInClose")
#else
  #pragma comment(linker, "/EXPORT:waveInClose=_p_waveInClose@4")
#endif

  if (!owaveInClose) {
    owaveInClose = GetSysProc(sWinmm, "waveInClose");
    if (owaveInClose) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInClose, &hm);
    } else {
      owaveInClose = (void*)-1;
    }
  }
  if (owaveInClose != (void*)-1)
    return owaveInClose(hwi);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInGetDevCapsA(UINT uDeviceID, LPWAVEINCAPSA pwic, UINT cbwic)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInGetDevCapsA=p_waveInGetDevCapsA")
#else
  #pragma comment(linker, "/EXPORT:waveInGetDevCapsA=_p_waveInGetDevCapsA@12")
#endif

  if (!owaveInGetDevCapsA) {
    owaveInGetDevCapsA = GetSysProc(sWinmm, "waveInGetDevCapsA");
    if (owaveInGetDevCapsA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInGetDevCapsA, &hm);
    } else {
      owaveInGetDevCapsA = (void*)-1;
    }
  }
  if (owaveInGetDevCapsA != (void*)-1)
    return owaveInGetDevCapsA(uDeviceID, pwic, cbwic);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInGetDevCapsW(UINT uDeviceID, LPWAVEINCAPSW pwic, UINT cbwic)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInGetDevCapsW=p_waveInGetDevCapsW")
#else
  #pragma comment(linker, "/EXPORT:waveInGetDevCapsW=_p_waveInGetDevCapsW@12")
#endif

  if (!owaveInGetDevCapsW) {
    owaveInGetDevCapsW = GetSysProc(sWinmm, "waveInGetDevCapsW");
    if (owaveInGetDevCapsW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInGetDevCapsW, &hm);
    } else {
      owaveInGetDevCapsW = (void*)-1;
    }
  }
  if (owaveInGetDevCapsW != (void*)-1)
    return owaveInGetDevCapsW(uDeviceID, pwic, cbwic);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInGetErrorTextA(UINT mmrError, LPSTR pszText, UINT cchText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInGetErrorTextA=p_waveInGetErrorTextA")
#else
  #pragma comment(linker, "/EXPORT:waveInGetErrorTextA=_p_waveInGetErrorTextA@12")
#endif

  if (!owaveInGetErrorTextA) {
    owaveInGetErrorTextA = GetSysProc(sWinmm, "waveInGetErrorTextA");
    if (owaveInGetErrorTextA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInGetErrorTextA, &hm);
    } else {
      owaveInGetErrorTextA = (void*)-1;
    }
  }
  if (owaveInGetErrorTextA != (void*)-1)
    return owaveInGetErrorTextA(mmrError, pszText, cchText);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInGetErrorTextW(UINT mmrError, LPWSTR pszText, UINT cchText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInGetErrorTextW=p_waveInGetErrorTextW")
#else
  #pragma comment(linker, "/EXPORT:waveInGetErrorTextW=_p_waveInGetErrorTextW@12")
#endif

  if (!owaveInGetErrorTextW) {
    owaveInGetErrorTextW = GetSysProc(sWinmm, "waveInGetErrorTextW");
    if (owaveInGetErrorTextW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInGetErrorTextW, &hm);
    } else {
      owaveInGetErrorTextW = (void*)-1;
    }
  }
  if (owaveInGetErrorTextW != (void*)-1)
    return owaveInGetErrorTextW(mmrError, pszText, cchText);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInGetID(HANDLE hwi, LPUINT puDeviceID)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInGetID=p_waveInGetID")
#else
  #pragma comment(linker, "/EXPORT:waveInGetID=_p_waveInGetID@8")
#endif

  if (!owaveInGetID) {
    owaveInGetID = GetSysProc(sWinmm, "waveInGetID");
    if (owaveInGetID) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInGetID, &hm);
    } else {
      owaveInGetID = (void*)-1;
    }
  }
  if (owaveInGetID != (void*)-1)
    return owaveInGetID(hwi, puDeviceID);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInGetNumDevs(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInGetNumDevs=p_waveInGetNumDevs")
#else
  #pragma comment(linker, "/EXPORT:waveInGetNumDevs=_p_waveInGetNumDevs@0")
#endif

  if (!owaveInGetNumDevs) {
    owaveInGetNumDevs = GetSysProc(sWinmm, "waveInGetNumDevs");
    if (owaveInGetNumDevs) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInGetNumDevs, &hm);
    } else {
      owaveInGetNumDevs = (void*)-1;
    }
  }
  if (owaveInGetNumDevs != (void*)-1)
    return owaveInGetNumDevs();

  return 0;
}

UINT __stdcall p_waveInGetPosition(HANDLE hwi, LPMMTIME pmmt, UINT cbmmt)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInGetPosition=p_waveInGetPosition")
#else
  #pragma comment(linker, "/EXPORT:waveInGetPosition=_p_waveInGetPosition@12")
#endif

  if (!owaveInGetPosition) {
    owaveInGetPosition = GetSysProc(sWinmm, "waveInGetPosition");
    if (owaveInGetPosition) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInGetPosition, &hm);
    } else {
      owaveInGetPosition = (void*)-1;
    }
  }
  if (owaveInGetPosition != (void*)-1)
    return owaveInGetPosition(hwi, pmmt, cbmmt);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInMessage(HANDLE hwi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInMessage=p_waveInMessage")
#else
  #pragma comment(linker, "/EXPORT:waveInMessage=_p_waveInMessage@16")
#endif

  if (!owaveInMessage) {
    owaveInMessage = GetSysProc(sWinmm, "waveInMessage");
    if (owaveInMessage) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInMessage, &hm);
    } else {
      owaveInMessage = (void*)-1;
    }
  }
  if (owaveInMessage != (void*)-1)
    return owaveInMessage(hwi, uMsg, dw1, dw2);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInOpen(LPHANDLE phwi, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInOpen=p_waveInOpen")
#else
  #pragma comment(linker, "/EXPORT:waveInOpen=_p_waveInOpen@24")
#endif

  if (!owaveInOpen) {
    owaveInOpen = GetSysProc(sWinmm, "waveInOpen");
    if (owaveInOpen) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInOpen, &hm);
    } else {
      owaveInOpen = (void*)-1;
    }
  }
  if (owaveInOpen != (void*)-1)
    return owaveInOpen(phwi, uDeviceID, pwfx, dwCallback, dwInstance, fdwOpen);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInPrepareHeader(HANDLE hwi, LPWAVEHDR pwh, UINT cbwh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInPrepareHeader=p_waveInPrepareHeader")
#else
  #pragma comment(linker, "/EXPORT:waveInPrepareHeader=_p_waveInPrepareHeader@12")
#endif

  if (!owaveInPrepareHeader) {
    owaveInPrepareHeader = GetSysProc(sWinmm, "waveInPrepareHeader");
    if (owaveInPrepareHeader) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInPrepareHeader, &hm);
    } else {
      owaveInPrepareHeader = (void*)-1;
    }
  }
  if (owaveInPrepareHeader != (void*)-1)
    return owaveInPrepareHeader(hwi, pwh, cbwh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInReset(HANDLE hwi)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInReset=p_waveInReset")
#else
  #pragma comment(linker, "/EXPORT:waveInReset=_p_waveInReset@4")
#endif

  if (!owaveInReset) {
    owaveInReset = GetSysProc(sWinmm, "waveInReset");
    if (owaveInReset) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInReset, &hm);
    } else {
      owaveInReset = (void*)-1;
    }
  }
  if (owaveInReset != (void*)-1)
    return owaveInReset(hwi);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInStart(HANDLE hwi)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInStart=p_waveInStart")
#else
  #pragma comment(linker, "/EXPORT:waveInStart=_p_waveInStart@4")
#endif

  if (!owaveInStart) {
    owaveInStart = GetSysProc(sWinmm, "waveInStart");
    if (owaveInStart) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInStart, &hm);
    } else {
      owaveInStart = (void*)-1;
    }
  }
  if (owaveInStart != (void*)-1)
    return owaveInStart(hwi);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInStop(HANDLE hwi)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInStop=p_waveInStop")
#else
  #pragma comment(linker, "/EXPORT:waveInStop=_p_waveInStop@4")
#endif

  if (!owaveInStop) {
    owaveInStop = GetSysProc(sWinmm, "waveInStop");
    if (owaveInStop) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInStop, &hm);
    } else {
      owaveInStop = (void*)-1;
    }
  }
  if (owaveInStop != (void*)-1)
    return owaveInStop(hwi);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveInUnprepareHeader(HANDLE hwi, LPWAVEHDR pwh, UINT cbwh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveInUnprepareHeader=p_waveInUnprepareHeader")
#else
  #pragma comment(linker, "/EXPORT:waveInUnprepareHeader=_p_waveInUnprepareHeader@12")
#endif

  if (!owaveInUnprepareHeader) {
    owaveInUnprepareHeader = GetSysProc(sWinmm, "waveInUnprepareHeader");
    if (owaveInUnprepareHeader) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveInUnprepareHeader, &hm);
    } else {
      owaveInUnprepareHeader = (void*)-1;
    }
  }
  if (owaveInUnprepareHeader != (void*)-1)
    return owaveInUnprepareHeader(hwi, pwh, cbwh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutBreakLoop(HANDLE hwo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutBreakLoop=p_waveOutBreakLoop")
#else
  #pragma comment(linker, "/EXPORT:waveOutBreakLoop=_p_waveOutBreakLoop@4")
#endif

  if (!owaveOutBreakLoop) {
    owaveOutBreakLoop = GetSysProc(sWinmm, "waveOutBreakLoop");
    if (owaveOutBreakLoop) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutBreakLoop, &hm);
    } else {
      owaveOutBreakLoop = (void*)-1;
    }
  }
  if (owaveOutBreakLoop != (void*)-1)
    return owaveOutBreakLoop(hwo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutClose(HANDLE hwo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutClose=p_waveOutClose")
#else
  #pragma comment(linker, "/EXPORT:waveOutClose=_p_waveOutClose@4")
#endif

  if (!owaveOutClose) {
    owaveOutClose = GetSysProc(sWinmm, "waveOutClose");
    if (owaveOutClose) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutClose, &hm);
    } else {
      owaveOutClose = (void*)-1;
    }
  }
  if (owaveOutClose != (void*)-1)
    return owaveOutClose(hwo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutGetDevCapsA(UINT uDeviceID, LPWAVEOUTCAPSA pwoc, UINT cbwoc)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=p_waveOutGetDevCapsA")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=_p_waveOutGetDevCapsA@12")
#endif

  if (!owaveOutGetDevCapsA) {
    owaveOutGetDevCapsA = GetSysProc(sWinmm, "waveOutGetDevCapsA");
    if (owaveOutGetDevCapsA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetDevCapsA, &hm);
    } else {
      owaveOutGetDevCapsA = (void*)-1;
    }
  }
  if (owaveOutGetDevCapsA != (void*)-1)
    return owaveOutGetDevCapsA(uDeviceID, pwoc, cbwoc);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutGetDevCapsW(UINT uDeviceID, LPWAVEOUTCAPSW pwoc, UINT cbwoc)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=p_waveOutGetDevCapsW")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=_p_waveOutGetDevCapsW@12")
#endif

  if (!owaveOutGetDevCapsW) {
    owaveOutGetDevCapsW = GetSysProc(sWinmm, "waveOutGetDevCapsW");
    if (owaveOutGetDevCapsW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetDevCapsW, &hm);
    } else {
      owaveOutGetDevCapsW = (void*)-1;
    }
  }
  if (owaveOutGetDevCapsW != (void*)-1)
    return owaveOutGetDevCapsW(uDeviceID, pwoc, cbwoc);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutGetErrorTextA(UINT mmrError, LPSTR pszText, UINT cchText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=p_waveOutGetErrorTextA")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=_p_waveOutGetErrorTextA@12")
#endif

  if (!owaveOutGetErrorTextA) {
    owaveOutGetErrorTextA = GetSysProc(sWinmm, "waveOutGetErrorTextA");
    if (owaveOutGetErrorTextA) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetErrorTextA, &hm);
    } else {
      owaveOutGetErrorTextA = (void*)-1;
    }
  }
  if (owaveOutGetErrorTextA != (void*)-1)
    return owaveOutGetErrorTextA(mmrError, pszText, cchText);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutGetErrorTextW(UINT mmrError, LPWSTR pszText, UINT cchText)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=p_waveOutGetErrorTextW")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=_p_waveOutGetErrorTextW@12")
#endif

  if (!owaveOutGetErrorTextW) {
    owaveOutGetErrorTextW = GetSysProc(sWinmm, "waveOutGetErrorTextW");
    if (owaveOutGetErrorTextW) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetErrorTextW, &hm);
    } else {
      owaveOutGetErrorTextW = (void*)-1;
    }
  }
  if (owaveOutGetErrorTextW != (void*)-1)
    return owaveOutGetErrorTextW(mmrError, pszText, cchText);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutGetID(HANDLE hwo, LPUINT puDeviceID)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetID=p_waveOutGetID")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetID=_p_waveOutGetID@8")
#endif

  if (!owaveOutGetID) {
    owaveOutGetID = GetSysProc(sWinmm, "waveOutGetID");
    if (owaveOutGetID) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetID, &hm);
    } else {
      owaveOutGetID = (void*)-1;
    }
  }
  if (owaveOutGetID != (void*)-1)
    return owaveOutGetID(hwo, puDeviceID);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutGetNumDevs(void)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetNumDevs=p_waveOutGetNumDevs")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetNumDevs=_p_waveOutGetNumDevs@0")
#endif

  if (!owaveOutGetNumDevs) {
    owaveOutGetNumDevs = GetSysProc(sWinmm, "waveOutGetNumDevs");
    if (owaveOutGetNumDevs) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetNumDevs, &hm);
    } else {
      owaveOutGetNumDevs = (void*)-1;
    }
  }
  if (owaveOutGetNumDevs != (void*)-1)
    return owaveOutGetNumDevs();

  return 0;
}

UINT __stdcall p_waveOutGetPitch(HANDLE hwo, LPDWORD pdwPitch)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetPitch=p_waveOutGetPitch")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetPitch=_p_waveOutGetPitch@8")
#endif

  if (!owaveOutGetPitch) {
    owaveOutGetPitch = GetSysProc(sWinmm, "waveOutGetPitch");
    if (owaveOutGetPitch) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetPitch, &hm);
    } else {
      owaveOutGetPitch = (void*)-1;
    }
  }
  if (owaveOutGetPitch != (void*)-1)
    return owaveOutGetPitch(hwo, pdwPitch);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutGetPlaybackRate(HANDLE hwo, LPDWORD pdwRate)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=p_waveOutGetPlaybackRate")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=_p_waveOutGetPlaybackRate@8")
#endif

  if (!owaveOutGetPlaybackRate) {
    owaveOutGetPlaybackRate = GetSysProc(sWinmm, "waveOutGetPlaybackRate");
    if (owaveOutGetPlaybackRate) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetPlaybackRate, &hm);
    } else {
      owaveOutGetPlaybackRate = (void*)-1;
    }
  }
  if (owaveOutGetPlaybackRate != (void*)-1)
    return owaveOutGetPlaybackRate(hwo, pdwRate);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutGetPosition(HANDLE hwo, LPMMTIME pmmt, UINT cbmmt)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetPosition=p_waveOutGetPosition")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetPosition=_p_waveOutGetPosition@12")
#endif

  if (!owaveOutGetPosition) {
    owaveOutGetPosition = GetSysProc(sWinmm, "waveOutGetPosition");
    if (owaveOutGetPosition) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetPosition, &hm);
    } else {
      owaveOutGetPosition = (void*)-1;
    }
  }
  if (owaveOutGetPosition != (void*)-1)
    return owaveOutGetPosition(hwo, pmmt, cbmmt);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutGetVolume(HANDLE hwo, LPDWORD pdwVolume)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutGetVolume=p_waveOutGetVolume")
#else
  #pragma comment(linker, "/EXPORT:waveOutGetVolume=_p_waveOutGetVolume@8")
#endif

  if (!owaveOutGetVolume) {
    owaveOutGetVolume = GetSysProc(sWinmm, "waveOutGetVolume");
    if (owaveOutGetVolume) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutGetVolume, &hm);
    } else {
      owaveOutGetVolume = (void*)-1;
    }
  }
  if (owaveOutGetVolume != (void*)-1)
    return owaveOutGetVolume(hwo, pdwVolume);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutMessage(HANDLE hwo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutMessage=p_waveOutMessage")
#else
  #pragma comment(linker, "/EXPORT:waveOutMessage=_p_waveOutMessage@16")
#endif

  if (!owaveOutMessage) {
    owaveOutMessage = GetSysProc(sWinmm, "waveOutMessage");
    if (owaveOutMessage) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutMessage, &hm);
    } else {
      owaveOutMessage = (void*)-1;
    }
  }
  if (owaveOutMessage != (void*)-1)
    return owaveOutMessage(hwo, uMsg, dw1, dw2);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutOpen(LPHANDLE phwo, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutOpen=p_waveOutOpen")
#else
  #pragma comment(linker, "/EXPORT:waveOutOpen=_p_waveOutOpen@24")
#endif

  if (!owaveOutOpen) {
    owaveOutOpen = GetSysProc(sWinmm, "waveOutOpen");
    if (owaveOutOpen) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutOpen, &hm);
    } else {
      owaveOutOpen = (void*)-1;
    }
  }
  if (owaveOutOpen != (void*)-1)
    return owaveOutOpen(phwo, uDeviceID, pwfx, dwCallback, dwInstance, fdwOpen);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutPause(HANDLE hwo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutPause=p_waveOutPause")
#else
  #pragma comment(linker, "/EXPORT:waveOutPause=_p_waveOutPause@4")
#endif

  if (!owaveOutPause) {
    owaveOutPause = GetSysProc(sWinmm, "waveOutPause");
    if (owaveOutPause) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutPause, &hm);
    } else {
      owaveOutPause = (void*)-1;
    }
  }
  if (owaveOutPause != (void*)-1)
    return owaveOutPause(hwo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutPrepareHeader(HANDLE hwo, LPWAVEHDR pwh, UINT cbwh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutPrepareHeader=p_waveOutPrepareHeader")
#else
  #pragma comment(linker, "/EXPORT:waveOutPrepareHeader=_p_waveOutPrepareHeader@12")
#endif

  if (!owaveOutPrepareHeader) {
    owaveOutPrepareHeader = GetSysProc(sWinmm, "waveOutPrepareHeader");
    if (owaveOutPrepareHeader) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutPrepareHeader, &hm);
    } else {
      owaveOutPrepareHeader = (void*)-1;
    }
  }
  if (owaveOutPrepareHeader != (void*)-1)
    return owaveOutPrepareHeader(hwo, pwh, cbwh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutReset(HANDLE hwo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutReset=p_waveOutReset")
#else
  #pragma comment(linker, "/EXPORT:waveOutReset=_p_waveOutReset@4")
#endif

  if (!owaveOutReset) {
    owaveOutReset = GetSysProc(sWinmm, "waveOutReset");
    if (owaveOutReset) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutReset, &hm);
    } else {
      owaveOutReset = (void*)-1;
    }
  }
  if (owaveOutReset != (void*)-1)
    return owaveOutReset(hwo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutRestart(HANDLE hwo)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutRestart=p_waveOutRestart")
#else
  #pragma comment(linker, "/EXPORT:waveOutRestart=_p_waveOutRestart@4")
#endif

  if (!owaveOutRestart) {
    owaveOutRestart = GetSysProc(sWinmm, "waveOutRestart");
    if (owaveOutRestart) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutRestart, &hm);
    } else {
      owaveOutRestart = (void*)-1;
    }
  }
  if (owaveOutRestart != (void*)-1)
    return owaveOutRestart(hwo);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutSetPitch(HANDLE hwo, DWORD dwPitch)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutSetPitch=p_waveOutSetPitch")
#else
  #pragma comment(linker, "/EXPORT:waveOutSetPitch=_p_waveOutSetPitch@8")
#endif

  if (!owaveOutSetPitch) {
    owaveOutSetPitch = GetSysProc(sWinmm, "waveOutSetPitch");
    if (owaveOutSetPitch) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutSetPitch, &hm);
    } else {
      owaveOutSetPitch = (void*)-1;
    }
  }
  if (owaveOutSetPitch != (void*)-1)
    return owaveOutSetPitch(hwo, dwPitch);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutSetPlaybackRate(HANDLE hwo, DWORD dwRate)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=p_waveOutSetPlaybackRate")
#else
  #pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=_p_waveOutSetPlaybackRate@8")
#endif

  if (!owaveOutSetPlaybackRate) {
    owaveOutSetPlaybackRate = GetSysProc(sWinmm, "waveOutSetPlaybackRate");
    if (owaveOutSetPlaybackRate) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutSetPlaybackRate, &hm);
    } else {
      owaveOutSetPlaybackRate = (void*)-1;
    }
  }
  if (owaveOutSetPlaybackRate != (void*)-1)
    return owaveOutSetPlaybackRate(hwo, dwRate);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutSetVolume(HANDLE hwo, DWORD dwVolume)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutSetVolume=p_waveOutSetVolume")
#else
  #pragma comment(linker, "/EXPORT:waveOutSetVolume=_p_waveOutSetVolume@8")
#endif

  if (!owaveOutSetVolume) {
    owaveOutSetVolume = GetSysProc(sWinmm, "waveOutSetVolume");
    if (owaveOutSetVolume) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutSetVolume, &hm);
    } else {
      owaveOutSetVolume = (void*)-1;
    }
  }
  if (owaveOutSetVolume != (void*)-1)
    return owaveOutSetVolume(hwo, dwVolume);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutUnprepareHeader(HANDLE hwo, LPWAVEHDR pwh, UINT cbwh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=p_waveOutUnprepareHeader")
#else
  #pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=_p_waveOutUnprepareHeader@12")
#endif

  if (!owaveOutUnprepareHeader) {
    owaveOutUnprepareHeader = GetSysProc(sWinmm, "waveOutUnprepareHeader");
    if (owaveOutUnprepareHeader) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutUnprepareHeader, &hm);
    } else {
      owaveOutUnprepareHeader = (void*)-1;
    }
  }
  if (owaveOutUnprepareHeader != (void*)-1)
    return owaveOutUnprepareHeader(hwo, pwh, cbwh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_waveOutWrite(HANDLE hwo, LPWAVEHDR pwh, UINT cbwh)
{
#ifdef _WIN64
  #pragma comment(linker, "/EXPORT:waveOutWrite=p_waveOutWrite")
#else
  #pragma comment(linker, "/EXPORT:waveOutWrite=_p_waveOutWrite@12")
#endif

  if (!owaveOutWrite) {
    owaveOutWrite = GetSysProc(sWinmm, "waveOutWrite");
    if (owaveOutWrite) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owaveOutWrite, &hm);
    } else {
      owaveOutWrite = (void*)-1;
    }
  }
  if (owaveOutWrite != (void*)-1)
    return owaveOutWrite(hwo, pwh, cbwh);

  return 10; // MMSYSERR_NOTSUPPORTED
}

#ifndef _WIN64
UINT __stdcall p_wid32Message(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3)
{
  #pragma comment(linker, "/EXPORT:wid32Message=_p_wid32Message@20")

  if (!owid32Message) {
    owid32Message = GetSysProc(sWinmm, "wid32Message");
    if (owid32Message) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owid32Message, &hm);
    } else {
      owid32Message = (void*)-1;
    }
  }
  if (owid32Message != (void*)-1)
    return owid32Message(uDeviceID, uMsg, dw1, dw2, dw3);

  return 10; // MMSYSERR_NOTSUPPORTED
}

UINT __stdcall p_wod32Message(UINT_PTR uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2, DWORD_PTR dw3)
{
  #pragma comment(linker, "/EXPORT:wod32Message=_p_wod32Message@20")

  if (!owod32Message) {
    owod32Message = GetSysProc(sWinmm, "wod32Message");
    if (owod32Message) {
      HMODULE hm;
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)owod32Message, &hm);
    } else {
      owod32Message = (void*)-1;
    }
  }
  if (owod32Message != (void*)-1)
    return owod32Message(uDeviceID, uMsg, dw1, dw2, dw3);

  return 10; // MMSYSERR_NOTSUPPORTED
}
#endif // !_WIN64

__noinline static void winmm_hook() {
#ifndef DLL_PROXY_DELAY_LOAD
  HMODULE hm = LoadSysMod(sWinmm);
  if (hm) {
#if 0
    oNONAMEPlaySoundA = (PlaySoundA_fn)GetProcAddress(hm, MAKEINTRESOURCE(2));
#endif
    oCloseDriver = (CloseDriver_fn)GetProcAddress(hm, "CloseDriver");
    oDefDriverProc = (DefDriverProc_fn)GetProcAddress(hm, "DefDriverProc");
    oDriverCallback = (DriverCallback_fn)GetProcAddress(hm, "DriverCallback");
    oDrvGetModuleHandle = (DrvGetModuleHandle_fn)GetProcAddress(hm, "DrvGetModuleHandle");
    oGetDriverModuleHandle = (GetDriverModuleHandle_fn)GetProcAddress(hm, "GetDriverModuleHandle");
    oOpenDriver = (OpenDriver_fn)GetProcAddress(hm, "OpenDriver");
    oPlaySound = (PlaySoundA_fn)GetProcAddress(hm, "PlaySound");
    oPlaySoundA = (PlaySoundA_fn)GetProcAddress(hm, "PlaySoundA");
    oPlaySoundW = (PlaySoundW_fn)GetProcAddress(hm, "PlaySoundW");
    oSendDriverMessage = (SendDriverMessage_fn)GetProcAddress(hm, "SendDriverMessage");
    oWOWAppExit = (WOWAppExit_fn)GetProcAddress(hm, "WOWAppExit");
    oauxGetDevCapsA = (auxGetDevCapsA_fn)GetProcAddress(hm, "auxGetDevCapsA");
    oauxGetDevCapsW = (auxGetDevCapsW_fn)GetProcAddress(hm, "auxGetDevCapsW");
    oauxGetNumDevs = (auxGetNumDevs_fn)GetProcAddress(hm, "auxGetNumDevs");
    oauxGetVolume = (auxGetVolume_fn)GetProcAddress(hm, "auxGetVolume");
    oauxOutMessage = (auxOutMessage_fn)GetProcAddress(hm, "auxOutMessage");
    oauxSetVolume = (auxSetVolume_fn)GetProcAddress(hm, "auxSetVolume");
    ojoyConfigChanged = (joyConfigChanged_fn)GetProcAddress(hm, "joyConfigChanged");
    ojoyGetDevCapsA = (joyGetDevCapsA_fn)GetProcAddress(hm, "joyGetDevCapsA");
    ojoyGetDevCapsW = (joyGetDevCapsW_fn)GetProcAddress(hm, "joyGetDevCapsW");
    ojoyGetNumDevs = (joyGetNumDevs_fn)GetProcAddress(hm, "joyGetNumDevs");
    ojoyGetPos = (joyGetPos_fn)GetProcAddress(hm, "joyGetPos");
    ojoyGetPosEx = (joyGetPosEx_fn)GetProcAddress(hm, "joyGetPosEx");
    ojoyGetThreshold = (joyGetThreshold_fn)GetProcAddress(hm, "joyGetThreshold");
    ojoyReleaseCapture = (joyReleaseCapture_fn)GetProcAddress(hm, "joyReleaseCapture");
    ojoySetCapture = (joySetCapture_fn)GetProcAddress(hm, "joySetCapture");
    ojoySetThreshold = (joySetThreshold_fn)GetProcAddress(hm, "joySetThreshold");
    omciDriverNotify = (mciDriverNotify_fn)GetProcAddress(hm, "mciDriverNotify");
    omciDriverYield = (mciDriverYield_fn)GetProcAddress(hm, "mciDriverYield");
    omciExecute = (mciExecute_fn)GetProcAddress(hm, "mciExecute");
    omciFreeCommandResource = (mciFreeCommandResource_fn)GetProcAddress(hm, "mciFreeCommandResource");
    omciGetCreatorTask = (mciGetCreatorTask_fn)GetProcAddress(hm, "mciGetCreatorTask");
    omciGetDeviceIDA = (mciGetDeviceIDA_fn)GetProcAddress(hm, "mciGetDeviceIDA");
    omciGetDeviceIDFromElementIDA = (mciGetDeviceIDFromElementIDA_fn)GetProcAddress(hm, "mciGetDeviceIDFromElementIDA");
    omciGetDeviceIDFromElementIDW = (mciGetDeviceIDFromElementIDW_fn)GetProcAddress(hm, "mciGetDeviceIDFromElementIDW");
    omciGetDeviceIDW = (mciGetDeviceIDW_fn)GetProcAddress(hm, "mciGetDeviceIDW");
    omciGetDriverData = (mciGetDriverData_fn)GetProcAddress(hm, "mciGetDriverData");
    omciGetErrorStringA = (mciGetErrorStringA_fn)GetProcAddress(hm, "mciGetErrorStringA");
    omciGetErrorStringW = (mciGetErrorStringW_fn)GetProcAddress(hm, "mciGetErrorStringW");
    omciGetYieldProc = (mciGetYieldProc_fn)GetProcAddress(hm, "mciGetYieldProc");
    omciLoadCommandResource = (mciLoadCommandResource_fn)GetProcAddress(hm, "mciLoadCommandResource");
    omciSendCommandA = (mciSendCommandA_fn)GetProcAddress(hm, "mciSendCommandA");
    omciSendCommandW = (mciSendCommandW_fn)GetProcAddress(hm, "mciSendCommandW");
    omciSendStringA = (mciSendStringA_fn)GetProcAddress(hm, "mciSendStringA");
    omciSendStringW = (mciSendStringW_fn)GetProcAddress(hm, "mciSendStringW");
    omciSetDriverData = (mciSetDriverData_fn)GetProcAddress(hm, "mciSetDriverData");
    omciSetYieldProc = (mciSetYieldProc_fn)GetProcAddress(hm, "mciSetYieldProc");
    omidiConnect = (midiConnect_fn)GetProcAddress(hm, "midiConnect");
    omidiDisconnect = (midiDisconnect_fn)GetProcAddress(hm, "midiDisconnect");
    omidiInAddBuffer = (midiInAddBuffer_fn)GetProcAddress(hm, "midiInAddBuffer");
    omidiInClose = (midiInClose_fn)GetProcAddress(hm, "midiInClose");
    omidiInGetDevCapsA = (midiInGetDevCapsA_fn)GetProcAddress(hm, "midiInGetDevCapsA");
    omidiInGetDevCapsW = (midiInGetDevCapsW_fn)GetProcAddress(hm, "midiInGetDevCapsW");
    omidiInGetErrorTextA = (midiInGetErrorTextA_fn)GetProcAddress(hm, "midiInGetErrorTextA");
    omidiInGetErrorTextW = (midiInGetErrorTextW_fn)GetProcAddress(hm, "midiInGetErrorTextW");
    omidiInGetID = (midiInGetID_fn)GetProcAddress(hm, "midiInGetID");
    omidiInGetNumDevs = (midiInGetNumDevs_fn)GetProcAddress(hm, "midiInGetNumDevs");
    omidiInMessage = (midiInMessage_fn)GetProcAddress(hm, "midiInMessage");
    omidiInOpen = (midiInOpen_fn)GetProcAddress(hm, "midiInOpen");
    omidiInPrepareHeader = (midiInPrepareHeader_fn)GetProcAddress(hm, "midiInPrepareHeader");
    omidiInReset = (midiInReset_fn)GetProcAddress(hm, "midiInReset");
    omidiInStart = (midiInStart_fn)GetProcAddress(hm, "midiInStart");
    omidiInStop = (midiInStop_fn)GetProcAddress(hm, "midiInStop");
    omidiInUnprepareHeader = (midiInUnprepareHeader_fn)GetProcAddress(hm, "midiInUnprepareHeader");
    omidiOutCacheDrumPatches = (midiOutCacheDrumPatches_fn)GetProcAddress(hm, "midiOutCacheDrumPatches");
    omidiOutCachePatches = (midiOutCachePatches_fn)GetProcAddress(hm, "midiOutCachePatches");
    omidiOutClose = (midiOutClose_fn)GetProcAddress(hm, "midiOutClose");
    omidiOutGetDevCapsA = (midiOutGetDevCapsA_fn)GetProcAddress(hm, "midiOutGetDevCapsA");
    omidiOutGetDevCapsW = (midiOutGetDevCapsW_fn)GetProcAddress(hm, "midiOutGetDevCapsW");
    omidiOutGetErrorTextA = (midiOutGetErrorTextA_fn)GetProcAddress(hm, "midiOutGetErrorTextA");
    omidiOutGetErrorTextW = (midiOutGetErrorTextW_fn)GetProcAddress(hm, "midiOutGetErrorTextW");
    omidiOutGetID = (midiOutGetID_fn)GetProcAddress(hm, "midiOutGetID");
    omidiOutGetNumDevs = (midiOutGetNumDevs_fn)GetProcAddress(hm, "midiOutGetNumDevs");
    omidiOutGetVolume = (midiOutGetVolume_fn)GetProcAddress(hm, "midiOutGetVolume");
    omidiOutLongMsg = (midiOutLongMsg_fn)GetProcAddress(hm, "midiOutLongMsg");
    omidiOutMessage = (midiOutMessage_fn)GetProcAddress(hm, "midiOutMessage");
    omidiOutOpen = (midiOutOpen_fn)GetProcAddress(hm, "midiOutOpen");
    omidiOutPrepareHeader = (midiOutPrepareHeader_fn)GetProcAddress(hm, "midiOutPrepareHeader");
    omidiOutReset = (midiOutReset_fn)GetProcAddress(hm, "midiOutReset");
    omidiOutSetVolume = (midiOutSetVolume_fn)GetProcAddress(hm, "midiOutSetVolume");
    omidiOutShortMsg = (midiOutShortMsg_fn)GetProcAddress(hm, "midiOutShortMsg");
    omidiOutUnprepareHeader = (midiOutUnprepareHeader_fn)GetProcAddress(hm, "midiOutUnprepareHeader");
    omidiStreamClose = (midiStreamClose_fn)GetProcAddress(hm, "midiStreamClose");
    omidiStreamOpen = (midiStreamOpen_fn)GetProcAddress(hm, "midiStreamOpen");
    omidiStreamOut = (midiStreamOut_fn)GetProcAddress(hm, "midiStreamOut");
    omidiStreamPause = (midiStreamPause_fn)GetProcAddress(hm, "midiStreamPause");
    omidiStreamPosition = (midiStreamPosition_fn)GetProcAddress(hm, "midiStreamPosition");
    omidiStreamProperty = (midiStreamProperty_fn)GetProcAddress(hm, "midiStreamProperty");
    omidiStreamRestart = (midiStreamRestart_fn)GetProcAddress(hm, "midiStreamRestart");
    omidiStreamStop = (midiStreamStop_fn)GetProcAddress(hm, "midiStreamStop");
    omixerClose = (mixerClose_fn)GetProcAddress(hm, "mixerClose");
    omixerGetControlDetailsA = (mixerGetControlDetailsA_fn)GetProcAddress(hm, "mixerGetControlDetailsA");
    omixerGetControlDetailsW = (mixerGetControlDetailsW_fn)GetProcAddress(hm, "mixerGetControlDetailsW");
    omixerGetDevCapsA = (mixerGetDevCapsA_fn)GetProcAddress(hm, "mixerGetDevCapsA");
    omixerGetDevCapsW = (mixerGetDevCapsW_fn)GetProcAddress(hm, "mixerGetDevCapsW");
    omixerGetID = (mixerGetID_fn)GetProcAddress(hm, "mixerGetID");
    omixerGetLineControlsA = (mixerGetLineControlsA_fn)GetProcAddress(hm, "mixerGetLineControlsA");
    omixerGetLineControlsW = (mixerGetLineControlsW_fn)GetProcAddress(hm, "mixerGetLineControlsW");
    omixerGetLineInfoA = (mixerGetLineInfoA_fn)GetProcAddress(hm, "mixerGetLineInfoA");
    omixerGetLineInfoW = (mixerGetLineInfoW_fn)GetProcAddress(hm, "mixerGetLineInfoW");
    omixerGetNumDevs = (mixerGetNumDevs_fn)GetProcAddress(hm, "mixerGetNumDevs");
    omixerMessage = (mixerMessage_fn)GetProcAddress(hm, "mixerMessage");
    omixerOpen = (mixerOpen_fn)GetProcAddress(hm, "mixerOpen");
    omixerSetControlDetails = (mixerSetControlDetails_fn)GetProcAddress(hm, "mixerSetControlDetails");
    ommDrvInstall = (mmDrvInstall_fn)GetProcAddress(hm, "mmDrvInstall");
    ommGetCurrentTask = (mmGetCurrentTask_fn)GetProcAddress(hm, "mmGetCurrentTask");
    ommTaskBlock = (mmTaskBlock_fn)GetProcAddress(hm, "mmTaskBlock");
    ommTaskCreate = (mmTaskCreate_fn)GetProcAddress(hm, "mmTaskCreate");
    ommTaskSignal = (mmTaskSignal_fn)GetProcAddress(hm, "mmTaskSignal");
    ommTaskYield = (mmTaskYield_fn)GetProcAddress(hm, "mmTaskYield");
    ommioAdvance = (mmioAdvance_fn)GetProcAddress(hm, "mmioAdvance");
    ommioAscend = (mmioAscend_fn)GetProcAddress(hm, "mmioAscend");
    ommioClose = (mmioClose_fn)GetProcAddress(hm, "mmioClose");
    ommioCreateChunk = (mmioCreateChunk_fn)GetProcAddress(hm, "mmioCreateChunk");
    ommioDescend = (mmioDescend_fn)GetProcAddress(hm, "mmioDescend");
    ommioFlush = (mmioFlush_fn)GetProcAddress(hm, "mmioFlush");
    ommioGetInfo = (mmioGetInfo_fn)GetProcAddress(hm, "mmioGetInfo");
    ommioInstallIOProcA = (mmioInstallIOProcA_fn)GetProcAddress(hm, "mmioInstallIOProcA");
    ommioInstallIOProcW = (mmioInstallIOProcW_fn)GetProcAddress(hm, "mmioInstallIOProcW");
    ommioOpenA = (mmioOpenA_fn)GetProcAddress(hm, "mmioOpenA");
    ommioOpenW = (mmioOpenW_fn)GetProcAddress(hm, "mmioOpenW");
    ommioRead = (mmioRead_fn)GetProcAddress(hm, "mmioRead");
    ommioRenameA = (mmioRenameA_fn)GetProcAddress(hm, "mmioRenameA");
    ommioRenameW = (mmioRenameW_fn)GetProcAddress(hm, "mmioRenameW");
    ommioSeek = (mmioSeek_fn)GetProcAddress(hm, "mmioSeek");
    ommioSendMessage = (mmioSendMessage_fn)GetProcAddress(hm, "mmioSendMessage");
    ommioSetBuffer = (mmioSetBuffer_fn)GetProcAddress(hm, "mmioSetBuffer");
    ommioSetInfo = (mmioSetInfo_fn)GetProcAddress(hm, "mmioSetInfo");
    ommioStringToFOURCCA = (mmioStringToFOURCCA_fn)GetProcAddress(hm, "mmioStringToFOURCCA");
    ommioStringToFOURCCW = (mmioStringToFOURCCW_fn)GetProcAddress(hm, "mmioStringToFOURCCW");
    ommioWrite = (mmioWrite_fn)GetProcAddress(hm, "mmioWrite");
    ommsystemGetVersion = (mmsystemGetVersion_fn)GetProcAddress(hm, "mmsystemGetVersion");
    osndPlaySoundA = (sndPlaySoundA_fn)GetProcAddress(hm, "sndPlaySoundA");
    osndPlaySoundW = (sndPlaySoundW_fn)GetProcAddress(hm, "sndPlaySoundW");
    otimeBeginPeriod = (timeBeginPeriod_fn)GetProcAddress(hm, "timeBeginPeriod");
    otimeEndPeriod = (timeEndPeriod_fn)GetProcAddress(hm, "timeEndPeriod");
    otimeGetDevCaps = (timeGetDevCaps_fn)GetProcAddress(hm, "timeGetDevCaps");
    otimeGetSystemTime = (timeGetSystemTime_fn)GetProcAddress(hm, "timeGetSystemTime");
    otimeGetTime = (timeGetTime_fn)GetProcAddress(hm, "timeGetTime");
    otimeKillEvent = (timeKillEvent_fn)GetProcAddress(hm, "timeKillEvent");
    otimeSetEvent = (timeSetEvent_fn)GetProcAddress(hm, "timeSetEvent");
    owaveInAddBuffer = (waveInAddBuffer_fn)GetProcAddress(hm, "waveInAddBuffer");
    owaveInClose = (waveInClose_fn)GetProcAddress(hm, "waveInClose");
    owaveInGetDevCapsA = (waveInGetDevCapsA_fn)GetProcAddress(hm, "waveInGetDevCapsA");
    owaveInGetDevCapsW = (waveInGetDevCapsW_fn)GetProcAddress(hm, "waveInGetDevCapsW");
    owaveInGetErrorTextA = (waveInGetErrorTextA_fn)GetProcAddress(hm, "waveInGetErrorTextA");
    owaveInGetErrorTextW = (waveInGetErrorTextW_fn)GetProcAddress(hm, "waveInGetErrorTextW");
    owaveInGetID = (waveInGetID_fn)GetProcAddress(hm, "waveInGetID");
    owaveInGetNumDevs = (waveInGetNumDevs_fn)GetProcAddress(hm, "waveInGetNumDevs");
    owaveInGetPosition = (waveInGetPosition_fn)GetProcAddress(hm, "waveInGetPosition");
    owaveInMessage = (waveInMessage_fn)GetProcAddress(hm, "waveInMessage");
    owaveInOpen = (waveInOpen_fn)GetProcAddress(hm, "waveInOpen");
    owaveInPrepareHeader = (waveInPrepareHeader_fn)GetProcAddress(hm, "waveInPrepareHeader");
    owaveInReset = (waveInReset_fn)GetProcAddress(hm, "waveInReset");
    owaveInStart = (waveInStart_fn)GetProcAddress(hm, "waveInStart");
    owaveInStop = (waveInStop_fn)GetProcAddress(hm, "waveInStop");
    owaveInUnprepareHeader = (waveInUnprepareHeader_fn)GetProcAddress(hm, "waveInUnprepareHeader");
    owaveOutBreakLoop = (waveOutBreakLoop_fn)GetProcAddress(hm, "waveOutBreakLoop");
    owaveOutClose = (waveOutClose_fn)GetProcAddress(hm, "waveOutClose");
    owaveOutGetDevCapsA = (waveOutGetDevCapsA_fn)GetProcAddress(hm, "waveOutGetDevCapsA");
    owaveOutGetDevCapsW = (waveOutGetDevCapsW_fn)GetProcAddress(hm, "waveOutGetDevCapsW");
    owaveOutGetErrorTextA = (waveOutGetErrorTextA_fn)GetProcAddress(hm, "waveOutGetErrorTextA");
    owaveOutGetErrorTextW = (waveOutGetErrorTextW_fn)GetProcAddress(hm, "waveOutGetErrorTextW");
    owaveOutGetID = (waveOutGetID_fn)GetProcAddress(hm, "waveOutGetID");
    owaveOutGetNumDevs = (waveOutGetNumDevs_fn)GetProcAddress(hm, "waveOutGetNumDevs");
    owaveOutGetPitch = (waveOutGetPitch_fn)GetProcAddress(hm, "waveOutGetPitch");
    owaveOutGetPlaybackRate = (waveOutGetPlaybackRate_fn)GetProcAddress(hm, "waveOutGetPlaybackRate");
    owaveOutGetPosition = (waveOutGetPosition_fn)GetProcAddress(hm, "waveOutGetPosition");
    owaveOutGetVolume = (waveOutGetVolume_fn)GetProcAddress(hm, "waveOutGetVolume");
    owaveOutMessage = (waveOutMessage_fn)GetProcAddress(hm, "waveOutMessage");
    owaveOutOpen = (waveOutOpen_fn)GetProcAddress(hm, "waveOutOpen");
    owaveOutPause = (waveOutPause_fn)GetProcAddress(hm, "waveOutPause");
    owaveOutPrepareHeader = (waveOutPrepareHeader_fn)GetProcAddress(hm, "waveOutPrepareHeader");
    owaveOutReset = (waveOutReset_fn)GetProcAddress(hm, "waveOutReset");
    owaveOutRestart = (waveOutRestart_fn)GetProcAddress(hm, "waveOutRestart");
    owaveOutSetPitch = (waveOutSetPitch_fn)GetProcAddress(hm, "waveOutSetPitch");
    owaveOutSetPlaybackRate = (waveOutSetPlaybackRate_fn)GetProcAddress(hm, "waveOutSetPlaybackRate");
    owaveOutSetVolume = (waveOutSetVolume_fn)GetProcAddress(hm, "waveOutSetVolume");
    owaveOutUnprepareHeader = (waveOutUnprepareHeader_fn)GetProcAddress(hm, "waveOutUnprepareHeader");
    owaveOutWrite = (waveOutWrite_fn)GetProcAddress(hm, "waveOutWrite");
#ifndef _WIN64
    oNotifyCallbackData = (NotifyCallbackData_fn)GetProcAddress(hm, "NotifyCallbackData");
    oWOW32DriverCallback = (WOW32DriverCallback_fn)GetProcAddress(hm, "WOW32DriverCallback");
    oWOW32ResolveMultiMediaHandle = (WOW32ResolveMultiMediaHandle_fn)GetProcAddress(hm, "WOW32ResolveMultiMediaHandle");
    oaux32Message = (aux32Message_fn)GetProcAddress(hm, "aux32Message");
    ojoy32Message = (joy32Message_fn)GetProcAddress(hm, "joy32Message");
    omci32Message = (mci32Message_fn)GetProcAddress(hm, "mci32Message");
    omid32Message = (mid32Message_fn)GetProcAddress(hm, "mid32Message");
    omod32Message = (mod32Message_fn)GetProcAddress(hm, "mod32Message");
    omxd32Message = (mxd32Message_fn)GetProcAddress(hm, "mxd32Message");
    otid32Message = (tid32Message_fn)GetProcAddress(hm, "tid32Message");
    owid32Message = (wid32Message_fn)GetProcAddress(hm, "wid32Message");
    owod32Message = (wod32Message_fn)GetProcAddress(hm, "wod32Message");
#endif // !_WIN64
    if (oCloseDriver)
      GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCSTR)oCloseDriver, &hm);
  }
#endif // !DLL_PROXY_DELAY_LOAD
}

#endif // __WINMM_DLL_H

