#include "View.h"

#include "Widget.h"

#include <SDL.h>



View::View()
{

}

View::~View()
{
	for ( Widget* w : widgets ) {
		delete w;
	}
}

void View::render( SDL_Renderer* r )
{
	// Clear screen.
	SDL_SetRenderDrawColor( r, 0, 0, 0, 0xFF );
	SDL_RenderClear( r );

	// Render widgets.
	for ( Widget* w : widgets ) {
		w->render( r );
	}

	// Present.
	SDL_RenderPresent( r );
}

void View::addWidget( Widget* w )
{
	widgets.push_back( w );
}

void View::handleEvent( const SDL_Event& e )
{

}
