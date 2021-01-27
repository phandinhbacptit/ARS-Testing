/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QFrame *frame;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_2;
    QLineEdit *mLeNameExecutor;
    QLineEdit *mLeIDExecutor;
    QLineEdit *mLeWorkExecutor;
    QLabel *label_3;
    QLineEdit *mLeNameSupervisor;
    QLineEdit *mLeIDSupervisor;
    QLineEdit *mLeWorkSupervisor;
    QLabel *label_4;
    QLineEdit *mLeLocalTest;
    QLabel *label_5;
    QLineEdit *mLeTimeTest;
    QLabel *label_9;
    QLabel *label_14;
    QPushButton *btnMainExit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_2;
    QPushButton *mBtCableTest;
    QLabel *label_10;
    QFrame *frame_3;
    QPushButton *mBtRfTest;
    QLabel *label_11;
    QFrame *frame_4;
    QPushButton *mBtModuleTest;
    QLabel *label_12;
    QFrame *frame_5;
    QPushButton *mBtMechanicalTest;
    QLabel *label_13;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1143, 685);
        MainWindow->setMaximumSize(QSize(21696, 13560));
        MainWindow->setBaseSize(QSize(-7655, 0));
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(242,242,242);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 261, 71));
        QFont font;
        font.setFamily(QStringLiteral("Sans"));
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font:28pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(300, 50, 831, 181));
        frame->setStyleSheet(QStringLiteral("background-color: none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 12, 811, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 3, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        mLeNameExecutor = new QLineEdit(layoutWidget);
        mLeNameExecutor->setObjectName(QStringLiteral("mLeNameExecutor"));
        mLeNameExecutor->setStyleSheet(QStringLiteral("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeNameExecutor, 1, 1, 1, 1);

        mLeIDExecutor = new QLineEdit(layoutWidget);
        mLeIDExecutor->setObjectName(QStringLiteral("mLeIDExecutor"));
        mLeIDExecutor->setStyleSheet(QStringLiteral("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeIDExecutor, 1, 2, 1, 1);

        mLeWorkExecutor = new QLineEdit(layoutWidget);
        mLeWorkExecutor->setObjectName(QStringLiteral("mLeWorkExecutor"));
        mLeWorkExecutor->setStyleSheet(QStringLiteral("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeWorkExecutor, 1, 3, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        mLeNameSupervisor = new QLineEdit(layoutWidget);
        mLeNameSupervisor->setObjectName(QStringLiteral("mLeNameSupervisor"));
        mLeNameSupervisor->setStyleSheet(QStringLiteral("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeNameSupervisor, 2, 1, 1, 1);

        mLeIDSupervisor = new QLineEdit(layoutWidget);
        mLeIDSupervisor->setObjectName(QStringLiteral("mLeIDSupervisor"));
        mLeIDSupervisor->setStyleSheet(QStringLiteral("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeIDSupervisor, 2, 2, 1, 1);

        mLeWorkSupervisor = new QLineEdit(layoutWidget);
        mLeWorkSupervisor->setObjectName(QStringLiteral("mLeWorkSupervisor"));
        mLeWorkSupervisor->setStyleSheet(QStringLiteral("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeWorkSupervisor, 2, 3, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        mLeLocalTest = new QLineEdit(layoutWidget);
        mLeLocalTest->setObjectName(QStringLiteral("mLeLocalTest"));
        mLeLocalTest->setStyleSheet(QStringLiteral("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeLocalTest, 3, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        mLeTimeTest = new QLineEdit(layoutWidget);
        mLeTimeTest->setObjectName(QStringLiteral("mLeTimeTest"));
        mLeTimeTest->setStyleSheet(QStringLiteral("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeTimeTest, 4, 1, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(60, 120, 171, 91));
        label_14->setStyleSheet(QStringLiteral("border-image: url(\":/Test/images/logo.png\");"));
        btnMainExit = new QPushButton(centralWidget);
        btnMainExit->setObjectName(QStringLiteral("btnMainExit"));
        btnMainExit->setGeometry(QRect(1090, 4, 51, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Test/images/button/exit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMainExit->setIcon(icon);
        btnMainExit->setIconSize(QSize(25, 25));
        btnMainExit->setFlat(true);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 280, 1121, 341));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(layoutWidget1);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        mBtCableTest = new QPushButton(frame_2);
        mBtCableTest->setObjectName(QStringLiteral("mBtCableTest"));
        mBtCableTest->setGeometry(QRect(0, 60, 261, 281));
        mBtCableTest->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color: rgba(220,225,226, 255);\n"
"outline: none;\n"
"color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"border-image: url(\":/Test/images/electric_cable_test.png\");\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(176,188,189);\n"
"}"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 20, 231, 20));
        label_10->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 14pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(frame_2);

        frame_3 = new QFrame(layoutWidget1);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        mBtRfTest = new QPushButton(frame_3);
        mBtRfTest->setObjectName(QStringLiteral("mBtRfTest"));
        mBtRfTest->setGeometry(QRect(0, 60, 261, 281));
        mBtRfTest->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color: rgb(220,225,226);\n"
"outline: none;\n"
"color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"border-image: url(\":/Test/images/rf_cable_test.png\");\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(176,188,189);\n"
"}"));
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 20, 171, 20));
        label_11->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 14pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(frame_3);

        frame_4 = new QFrame(layoutWidget1);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        mBtModuleTest = new QPushButton(frame_4);
        mBtModuleTest->setObjectName(QStringLiteral("mBtModuleTest"));
        mBtModuleTest->setGeometry(QRect(0, 60, 261, 281));
        mBtModuleTest->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color: rgb(220,225,226);\n"
"outline: none;\n"
"color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"border-image: url(\":/Test/images/module_test.png\");\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(176,188,189);\n"
"}\n"
""));
        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 20, 171, 20));
        label_12->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 14pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(frame_4);

        frame_5 = new QFrame(layoutWidget1);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        mBtMechanicalTest = new QPushButton(frame_5);
        mBtMechanicalTest->setObjectName(QStringLiteral("mBtMechanicalTest"));
        mBtMechanicalTest->setGeometry(QRect(0, 60, 271, 281));
        mBtMechanicalTest->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color: rgb(220,225,226);\n"
"outline: none;\n"
"color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"border-image: url(\":/Test/images/mechanical_test.png\");\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(176,188,189);\n"
"}"));
        label_13 = new QLabel(frame_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 20, 171, 20));
        label_13->setStyleSheet(QLatin1String("color: rgb(49,67,100);\n"
"font: 14pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(frame_5);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        label->setText(QApplication::translate("MainWindow", "ARS-Testing", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "ID staff", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Workplace", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Executor", Q_NULLPTR));
        mLeNameExecutor->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Supervisor", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Location Test", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Time Test", Q_NULLPTR));
        label_9->setText(QString());
        label_14->setText(QString());
        btnMainExit->setText(QString());
        mBtCableTest->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Test Electrical Cable ", Q_NULLPTR));
        mBtRfTest->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "Test RF Cable", Q_NULLPTR));
        mBtModuleTest->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "Test Module", Q_NULLPTR));
        mBtMechanicalTest->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Test Mechanical", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
