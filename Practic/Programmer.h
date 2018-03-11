#pragma once
#include <string>
#include <iostream>

class Programmer
{
public:
	std::string name;
	int revised, toRevise;

	Programmer() : name(""), revised(0), toRevise(0) {}
	Programmer(std::string n, int r, int t) : name(n), revised(r), toRevise(t) {}

	friend std::istream& operator >> (std::istream& is, Programmer& p);
	friend std::ostream& operator << (std::ostream& os, Programmer& p);
};