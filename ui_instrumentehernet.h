/********************************************************************************
** Form generated from reading UI file 'instrumentehernet.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUMENTEHERNET_H
#define UI_INSTRUMENTEHERNET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_instrumentEhernet
{
public:
    QGridLayout *gridLayout_4;
    QFrame *frame_4;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *leSerial;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *leRegisDeadline;
    QLabel *label_6;
    QLineEdit *leErrorInstrument;
    QLineEdit *leNameInstrument;
    QLabel *label_4;
    QPushButton *pushButton;
    QComboBox *cbTypeInstr;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *leIp;
    QLabel *label_8;
    QLineEdit *lePort;
    QDialogButtonBox *selectInstrument;

    void setupUi(QDialog *instrumentEhernet)
    {
        if (instrumentEhernet->objectName().isEmpty())
            instrumentEhernet->setObjectName(QString::fromUtf8("instrumentEhernet"));
        instrumentEhernet->resize(572, 295);
        instrumentEhernet->setStyleSheet(QString::fromUtf8("background-color:rgb(245, 245, 245);"));
        gridLayout_4 = new QGridLayout(instrumentEhernet);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, -1);
        frame_4 = new QFrame(instrumentEhernet);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgb(149,165,166);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 87 10.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame_4, 0, 0, 1, 1);

        frame = new QFrame(instrumentEhernet);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        leSerial = new QLineEdit(frame_3);
        leSerial->setObjectName(QString::fromUtf8("leSerial"));

        gridLayout->addWidget(leSerial, 1, 4, 1, 1);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_5, 2, 3, 1, 1);

        leRegisDeadline = new QLineEdit(frame_3);
        leRegisDeadline->setObjectName(QString::fromUtf8("leRegisDeadline"));

        gridLayout->addWidget(leRegisDeadline, 2, 4, 1, 1);

        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        leErrorInstrument = new QLineEdit(frame_3);
        leErrorInstrument->setObjectName(QString::fromUtf8("leErrorInstrument"));

        gridLayout->addWidget(leErrorInstrument, 3, 2, 1, 1);

        leNameInstrument = new QLineEdit(frame_3);
        leNameInstrument->setObjectName(QString::fromUtf8("leNameInstrument"));

        gridLayout->addWidget(leNameInstrument, 1, 2, 1, 1);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 8pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	outline:none;\n"
"}"));

        gridLayout->addWidget(pushButton, 3, 4, 1, 1);

        cbTypeInstr = new QComboBox(frame_3);
        cbTypeInstr->setObjectName(QString::fromUtf8("cbTypeInstr"));

        gridLayout->addWidget(cbTypeInstr, 2, 2, 1, 1);


        gridLayout_3->addWidget(frame_3, 0, 0, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        leIp = new QLineEdit(frame_2);
        leIp->setObjectName(QString::fromUtf8("leIp"));

        gridLayout_2->addWidget(leIp, 0, 1, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout_2->addWidget(label_8, 0, 2, 1, 1);

        lePort = new QLineEdit(frame_2);
        lePort->setObjectName(QString::fromUtf8("lePort"));

        gridLayout_2->addWidget(lePort, 0, 3, 1, 1);

        gridLayout_2->setColumnStretch(1, 3);
        gridLayout_2->setColumnStretch(3, 2);

        gridLayout_3->addWidget(frame_2, 1, 0, 1, 1);


        gridLayout_4->addWidget(frame, 1, 0, 1, 1);

        selectInstrument = new QDialogButtonBox(instrumentEhernet);
        selectInstrument->setObjectName(QString::fromUtf8("selectInstrument"));
        selectInstrument->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 8pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	outline:none;\n"
"}"));
        selectInstrument->setOrientation(Qt::Horizontal);
        selectInstrument->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_4->addWidget(selectInstrument, 2, 0, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 6);

        retranslateUi(instrumentEhernet);
        QObject::connect(selectInstrument, SIGNAL(accepted()), instrumentEhernet, SLOT(accept()));
        QObject::connect(selectInstrument, SIGNAL(rejected()), instrumentEhernet, SLOT(reject()));

        QMetaObject::connectSlotsByName(instrumentEhernet);
    } // setupUi

    void retranslateUi(QDialog *instrumentEhernet)
    {
        instrumentEhernet->setWindowTitle(QCoreApplication::translate("instrumentEhernet", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("instrumentEhernet", "C\341\272\245u h\303\254nh m\303\241y \304\221o", nullptr));
        label_2->setText(QCoreApplication::translate("instrumentEhernet", "T\303\252n m\303\241y \304\221o", nullptr));
        label_3->setText(QCoreApplication::translate("instrumentEhernet", "K\303\255 hi\341\273\207u/Model", nullptr));
        label_5->setText(QCoreApplication::translate("instrumentEhernet", "H\341\272\241n \304\221\304\203ng ki\341\273\203m", nullptr));
        label_6->setText(QCoreApplication::translate("instrumentEhernet", "Sai s\341\273\221 m\303\241y \304\221o", nullptr));
        label_4->setText(QCoreApplication::translate("instrumentEhernet", "S\341\273\221 hi\341\273\207u", nullptr));
        pushButton->setText(QCoreApplication::translate("instrumentEhernet", "Gi\341\272\245y ch\341\273\251ng nh\341\272\255n \304\221i k\303\250m", nullptr));
        label_7->setText(QCoreApplication::translate("instrumentEhernet", "\304\220\341\273\213a ch\341\273\211 IP", nullptr));
        label_8->setText(QCoreApplication::translate("instrumentEhernet", "Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class instrumentEhernet: public Ui_instrumentEhernet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUMENTEHERNET_H
