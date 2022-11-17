#pragma once



	/// Color utility.
	/// This class stores an RGB color in a 32-bits integer.
class Color
{
public:

		/// Initializes color to black.
	Color();

	Color( unsigned char r, unsigned char g, unsigned char b );

	unsigned int getRGBA() const { return rgba; }

	unsigned char getR() const { return r; }
	unsigned char getG() const { return g; }
	unsigned char getB() const { return b; }



private:

		/// Color data.
		/// RGBA must be inverted for little-endian memory.
	union {
		unsigned int rgba;
		struct {
			unsigned char a;
			unsigned char b;
			unsigned char g;
			unsigned char r;
		};
	};
};
