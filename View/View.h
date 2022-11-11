#pragma once

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

	void handleEvent( const SDL_Event& e );



private:



	std::vector<Widget*> widgets;
};
