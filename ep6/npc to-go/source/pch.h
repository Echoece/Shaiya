#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//the main function
void npcHook();
//definition for the hook function
void* Hook(DWORD address, int length, DWORD target);
int ptrValue1 = 1;
int ptrValue2 = 257;
DWORD npcReturn1 = 0x58712A;
//store the npc window ids in an array of 6 integers
int npcArray[6] = { 102, 121, 103, 110, 111, 101 };
DWORD npcCall = 0x51C070;
DWORD npcReturn2 = 0x522165;

#endif
