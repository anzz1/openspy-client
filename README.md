## openspy-client

openspy-client is a modification for games to replace the now-defunct GameSpy Arcade service with an open-source alternative.

This allows the multiplayer feature of those games to be used again.

The openspy client module is unobtrusive, meaning no game files need to be altered. It is loaded into the game's memory and redirects the requests from GameSpy to OpenSpy on the fly. It is very light and does not carry any performance penalty.

On this early stage, only a few games are listed as supported. However, due to the generic implementation, many games should be already supported.

Help us by [reporting the games you found working](https://github.com/anzz1/openspy-test/issues/new?labels=working+game&template=report-working-game.yml&title=%5Bworking-game%5D+X) so we can add them to the list and [reporting the ones which don't](https://github.com/anzz1/openspy-test/issues/new?labels=game+request&template=request-for-game-support.yml&title=%5Bgame-request%5D+X) so we can work on adding the support.

Aim is to eventually support 100% of GameSpy Arcade titles.

## How to install

1. Download the [latest release](https://github.com/anzz1/openspy-test/releases/latest/download/openspy.zip)

2. Extract the `openspy.dll` file from it to the game folder, next to the game launcher.  
(e.g. if you launch your game from FlatOut2.exe, put it into the same folder with it)

3. Rename the `openspy.dll` to what is listed in the [supported games list](#supported-games-list)  
(e.g. `dinput8.dll` for FlatOut 2)

4. Play !

## Account creation
If the game requires an account to play, you can create one in game.

If the game does not have an option to create an account, you can [create one here](http://account.openspy.net/).

Please note that the GameSpy protocol is old and does not meet modern password encryption security standards, so do not use a password which you have used elsewhere.

## Supported games list

| Game | DLL (32-bit) | DLL (64-bit) | 
| --- | --- |  --- |
| Colin McRae Rally 2005 | `dinput8.dll` |   |
| Crysis | `Bin32\dinput8.dll` | `Bin64\dinput8.dll`  |
| FlatOut 2 | `dinput8.dll` |   |
| Saints Row 2 | `dinput8.dll` |   |
| [report supported game](https://github.com/anzz1/openspy-test/issues/new?assignees=&labels=working+game&projects=&template=report-working-game.yml&title=%5Bworking-game%5D+X) |

## Unsupported games list
| Game | Status |
| --- | --- |
| [report unsupported game](https://github.com/anzz1/openspy-test/issues/new?assignees=&labels=game+request&projects=&template=request-for-game-support.yml&title=%5Bgame-request%5D+X) |

## Remarks
To uninstall, simply delete the `openspy.dll` file.

If you game is not listed, you can try renaming it as the different variations openspy-client currently supports:  
- `dinput8.dll`
- `version.dll`
- `dsound.dll`

Please report back with your findings to help us fill the supported games list.

It does not matter how the openspy-client module is loaded into the game. This means that in addition to the variations supported, you can also use any other method to load the module into the game.

For example, if you already use an [ASI loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) to load a [Widescreen Fix](https://thirteenag.github.io/wfp) for your game, you can simply rename the module to `openspy.asi` and place it next to the `WideScreenFix.asi` and it will be loaded that way.


---

This component is a part of the [OpenSpy](https://beta.openspy.net/) project

- [openspy-core-v2](https://github.com/chc/openspy-core-v2)
- [openspy-web-backend](https://github.com/chc/openspy-web-backend)
- openspy-client

:earth_americas: [Web](https://beta.openspy.net/) &emsp;
<img alt="Discord" src="https://user-images.githubusercontent.com/13628128/226210682-c9044ed1-e4d9-431c-b085-1d684a9f9942.png" width="20" height="20"> [Discord](http://discord.gg/sMaWdbt)

