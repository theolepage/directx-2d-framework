#include "fcolor.h"

FloatColor::FloatColor(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

FloatColor::FloatColor(int rgb) {
	this->r = (rgb & 0xFF0000) >> 16;
	this->g = (rgb & 0xFF00) >> 8;
	this->b = rgb & 0xFF;
}

FloatColor::~FloatColor() {}