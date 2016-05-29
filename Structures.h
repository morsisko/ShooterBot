#pragma once

#pragma once

//Generated using ReClass 2013 Mod by CypherPresents

class MiniGame_3;
class TimingShotGame;
class MiniGameManagerList;
class HitBox;

class MiniGame_3
{
public:
	char _0x0000[2220];
	TimingShotGame* chickenRightPaddle; //0x08AC 
	TimingShotGame* batRightPaddle; //0x08B0 
	TimingShotGame* roosterRightPaddle; //0x08B4 
	TimingShotGame* chickenLeftPaddle; //0x08B8 
	TimingShotGame* batLeftPaddle; //0x08BC 
	TimingShotGame* roosterLeftPaddle; //0x08C0 
	__int8 m_bLifes; //0x08C4 
	char _0x08C5[3];
	__int32 m_iPoints; //0x08C8 
	char _0x08CC[60];
	__int8 m_bAmmo; //0x0908 
	char _0x0909[2];
	bool m_bHasMaxAmmo; //0x090B 
	char _0x090C[52];

};//Size=0x0940

class HitBox
{
public:
	__int32 first; //0x0000 
	__int32 second; //0x0004 

};//Size=0x0008

class TimingShotGame
{
public:
	char _0x0000[36];
	void* data; //0x0024 
	char _0x0028[8];
	HitBox* hitBox; //0x0030 
	char _0x0034[24];
	MiniGame_3* miniGame; //0x004C 

};//Size=0x0050

class MiniGameManagerList
{
private:
	void* basePointer; //0x0000
	MiniGame_3** pointerToArray; //0x0004
	int currentSize; //0x0008
	int paddle[2];

public:

	MiniGame_3* getMiniGame()
	{
		if (currentSize <= 6)
			return nullptr;
		else
			return pointerToArray[6];
	}

};//Size=0x0014

class TMiniGameManager
{
public:
	char _0x0000[32];
	MiniGameManagerList* miniGameManagerList; //0x0020 

};//Size=0x0024