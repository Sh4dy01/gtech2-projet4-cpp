#include "App/App.h"
#include "bib.h"

#include "App/View/MainMenuView.h"
#include "App/View/MealView.h"
#include "App/View/ShoppingListView.h"
#include "App/View/SettingsView.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>


int App::currentTime = 0;
float App::frameTime = 0;
int App::prevTime = 0;
float App::deltaTime = 0;

Bib* App::bib = 0;

SDL_Window* App::window = 0;
SDL_Renderer* App::renderer = 0;
TTF_Font* App::regFont = 0;
TTF_Font* App::boldFont = 0;
TTF_Font* App::lightFont = 0;
TTF_Font* App::titleFont = 0;
TTF_Font* App::smallFont = 0;
TTF_Font* App::smallLightFont = 0;

Mix_Chunk* App::ahhhhh = 0;

View* App::currentView = 0;

View* App::viewMainMenu = 0;
View* App::viewMeal = 0;
View* App::viewShoppingList = 0;
View* App::viewSettings = 0;

bool App::running = false;



bool App::initialize()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
		return false;
	}

	//Create window
	window = SDL_CreateWindow("Bib.i", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
		return false;
	}

	//Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
		return false;
	}

	if (TTF_Init() == -1) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
	};

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", Mix_GetError());
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", IMG_GetError());
	}

	//Create fonts
	{
		regFont = TTF_OpenFont("Assets/Fonts/Comfortaa-Regular.ttf", 32);
		if (regFont == NULL)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
		}
		boldFont = TTF_OpenFont("Assets/Fonts/Comfortaa-Bold.ttf", 32);
		if (boldFont == NULL)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
		}
		lightFont = TTF_OpenFont("Assets/Fonts/Comfortaa-Light.ttf", 24);
		if (lightFont == NULL)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
		}
		titleFont = TTF_OpenFont("Assets/Fonts/Comfortaa-Bold.ttf", 24);
		if (titleFont == NULL)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
		}
		smallFont = TTF_OpenFont("Assets/Fonts/Comfortaa-Bold.ttf", 22);
		if (smallFont == NULL)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
		}
		smallLightFont = TTF_OpenFont("Assets/Fonts/Comfortaa-Light.ttf", 16);
		if (smallLightFont == NULL)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
		}
	}

	ahhhhh = Mix_LoadWAV("Assets/AUUGHHH.wav");
	if (ahhhhh == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", Mix_GetError());
	}

	bib = new Bib();

	// Create views.
	viewMainMenu     = new MainMenuView();
	viewMeal         = new MealView();
	viewShoppingList = new ShoppingListView();
	viewSettings     = new SettingsView();

	currentView = viewMainMenu;

	running = true;

	// Load saved settings.
	bib->loadSettings();

	return true;
}

void App::render()
{
	// Adjust rendering space to stretch to window.
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	SDL_RenderSetScale(renderer, w / (float) RENDER_WIDTH, h / (float) RENDER_HEIGHT);

	currentView->render();
}

void App::Update()
{
	prevTime = currentTime;
	currentTime = SDL_GetTicks();
	deltaTime = (currentTime - prevTime) / 1000.0f;
}

void App::HandleTimers()
{
	frameTime += deltaTime;

	//Update the necessary objects in the current view every second
	if (frameTime >= 1.0f)
	{
		frameTime = 0;
		App::getCurrentView()->update();
	}
}

time_t App::GetCurrentTime() {

	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	return rawtime;
}

time_t App::GetCurrentTime(char* out) {

	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(out, 30, "%D - %T", timeinfo);

	std::cout << out << std::endl;

	return rawtime;
}

void App::quit()
{
	running = false;

	// Save settings!
	bib->saveSettings();
	delete bib;

	// Free views.
	delete viewMainMenu;
	delete viewMeal;
	delete viewShoppingList;
	delete viewSettings;

	// Free fonts.
	TTF_CloseFont(regFont);
	TTF_CloseFont(boldFont);
	TTF_CloseFont(lightFont);
	TTF_CloseFont(titleFont);
	TTF_CloseFont(smallFont);
	TTF_CloseFont(smallLightFont);

	Mix_FreeChunk(ahhhhh);

	// Quit SDL.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
