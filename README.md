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
```

## Documentation

All the code running your application shoukd be place in the `App.cpp` file.  
If you want to make your own shapes, create a class extending `Shape`.

### Window
Class handling the window creation and its events.

### Entity
Class inherited by all objects requiring a position.

### Color
We have made a new object to handle colors called *FloatColor* to easily handle colors with shaders. This object let you create a color object that could be used multiple times.
This color object can be created using multiple formats:
1. The single int RGB format
..* Example: `0xff00ff`
2. The triple int RGB format
..* Example: `255, 0, 255`
3. The triple float RGB format
..* Example: `1.0f, 0.0f, 1.0f`
> Color channels will be stored as float but you could use `toRGB()` to get it as an integer.

### Shape
Class inherited by all shapes storing their vertices and their color.

> All shapes below will be centered on the specified position.

#### S2DLine
Class to draw a line. You'll need to specify the lower position first and then the upper position using their x and y coordinates. You also need to specify the line's width.
```
S2DLine::S2DLine(double x1, double y1,
	double x2, double y2,
	double width, FloatColor *color)
```
Example:
```cpp
 S2DLine line = new S2DLine(0.5, 0.3, 0.15, 0.65, 0.1, new FloatColor(0xfcc602));
```

#### S2DCircle
Class to draw a circle depending on its position, radius, resolution and color.
```
S2DCircle(double x,
	double y,
	double radius,
	int resolution,
	FloatColor* color)
```
Example:
```cpp
S2DCircle circle = new S2DCircle(0, 0, 0.5, 100, new FloatColor(0xFF00FF));
```

#### S2DRectangle
Class to draw a rectangle depending on it's position, width, height and color.
```
S2DRectangle(double x,
	double y,
	double width,
	double height,
	FloatColor* color)
```
Example:
```cpp
S2DRectangle rectangle = new S2DRectangle(0.0, 0.3, 0.3, 0.2, new FloatColor(0x8c8c8c));
```
#### S2DDiamond
Class to draw a diamond, you'll need to specify it's position, it's width and it's height.
```
S2DDiamond(double x,
	double y,
	double width,
	double height,
	FloatColor* color)
```
Example:
```cpp
S2DDiamond rectangle = new S2DDiamond(0.0, 0.3, 0.3, 0.2, new FloatColor(0x2c5c2c));
```
#### S2DQuad
Class to draw a quadrangle by specifying it's angles position.
```
S2DQuad(double x1, double y1,
	double x2, double y2,
	double x3, double y3,
	double x4, double y4,
	FloatColor* color)
```
Example:
```cpp
S2DQuad quad = S2DQuad(0.5, 0.5 , 1.0, 0.5, 0.5, -0.5, 1.0, -0.5,new FloatColor(0x8c8c8c));
```
#### S2DCycloid
Class to draw any kind of cycloid shape, this kind of object are trickier to use than the previous ones but they also offer more possibility. These objects take two functions in their arguments, the first one is a filter for triangles that needs to be displayed and the second one is a function that determines the radius to use from the angle.
```
S2DCycloid(double x,
	double y,
	double radius,
	int res,
	FloatColor* color,
	bool(*expr)(int),
	float(*radExpr)(float))
```
Example:
```cpp
S2DCycloid cycloid =  = new S2DCycloid(0.0, 0.0, 1.0, 200, new FloatColor(0x48f442),
		[](int i) {return i % 3 != 0; },
		[](float i) {return abs(cos(i * 2.0f) * cos(i * 4.0f)); }));
```

## To-Do

- Handle alpha color channel