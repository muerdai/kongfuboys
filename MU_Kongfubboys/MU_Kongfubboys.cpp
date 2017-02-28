// MU_Kongfubboys.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GameManager.h"
int _tmain(int argc, _TCHAR* argv[])
{
	CGameManager game;
	game.InitGame();
	game.Run();
	return 0;
}