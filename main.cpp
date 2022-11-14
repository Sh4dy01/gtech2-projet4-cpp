#include "bib.h"
#include <SDL.h>
#include <SDL_ttf.h>

#include <iostream>

#include "App/App.h"

#include "View/View.h"
#include "View/Widget.h"
#include "View/Button.h"
#include "View/Text.h"



int main(int argc, char* args[])
{
	App::initialize();

	SDL_Event e;
	while (App::isRunning()) {

		App::render();

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				App::setShouldClose();
			}
			else {
				App::getCurrentView()->handleEvent(e);
			}
		}
	}

	App::quit();

	return 0;
}
