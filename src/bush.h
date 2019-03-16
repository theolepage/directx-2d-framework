#pragma once
#include <list>
#include "entity.h"
#include "flower.h"

class Bush :
	public Entity
{
private:
	std::list<Flower*> flowers;
	S2DCycloid *body;
	double getPos(double);
	FloatColor* getRandomLeafColor();
public:
	Bush(double, double, double,int, FloatColor*, FloatColor*);
	Bush(double, double, double, int);
	Bush(double, double, double);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	~Bush() {}
};

