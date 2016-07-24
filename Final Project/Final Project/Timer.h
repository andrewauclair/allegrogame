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

#pragma once

#include <allegro.h>
#include <winalleg.h>

class Timer
{
public:
	Timer();
	~Timer();

	void start();
	void stop();
	double getElapsedTime();
	void sleepUntilElapsed( double ms );

private:
	LARGE_INTEGER mStartTime;
	LARGE_INTEGER mEndTime;
	LARGE_INTEGER mTimerFrequency;
	double mElapsedTime;

	//helper function - uses current frequency for the Timer
	double calcDifferenceInMS( LARGE_INTEGER from, LARGE_INTEGER to );

};