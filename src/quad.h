#pragma once

#include "shape.h"

class S2DQuad :
	public Shape
{
public:
	S2DQuad(double, double,
		double, double,
		double, double,
		double, double,
		FloatColor*,
		ID3D11Device*,
		D3D11_BUFFER_DESC&,
		D3D11_SUBRESOURCE_DATA&);
	~S2DQuad();
};

class S2DRectangle :
	public S2DQuad
{
public:
	S2DRectangle(double,
		double,
		double,
		double,
		FloatColor*,
		ID3D11Device*,
		D3D11_BUFFER_DESC&,
		D3D11_SUBRESOURCE_DATA&);
	~S2DRectangle();
};

class S2DDiamond :
	public S2DQuad
{
public:
	S2DDiamond(double,
		double,
		double,
		double,
		FloatColor*,
		ID3D11Device*,
		D3D11_BUFFER_DESC&,
		D3D11_SUBRESOURCE_DATA&);
	~S2DDiamond();
};

