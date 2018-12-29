#pragma once
//assn3.exe test.bmp 200 100 127 127 127 S 255 0 0 4 10 10 10 190 90 190 90 10 S 0 255 0 3 50 100 55 105 55 95 L 0 0 255 60 30 80 100 L 0 0 255 80 100 60 170 P 0 0 0 25 70 P 0 0 0 25 130
#pragma once
#include <string>
#define CHANNELS 3
//RGB colour object
typedef struct {
	unsigned char rgb[CHANNELS];
} COLOUR;

//Row-column coordinate object
typedef struct {
	int row;
	int col;
} COORD;

class Drawing
{
private:
	unsigned w;
	unsigned h;
	unsigned char *pixels;
public:
	Drawing(unsigned width, unsigned height, COLOUR clr = { 0,0,0 });
	~Drawing() { delete[] pixels; }
	bool saveBMP(std::string file_name);
	void setPixel(COORD coord, COLOUR clr);
	void drawLine(COORD start, COORD end, COLOUR clr);
};