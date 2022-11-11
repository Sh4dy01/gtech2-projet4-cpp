#pragma once

#include "Color.h"

// Forward declarations.
struct SDL_Renderer;
typedef union SDL_Event;



class Widget
{
public:

	Widget();

		/// Is the mouse cursor positioned over this widget?
	bool isMouseHovering() const;

		/// Get the position of this widget in pixels relative to the window.
	int getPositionX() const { return posX; }
	int getPositionY() const { return posY; }

		/// Get the dimensions of this widget in pixels.
	int getWidth() const { return width; }
	int getHeight() const { return height; }

	void setPosition( int x, int y );
	void setSize( int w, int h );
	void setColor( unsigned char r, unsigned char g, unsigned char b );



		/// Render this widget using a given SDL renderer.
		/// Each widget type implements its own rendering method.
	virtual void render(SDL_Renderer* r) = 0;

	virtual void onMouseHover() { }
	virtual void onMouseUnhover() { }
	virtual void onMouseClick() { }



protected:

		/// Position & dimensions of this widget, in pixels.
		/// The position is relative to the window, (0; 0) being the top-left corner.

		/// default = (0; 0)
	int posX;
	int posY;

		/// default = (100; 100)
	int width;
	int height;

		/// The background color of this widget.
		/// default = 0xFFFFFF (white)
	Color color;
};
