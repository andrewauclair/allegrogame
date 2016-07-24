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

#include "Credits.h"
#include "Game.h"

Credits::Credits()
{
	gpGame->getEventSystem()->addListener(CREDITS_EVENT, this);
	mSpeed = 1;
	mCreditsOver = false;
}

Credits::~Credits()
{
}

//play the credits
void Credits::update()
{
	Point loc(0, mTimer.getElapsedTime() * (mSpeed/8.0) * -1);

	if (loc.getY() < -7200)
	{
		loc.setY(-7200);
	}

	if ((mTimer.getElapsedTime() * (mSpeed/8.0)) > 8200 && !mCreditsOver)
	{
		mCreditsOver = true;
		gpGame->getEventSystem()->addEvent(new Event(GAME_OVER_EVENT));
	}

	gpGame->getGraphicsSystem()->draw(Point(0, 0), gpGame->getAssetManager()->getSprite(CREDITS_BACKGROUND)->getFrames()[0], false);
	
	set_alpha_blender();

	draw_trans_sprite(gpGame->getGraphicsSystem()->mBackBuffer, gpGame->getAssetManager()->getSprite(CREDITS)->getFrames()[gpGame->getLocalizationSystem()->getCurrentLanguage()], loc.getX(), loc.getY());
}

void Credits::handleEvent(Event* theEvent)
{
	if (theEvent->getType() == CREDITS_EVENT)
	{
		mTimer.start();
	}
}