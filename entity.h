#pragma once

#include "simple_vertex.h"
#include "constant_buffer.h"


class Entity
{
protected:
	double x, y;
public:
	Entity() {}
	virtual ~Entity() {}
	virtual void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*) = 0;
};