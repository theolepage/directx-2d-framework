#include <cmath>
#include "fcolor.h"

const FloatColor FloatColor::Black(0, 0, 0);
const FloatColor FloatColor::White(255, 255, 255);
const FloatColor FloatColor::LightGray(192, 192, 192);
const FloatColor FloatColor::Gray(128, 128, 128);
const FloatColor FloatColor::DarkGray(64, 64, 64);
const FloatColor FloatColor::Red(255, 0, 0);
const FloatColor FloatColor::Pink(255, 175, 175);
const FloatColor FloatColor::Orange(255, 200, 0);
const FloatColor FloatColor::Yellow(255, 255, 0);
const FloatColor FloatColor::Green(0, 255, 0);
const FloatColor FloatColor::Magenta(255, 0, 255);
const FloatColor FloatColor::Cyan(0, 255, 255);
const FloatColor FloatColor::Blue(0, 0, 255);

FloatColor::FloatColor(float r, float g, float b)
{
		this->r = r;
		this->g = g;
		this->b = b;
}

FloatColor::FloatColor(int r, int g, int b)
{
	this->r = r / 255.0f;
	this->g = g / 255.0f;
	this->b = b / 255.0f;
}

FloatColor::FloatColor(int rgb) {
	this->r = ((rgb & 0xFF0000) >> 16) / 255.0;
	this->g = ((rgb & 0xFF00) >> 8) / 255.0;
	this->b = (rgb & 0xFF) / 255.0;
}

int FloatColor::toRGB() const
{
	return ((255 * (int)r) << 16) | ((255 * (int)g) << 8) | (255 * (int)b);
}

FloatColor::~FloatColor() {}