#include "pch.h"
#include "database.h"

CDataBase g_DBobj;
//defines return addresses and initializes variables
DWORD dwReturnAddr1 = 0x47D157;
DWORD dwGetPoint = 0;
DWORD dwReturnAddr2 = 0x488025;
DWORD dwFalseAddr = 0x488027;
DWORD dwUsePoint = 0;
DWORD dwReturnAddr3 = 0x488D5F;
DWORD dwSetPoint = 0;
//defines the asm hook for getting the user's points
__declspec(naked) void ShopHook1()
{
	_asm
	{
		pushad //save the data stored in all 32 bit registers
		lea eax,[ecx+0x5AC0] //load the user's points into eax
		push eax //save the user's point data in eax              
		mov eax,[ecx+0x582C] //move the useruid into eax
		push eax //save the useruid data in eax              
		call dwGetPoint //query sql to get the user's points
		add esp,0x8 //add 8 bytes to the stack
		popad //restore previous data to all 32 bit registers
		//orginal code
		xor ebp,ebp
		cmp byte ptr[esi+0xA],0x0
		jmp dwReturnAddr1
	}
}
//defines the asm hook for spending points
__declspec(naked) void ShopHook2()
{
	_asm
	{
		pushad //save the data stored in all 32 bit registers
		push ecx //save ecx              
		mov ecx,[edi+0x582C] //move the useruid into ecx
		push ecx //save the useruid data in ecx              
		call dwUsePoint //call the boolean function to check if the user has enough points
		//the true or false return value will be in eax
		add esp,0x8 //add 8 bytes to the stack
		cmp al,0x1 //check if the result in eax is true by checking the lowest byte of eax
		popad //restore previous data to all 32 bit registers
		jne _false //disallow buying the item if the boolean function returned false
		//orginal code
		cmp ecx,dword ptr[edi+0x5AC0]
		jmp dwReturnAddr2
		_false:
		jmp dwFalseAddr
	}
}
//defines the asm hook for updating the user's points
__declspec(naked) void ShopHook3()
{
	_asm
	{
		pushad //save the data stored in all 32 bit registers
		mov eax,dword ptr[edi+0x582C] //move the useruid into eax
		push eax //save the useruid data in eax                       
		call dwSetPoint //call the function that updates the points
		add esp,0x4 //add 4 bytes to the stack
		popad //restore previous data to all 32 bit registers
		jmp dwReturnAddr3
	}
}
//queries sql to get the user's points
void GetPoint(DWORD dwUid, PVOID pAddr)
{
	CString szSql;
	szSql.Format(L"select point from ps_userdata.dbo.users_master where useruid=%d", dwUid);
	*((DWORD*)pAddr) = _tcstoul(g_DBobj.ExeSqlByCommand(szSql, L"point"), 0, 10);
}
//queries sql to check if the user has enough points to buy an item
BOOL UsePoint(DWORD dwUid, DWORD dwCost)
{
	PDWORD pPoint; //initialize a variable for the user's points
	_asm
	{
		lea eax,[edi+0x5AC0] //load the user's points into eax
		mov pPoint,eax //move eax into the variable
	}
	CString szSql;
	szSql.Format(L"select point from ps_userdata.dbo.users_master where useruid=%d", dwUid);
	DWORD dwPoint = _tcstoul(g_DBobj.ExeSqlByCommand(szSql, L"point"), 0, 10);
	*pPoint = dwPoint;
	//checks if the user has enough points to buy the item
	if (dwCost > dwPoint) return FALSE; //returns 0 if the cost is greater than the points
	//else, it returns true and stores a value of 1 in eax
	return TRUE;
}
//updates the user's points after buying an item
DWORD __stdcall UpdatePoint(_In_ LPVOID lpParameter)
{
	DWORD dwUid = (DWORD)lpParameter;
	char buff[90] = { 0 };
	ZeroMemory(buff, 90);

	*(PDWORD(&buff[4])) = DWORD(&buff[12]);
	*(PDWORD(&buff[12])) = 0x1B02000B;
	*(PDWORD(&buff[16])) = dwUid;

	DWORD dwTempCall = 0x406960;
	DWORD dwBuffAddr = (DWORD)buff;

	_asm
	{
		push dwBuffAddr
		mov ecx,0x0
		call dwTempCall
	}
	return 0;
}
//creates a thread using the function that update points
void SetPoint(DWORD dwUid)
{
	CreateThread(NULL, 0, UpdatePoint, (PVOID)dwUid, NULL, 0);
}
//defines the function for hooking addresses
void* Hook(DWORD address, int length, DWORD target);
//creates a thread to check the database connection
DWORD __stdcall ShopConnect(_In_ LPVOID lpParameter)
{
	//checks the database connection
	if (!g_DBobj.LinkDataBase()) return 0;
	//writes functions in memory
	dwGetPoint = (DWORD)GetPoint;
	dwUsePoint = (DWORD)UsePoint;
	dwSetPoint = (DWORD)SetPoint;
	//defines addresses for asm hooks
	Hook(0x47D151, 6, (DWORD)ShopHook1);
	Hook(0x48801F, 6, (DWORD)ShopHook2);
	Hook(0x48876F, 5, (DWORD)ShopHook3);

	return 0;
}
