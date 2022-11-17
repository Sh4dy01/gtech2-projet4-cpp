#pragma once

#include "Widget.h"

#include <string>

struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;



	/// A button.
	/// Buttons are represented by a rectangle, and an optional label.
	///	Upon being clicking, the button can issue a callback set by the user.
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

		/// Set this button's callback.
		/// Additionally, a user-defined parameter can be passed to the callback.
	void setOnClickCallback(void (*c)()) { onClickCallback = (void (*)(int)) c; callbackUserData = 0; }
	void setOnClickCallback(void (*c)(int), int userdata) { onClickCallback = c; callbackUserData = userdata; }



private:

	std::string label;
	SDL_Texture* labelTexture;

		/// Font override.
	TTF_Font* font;

		/// Callback function pointer and userdata.
	void (*onClickCallback)(int);
	int callbackUserData;
};
