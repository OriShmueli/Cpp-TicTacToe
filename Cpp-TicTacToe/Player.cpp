#include "Player.h"

Player::Player(string name)
{
	this->name = name;
}

void Player::play(Board* board)
{
	string commend;
	cout << "Make your move: " << name;
	cout << "-> ";
	cin >> commend;
	if (board->checkInput(commend)) {
	}
	else {
		play(board);
	}
}


string Player::getName()
{
	return name;
}

void Player::setName(string name)
{
	this->name = name;
}

string Player::getSign()
{
	return sign;
}

void Player::setSing(string sign)
{
	this->sign = sign;
}
