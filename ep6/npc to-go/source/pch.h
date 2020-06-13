#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//the main function
void npcFunc();
//definition for the hook function
void* Hook(DWORD address, int length, DWORD target);
//store the npc window ids in an array of integers
int npcArray[6] = { 102, 121, 103, 110, 111, 101 };
DWORD npcCall = 0x51C070;
DWORD npcReturn = 0x522165;

#endif
