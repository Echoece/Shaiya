#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <time.h>
//the main function
void buffFunc();
//definition for the hook function
void* Hook(DWORD address, int length, DWORD target);
//define ps_game call, return, and function addresses
DWORD buffReturn = 0x465152;
DWORD GetSkillInfo = 0x41BB30;
DWORD UseItemSkill = 0x4725B0;

#endif
