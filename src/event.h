#pragma once
#include <list>

class EventHandler
{
private:
	std::list<Event*> events;
public:
	EventHandler();
	~EventHandler();
};

class Event
{
public:
	Event();
	~Event();
};

