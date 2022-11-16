#pragma once

#include "Widget.h"

#include <string>

struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;



class Text : public Widget
{
public:

	Text();
	~Text();

	std::string inline GetText() { return text; };
	void setIsUnderline();

		/// Set the text to be displayed by this widget.
	void setText(const char* text);

		/// Set an optional font to override the global font of the widget's owning view.
	void setFont(TTF_Font* font);

	virtual void render(SDL_Renderer*) override;

	virtual void onAddToView(View* v) override;

private:

	void regenerateSDLTexture();



private:

	bool isUnderline = false;

	std::string text;
	SDL_Texture* texture;

	TTF_Font* font;
};
