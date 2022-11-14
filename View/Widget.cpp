#include "Widget.h"

#include "View.h"

#include <SDL.h>



Widget::Widget()
	: posX( 0 ), posY( 0 ), width( 100 ), height( 100 )
	, color( 0xFF, 0xFF, 0xFF )
{

}

bool Widget::isMouseHovering() const
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (x >= this->posX && x <= this->posX + this->width) {
		if (y >= this->posY && y <= this->posY + this->height) {
			return true;
		}
	}
	return false;
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

void Widget::setHorizontallyCentered()
{
	if (!this->view) {
		return;
	}

	this->posX = (view->getWidth() - this->width) / 2;
}
