#pragma once
#include "Drawing.h"
#include <vector>
using namespace std;
class Drawobject {
private:
//private colour member
	COLOUR clr ;
protected:
	vector<COORD>listCOORDS;
public:
	COLOUR getColour() {return clr;}//getter method for colour-used by subclasses to pass colour to draw function
	
	Drawobject() {				//base constructor if nothing is passed to it

	}
	virtual ~Drawobject() {//needed to be able to properly decrement shapecounter

	}
	
		//virtual draw method- returns void accepts reference to a draw object
	virtual void draw(Drawing &obj) = 0;

	Drawobject(COLOUR colour ) {clr = colour;}
};


class Point: public Drawobject
{
private:
	
public:
	Point(COLOUR colour, COORD crd):Drawobject(colour)//intiialization list
	{
		listCOORDS.push_back(crd);//syntax to add an element to a vector
	}


	void draw(Drawing &obj){
		obj.setPixel(listCOORDS.at(0), getColour());
	}
		//This method will set the pixel at first COORD to the COLOUR using the baseclass getter
};

class Line : public Drawobject
{
public:
	Line(COLOUR colour, COORD startCrd, COORD endCrd) : Drawobject(colour) 		
	{
		listCOORDS.push_back(startCrd);//at first location is the startcoord
		listCOORDS.push_back(endCrd);//at second location is endcoord
	}

	
	void draw(Drawing &obj)
	{
		obj.drawLine(listCOORDS.at(0), listCOORDS.at(1), getColour());//the line function reqquires the starcord, endcoord and the colour
	}
};

class Shape: public Drawobject {
private:
	static int counter;//needed to keep track of the shapes
public:
	//conrtuctor which accepts colour for line of the shape, increments counter
	Shape(COLOUR clr) : Drawobject(clr) {
		counter++;
	}
									//sets the colour attribute of the abstract class to the inputted colour from shape object creationcounter++;
	
	void AddCoord(COORD crd)
	{
		listCOORDS.push_back(crd);
		//adds to baseclass vector<coord>
	}
	
	~Shape(){counter--;}//destructor decrements the amount of shape objects because they are being deleted
	
	void draw(Drawing &obj)//drawing fcn for shape object
	{
		
		
		for (int i = 0; i < listCOORDS.size(); i++)
		
		{
			
			
			if (i == listCOORDS.size() - 1)
			
			
			{
				obj.drawLine(listCOORDS.at(i), listCOORDS.at(0), getColour());//calls draw line fcn to draw from last coord to first coord
				
				
				
				break;
			
			
			
			}

			
			
			
			
			
			obj.drawLine(listCOORDS.at(i), listCOORDS.at(i + 1), getColour());//draws from one coord to the next
		}
	}
	
	
	static int GetShapes() { return counter; }//public static method which gets number of shapes in existence-called from main
};
int Shape ::counter = 0; // this is so it can be accessed without instantiating a shape object
//was told to declare outside class