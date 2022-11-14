#pragma once

#include "Widget.h"

#include <string>

struct SDL_Texture;



class Text : public Widget
{
public:

	Text();
	~Text();

	void setText(const char* text);

	virtual void render(SDL_Renderer*) override;

	virtual void onAddToView(View* v) override;

private:

	void regenerateSDLTexture();



private:

	std::string text;
	SDL_Texture* texture;
};
