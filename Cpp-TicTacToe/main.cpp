#include <iostream>
#include <string>
#include "Game.h";

using namespace std;

int main() {
	
	Game *game = new Game();
	string commend;
	while (true)
	{
		game->enterGameMode();
		game->startGame();
		game->freePlayerMemory();
		cin >> commend;
		if (commend == "exit") { break; }
	}
	
	delete game;

	cin.get();
	return 0;
}
