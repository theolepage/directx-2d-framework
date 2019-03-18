#include "wheel.h"

Wheel::Wheel(double x, double y, double radius)
{
	this->x = x;
	this->y = y;
	tire = new Tire(x, y, radius, radius * 0.96, 0.90 * radius, 0.6 * radius);
	rim = new Rim(x, y, 0.5 * radius);
}

//--------------------------------------------------------------------------------------
// Set the posisiton for all inner components.
//--------------------------------------------------------------------------------------
void Wheel::setPos(double x, double y) {
	tire->setPos(x, y);
	rim->setPos(x, y);
}

//--------------------------------------------------------------------------------------
// Register all components of the wheel.
//--------------------------------------------------------------------------------------
void Wheel::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	tire->Register(g_pd3dDevice, bd, InitData);
	rim->Register(g_pd3dDevice, bd, InitData);
}

//--------------------------------------------------------------------------------------
// Render all components of the wheel in the correct order (rim should be above).
//--------------------------------------------------------------------------------------
void Wheel::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	tire->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	rim->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
}


Tire::Tire(double x, double y, double gripRadius,double externalRadius, double mainRadius, double innerRadius) {
	this->x = x;
	this->y = y;
	grip = new S2DCycloid(x, y, gripRadius, 100, new FloatColor(0x2d2d2d), [](int i) { return i % 9 != 0; }, [](float i) {return 1.0f; });
	outer = new S2DCircle(x, y, externalRadius, 100, new FloatColor(0x2d2d2d));
	main = new S2DCircle(x, y, mainRadius, 100, new FloatColor(0x1c1c1c));
	inner = new S2DCircle(x, y, innerRadius, 80, new FloatColor(0x151515));
}

//--------------------------------------------------------------------------------------
// Set the posisiton for all inner components.
//--------------------------------------------------------------------------------------
void Tire::setPos(double x, double y) {
	grip->x = x;
	grip->y = y;
	outer->x = x;
	outer->y = y;
	main->x = x;
	main->y = y;
	inner->x = x;
	inner->y = y;
}

//--------------------------------------------------------------------------------------
// Register all components of the tire.
//--------------------------------------------------------------------------------------
void Tire::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	grip->Register(g_pd3dDevice, bd, InitData);
	outer->Register(g_pd3dDevice, bd, InitData);
	main->Register(g_pd3dDevice, bd, InitData);
	inner->Register(g_pd3dDevice, bd, InitData);
}

//--------------------------------------------------------------------------------------
// Render all components of the tire in the correct order.
//--------------------------------------------------------------------------------------
void Tire::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	grip->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	outer->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	main->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	inner->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
}

Rim::Rim(double x, double y, double radius)
{
	this->x = x;
	this->y = y;

	FloatColor *dark = new FloatColor(0x404040);
	FloatColor *light = new FloatColor(0x777777);

	outer = new S2DCircle(x, y, radius, 100, light);
	under = new S2DCircle(x, y, 0.9 * radius, 90, dark);
	inner = new S2DCircle(x, y, 0.3 * radius, 80, new FloatColor(0x7b7b7b));
	nut = new S2DCircle(x, y, 0.1 * radius, 8, new FloatColor(0x606060));
	spokes = new S2DCycloid(x, y, 0.92 * radius, 16, light, [](int i) {return i % 2 == 0; }, [](float i) { return 1.0f; });
}

//--------------------------------------------------------------------------------------
// Set the posisiton for all inner components.
//--------------------------------------------------------------------------------------
void Rim::setPos(double x, double y) {

	outer->x = x;
	outer->y = y;
	under->x = x;
	under->y = y;
	spokes->x = x;
	spokes->y = y;
	inner->x = x;
	inner->y = y;
	nut->x = x;
	nut->y = y;
}

//--------------------------------------------------------------------------------------
// Register all components of the rim.
//--------------------------------------------------------------------------------------
void Rim::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	outer->Register(g_pd3dDevice, bd, InitData);
	under->Register(g_pd3dDevice, bd, InitData);
	inner->Register(g_pd3dDevice, bd, InitData);
	spokes->Register(g_pd3dDevice, bd, InitData);
	nut->Register(g_pd3dDevice, bd, InitData);
}

//--------------------------------------------------------------------------------------
// Render all components of the rim in the correct order.
//--------------------------------------------------------------------------------------
void Rim::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	outer->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	under->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	spokes->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	inner->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	nut->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
}