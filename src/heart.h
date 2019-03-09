#pragma once
#include "entity.h"
#include "cycloid.h"
#include "quad.h"

class Heart :
	public Entity
{
private:
	S2DQuad* spike;
	S2DCycloid* round;
public:
	Heart(double, double, double, FloatColor*);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
};

