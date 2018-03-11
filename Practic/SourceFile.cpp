#include "SourceFile.h"
#include <vector>
#include "Utils.h"
using namespace std;

std::istream& operator >> (std::istream& is, SourceFile& p)
{
	string line;
	getline(is, line);
	vector<string> result = tokenize(line, ',');

	if (result.size() != 4)
		return is;

	p.name = result[0];
	p.status = result[1];
	p.creator = result[2];
	p.reviewer = result[3];

	return is;
}
std::ostream& operator << (std::ostream& os, SourceFile& p)
{
	os << p.name << "," << p.status << "," << p.creator << "," << p.reviewer;
	return os;
}