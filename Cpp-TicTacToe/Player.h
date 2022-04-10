#pragma once

#include <string>
#include "Board.h"
using namespace std;
class Player
{
public:
	Player(string name);
	virtual void play(Board* board);
	string getSign();
	void setSing(string sign);
	string getName();
	void setName(string name);
private:
	string name;
	string sign;
};

