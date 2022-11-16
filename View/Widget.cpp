#include "Widget.h"
#include "View.h"

#include <SDL.h>



Widget::Widget()
	: posX( 0 ), posY( 0 ), width( 100 ), height( 100 ), view(0)
	, color( 0xFF, 0xFF, 0xFF )
{

}

bool Widget::isMouseHovering() const
{
	// Take scaling into account!
	int x, y;
	view->getMousePos(&x, &y);

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

void Widget::setHorizontallyCentered(int offset)
{
	if (!this->view) {
		return;
	}

	this->posX = (view->getWidth() - this->width) / 2 + offset;
}

void Widget::setVerticallyCentered()
{
	if (!this->view) {
		return;
	}

	this->posY = (view->getHeight() - this->height) / 2;
}

void Widget::setVerticallyCentered(int offset)
{
	if (!this->view) {
		return;
	}

	this->posY = (view->getHeight() - this->height) / 2 + offset;
}

void Widget::setFocused()
{
	// Check if this widget is owned first!
	if (this->view) {
		this->view->setFocusedWidget(this);
	}
}
