#pragma once

#include "Widget.h"

#include <string>

struct SDL_Texture;



class Text : public Widget
{
public:

	Text();
	~Text();

	virtual void render(SDL_Renderer*) override;

	void setText(const char* text);



private:

	std::string text;
	SDL_Texture* texture;
};
