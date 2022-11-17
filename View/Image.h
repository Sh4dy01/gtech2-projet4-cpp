#pragma once

#include "Widget.h"

struct SDL_Texture;
struct SDL_Surface;



	/// Image widget.
class Image : public Widget
{
	friend class View;

public:

	Image(const char* path);
	~Image();

	virtual void render(SDL_Renderer* r) override;
	SDL_Surface* loadSurface(const char* path);

	virtual void onAddToView(View* v) override;

	/*virtual void onMouseHover() override;
	virtual void onMouseUnhover() override;
	virtual void onMouseClick() override;*/

	void setOnClickCallback(void (*c)()) { onClickCallback = c; }



private:

	const char* path;
	SDL_Texture* labelTexture;

	void (*onClickCallback)();
};
