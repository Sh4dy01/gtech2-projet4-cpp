#pragma once

#include <string>

// Default size of window.
#define WINDOW_WIDTH  480
#define WINDOW_HEIGHT 900

// Size of render target.
#define RENDER_WIDTH  480
#define RENDER_HEIGHT 900

// Size of buttons.
#define BUTTON_WIDTH 400
#define BUTTON_HEIGHT 50

// Forward declarations.
class View;

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;

typedef struct _TTF_Font TTF_Font;



class App
{
public:

	static bool initialize();
	static void render();
	static void quit();

	static inline View* getCurrentView() { return currentView; }
	static inline void setCurrentView(View* v) { currentView = v; }

		/// Is the application running.
	static inline bool isRunning() { return running; }

		/// Tell the application to exit its main loop and close.
	static inline void setShouldClose() { running = false; }

	static inline SDL_Window*   getSDLWindow() { return window; }
	static inline SDL_Renderer* getSDLRenderer() { return renderer; }
	static inline TTF_Font*     getSDLDefaultFont() { return regFont; }
	static inline TTF_Font*     getSmallFont() { return smallFont; }

	static inline View* getViewMainMenu() { return viewMainMenu; }
	static inline View* getViewMeal() { return viewMeal; }
	static inline View* getViewShoppingList() { return viewShoppingList; }
	static inline View* getViewSettings() { return viewSettings; }

private:

		/// SDL stuff.
	static SDL_Window* window;
	static SDL_Renderer* renderer;

	static TTF_Font* regFont;
	static TTF_Font* boldFont;
	static TTF_Font* lightFont;
	static TTF_Font* smallFont;


		/// Views.
	static View* currentView;

	static View* viewMainMenu;
	static View* viewMeal;
	static View* viewShoppingList;
	static View* viewSettings;

		/// Running flag.
	static bool running;

};
