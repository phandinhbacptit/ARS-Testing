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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
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
    QPushButton *btnMainExit;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QFrame *frame_9;
    QGridLayout *gridLayout_14;
    QComboBox *cbNameExcutor;
    QToolButton *addNameExcutor;
    QToolButton *subNameExcutor;
    QLabel *label_4;
    QFrame *frame_15;
    QGridLayout *gridLayout_19;
    QComboBox *cbWorkSupervisor;
    QToolButton *addWorkSupervisor;
    QToolButton *subWorkSupervisor;
    QLabel *label_3;
    QFrame *frame_16;
    QGridLayout *gridLayout_20;
    QComboBox *cbIDSupervisor;
    QToolButton *addIDSupervisor;
    QToolButton *subIDSupervisor;
    QFrame *frame_10;
    QGridLayout *gridLayout_15;
    QComboBox *cbNameSupervisor;
    QToolButton *addNameSupervisor;
    QToolButton *subNameSupervisor;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *frame_13;
    QGridLayout *gridLayout_16;
    QComboBox *cbLocalTest;
    QToolButton *addLocalTest;
    QToolButton *subLocalTest;
    QFrame *frame_14;
    QGridLayout *gridLayout_18;
    QComboBox *cbWorkExcutor;
    QToolButton *addWorkExcutor;
    QToolButton *subWorkExcutor;
    QLabel *label_8;
    QLabel *label_2;
    QFrame *frame_17;
    QGridLayout *gridLayout_12;
    QComboBox *cbIDExcutor;
    QToolButton *addIDExcutor;
    QToolButton *subIDExcutor;
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

        gridLayout_2->setRowStretch(0, 1);

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
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        frame_9 = new QFrame(frame);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setStyleSheet(QString::fromUtf8("border: none;"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frame_9);
        gridLayout_14->setSpacing(1);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        cbNameExcutor = new QComboBox(frame_9);
        cbNameExcutor->setObjectName(QString::fromUtf8("cbNameExcutor"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbNameExcutor->sizePolicy().hasHeightForWidth());
        cbNameExcutor->setSizePolicy(sizePolicy);
        cbNameExcutor->setStyleSheet(QString::fromUtf8("background-color: rgb(224,220,230);"));

        gridLayout_14->addWidget(cbNameExcutor, 0, 0, 2, 1);

        addNameExcutor = new QToolButton(frame_9);
        addNameExcutor->setObjectName(QString::fromUtf8("addNameExcutor"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addNameExcutor->sizePolicy().hasHeightForWidth());
        addNameExcutor->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Myriad Pro"));
        font1.setPointSize(5);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        addNameExcutor->setFont(font1);
        addNameExcutor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_14->addWidget(addNameExcutor, 0, 1, 1, 1);

        subNameExcutor = new QToolButton(frame_9);
        subNameExcutor->setObjectName(QString::fromUtf8("subNameExcutor"));
        sizePolicy1.setHeightForWidth(subNameExcutor->sizePolicy().hasHeightForWidth());
        subNameExcutor->setSizePolicy(sizePolicy1);
        subNameExcutor->setFont(font1);
        subNameExcutor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_14->addWidget(subNameExcutor, 1, 1, 1, 1);

        gridLayout_14->setColumnStretch(0, 10);
        gridLayout_14->setColumnStretch(1, 1);

        gridLayout->addWidget(frame_9, 1, 1, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        frame_15 = new QFrame(frame);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        gridLayout_19 = new QGridLayout(frame_15);
        gridLayout_19->setSpacing(1);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        cbWorkSupervisor = new QComboBox(frame_15);
        cbWorkSupervisor->setObjectName(QString::fromUtf8("cbWorkSupervisor"));
        sizePolicy.setHeightForWidth(cbWorkSupervisor->sizePolicy().hasHeightForWidth());
        cbWorkSupervisor->setSizePolicy(sizePolicy);
        cbWorkSupervisor->setStyleSheet(QString::fromUtf8("background-color: rgb(224,220,230);"));

        gridLayout_19->addWidget(cbWorkSupervisor, 0, 0, 2, 1);

        addWorkSupervisor = new QToolButton(frame_15);
        addWorkSupervisor->setObjectName(QString::fromUtf8("addWorkSupervisor"));
        sizePolicy1.setHeightForWidth(addWorkSupervisor->sizePolicy().hasHeightForWidth());
        addWorkSupervisor->setSizePolicy(sizePolicy1);
        addWorkSupervisor->setFont(font1);
        addWorkSupervisor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_19->addWidget(addWorkSupervisor, 0, 1, 1, 1);

        subWorkSupervisor = new QToolButton(frame_15);
        subWorkSupervisor->setObjectName(QString::fromUtf8("subWorkSupervisor"));
        sizePolicy1.setHeightForWidth(subWorkSupervisor->sizePolicy().hasHeightForWidth());
        subWorkSupervisor->setSizePolicy(sizePolicy1);
        subWorkSupervisor->setFont(font1);
        subWorkSupervisor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_19->addWidget(subWorkSupervisor, 1, 1, 1, 1);

        gridLayout_19->setColumnStretch(0, 10);
        gridLayout_19->setColumnStretch(1, 1);

        gridLayout->addWidget(frame_15, 2, 3, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        frame_16 = new QFrame(frame);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        gridLayout_20 = new QGridLayout(frame_16);
        gridLayout_20->setSpacing(1);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        cbIDSupervisor = new QComboBox(frame_16);
        cbIDSupervisor->setObjectName(QString::fromUtf8("cbIDSupervisor"));
        sizePolicy.setHeightForWidth(cbIDSupervisor->sizePolicy().hasHeightForWidth());
        cbIDSupervisor->setSizePolicy(sizePolicy);
        cbIDSupervisor->setStyleSheet(QString::fromUtf8("background-color: rgb(224,220,230);"));

        gridLayout_20->addWidget(cbIDSupervisor, 0, 0, 2, 1);

        addIDSupervisor = new QToolButton(frame_16);
        addIDSupervisor->setObjectName(QString::fromUtf8("addIDSupervisor"));
        sizePolicy1.setHeightForWidth(addIDSupervisor->sizePolicy().hasHeightForWidth());
        addIDSupervisor->setSizePolicy(sizePolicy1);
        addIDSupervisor->setFont(font1);
        addIDSupervisor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_20->addWidget(addIDSupervisor, 0, 1, 1, 1);

        subIDSupervisor = new QToolButton(frame_16);
        subIDSupervisor->setObjectName(QString::fromUtf8("subIDSupervisor"));
        sizePolicy1.setHeightForWidth(subIDSupervisor->sizePolicy().hasHeightForWidth());
        subIDSupervisor->setSizePolicy(sizePolicy1);
        subIDSupervisor->setFont(font1);
        subIDSupervisor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_20->addWidget(subIDSupervisor, 1, 1, 1, 1);

        gridLayout_20->setColumnStretch(0, 10);
        gridLayout_20->setColumnStretch(1, 1);

        gridLayout->addWidget(frame_16, 2, 2, 1, 1);

        frame_10 = new QFrame(frame);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(frame_10);
        gridLayout_15->setSpacing(1);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        cbNameSupervisor = new QComboBox(frame_10);
        cbNameSupervisor->setObjectName(QString::fromUtf8("cbNameSupervisor"));
        sizePolicy.setHeightForWidth(cbNameSupervisor->sizePolicy().hasHeightForWidth());
        cbNameSupervisor->setSizePolicy(sizePolicy);
        cbNameSupervisor->setStyleSheet(QString::fromUtf8("background-color: rgb(224,220,230);"));

        gridLayout_15->addWidget(cbNameSupervisor, 0, 0, 2, 1);

        addNameSupervisor = new QToolButton(frame_10);
        addNameSupervisor->setObjectName(QString::fromUtf8("addNameSupervisor"));
        sizePolicy1.setHeightForWidth(addNameSupervisor->sizePolicy().hasHeightForWidth());
        addNameSupervisor->setSizePolicy(sizePolicy1);
        addNameSupervisor->setFont(font1);
        addNameSupervisor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_15->addWidget(addNameSupervisor, 0, 1, 1, 1);

        subNameSupervisor = new QToolButton(frame_10);
        subNameSupervisor->setObjectName(QString::fromUtf8("subNameSupervisor"));
        sizePolicy1.setHeightForWidth(subNameSupervisor->sizePolicy().hasHeightForWidth());
        subNameSupervisor->setSizePolicy(sizePolicy1);
        subNameSupervisor->setFont(font1);
        subNameSupervisor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_15->addWidget(subNameSupervisor, 1, 1, 1, 1);

        gridLayout_15->setColumnStretch(0, 10);
        gridLayout_15->setColumnStretch(1, 1);

        gridLayout->addWidget(frame_10, 2, 1, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        frame_13 = new QFrame(frame);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(frame_13);
        gridLayout_16->setSpacing(1);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        cbLocalTest = new QComboBox(frame_13);
        cbLocalTest->setObjectName(QString::fromUtf8("cbLocalTest"));
        sizePolicy.setHeightForWidth(cbLocalTest->sizePolicy().hasHeightForWidth());
        cbLocalTest->setSizePolicy(sizePolicy);
        cbLocalTest->setStyleSheet(QString::fromUtf8("background-color: rgb(224,220,230);"));

        gridLayout_16->addWidget(cbLocalTest, 0, 0, 2, 1);

        addLocalTest = new QToolButton(frame_13);
        addLocalTest->setObjectName(QString::fromUtf8("addLocalTest"));
        sizePolicy1.setHeightForWidth(addLocalTest->sizePolicy().hasHeightForWidth());
        addLocalTest->setSizePolicy(sizePolicy1);
        addLocalTest->setFont(font1);
        addLocalTest->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_16->addWidget(addLocalTest, 0, 1, 1, 1);

        subLocalTest = new QToolButton(frame_13);
        subLocalTest->setObjectName(QString::fromUtf8("subLocalTest"));
        sizePolicy1.setHeightForWidth(subLocalTest->sizePolicy().hasHeightForWidth());
        subLocalTest->setSizePolicy(sizePolicy1);
        subLocalTest->setFont(font1);
        subLocalTest->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_16->addWidget(subLocalTest, 1, 1, 1, 1);

        gridLayout_16->setColumnStretch(0, 10);
        gridLayout_16->setColumnStretch(1, 1);

        gridLayout->addWidget(frame_13, 3, 1, 1, 1);

        frame_14 = new QFrame(frame);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(frame_14);
        gridLayout_18->setSpacing(1);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        cbWorkExcutor = new QComboBox(frame_14);
        cbWorkExcutor->setObjectName(QString::fromUtf8("cbWorkExcutor"));
        sizePolicy.setHeightForWidth(cbWorkExcutor->sizePolicy().hasHeightForWidth());
        cbWorkExcutor->setSizePolicy(sizePolicy);
        cbWorkExcutor->setStyleSheet(QString::fromUtf8("background-color: rgb(224,220,230);"));

        gridLayout_18->addWidget(cbWorkExcutor, 0, 0, 2, 1);

        addWorkExcutor = new QToolButton(frame_14);
        addWorkExcutor->setObjectName(QString::fromUtf8("addWorkExcutor"));
        sizePolicy1.setHeightForWidth(addWorkExcutor->sizePolicy().hasHeightForWidth());
        addWorkExcutor->setSizePolicy(sizePolicy1);
        addWorkExcutor->setFont(font1);
        addWorkExcutor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_18->addWidget(addWorkExcutor, 0, 1, 1, 1);

        subWorkExcutor = new QToolButton(frame_14);
        subWorkExcutor->setObjectName(QString::fromUtf8("subWorkExcutor"));
        sizePolicy1.setHeightForWidth(subWorkExcutor->sizePolicy().hasHeightForWidth());
        subWorkExcutor->setSizePolicy(sizePolicy1);
        subWorkExcutor->setFont(font1);
        subWorkExcutor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_18->addWidget(subWorkExcutor, 1, 1, 1, 1);

        gridLayout_18->setColumnStretch(0, 10);
        gridLayout_18->setColumnStretch(1, 1);

        gridLayout->addWidget(frame_14, 1, 3, 1, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 3, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(49,67,100);\n"
"font: 11pt \"Sans\";\n"
"font:bold;\n"
"background-color: none;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        frame_17 = new QFrame(frame);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        frame_17->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_17);
        gridLayout_12->setSpacing(1);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        cbIDExcutor = new QComboBox(frame_17);
        cbIDExcutor->setObjectName(QString::fromUtf8("cbIDExcutor"));
        sizePolicy.setHeightForWidth(cbIDExcutor->sizePolicy().hasHeightForWidth());
        cbIDExcutor->setSizePolicy(sizePolicy);
        cbIDExcutor->setStyleSheet(QString::fromUtf8("background-color: rgb(224,220,230);"));

        gridLayout_12->addWidget(cbIDExcutor, 0, 0, 2, 1);

        addIDExcutor = new QToolButton(frame_17);
        addIDExcutor->setObjectName(QString::fromUtf8("addIDExcutor"));
        sizePolicy1.setHeightForWidth(addIDExcutor->sizePolicy().hasHeightForWidth());
        addIDExcutor->setSizePolicy(sizePolicy1);
        addIDExcutor->setFont(font1);
        addIDExcutor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_12->addWidget(addIDExcutor, 0, 1, 1, 1);

        subIDExcutor = new QToolButton(frame_17);
        subIDExcutor->setObjectName(QString::fromUtf8("subIDExcutor"));
        sizePolicy1.setHeightForWidth(subIDExcutor->sizePolicy().hasHeightForWidth());
        subIDExcutor->setSizePolicy(sizePolicy1);
        subIDExcutor->setFont(font1);
        subIDExcutor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 5pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"border:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_12->addWidget(subIDExcutor, 1, 1, 1, 1);

        gridLayout_12->setColumnStretch(0, 10);

        gridLayout->addWidget(frame_17, 1, 2, 1, 1);

        gridLayout->setRowStretch(0, 1);

        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);


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
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mBtCableTest->sizePolicy().hasHeightForWidth());
        mBtCableTest->setSizePolicy(sizePolicy2);
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
        sizePolicy2.setHeightForWidth(mBtRfTest->sizePolicy().hasHeightForWidth());
        mBtRfTest->setSizePolicy(sizePolicy2);
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
        sizePolicy2.setHeightForWidth(mBtModuleTest->sizePolicy().hasHeightForWidth());
        mBtModuleTest->setSizePolicy(sizePolicy2);
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
        sizePolicy2.setHeightForWidth(mBtMechanicalTest->sizePolicy().hasHeightForWidth());
        mBtMechanicalTest->setSizePolicy(sizePolicy2);
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
        btnMainExit->setText(QString());
        addNameExcutor->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        subNameExcutor->setText(QCoreApplication::translate("MainWindow", "- ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Location Test", nullptr));
        addWorkSupervisor->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        subWorkSupervisor->setText(QCoreApplication::translate("MainWindow", "- ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Supervisor", nullptr));
        addIDSupervisor->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        subIDSupervisor->setText(QCoreApplication::translate("MainWindow", "- ", nullptr));
        addNameSupervisor->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        subNameSupervisor->setText(QCoreApplication::translate("MainWindow", "- ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ID staff", nullptr));
        addLocalTest->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        subLocalTest->setText(QCoreApplication::translate("MainWindow", "- ", nullptr));
        addWorkExcutor->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        subWorkExcutor->setText(QCoreApplication::translate("MainWindow", "- ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Workplace", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Executor", nullptr));
        addIDExcutor->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        subIDExcutor->setText(QCoreApplication::translate("MainWindow", "- ", nullptr));
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
