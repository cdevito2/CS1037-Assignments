#pragma once
#include <iostream>
#include "Guess.h"

class Player
{
private:
	int score;
public:
	Player();
	~Player();
	Player(int score);
	Player& operator--();	inline int const getScore() {		return score;	}};

