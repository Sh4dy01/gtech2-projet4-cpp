#include "InputText.h"

#include "View.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include <chrono>



InputText::InputText(int maxNumChars)
	: texture(0), font(0), maxNumChars(maxNumChars)
{

}

InputText::~InputText()
{
	if (this->texture) {
		SDL_DestroyTexture(this->texture);
	}
}

void InputText::setText(const char* text)
{
	this->text = text;
	this->regenerateTexture();
}

void InputText::setFont(TTF_Font* f)
{
	this->font = f;
	this->regenerateTexture();
}

void InputText::regenerateTexture()
{
	// Destroy old texture.
	if (this->texture) {
		SDL_DestroyTexture(this->texture);
		this->texture = 0;
	}

	// If there is text and widget belongs to a view.
	if (!this->text.empty() && this->view) {

		// Determine used font.
		TTF_Font* usedFont = this->font;
		if (!usedFont) {
			usedFont = this->view->getFont();
		}

		SDL_Surface* s = TTF_RenderText_Blended(usedFont, this->text.c_str(), { 0, 0, 0, 255 });
		this->texture = SDL_CreateTextureFromSurface(this->view->getSDLRenderer(), s);
		SDL_FreeSurface(s);
	}
}

void InputText::render(SDL_Renderer* r)
{
	SDL_Rect dest = { this->posX, this->posY, this->width, this->height };

	// Render background.
	SDL_SetRenderDrawColor(this->view->getSDLRenderer(), this->color.getR(), this->color.getG(), this->color.getB(), 255);
	SDL_RenderFillRect(this->view->getSDLRenderer(), &dest );

	// Render text texture.
	if (this->texture) {
		SDL_QueryTexture(this->texture, 0, 0, &dest.w, &dest.h);
		SDL_RenderCopy(r, this->texture, 0, &dest);
	}
	else {
		dest.w = 0;
	}

	// Render cursor IF focused!
	if (this == this->view->getFocusedWidget()) {

		// Blink cursor every 0.5 seconds.
		auto now = std::chrono::high_resolution_clock::now();
		unsigned long long millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
		if ((millis % 1000) >= 500) {
			int x = dest.x + dest.w + 2;

			SDL_SetRenderDrawColor(this->view->getSDLRenderer(), 0, 0, 0, 255);
			SDL_RenderDrawLine(this->view->getSDLRenderer(), x, dest.y + 2, x, dest.y + this->height - 3);
		}
	}
}

void InputText::onAddToView(View* v)
{
	this->regenerateTexture();
}

void InputText::onMouseClick()
{
	// Catch focus when clicked on.
	this->setFocused();

	SDL_StartTextInput();
}

void InputText::onTextInput(char c)
{
	// Backspace.
	if (c == 8) {

		// Check if text is not empty first!
		if (!this->text.empty()) {
			this->text.pop_back();
		}
	}

	// Any other printable character.
	else if ( isprint(c) ) {

		if (this->text.size() < this->maxNumChars) {
			this->text += c;
		}
	}

	this->regenerateTexture();
}
