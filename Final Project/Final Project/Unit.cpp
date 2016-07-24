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

#include "Unit.h"
#include "Game.h"

Unit::Unit()
{
}

Unit::Unit(vector<AnimatedSprite*> sprites)
{
	for (unsigned int i = 0; i < sprites.size(); i++)
	{
		mSprites.push_back(sprites[i]);
	}
}

Unit::Unit(vector<AnimatedSprite*> sprites, Point location)
{
	mSprites = vector<AnimatedSprite*>();

	for (unsigned int i = 0; i < sprites.size(); i++)
	{
		mSprites.push_back(sprites[i]);
	}

	mLocation = location;
	mStartLocation = location;
}

Unit::~Unit()
{
}

void Unit::update()
{
	gpGame->getGraphicsSystem()->draw(mLocation, mSprites[mCurrentAnimation]->getBitmap(), true);
}

vector<AnimatedSprite*> Unit::getSprites()
{
	return mSprites;
}

Point Unit::getLocation()
{
	return mLocation;
}

void Unit::setSprites(vector<AnimatedSprite*> sprites)
{
	for (unsigned int i = 0; i < sprites.size(); i++)
	{
		mSprites[i] = sprites[i];
	}
}

void Unit::setLocation(Point location)
{
	mLocation = location;
}

void Unit::handleEvent(Event* theEvent)
{
}

//for only playing an animation once through
bool Unit::playAnimationOnce(int animation, Point loc, bool start)
{
	if (start)
	{
		mPlayOnceTimer.start();
	}

	if (mPlayOnceTimer.getElapsedTime() >= mSprites[animation]->getSpeed() * (mSprites[animation]->getFrames().size()))
	{
		mPlayOnceTimer.stop();

		return false;
	}

	mSprites[animation]->playAnimation(loc);

	return true;
}

int Unit::getCurrentHP()
{
	return mCurrentHP;
}

int Unit::getCurrentMP()
{
	return mCurrentMP;
}

void Unit::setCurrentHP(int hp)
{
	mCurrentHP = hp;
}

void Unit::setCurrentMP(int mp)
{
	mCurrentMP = mp;
}

void Unit::reset()
{
	mLocation = mStartLocation;
}