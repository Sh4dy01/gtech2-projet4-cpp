#include "Text.h"

#include "View.h"

#include <SDL.h>
#include <SDL_ttf.h>



Text::Text()
	: texture(0), font(0)
{
	
}

Text::~Text()
{
	if (texture) {
		SDL_DestroyTexture(texture);
	}
}

void Text::setIsUnderline() {
	this->isUnderline = true;
}

void Text::setText(const char* text)
{
	this->text = text;
	this->regenerateSDLTexture();
}

void Text::setFont(TTF_Font* font)
{
	this->font = font;
	this->regenerateSDLTexture();
}

void Text::render(SDL_Renderer* renderer)
{
	if (texture) {
		// Copy the texture to the target.
		SDL_Rect dest;
		dest.x = this->getPositionX();
		dest.y = this->getPositionY();

		SDL_QueryTexture(texture, 0, 0, &dest.w, &dest.h);

		SDL_RenderCopy(renderer, texture, 0, &dest);
	}

	// Render a line below the text's rectangle.
	if (isUnderline) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawLine(renderer, posX,posY+height,posX+width,posY+height);
	}
}

void Text::onAddToView(View* v)
{
	this->regenerateSDLTexture();
}

void Text::regenerateSDLTexture()
{
	// Text does not belong to a view yet, so we cannot proceed.
	if (!this->view) {
		return;
	}

	// Destroy old texture.
	if (texture) {
		SDL_DestroyTexture(texture);
		texture = 0;
	}

	// If text is not empty.
	if (!text.empty()) {

		TTF_Font* usedFont = this->font;
		if (!usedFont) {
			// use global font if no override has been specified.
			usedFont = this->view->getFont();
		}

		SDL_Color color = { this->color.getR(), this->color.getG(), this->color.getB(), 0xFF };
		SDL_Surface* temp = TTF_RenderText_Blended(usedFont, text.c_str(), color);

		texture = SDL_CreateTextureFromSurface(this->view->getSDLRenderer(), temp);

		SDL_FreeSurface(temp);

		// Update size.
		SDL_QueryTexture(texture, 0, 0, &this->width, &this->height);
	}
}
