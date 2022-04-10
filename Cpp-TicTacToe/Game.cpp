#include "Game.h"

Game::Game()
{
	board = new Board();
}


void Game::enterGameMode()
{
	
	/*std::cout << "Enter game mode: \n1: play player vs player.\n2: player vs random bot.\n3: player vs AI." << std::endl;
	std::cout << "-> ";
	string commend;
	std::cin >> commend;
	if (!board->isd(commend)) {
		enterGameMode();
	}

	int mode = std::stoi(commend);
	if (PlayerVsPlayer == mode) {
		enterPlayersNames();
	}
	else if (PlayerVsRandom == mode) {
		enterPlayerName();
	}
	else if (PlayerVsAI == mode) {

	}
	else {
		enterGameMode();
	}*/

	enterPlayersNames();
	std::cout << "-> ";
}

void Game::enterPlayersNames()
{
	string commend;
	cout << "Enter player 1 name: ";
	std::cin >> commend;
	player1 = new Player(commend);
	player1->setSing("x");

	cout << "Enter player 2 name: ";
	std::cin >> commend;
	player2 = new Player(commend);
	player2->setSing("o");
}

void Game::freePlayerMemory()
{
	delete player1;
	delete player2;
	delete board;
	//delete currentPlayer; //crushing the program dont know whay...
}

void Game::printGame()
{
	board->drawBoard();
}

void Game::startGame()
{
	
	board->initializeBoard();
	string playerName;
	printGame();
	while (true)
	{
		board->setPlayerSign(player1->getSign());
		currentPlayer = player1;
		player1->play(board);
		printGame();
		playerName = player1->getName();
		if (checkForWinner(playerName)) {
			break;
		}

		board->setPlayerSign(player2->getSign());
		currentPlayer = player2;
		player2->play(board);
		printGame();
		playerName = player2->getName();
		if (checkForWinner(playerName)) {
			break;
		}
	}
}

bool Game::checkForWinner(std::string& name)
{

	for (int i = 0; i < 3; i++)
	{
		if (board->board[i][0] == board->board[i][1] && board->board[i][1] == board->board[i][2] && board->board[i][2] != "_") {
			cout << name << " Won!" << endl;
			return true;
		}

		if (board->board[0][i] == board->board[1][i] && board->board[1][i] == board->board[2][i] && board->board[2][i] != "_") {
			cout << name << " Won!" << endl;
			return true;
		}
	}

	if (board->board[0][0] == board->board[1][1] && board->board[1][1] == board->board[2][2] && board->board[2][2] != "_") {
		cout << name << " Won!" << endl;
		return true;
	}

	if (board->board[2][0] == board->board[1][1] && board->board[1][1] == board->board[0][2] && board->board[0][2] != "_") {
		cout << name << " Won!" << endl;
		return true;
	}
	
	return false;
}

void Game::enterPlayerName()
{
	string commend;
	cout << "Enter your name: ";
	cin >> commend;

}

