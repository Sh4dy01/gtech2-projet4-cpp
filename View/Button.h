#pragma once

#include "Widget.h"

#include <string>

struct SDL_Texture;



class Button : public Widget
{
	friend class View;

public:

	Button( const char* label = "" );
	~Button();

	virtual void render(SDL_Renderer* r) override;

	virtual void onMouseHover() override;
	virtual void onMouseUnhover() override;
	virtual void onMouseClick() override;

	void setOnClickCallback(void (*c)()) { onClickCallback = c; }



private:

	std::string label;
	SDL_Texture* labelTexture;

	void (*onClickCallback)();
};
