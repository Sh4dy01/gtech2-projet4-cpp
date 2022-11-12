#include "Text.h"

#include "View.h"

#include <SDL.h>
#include <SDL_ttf.h>



Text::Text()
	: texture(0)
{
	
}

Text::~Text()
{
	if (texture) {
		SDL_DestroyTexture(texture);
	}
}

void Text::render(SDL_Renderer* renderer)
{
	// If text is not empty.
	if (!text.empty()) {
		SDL_Color color = { this->color.getR(), this->color.getG(), this->color.getB(), 0xFF };
		SDL_Surface* temp = TTF_RenderText_Blended(this->view->getFont(), text.c_str(), color);

		texture = SDL_CreateTextureFromSurface(renderer, temp);

		SDL_FreeSurface(temp);
	}

	if (texture) {
		// Copy the texture to the target.
		SDL_Rect dest;
		dest.x = this->getPositionX();
		dest.y = this->getPositionY();

		SDL_QueryTexture(texture, 0, 0, &dest.w, &dest.h);

		SDL_RenderCopy(renderer, texture, 0, &dest);
	}
}

void Text::setText(const char* text)
{
	// Destroy old texture.
	if (texture) {
		SDL_DestroyTexture(texture);
		texture = 0;
	}

	this->text = text;
}
