#pragma once
#include "entity.h"
#include "cycloid.h"

class Tire :
	public Entity
{
private:
	S2DCircle *outer, *main, *inner;
	S2DCycloid *grip;
public:
	Tire(double, double, double, double, double, double);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	void setPos(double, double);
	~Tire() {}
};

class Rim :
	public Entity
{
private:
	S2DCircle *outer, *under, *inner, *nut;
	S2DCycloid *spokes;
public:
	Rim(double, double, double);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	void setPos(double, double);
	~Rim() {}
};

class Wheel :
	public Entity
{
private:
	Tire *tire;
	Rim *rim;
public:
	Wheel(double, double, double);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	void setPos(double, double);
	~Wheel() {}
};