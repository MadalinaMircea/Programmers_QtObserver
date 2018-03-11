#ifndef PRACTIC_H
#define PRACTIC_H

#include <QtWidgets/QMainWindow>
#include "ui_practic.h"

class Practic : public QMainWindow
{
	Q_OBJECT

public:
	Practic(QWidget *parent = 0);
	~Practic();

private:
	Ui::PracticClass ui;
};

#endif // PRACTIC_H
