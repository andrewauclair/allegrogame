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

#include "Portal.h"
#include "Game.h"

Portal::Portal(vector<AnimatedSprite*> sprites, Point loc)
:Unit(sprites, loc)
{
}

Portal::~Portal()
{
}

void Portal::update()
{
	// draw the portal
	if (mTimer.getElapsedTime() < 2000)
	{
		mSprites[0]->playAnimation(mLocation);
	}
	else
	{
		mSprites[1]->playAnimation(mLocation);
	}
}

void Portal::startTimer()
{
	mTimer.start();
}