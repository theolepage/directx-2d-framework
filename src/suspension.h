#pragma once
#include <list>
#include "entity.h"
#include "quad.h"

class Suspension :
	public Entity
{
private:
	std::list <S2DQuad*> quads;
	S2DRectangle *main, *second;
public:
	Suspension(double, double, double, double, int, FloatColor*, FloatColor*, FloatColor*);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	void setPos(double, double);
	~Suspension() {}
};

