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

#include "Point.h"

Point::Point()
{
}

Point::Point(int x, int y)
{
	mX = x;
	mY = y;
}

Point::~Point()
{
}

void Point::setX(int x)
{
	mX = x;
}

void Point::setY(int y)
{
	mY = y;
}

int Point::getX()
{
	return mX;
}

int Point::getY()
{
	return mY;
}