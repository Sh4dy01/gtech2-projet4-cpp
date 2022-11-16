#pragma once

#include "Widget.h"

#include <string>

struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;



class InputText : public Widget
{
public:

	InputText( int maxNumChars = 32 );
	~InputText();

		/// Get the contents of this text box.
	inline const char* getText() const { return text.c_str(); }

		/// Set the contents of this text box.
		/// This replaces all existing text!
	void setText( const char* text );

	void setPlaceholder(const char* text);

		/// Set a font to override the owning view's global font.
	void setFont(TTF_Font* f);



private:

	void regenerateTexture();

	virtual void render(SDL_Renderer* r) override;

	virtual void onAddToView(View* v) override;
	virtual void onMouseClick() override;
	virtual void onTextInput(char c) override;

private:

	std::string text;
	std::string placeholder;

	int maxNumChars;

	SDL_Texture* texture;
	TTF_Font* font;
};
