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

#include "MapManager.h"
#include "ChangeMapEvent.h"
#include "Game.h"
#include "Enemy.h"
#include "Portal.h"
#include "Battle.h"
#include <fstream>
#include <string>
using namespace std;

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
	for (unsigned int i = 0; i < mMaps.size(); i++)
	{
		delete mMaps[i];
	}
}

void MapManager::init()
{
	mCurrentMap = 10;

	// load maps
	BITMAP* foregroundMap1 = load_bitmap("Assets/Maps/map1Foreground.bmp", NULL);
	BITMAP* foregroundMap2 = load_bitmap("Assets/Maps/map2Foreground.bmp", NULL);
	BITMAP* foregroundMap3 = load_bitmap("Assets/Maps/map3Foreground.bmp", NULL);
	BITMAP* foregroundMap4 = load_bitmap("Assets/Maps/map4Foreground.bmp", NULL);
	BITMAP* foregroundMap5 = load_bitmap("Assets/Maps/map5Foreground.bmp", NULL);
	BITMAP* foregroundMap6 = load_bitmap("Assets/Maps/map6Foreground.bmp", NULL);
	BITMAP* foregroundMap7 = load_bitmap("Assets/Maps/map7Foreground.bmp", NULL);
	BITMAP* foregroundMap8 = load_bitmap("Assets/Maps/map8Foreground.bmp", NULL);
	BITMAP* foregroundMap9 = load_bitmap("Assets/Maps/map9Foreground.bmp", NULL);
	BITMAP* foregroundMap10 = load_bitmap("Assets/Maps/map10Foreground.bmp", NULL);
	BITMAP* foregroundMap11 = load_bitmap("Assets/Maps/map11Foreground.bmp", NULL);

	BITMAP* backgroundMap1 = load_bitmap("Assets/Maps/map1Background.bmp", NULL);
	BITMAP* backgroundMap2 = load_bitmap("Assets/Maps/map2Background.bmp", NULL);
	BITMAP* backgroundMap3 = load_bitmap("Assets/Maps/map3Background.bmp", NULL);
	BITMAP* backgroundMap4 = load_bitmap("Assets/Maps/map4Background.bmp", NULL);
	BITMAP* backgroundMap5 = load_bitmap("Assets/Maps/map5Background.bmp", NULL);
	BITMAP* backgroundMap6 = load_bitmap("Assets/Maps/map6Background.bmp", NULL);
	BITMAP* backgroundMap7 = load_bitmap("Assets/Maps/map7Background.bmp", NULL);
	BITMAP* backgroundMap8 = load_bitmap("Assets/Maps/map8Background.bmp", NULL);
	BITMAP* backgroundMap9 = load_bitmap("Assets/Maps/map9Background.bmp", NULL);
	BITMAP* backgroundMap10 = load_bitmap("Assets/Maps/map10Background.bmp", NULL);
	BITMAP* backgroundMap11 = load_bitmap("Assets/Maps/map11Background.bmp", NULL);

	Map* map1 = new Map(foregroundMap1, backgroundMap1, 1, -1, 2, -1, -1);
	Map* map2 = new Map(foregroundMap2, backgroundMap2, 2, 1, -1, -1, 3);
	Map* map3 = new Map(foregroundMap3, backgroundMap3, 3, -1, -1, 2, 4);
	Map* map4 = new Map(foregroundMap4, backgroundMap4, 4, 5, -1, 3, -1);
	Map* map5 = new Map(foregroundMap5, backgroundMap5, 5, -1, 4, -1, 6);
	Map* map6 = new Map(foregroundMap6, backgroundMap6, 6, -1, 7, 5, -1);
	Map* map7 = new Map(foregroundMap7, backgroundMap7, 7, 6, 8, -1, -1);
	Map* map8 = new Map(foregroundMap8, backgroundMap8, 8, 7, -1, 9, -1);
	Map* map9 = new Map(foregroundMap9, backgroundMap9, 9, -1, 10, -1, 8);
	Map* map10 = new Map(foregroundMap10, backgroundMap10, 10, 9, 11, -1, -1);
	Map* map11 = new Map(foregroundMap11, backgroundMap11, 11, 10, -1, -1, -1);

	// load collisions
	ifstream mapCollisions;

	const string files[] = {"MapCollisions/map1Collisions.txt", "MapCollisions/map2Collisions.txt",
		"MapCollisions/map3Collisions.txt", "MapCollisions/map4Collisions.txt", 
		"MapCollisions/map5Collisions.txt", "MapCollisions/map6Collisions.txt", "MapCollisions/map7Collisions.txt",
		"MapCollisions/map8Collisions.txt", "MapCollisions/map9Collisions.txt", "MapCollisions/map10Collisions.txt",
		"MapCollisions/map11Collisions.txt"};

	

	int num;
	//load all of the collision areas
	for (int i = 1; i <= 11; i++)
	{
		mapCollisions.open(files[i-1].c_str());

		while (!mapCollisions.eof())
		{
			mapCollisions >> num;

			Point newPoint1;
			newPoint1.setX(num);

			mapCollisions >> num;

			newPoint1.setY(num);

			Point newPoint2;
			
			mapCollisions >> num;

			newPoint2.setX(num);

			mapCollisions >> num;

			newPoint2.setY(num);

			switch (i)
			{
			case 1:
				map1->addCollision(newPoint1, newPoint2);
				break;
			case 2:
				map2->addCollision(newPoint1, newPoint2);
				break;
			case 3:
				map3->addCollision(newPoint1, newPoint2);
				break;
			case 4:
				map4->addCollision(newPoint1, newPoint2);
				break;
			case 5:
				map5->addCollision(newPoint1, newPoint2);
				break;
			case 6:
				map6->addCollision(newPoint1, newPoint2);
				break;
			case 7:
				map7->addCollision(newPoint1, newPoint2);
				break;
			case 8:
				map8->addCollision(newPoint1, newPoint2);
				break;
			case 9:
				map9->addCollision(newPoint1, newPoint2);
				break;
			case 10:
				map10->addCollision(newPoint1, newPoint2);
				break;
			case 11:
				map11->addCollision(newPoint1, newPoint2);
				break;
			}
		}

		mapCollisions.close();
		mapCollisions.clear();
	}

	const string enemiesFiles[] = {"MapEnemies/map1Enemies.txt", "MapEnemies/map2Enemies.txt",
		"MapEnemies/map3Enemies.txt", "MapEnemies/map4Enemies.txt", 
		"MapEnemies/map5Enemies.txt", "MapEnemies/map6Enemies.txt", "MapEnemies/map7Enemies.txt",
		"MapEnemies/map8Enemies.txt", "MapEnemies/map9Enemies.txt", "MapEnemies/map10Enemies.txt", "mapEnemies/map11Enemies.txt"};

	// read in the enemies for the map and set them
	vector<Unit*> wanderingEnemies;
	vector<Battle*> battles;
	vector<Enemy*> battleEnemies;

	ifstream mapEnemies;

	// Create enemies to use later
	vector<AnimatedSprite*> devilingSprites;
	devilingSprites.push_back(gpGame->getAssetManager()->getSprite(DEVILING_IDLE));  // left
	devilingSprites.push_back(gpGame->getAssetManager()->getSprite(DEVILING_IDLE_RIGHT));  // right
	devilingSprites.push_back(gpGame->getAssetManager()->getSprite(DEVILING_UP));	 // up
	devilingSprites.push_back(gpGame->getAssetManager()->getSprite(DEVILING_IDLE));  // down
	devilingSprites.push_back(gpGame->getAssetManager()->getSprite(DEVILING_IDLE));  // idle
	devilingSprites.push_back(gpGame->getAssetManager()->getSprite(DEVILING_ATTACK));// attack
	devilingSprites.push_back(gpGame->getAssetManager()->getSprite(DEVILING_DYING));// dying

	vector<AnimatedSprite*> dracoSprites;
	dracoSprites.push_back(gpGame->getAssetManager()->getSprite(DRACO_LEFT)); // left
	dracoSprites.push_back(gpGame->getAssetManager()->getSprite(DRACO_RIGHT)); // right
	dracoSprites.push_back(gpGame->getAssetManager()->getSprite(DRACO_UP)); // up
	dracoSprites.push_back(gpGame->getAssetManager()->getSprite(DRACO_LEFT)); // down
	dracoSprites.push_back(gpGame->getAssetManager()->getSprite(DRACO_IDLE)); // idle
	dracoSprites.push_back(gpGame->getAssetManager()->getSprite(DRACO_ATTACK)); // attack
	dracoSprites.push_back(gpGame->getAssetManager()->getSprite(DRACO_DYING)); // dying

	vector<AnimatedSprite*> goblinSprites;
	goblinSprites.push_back(gpGame->getAssetManager()->getSprite(GOBLIN_IDLE)); // left
	goblinSprites.push_back(gpGame->getAssetManager()->getSprite(GOBLIN_IDLE)); // right
	goblinSprites.push_back(gpGame->getAssetManager()->getSprite(GOBLIN_IDLE)); // up
	goblinSprites.push_back(gpGame->getAssetManager()->getSprite(GOBLIN_IDLE)); // down
	goblinSprites.push_back(gpGame->getAssetManager()->getSprite(GOBLIN_IDLE)); // idle
	goblinSprites.push_back(gpGame->getAssetManager()->getSprite(GOBLIN_ATTACK)); // attack
	goblinSprites.push_back(gpGame->getAssetManager()->getSprite(GOBLIN_DYING)); // dying

	vector<AnimatedSprite*> desertWolfSprites;
	desertWolfSprites.push_back(gpGame->getAssetManager()->getSprite(WOLF_IDLE)); // left
	desertWolfSprites.push_back(gpGame->getAssetManager()->getSprite(WOLF_IDLE)); // right
	desertWolfSprites.push_back(gpGame->getAssetManager()->getSprite(WOLF_IDLE)); // up
	desertWolfSprites.push_back(gpGame->getAssetManager()->getSprite(WOLF_IDLE)); // down
	desertWolfSprites.push_back(gpGame->getAssetManager()->getSprite(WOLF_IDLE)); // idle
	desertWolfSprites.push_back(gpGame->getAssetManager()->getSprite(WOLF_ATTACK)); // attack
	desertWolfSprites.push_back(gpGame->getAssetManager()->getSprite(WOLF_DYING)); // dying

	vector<AnimatedSprite*> aquaSprites;
	aquaSprites.push_back(gpGame->getAssetManager()->getSprite(AQUA_IDLE)); // left
	aquaSprites.push_back(gpGame->getAssetManager()->getSprite(AQUA_IDLE)); // right
	aquaSprites.push_back(gpGame->getAssetManager()->getSprite(AQUA_IDLE)); // up
	aquaSprites.push_back(gpGame->getAssetManager()->getSprite(AQUA_IDLE)); // down
	aquaSprites.push_back(gpGame->getAssetManager()->getSprite(AQUA_IDLE)); // idle
	aquaSprites.push_back(gpGame->getAssetManager()->getSprite(AQUA_ATTACK)); // attack
	aquaSprites.push_back(gpGame->getAssetManager()->getSprite(AQUA_DYING)); // dying

	vector<AnimatedSprite*> seekerSprites;
	seekerSprites.push_back(gpGame->getAssetManager()->getSprite(SEEKER_IDLE)); // left
	seekerSprites.push_back(gpGame->getAssetManager()->getSprite(SEEKER_IDLE)); // right
	seekerSprites.push_back(gpGame->getAssetManager()->getSprite(SEEKER_IDLE)); // up
	seekerSprites.push_back(gpGame->getAssetManager()->getSprite(SEEKER_IDLE)); // down
	seekerSprites.push_back(gpGame->getAssetManager()->getSprite(SEEKER_IDLE)); // idle
	seekerSprites.push_back(gpGame->getAssetManager()->getSprite(SEEKER_ATTACK)); // attack
	seekerSprites.push_back(gpGame->getAssetManager()->getSprite(SEEKER_DYING)); // dying

	vector<AnimatedSprite*> salamanderSprites;
	salamanderSprites.push_back(gpGame->getAssetManager()->getSprite(SALAMANDER_IDLE)); // left
	salamanderSprites.push_back(gpGame->getAssetManager()->getSprite(SALAMANDER_IDLE)); // right
	salamanderSprites.push_back(gpGame->getAssetManager()->getSprite(SALAMANDER_IDLE)); // up
	salamanderSprites.push_back(gpGame->getAssetManager()->getSprite(SALAMANDER_IDLE)); // down
	salamanderSprites.push_back(gpGame->getAssetManager()->getSprite(SALAMANDER_IDLE)); // idle
	salamanderSprites.push_back(gpGame->getAssetManager()->getSprite(SALAMANDER_ATTACK)); // attack
	salamanderSprites.push_back(gpGame->getAssetManager()->getSprite(SALAMANDER_DYING)); // dying

	vector<AnimatedSprite*> nidhoggrSprites;
	nidhoggrSprites.push_back(gpGame->getAssetManager()->getSprite(NIDHOGGR_IDLE)); // left
	nidhoggrSprites.push_back(gpGame->getAssetManager()->getSprite(NIDHOGGR_IDLE)); // right
	nidhoggrSprites.push_back(gpGame->getAssetManager()->getSprite(NIDHOGGR_IDLE)); // up
	nidhoggrSprites.push_back(gpGame->getAssetManager()->getSprite(NIDHOGGR_IDLE)); // down
	nidhoggrSprites.push_back(gpGame->getAssetManager()->getSprite(NIDHOGGR_IDLE)); // idle
	nidhoggrSprites.push_back(gpGame->getAssetManager()->getSprite(NIDHOGGR_ATTACK)); // attack
	nidhoggrSprites.push_back(gpGame->getAssetManager()->getSprite(NIDHOGGR_DYING)); // dying

	vector<AnimatedSprite*> gopinichSprites;
	gopinichSprites.push_back(gpGame->getAssetManager()->getSprite(GOPINICH_IDLE)); // left
	gopinichSprites.push_back(gpGame->getAssetManager()->getSprite(GOPINICH_IDLE)); // right
	gopinichSprites.push_back(gpGame->getAssetManager()->getSprite(GOPINICH_IDLE)); // up
	gopinichSprites.push_back(gpGame->getAssetManager()->getSprite(GOPINICH_IDLE)); // down
	gopinichSprites.push_back(gpGame->getAssetManager()->getSprite(GOPINICH_IDLE)); // idle
	gopinichSprites.push_back(gpGame->getAssetManager()->getSprite(GOPINICH_ATTACK)); // attack
	gopinichSprites.push_back(gpGame->getAssetManager()->getSprite(GOPINICH_DYING)); // dying

	vector<AnimatedSprite*> boitataSprites;
	boitataSprites.push_back(gpGame->getAssetManager()->getSprite(BOITATA_IDLE)); // left
	boitataSprites.push_back(gpGame->getAssetManager()->getSprite(BOITATA_IDLE)); // right
	boitataSprites.push_back(gpGame->getAssetManager()->getSprite(BOITATA_IDLE)); // up
	boitataSprites.push_back(gpGame->getAssetManager()->getSprite(BOITATA_IDLE)); // down
	boitataSprites.push_back(gpGame->getAssetManager()->getSprite(BOITATA_IDLE)); // idle
	boitataSprites.push_back(gpGame->getAssetManager()->getSprite(BOITATA_ATTACK)); // attack
	boitataSprites.push_back(gpGame->getAssetManager()->getSprite(BOITATA_DYING)); // dying

	vector<AnimatedSprite*> portalSprites;
	portalSprites.push_back(gpGame->getAssetManager()->getSprite(PORTAL_INIT));
	portalSprites.push_back(gpGame->getAssetManager()->getSprite(PORTAL_OPEN));

	vector<AnimatedSprite*> satanSprites;
	satanSprites.push_back(gpGame->getAssetManager()->getSprite(SATAN_MORROC_IDLE));
	satanSprites.push_back(gpGame->getAssetManager()->getSprite(SATAN_MORROC_IDLE));
	satanSprites.push_back(gpGame->getAssetManager()->getSprite(SATAN_MORROC_IDLE));
	satanSprites.push_back(gpGame->getAssetManager()->getSprite(SATAN_MORROC_IDLE));
	satanSprites.push_back(gpGame->getAssetManager()->getSprite(SATAN_MORROC_IDLE));
	satanSprites.push_back(gpGame->getAssetManager()->getSprite(SATAN_MORROC_ATTACK));
	satanSprites.push_back(gpGame->getAssetManager()->getSprite(SATAN_MORROC_DYING));

	mMaps.push_back(map1);
	mMaps.push_back(map2);
	mMaps.push_back(map3);
	mMaps.push_back(map4);
	mMaps.push_back(map5);
	mMaps.push_back(map6);
	mMaps.push_back(map7);
	mMaps.push_back(map8);
	mMaps.push_back(map9);
	mMaps.push_back(map10);
	mMaps.push_back(map11);

	for (int i = 0; i < 11; i++)
	{
		mapEnemies.open(enemiesFiles[i].c_str());

		string line;

		bool wandering = true;

		while (!mapEnemies.eof())
		{
			mapEnemies >> line;

			if (line.compare("//Wandering") == 0)
			{
				// ignore
				continue;
			}
			else if (line.compare("//Battle") == 0)
			{
				// new battle
				wandering = false; // set wandering to false to stop looking for wandering enemies
			
				if (battleEnemies.size() > 0)
				{
					battles.push_back(new Battle(battleEnemies, i+1));
				}

				battleEnemies.clear();
			}
			else if (line.compare("//End") == 0)
			{
				battles.push_back(new Battle(battleEnemies, i+1));
				break;
			}

			if (wandering)
			{
				// add a new enemy to the vector
				if (line.compare("Deviling") == 0)
				{
					// read enemies location
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* deviling = new Enemy(devilingSprites, Point(x, y));

					wanderingEnemies.push_back(deviling);
				}
				else if (line.compare("Draco") == 0)
				{
					// read enemies location
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* draco = new Enemy(dracoSprites, Point(x, y));

					wanderingEnemies.push_back(draco);
				}
				else if (line.compare("Portal") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Portal* portal = new Portal(portalSprites, Point(x, y));

					wanderingEnemies.push_back(portal);
				}
			}
			else
			{
				// add a new enemy to the vector
				if (line.compare("Deviling") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* deviling = new Enemy(devilingSprites, Point(x, y));

					deviling->setEnemyName(DEVILING);

					battleEnemies.push_back(deviling);
				}
				else if (line.compare("Draco") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;
					Enemy* draco = new Enemy(dracoSprites, Point(x, y));

					draco->setEnemyName(DRACO);

					battleEnemies.push_back(draco);
				}
				else if (line.compare("Goblin") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* goblin = new Enemy(goblinSprites, Point(x, y));

					goblin->setEnemyName(GOBLIN);

					battleEnemies.push_back(goblin);
				}
				else if (line.compare("Desert_Wolf") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* desertWolf = new Enemy(desertWolfSprites, Point(x, y));

					desertWolf->setEnemyName(DESERT_WOLF);

					battleEnemies.push_back(desertWolf);
				}
				else if (line.compare("Aqua") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* aqua = new Enemy(aquaSprites, Point(x, y));

					aqua->setEnemyName(AQUA);

					battleEnemies.push_back(aqua);
				}
				else if (line.compare("Seeker") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* seeker = new Enemy(seekerSprites, Point(x, y));

					seeker->setEnemyName(SEEKER);

					battleEnemies.push_back(seeker);
				}
				else if (line.compare("Salamander") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* salamander = new Enemy(salamanderSprites, Point(x, y));

					salamander->setEnemyName(SALAMANDER);

					battleEnemies.push_back(salamander);
				}
				else if (line.compare("Nidhoggr") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* nidhoggr = new Enemy(nidhoggrSprites, Point(x, y));

					nidhoggr->setEnemyName(NIDHOGGR);

					battleEnemies.push_back(nidhoggr);
				}
				else if (line.compare("Gopinich") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* gopinich = new Enemy(gopinichSprites, Point(x, y));

					gopinich->setEnemyName(GOPINICH);

					battleEnemies.push_back(gopinich);
				}
				else if (line.compare("Boitata") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* boitata = new Enemy(boitataSprites, Point(x, y));

					boitata->setEnemyName(BOITATA);

					battleEnemies.push_back(boitata);
				}
				else if (line.compare("Satan") == 0)
				{
					int x, y;
					mapEnemies >> x;
					mapEnemies >> y;

					Enemy* satan = new Enemy(satanSprites, Point(x, y));

					satan->setEnemyName(SATAN_MORROC);

					battleEnemies.push_back(satan);
				}
			}
		}

		// add the enemies to the map
		switch(i)
		{
		case 0:
			map1->addEnemies(wanderingEnemies);
			map1->addBattles(battles);
			break;
		case 1:
			map2->addEnemies(wanderingEnemies);
			map2->addBattles(battles);
			break;
		case 2:
			map3->addEnemies(wanderingEnemies);
			map3->addBattles(battles);
			break;
		case 3:
			map4->addEnemies(wanderingEnemies);
			map4->addBattles(battles);
			break;
		case 4:
			map5->addEnemies(wanderingEnemies);
			map5->addBattles(battles);
			break;
		case 5:
			map6->addEnemies(wanderingEnemies);
			map6->addBattles(battles);
			break;
		case 6:
			map7->addEnemies(wanderingEnemies);
			map7->addBattles(battles);
			break;
		case 7:
			map8->addEnemies(wanderingEnemies);
			map8->addBattles(battles);
			break;
		case 8:
			map9->addEnemies(wanderingEnemies);
			map9->addBattles(battles);
			break;
		case 9:
			map10->addEnemies(wanderingEnemies);
			map10->addBattles(battles);
			break;
		case 10:
			map11->addEnemies(wanderingEnemies);
			map11->addBattles(battles);
		}

		wanderingEnemies.clear();
		battles.clear();
		battleEnemies.clear();
		mapEnemies.close();
		mapEnemies.clear();
	}

	// load map starting points
	ifstream mapPoints;
	mapPoints.open("MapStartingPoints/MapStartingPoints.txt");

	for (unsigned int i = 0; i < 11; i++)
	{
		int x, y;
		mapPoints >> x;
		mapPoints >> y;

		switch (i)
		{
		case 0:
			map1->setStartPoint(Point(x, y));
			break;
		case 1:
			map2->setStartPoint(Point(x, y));
			break;
		case 2:
			map3->setStartPoint(Point(x, y));
			break;
		case 3:
			map4->setStartPoint(Point(x, y));
			break;
		case 4:
			map5->setStartPoint(Point(x, y));
			break;
		case 5:
			map6->setStartPoint(Point(x, y));
			break;
		case 6:
			map7->setStartPoint(Point(x, y));
			break;
		case 7:
			map8->setStartPoint(Point(x, y));
			break;
		case 8:
			map9->setStartPoint(Point(x, y));
			break;
		case 9:
			map10->setStartPoint(Point(x, y));
			break;
		case 10:
			map11->setStartPoint(Point(x, y));
			break;
		}
	}

	gpGame->getEventSystem()->addListener(CHANGE_MAP_EVENT, this);
}

void MapManager::drawMapForeground()
{
	if (!gpGame->getCael()->isInBattle())
	{
		mMaps[mCurrentMap]->drawForeground();
	}
}

void MapManager::drawMapBackground()
{
	if (!gpGame->getCael()->isInBattle())
	{
		mMaps[mCurrentMap]->drawBackground();
	}
}

void MapManager::update()
{
	if (gpGame->getCael()->isInBattle())
	{
		gpGame->getGraphicsSystem()->draw(Point(0, 0), gpGame->getAssetManager()->getSprite(BATTLE_BACKGROUND)->getFrames()[0], false);
	}
	
	mMaps[mCurrentMap]->update();
}

void MapManager::handleEvent(Event* theEvent)
{
	if (theEvent->getType() == CHANGE_MAP_EVENT)
	{
		ChangeMapEvent* changeEvent = (ChangeMapEvent*)(theEvent);

		switch (changeEvent->getDirection())
		{
		case MAP_LEFT:
			if (mMaps[mCurrentMap]->getLeftMap() != -1)
			{
				mMaps[mCurrentMap]->reset();

				mCurrentMap = mMaps[mCurrentMap]->getLeftMap() - 1;

				ResetCaelEvent* resetEvent = new ResetCaelEvent(MAP_LEFT);

				gpGame->getEventSystem()->addEvent(resetEvent);
			}
			break;
		case MAP_RIGHT:
			if (mMaps[mCurrentMap]->getRightMap() != -1)
			{
				mMaps[mCurrentMap]->reset();

				mCurrentMap = mMaps[mCurrentMap]->getRightMap() - 1;

				if (mCurrentMap == 10)
				{
					((Portal*)mMaps[mCurrentMap]->getUnitManager()->getUnit(0))->startTimer();
				}

				ResetCaelEvent* resetEvent = new ResetCaelEvent(MAP_RIGHT);

				gpGame->getEventSystem()->addEvent(resetEvent);
			}
			break;
		case MAP_UP:
			if (mMaps[mCurrentMap]->getUpMap() != -1)
			{
				mMaps[mCurrentMap]->reset();

				mCurrentMap = mMaps[mCurrentMap]->getUpMap() - 1;

				ResetCaelEvent* resetEvent = new ResetCaelEvent(MAP_UP);

				gpGame->getEventSystem()->addEvent(resetEvent);
			}
			break;
		case MAP_DOWN:
			if (mMaps[mCurrentMap]->getDownMap() != -1)
			{
				mMaps[mCurrentMap]->reset();

				mCurrentMap = mMaps[mCurrentMap]->getDownMap() - 1;

				ResetCaelEvent* resetEvent = new ResetCaelEvent(MAP_DOWN);

				gpGame->getEventSystem()->addEvent(resetEvent);
			}
			break;
		}
	}
}

Map* MapManager::getCurrentMap()
{
	return mMaps[mCurrentMap];
}

Map* MapManager::getMap(int map)
{
	return mMaps[map];
}

void MapManager::setCurrentMap(int mapNum)
{
	mCurrentMap = mapNum - 1;
}

void MapManager::reset()
{
	for (unsigned int i = 0; i <= mMaps.size() - 1; i++)
	{
		mMaps[i]->reset();
	}
}