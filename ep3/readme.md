**contents**
* sql query that will solve the nostrum hack by making nostrum skills learned above the maximum server level
* ct files that help solve issues with rune skill cutting, the skill cooldown exploit, and the stealth exploit
* ct file that will allow rangers and sins to use skills from stealth like they are able to in newer episodes
* ct file that corrects the bug of prior ranking battle points stacking with the current ranking battle points
* game.exe with antifreeze and exploit solutions

**server**
* complete ep3 server files for client version 40 that are vastly improved but not flawless (thanks, ZeroSignal)
* ps_game that runs without the gameguard dlls and cauth config files
* ps_db_Agent that has been edited to match lilprohacker's packet-based dupe solution (needs testing)
* ps_login is the same one available in the parent directory

**notes**
* execute remove apostrophes, nostrum hack solution, and no enchant or oj after mass skill and item updates
* the ep3 ps_game expects to read 3 drops per mob from the mobitems table and cannot handle more
* all ep3 client sdata files must be decrypted
* npc names and quest names will still cause insert errors if the server NpcQuest.SData has apostrophes

**solution**
1. install Python26 and ZeroSignal's scripts and put the NpcQuest.SData in C:/Python26/Input/SData
2. open a command prompt and navigate to the Python26 directory by executing cd C:/Python26
3. next, execute NpcQuest_csv and leave the command prompt window open
4. go to the Output/SData directory and open all of the csv files at the same time with Notepad++
5. press Crtl+H and put an apostrophe in the 'Find what:' tab and an underscore in the 'Replace with:' tab
6. choose the 'Replace All in All Opened Documents' option and then press Crtl+Shift+S to save them all
7. then, execute NpcQuest_sdata in the command prompt and everything should compile without errors
8. go to the Output/SData folder and copy the new NpcQuest.SData to the Bin/Data directory

*when the repository is linked with Shaiya Studio it will save a decrypted duplicate of the NpcQuest.SData from the client to the server directory. the author claims this behavior is non-existent. ep5 server files will escape the apostrophes.*
