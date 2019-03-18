#pragma once
#include "entity.h"
#include "wheel.h"
#include "suspension.h"

class ArchPanel :
	public Entity
{
private:
	S2DCycloid *inner, *outer;
public:
	ArchPanel(double, double, double, double, FloatColor*, FloatColor*);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	void setPos(double, double);
	~ArchPanel() {}
};

class Fender :
	public Entity
{
private:
	S2DRectangle *rockerPanel, *mainBody, *tailEdge, *radiator, *tailCabin, *roof, *underRoof;
	S2DLine *windshield;
public:
	Fender(double, double, FloatColor*, FloatColor*);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	void setPos(double, double);
	~Fender() {}
};

class Car :
	public Entity
{
private:
	Wheel *frontWheel, *rearWheel;
	Suspension *frontSus, *rearSus;
	ArchPanel *frontWheelFender, *rearWheelFender;
	Fender *fender;
public:
	Car(double, double);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
	void setPos(double, double);
	~Car() {}
};

