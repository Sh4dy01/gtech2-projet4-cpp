#pragma once

#include "Widget.h"

#include <string>



class Button : public Widget
{
public:

	Button( const char* label = "");

	virtual void render(SDL_Renderer* r) override;

	virtual void onMouseHover() override;
	virtual void onMouseUnhover() override;
	virtual void onMouseClick() override;

	void setOnClickCallback(void (*c)()) { onClickCallback = c; }



private:

	std::string label;

	void (*onClickCallback)();
};
