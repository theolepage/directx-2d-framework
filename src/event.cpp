#include "event.h"

EventHandler::EventHandler() {}

//--------------------------------------------------------------------------------------
// Determine the kind of event passed in parameter and store it in the correct list
//--------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------
// Handle every supported types of messages and accordingly execute events.
//--------------------------------------------------------------------------------------
LRESULT EventHandler::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hWnd, WM_CHAR, OnChar);
		HANDLE_MSG(hWnd, WM_LBUTTONDOWN, OnLBD);
		HANDLE_MSG(hWnd, WM_LBUTTONUP, OnLBU);
		HANDLE_MSG(hWnd, WM_RBUTTONDOWN, OnRBD);
		HANDLE_MSG(hWnd, WM_RBUTTONUP, OnRBU);
		HANDLE_MSG(hWnd, WM_MOUSEMOVE, OnMM);
		HANDLE_MSG(hWnd, WM_KEYDOWN, OnKeyDown);
		HANDLE_MSG(hWnd, WM_KEYUP, OnKeyUp);
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	};
	
	return 0;
}

//--------------------------------------------------------------------------------------
// Execute all events requested by a typed character.
//--------------------------------------------------------------------------------------
void EventHandler::OnChar(HWND hwnd, UINT ch, int cRepeat)
{
	for (auto const& e : onCharEvents) {
		e->expr(hwnd, ch, cRepeat);
	}
}

//--------------------------------------------------------------------------------------
// Execute all events requested by a left mouse button down.
//--------------------------------------------------------------------------------------
void EventHandler::OnLBD(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	for (auto const& e : onLBDEvents) {
		e->expr(hwnd, fDoubleClick, x, y, keyFlags);
	}
}

//--------------------------------------------------------------------------------------
// Execute all events requested by a left mouse button up.
//--------------------------------------------------------------------------------------
void EventHandler::OnLBU(HWND hwnd, int x, int y, UINT keyFlags)
{
	for (auto const& e : onLBUEvents) {
		e->expr(hwnd, x, y, keyFlags);
	}
}

//--------------------------------------------------------------------------------------
// Execute all events requested by a right mouse button down.
//--------------------------------------------------------------------------------------
void EventHandler::OnRBD(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	for (auto const& e : onRBDEvents) {
		e->expr(hwnd, fDoubleClick, x, y, keyFlags);
	}
}

//--------------------------------------------------------------------------------------
// Execute all events requested by a right mouse button up.
//--------------------------------------------------------------------------------------
void EventHandler::OnRBU(HWND hwnd, int x, int y, UINT keyFlags)
{
	for (auto const& e : onRBUEvents) {
		e->expr(hwnd, x, y, keyFlags);
	}
}

//--------------------------------------------------------------------------------------
// Execute all events requested by a mouse movement.
//--------------------------------------------------------------------------------------
void EventHandler::OnMM(HWND hwnd, int x, int y, UINT keyFlags)
{
	for (auto const& e : onMMEvents) {
		e->expr(hwnd, x, y, keyFlags);
	}
}

//--------------------------------------------------------------------------------------
// Execute all events requested by a key down.
//--------------------------------------------------------------------------------------
void EventHandler::OnKeyDown(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	for (auto const& e : onKeyDownEvents) {
		e->expr(hwnd, vk, fDown, cRepeat, flags);
	}
}

//--------------------------------------------------------------------------------------
// Execute all events requested by a key up.
//--------------------------------------------------------------------------------------
void EventHandler::OnKeyUp(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	for (auto const& e : onKeyUpEvents) {
		e->expr(hwnd, vk, fDown, cRepeat, flags);
	}
}

//--------------------------------------------------------------------------------------
// Return the type of an event.
//--------------------------------------------------------------------------------------
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