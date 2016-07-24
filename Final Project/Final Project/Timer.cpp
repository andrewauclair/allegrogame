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

#include "Timer.h"

/*
pre: none
post: initialized
purpose: create timer
*/
Timer::Timer()
:mElapsedTime(0.0)
{
	QueryPerformanceFrequency( &mTimerFrequency );
	mStartTime.QuadPart = 0;
	mEndTime.QuadPart = 0;
}

/*
pre: initialized
post: none
purpose: destroy timer
*/
Timer::~Timer()
{
}

/*
pre: initialized
post: timer started
purpose: start timer
*/
void Timer::start()
{
	QueryPerformanceCounter( &mStartTime );
	
	//reset end time as well
	mEndTime.QuadPart = 0;
}

/*
pre: initialized
post: timer stopped
purpose: stop timer
*/
void Timer::stop()
{
	QueryPerformanceCounter( &mEndTime );
	mElapsedTime = calcDifferenceInMS( mStartTime, mEndTime );
}

/*
pre: initialized
post: elapsed time returned
purpose: return elapsed time
*/
double Timer::getElapsedTime()
{
	//if we have an end time then the timer isn't running and we can just return the elapsed time
	if( mEndTime.QuadPart != 0 )
	{
		return mElapsedTime;
	}
	else //otherwise we need to get the current time, do the math and return that
	{
		LARGE_INTEGER currentTime;
		QueryPerformanceCounter( &currentTime );
		return calcDifferenceInMS( mStartTime, currentTime );
	}
}

/*
pre: initialized
post: slept for ms
purpose: sleep for ms
*/
void Timer::sleepUntilElapsed( double ms )
{
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter( &currentTime );

	double timeElapsed = calcDifferenceInMS( mStartTime, currentTime );
	
	double timeToSleep = ms - timeElapsed;
	if( timeToSleep > 0.0 )
	{
		Sleep( (DWORD)timeToSleep );
	}
}

/*
pre: initialized
post: difference in ms returned
purpose: return difference in ms
*/
double Timer::calcDifferenceInMS( LARGE_INTEGER from, LARGE_INTEGER to )
{
	double difference = (double)(to.QuadPart - from.QuadPart) / (double)mTimerFrequency.QuadPart;
	return difference * 1000;
}
