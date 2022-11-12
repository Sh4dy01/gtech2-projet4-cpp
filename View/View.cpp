#include "View.h"

#include "Widget.h"

#include <SDL.h>



View::View()
	: hoveredWidget( 0 ), font( 0 )
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
	SDL_SetRenderDrawColor( r, backgroundColor.getR(), backgroundColor.getG(), backgroundColor.getB(), 0xFF);
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
	w->view = this;
}

void View::setBackgroundColor(unsigned char r, unsigned char g, unsigned char b)
{
	backgroundColor = Color(r, g, b);
}

void View::handleEvent( const SDL_Event& e )
{
	switch (e.type) {
	// Mouse down event.
	case SDL_MOUSEBUTTONDOWN:
		{
			Widget* w = this->getHoveredWidget();
			if (w) {
				w->onMouseClick();
			}
		}
		break;

	// Mouse move event.
	case SDL_MOUSEMOTION:
		{
			Widget* w = this->getHoveredWidget();

			// Mouse hover mechanic (Proceed to switch).
			if (this->hoveredWidget != w) {
				if (this->hoveredWidget) {
					this->hoveredWidget->onMouseUnhover();
				}

				this->hoveredWidget = w;

				if (this->hoveredWidget) {
					this->hoveredWidget->onMouseHover();
				}
			}
		}
		break;
	}
}

Widget* View::getHoveredWidget() const
{
	for (Widget* w : widgets) {
		if (w->isMouseHovering()) {
			return w;
		}
	}
	return 0;
}
