#include "Image.h"
#include "App/App.h"

#include "View.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>

Image::Image(const char* path)
	: path(path), onClickCallback(0)
	, labelTexture(0)
{

}

Image::~Image()
{
	if (this->labelTexture) {
		SDL_DestroyTexture(this->labelTexture);
	}
}

void Image::render(SDL_Renderer* r)
{
	SDL_Rect rect = { this->posX, this->posY, this->width, this->height };
	SDL_RenderCopy(r, this->labelTexture, NULL, &rect);
}

void Image::onAddToView(View* v)
{
	// Generate label texture.
	SDL_Surface* temp = IMG_Load(path);
	if (temp == NULL) {
		std::cout << "Error loading image: " << IMG_GetError();
		App::setShouldClose();
	}

	if (this->width == 100 || this->height == 100)
	{
		this->width = temp->w;
		this->height = temp->h;
	}
	this->labelTexture = SDL_CreateTextureFromSurface(this->view->getSDLRenderer(), temp);
	SDL_FreeSurface(temp);
}

void Image::onMouseClick()
{
	if (this->onClickCallback)
		this->onClickCallback(this->callbackUserData);
}


SDL_Surface* Image::loadSurface(const char* path) {
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, SDL_GetWindowSurface(App::getSDLWindow())->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

//void Image::onMouseHover()
//{
//
//}
//
//void Image::onMouseUnhover()
//{
//	this->setColor(255, 255, 255);
//}
//
//void Image::onMouseClick()
//{
//	this->setColor(220, 220, 220);
//
//	if (this->onClickCallback)
//		this->onClickCallback();
//}
