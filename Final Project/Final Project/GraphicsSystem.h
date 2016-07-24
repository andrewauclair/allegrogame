/*
	Author:			Erin Trzcinski and Andrew Auclair
	Class:			EGP 310 01
	Assignment:		Final Project: Dance with the Devil	
	Date Assigned:	2011 03 30
	Due Date:		2011 04 27 at 1:00PM

	Description:	To create a create a game using the architecture 
					we've learned in class

	Certification of Authenticity:
		We certify that this assignment is entirely our own work. 
		Save for the art, music, sound effects, A* pathfinding, etc.
*/

#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include <allegro.h>
#include "Point.h"
#include <string>
using namespace std;

const int HEIGHT = 600;
const int WIDTH = 900;

class GraphicsSystem
{
public:
	GraphicsSystem();
	~GraphicsSystem();

	void init();
	void draw(Point loc, BITMAP* image, bool masked);
	void drawText(Point loc, const string& text, int size, bool centered, int width = 0);
	int  getPixelWidthOfText(const string& text, int size);

	void swap();
	BITMAP* mBackBuffer;
private:
	BITMAP* mScreen;
	
};

#endif