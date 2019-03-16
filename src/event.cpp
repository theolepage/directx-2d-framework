#include "event.h"

EventHandler::EventHandler()
{
}

void EventHandler::addEvent(Event *event) {
	switch (event->getType())
	{
	case WM_CHAR:
		onCharEvents.push_back((OnCharEvent*)event);
		break;
	case WM_LBUTTONDOWN:
		onLBDEvents.push_back((OnLBDEvent*)event);
		break;
	case WM_RBUTTONDOWN:
		onRBDEvents.push_back((OnRBDEvent*)event);
		break;
	case WM_LBUTTONUP:
		onLBUEvents.push_back((OnLBUEvent*)event);
		break;
	case WM_RBUTTONUP:
		onRBUEvents.push_back((OnRBUEvent*)event);
		break;
	case WM_MOUSEMOVE:
		onMMEvents.push_back((OnMMEvent*)event);
		break;
	case WM_KEYDOWN:
		onKeyDownEvents.push_back((OnKeyDownEvent*)event);
		break;
	case WM_KEYUP:
		onKeyUpEvents.push_back((OnKeyUpEvent*)event);
		break;
	default:
		break;
	}
}

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
		return DefWindowProc(hWnd, message, wParam, lParam);
	};
	
	return 0;
}

void EventHandler::OnChar(HWND hwnd, UINT ch, int cRepeat)
{
	for (auto const& e : onCharEvents) {
		e->expr(hwnd, ch, cRepeat);
	}
}

void EventHandler::OnLBD(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	for (auto const& e : onLBDEvents) {
		e->expr(hwnd, fDoubleClick, x, y, keyFlags);
	}
}

void EventHandler::OnLBU(HWND hwnd, int x, int y, UINT keyFlags)
{
	for (auto const& e : onLBUEvents) {
		e->expr(hwnd, x, y, keyFlags);
	}
}

void EventHandler::OnRBD(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	for (auto const& e : onRBDEvents) {
		e->expr(hwnd, fDoubleClick, x, y, keyFlags);
	}
}

void EventHandler::OnRBU(HWND hwnd, int x, int y, UINT keyFlags)
{
	for (auto const& e : onRBUEvents) {
		e->expr(hwnd, x, y, keyFlags);
	}
}

void EventHandler::OnMM(HWND hwnd, int x, int y, UINT keyFlags)
{
	for (auto const& e : onMMEvents) {
		e->expr(hwnd, x, y, keyFlags);
	}
}
void EventHandler::OnKeyDown(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	for (auto const& e : onKeyDownEvents) {
		e->expr(hwnd, vk, fDown, cRepeat, flags);
	}
}

void EventHandler::OnKeyUp(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	for (auto const& e : onKeyUpEvents) {
		e->expr(hwnd, vk, fDown, cRepeat, flags);
	}
}

UINT Event::getType() {
	return type;
}

OnCharEvent::OnCharEvent(void(*expr)(HWND, UINT, int)) {
	type = WM_CHAR;
	this->expr = expr;
}


OnLBDEvent::OnLBDEvent(void(*expr)(HWND, BOOL, int, int, UINT)) {
	type = WM_LBUTTONDOWN;
	this->expr = expr;
}

OnLBUEvent::OnLBUEvent(void(*expr)(HWND, int, int, UINT)) {
	type = WM_LBUTTONUP;
	this->expr = expr;
}

OnRBDEvent::OnRBDEvent(void(*expr)(HWND, BOOL, int, int, UINT)) {
	type = WM_RBUTTONDOWN;
	this->expr = expr;
}

OnRBUEvent::OnRBUEvent(void(*expr)(HWND, int, int, UINT)) {
	type = WM_RBUTTONUP;
	this->expr = expr;
}

OnMMEvent::OnMMEvent(void(*expr)(HWND, int, int, UINT)) {
	type = WM_MOUSEMOVE;
	this->expr = expr;
}

OnKeyUpEvent::OnKeyUpEvent(void(*expr)(HWND, UINT, BOOL, int, UINT)) {
	type = WM_KEYUP;
	this->expr = expr;
}

OnKeyDownEvent::OnKeyDownEvent(void(*expr)(HWND, UINT, BOOL, int, UINT)) {
	type = WM_KEYDOWN;
	this->expr = expr;
}