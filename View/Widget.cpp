#include "Widget.h"

#include <SDL.h>



Widget::Widget()
	: posX( 0 ), posY( 0 ), width( 100 ), height( 100 )
	, color( 0xFF, 0xFF, 0xFF )
{

}

void Widget::setPosition( int x, int y )
{
	this->posX = x;
	this->posY = y;
}

void Widget::setSize( int w, int h )
{
	this->width = w;
	this->height = h;
}

void Widget::setColor( unsigned char r, unsigned char g, unsigned char b )
{
	this->color = Color( r, g, b );
}

void Widget::render( SDL_Renderer* r )
{
	SDL_Rect rect = { this->posX, this->posY, this->width, this->height };

	SDL_SetRenderDrawColor( r, color.getR(), color.getG(), color.getB(), 0xFF );
	SDL_RenderFillRect( r, &rect );
}

void Widget::handleEvent( const SDL_Event& e )
{
	if ( e.type == SDL_MOUSEBUTTONDOWN ) {

		int x, y;
		SDL_GetMouseState( &x, &y );

		if ( x >= this->posX && x <= this->posX + this->width ) {
			if ( y >= this->posY && y <= this->posY + this->height ) {

			}
		}
	}
}
