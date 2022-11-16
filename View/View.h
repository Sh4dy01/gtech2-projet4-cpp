#pragma once

#include "Color.h"

#include <vector>

class Widget;

struct SDL_Window;
struct SDL_Renderer;
typedef union SDL_Event;

struct _TTF_Font;
typedef _TTF_Font TTF_Font;



class View
{
public:

	View( SDL_Window* window, SDL_Renderer* re );
	~View();

		/// Renders all the widgets in this view.
	void render();
	virtual void update();

		/// Add a widget to this view.
		/// Once added to a view, a widget's ownership is transfered to it, and the view
		///	takes the responsibility of destroying the widget when being deleted.
	void addWidget( Widget* w );

	void setBackgroundColor(unsigned char r, unsigned char g, unsigned char b);

	void handleEvent( const SDL_Event& e );

	Widget* getFocusedWidget() const { return focusedWidget; }
	void    setFocusedWidget(Widget* w) { focusedWidget = w; }

		/// Returns a pointer to the widget hovered by the mouse cursor.
		/// If the cursor is not hovering any widget, this returns null.
	Widget* getHoveredWidget() const;

		/// Get the mouse cursor's position relative to render space.
		/// This method takes into account the window resizing and scaling.
		/// Use this instead of SDL_GetMouseState().
	void getMousePos(int* x, int* y) const;

	int getWidth() const;
	int getHeight() const;

	TTF_Font* getFont() const { return font; }
	void setFont(TTF_Font* f) { font = f; }

	SDL_Renderer* getSDLRenderer() const { return renderer; }



private:

	std::vector<Widget*> widgets;
	Widget* focusedWidget;
	Widget* hoveredWidget;

	Color backgroundColor;

	SDL_Window* window;
	SDL_Renderer* renderer;

	TTF_Font* font;
};
