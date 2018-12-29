#include <iostream>
#include "Drawing.h"
#include "Drawable.h"
#include <forward_list>
#include <string>
using namespace std;



int main(int argc, char *argv[])
{
	
	forward_list<Drawobject *>list;
	int nextLetter = 0;
	string BMfileNM;
	int w;
	int h;
	COLOUR colourBcrnd;
	
	
	h = atoi(argv[4]);//this and line below set the grey background dimensions
	w = atoi(argv[3]);


	for (int i = 0; i < 3; i++)
	{
		colourBcrnd.rgb[i] = atoi(argv[i + 5]);//these set the colour for the background to be grey
	}

	Drawing drawing(w, h, colourBcrnd); //step one is to create drawing object

	for (int x = 8; x < argc; x = x + nextLetter)//starts at 8 because the first 7 args correspond to the file path, name, background etc
	{												//the first letter occurs at argv[8] also
		if (*argv[x] == 'L')//checks the command line arguments to see if the letter L occurs
		{

			COLOUR linecolour;
			COORD linecoordStart;
			COORD linecoordEnd;
			
			linecolour.rgb[0] = atoi(argv[x + 1]);//the first 3 args after L are the 3 rgb vals for colour
			linecolour.rgb[1] = atoi(argv[x + 2]);//i tried to use a for loop but it wasnt working
			linecolour.rgb[2] = atoi(argv[x + 3]);
			
			linecoordStart = { atoi(argv[x + 4]),  atoi(argv[x + 5]) };
			linecoordEnd = { atoi(argv[x + 6]) , atoi(argv[x + 7]) };

			Line *lineptr = new Line(linecolour, linecoordStart, linecoordEnd);
			list.push_front(lineptr);//adds pointer to forward list
			nextLetter = 8;//needed because there are 8 argc that occur with the Letter that correspond to line, 
							// so the for loop needs to skip all of these when the if statment is complete
							//so that it doesnt repeat the same drawing twice
		}
		else if (*argv[x] == 'P')//if command arg is a letter p
		{

			COLOUR pointcolour;//point objects only take in one parameter which is colour
			pointcolour.rgb[0] = atoi(argv[x + 1]);//the next 3 values that come after P in command arguments correspond to colour rbg values
			pointcolour.rgb[1] = atoi(argv[x + 2]);//tried to use for loop but it didnt work
			pointcolour.rgb[2] = atoi(argv[x + 3]);

			COORD pointcoord;
			pointcoord = { atoi(argv[x + 4]), atoi(argv[x + 5]) };//the 4th and 5th args after the letter correspond to the R and C of the coord

			Point *pointptr = new Point(pointcolour, pointcoord);//pointer pointing to point object
			list.push_front(pointptr);

			nextLetter = 6;//same explanation as previous if statment except there are only 6 arguments that correspond to point
			}
		else if (*argv[x] == 'S')
		{
			COLOUR shapecolour;
		
			
			int numFollowingCoords = atoi(argv[x + 4]);//number of coords in the list of args for shape 
			int coordRolCol = x + 5;//the first coord row, column is the arg right after
			
			shapecolour.rgb[0] = atoi(argv[x + 1]);//getting the 3 colour rbg vals
			shapecolour.rgb[1] = atoi(argv[x + 2]);
			shapecolour.rgb[2] = atoi(argv[x + 3]);
			Shape *shapeptr = new Shape(shapecolour);//pointer pointing to shape object

			for (int j = 0; j < numFollowingCoords; j++)//runs aslong as there is another coord
			{
				COORD shapecoord = { atoi(argv[coordRolCol]), atoi(argv[coordRolCol + 1]) };//created a shapecoord
				(*shapeptr).AddCoord(shapecoord);//adds the newly created coord to the shapes coord list
				coordRolCol = coordRolCol + 2;
			}

			list.push_front(shapeptr);//adds the pointer to the forward list
			nextLetter = 5 + (2 * numFollowingCoords);//needed to get to the next letter after 
		}
		
		else
		{
			cout << "\_('.')_/" << endl;//included because i felt like it
		}

	}

	cout <<"Num of shapes "<< Shape::GetShapes() << endl;//gets the shapes from the counter that been hopefully incrementing
		while (!(list.empty()))//runs until all elements are deleter
		{
			(list.front())->draw(drawing);//calls the draw fcn in order of which pointer is at front of the list
			delete (list.front()); //deletes the first element in the list aka frees memory
			list.pop_front();//allows us to access the next element as it has become the first element in the list

		}
		cout << "num of shapes "<< Shape::GetShapes() << endl;
		BMfileNM = argv[2];
		drawing.saveBMP(BMfileNM);//needed to it produces a file in assignment folder to see the drawing
		cout << "File " << BMfileNM << " saved successfully!" << endl;//file has been successfully saved
		char c;
		cin >> c;


}
