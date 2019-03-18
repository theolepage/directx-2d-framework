#include "car.h"


Car::Car(double x, double y)
{
	this->x = x;
	this->y = y;
	frontWheel = new Wheel(x + 0.5, y, 0.2);
	rearWheel = new Wheel(x -0.5, y, 0.2);

	frontSus = new Suspension(x + 0.5, y + 0.13, 0.1, 0.017, 7, new FloatColor(0x383838), new FloatColor(0xadadad), new FloatColor(0x262e84));
	rearSus = new Suspension(x - 0.5, y + 0.13, 0.1, 0.017, 7, new FloatColor(0x383838), new FloatColor(0xadadad), new FloatColor(0x262e84));

	frontWheelFender = new ArchPanel(x + 0.5, y + 0.02, 0.25, 0.3, new FloatColor(0x0f0f0f), new FloatColor(0xcc0000));
	rearWheelFender = new ArchPanel(x - 0.5, y + 0.02, 0.25, 0.3, new FloatColor(0x0f0f0f), new FloatColor(0xcc0000));

	fender = new Fender(x, y, new FloatColor(0xFF0000), new FloatColor(0xcc0000));
	setPos(x, y);
}

//--------------------------------------------------------------------------------------
// Set the posisiton for all inner components.
//--------------------------------------------------------------------------------------
#define AMP 0.025
#define CYCL 5
void Car::setPos(double x, double y) {
	this->x = x;
	this->y = y;

	frontWheel->setPos(x, y);
	rearWheel->setPos(x, y);

	frontSus->setPos(x, y + sin(x * CYCL) * AMP);
	rearSus->setPos(x, y + sin(x * CYCL) * AMP);

	frontWheelFender->setPos(x, y + sin(x * CYCL) * AMP);
	rearWheelFender->setPos(x, y + sin(x * CYCL) * AMP);

	fender->setPos(x, y + sin(x * CYCL) * AMP);
}

//--------------------------------------------------------------------------------------
// Register all components of the wheel.
//--------------------------------------------------------------------------------------
void Car::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	frontWheel->Register(g_pd3dDevice, bd, InitData);
	rearWheel->Register(g_pd3dDevice, bd, InitData);

	frontSus->Register(g_pd3dDevice, bd, InitData);
	rearSus->Register(g_pd3dDevice, bd, InitData);

	frontWheelFender->Register(g_pd3dDevice, bd, InitData);
	rearWheelFender->Register(g_pd3dDevice, bd, InitData);

	fender->Register(g_pd3dDevice, bd, InitData);
}

//--------------------------------------------------------------------------------------
// Render all components of the car in the correct order.
//--------------------------------------------------------------------------------------
void Car::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	fender->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);

	frontWheelFender->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	rearWheelFender->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);

	rearSus->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	frontSus->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);

	frontWheel->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	rearWheel->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
}

ArchPanel::ArchPanel(double x, double y, double innerRadius, double outerRadius, FloatColor *innerColor, FloatColor *outerColor)
{
	inner = new S2DCycloid(x, y, innerRadius, 100, innerColor, [](int i) { return true; }, [](float i) {return (i > 3 * 1.57079632679 || i < 1.57079632679) ? 1.0f : 0.0f; });
	outer = new S2DCycloid(x, y, outerRadius, 100, outerColor, [](int i) { return true; }, [](float i) {return (i > 3 * 1.57079632679 || i < 1.57079632679) ? 1.0f : 0.0f; });
}

//--------------------------------------------------------------------------------------
// Set the posisiton for all inner components.
//--------------------------------------------------------------------------------------
void ArchPanel::setPos(double x, double y) {
	inner->x = x;
	inner->y = y;
	outer->x = x;
	outer->y = y;
}

//--------------------------------------------------------------------------------------
// Register all components of the archpanel.
//--------------------------------------------------------------------------------------
void ArchPanel::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	inner->Register(g_pd3dDevice, bd, InitData);
	outer->Register(g_pd3dDevice, bd, InitData);
}

//--------------------------------------------------------------------------------------
// Render all components of the archpanel in the correct order.
//--------------------------------------------------------------------------------------
void ArchPanel::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	outer->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	inner->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
}

Fender::Fender(double x, double y, FloatColor *primary, FloatColor* second)
{
	windshield = new S2DLine(x + 0.5, y + 0.3, x + 0.15, y + 0.65, 0.1, primary);
	roof = new S2DRectangle(x + 0.04, y + 0.65, 0.4, 0.03, second);
	underRoof = new S2DRectangle(x + 0.04, y + 0.62, 0.35, 0.03, primary);
	tailCabin = new S2DRectangle(x - 0.05, y + 0.525, 0.2, 0.25, primary);
	tailEdge = new S2DRectangle(x - 0.51, y + 0.4, 0.75, 0.05, second);
	rockerPanel = new S2DRectangle(x, y + 0.1, 1.75, 0.05, second);
	mainBody = new S2DRectangle(x, y + 0.25, 1.7, 0.3, primary);
	radiator = new S2DRectangle(x + 0.85, y + 0.25, 0.04, 0.2, new FloatColor(0x8c8c8c));
}

void Fender::setPos(double x, double y)
{
	tailCabin->x = x;
	tailCabin->y = y;

	rockerPanel->x = x;
	rockerPanel->y = y;
	
	mainBody->x = x;
	mainBody->y = y;
	
	tailEdge->x = x;
	tailEdge->y = y;

	radiator->x = x;
	radiator->y = y;

	roof->x = x;
	roof->y = y;

	underRoof->x = x;
	underRoof->y = y;

	windshield->x = x;
	windshield->y = y;
}

//--------------------------------------------------------------------------------------
// Register all components of the fender.
//--------------------------------------------------------------------------------------
void Fender::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	tailCabin->Register(g_pd3dDevice, bd, InitData);
	mainBody->Register(g_pd3dDevice, bd, InitData);
	rockerPanel->Register(g_pd3dDevice, bd, InitData);
	tailEdge->Register(g_pd3dDevice, bd, InitData);
	radiator->Register(g_pd3dDevice, bd, InitData);
	roof->Register(g_pd3dDevice, bd, InitData);
	underRoof->Register(g_pd3dDevice, bd, InitData);
	windshield->Register(g_pd3dDevice, bd, InitData);
}

//--------------------------------------------------------------------------------------
// Render all components of the fender in the correct order.
//--------------------------------------------------------------------------------------
void Fender::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	tailCabin->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	windshield->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	underRoof->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	roof->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	mainBody->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	rockerPanel->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	tailEdge->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	radiator->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
}