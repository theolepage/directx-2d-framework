#include <list>
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include "resource.h"
#include "simple_vertex.h"
#include "constant_buffer.h"

#include "tree.h"

#pragma once
class Window
{
public:
	Window(LPCWSTR title, int width, int height, FloatColor* background);
	int Start(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow);
	void addEntity(Entity *entity);

	ID3D11Device*           g_pd3dDevice = NULL;

	LPCWSTR title;
	int width;
	int height;
	FloatColor* background;

private:
	HINSTANCE               g_hInst = NULL;
	HWND                    g_hWnd = NULL;
	D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11DeviceContext*    g_pImmediateContext = NULL;
	IDXGISwapChain*         g_pSwapChain = NULL;
	ID3D11RenderTargetView* g_pRenderTargetView = NULL;
	ID3D11VertexShader*     g_pVertexShader = NULL;
	ID3D11PixelShader*      g_pPixelShader = NULL;
	ID3D11InputLayout*      g_pVertexLayout = NULL;
	ID3D11Buffer*           g_pVertexBuffer = NULL;
	ID3D11Buffer*			g_pConstantBuffer = NULL;

	std::list <Entity*>		entities;
	VS_CONSTANT_BUFFER		VsConstData;

	HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow);
	HRESULT InitDevice();
	void CleanupDevice();
	void Render();
};

