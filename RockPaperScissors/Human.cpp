#include "Human.h"
#include "Player.h"
#include <iostream>
#include <string>


Human::Human()
{
}

Human::Human(string nm) : name(nm), Player(3) 
{ 
}//sets base score to 3, initializtion list to assign name variable to string that user enters

Human::~Human()
{
}
