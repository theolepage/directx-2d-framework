#pragma once
#include "shape.h"



class S2DCycloid :
	public Shape
{
private:
	void GeneratePolygonVertices(SimpleVertex* vertices, int sides, float radius, float centerX, float centerY, int arrayOffset, bool(*expr)(int), float(*radExpr)(float));
public:
	S2DCycloid(double,
		double,
		double,
		int,
		FloatColor*,
		bool(*)(int),
		float(*)(float));
};


class S2DCircle : public S2DCycloid
{
public:

	S2DCircle(double,
		double,
		double,
		int,
		FloatColor*);
};

