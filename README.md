# cpp-directx-boilerplate

![Screenshot](https://raw.githubusercontent.com/thdoteo/cpp-directx-boilerplate/master/docs/screenshot.png)  

A simple framework to make C++ DirectX 3D applications. 

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Usage

Just clone the repository and open the project with Visual Studio.

## TL;DR
It doesn't get much simpler than this code:

```cpp
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include "window.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	Window window = Window(L"Framework demonstration", 640, 600, new FloatColor(0xb5d1ff));

	window.addEvent((Event*) new OnCharEvent([](HWND hwnd, UINT ch, int cRepeat) {
		// Do what you want with your event
	}));

	// Add whatever entity you need
	window.addEntity(new S2DCircle(0.0, 0.0, 0.3, 100, new FloatColor(0xe2492b)));

	return window.Start(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}
```

You don't need to worry about tricky details. Just focus on creation, we'll handle all the boring stuff.

## Tutorial

We wrote some useful objects to use to help you out.
### Entity
This class is just a container for everything that needs to be stored in your app and that require a position.
### Shape
This class give you access to a set of tool such as a vertex buffer, an array of vertices and a color to create your own shapes.
### S2DCircle
This class allows you to draw circle easily, you need to specify the position, the radius, the resolution and the color of your circle and you're done.
```
S2DCircle(x, y, radius, resolution, color);
```
Example:
```cpp
S2DCircle circle = new S2DCircle(0, 0, 0.5, 100, new FloatColor(0xFF00FF));
```

There is a demo file inside, take a look and dive in.

## To-Do

- Handle alpha color channel