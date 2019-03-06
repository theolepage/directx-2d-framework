#include <cmath>
#include "fcolor.h"

FloatColor::FloatColor(float r, float g, float b)
{
	if (std::floor(r) == r && std::floor(g) == g && std::floor(b) == b) {
		this->r = r / 255;
		this->g = g / 255;
		this->b = b / 255;
	}
	else {
		this->r = r;
		this->g = g;
		this->b = b;
	}
}

FloatColor::FloatColor(int rgb) {
	this->r = ((rgb & 0xFF0000) >> 16) / 255.0;
	this->g = ((rgb & 0xFF00) >> 8) / 255.0;
	this->b = (rgb & 0xFF) / 255.0;
}

FloatColor::~FloatColor() {}