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

#include "PathFindingSystem.h"
#include "Game.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

PathFindingSystem::PathFindingSystem()
{
}

PathFindingSystem::~PathFindingSystem()
{
}

Point PathFindingSystem::getMove(int width, int height, int speed, Point start, Point end)
{	
	// check to see if end is NULL, if it is then we are just wandering randomly
	// other wise we are going to move towards the end point from start
	if (end.getX() == -1)
	{
		// pick a random direction to move in and then check to see if theres a collision
		int randDirection = rand()%(4)+1;

		int xChange = 0;
		int yChange = 0;

		switch(randDirection)
		{
		case 1:
			yChange = speed * -1;
			break;
		case 2:
			xChange = speed * -1;
			break;
		case 3:
			xChange = speed;
			break;
		case 4:
			yChange = speed;
			break;
		}

		if (!gpGame->getMapManager()->getCurrentMap()->checkCollisions(Point(start.getX() + xChange, start.getY() + yChange), width, height) &&
			!gpGame->getMapManager()->getCurrentMap()->checkEnemyCollisions(start, Point(start.getX() + xChange, start.getY() + yChange), width, height))
		{
			return Point(start.getX() + xChange, start.getY() + yChange);
		}
		else
		{
			return start;
		}
	
	}
	else
	{
		// make the 4 points that are possible to move to
		vector<Point> possibleMoves;
		vector<int> values;

		// give each point its F value along the way
		if (!gpGame->getMapManager()->getCurrentMap()->checkCollisions(Point(start.getX(), start.getY() - speed), width, height) &&
			!gpGame->getMapManager()->getCurrentMap()->checkEnemyCollisions(start, Point(start.getX(), start.getY() - speed), width, height))
		{
			Point newPoint = Point(start.getX(), start.getY() - speed);
			possibleMoves.push_back(newPoint);
			values.push_back(manhattanDistance(newPoint, end) + 10);
		}

		if (!gpGame->getMapManager()->getCurrentMap()->checkCollisions(Point(start.getX() - speed, start.getY()), width, height) &&
			!gpGame->getMapManager()->getCurrentMap()->checkEnemyCollisions(start, Point(start.getX() - speed, start.getY()), width, height))
		{
			Point newPoint = Point(start.getX() - speed, start.getY());
			possibleMoves.push_back(newPoint);
			values.push_back(manhattanDistance(newPoint, end) + 10);
		}

		if (!gpGame->getMapManager()->getCurrentMap()->checkCollisions(Point(start.getX() + speed, start.getY()), width, height) &&
			!gpGame->getMapManager()->getCurrentMap()->checkEnemyCollisions(start, Point(start.getX() + speed, start.getY()), width, height))
		{
			Point newPoint = Point(start.getX() + speed, start.getY());
			possibleMoves.push_back(newPoint);
			values.push_back(manhattanDistance(newPoint, end) + 10);
		}

		if (!gpGame->getMapManager()->getCurrentMap()->checkCollisions(Point(start.getX(), start.getY() + speed), width, height) &&
			!gpGame->getMapManager()->getCurrentMap()->checkEnemyCollisions(start, Point(start.getX(), start.getY() + speed), width, height))
		{
			Point newPoint = Point(start.getX(), start.getY() + speed);
			possibleMoves.push_back(newPoint);
			values.push_back(manhattanDistance(newPoint, end) + 10);
		}

		// choose the best move and return it
		int lowest = 0;

		for (unsigned int i = 1; i < values.size(); i++)
		{
			if (values[i] < values[lowest])
			{
				lowest = i;
			}
		}

		// found the lowest so return that point
		if (possibleMoves.size() > 0)
		{
			return possibleMoves[lowest];
		}

		return start;
	}
}

int PathFindingSystem::manhattanDistance(Point start, Point end)
{
	return abs(start.getX() - end.getX()) + abs(start.getY() - end.getY());
}