#include "cycloid.h"

S2DCycloid::S2DCycloid(double x,
	double y,
	double radius,
	int res,
	FloatColor* color,
	bool(*expr)(int),
	float(*radExpr)(float))
{
	this->color = color;

	n_vertices = 0;

	/* Counting the space needed */
	for (int i = 0; i <= res; ++i) {
		n_vertices += expr(i) ? 3 : 0;
	}

	vertices = new SimpleVertex[n_vertices];

	GeneratePolygonVertices(vertices, res, radius, x, y, 0, expr, radExpr);
}

void S2DCycloid::GeneratePolygonVertices(SimpleVertex* vertices, int sides, float radius, float centerX, float centerY, int arrayOffset, bool(*expr)(int), float(*radExpr)(float))
{
	float PI = 3.14159265358979323846;
	int index = 0;
	float theta = PI / sides;

	XMFLOAT3 last = XMFLOAT3(radExpr(theta) * radius * cos(theta) + centerX, radExpr(theta) * radius * sin(theta) + centerY, 0.5f);
	for (int n = 1; n <= sides; ++n)
	{	

		float x = radExpr(n * theta) * radius * cos(theta + 2 * PI * n / sides) + centerX;
		float y = radExpr(n * theta) * radius * sin(theta + 2 * PI * n / sides) + centerY;

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
			index += 3;
		}
		
		
	}
}


S2DCircle::S2DCircle(double x,
	double y,
	double radius,
	int res,
	FloatColor* color) : S2DCycloid(x, y, radius, res, color, [](int i) {return true; }, [](float i) {return 1.0f;})
{}