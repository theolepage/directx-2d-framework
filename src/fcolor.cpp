#include "fcolor.h"

FloatColor::FloatColor(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

FloatColor::FloatColor(int r, int g, int b) : FloatColor(r / 255.0f, g / 255.0f, b / 255.0f) {}

FloatColor::~FloatColor() {}