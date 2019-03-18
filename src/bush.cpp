#include <iostream>
#include "bush.h"

Bush::Bush(double x, double y, double radius,int maxFlower,FloatColor* flowerInner, FloatColor* flowerOuter)
{
	this->x = x;
	this->y = y;

	// Set the number of flowers
	maxFlower = (int)((((double)rand() / (RAND_MAX)) + 1) * maxFlower);
	
	// Add the flowers to the bush
	for (int i = 0; i < maxFlower; i++) {
		flowers.push_back(new Flower(x + getPos(radius), y + getPos(radius), radius / 3, flowerInner, flowerOuter));
	}

	// Create the body of the bush
	body = new S2DCycloid(x, y, radius, 200,
		getRandomLeafColor(),
		[](int i) {return true; },
		[](float i) {return (abs(cos(i * 5.0f)) > 0.8) ? abs(cos(i * 5.0f)) : abs(sin(i * 5.0f)); });
}

Bush::Bush(double x, double y, double radius, int maxFlower)
{
	this->x = x;
	this->y = y;

	// Set the number of flowers
	maxFlower = (int)(((double)rand() / (RAND_MAX)) + 1) * maxFlower;

	// Add the flowers to the bush
	for (int i = 0; i < maxFlower; i++) {
		flowers.push_back(new Flower(x + getPos(radius), y + getPos(radius), radius / 3, new FloatColor(0xffdb00), new FloatColor(rand() % 255, rand() % 150, rand() % 255)));
	}

	// Create the body of the bush
	body = new S2DCycloid(x, y, radius, 200,
		getRandomLeafColor(),
		[](int i) {return true; },
		[](float i) {return (abs(cos(i * 5.0f)) > 0.8) ? abs(cos(i * 5.0f)) : abs(sin(i * 5.0f)); });
}

Bush::Bush(double x, double y, double radius) : Bush(x, y, radius, (int)(radius * 10.0)){}

//--------------------------------------------------------------------------------------
// Get a random position inside the body of the bush
//--------------------------------------------------------------------------------------
double Bush::getPos(double radius)
{
	double pos = (((double)rand() / (RAND_MAX)) + 1) * radius / 3.0;

	// Chosing wether the position will be negative or positive
	if (rand() % 100 >= 50) {
		return pos;
	}
	else {
		return -pos;
	}
}

//--------------------------------------------------------------------------------------
// Get a random greenish color
//--------------------------------------------------------------------------------------
FloatColor* Bush::getRandomLeafColor()
{
	int green = rand() % 200 + 55;

	// We use a ternary operator to avoid division by 0
	int red = rand() % ((green / 3) != 0) ? (green / 3) : 1;
	int blue = rand() % ((green / 3) != 0) ? (green / 3) : 1;

	return new FloatColor(red, green, blue);
}

//--------------------------------------------------------------------------------------
// Register all components of the bush (Flowers and body)
//--------------------------------------------------------------------------------------
void Bush::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	for (auto const& i : flowers) {
		i->Register(g_pd3dDevice, bd, InitData);
	}
	body->Register(g_pd3dDevice, bd, InitData);
}

//--------------------------------------------------------------------------------------
// Render all components of the bush in the correct order (flowers should appear above)
//--------------------------------------------------------------------------------------
void Bush::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	body->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	for (auto const& i : flowers) {
		i->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	}
}
