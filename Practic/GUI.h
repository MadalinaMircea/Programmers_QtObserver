#pragma once
#include "Repository.h"
#include "Programmer.h"
#include "ProgrammerWidget.h"

class GUI
{
public:
	std::vector<Programmer> programmers;
	std::vector<ProgrammerWidget*> widgets;
	Repository* repo;
	GUI() {}
	GUI(Repository* r);
	~GUI() { delete repo; }
	void init();
	void readProgrammers();
	void startProgrammers();
};