#pragma once

#include "fcolor.h"
#include "shape.h"

class Circle : public Shape
{
public:

	Circle(double x,
		double y,
		double r,
		int res,
		FloatColor* color,
		ID3D11Device* g_pd3dDevice,
		D3D11_BUFFER_DESC& bd,
		D3D11_SUBRESOURCE_DATA& InitData);

	~Circle();

	void GeneratePolygonVertices(SimpleVertex* vertices, int sides, float radius, float centerX, float centerY, int arrayOffset);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
};