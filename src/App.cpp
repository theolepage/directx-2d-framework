#include <list>
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>


#include "window.h"

#include "entity.h"
#include "circle.h"
#include "tree.h"



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	Window w = Window(L"Hello world", 640, 480);

	//w.addEntity(new Circle(0, 0.5, 0.3, 60, new FloatColor(0xFF00FF));
	//w.addEntity(((*Entity) (new Tree(0.46, -0.5)));

	return w.Start(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}