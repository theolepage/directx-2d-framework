#include "quad.h"

S2DQuad::S2DQuad(double x1, double y1,
	double x2, double y2,
	double x3, double y3,
	double x4, double y4,
	FloatColor* color)
{
	this->color = color;

	n_vertices = 6;
	vertices = new SimpleVertex[n_vertices];

	vertices[0].Pos = XMFLOAT3(x4, y4, 0);
	vertices[1].Pos = XMFLOAT3(x2, y2, 0);
	vertices[2].Pos = XMFLOAT3(x1, y1, 0);
	vertices[3].Pos = XMFLOAT3(x3, y3, 0);
	vertices[4].Pos = XMFLOAT3(x4, y4, 0);
	vertices[5].Pos = XMFLOAT3(x1, y1, 0);
}

S2DRectangle::S2DRectangle(double x,
	double y,
	double width,
	double height,
	FloatColor* color) : S2DQuad(x - width / 2.0, y - height / 2.0,
											x + width / 2.0, y - height / 2.0,
											x - width / 2.0, y + height / 2.0,
											x + width / 2.0, y + height / 2.0,
											color)
{
}

S2DDiamond::S2DDiamond(double x,
	double y,
	double width,
	double height,
	FloatColor* color) : S2DQuad(x, y - height / 2.0,
											x + width / 2.0, y,
											x - width / 2.0, y,
											x, y + height / 2.0,
											color){}