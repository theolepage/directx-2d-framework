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
	D3D11_SUBRESOURCE_DATA& InitData)
{
	this->color = color;

	n_vertices = res * 3;

	vertices = new SimpleVertex[n_vertices];

	//TODO: Make a proper circle declaration

	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * n_vertices;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	g_pd3dDevice->CreateBuffer(&bd, &InitData, &g_pVertexBuffer);
}


Circle::~Circle() {}

void Circle::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset) {
	VsConstData.color_R = color->r;
	VsConstData.color_G = color->g;
	VsConstData.color_B = color->b;
	g_pImmediateContext->UpdateSubresource(g_pConstantBuffer, 0, 0, &VsConstData, 0, 0);
	g_pImmediateContext->IASetVertexBuffers(0, 1, &g_pVertexBuffer, stride, offset);
	g_pImmediateContext->Draw(n_vertices, 0);
}