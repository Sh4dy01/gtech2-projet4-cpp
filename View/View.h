#pragma once

#include "Color.h"

#include <vector>

class Widget;

struct SDL_Renderer;
typedef union SDL_Event;



class View
{
public:

	View();
	~View();

		/// Renders all the widgets in this view.
	void render( SDL_Renderer* r );

		/// Add a widget to this view.
		/// Once added to a view, a widget's ownership is transfered to it, and the view
		///	takes the responsibility of destroying the widget when being deleted.
	void addWidget( Widget* w );

	void setBackgroundColor(unsigned char r, unsigned char g, unsigned char b);

	void handleEvent( const SDL_Event& e );

		/// Returns a pointer to the widget hovered by the mouse cursor.
		/// If the cursor is not hovering any widget, this returns null.
	Widget* getHoveredWidget() const;



private:

	std::vector<Widget*> widgets;
	Widget* hoveredWidget;

	Color backgroundColor;
};
