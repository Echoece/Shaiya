**original code** 

https://github.com/zidane168/Shaiya-Projects/tree/master/Fix%20Item%20mall%20SQL%202012

**known bugs**
* ps_game service doesn't start on the first try sometimes but starts on the second try

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

**instructions**
1. copy the dll, ini, and ps_game to your bin edit the ini username and password

**revisions**
* the code is smaller, more readable, and uses different source code for hooks
* added support for reading the account username and password from an ini file

**ep6 version**

https://github.com/426f776965/shaiya-solutions/tree/master/ep6


**contents**
* ps_game reported not to have random disconnects with one hook for ncash.dll
* the ini file that ncash.dll will parse to get the username and password
* ps_dbAgent for ep5 and usp_Save_User_BuyPointItems2 procedure that it needs
* linked servers query that needs to be edited to match your login credentials
* usp_Save_User_BuyPointItems2 that the ep5 ps_dbAgent requires

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


