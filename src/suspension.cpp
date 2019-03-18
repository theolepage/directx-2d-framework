#include "suspension.h"

Suspension::Suspension(double x, double y, double width, double height, int number, FloatColor* primaryColor, FloatColor* secondColor, FloatColor* thirdColor)
{
	double left = x - width / 2.0, right = x + width / 2.0;

	// Add quads above
	double startY = y - height * number;
	for (int i = 0; i < number; i++) {
		quads.push_back(new S2DQuad(
			right, startY + 2 * height,
			left, startY + height,
			right, startY + height,
			left, startY,
			thirdColor));
		startY += 2 * height;
	}

	main = new S2DRectangle(x, y + number / 2 * height, width / 2, (number + 3) * height, primaryColor);
	second = new S2DRectangle(x, y - number / 2 * height, width / 3, (number + 3) * height, secondColor);
}

void Suspension::setPos(double x, double y) {
	for (auto const& i : quads) {
		i->x = x;
		i->y = y;
	}
	main->x = x;
	main->y = y;
	second->x = x;
	second->y = y;
}

//--------------------------------------------------------------------------------------
// Register all components of the wheel.
//--------------------------------------------------------------------------------------
void Suspension::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	for (auto const& i : quads) {
		i->Register(g_pd3dDevice, bd, InitData);
	}
	main->Register(g_pd3dDevice, bd, InitData);
	second->Register(g_pd3dDevice, bd, InitData);
}

//--------------------------------------------------------------------------------------
// Render all components of the car in the correct order.
//--------------------------------------------------------------------------------------
void Suspension::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	second->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	main->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	for (auto const& i : quads) {
		i->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	}
}
