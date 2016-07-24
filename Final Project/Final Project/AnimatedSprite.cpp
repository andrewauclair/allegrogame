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

#include "AnimatedSprite.h"
#include "Game.h"

/***********************************************
 * Pre: Instance must be created
 * Post: Animation Timer is started
 * Purpose: To start the animation timer
 ***********************************************/
AnimatedSprite::AnimatedSprite()
{
	//mFrameTimer.start();
	mSpeed = 0;
	mFrameCount = -1;
}

/***********************************************
 * Pre: Instance must be created as well as a Bitmap vector
		and the speed
 * Post: Frames vector and speed are set
 * Purpose: To set the vector and speed
 ***********************************************/
AnimatedSprite::AnimatedSprite(vector<BITMAP*> theFrames, int speed)
{
	//mFrameTimer.start();
	mFrames = theFrames;
	mSpeed = speed;
	mFrameCount = -1;
}

/***********************************************
 * Pre: Instance must be created
 * Post: N/A
 * Purpose: N/A
 ***********************************************/
AnimatedSprite::~AnimatedSprite()
{
	for (unsigned int i = 0; i < mFrames.size(); i++)
	{
		destroy_bitmap(mFrames[i]);
	}
}

/***********************************************
 * Pre: Instance must be created
 * Post: Frames are returned
 * Purpose: To return the Frames
 ***********************************************/
vector<BITMAP*> AnimatedSprite::getFrames()
{
	return mFrames;
}

BITMAP* AnimatedSprite::getBitmap()
{
	return mFrames[0];
}

/***********************************************
 * Pre: Instance must be created
 * Post: Speed is returned
 * Purpose: To return the Speed
 ***********************************************/
int AnimatedSprite::getSpeed()
{
	return mSpeed;
}

/***********************************************
 * Pre: Instance must be created
 * Post: Timer is returned
 * Purpose: To return the Timer
 ***********************************************/
Timer AnimatedSprite::getTimer()
{
	return mFrameTimer;
}


/***********************************************
 * Pre: Instance must be created as well as a bitmap vector
 * Post: Frames is set to equal the incoming vector
 * Purpose: To set the Frames as desired
 ***********************************************/
void AnimatedSprite::setFrames(vector<BITMAP*> theFrames)
{
	mFrames = theFrames;
}

/***********************************************
 * Pre: Instance must be created as well a the speed int
 * Post: mSpeed is set to equal speed
 * Purpose: To set mSpeed as desired
 ***********************************************/
void AnimatedSprite::setSpeed(int speed)
{
	mSpeed = speed;
}

/***********************************************
 * Pre: Instance must be created as well as a Timer
 * Post: FrameTimer is set to equal theTime
 * Purpose: To set Frametimer
 ***********************************************/
void AnimatedSprite::setTimer(Timer theTime)
{
	mFrameTimer = theTime;
}

/***********************************************
 * Pre: Instance must be created as well as a bitmap
 * Post: A frame is added to the vector
 * Purpose: To add a frame to the vector
 ***********************************************/
void AnimatedSprite::addFrame(BITMAP* frame)
{
	mFrames.push_back(frame);
}

/***********************************************
 * Pre: Instance must be created as well as the GraphicsSystem
 * Post: Depending on the Timer, a certain frame is drawn to the screen
 * Purpose: To draw a certain frame in the vector to the screen
 ***********************************************/
void AnimatedSprite::playAnimation(Point location)
{
	if (mFrameCount == -1)
	{
		mFrameTimer.start();
		mFrameCount = 0;
	}

	if (mFrameTimer.getElapsedTime() >= mSpeed * (mFrameCount+1))
	{
		mFrameCount++;
	}
	
	if ((unsigned)mFrameCount >= mFrames.size())
	{
		mFrameCount = 0;
		mFrameTimer.start();
	}

	gpGame->getGraphicsSystem()->draw(location, mFrames[mFrameCount], true);
	//gpGame->getGraphicsSystem()->draw(location, mFrames[((int)mFrameTimer.getElapsedTime() / mSpeed) % mFrames.size()], true);
}

int AnimatedSprite::getCurrentFrame()
{
	return ((int)mFrameTimer.getElapsedTime() / mSpeed) % mFrames.size();
}