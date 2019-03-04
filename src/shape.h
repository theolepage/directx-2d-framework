#pragma once

#include "fcolor.h"
#include "entity.h"

class Shape : public Entity
{
protected:
	int n_vertices;
	FloatColor *color;
	SimpleVertex *vertices;
	ID3D11Buffer* g_pVertexBuffer;

public:
	Shape() {}
	virtual ~Shape() {}
	virtual void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*) = 0;
};