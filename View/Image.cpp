#include "Image.h"
#include "App/App.h"

#include "View.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

Image::Image(std::string label)
	: label(label), onClickCallback(0)
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
	
}

void Image::onAddToView(View* v)
{
	// Generate label texture.
	SDL_Surface* temp = TTF_RenderText_Blended(this->view->getFont(), this->label.c_str(), { 0, 0, 0, 255 });
	this->labelTexture = SDL_CreateTextureFromSurface(this->view->getSDLRenderer(), temp);
	SDL_FreeSurface(temp);
}

SDL_Surface* Image::loadSurface(std::string path) {
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, SDL_GetWindowSurface(App::getSDLWindow())->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
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
