#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include <ctime>

#include "window.h"
#include "tree.h"
#include "car.h"

#define UNIT 0.015
Car *car;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));
	Window window = Window(L"Hello world", 640, 600, new FloatColor(0xb5d1ff));

	car = new Car(0.2, -0.4);

	window.addEvent((Event*) new OnCharEvent([](HWND hwnd, UINT ch, int cRepeat) {
		if (ch == 'a') {
			car->setPos(car->x - UNIT, car->y);
		}
		if (ch == 'd') {
			car->setPos(car->x + UNIT, car->y);
		}
	}));

	window.addEntity(car);
	window.addEntity(new S2DCircle(-0.6, 0.6, 0.2, 100, new FloatColor(0xffe7b4)));
	window.addEntity(new Tree(0.0f, -1.0, 0.1));

	return window.Start(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}