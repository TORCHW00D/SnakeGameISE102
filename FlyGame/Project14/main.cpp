#include <iostream>
#include "FlyGame.h"

using namespace std;

int main()
{
	FlyGame game;
	game.ConstructConsole(30, 30, 24, 24);
	game.Start();

	return 0;
}
