#pragma once

#include "Color.h"

// Forward declarations.
struct SDL_Renderer;
typedef union SDL_Event;



class Widget
{
public:

	Widget();

	virtual void render( SDL_Renderer* r );

	void handleEvent( const SDL_Event& e );

		/// Get the position of this widget in pixels relative to the window.
	int getPositionX() const { return posX; }
	int getPositionY() const { return posY; }

		/// Get the dimensions of this widget in pixels.
	int getWidth() const { return width; }
	int getHeight() const { return height; }

	void setPosition( int x, int y );
	void setSize( int w, int h );
	void setColor( unsigned char r, unsigned char g, unsigned char b );



private:

		/// Position & dimensions of this widget, in pixels.
		/// The position is relative to the window, (0; 0) being the top-left corner.
	int posX;
	int posY;
	int width;
	int height;

		/// The background color of this widget.
	Color color;
};
