#pragma once
#include "shape.h"

class Cycloid :
	public Shape
{
private:
	void GeneratePolygonVertices(SimpleVertex* vertices, int sides, float radius, float centerX, float centerY, int arrayOffset, bool(*expr)(int));
public:
	Cycloid(double x,
		double y,
		double r,
		int res,
		FloatColor* color,
		bool(*expr)(int),
		ID3D11Device* g_pd3dDevice,
		D3D11_BUFFER_DESC& bd,
		D3D11_SUBRESOURCE_DATA& InitData);
	
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	~Cycloid();
};

