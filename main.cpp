#include <SDL.h>
#include <SDL_ttf.h>

#include <iostream>

#include "App/App.h"
#include "App/bib.h"

#include "View/View.h"
#include "View/Widget.h"
#include "View/Button.h"
#include "View/Text.h"



int main(int argc, char* args[])
{
	//SDL_TimerID updateDate = SDL_AddTimer(1000, );

	App::initialize();

	SDL_Event e;
	while (App::isRunning()) {

		App::render();
		App::Update();
		
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				App::setShouldClose();
			}
			else {
				App::getCurrentView()->handleEvent(e);
			}
		}

		App::HandleTimers();
	}

	App::quit();

	return 0;
}
