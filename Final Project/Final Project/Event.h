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

#ifndef EVENT_H
#define EVENT_H

enum EVENT_TYPE
{
	INVALID_EVENT_TYPE = -1,
	QUIT_EVENT,
	MOVE_EVENT,
	CHANGE_MAP_EVENT,
	RESET_CAEL_EVENT,
	BATTLE_EVENT,
	END_BATTLE_EVENT,
	PAUSE_EVENT,
	MENU_UP_EVENT,
	MENU_DOWN_EVENT,
	ENTER_EVENT,
	LEFT_EVENT,
	RIGHT_EVENT,
	CREDITS_EVENT,
	ITEMS_EVENT,
	OPTIONS_EVENT,
	SAVE_EVENT,
	BACK_EVENT,
	USE_POTION_EVENT,
	USE_ETHER_EVENT,
	CHANGE_LANGUAGE_EVENT,
	NEW_GAME_EVENT,
	LOAD_GAME_EVENT,
	SOUND_EVENT,
	LANGUAGES_EVENT,
	DIFFICULTY_EVENT,
	ATTACK_EVENT,
	MAGIC_EVENT,
	GAME_OVER_EVENT,
	END_TURN_EVENT,
	NOP_EVENT
};

class Event
{
public:
	Event( EVENT_TYPE type );
	virtual ~Event();

	EVENT_TYPE getType() const { return mType; };

private:
	EVENT_TYPE mType;

};

class ResetCaelEvent : public Event
{
public:
	ResetCaelEvent(int direction);
	~ResetCaelEvent();

	int getDirection() const { return mDirection; };

private:
	int mDirection;
};

#endif