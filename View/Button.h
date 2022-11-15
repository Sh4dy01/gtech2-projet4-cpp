#pragma once

#include "Widget.h"

#include <string>

struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;



class Button : public Widget
{
	friend class View;

public:

	Button( const char* label = "" );
	~Button();

		/// Set an optional font to override the global font of the widget's owning view.
	void setFont(TTF_Font* font);

	virtual void render(SDL_Renderer* r) override;

	virtual void onAddToView(View* v) override;

	virtual void onMouseHover() override;
	virtual void onMouseUnhover() override;
	virtual void onMouseClick() override;

	void setOnClickCallback(void (*c)()) { onClickCallback = c; }



private:

	std::string label;
	SDL_Texture* labelTexture;

	TTF_Font* font;

	void (*onClickCallback)();
};
