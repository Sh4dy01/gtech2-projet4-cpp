#include "bib.h"
#include <SDL.h>
#include <SDL_ttf.h>

#include <iostream>

#include "View/View.h"
#include "View/Widget.h"
#include "View/Button.h"


SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;
TTF_Font * font = NULL;

bool IsAppRuning = true;

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



void onBtnExit()
{
	IsAppRuning = false;
}

int main(int argc, char* args[])
{
	InitSDL();

	// View test.
	View* view = new View();
	view->setBackgroundColor(240, 240, 240);
	{
		Button* button = new Button();
		button->setPosition( 10, 20 );
		button->setSize( 80, 20 );
		button->setOnClickCallback(onBtnExit);
		view->addWidget(button);

		Button* button0 = new Button();
		button0->setPosition(10, 50);
		button0->setSize(80, 20);
		button0->setOnClickCallback([]() {
			std::cout << "I have been pressed!" << std::endl;
		});
		view->addWidget(button0);
	}

	SDL_Event e;

	while (IsAppRuning) {

		view->render(renderer );

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				IsAppRuning = false;
			else
				view->handleEvent(e);
		}
	}

	delete view;

	return 0;
}