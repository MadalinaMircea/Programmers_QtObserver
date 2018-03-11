#include "Programmer.h"
#include <vector>
#include "Utils.h"
using namespace std;

std::istream& operator >> (std::istream& is, Programmer& p)
{
	string line;
	getline(is, line);
	vector<string> result = tokenize(line, ',');

	if (result.size() != 3)
		return is;

	p.name = result[0];
	p.revised = stoi(result[1]);
	p.toRevise = stoi(result[2]);

	return is;
}
std::ostream& operator << (std::ostream& os, Programmer& p)
{
	os << p.name << "," << p.revised << "," << p.toRevise;
	return os;
}