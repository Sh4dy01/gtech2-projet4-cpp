#pragma once

#include "Widget.h"

#include <string>



class Rect : public Widget
{
	friend class View;

public:

	virtual void render(SDL_Renderer* r) override;

	/*virtual void onAddToView(View* v) override;*/

	/*virtual void onMouseHover() override;
	virtual void onMouseUnhover() override;
	virtual void onMouseClick() override;*/

	/*void setOnClickCallback(void (*c)()) { onClickCallback = c; }*/
};
