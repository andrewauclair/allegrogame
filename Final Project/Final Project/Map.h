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

#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include "UnitManager.h"
#include "Enemy.h"
#include "Battle.h"
#include "EventListener.h"
#include <allegro.h>
#include <vector>
using namespace std;

class Map : public EventListener
{
public:
	Map();
	Map(BITMAP* foreground, BITMAP* background);
	Map(BITMAP* foreground, BITMAP* background, int num, int left, int right, int up, int down);
	~Map();

	void drawForeground();
	void drawBackground();

	void update();

	void setForeground(BITMAP* foreground);
	void setBackground(BITMAP* background);

	int getLeftMap();
	int getRightMap();
	int getUpMap();
	int getDownMap();

	void setLeftMap(int left);
	void setRightMap(int right);
	void setUpMap(int up);
	void setDownMap(int down);

	void addEnemies(vector<Unit*> enemies);
	void addBattles(vector<Battle*> battles);

	vector<Battle*> getBattles();

	virtual void handleEvent(Event* theEvent);

	UnitManager* getUnitManager();

	void addCollision(Point point1, Point point2);

	bool checkCollisions(Point &loc, int width, int height);
	bool checkCollisions(Unit* unit1, Unit* unit2);
	bool checkCollisions(Point &loc);
	bool checkEnemyCollisions(Point &start, Point &loc, int width, int height);
	bool checkEnemyCollisions(Point &start, Point &loc);

	int getNumber();

	void reset();

	void setStartPoint(Point location);
	Point getStartPoint();

private:
	BITMAP* mForeground;
	BITMAP* mBackground;

	vector<Point> mCollisionsStart;
	vector<Point> mCollisionsEnd;

	vector<Battle*> mBattles;

	UnitManager* mUnitManager;

	int mLeftMap;
	int mRightMap;
	int mUpMap;
	int mDownMap;

	int mNum;
	int mBattleNum;

	Point mStartPosition;
};

#endif