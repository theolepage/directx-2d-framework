#pragma once
#include <list>
#include "entity.h"
#include "bush.h"
#include "quad.h"



class Tree :
	public Entity
{
private:
	std::list<Bush*> leaves;
	std::list<S2DLine*> branches;
	void addBranch(double, double, double);
	FloatColor *trunkColor;
	double size;
public:
	Tree(double, double, double);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, VS_CONSTANT_BUFFER&, ID3D11Buffer*, UINT*, UINT*);
};