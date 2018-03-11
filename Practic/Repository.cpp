#include "Repository.h"
#include <fstream>
#include <assert.h>
using namespace std;

void Repository::readFromFile()
{
	ifstream fin("sources.txt");
	if (!fin.is_open())
		return;

	SourceFile s;
	while (fin >> s)
		this->sources.push_back(s);

	fin.close();
}
void Repository::writeToFile()
{
	ofstream fout("sources.txt");
	if (!fout.is_open())
		return;

	for (auto s : sources)
		fout << s << '\n';

	fout.close();
}

void Repository::add(std::string n, std::string p)
{
	if (n.length() == 0)
		throw std::exception("File name cannot be empty.");

	for (auto s : this->sources)
		if (s.name == n)
			throw std::exception("Name already in use.");

	SourceFile s{ n, "not_revised", p, "-"};
	this->sources.push_back(s);
	this->writeToFile();
	this->notify();
}

void Repository::revise(int i, Programmer& p)
{
	this->sources[i].reviewer = p.name;
	this->sources[i].status = string{ "revised" };
	p.revised++;
	this->writeToFile();
	this->notify();
}

void Repository::test()
{
	Repository* repo = new Repository{};
	int l = repo->sources.size();
	repo->add("New Source", "New Programmer");
	assert(repo->sources.size() == l + 1);
	assert(repo->sources[l].name == "New Source");
	assert(repo->sources[l].creator == "New Programmer");
	assert(repo->sources[l].status == "not_revised");
	assert(repo->sources[l].reviewer == "-");
	try
	{
		repo->add("New Source", "New Programmer");
	}
	catch (exception& e)
	{
		assert(strcmp(e.what(),"Name already in use.") == 0);
	}

	try
	{
		repo->add("", "New Programmer");
	}
	catch (exception& e)
	{
		assert(strcmp(e.what(), "File name cannot be empty.") == 0);
	}

	Programmer p{ "Programmer", 0, 1 };
	repo->revise(l, p);
	assert(repo->sources[l].reviewer == "Programmer");
	assert(repo->sources[l].status == "revised");
	assert(p.revised == 1);
}