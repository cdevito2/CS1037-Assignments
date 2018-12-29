#include<iostream>
#include "Drawing.h"
#include <fstream>
#include <math.h>
using namespace std;
Drawing::Drawing(unsigned width, unsigned height, COLOUR clr) :
	w(width), h(height), pixels(nullptr) {
	pixels = new unsigned char[w * h * CHANNELS];
	for (unsigned r = 0; r < h; r++) {
		for (unsigned c = 0; c < w; c++) {
			for (unsigned x = 0; x < CHANNELS; x++) {
				pixels[r * w * CHANNELS + c * CHANNELS + x] = clr.rgb[x];
			}
		}
	}
}

void Drawing::setPixel(COORD coord, COLOUR clr) {
	for (unsigned x = 0; x < CHANNELS; x++)
		pixels[coord.row * w * CHANNELS + coord.col * CHANNELS + x] = clr.rgb[x];
}

void Drawing::drawLine(COORD start, COORD end, COLOUR clr) {
	//Bresenham's line algorithm modified for symmetric cases
	 //always draw line origin
	setPixel(start, clr);
	//rename the axis as s=step and c=calculated
	//using pointers to avoid if-checks within the loop
	int ds = abs(end.col - start.col), dc = abs(end.row - start.row);
	//compute axis to step thru
	int *s1, *s2, *c1, *c2;
	if (dc > ds) {
		s1 = &start.row;
		c1 = &start.col;
		s2 = &end.row;
		c2 = &end.col;
		ds = abs(end.row - start.row);
		dc = abs(end.col - start.col);
	}
	else {
		s1 = &start.col;
		c1 = &start.row;
		s2 = &end.col;
		c2 = &end.row;
	}
	//check whether calc axis is negative
	int calcIncr = (*c2 < *c1) ? -1 : 1;
	//check whether step axis is negative
	int stepIncr = (*s2 < *s1) ? -1 : 1;
	//define p increments once instead of recalculating in for loop
	int i, incrNeg = 2 * dc, incrPos = 2 * dc - 2 * ds, p = 2 * dc - ds;
	//iterate for each point along the step axis
	for (i = 0; i < ds; i++) {
		if (p < 0) {
			p += incrNeg;
		}
		else {
			p += incrPos;
			(*c1) += calcIncr;
		}
		(*s1) += stepIncr;
		setPixel(start, clr);
	}
}

bool Drawing::saveBMP(std::string file_name) {
	//See https://en.wikipedia.org/wiki/BMP_file_format for a good description!
	ofstream f(file_name, ios::binary | ios::out);
	if (!f.is_open()) return false;
	f.write("BM", 2);
	unsigned int filler = 0, headsz = 54;
	//calculate row length with padding to 4 bytes boundaries
	unsigned int rowsz = (24 * w + 31) / 32;
	rowsz *= 4;
	unsigned int sz = headsz + rowsz * h;
	f.write((char *)&sz, 4);
	f.write((char *)&filler, 4);
	f.write((char *)&headsz, 4);
	sz = 40;
	f.write((char *)&sz, 4);
	f.write((char *)&w, 4);
	//BMP stored bottom to top unless negative height used
	int reverse = h;
	reverse *= -1;
	f.write((char *)&reverse, 4);
	unsigned short shrt = 1;
	f.write((char *)&shrt, 2);
	shrt = 24;
	f.write((char *)&shrt, 2);
	f.write((char *)&filler, 4);
	sz = rowsz * h;
	f.write((char *)&sz, 4);
	filler = 2835;
	f.write((char *)&filler, 4);
	f.write((char *)&filler, 4);
	filler = 0;
	f.write((char *)&filler, 4);
	f.write((char *)&filler, 4);
	unsigned pos;
	shrt = 0;
	for (unsigned r = 0; r < h; r++) {
		pos = 0;
		for (unsigned c = 0; c < w; c++) {
			for (unsigned x = 0; x < CHANNELS; x++) {
				//BMP stored as BGR
				f.write((char *)&pixels[r*w*CHANNELS + c * CHANNELS + (2 - x)], 1);
			}
			pos += CHANNELS;
		}
		//add blank padding to 4 byte boundaries
		while (pos % 4 != 0) {
			f.write((char *)&shrt, 1);
			pos++;
		}
	}
	f.close();
	return true;
}