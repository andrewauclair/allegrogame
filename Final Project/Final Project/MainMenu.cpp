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

#include "MainMenu.h"
#include "Game.h"
#include "ItemsMenu.h"
#include "ChangeLanguageEvent.h"
#include <sstream>
using namespace std;

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
}

void MainMenu::update()
{
	// draw text
	stringstream ss;
	ss << "Cael: ";
	ss << gpGame->getLocalizationSystem()->getText(LEVEL);
	ss << " ";
	ss << gpGame->getLevelManager()->getCurrentLevel().getLevelNum();

	GraphicsSystem* t_pGraphicsSystem = gpGame->getGraphicsSystem();

	gpGame->getGraphicsSystem()->drawText(Point(50, 50), ss.str(), 40, false);
	
	ss.str("");
	ss << "HP: ";
	ss << gpGame->getCael()->getCurrentHP();
	ss << "/";
	ss << gpGame->getLevelManager()->getCurrentLevel().getHP();

	gpGame->getGraphicsSystem()->drawText(Point(80, 140), ss.str(), 40, false);
	
	ss.str("");
	ss << "MP: ";
	ss << gpGame->getCael()->getCurrentMP();
	ss << "/";
	ss << gpGame->getLevelManager()->getCurrentLevel().getMP();

	gpGame->getGraphicsSystem()->drawText(Point(80, 190), ss.str(), 40, false);

	ss.str("");
	ss << "STR: ";
	ss << gpGame->getLevelManager()->getCurrentLevel().getStrength();
	
	gpGame->getGraphicsSystem()->drawText(Point(80, 240), ss.str(), 40, false);

	ss.str("");
	ss << "MA: ";
	ss << gpGame->getLevelManager()->getCurrentLevel().getMagic();

	gpGame->getGraphicsSystem()->drawText(Point(80, 290), ss.str(), 40, false);
	
	ss.str("");
	ss << "DF: ";
	ss << gpGame->getLevelManager()->getCurrentLevel().getDefense();

	gpGame->getGraphicsSystem()->drawText(Point(80, 340), ss.str(), 40, false);

	ss.str("");
	ss << gpGame->getLocalizationSystem()->getText(TOTAL_EXP);
	ss << " ";
	ss << gpGame->getCael()->getExperience();

	gpGame->getGraphicsSystem()->drawText(Point(80, 390), ss.str(), 40, false);

	ss.str("");
	ss << "EXP ";
	ss << gpGame->getLocalizationSystem()->getText(NEXT);
	ss << " Lvl: ";

	if (gpGame->getLevelManager()->getCurrentLevel().getLevelNum() >= 50)
	{
		ss << "0";
	}
	else
	{
		ss << gpGame->getLevelManager()->getCurrentLevel().getEXP() - gpGame->getCael()->getExperience();
	}

	gpGame->getGraphicsSystem()->drawText(Point(80, 440), ss.str(), 40, false);
}