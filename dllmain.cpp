// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "Structures.h"
#include "PatternScanner.h"

#define KEY_DOWN 0x100
#define KEY_UP 0x101
#define VK_LEFT 0x25
#define VK_RIGHT 0x27


DWORD WINAPI DLLStart(LPVOID param)
{
	//Get pointer that points to TMiniGameManager pointer
	TMiniGameManager* manager = **(TMiniGameManager***)(FindPattern((BYTE*)0x500000,
		0x200000,
		(BYTE*)("\xA1\x00\x00\x00\x00\x8B\x08\xFF\x51\x44\xA1\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xD2"), "x????xxxxxx????x????xx") + 1);

	MiniGame_3* game = manager->miniGameManagerList->getMiniGame();

	//Check if the pointer to MiniGame_1 is correct
	if (IsBadReadPtr(game, sizeof(MiniGame_3)))
		return -1;

	//Get the paddles data
	void* leftChickenPaddleData = game->chickenLeftPaddle->data;
	void* rightChickenPaddleData = game->chickenRightPaddle->data;

	void* leftBatPaddleData = game->batLeftPaddle->data;
	void* rightBatPaddleData = game->batRightPaddle->data;

	void* leftRoosterPaddleData = game->roosterLeftPaddle->data;
	void* rightRoosterPaddleData = game->roosterRightPaddle->data;

	int iterateTo = 458 - game->chickenLeftPaddle->hitBox->first;

	//Find hwnd of NosTale window
	HWND hwnd = FindWindowA("TNosTaleMainF", "NosTale");


	while (true)
	{
			game->m_bHasMaxAmmo = true;
			for (int i = 458; i != iterateTo; i--)
			{
				if (*(BYTE*)((DWORD)leftRoosterPaddleData + (DWORD)i) > 0)
				{
					PostMessage(hwnd, KEY_DOWN, VK_LEFT, 0);
					PostMessage(hwnd, KEY_UP, VK_LEFT, 0);
					Sleep(2);
					break;
				}

				if (*(BYTE*)((DWORD)leftBatPaddleData + (DWORD)i) > 0)
				{
					PostMessage(hwnd, KEY_DOWN, VK_LEFT, 0);
					PostMessage(hwnd, KEY_UP, VK_LEFT, 0);
					Sleep(2);
					break;
				}

				if (*(BYTE*)((DWORD)leftChickenPaddleData + (DWORD)i) > 0)
				{
					PostMessage(hwnd, KEY_DOWN, VK_LEFT, 0);
					PostMessage(hwnd, KEY_UP, VK_LEFT, 0);
					Sleep(2);
					break;
				}

				if (*(BYTE*)((DWORD)rightRoosterPaddleData + (DWORD)i) > 0)
				{
					PostMessage(hwnd, KEY_DOWN, VK_RIGHT, 0);
					PostMessage(hwnd, KEY_UP, VK_RIGHT, 0);
					Sleep(2);
					break;
				}

				if (*(BYTE*)((DWORD)rightBatPaddleData + (DWORD)i) > 0)
				{
					PostMessage(hwnd, KEY_DOWN, VK_RIGHT, 0);
					PostMessage(hwnd, KEY_UP, VK_RIGHT, 0);
					Sleep(2);
					break;
				}

				if (*(BYTE*)((DWORD)rightChickenPaddleData + (DWORD)i) > 0)
				{
					PostMessage(hwnd, KEY_DOWN, VK_RIGHT, 0);
					PostMessage(hwnd, KEY_UP, VK_RIGHT, 0);
					Sleep(2);
					break;
				}


			}

		Sleep(1);
	}


	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, DLLStart, 0, 0, 0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
