/********************************************************************************
** Form generated from reading UI file 'testmechanical.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMECHANICAL_H
#define UI_TESTMECHANICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMechanical
{
public:
    QLabel *label;

    void setupUi(QWidget *TestMechanical)
    {
        if (TestMechanical->objectName().isEmpty())
            TestMechanical->setObjectName(QStringLiteral("TestMechanical"));
        TestMechanical->resize(1152, 716);
        TestMechanical->setStyleSheet(QStringLiteral("background-color: rgb(252,252,252);"));
        label = new QLabel(TestMechanical);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 311, 61));
        label->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font:25pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));

        retranslateUi(TestMechanical);

        QMetaObject::connectSlotsByName(TestMechanical);
    } // setupUi

    void retranslateUi(QWidget *TestMechanical)
    {
        TestMechanical->setWindowTitle(QApplication::translate("TestMechanical", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("TestMechanical", "Test Mechanical", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestMechanical: public Ui_TestMechanical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMECHANICAL_H
