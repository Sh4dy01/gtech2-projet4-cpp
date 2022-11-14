#include "Button.h"

#include "View.h"

#include <SDL.h>
#include <SDL_ttf.h>



Button::Button(const char* label)
	: label( label ), onClickCallback( 0 )
	, labelTexture( 0 )
{
	
}

Button::~Button()
{
	if (this->labelTexture) {
		SDL_DestroyTexture(this->labelTexture);
	}
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

	// Render text.
	if (this->label.size() > 0) {

		if (!this->labelTexture) {
			SDL_Surface* temp = TTF_RenderText_Blended(this->view->getFont(), this->label.c_str(), { 0, 0, 0, 255 });
			this->labelTexture = SDL_CreateTextureFromSurface(r, temp);
			SDL_FreeSurface(temp);
		}

		rect.y += 3;
		rect.x += 2;
		SDL_QueryTexture(this->labelTexture, NULL, NULL, &rect.w, &rect.h);
		SDL_RenderCopy(r, this->labelTexture, 0, &rect);
	}
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
