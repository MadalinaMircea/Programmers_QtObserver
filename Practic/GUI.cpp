#include "GUI.h"
#include<fstream>
using namespace std;

GUI::GUI(Repository * r) : repo(r)
{
	this->init();
}

void GUI::init()
{
	this->readProgrammers();
	this->startProgrammers();
}

void GUI::readProgrammers()
{
	ifstream fin("programmers.txt");

	if (!fin.is_open())
		return;

	Programmer p;
	while (fin >> p)
		this->programmers.push_back(p);

	fin.close();
}

void GUI::startProgrammers()
{
	for (int i = 0; i < this->programmers.size(); i++)
	{
		ProgrammerWidget* p = new ProgrammerWidget{ this->repo, this->programmers[i] };
		this->widgets.push_back(p);
		this->widgets[i]->setWindowTitle(QString::fromStdString(this->programmers[i].name));
		this->widgets[i]->show();
		this->repo->addObserver(this->widgets[i]);
	}
}