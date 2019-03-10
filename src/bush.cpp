#include <iostream>
#include "bush.h"

Bush::Bush(double x, double y, double radius,int maxFlower,FloatColor* flowerInner, FloatColor* flowerOuter)
{
	maxFlower = (int)((((double)rand() / (RAND_MAX)) + 1) * maxFlower);
	for (int i = 0; i < maxFlower; i++) {
		flowers.push_back(new Flower(x + getPos(radius), y + getPos(radius), radius / 3, flowerInner, flowerOuter));
	}
	body = new S2DCycloid(x, y, radius, 200,
		getRandomLeafColor(),
		[](int i) {return true; },
		[](float i) {return (abs(cos(i * 5.0f)) > 0.8) ? abs(cos(i * 5.0f)) : abs(sin(i * 5.0f)); });
}

Bush::Bush(double x, double y, double radius, int maxFlower)
{
	maxFlower = (int)(((double)rand() / (RAND_MAX)) + 1) * maxFlower;

	for (int i = 0; i < maxFlower; i++) {
		flowers.push_back(new Flower(x + getPos(radius), y + getPos(radius), radius / 3, new FloatColor(0xffdb00), new FloatColor(rand() % 255, rand() % 150, rand() % 255)));
	}
	body = new S2DCycloid(x, y, radius, 200,
		getRandomLeafColor(),
		[](int i) {return true; },
		[](float i) {return (abs(cos(i * 5.0f)) > 0.8) ? abs(cos(i * 5.0f)) : abs(sin(i * 5.0f)); });
}

Bush::Bush(double x, double y, double radius) : Bush(x, y, radius, (int)(radius * 10.0)){}

double Bush::getPos(double radius)
{
	double pos = (((double)rand() / (RAND_MAX)) + 1) * radius / 3.0;

	if (rand() % 100 >= 50) {
		return pos;
	}
	else {
		return -pos;
	}
}

FloatColor* Bush::getRandomLeafColor()
{
	int green = rand() % 200 + 55;
	int red = rand() % ((green / 3) != 0) ? (green / 3) : 1;
	int blue = rand() % ((green / 3) != 0) ? (green / 3) : 1;

	return new FloatColor(red, green, blue);
}

void Bush::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	for (auto const& i : flowers) {
		i->Register(g_pd3dDevice, bd, InitData);
	}
	body->Register(g_pd3dDevice, bd, InitData);
}

void Bush::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	body->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	for (auto const& i : flowers) {
		i->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	}
}

Bush::~Bush()
{
}
