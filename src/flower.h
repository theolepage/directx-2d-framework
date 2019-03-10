#pragma once
#include <cmath>
#include "entity.h"
#include "cycloid.h"

class Flower :
	public Entity
{
private:
	S2DCycloid *petals;
	S2DCircle *heart;
public:
	Flower(double, double, double, double, FloatColor*, FloatColor*);
	Flower(double, double, double, FloatColor*, FloatColor*);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	~Flower();
};

