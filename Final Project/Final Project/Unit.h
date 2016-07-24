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

#ifndef UNIT_H
#define UNIT_H

#include "AnimatedSprite.h"
#include "Point.h"
#include "EventListener.h"

class Unit : public EventListener
{
public:
	Unit();
	Unit(vector<AnimatedSprite*> sprites);
	Unit(vector<AnimatedSprite*> sprites, Point location);
	~Unit();

	virtual void update();

	vector<AnimatedSprite*> getSprites();
	Point getLocation();

	void setSprites(vector<AnimatedSprite*> sprites);
	void setLocation(Point location);

	bool playAnimationOnce(int animation, Point loc, bool start = false);

	int getCurrentHP();
	int getCurrentMP();
	
	void setCurrentHP(int hp);
	void setCurrentMP(int mp);

	virtual void handleEvent(Event* theEvent);

	void reset();

protected:
	vector<AnimatedSprite*> mSprites;
	Point mLocation;
	Point mStartLocation;

	int mCurrentAnimation;

	int mCurrentHP;
	int mCurrentMP;

	Timer mPlayOnceTimer;
};

#endif