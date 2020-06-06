**original code** 

https://github.com/zidane168/Shaiya-Projects/tree/master/Fix%20Item%20mall%20SQL%202012

**compatibility**

* SQL Server 2019
* SQL Server 2017
* SQL Server 2016
* SQL Server 2014
* SQL Server 2012

**additional dependencies**
* legacy_stdio_definitions.lib;

**disable specific warnings**
* 4996;4838;

**building**
* copy msado15.dll and msado15.tlh into the Debug folder

**ep6 version**

https://github.com/426f776965/shaiya-solutions/tree/master/ep6

**instructions**
1. add the ps_game, msado15.dll, ncash.dll, and ncash.ini to your bin folder
2. add your sql account username and password to the ini file
3. execute usp_Save_User_BuyPointItems2 (credit: shen1l)

**contents**
* ps_game reported not to have random disconnects with one hook for ncash.dll
* ps_dbAgent for ep5 and usp_Save_User_BuyPointItems2 procedure that it calls

**notes**
* the jump to hook the dll is at address 005312FB and overwrites the following code

```asm
pop esi
pop edi
pop ebx
leave
retn
```

* the overwritten code is added to the end of the hook that begins at address 00553F97
* the dll name is a binary edit that begins at address 00553FAA and is pushed before calling LoadLibraryA

```asm
pushad
push 00553FAA //ncash.dll
call dword ptr ds:[005541C4] //LoadLibraryA
popad
pop esi
pop edi
pop ebx
leave
retn
```

* you may hook as many dlls as you wish by following this example

```asm
pushad
push 00553FAA //ncash.dll
call dword ptr ds:[005541C4] //LoadLibraryA
push <dllnameaddress> //another.dll
call dword ptr ds:[005541C4] //LoadLibraryA
popad
pop esi
pop edi
pop ebx
leave
retn
```


