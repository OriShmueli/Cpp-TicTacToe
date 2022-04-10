#pragma once

#include "Player.h"
#include <iostream>

class Game
{
public:
	Game();
	void enterGameMode();
	void enterPlayersNames();
	void freePlayerMemory();
	void printGame();
	void startGame();
	bool checkForWinner(std::string& name);
	void enterPlayerName();
private:
	enum GameMode
	{
		PlayerVsPlayer= 1,
		PlayerVsRandom,
		PlayerVsAI
	};
	bool isGameOver = true;
	Player* player1;
	Player* player2;
	Board* board;
	Player* currentPlayer;
};