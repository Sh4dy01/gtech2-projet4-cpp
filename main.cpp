#include "bib.h"
#include <SDL.h>
#include <SDL_ttf.h>

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;
TTF_Font * font = NULL;

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

	font = TTF_OpenFont("ARIAL.TTF", 32);
	if (font == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
	}

}

int main(int argc, char* args[])
{
	InitSDL();

	SDL_Event e;
	bool IsAppRuning = true;

	while (IsAppRuning) {
		while (SDL_PollEvent(&e)) { 
			if (e.type == SDL_QUIT) IsAppRuning = false;



		} 
	}

	return 0;
}
