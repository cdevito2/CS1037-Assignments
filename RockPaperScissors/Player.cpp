#include "Player.h"
#include <iostream>



Player::Player()
{
}



Player::Player(int s)
{
	score = s;//sets the score to the parameter,used in other files in initialization list
}
Player::~Player()
{
}

Player &Player::operator--() {//this allows us to decrement the player score by 1
	score--;
	Player player(score);
	return player;

}

