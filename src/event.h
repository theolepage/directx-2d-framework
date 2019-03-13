#pragma once
#include <map>
#include <list>
#include <windows.h>

typedef unsigned int UINT;

class Event
{
public:
	Event(UINT keyflag);
	~Event();
};

class EventHandler
{
private:
	std::map<UINT, std::list<Event*>> events;
public:
	EventHandler();
	LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);
	void OnChar(HWND, UINT, int);
	void OnLBD(HWND, BOOL, int, int, UINT);
	void OnLBU(HWND, BOOL, int, int, UINT);
	void OnRBD(HWND, BOOL, int, int, UINT);
	void OnRBU(HWND, int, int, UINT);
	void OnMM(HWND, int, int, UINT);

	void addEvent(Event*, UINT);
	~EventHandler();
};

