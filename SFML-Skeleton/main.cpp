#include <Windows.h>

#include "Game.h"

#if _DEBUG
int main()
#else
INT WinMain(HINSTANCE,HINSTANCE,PSTR,INT)
#endif
{
	Game game;
	game.run();
	return 0;
}