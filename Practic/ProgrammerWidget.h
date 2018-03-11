#ifndef PROGRAMMERWIDGET_H
#define PROGRAMMERWIDGET_H

#include <QWidget>
#include "ui_ProgrammerWidget.h"
#include "Programmer.h"
#include "Repository.h"
#include "Observer.h"

class ProgrammerWidget : public QWidget, public Observer
{
	Q_OBJECT

public:
	Programmer p;
	Repository* repo;
	ProgrammerWidget(Repository* r, Programmer p, QWidget *parent = 0);
	~ProgrammerWidget();
	void init();
	void connectAll();
	void update() override { this->init(); }

private:
	Ui::ProgrammerWidget ui;

private slots:
	void addButtonHandler();
	void reviseButtonHandler();
	void changedHandler();
};

#endif // PROGRAMMERWIDGET_H
