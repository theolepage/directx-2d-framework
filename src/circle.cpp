#define _USE_MATH_DEFINES

#include <math.h>
#include "circle.h"

Circle::Circle(double x,
	double y,
	double radius,
	int res,
	FloatColor* color,
	ID3D11Device* g_pd3dDevice,
	D3D11_BUFFER_DESC& bd,
	D3D11_SUBRESOURCE_DATA& InitData) : Cycloid(x, y, radius, res, color, [](int i) {return true; }, g_pd3dDevice, bd, InitData)
{
}


Circle::~Circle() {}