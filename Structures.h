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
	char _0x0000[24];
	__int8 m_bIsVisible; //0x0018 
	char _0x0019[2195];
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
	__int8 m_bHasMaxAmmo; //0x090B 
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
	BYTE* data; //0x0024 
	char _0x0028[8];
	HitBox* hitBox; //0x0030 
	char _0x0034[24];
	MiniGame_3* miniGame; //0x004C 

};//Size=0x0050


class TMiniGameManager
{
public:
	char _0x0000[104];
	__int32 m_iCurrentMiniGame; //0x0068 
	char _0x006C[4];
	void* miniGame_2; //0x0070 
	void* miniGame_1; //0x0074 
	MiniGame_3* miniGame_3; //0x0078 
	void* miniGame_4; //0x007C 
	void* miniGame_6; //0x0080 
	void* miniGame_5; //0x0084 

};//Size=0x0088