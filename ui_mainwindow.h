/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout_3;
    QFrame *frame_7;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_14;
    QPushButton *btnMainExit;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLineEdit *mLeNameExecutor;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *mLeLocalTest;
    QLineEdit *mLeIDExecutor;
    QLabel *label_4;
    QLineEdit *mLeWorkSupervisor;
    QLineEdit *mLeIDSupervisor;
    QLineEdit *mLeNameSupervisor;
    QLabel *label_9;
    QLineEdit *mLeWorkExecutor;
    QLabel *label_6;
    QFrame *frame_6;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_7;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QPushButton *mBtCableTest;
    QLabel *mlElectricCable;
    QFrame *frame_3;
    QGridLayout *gridLayout_8;
    QLabel *mlRfCable;
    QPushButton *mBtRfTest;
    QFrame *frame_4;
    QGridLayout *gridLayout_9;
    QLabel *mlModule;
    QPushButton *mBtModuleTest;
    QFrame *frame_5;
    QGridLayout *gridLayout_10;
    QLabel *mlMechanical;
    QPushButton *mBtMechanicalTest;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1143, 638);
        MainWindow->setMaximumSize(QSize(21696, 13560));
        MainWindow->setBaseSize(QSize(-7655, 0));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(242,242,242);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(20);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 5, 10, 0);
        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setStyleSheet(QString::fromUtf8("outline:none;\n"
"border:none;"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_7);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(frame_7);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans"));
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font:28pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_14 = new QLabel(frame_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("border-image: url(\":/Test/images/logo.png\");"));

        gridLayout_2->addWidget(label_14, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 3);

        gridLayout_3->addWidget(frame_7, 0, 0, 2, 1);

        btnMainExit = new QPushButton(centralWidget);
        btnMainExit->setObjectName(QString::fromUtf8("btnMainExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Test/images/button/exit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMainExit->setIcon(icon);
        btnMainExit->setIconSize(QSize(25, 25));
        btnMainExit->setFlat(true);

        gridLayout_3->addWidget(btnMainExit, 0, 1, 1, 1, Qt::AlignRight);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        mLeNameExecutor = new QLineEdit(frame);
        mLeNameExecutor->setObjectName(QString::fromUtf8("mLeNameExecutor"));
        mLeNameExecutor->setStyleSheet(QString::fromUtf8("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeNameExecutor, 1, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 3, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        mLeLocalTest = new QLineEdit(frame);
        mLeLocalTest->setObjectName(QString::fromUtf8("mLeLocalTest"));
        mLeLocalTest->setStyleSheet(QString::fromUtf8("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeLocalTest, 3, 1, 1, 1);

        mLeIDExecutor = new QLineEdit(frame);
        mLeIDExecutor->setObjectName(QString::fromUtf8("mLeIDExecutor"));
        mLeIDExecutor->setStyleSheet(QString::fromUtf8("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeIDExecutor, 1, 2, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        mLeWorkSupervisor = new QLineEdit(frame);
        mLeWorkSupervisor->setObjectName(QString::fromUtf8("mLeWorkSupervisor"));
        mLeWorkSupervisor->setStyleSheet(QString::fromUtf8("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeWorkSupervisor, 2, 3, 1, 1);

        mLeIDSupervisor = new QLineEdit(frame);
        mLeIDSupervisor->setObjectName(QString::fromUtf8("mLeIDSupervisor"));
        mLeIDSupervisor->setStyleSheet(QString::fromUtf8("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeIDSupervisor, 2, 2, 1, 1);

        mLeNameSupervisor = new QLineEdit(frame);
        mLeNameSupervisor->setObjectName(QString::fromUtf8("mLeNameSupervisor"));
        mLeNameSupervisor->setStyleSheet(QString::fromUtf8("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeNameSupervisor, 2, 1, 1, 1);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        mLeWorkExecutor = new QLineEdit(frame);
        mLeWorkExecutor->setObjectName(QString::fromUtf8("mLeWorkExecutor"));
        mLeWorkExecutor->setStyleSheet(QString::fromUtf8("background-color: rgb(220,225,226);"));

        gridLayout->addWidget(mLeWorkExecutor, 1, 3, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 2);
        gridLayout->setRowStretch(2, 2);
        gridLayout->setRowStretch(3, 2);

        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_4->setRowStretch(0, 1);

        gridLayout_3->addWidget(frame, 1, 1, 1, 1);

        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setStyleSheet(QString::fromUtf8("outline: none;\n"
"border:none;"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(50);
        gridLayout_5->setVerticalSpacing(10);
        gridLayout_5->setContentsMargins(-1, 0, 0, -1);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(15);
        gridLayout_7->setContentsMargins(0, -1, -1, -1);
        frame_2 = new QFrame(frame_6);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgba(194,204,205);\n"
"border: 10px;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(2, 2, 2, 2);
        mBtCableTest = new QPushButton(frame_2);
        mBtCableTest->setObjectName(QString::fromUtf8("mBtCableTest"));
        mBtCableTest->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mBtCableTest->sizePolicy().hasHeightForWidth());
        mBtCableTest->setSizePolicy(sizePolicy);
        mBtCableTest->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: rgba(207,215,216, 255);\n"
"outline: none;\n"
"color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"border-image: url(\":/Test/images/electric_cable_test_disable.png\");\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(176,188,189);\n"
"}"));

        gridLayout_6->addWidget(mBtCableTest, 1, 0, 1, 1);

        mlElectricCable = new QLabel(frame_2);
        mlElectricCable->setObjectName(QString::fromUtf8("mlElectricCable"));
        mlElectricCable->setStyleSheet(QString::fromUtf8("color: rgb(170, 186, 198);\n"
"font: 14pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        mlElectricCable->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(mlElectricCable, 0, 0, 1, 1);

        gridLayout_6->setRowStretch(0, 2);
        gridLayout_6->setRowStretch(1, 12);

        gridLayout_7->addWidget(frame_2, 0, 0, 1, 1);

        frame_3 = new QFrame(frame_6);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgba(194,204,205);\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(2, 2, 2, 2);
        mlRfCable = new QLabel(frame_3);
        mlRfCable->setObjectName(QString::fromUtf8("mlRfCable"));
        mlRfCable->setStyleSheet(QString::fromUtf8("color: rgb(170, 186, 198);\n"
"font: 14pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        mlRfCable->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(mlRfCable, 0, 0, 1, 1);

        mBtRfTest = new QPushButton(frame_3);
        mBtRfTest->setObjectName(QString::fromUtf8("mBtRfTest"));
        mBtRfTest->setEnabled(true);
        sizePolicy.setHeightForWidth(mBtRfTest->sizePolicy().hasHeightForWidth());
        mBtRfTest->setSizePolicy(sizePolicy);
        mBtRfTest->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: rgb(220,225,226);\n"
"outline: none;\n"
"color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"border-image: url(\":/Test/images/rf_cable_test_disable.png\");\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(176,188,189);\n"
"}"));

        gridLayout_8->addWidget(mBtRfTest, 1, 0, 1, 1);

        gridLayout_8->setRowStretch(0, 2);
        gridLayout_8->setRowStretch(1, 12);

        gridLayout_7->addWidget(frame_3, 0, 1, 1, 1);

        frame_4 = new QFrame(frame_6);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgba(194,204,205);\n"
""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(frame_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(2, 2, 2, 2);
        mlModule = new QLabel(frame_4);
        mlModule->setObjectName(QString::fromUtf8("mlModule"));
        mlModule->setStyleSheet(QString::fromUtf8("color: rgb(170, 186, 198);\n"
"font: 14pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        mlModule->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(mlModule, 0, 0, 1, 1);

        mBtModuleTest = new QPushButton(frame_4);
        mBtModuleTest->setObjectName(QString::fromUtf8("mBtModuleTest"));
        mBtModuleTest->setEnabled(true);
        sizePolicy.setHeightForWidth(mBtModuleTest->sizePolicy().hasHeightForWidth());
        mBtModuleTest->setSizePolicy(sizePolicy);
        mBtModuleTest->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: rgb(220,225,226);\n"
"outline: none;\n"
"color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"border-image: url(\":/Test/images/module_test_disable.png\");\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(176,188,189);\n"
"}\n"
""));

        gridLayout_9->addWidget(mBtModuleTest, 1, 0, 1, 1);

        gridLayout_9->setRowStretch(0, 2);
        gridLayout_9->setRowStretch(1, 12);

        gridLayout_7->addWidget(frame_4, 0, 2, 1, 1);

        frame_5 = new QFrame(frame_6);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgba(194,204,205);\n"
""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_5);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(2, 2, 2, 2);
        mlMechanical = new QLabel(frame_5);
        mlMechanical->setObjectName(QString::fromUtf8("mlMechanical"));
        mlMechanical->setStyleSheet(QString::fromUtf8("color: rgb(170, 186, 198);\n"
"font: 14pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        mlMechanical->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(mlMechanical, 0, 0, 1, 1);

        mBtMechanicalTest = new QPushButton(frame_5);
        mBtMechanicalTest->setObjectName(QString::fromUtf8("mBtMechanicalTest"));
        mBtMechanicalTest->setEnabled(true);
        sizePolicy.setHeightForWidth(mBtMechanicalTest->sizePolicy().hasHeightForWidth());
        mBtMechanicalTest->setSizePolicy(sizePolicy);
        mBtMechanicalTest->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: rgb(220,225,226);\n"
"outline: none;\n"
"color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"border-image: url(\":/Test/images/mechanical_test_disable.png\");\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(176,188,189);\n"
"}"));

        gridLayout_10->addWidget(mBtMechanicalTest, 1, 0, 1, 1);

        gridLayout_10->setRowStretch(0, 2);
        gridLayout_10->setRowStretch(1, 12);

        gridLayout_7->addWidget(frame_5, 0, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_6, 2, 0, 1, 2);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 2);
        gridLayout_3->setRowStretch(2, 5);
        MainWindow->setCentralWidget(centralWidget);
        frame_7->raise();
        frame_6->raise();
        frame->raise();
        btnMainExit->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "ARS-Testing", nullptr));
        label_14->setText(QString());
        btnMainExit->setText(QString());
        mLeNameExecutor->setText(QString());
        mLeNameExecutor->setPlaceholderText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Supervisor", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Executor", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Workplace", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ID staff", nullptr));
        mLeLocalTest->setPlaceholderText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        mLeIDExecutor->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID Number", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Location Test", nullptr));
        mLeWorkSupervisor->setPlaceholderText(QCoreApplication::translate("MainWindow", "Workplace ", nullptr));
        mLeIDSupervisor->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID Number", nullptr));
        mLeNameSupervisor->setPlaceholderText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_9->setText(QString());
        mLeWorkExecutor->setPlaceholderText(QCoreApplication::translate("MainWindow", "Workplace", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        mBtCableTest->setText(QString());
        mlElectricCable->setText(QCoreApplication::translate("MainWindow", "Test Electrical Cable ", nullptr));
        mlRfCable->setText(QCoreApplication::translate("MainWindow", "Test RF Cable", nullptr));
        mBtRfTest->setText(QString());
        mlModule->setText(QCoreApplication::translate("MainWindow", "Test Module", nullptr));
        mBtModuleTest->setText(QString());
        mlMechanical->setText(QCoreApplication::translate("MainWindow", "Test Mechanical", nullptr));
        mBtMechanicalTest->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
