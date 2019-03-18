# directx-2d-framework

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

A simple framework to make C++ DirectX 3D applications. 

## Usage

Just clone the repository and open the project with Visual Studio. You can compile and run the app directly. Use the `App.cpp` file as an example.

## Example

![Screenshot](https://raw.githubusercontent.com/thdoteo/cpp-directx-boilerplate/master/docs/example.gif)  

```cpp
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include "window.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
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
```

## Documentation

All the code running your application shoukd be place in the `App.cpp` file.  
If you want to make your own shapes, create a class extending `Shape`.

### Window
Class handling the window creation and its events.

### Entity
Class inherited by all objects requiring a position.

### Shape
Class inherited by all shapes storing their vertices and their color.

#### S2DCircle
Class to draw a circle depending on its position, radius, resolution and color.
```
S2DCircle(x, y, radius, resolution, color);
```
Example:
```cpp
S2DCircle circle = new S2DCircle(0, 0, 0.5, 100, new FloatColor(0xFF00FF));
```

## To-Do

- Handle alpha color channel