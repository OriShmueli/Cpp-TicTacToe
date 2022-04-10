#include "Bot.h"
#include <random>

void Bot::play(Board* board)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<int> distr(1, 9);
	string input = std::to_string(distr(eng));
	if (board->checkInput(input)) {
	}
	else {
		play(board);
	}
}
