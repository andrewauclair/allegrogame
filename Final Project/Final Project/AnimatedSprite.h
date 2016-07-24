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

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>
#include "Timer.h"
#include "Point.h"
#include <allegro.h>

using namespace std;

class AnimatedSprite
{
private:
	vector<BITMAP*> mFrames;
	Timer mFrameTimer;
	int mSpeed;
	int mFrameCount;

public:
	AnimatedSprite();
	AnimatedSprite(vector<BITMAP*> theFrames, int speed);
	~AnimatedSprite();

	vector<BITMAP*> getFrames();
	BITMAP* getBitmap();
	int getSpeed();
	Timer getTimer();

	void setFrames(vector<BITMAP*> theFrames);
	void setSpeed(int speed);
	void setTimer(Timer theTime);

	int getCurrentFrame();

	void addFrame(BITMAP* frame);
	void playAnimation(Point location);
};


#endif