## openspy-client

**openspy-client** is a universal modification for old PC games to replace the now-defunct GameSpy Arcade service with an open-source alternative.

This allows the multiplayer feature of those games to be used again.

The **openspy-client** module is unobtrusive, meaning no game files need to be altered. It is loaded into the game's memory and redirects the requests from GameSpy to OpenSpy on the fly. It is very light and does not carry any performance penalty.

In this early stage, only a few games are listed as supported. However, due to the generic implementation, many games should be already supported.

Help us by [reporting the games you found working](https://github.com/anzz1/openspy-client/issues/new?labels=working+game&template=report-working-game.yml&title=%5Bworking-game%5D+GAME+NAME) so we can add them to the list, and [reporting the ones which don't](https://github.com/anzz1/openspy-client/issues/new?labels=game+request&template=request-for-game-support.yml&title=%5Bgame-request%5D+GAME+NAME) so we can work on adding the support.

The goal is to eventually support 100% of GameSpy Arcade titles.

Compatible with Windows XP / Vista / 7 / 8 / 8.1 / 10 / 11 and Server 2003 / 2003 R2 / 2008 / 2008 R2 / 2012 / 2012 R2 / 2016 / 2019 / 2022.

## How to install

1. Download the [latest release](https://github.com/anzz1/openspy-client/releases/latest/download/openspy.zip).

2. Install:
    1. For 32-bit games:
        1. Extract the `openspy.x86.dll` file to the game folder, next to the game executable.  
        2. Rename the `openspy.x86.dll` to the name listed in the [supported games list](#supported-games-list).

    2. For 64-bit games:
        1. Extract the `openspy.x64.dll` file to the game folder, next to the game executable.  
        2. Rename the `openspy.x64.dll` to the name listed in the [supported games list](#supported-games-list).

3. Play!

## Account creation

If the game requires an account to play, you can create one in-game.

Please note that the GameSpy protocol is old and does not meet modern password encryption security standards, so **do not** use a password which you have used elsewhere.

## Supported games list

| Game | Compatibility | DLL<br>(x86, 32-bit) | DLL<br>(x64, 64-bit) | Notes |
| --- | :-: | :-: | :-: | --- |
| 1944: Battle of the Bulge | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/botb/BotB.v1.0.NoCD.zip) to remove StarForce (V3) protection</sub> |
| Act of War: High Treason | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/act_of_war_gold_edition"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/9760/Act_of_War_High_Treason/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a |   |
| Anno 1701 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/anno_1701_ad"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `version.dll` | n/a |   |
| Area 51 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> [Free download](https://taco.cab/files/games/a51/midway_area51.zip)<br><sup>[2]</sup> Requires latest [v1.2 update](https://taco.cab/files/games/a51/a51_us_patch_1_2.zip)</sub> |
| Battlefield 1942 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `winmm.dll` | n/a |   |
| Battlefield Vietnam | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Blood II | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/blood_2_the_chosen_expansion"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/299050/Blood_II_The_Chosen__Expansion/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `winmm.dll` | n/a |   |
| Chaser | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/game/chaser"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/39670/Chaser/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| Civilization III | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sid_meiers_civilization_iii_complete"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `version.dll` | n/a |   |
| Civilization IV | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sid_meiers_civilization_iv_the_complete_edition"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Colin McRae Rally 2005 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/colin_mcrae_rally_2005"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput8.dll` | n/a |   |
| Conan: The Dark Axe | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.03 update](https://taco.cab/files/games/conan/conan_v1_03.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/conan/Conan.v1.03.NoCD.zip) to remove SecuROM (V5) protection</sub> |
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
| Full Spectrum Warrior | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/full_spectrum_warrior"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/4520/Full_Spectrum_Warrior/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| GangLand | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/gangland"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput8.dll` | n/a |   |
| Gene Troopers | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/gtroopers/Gene.Troopers.v1.0.NoCD.zip) to remove StarForce (V3) protection</sub> |
| Global Operations | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `version.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v2.0 update](https://taco.cab/files/games/glops/glopsus2_0.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/glops/GlobalOps.v2.0.NoCD.zip) to remove SafeDisc (V2) protection</sub> |
| Halo: Combat Evolved | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `version.dll` | n/a |   |
| Heretic II | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12352143/H2-OpenSpy.zip) instead<br><sup>[2]</sup> No in-game server browser, use the "gspylite" tool to connect to servers</sub> |
| Hidden &amp; Dangerous 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/game/hidden_dangerous_2_courage_under_fire"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/703320/Hidden__Dangerous_2_Courage_Under_Fire/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput.dll` | n/a |   |
| IGI 2: Covert Strike | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/i_g_i_2_covert_strike"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `version.dll` | n/a |   |
| James Bond 007: Nightfire | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Jet Fighter IV | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput.dll` | n/a |   |
| Kohan: Ahriman's Gift | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/97120/Kohan_Ahrimans_Gift/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dsound.dll` | n/a |   |
| Kohan: Immortal Sovereigns | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/97110/Kohan_Immortal_Sovereigns/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dsound.dll` | n/a |   |
| Magic: The Gathering - Battlegrounds | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Marvel: Ultimate Alliance | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `winmm.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/mua/Marvel.Ultimate.Alliance.v1.0.NoCD.zip) to remove SafeDisc (V4) protection</sub> |
| Medal of Honor: Allied Assault | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/medal_of_honor_allied_assault_war_chest"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput.dll` | n/a |   |
| Midnight Club 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/12160/Midnight_Club_2/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| MotoGP 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| MotoGP 3 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/motogp3/MotoGP.3.v1.0.NoCD.zip) to remove SecuROM (V7) protection</sub> |
| MX vs. ATV Unleashed | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/mx_vs_atv_unleashed"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/359220/MX_vs_ATV_Unleashed/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dsound.dll` | n/a |   |
| Need for Speed: Hot Pursuit 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v242 update](https://taco.cab/files/games/nfshp2/NFSHP2_patch242.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/nfshp2/NFSHP2.v242.NoCD.zip) to remove SafeDisc (V2) protection</sub> |
| Nerf Arena Blast | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/12753460/NAB-OpenSpy.zip) instead<br><sup>[2]</sup> Latest [v1.2 update](https://taco.cab/files/games/nerf/nerfpatch1-2.zip) is recommended</sub> |
| No One Lives Forever | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `winmm.dll` | n/a |   |
| Painkiller | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/painkiller"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/39530/Painkiller_Black_Edition/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| ParaWorld | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `winmm.dll` | n/a | <sub><sup>[1]</sup> Latest [v1.01 update](https://taco.cab/files/games/paraworld/paraworld_patch_1_01.zip) is recommended</sub> |
| Postal 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/postal_2"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/223470/POSTAL_2/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/13580787/Postal2-OpenSpy.zip) instead</sub> |
| Rise of Nations | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `winmm.dll` | n/a | <sub><sup>[1]</sup> Requires latest [02.04.04.2903/03.02.12.0800 update](https://taco.cab/files/games/ron/ron_patch.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/ron/RoN.NoCD.zip) to remove SafeDisc (V2) protection</sub> |
| Rise of Nations: Rise of Legends | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a | <sub><sup>[1]</sup> Requires latest v2.5 update</sub> |
| Rome: Total War | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/rtw/RTW.NoCD.zip) to remove SafeDisc (V4) protection</sub> |
| Rush for Berlin | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/40320/Rush_for_Berlin_Gold/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dsound.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.25 update](https://taco.cab/files/games/rfb/international_rfb_patch_all.zip)&nbsp;&nbsp;<sup>**RETAIL**</sup><br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/rfb/RfB.Gold.v1.25.NoCD.zip) to remove StarForce (V3) protection&nbsp;&nbsp;<sup>**RETAIL**</sup></sub> |
| Sacrifice | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sacrifice"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/38440/Sacrifice/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput.dll` | n/a |   |
| Saints Row 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/saints_row_2"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/9480/Saints_Row_2/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| Serious Sam: The First Encounter | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/serious_sam_the_first_encounter"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Serious Sam: The Second Encounter | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/serious_sam_the_second_encounter"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a |   |
| Serious Sam 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a |   |
| Sniper Elite | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/sniper_elite_berlin_1945"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/3700/Sniper_Elite/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| Startopia | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/game/startopia"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/243040/Startopia/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dsound.dll` | n/a |   |
| Star Trek: Armada II | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/star_trek_armada_ii"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dsound.dll` | n/a | <sub><sup>[1]</sup> Latest [v1.1 update](http://armadafiles.com/files/armada-2/official-releases/patches/star-trek-armada-ii-patch-11/details) is recommended&nbsp;&nbsp;<sup>**RETAIL**</sup><br><sup>[2]</sup> Also works with free [Demo](http://armadafiles.com/files/armada-2/official-releases/demo/star-trek-armada-ii-demo/details)</sub> |
| Star Trek: Armada II Demo | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dsound.dll` | n/a | <sub><sup>[1]</sup> [Free download](http://armadafiles.com/files/armada-2/official-releases/demo/star-trek-armada-ii-demo/details)</sub> |
| Star Trek: Bridge Commander | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/star_trek_bridge_commander"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput.dll` | n/a |   |
| Star Trek: Legacy | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Latest [v1.2 update](https://taco.cab/files/games/stlegacy/STLegacyv1.2.zip) is recommended</sub> |
| Star Wars: Republic Commando | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/star_wars_republic_commando"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/6000/STAR_WARS_Republic_Commando/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `version.dll` | n/a |   |
| Street Racing Syndicate | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/street_racing_syndicate"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/292410/Street_Racing_Syndicate/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a |   |
| Terminator 3: War of the Machines | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.16 update](https://taco.cab/files/games/t3wotm/t3wotm_us_retail-116.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/t3wotm/T3.WOTM.NoCD.zip) to remove SecuROM (V5) protection</sub> |
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
| Unreal Tournament 2004 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://www.gog.com/en/game/unreal_tournament_2004_ece"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a>&nbsp;<a href="https://store.steampowered.com/app/13230/Unreal_Tournament_2004_Editors_Choice_Edition/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | n/a | n/a | <sub><sup>[1]</sup> No DLL, use [this configuration file](https://github.com/anzz1/openspy-client/files/14950937/UT2004-OpenSpy.zip) instead<br><sup>[2]</sup> Installing [ECE Bonus Pack](https://taco.cab/files/games/ut2004/ut2004-ECEBonusPack1-1.zip) + Latest [v3369 update](https://taco.cab/files/games/ut2004/ut2004winpatch3369.zip) is recommended&nbsp;&nbsp;<sup>**RETAIL**</sup></sub> |
| Unreal Tournament 3 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture>&nbsp;<a href="https://store.steampowered.com/app/13210/Unreal_Tournament_3/"><img src="./.github/img/steam.png" title="Steam" alt="(Steam)" /></a> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v2.1 update](https://taco.cab/files/games/ut3/UT3Patch5.zip)&nbsp;&nbsp;<sup>**RETAIL**</sup></sub> |
| Vietcong 2 | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a |   |
| Warhammer 40,000: Fire Warrior | <a href="https://www.gog.com/en/game/warhammer_40000_fire_warrior"><img src="./.github/img/gog.png" title="GOG" alt="(GOG)" /></a> | `dinput8.dll` | n/a |   |
| Worms 3D | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.073 update](https://taco.cab/files/games/w3d/Worms3DServicePatch2.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/w3d/W3D.Euro.v1.073.NoCD.zip) to remove SecuROM (V5) protection</sub> |
| Worms 4: Mayhem | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> Requires latest [v1.01 update](https://taco.cab/files/games/w4m/WormsMayhemPATCHv1.01.zip)<br><sup>[2]</sup> Requires [No-CD patch](https://taco.cab/files/games/w4m/W4M.Euro.v1.01.3013.NoDRM.zip) to remove StarForce (V3) protection</sub> |
| Worms 4: Mayhem Online Demo | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput8.dll` | n/a | <sub><sup>[1]</sup> [Free download](https://taco.cab/files/games/w4m/worms_4_multi_demo.zip)</sub> |
| X-Men Legends II | <picture><img src="./.github/img/disc.png" title="Retail" alt="(Retail)" /></picture> | `dinput.dll` | n/a | <sub><sup>[1]</sup> Requires [No-CD patch](https://taco.cab/files/games/xml2/X-Men.Legends.II.v1.0.NoCD.zip) to remove SafeDisc (V4) protection</sub> |
| [report supported game](https://github.com/anzz1/openspy-client/issues/new?assignees=&labels=working+game&projects=&template=report-working-game.yml&title=%5Bworking-game%5D+GAME+NAME) |

## Unsupported games list
| Game | Status |
| --- | --- |
| Aliens vs. Predator 2 | not working |
| Battlefield 2142 | not working |
| Codename Panzers: Phase One | not working |
| Crysis 2 | not working |
| Empires: Dawn of the Modern World | not working |
| Lord of the Rings: The Battle for Middle-earth II | FESL not implemented, see [issue #3](https://github.com/anzz1/openspy-client/issues/3) |
| Lord of the Rings: War of the Ring | crashes while retrieving profiles |
| Men of War: Assault Squad | coming soon&trade; |
| Soldier of Fortune 2: Double Helix | not working |
| Star Wars: Empire at War | not working |
| Test Drive Unlimited | not working |
| [report unsupported game](https://github.com/anzz1/openspy-client/issues/new?labels=game+request&template=request-for-game-support.yml&title=%5Bgame-request%5D+GAME+NAME) |

## Remarks
To uninstall, simply delete the renamed `openspy.dll` file from the game directory.

If a game is not listed, you can try renaming it as the different variations **openspy-client** currently supports: 
- `dinput.dll`
- `dinput8.dll`
- `dsound.dll`
- `version.dll`
- `winmm.dll`

Please report back with your findings to help us add to the [supported games list](#supported-games-list).

Generally, it does not matter how the **openspy-client** module is loaded into the game. This means that in addition to the DLL variations supported, you can also use any other method to load the module into the game.

For example, if you use an [ASI loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) to load mods like [Widescreen Fix](https://thirteenag.github.io/wfp) for your game, you can simply rename the OpenSpy module to `openspy.asi` and place it next to the `WideScreenFix.asi` and it will be loaded that way.


---

🌎 [Web](https://openspy.net/)

<img alt="Discord" src="https://user-images.githubusercontent.com/13628128/226210682-c9044ed1-e4d9-431c-b085-1d684a9f9942.png" height="20">&nbsp;[Discord](http://discord.gg/sMaWdbt)

This component is a part of the [OpenSpy](https://openspy.net/) project:

- [openspy-core](https://github.com/openspy/openspy-core)
- [openspy-web-backend](https://github.com/openspy/openspy-web-backend)
- [openspy-natneg-helper](https://github.com/openspy/natneg-helper)
- [openspy-discord-bot](https://github.com/openspy/openspy-discord-bot)
- openspy-client

