#include <list>
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

#include "window.h"
#include "entity.h"
#include "tree.h"
#include "cycloid.h"
#include "quad.h"
#include "heart.h"



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	Window window = Window(L"Hello world", 640, 600, new FloatColor(0xb5d1ff));

	window.addEntity(new S2DCircle(-0.6, 0.6, 0.2, 100, new FloatColor(0xffe7b4)));
	window.addEntity(new Tree(0.46, -0.5));

	return window.Start(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}