#include "Utils.h"
#include <sstream>
using namespace std;

vector<string> tokenize(string str, char delim)
{
	string token;
	vector<string> result;
	stringstream ss(str);

	while (getline(ss, token, delim))
		result.push_back(token);

	return result;
}