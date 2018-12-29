#include<iostream>
#include<string>
#include "Computer.h"
#include "Guess.h"
#include "Human.h"
#include "Player.h"
using namespace std;


int main(int argc, char *argv[])
{
	cout << "welcome " << endl;
	string nm;
	cout << "Player Name: "; 
	cin >> nm;//user enters name
	cout << endl;
	
	
	//do while loop for score here
	Human human(nm);//creating a human object with the user entererd name
	Computer comp;//computer object, doesnt take parameters
	
	
	
	while (human.getScore()!=0 && comp.getScore()!=0)//this loop runs aslong as either of the 2 scores is not equal to zero
	{ 
		
		
		
		Guess HumanGuess(human.getGuess());//guess object which takes the user entered char/int as its guess
		Guess CompGuess(comp.getGuess());//guess object which takes the random computer guess as its parameter

		cout << "Human: " << HumanGuess.getGuess() << " Computer: " << CompGuess.getGuess() << endl;//outputs guesses
		//must compare here
		int compareResult = HumanGuess.compare(CompGuess);//calls compare function and takes the 2 guesses

		if (compareResult == -1)
		{
			human.Player::operator--();//calls the overriding operator function to enable us to decrement score by 1
		}

		else if (compareResult == 1)
		{
			comp.Player::operator--();//if it returns 1, that means computer won the round so we decrement its score by 1
		}

		
		
		cout << "Human: " << human.getScore() << " Computer: " << comp.getScore() << endl;

	
	
	}
	
	if (human.getScore() == 0)
	{
		cout << human.getName()<< " WON!" << endl;//if the human won their name is outputted
	}
	
	else if (comp.getScore() == 0)
	{
		cout <<"COMP WON!" << endl;//if computer wins this is outputted
	}
	char c;
	
	cin >> c;
	cout << "hello" << endl;

}