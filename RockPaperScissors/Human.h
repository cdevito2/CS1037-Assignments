#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "Guess.h"
using namespace std;
class Human : public Player//means human is sublass of player
{
public:
	Human();
	Guess getGuess() const { 
		char guess;
		cout << "Please enter (R,P,S): "; cin >> guess;
		return guess;
	}
	
	Human(string nm);//constuctor which takes a string as parameter
	
	inline string const getName() {//inline function which returns name to main
		return name;
	}


	~Human();
private:
	string name;
};

