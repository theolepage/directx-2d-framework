#include "quad.h"

S2DQuad::S2DQuad(double x1, double y1,
	double x2, double y2,
	double x3, double y3,
	double x4, double y4,
	FloatColor* color,
	ID3D11Device* g_pd3dDevice,
	D3D11_BUFFER_DESC& bd,
	D3D11_SUBRESOURCE_DATA& InitData)
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

	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * n_vertices;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	g_pd3dDevice->CreateBuffer(&bd, &InitData, &g_pVertexBuffer);
}

S2DQuad::~S2DQuad() {}

S2DRectangle::S2DRectangle(double x,
	double y,
	double width,
	double height,
	FloatColor* color,
	ID3D11Device* g_pd3dDevice,
	D3D11_BUFFER_DESC& bd,
	D3D11_SUBRESOURCE_DATA& InitData) : S2DQuad(x - width / 2.0, y - height / 2.0,
											x + width / 2.0, y - height / 2.0,
											x - width / 2.0, y + height / 2.0,
											x + width / 2.0, y + height / 2.0,
											color, g_pd3dDevice, bd, InitData)
{
}


S2DRectangle::~S2DRectangle(){}

S2DDiamond::S2DDiamond(double x,
	double y,
	double width,
	double height,
	FloatColor* color,
	ID3D11Device* g_pd3dDevice,
	D3D11_BUFFER_DESC& bd,
	D3D11_SUBRESOURCE_DATA& InitData) : S2DQuad(x, y - height / 2.0,
											x + width / 2.0, y,
											x - width / 2.0, y,
											x, y + height / 2.0,
											color, g_pd3dDevice, bd, InitData){}

S2DDiamond::~S2DDiamond(){}