#pragma once
#include <iostream>
using namespace std;
class Guess
{
public:
	Guess();
	~Guess();

	inline char getGuess()
	{
		return guess;
	}
	
	int compare (const Guess &other) const;
	Guess(char g);
	Guess(int g);

private:
	char guess;


};

