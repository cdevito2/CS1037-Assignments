#include "Guess.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Guess::Guess()
{
	srand(time(NULL));//required code to get a truly random number
	int randGuess = rand() % 3;//random num btwn 0-3
	if (randGuess == 0)
	{
		guess = 'R';
	}
	else if (randGuess == 1)
	{
		guess = 'P';
	}

	else
	{
		guess = 'S';
	}


}


Guess::Guess(char g)
{
	if (g == 'R' || g == 'r')
	{
		guess = 'R';//if user enters upper or lowercase it gets assigned uppercase
	}

	else if (g == 'P' || g == 'p')
	{
		guess = 'P';
	}
	
	else
	{
		guess = 'S';
	}

}

Guess::Guess(int g)
{
	if (g == 0)
	{
		guess = 'R';
	}
	else if (g == 1)
	{
		guess = 'P';
	}
	else
	{
		guess = 'S';
	}
}


int Guess::compare(const Guess &other) const {

	if (guess == other.guess)
	{
		return 0;//if char guesses are equal a zero is returned
	}
	else if ((guess == 'R' && other.guess == 'S') || (guess == 'P'&&other.guess == 'R') || (guess == 'S'&&other.guess == 'P'))
	{
		return -1;//all scenarios where the guess on the left hand side wins returns -1
	}
	else if ((guess == 'R' && other.guess == 'P') || (guess == 'S'&&other.guess == 'R') || (guess == 'P'&&other.guess == 'S'))
	{
		return 1;//all scenatios where the guess on the right hand side wins returns 1
	}
	else{}
}








Guess::~Guess()
{
}
