**contents**
* ps_game that runs without the gameguard dlls and cauth config files (you can remove them from the bin)
* ct files that help solve issues with rune skill cutting by delaying the use of runes after using skills
* ct file that will prevent rangers and assassins from adding or removing gear in stealth mode
* ct file that will remove the code that keeps guards from detecting a character in stealth mode
* ct files that disable the /iclear, /eclear, and /warning commands
* ct file that blocks defenders and guardians from using skill reset stones and blocks target res runes in grb
* ps_dbAgent with packet based dupe fix with edited [dbo].[usp_Save_Char_Info_E] (credit: lilprohacker)
* game.exe with antifreeze, speed recreation, speed enchantment, and exploit solutions
* apostrophe removal query for mobs, skills, and items that should be executed after updating the tables

**notes**
* npc names and quest names will still cause insert errors if the server NpcQuest.SData has apostrophes

1. install Python26 and ZeroSignal's scripts and put the NpcQuest.SData in C:/Python26/Input/SData
2. open a command prompt and navigate to the Python26 directory by executing cd C:/Python26
3. next, execute NpcQuest_csv and leave the command prompt window open
4. go to the Output/SData directory and open all of the csv files at the same time with Notepad++
5. press Crtl+H and put an apostrophe in the 'Find what:' tab and an underscore in the 'Replace with:' tab
6. choose the 'Replace All in All Opened Documents' option and then press Crtl+Shift+S to save them all
7. then, execute NpcQuest_sdata in the command prompt and everything should compile without errors
8. go to the Output/SData folder and copy the new NpcQuest.SData to the Bin/Data directory

