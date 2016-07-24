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

#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

	void setX(int x);
	void setY(int y);

	int getX();
	int getY();

private:
	int mX;
	int mY;
};

#endif