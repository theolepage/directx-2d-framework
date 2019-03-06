#include "cycloid.h"

S2DCycloid::S2DCycloid(double x,
	double y,
	double radius,
	int res,
	FloatColor* color,
	bool(*expr)(int),
	ID3D11Device* g_pd3dDevice,
	D3D11_BUFFER_DESC& bd,
	D3D11_SUBRESOURCE_DATA& InitData)
{
	this->color = color;

	n_vertices = res * 3;

	//FIXME: We don't need that much vertices
	vertices = new SimpleVertex[n_vertices];

	GeneratePolygonVertices(vertices, res, radius, x, y, 0, expr);

	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * n_vertices;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	g_pd3dDevice->CreateBuffer(&bd, &InitData, &g_pVertexBuffer);
}

void S2DCycloid::GeneratePolygonVertices(SimpleVertex* vertices, int sides, float radius, float centerX, float centerY, int arrayOffset, bool(*expr)(int))
{
	float PI = 3.14159265358979323846;
	int index = 0;
	float theta = PI / sides;

	XMFLOAT3 last = XMFLOAT3(radius * cos(theta) + centerX, radius * sin(theta) + centerY, 0.5f);

	for (int n = 1; n <= sides; n += 1)
	{

		float x = radius * cos(theta + 2 * PI * n / sides) + centerX;
		float y = radius * sin(theta + 2 * PI * n / sides) + centerY;


		SimpleVertex a = SimpleVertex();
		SimpleVertex b = SimpleVertex();
		SimpleVertex c = SimpleVertex();

		a.Pos = XMFLOAT3(x, y, 0.5f);
		b.Pos = last;
		c.Pos = XMFLOAT3(centerX, centerY, 0.5f);
		last = a.Pos;
		
		if (expr(n)) {
			vertices[arrayOffset + index] = a;
			vertices[arrayOffset + index + 1] = b;
			vertices[arrayOffset + index + 2] = c;
		}
		
		index += 3;
	}
}


S2DCycloid::~S2DCycloid(){}


S2DCircle::S2DCircle(double x,
	double y,
	double radius,
	int res,
	FloatColor* color,
	ID3D11Device* g_pd3dDevice,
	D3D11_BUFFER_DESC& bd,
	D3D11_SUBRESOURCE_DATA& InitData) : S2DCycloid(x, y, radius, res, color, [](int i) {return true; }, g_pd3dDevice, bd, InitData)
{}


S2DCircle::~S2DCircle() {}