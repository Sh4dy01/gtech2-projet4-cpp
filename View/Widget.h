#pragma once

#include "Color.h"

// Forward declarations.
class View;

struct SDL_Renderer;
typedef union SDL_Event;



class Widget
{
	friend class View;

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

		/// Moves the calling widget to be horizontally centered relative to its parent view.
		/// The final position will depend on the size of the view and the size of this widget.
		///	The calling widget must be owned by a view BEFORE calling this method.
	void setHorizontallyCentered();
	void setHorizontallyCentered(int offset);
	void setVerticallyCentered();
	void setVerticallyCentered(int offset);

		/// Set this widget to be focused.
	void setFocused();



		/// Render this widget using a given SDL renderer.
		/// Each widget type implements its own rendering method.
	virtual void render(SDL_Renderer* r) = 0;

	virtual void onAddToView(View* w) { }

	virtual void onMouseHover() { }
	virtual void onMouseUnhover() { }
	virtual void onMouseClick() { }

	virtual void onTextInput(char c) { }



protected:

		/// The view owning this widget.
	View* view;

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
