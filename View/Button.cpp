#include "Button.h"

#include <SDL.h>



Button::Button(const char* label)
	: label( label ), onClickCallback( 0 )
{

}

void Button::render( SDL_Renderer* r )
{
	const int BORDER_SIZE = 1;

	// Draw a border.
	SDL_Rect rect = { this->posX, this->posY, this->width, this->height };

	if ( this->isMouseHovering() )
		SDL_SetRenderDrawColor(r, 0, 127, 255, 0xFF);
	else
		SDL_SetRenderDrawColor(r, 80, 80, 80, 0xFF);
	SDL_RenderFillRect(r, &rect);

	// Draw the inside of the button.
	rect.x += BORDER_SIZE;
	rect.y += BORDER_SIZE;
	rect.w -= BORDER_SIZE * 2;
	rect.h -= BORDER_SIZE * 2;

	SDL_SetRenderDrawColor(r, color.getR(), color.getG(), color.getB(), 0xFF);
	SDL_RenderFillRect(r, &rect);

	// TODO : render text.
}

void Button::onMouseHover()
{
	
}

void Button::onMouseUnhover()
{
	this->setColor(255, 255, 255);
}

void Button::onMouseClick()
{
	this->setColor(220, 220, 220);

	if (this->onClickCallback)
		this->onClickCallback();
}
