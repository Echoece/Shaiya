#pragma once

#define WIN32_LEAN_AND_MEAN

#include <sdkddkver.h>
#include <windows.h>
#include <atlstr.h>
#include <stdafx.h>
#include <comdef.h>
#include <vector>

//defines the function for hooking addresses
void* Hook(DWORD address, int length, DWORD target);

DWORD __stdcall ShopConnect(_In_ LPVOID lpParameter);
DWORD __stdcall UpdatePoint(_In_ LPVOID lpParameter);
