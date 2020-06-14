#include "pch.h"

#pragma warning( push )
//ignore the conversion of 'time_t' to 'unsigned int' warning
#pragma warning( disable : 4244 )
//returns a random integer stored in an array
int randomId() {
	srand(time(0)); //initialize the random seed
	//store the skill ids in an array of integers
	int i[10] = { 276, 277, 278, 279, 280, 281, 282, 283, 284, 285 };
	return i[rand() % 10]; //return a random id from the array
}
#pragma warning( pop )
// Author: Cups
// Use a skill for a player instance (player, id, level)
void __declspec(naked) castSkill() {
	__asm {
		push ebp // Save EBP
		mov ebp,esp // Move the current stack to EBP
		mov edx,[ebp+0x08] // Skill Level
		mov eax,[ebp+0x0C] // Skill ID
		mov edi,[ebp+0x10] // Player
		call GetSkillInfo //CGameData::GetSkillInfo
		// Result is now stored in EAX
		call UseItemSkill //CUser::UseItemSkill
		pop ebp // Restore EBP to it's previous value
		retn 0x0C // Restore the stack
	}
}
//asm code for hooking an exp gain address
void __declspec(naked) buffHook() {
	__asm {
		pushad //save all registers
		pushfd //save all flags
		call randomId //call the random skill id function
		//the skill id returned is in eax
		push esi //push the player register
		push eax //push the skill id
		push 0x1 //push the skill level
		call castSkill //call the skill casting function
		popfd //restore all flags
		popad //restore all registers
		mov edi,[esi+0x13C] //original code
		jmp buffReturn
	}
}
//the main function
void buffFunc() {
	Hook(0x46514C, 6, (DWORD)buffHook); //hooks the address
}
