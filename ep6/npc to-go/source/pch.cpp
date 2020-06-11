#include "pch.h"

//asm code for overwriting CustomGame.dll npc to-go
void __declspec(naked) npcHook1() {
	__asm {
		//likely a more elegant way, but this works
		cmp dword ptr[esp],dword ptr[0x439740]
		je _one
		cmp dword ptr[esp],dword ptr[0x43B41B] 
		je _two
		jmp _exit
		_one:
		cmp dword ptr[esp+0xA4],dword ptr[0x41833F]
		jne _exit
		lea eax,[ptrValue1]
		movzx eax,byte ptr[eax]
		cmp eax,0x1
		je _exit
		mov eax,0x0000000
		jmp npcReturn1
		_two:
		lea eax,[ptrValue2]
		movzx eax,byte ptr[eax]
		cmp eax,0x1
		je _exit
		mov eax,0x0000000
		jmp npcReturn1
		_exit:
		mov eax,[ecx+0x12C] //orginal code
		jmp npcReturn1
	}
}
//asm code for overwriting CustomGame.dll npc to-go
void __declspec(naked) npcHook2() {
	__asm {
		cmp edi,0x5
		jg _exit
		push ecx
		lea ecx,[npcArray]
		mov ecx,[ecx+edi*0x4]
		//dword ptr ds:[0x9144E4] compiles as a game.exe address
		//otherwise, it'll get compiled as an address in the dll
		mov dword ptr ds:[0x9144E4],ecx
		pop ecx
		_exit:
		call npcCall //original code
		jmp npcReturn2
	}
}
//the main function
void npcHook() {
	Hook(0x587124, 6, (DWORD)npcHook1); //hooks the 1st npc to-go address
	Hook(0x522160, 5, (DWORD)npcHook2); //hooks the 2nd npc to-go address
}
