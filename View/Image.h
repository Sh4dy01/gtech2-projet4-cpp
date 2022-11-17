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
	virtual void onMouseClick() override;

	/*virtual void onMouseHover() override;
	virtual void onMouseUnhover() override;*/

	void setOnClickCallback(void (*c)()) { onClickCallback = (void (*)(int)) c; callbackUserData = 0; }
	void setOnClickCallback(void (*c)(int), int userdata) { onClickCallback = c; callbackUserData = userdata; }



private:

	const char* path;
	SDL_Texture* labelTexture;

	void (*onClickCallback)(int);
	int callbackUserData;
};
