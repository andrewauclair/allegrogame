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

#include "GraphicsSystem.h"
#include <iostream>
using namespace std;

GraphicsSystem::GraphicsSystem()
{
}

GraphicsSystem::~GraphicsSystem()
{
	destroy_bitmap(mBackBuffer);
}

void GraphicsSystem::init()
{
	

	cout << "Initialized Graphics System" << endl;

	// show screen
	set_color_depth(32);
	
	mBackBuffer = create_bitmap(WIDTH, HEIGHT);

	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, WIDTH, HEIGHT, 0, 0) != 0)
	{
		if (set_gfx_mode(GFX_SAFE, 640, 480, 0, 0) != 0)
		{
			set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
			allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
		}
	}
	
	int num = 0;

	set_display_switch_mode(SWITCH_BACKGROUND);

	mScreen = screen;

	install_mouse();
	disable_hardware_cursor();
	scare_mouse();
}

void GraphicsSystem::draw(Point loc, BITMAP* image, bool masked)
{
	if (masked)
	{
		masked_blit(image, mBackBuffer, 0, 0, loc.getX(), loc.getY(), image->w, image->h);
	}
	else
	{
		blit(image, mBackBuffer, 0, 0, loc.getX(), loc.getY(), image->w, image->h);
	}
}

void GraphicsSystem::drawText(Point loc, const string& text, int size, bool centered, int width)
{
	 BITMAP *tmp;
	   
	 size = size / 12;

	 tmp = create_bitmap( text_length(font, text.c_str()), text_height(font));
	    
	 clear_to_color( tmp , makecol( 255 , 0 , 255 ) );
	 textout_ex( tmp, font, text.c_str(), 0, 0, makecol(255, 255, 255), -1) ;
	   
	 if (centered)
	 {
		masked_stretch_blit(tmp, mBackBuffer, 0, 0, tmp->w, tmp->h, (width / 2 - (tmp->w * size)/2) + loc.getX(), loc.getY(), (int)(tmp->w * size), (int)(tmp->h * size)); 
	 }
	 else
	 {
		 masked_stretch_blit(tmp, mBackBuffer, 0, 0, tmp->w, tmp->h, loc.getX(), loc.getY(), (int)(tmp->w * size), (int)(tmp->h * size));
	 }
	   
	 destroy_bitmap( tmp );
}

int GraphicsSystem::getPixelWidthOfText(const std::string& text, int size)
{
	size = size / 12;

	int width = text_length(font, text.c_str());

	return width * size;
}

void GraphicsSystem::swap()
{
	acquire_screen();

	blit(mBackBuffer, mScreen, 0, 0, 0, 0, WIDTH, HEIGHT);

	release_screen();
}