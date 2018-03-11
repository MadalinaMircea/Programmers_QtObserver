#pragma once
#include "SourceFile.h"
#include <vector>
#include "Observer.h"
#include "Programmer.h"

class Repository : public Observable
{
public:
	std::vector<SourceFile> sources;
	Repository() { this->readFromFile(); }
	/*
	Adds a SourceFile to the repository;
	input - n, a string representing the name of the file
		  - p, a string representing the name of the programmer who initiated the add
	output - if n is empty or if there already is a SourceFile with that name, throws an exception
		   - otherwise, adds a SourceFile with name = n, creator = p, status = not_revised,
			 reviewer = -, updates the file and notifies the observers
	*/
	void add(std::string n, std::string p);
	void readFromFile();
	void writeToFile();
	/*
	Reviewes a source file
	input - i, the position of the source to be updated
		  - p, a reference to a Programmer type object
		  - the data is assumed correct because the button would not have been enabled otherwise
	output - modifies the status and reviewer of the SourceFile on position i,
			 increments the number of sources reviewed by the programmer, updates the file
			 and notifies the observers
	*/
	void revise(int i, Programmer& p);
	static void test();
};