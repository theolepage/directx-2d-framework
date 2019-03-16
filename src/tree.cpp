#include "tree.h"

Tree::Tree(double x, double y, double size)
{
	// Get a random red color
	int randRed = rand() % 255;
	// Use the red to generate a brown color
	this->trunkColor = new FloatColor(randRed, 0.3 * randRed, 0);
	this->size = size;

	double ny = y + ((((double)rand() / (RAND_MAX)) + 1) * size * 2.5);
	branches.push_back(new S2DLine(x, y, x, ny, size, trunkColor));

	// Add branches above the trunk
	addBranch(x, ny, size);

	// If there is less than 3 branches then we automatically put a leaf on the three
	if (leaves.size() == 0 && branches.size() <= 3) {
		double nx = branches.back()->x1;
		ny = branches.back()->y1;

		leaves.push_back(new Bush(nx, ny, size * 4));
	}
	
}

//--------------------------------------------------------------------------------------
// Add up to three new branch from the specified position
//--------------------------------------------------------------------------------------
void Tree::addBranch(double x, double y, double csize) {
	// Stop condition : the size is too small
	if (csize > 0.05) {
		// Vertical branch
		if (rand() % 10 < 4) {
			double nSize = 0.9 * csize;
			double ny = y + 0.05 + (((double)rand() / (RAND_MAX)) * csize * 1.5);
			double nx = x;
			branches.push_back(new S2DLine(x, y, nx, ny, nSize, trunkColor));
			// Randomly add a leaf
			if(rand() % 3 < 1)
				leaves.push_back(new Bush(nx, ny, 0.01 / csize));
			addBranch(nx, ny, nSize);
		}

		// Right branch
		if (rand() % 10 < 6) {
			double nSize = 0.9 * csize;
			double ny = y + 0.05 + (((double)rand() / (RAND_MAX)) * csize * 1.5);
			double nx = x + ((double)rand() / (RAND_MAX)) / 3.0;
			branches.push_back(new S2DLine(x, y, nx, ny, nSize, trunkColor));
			// Randomly add a leaf
			if (rand() % 3 < 1)
				leaves.push_back(new Bush(nx, ny, 0.01 / csize));
			addBranch(nx, ny, nSize);
		}

		// Left branch
		if (rand() % 10 < 6) {
			double nSize = 0.9 * csize;
			double ny = y + 0.05 + (((double)rand() / (RAND_MAX)) * csize * 1.5);
			double nx = x - ((double)rand() / (RAND_MAX)) / 3.0;
			branches.push_back(new S2DLine(x, y, nx, ny, nSize, trunkColor));
			// Randomly add a leaf
			if (rand() % 3 < 1)
				leaves.push_back(new Bush(nx, ny, 0.01 / csize));
			addBranch(nx, ny, nSize);
		}
	}
}

//--------------------------------------------------------------------------------------
// Register all components of the tree
//--------------------------------------------------------------------------------------
void Tree::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	for (auto const& i : leaves) {
		i->Register(g_pd3dDevice, bd, InitData);
	}
	for (auto const& i : branches) {
		i->Register(g_pd3dDevice, bd, InitData);
	}
}

//--------------------------------------------------------------------------------------
// Render all components of the tree in the correct order (leaves should appear above)
//--------------------------------------------------------------------------------------
void Tree::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	// Render the branches
	for (auto const& i : branches) {
		i->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	}
	// Render the leaves
	for (auto const& i : leaves) {
		i->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	}
}
