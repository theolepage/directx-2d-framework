#include "shape.h"

void Shape::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset) {
	VsConstData.color_R = color->r;
	VsConstData.color_G = color->g;
	VsConstData.color_B = color->b;
	VsConstData.pos_X = 0;
	g_pImmediateContext->UpdateSubresource(g_pConstantBuffer, 0, 0, &VsConstData, 0, 0);
	g_pImmediateContext->IASetVertexBuffers(0, 1, &g_pVertexBuffer, stride, offset);
	g_pImmediateContext->Draw(n_vertices, 0);
}