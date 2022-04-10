#pragma once
#include "Player.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

class Bot : public Player
{
public:
	void play(Board* board) override;
};

