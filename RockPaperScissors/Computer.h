#pragma once
#include <iostream>
#include "Guess.h"
#include "Player.h"
#include "Human.h"
using namespace std;

class Computer: public Player//computer is subclass of player
{
public:
	Computer() : Player(5) {};
	//initialization list sets the initial computer score to 5
			Guess getGuess() const 	{		return Guess();	}	//this creates a guess object which contains a randomized guess for the computer

	~Computer();
};

