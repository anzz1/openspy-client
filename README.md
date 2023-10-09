## openspy-client

openspy-client is a universal modification for old PC games to replace the now-defunct GameSpy Arcade service with an open-source alternative.

This allows the multiplayer feature of those games to be used again.

The openspy client module is unobtrusive, meaning no game files need to be altered. It is loaded into the game's memory and redirects the requests from GameSpy to OpenSpy on the fly. It is very light and does not carry any performance penalty.

On this early stage, only a few games are listed as supported. However, due to the generic implementation, many games should be already supported.

Help us by [reporting the games you found working](https://github.com/anzz1/openspy-client/issues/new?labels=working+game&template=report-working-game.yml&title=%5Bworking-game%5D+GAME+NAME) so we can add them to the list and [reporting the ones which don't](https://github.com/anzz1/openspy-client/issues/new?labels=game+request&template=request-for-game-support.yml&title=%5Bgame-request%5D+GAME+NAME) so we can work on adding the support.

Aim is to eventually support 100% of GameSpy Arcade titles.

Compatible with Windows XP / Vista / 7 / 8 / 8.1 / 10 / 11 and Server 2003 / 2003 R2 / 2008 / 2008 R2 / 2012 / 2012 R2 / 2016 / 2019 / 2022

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
| Battlefield 1942 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `winmm.dll` | n/a |   |
| Battlefield Vietnam | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Blood II | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/blood_2_the_chosen_expansion"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/299050/Blood_II_The_Chosen__Expansion/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `winmm.dll` | n/a |   |
| Civilization III | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sid_meiers_civilization_iii_complete"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `version.dll` | n/a |   |
| Civilization IV | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sid_meiers_civilization_iv_the_complete_edition"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Colin McRae Rally 2005 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/colin_mcrae_rally_2005"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput8.dll` | n/a |   |
| Crysis | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/crysis"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/17300/Crysis/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | `version.dll`  | <sub><sup>[1]</sup> Replacing game executables with [c1-launcher](https://github.com/ccomrade/c1-launcher/releases/latest) is highly recommended for additional fixes</sub> |
| Crysis Wars | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/crysiswarhead"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/17330/Crysis_Warhead/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | `version.dll`  | <sub><sup>[1]</sup> Replacing game executables with [c1-launcher](https://github.com/ccomrade/c1-launcher/releases/latest) is highly recommended for additional fixes</sub> |
| Damnation | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/12790/Damnation/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/damnation/Damnation.v1.0.NoCD.zip) to remove SecuROM (V7) protection&nbsp;&nbsp;<sup>**RETAIL**</sup></sub> |
| Deer Hunter 2004 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Deer Hunter 2005 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| F1 Challenge '99-'02 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/f1comp/F1.Challenge.99-02.v1.0.NoCD.zip) to remove SafeDisc (V2) protection</sub> |
| F.E.A.R. | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/game/fear_platinum"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/21090/FEAR/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.08 update](https://taco.cab/files/games/fear/fear_update_en_100-107_108.zip)&nbsp;&nbsp;<sup>**RETAIL**</sup><br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/fear/FEAR.v1.08.NoCD.zip) to remove SecuROM (V7) protection</sub> |
| F.E.A.R. Combat | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `version.dll` | n/a | <sub><sup>[1]</sup> [Free download](https://taco.cab/files/games/fear/fearcombat_en_107.zip)<br><sup>[2]</sup> Requires latest [v1.08 update](https://taco.cab/files/games/fear/fearcombat_update_en_107_108.zip)<br><sup>[3]</sup> Requires [No-CD patch](https://taco.cab/files/games/fear/FEAR.v1.08.NoCD.zip) to remove SecuROM (V7) protection</sub> |
| F.E.A.R. Perseus Mandate | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/game/fear_platinum"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/21120/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.08 update](https://taco.cab/files/games/fear/fear_update_en_100-107_108.zip)&nbsp;&nbsp;<sup>**RETAIL**</sup><br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/fear/FEAR.v1.08.NoCD.zip) to remove SecuROM (V7) protection</sub> |
| F.E.A.R. 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/fear_2_project_origin_reborn"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/16450/FEAR_2_Project_Origin/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a |   |
| FlatOut 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/flatout_2"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/2990/FlatOut_2/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| GangLand | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/gangland"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput8.dll` | n/a |   |
| Gene Troopers | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/gtroopers/Gene.Troopers.v1.0.NoCD.zip) to remove StarForce (V3) protection</sub> |
| Global Operations | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `version.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v2.0 update](https://taco.cab/files/games/glops/glopsus2_0.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/glops/GlobalOps.v2.0.NoCD.zip) to remove SafeDisc (V2) protection</sub> |
| Halo: Combat Evolved | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `version.dll` | n/a |   |
| Heretic II | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12352143/H2-OpenSpy.zip) instead<br><sup>[2]</sup> No in-game server browser, use the "gspylite" tool to connect to servers</sub> |
| Hidden &amp; Dangerous 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/game/hidden_dangerous_2_courage_under_fire"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/703320/Hidden__Dangerous_2_Courage_Under_Fire/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput.dll` | n/a |   |
| IGI 2: Covert Strike | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/i_g_i_2_covert_strike"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `version.dll` | n/a |   |
| James Bond 007: Nightfire | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Jet Fighter IV | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput.dll` | n/a |   |
| Magic: The Gathering - Battlegrounds | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Medal of Honor: Allied Assault | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/medal_of_honor_allied_assault_war_chest"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput.dll` | n/a |   |
| Midnight Club 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/12160/Midnight_Club_2/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| MX vs. ATV Unleashed | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/mx_vs_atv_unleashed"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/359220/MX_vs_ATV_Unleashed/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dsound.dll` | n/a |   |
| Need for Speed: Hot Pursuit 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Nerf Arena Blast | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12753460/NAB-OpenSpy.zip) instead<br><sup>[2]</sup> Latest [v1.2 update](https://taco.cab/files/games/nerf/nerfpatch1-2.zip) is recommended</sub> |
| Painkiller | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/painkiller"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/39530/Painkiller_Black_Edition/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| ParaWorld | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `winmm.dll` | n/a | <sub><sup>[1]</sup> Latest [v1.01 update](https://taco.cab/files/games/paraworld/paraworld_patch_1_01.zip) is recommended</sub> |
| Saints Row 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/saints_row_2"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/9480/Saints_Row_2/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| Serious Sam: The First Encounter | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/serious_sam_the_first_encounter"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Serious Sam: The Second Encounter | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/serious_sam_the_second_encounter"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Serious Sam 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Sniper Elite | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sniper_elite_berlin_1945"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/3700/Sniper_Elite/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| Star Trek: Bridge Commander | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/star_trek_bridge_commander"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput.dll` | n/a |   |
| Star Wars: Republic Commando | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/star_wars_republic_commando"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/6000/STAR_WARS_Republic_Commando/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a |   |
| Terminator 3: War of the Machines | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.16 update](https://taco.cab/files/games/t3wotm/t3wotm_us_retail-116.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/t3wotm/T3.WOTM.v1.16.NoCD.zip) to remove SecuROM (V5) protection</sub> |
| TimeShift | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/game/timeshift"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/10130/TimeShift/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.02 update](https://taco.cab/files/games/timeshift/timeshiftpatch12.zip)&nbsp;&nbsp;<sup>**RETAIL&nbsp;&nbsp;STEAM**</sup></sub> |
| TOCA Race Driver | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| TOCA Race Driver 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| TOCA Race Driver 3 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/toca_race_driver_3"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Tom Clancy's Ghost Recon: Advanced Warfighter | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/13640/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.35 update](https://taco.cab/files/games/graw/graw_patch_135.zip)&nbsp;&nbsp;<sup>**RETAIL**</sup><br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/graw/GRAW.v1.35.NoCD.zip) to remove SecuROM (V7) protection&nbsp;&nbsp;<sup>**RETAIL**</sup></sub> |
| Tom Clancy's Ghost Recon: Advanced Warfighter 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/13510/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a |   |
| Tom Clancy's Rainbow Six: Rogue Spear | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/13660/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dsound.dll` | n/a |   |
| Tony Hawk's American Wasteland | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Tony Hawk's Pro Skater 3 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Tony Hawk's Pro Skater 4 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Tony Hawk's Underground 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Unreal | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/unreal_gold"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/13250/Unreal_Gold/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12391719/Unreal-OpenSpy.zip) instead</sub> |
| Unreal Tournament (1999) | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/unreal_tournament_goty"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/13240/Unreal_Tournament_Game_of_the_Year_Edition/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12317800/UT99-OpenSpy.zip) instead</sub> |
| Unreal Tournament 2003 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12413467/UT2003-OpenSpy.zip) instead</sub> |
| Unreal Tournament 2004 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/unreal_tournament_2004_ece"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/13230/Unreal_Tournament_2004_Editors_Choice_Edition/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12317115/UT2004-OpenSpy.zip) instead</sub> |
| Unreal Tournament 3 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/13210/Unreal_Tournament_3/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v2.1 update](https://taco.cab/files/games/ut3/UT3Patch5.zip)&nbsp;&nbsp;<sup>**RETAIL**</sup></sub> |
| Vietcong 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Worms 3D | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.073 update](https://taco.cab/files/games/w3d/Worms3DServicePatch2.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/w3d/W3D.Euro.v1.073.NoCD.zip) to remove SecuROM (V5) protection</sub> |
| Worms 4: Mayhem | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.01 update](https://taco.cab/files/games/w4m/WormsMayhemPATCHv1.01.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/w4m/W4M.Euro.v1.01.3013.NoDRM.zip) to remove StarForce (V3) protection</sub> |
| Worms 4: Mayhem Online Demo | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> [Free download](https://taco.cab/files/games/w4m/worms_4_multi_demo.zip)</sub> |
| X-Men Legends II | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/xml2/X-Men.Legends.II.v1.0.NoCD.zip) to remove SafeDisc (V4) protection</sub> |
| [report supported game](https://github.com/anzz1/openspy-client/issues/new?assignees=&labels=working+game&projects=&template=report-working-game.yml&title=%5Bworking-game%5D+GAME+NAME) |

## Unsupported games list
| Game | Status |
| --- | --- |
| Battlefield 2142 | not working |
| Battle for Middle-earth II | not working |
| Crysis 2 | not working |
| Men of War: Assault Squad | coming soon&trade; |
| Rise Of Nations: Rise Of Legends | coming soon&trade;, see [issue #2](https://github.com/anzz1/openspy-client/issues/2) |
| Soldier of Fortune 2: Double Helix | not working |
| Test Drive Unlimited | not working |
| [report unsupported game](https://github.com/anzz1/openspy-client/issues/new?assignees=&labels=game+request&projects=&template=request-for-game-support.yml&title=%5Bgame-request%5D+GAME+NAME) |

## Remarks
To uninstall, simply delete the `openspy.dll` file.

If a game is not listed, you can try renaming it as the different variations openspy-client currently supports: 
- `dinput.dll`
- `dinput8.dll`
- `version.dll`
- `dsound.dll`
- `winmm.dll`

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

