#pragma once
#include <map>
#include <list>
#include <windows.h>

typedef unsigned int UINT;

class Event
{
protected:
	UINT type = 0;
public:
	Event(){}
	~Event(){}
	virtual UINT getType() = 0;
};

class OnCharEvent :
	public Event
{
public:
	void(*expr)(HWND, UINT, int);
	OnCharEvent(void(*expr)(HWND, UINT, int));
	~OnCharEvent(){}
};

class OnLBDEvent :
	public Event
{
public:
	void(*expr)(HWND, BOOL, int, int, UINT);
	OnLBDEvent(void(*expr)(HWND, BOOL, int, int, UINT));
	~OnLBDEvent(){}
};

class OnLBUEvent :
	public Event
{
public:
	void (*expr)(HWND, int, int, UINT);
	OnLBUEvent(void(*expr)(HWND, int, int, UINT));
	~OnLBUEvent(){}
};

class OnRBDEvent :
	public Event
{
public:
	void(*expr)(HWND, BOOL, int, int, UINT);
	OnRBDEvent(void(*expr)(HWND, BOOL, int, int, UINT));
	~OnRBDEvent(){}
};

class OnRBUEvent :
	public Event
{
public:
	void(*expr)(HWND, int, int, UINT);
	OnRBUEvent(void(*expr)(HWND, int, int, UINT));
	~OnRBUEvent() {}
};

class OnMMEvent :
	public Event
{
public:
	void(*expr)(HWND, int, int, UINT);
	OnMMEvent(void(*expr)(HWND, int, int, UINT));
	~OnMMEvent() {}
};

class OnKeyUpEvent :
	public Event
{
public:
	void(*expr)(HWND, UINT, BOOL, int, UINT);
	OnKeyUpEvent(void(*expr)(HWND, UINT, BOOL, int, UINT));
	~OnKeyUpEvent() {}
};

class OnKeyDownEvent :
	public Event
{
public:
	void(*expr)(HWND, UINT, BOOL, int, UINT);
	OnKeyDownEvent(void(*expr)(HWND, UINT, BOOL, int, UINT));
	~OnKeyDownEvent() {}
};

class EventHandler
{
private:
	std::list<OnCharEvent*> onCharEvents;
	std::list<OnLBDEvent*> onLBDEvents;
	std::list<OnLBUEvent*> onLBUEvents;
	std::list<OnRBDEvent*> onRBDEvents;
	std::list<OnRBUEvent*> onRBUEvents;
	std::list<OnMMEvent*> onMMEvents;
	std::list<OnKeyUpEvent*> onKeyUpEvents;
	std::list<OnKeyDownEvent*> onKeyDownEvents;


	void OnChar(HWND, UINT, int);
	void OnLBD(HWND, BOOL, int, int, UINT);
	void OnRBD(HWND, BOOL, int, int, UINT);
	void OnLBU(HWND, int, int, UINT);
	void OnRBU(HWND, int, int, UINT);
	void OnMM(HWND, int, int, UINT);
	void OnKeyUp(HWND, UINT, BOOL, int, UINT);
	void OnKeyDown(HWND, UINT, BOOL, int, UINT);
public:
	EventHandler();
	LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);
	void addEvent(Event*);
	~EventHandler(){}
};

