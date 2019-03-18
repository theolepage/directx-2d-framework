#include "shape.h"

//--------------------------------------------------------------------------------------
// Create the vertex buffer of a shape.
//--------------------------------------------------------------------------------------
void Shape::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * n_vertices;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	g_pd3dDevice->CreateBuffer(&bd, &InitData, &g_pVertexBuffer);
}

//--------------------------------------------------------------------------------------
// Set the colors and render the shape.
//--------------------------------------------------------------------------------------
void Shape::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset) {
	VsConstData.color_R = color->r;
	VsConstData.color_G = color->g;
	VsConstData.color_B = color->b;
	VsConstData.pos_X = x;
	VsConstData.pos_Y = y;
	g_pImmediateContext->UpdateSubresource(g_pConstantBuffer, 0, 0, &VsConstData, 0, 0);
	g_pImmediateContext->IASetVertexBuffers(0, 1, &g_pVertexBuffer, stride, offset);
	g_pImmediateContext->Draw(n_vertices, 0);
}