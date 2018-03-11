#pragma once
#include <string>
#include <iostream>

class SourceFile
{
public:
	std::string name, status, creator, reviewer;

	SourceFile() : name(""), status(""), creator(""), reviewer("") {}
	SourceFile(std::string n, std::string s, std::string c, std::string r) : 
		name(n), status(s), creator(c), reviewer(r) {}

	friend std::istream& operator >> (std::istream& is, SourceFile& p);
	friend std::ostream& operator << (std::ostream& os, SourceFile& p);
};