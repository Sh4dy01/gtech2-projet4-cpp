#include "Forms.h"

#include "View.h"

#include <SDL.h>



void Rect::render(SDL_Renderer* r)
{
	const int BORDER_SIZE = 1;

	// Draw a border.
	SDL_Rect rect = { this->posX, this->posY, this->width, this->height };

	// Draw the inside of the button.
	rect.x += BORDER_SIZE;
	rect.y += BORDER_SIZE;
	rect.w -= BORDER_SIZE * 2;
	rect.h -= BORDER_SIZE * 2;

	SDL_SetRenderDrawColor(r, color.getR(), color.getG(), color.getB(), 0xFF);
	SDL_RenderFillRect(r, &rect);
}

//void Rect::onAddToView(View* v)
//{
//	// Generate label texture.
//	SDL_Surface* temp = TTF_RenderText_Blended(this->view->getFont(), this->label.c_str(), { 0, 0, 0, 255 });
//	this->labelTexture = SDL_CreateTextureFromSurface(this->view->getSDLRenderer(), temp);
//	SDL_FreeSurface(temp);
//}

//void Button::onMouseHover()
//{
//
//}
//
//void Button::onMouseUnhover()
//{
//	this->setColor(255, 255, 255);
//}
//
//void Button::onMouseClick()
//{
//	this->setColor(220, 220, 220);
//
//	if (this->onClickCallback)
//		this->onClickCallback();
//}
