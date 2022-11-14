#include "bib.h"
#include <SDL.h>
#include <SDL_ttf.h>

#include <iostream>

#include "View/View.h"
#include "View/Widget.h"
#include "View/Button.h"
#include "View/Text.h"



SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

TTF_Font * regFont = NULL;
TTF_Font * boldFont = NULL;
TTF_Font * lightFont = NULL;

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
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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



void onBtnExit()
{
	IsAppRuning = false;
}

int main(int argc, char* args[])
{
	InitSDL();

	// View test.
	View* view = new View(window, renderer);
	view->setBackgroundColor(240, 240, 240);
	view->setFont(regFont);
	{
		Button* button = new Button("Exit");
		button->setPosition( 10, 30 );
		button->setSize( 80, 20 );
		button->setOnClickCallback(onBtnExit);
		view->addWidget(button);
		button->setHorizontallyCentered();

		Button* button0 = new Button("Press Me!");
		button0->setPosition(10, 60);
		button0->setSize(80, 20);
		button0->setOnClickCallback([]() {
			std::cout << "I have been pressed!" << std::endl;
		});
		view->addWidget(button0);

		Text* title = new Text();
		title->setPosition(10, 10);
		title->setColor(0, 127, 127);
		title->setText("Bib.io");
		view->addWidget(title);
		title->setHorizontallyCentered();
	}

	SDL_Event e;
	while (IsAppRuning) {

		view->render();

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				IsAppRuning = false;
			else
				view->handleEvent(e);
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	TTF_CloseFont(regFont);
	TTF_CloseFont(boldFont);
	TTF_CloseFont(lightFont);

	SDL_Quit();

	delete view;

	return 0;
}
