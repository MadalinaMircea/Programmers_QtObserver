#include "ProgrammerWidget.h"
#include "qlistwidget.h"
#include <string>
#include <qmessagebox.h>
using namespace std;

ProgrammerWidget::ProgrammerWidget(Repository* r, Programmer p, QWidget *parent)
	: QWidget(parent), p(p), repo(r)
{
	ui.setupUi(this);
	this->init();
	this->connectAll();
}

ProgrammerWidget::~ProgrammerWidget()
{

}

void ProgrammerWidget::init()
{
	if (this->ui.sources->count() != 0)
		this->ui.sources->clear();

	this->ui.revised->setText(QString::number(this->p.revised));
	this->ui.toRevise->setText(QString::number(this->p.toRevise - this->p.revised));

	SourceFile aux;
	for(int i = 0; i < this->repo->sources.size() - 1; i++)
		for(int j = i + 1; j < this->repo->sources.size(); j++)
			if (this->repo->sources[i].name > this->repo->sources[j].name)
			{
				aux = this->repo->sources[i];
				this->repo->sources[i] = this->repo->sources[j];
				this->repo->sources[j] = aux;
			}

	for (int i = 0; i < this->repo->sources.size(); i++)
	{
		QString itemString = QString{ QString::fromStdString(this->repo->sources[i].name + " - " + \
			this->repo->sources[i].status + " - " + this->repo->sources[i].creator + " - " + \
			this->repo->sources[i].reviewer) };
		QListWidgetItem* item = new QListWidgetItem{ itemString };
		if (this->repo->sources[i].status == "revised")
		{
			item->setForeground(QColor{ 0,255,0 });
			QFont font = item->font();
			font.setWeight(QFont::Bold);
			item->setFont(font);
		}
		this->ui.sources->addItem(item);
	}
}

void ProgrammerWidget::connectAll()
{
	QObject::connect(this->ui.addButton, SIGNAL(clicked()), SLOT(addButtonHandler()));
	QObject::connect(this->ui.reviseButton, SIGNAL(clicked()), SLOT(reviseButtonHandler()));
	QObject::connect(this->ui.sources, SIGNAL(itemSelectionChanged()), SLOT(changedHandler()));
}

void ProgrammerWidget::addButtonHandler()
{
	string name = this->ui.nameTextBox->text().toStdString();

	try
	{
		this->repo->add(name, this->p.name);
	}
	catch (exception& e)
	{
		QMessageBox error;
		error.critical(0, "Error", e.what());
		error.show();
	}
}

void ProgrammerWidget::reviseButtonHandler()
{
	QModelIndexList index = this->ui.sources->selectionModel()->selectedIndexes();
	if (this->ui.sources->currentItem()->isSelected())
	{
			int i = index.at(0).row();
			this->repo->revise(i, this->p);
			if (this->p.revised == this->p.toRevise)
			{
				QMessageBox msg;
				msg.information(0, "Congratulations!", "Congratulations!");
			}
	}
}

void ProgrammerWidget::changedHandler()
{
	QModelIndexList index = this->ui.sources->selectionModel()->selectedIndexes();
	if (this->ui.sources->currentItem()->isSelected())
	{
		int i = index.at(0).row();
		if (this->repo->sources[i].status == "revised" || this->repo->sources[i].creator == this->p.name)
			this->ui.reviseButton->setEnabled(false);
		else
			this->ui.reviseButton->setEnabled(true);
	}
}