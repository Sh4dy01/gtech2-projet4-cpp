#include "Color.h"



Color::Color()
	: rgba( 0x000000FF )
{

}

Color::Color( unsigned char r, unsigned char g, unsigned char b )
{
	this->r = r;
	this->g = g;
	this->b = b;
}
