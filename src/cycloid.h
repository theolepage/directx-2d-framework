#pragma once
#include "shape.h"

class S2DCycloid :
	public Shape
{
private:
	void GeneratePolygonVertices(SimpleVertex* vertices, int sides, float radius, float centerX, float centerY, int arrayOffset, bool(*expr)(int));
public:
	S2DCycloid(double,
		double,
		double,
		int,
		FloatColor*,
		bool(*)(int),
		ID3D11Device*,
		D3D11_BUFFER_DESC&,
		D3D11_SUBRESOURCE_DATA&);
	~S2DCycloid();
};


class S2DCircle : public S2DCycloid
{
public:

	S2DCircle(double,
		double,
		double,
		int,
		FloatColor*,
		ID3D11Device*,
		D3D11_BUFFER_DESC&,
		D3D11_SUBRESOURCE_DATA&);

	~S2DCircle();
};

