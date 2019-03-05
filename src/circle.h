#pragma once

#include "fcolor.h"
#include "cycloid.h"

class Circle : public Cycloid
{
//private:
	//void GeneratePolygonVertices(SimpleVertex* vertices, int sides, float radius, float centerX, float centerY, int arrayOffset);

public:

	Circle(double,
		double,
		double,
		int,
		FloatColor*,
		ID3D11Device*,
		D3D11_BUFFER_DESC&,
		D3D11_SUBRESOURCE_DATA&);

	~Circle();
	//void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
};