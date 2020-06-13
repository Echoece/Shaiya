**contents**
* ct file that will prevent all notice functions from injecting the database
* ps_game that runs without the gameguard dlls and cauth config files (you can remove them from the bin)
* ps_dbAgent with packet based dupe fix with edited [dbo].[usp_Save_Char_Info_E] (credit: lilprohacker)
* game.exe with antifreeze, speed recreation, speed enchantment, and exploit solutions
* apostrophe removal query for mobs, skills, and items that should be executed after updating the tables
* various cheat engine files that either solve bugs and exploits or add simple modifications to the game

**notes**

*when the repository is linked with Shaiya Studio it will save a decrypted duplicate of the NpcQuest.SData from the client to the server directory. npc and quest names will contain apostrophes. ep5 server files will escape the apostrophes with underscores.*

**solution**
1. install Python26 and ZeroSignal's scripts and put the NpcQuest.SData in C:/Python26/Input/SData
2. open a command prompt and navigate to the Python26 directory by executing cd C:/Python26
3. next, execute NpcQuest_csv and leave the command prompt window open
4. go to the C:/Python26/Output/SData directory and open all of the csv files at once with Notepad++
5. press Ctrl+H and put an apostrophe in the 'Find what:' tab and an underscore in the 'Replace with:' tab
6. choose the 'Replace All in All Opened Documents' option and then press Ctrl+Shift+S to save them all
7. then, execute NpcQuest_sdata in the command prompt and everything should compile without errors
8. go to the C:/Python26/Output/SData folder and copy the new NpcQuest.SData to the Bin/Data directory

