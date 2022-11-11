#include "bib.h"
#include <SDL.h>
#include <SDL_ttf.h>

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

TTF_Font * regFont = NULL;
TTF_Font * boldFont = NULL;
TTF_Font * lightFont = NULL;

void InitSDL() {
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
	}

	//Create window
	window = SDL_CreateWindow("Bib.io", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
	}

	//Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
	}

	if (TTF_Init() == -1) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
	};

	//Create fonts
	regFont = TTF_OpenFont("Libs/Fonts/Comfortaa-Regular.ttf", 32);
	if (regFont == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
	}
	boldFont = TTF_OpenFont("Libs/Fonts/Comfortaa-Bold.ttf", 32);
	if (boldFont == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
	}
	lightFont = TTF_OpenFont("Libs/Fonts/Comfortaa-Light.ttf", 32);
	if (lightFont == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
	}

}

int main(int argc, char* args[])
{
	InitSDL();

	SDL_Event e;
	SDL_bool IsAppRuning = SDL_TRUE;

	while (IsAppRuning) {
		while (SDL_PollEvent(&e)) { 
			switch (e.type) {
				case SDL_QUIT:
					IsAppRuning = SDL_FALSE;
					break;
			}
		} 
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	TTF_CloseFont(regFont);
	TTF_CloseFont(boldFont);
	TTF_CloseFont(lightFont);

	SDL_Quit();

	return 0;
}
