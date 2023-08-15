## openspy-client

openspy-client is a modification for old PC games to replace the now-defunct GameSpy Arcade service with an open-source alternative.

This allows the multiplayer feature of those games to be used again.

The openspy client module is unobtrusive, meaning no game files need to be altered. It is loaded into the game's memory and redirects the requests from GameSpy to OpenSpy on the fly. It is very light and does not carry any performance penalty.

On this early stage, only a few games are listed as supported. However, due to the generic implementation, many games should be already supported.

Help us by [reporting the games you found working](https://github.com/anzz1/openspy-client/issues/new?labels=working+game&template=report-working-game.yml&title=%5Bworking-game%5D+X) so we can add them to the list and [reporting the ones which don't](https://github.com/anzz1/openspy-client/issues/new?labels=game+request&template=request-for-game-support.yml&title=%5Bgame-request%5D+X) so we can work on adding the support.

Aim is to eventually support 100% of GameSpy Arcade titles.

## How to install

1. Download the [latest release](https://github.com/anzz1/openspy-client/releases/latest/download/openspy.zip)

2. Install
    1. 32-bit games
        1. Extract the `openspy.x86.dll` file to the game folder, next to the game executable.  
        2. Rename the `openspy.x86.dll` to what is listed in the [supported games list](#supported-games-list)  

    2. 64-bit games
        1. Extract the `openspy.x64.dll` file to the game folder, next to the game executable.  
        2. Rename the `openspy.x64.dll` to what is listed in the [supported games list](#supported-games-list)  

3. Play !

## Account creation
If the game requires an account to play, you can create one in game.

If the game does not have an option to create an account, you can [create one here](http://account.openspy.net/).

Please note that the GameSpy protocol is old and does not meet modern password encryption security standards, so do not use a password which you have used elsewhere.

## Supported games list

| Game | Compatibility | DLL<br>(x86, 32-bit) | DLL<br>(x64, 64-bit) | Notes |
| --- | :-: | :-: | :-: | --- |
| Act of War: High Treason | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/act_of_war_gold_edition"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/9760/Act_of_War_High_Treason/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a |   |
| Civilization III | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sid_meiers_civilization_iii_complete"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `version.dll` | n/a |   |
| Civilization IV | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sid_meiers_civilization_iv_the_complete_edition"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Colin McRae Rally 2005 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/colin_mcrae_rally_2005"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput8.dll` | n/a |   |
| Crysis | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/crysis"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/17300/Crysis/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | `dinput8.dll`  |   |
| FEAR | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/game/fear_platinum"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/21090/FEAR/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a | <sub><sup>[1]</sup> Requires a No-CD patch to remove SecuROM (V7) protection<br><sup>[2]</sup> Compatible also with the free multiplayer release "FEAR Combat"</sub> |
| FEAR 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/fear_2_project_origin_reborn"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/16450/FEAR_2_Project_Origin/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a |   |
| FlatOut 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/flatout_2"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/2990/FlatOut_2/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| GangLand | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/gangland"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput8.dll` | n/a |   |
| Halo: Combat Evolved | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `version.dll` | n/a |   |
| Heretic II | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12352143/H2-OpenSpy.zip) instead<br><sup>[2]</sup> No in-game server browser, use the "gspylite" tool to connect to servers</sub> |
| IGI 2: Covert Strike | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/i_g_i_2_covert_strike"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `version.dll` | n/a |   |
| James Bond 007: Nightfire | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Need for Speed: Hot Pursuit 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Painkiller | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/painkiller"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/39530/Painkiller_Black_Edition/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a |   |
| Saints Row 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/saints_row_2"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/9480/Saints_Row_2/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| Serious Sam: The First Encounter | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/serious_sam_the_first_encounter"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Serious Sam: The Second Encounter | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/serious_sam_the_second_encounter"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Serious Sam 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Sniper Elite | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sniper_elite_berlin_1945"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/3700/Sniper_Elite/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| Star Wars: Republic Commando | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/star_wars_republic_commando"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/6000/STAR_WARS_Republic_Commando/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a |   |
| Tony Hawk's Pro Skater 4 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Unreal Tournament (1999) | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/unreal_tournament_goty"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/13240/Unreal_Tournament_Game_of_the_Year_Edition/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12317800/UT99-OpenSpy.zip) instead</sub> |
| Unreal Tournament 2004 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/unreal_tournament_2004_ece"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/13230/Unreal_Tournament_2004_Editors_Choice_Edition/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12317115/UT2004-OpenSpy.zip) instead</sub> |
| Unreal Tournament 3 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/13210/Unreal_Tournament_3/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Version 2.1 only</sub> |
| Vietcong 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Worms 3D | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| [report supported game](https://github.com/anzz1/openspy-client/issues/new?assignees=&labels=working+game&projects=&template=report-working-game.yml&title=%5Bworking-game%5D+X) |

## Unsupported games list
| Game | Status |
| --- | --- |
| [report unsupported game](https://github.com/anzz1/openspy-client/issues/new?assignees=&labels=game+request&projects=&template=request-for-game-support.yml&title=%5Bgame-request%5D+X) |

## Remarks
To uninstall, simply delete the `openspy.dll` file.

If a game is not listed, you can try renaming it as the different variations openspy-client currently supports: 
- `dinput.dll`
- `dinput8.dll`
- `version.dll`
- `dsound.dll`

Please report back with your findings to help us fill the supported games list.

Generally it does not matter how the openspy-client module is loaded into the game. This means that in addition to the variations supported, you can also use any other method to load the module into the game.

For example, if you use an [ASI loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) to load mods like [Widescreen Fix](https://thirteenag.github.io/wfp) for your game, you can simply rename the OpenSpy module to `openspy.asi` and place it next to the `WideScreenFix.asi` and it will be loaded that way.


---

:earth_americas: [Web](https://beta.openspy.net/) &emsp;
<img alt="Discord" src="https://user-images.githubusercontent.com/13628128/226210682-c9044ed1-e4d9-431c-b085-1d684a9f9942.png" width="20" height="20"> [Discord](http://discord.gg/sMaWdbt)

This component is a part of the [OpenSpy](https://beta.openspy.net/) project

- [openspy-core-v2](https://github.com/chc/openspy-core-v2)
- [openspy-web-backend](https://github.com/chc/openspy-web-backend)
- [openspy-natneg-helper](https://github.com/chc/openspy-natneg-helper)
- [openspy-discord-bot](https://github.com/chc/openspy-discord-bot)
- openspy-client

