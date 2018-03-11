#pragma once
#include <vector>

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Observable
{
public:
	std::vector<Observer*> observers;
	void addObserver(Observer* o) { this->observers.push_back(o); }
	void notify()
	{
		for (auto o : observers)
			o->update();
	}
};