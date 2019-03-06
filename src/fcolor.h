#pragma once

class FloatColor
{
public:
	float r, g, b;
	FloatColor(float, float, float);
	FloatColor(int, int, int);
	FloatColor(int);
	~FloatColor();
	int toRGB() const;

	static const FloatColor Black,
		White,
		LightGray,
		Gray,
		DarkGray,
		Red,
		Pink,
		Orange,
		Yellow,
		Green,
		Magenta,
		Cyan,
		Blue;
};