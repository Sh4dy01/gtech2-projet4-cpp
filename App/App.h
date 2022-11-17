#pragma once

#include <ctime>
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
class Bib;

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;

typedef struct _Mix_Music Mix_Music;
typedef struct Mix_Chunk;
typedef struct _TTF_Font TTF_Font;



	/// Global application structure.
	/// This static class is responsible for initializing the required libraries,
	/// creating the views, and model (application's local data).
class App
{
public:

	static bool initialize();
	static void render();
	static void Update();
	static void HandleTimers();
	static void quit();

	static time_t GetCurrentTime();
	static time_t GetCurrentTime(char* out);
	static inline View* getCurrentView() { return currentView; }
	static inline void setCurrentView(View* v) { currentView = v; }

		/// Is the application running.
	static inline bool isRunning() { return running; }

		/// Tell the application to exit its main loop and close.
	static inline void setShouldClose() { running = false; }

	static inline SDL_Window*   getSDLWindow() { return window; }
	static inline SDL_Renderer* getSDLRenderer() { return renderer; }
	static inline TTF_Font*     getSDLDefaultFont() { return regFont; }
	static inline TTF_Font*     GetTitleFont() { return titleFont; }
	static inline TTF_Font*     getSmallFont() { return smallFont; }
	static inline TTF_Font*     getSmallLightFont() { return smallLightFont; }
	static inline TTF_Font*     getLightFont() { return lightFont; }
	static inline TTF_Font*     getBoldFont() { return boldFont; }

	static inline Mix_Chunk*     GetAhhhhh() { return ahhhhh; }

	static inline View* getViewMainMenu() { return viewMainMenu; }
	static inline View* getViewMeal() { return viewMeal; }
	static inline View* getViewShoppingList() { return viewShoppingList; }
	static inline View* getViewSettings() { return viewSettings; }

	static inline Bib* GetBibi() { return bib; }

private:

	static float frameTime;
	static int prevTime;
	static int currentTime;
	static float deltaTime;

		/// SDL stuff.
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static Mix_Chunk* ahhhhh;

	static TTF_Font* regFont;
	static TTF_Font* boldFont;
	static TTF_Font* lightFont;
	static TTF_Font* titleFont;
	static TTF_Font* smallFont;
	static TTF_Font* smallLightFont;

		/// Views.
	static View* currentView;

	static View* viewMainMenu;
	static View* viewMeal;
	static View* viewShoppingList;
	static View* viewSettings;

		/// Running flag.
	static bool running;

	//BIBI
	static Bib* bib;
};
