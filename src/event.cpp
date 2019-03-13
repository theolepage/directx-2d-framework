#include "event.h"

EventHandler::EventHandler()
{
}

void EventHandler::addEvent(Event* event, UINT code) {
	events[code].push_back(event);
}

#define HANDLE_MSG(hwnd, message, fn)    \
    case (message): return HANDLE_##message((hwnd), (wParam), (lParam), (fn))

LRESULT EventHandler::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_CHAR:
		//OnChar(hWnd, reinterpret_cast<UINT>(wParam), (int)lParam);
		break;
	case WM_LBUTTONDOWN:
		//OnLBD(hWnd);
		break;
	case WM_LBUTTONUP:
		//OnLBU();
		break;
	case WM_MOUSEMOVE:
		//OnMM();
		break;
	case WM_KEYDOWN:
		//OnKD();
		break;
	case WM_KEYUP:
		//OnKU();
		break;
	case WM_RBUTTONUP:
		//OnRBU(hWnd);
		break;
	case WM_RBUTTONDOWN:
		//OnRBD(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return 0;
	}

}

void EventHandler::OnChar(HWND hwnd, UINT ch, int cRepeat)
{

}

void EventHandler::OnLBD(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{

}

void EventHandler::OnLBU(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{

}

void EventHandler::OnRBD(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{

}

void EventHandler::OnRBU(HWND hwnd, int x, int y, UINT keyFlags)
{


}

void EventHandler::OnMM(HWND hwnd, int x, int y, UINT keyFlags)
{

}

EventHandler::~EventHandler(){}

Event::Event(UINT key) {

}

Event::~Event(){}
