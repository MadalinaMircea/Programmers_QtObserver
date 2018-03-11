/********************************************************************************
** Form generated from reading UI file 'ProgrammerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMERWIDGET_H
#define UI_PROGRAMMERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgrammerWidget
{
public:
    QListWidget *sources;
    QPushButton *reviseButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLineEdit *nameTextBox;
    QPushButton *addButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *revisedLabel;
    QLabel *toReviseLabel;
    QLabel *revised;
    QLabel *toRevise;

    void setupUi(QWidget *ProgrammerWidget)
    {
        if (ProgrammerWidget->objectName().isEmpty())
            ProgrammerWidget->setObjectName(QStringLiteral("ProgrammerWidget"));
        ProgrammerWidget->resize(597, 441);
        sources = new QListWidget(ProgrammerWidget);
        sources->setObjectName(QStringLiteral("sources"));
        sources->setGeometry(QRect(0, 0, 341, 441));
        reviseButton = new QPushButton(ProgrammerWidget);
        reviseButton->setObjectName(QStringLiteral("reviseButton"));
        reviseButton->setGeometry(QRect(350, 190, 241, 23));
        layoutWidget = new QWidget(ProgrammerWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(350, 20, 241, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        verticalLayout->addWidget(nameLabel);

        nameTextBox = new QLineEdit(layoutWidget);
        nameTextBox->setObjectName(QStringLiteral("nameTextBox"));

        verticalLayout->addWidget(nameTextBox);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        verticalLayout->addWidget(addButton);

        layoutWidget1 = new QWidget(ProgrammerWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(350, 297, 241, 121));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        revisedLabel = new QLabel(layoutWidget1);
        revisedLabel->setObjectName(QStringLiteral("revisedLabel"));

        gridLayout->addWidget(revisedLabel, 0, 0, 1, 1);

        toReviseLabel = new QLabel(layoutWidget1);
        toReviseLabel->setObjectName(QStringLiteral("toReviseLabel"));

        gridLayout->addWidget(toReviseLabel, 0, 1, 1, 1);

        revised = new QLabel(layoutWidget1);
        revised->setObjectName(QStringLiteral("revised"));
        QFont font;
        font.setPointSize(48);
        revised->setFont(font);

        gridLayout->addWidget(revised, 1, 0, 1, 1);

        toRevise = new QLabel(layoutWidget1);
        toRevise->setObjectName(QStringLiteral("toRevise"));
        toRevise->setFont(font);

        gridLayout->addWidget(toRevise, 1, 1, 1, 1);


        retranslateUi(ProgrammerWidget);

        QMetaObject::connectSlotsByName(ProgrammerWidget);
    } // setupUi

    void retranslateUi(QWidget *ProgrammerWidget)
    {
        ProgrammerWidget->setWindowTitle(QApplication::translate("ProgrammerWidget", "ProgrammerWidget", 0));
        reviseButton->setText(QApplication::translate("ProgrammerWidget", "Revise", 0));
        nameLabel->setText(QApplication::translate("ProgrammerWidget", "Name", 0));
        addButton->setText(QApplication::translate("ProgrammerWidget", "Add", 0));
        revisedLabel->setText(QApplication::translate("ProgrammerWidget", "Revised", 0));
        toReviseLabel->setText(QApplication::translate("ProgrammerWidget", "To revise", 0));
        revised->setText(QApplication::translate("ProgrammerWidget", "0", 0));
        toRevise->setText(QApplication::translate("ProgrammerWidget", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgrammerWidget: public Ui_ProgrammerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMERWIDGET_H
