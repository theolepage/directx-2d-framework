#include "flower.h"

Flower::Flower(double x, double y, double radius, double innerRadius, FloatColor* heartColor, FloatColor* petalColor)
{
	petals = new S2DCycloid(x, y, radius, 200, petalColor, [](int i) {return true; }, [](float i) {return abs(cos(i * 10.0f)); });
	heart = new S2DCircle(x, y, innerRadius, 100, heartColor);

}

Flower::Flower(double x, double y, double radius, FloatColor* heartColor, FloatColor* petalColor) :
	Flower(x, y, radius, radius / 4.0f,heartColor, petalColor)
{
}

void Flower::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	petals->Register(g_pd3dDevice, bd, InitData);
	heart->Register(g_pd3dDevice, bd, InitData);
}


Flower::~Flower()
{
}


void Flower::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	petals->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	heart->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
}