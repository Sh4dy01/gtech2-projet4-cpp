#pragma once

#include "Widget.h"

#include <string>

struct SDL_Texture;
struct SDL_Surface;


class Image : public Widget
{
	friend class View;

public:

	Image(std::string path);
	~Image();

	virtual void render(SDL_Renderer* r) override;
	SDL_Surface* loadSurface(std::string path);

	virtual void onAddToView(View* v) override;

	/*virtual void onMouseHover() override;
	virtual void onMouseUnhover() override;
	virtual void onMouseClick() override;*/

	void setOnClickCallback(void (*c)()) { onClickCallback = c; }



private:

	std::string label;
	SDL_Texture* labelTexture;

	void (*onClickCallback)();
};
