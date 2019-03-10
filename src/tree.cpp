#include "tree.h"



Tree::Tree(double x, double y, double size)
{

	int randRed = rand() % 255;
	this->trunkColor = new FloatColor(randRed, 0.3 * randRed, 0);
	this->size = size;

	double ny = y + ((((double)rand() / (RAND_MAX)) + 1) * size * 2.5);
	branches.push_back(new S2DLine(x, y, x, ny, size, trunkColor));

	addBranch(x, ny, size);

	if (leaves.size() == 0 && branches.size() <= 3) {
		double nx = branches.back()->x1;
		ny = branches.back()->y1;

		leaves.push_back(new Bush(nx, ny, size * 4));
	}
	
}

void Tree::addBranch(double x, double y, double csize) {
	if (csize > 0.05) {
		if (rand() % 10 < 4) {
			double nSize = 0.9 * csize;//((double)rand() / (RAND_MAX) + (0.5 * size)) * size;
			double ny = y + 0.05 + (((double)rand() / (RAND_MAX)) * csize * 1.5);
			double nx = x;
			branches.push_back(new S2DLine(x, y, nx, ny, nSize, trunkColor));
			if(rand() % 3 < 1)
				leaves.push_back(new Bush(nx, ny, 0.01 / csize));
			addBranch(nx, ny, nSize);
		}
		if (rand() % 10 < 6) {
			double nSize = 0.9 * csize;
			double ny = y + 0.05 + (((double)rand() / (RAND_MAX)) * csize * 1.5);
			double nx = x + ((double)rand() / (RAND_MAX)) / 3.0;
			branches.push_back(new S2DLine(x, y, nx, ny, nSize, trunkColor));
			if (rand() % 3 < 1)
				leaves.push_back(new Bush(nx, ny, 0.01 / csize));
			addBranch(nx, ny, nSize);
		}
		if (rand() % 10 < 6) {
			double nSize = 0.9 * csize;
			double ny = y + 0.05 + (((double)rand() / (RAND_MAX)) * csize * 1.5);
			double nx = x - ((double)rand() / (RAND_MAX)) / 3.0;
			branches.push_back(new S2DLine(x, y, nx, ny, nSize, trunkColor));
			if (rand() % 3 < 1)
				leaves.push_back(new Bush(nx, ny, 0.01 / csize));
			addBranch(nx, ny, nSize);
		}
	}
}

void Tree::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	for (auto const& i : leaves) {
		i->Register(g_pd3dDevice, bd, InitData);
	}
	for (auto const& i : branches) {
		i->Register(g_pd3dDevice, bd, InitData);
	}
}

void Tree::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	for (auto const& i : branches) {
		i->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	}
	for (auto const& i : leaves) {
		i->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	}
}
