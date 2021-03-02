/********************************************************************************
** Form generated from reading UI file 'instrumentusart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUMENTUSART_H
#define UI_INSTRUMENTUSART_H

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

class Ui_instrumentUsart
{
public:
    QGridLayout *gridLayout_5;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *leNameIntrUsart;
    QLabel *label_5;
    QLineEdit *leSerialIntrUart;
    QLabel *label_3;
    QComboBox *cbModelInstrUart;
    QLabel *label_6;
    QLineEdit *leDtimeInstrUsart;
    QLabel *label_4;
    QLineEdit *leErrInstrUart;
    QPushButton *pushButton;
    QFrame *frame_4;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QComboBox *cbComport;
    QLabel *label_8;
    QLineEdit *leBaudrate;
    QDialogButtonBox *buttonBox;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QLabel *label;

    void setupUi(QDialog *instrumentUsart)
    {
        if (instrumentUsart->objectName().isEmpty())
            instrumentUsart->setObjectName(QString::fromUtf8("instrumentUsart"));
        instrumentUsart->resize(569, 303);
        gridLayout_5 = new QGridLayout(instrumentUsart);
        gridLayout_5->setSpacing(2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, -1);
        frame_2 = new QFrame(instrumentUsart);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        leNameIntrUsart = new QLineEdit(frame_3);
        leNameIntrUsart->setObjectName(QString::fromUtf8("leNameIntrUsart"));

        gridLayout->addWidget(leNameIntrUsart, 0, 1, 1, 1);

        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        leSerialIntrUart = new QLineEdit(frame_3);
        leSerialIntrUart->setObjectName(QString::fromUtf8("leSerialIntrUart"));

        gridLayout->addWidget(leSerialIntrUart, 0, 3, 1, 1);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        cbModelInstrUart = new QComboBox(frame_3);
        cbModelInstrUart->setObjectName(QString::fromUtf8("cbModelInstrUart"));

        gridLayout->addWidget(cbModelInstrUart, 1, 1, 1, 1);

        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        leDtimeInstrUsart = new QLineEdit(frame_3);
        leDtimeInstrUsart->setObjectName(QString::fromUtf8("leDtimeInstrUsart"));

        gridLayout->addWidget(leDtimeInstrUsart, 1, 3, 1, 1);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        leErrInstrUart = new QLineEdit(frame_3);
        leErrInstrUart->setObjectName(QString::fromUtf8("leErrInstrUart"));

        gridLayout->addWidget(leErrInstrUart, 2, 1, 1, 1);

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

        gridLayout->addWidget(pushButton, 2, 3, 1, 1);


        gridLayout_3->addWidget(frame_3, 0, 0, 1, 1);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        cbComport = new QComboBox(frame_4);
        cbComport->setObjectName(QString::fromUtf8("cbComport"));

        gridLayout_2->addWidget(cbComport, 0, 1, 1, 1);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 87 9.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout_2->addWidget(label_8, 0, 2, 1, 1);

        leBaudrate = new QLineEdit(frame_4);
        leBaudrate->setObjectName(QString::fromUtf8("leBaudrate"));

        gridLayout_2->addWidget(leBaudrate, 0, 3, 1, 1);


        gridLayout_3->addWidget(frame_4, 1, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 3);
        gridLayout_3->setRowStretch(1, 2);

        gridLayout_5->addWidget(frame_2, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(instrumentUsart);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_5->addWidget(buttonBox, 2, 1, 1, 1);

        frame = new QFrame(instrumentUsart);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgb(149,165,166);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 87 10.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);


        gridLayout_5->addWidget(frame, 0, 0, 1, 2);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setRowStretch(1, 8);

        retranslateUi(instrumentUsart);
        QObject::connect(buttonBox, SIGNAL(accepted()), instrumentUsart, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), instrumentUsart, SLOT(reject()));

        QMetaObject::connectSlotsByName(instrumentUsart);
    } // setupUi

    void retranslateUi(QDialog *instrumentUsart)
    {
        instrumentUsart->setWindowTitle(QCoreApplication::translate("instrumentUsart", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("instrumentUsart", "T\303\252n m\303\241y \304\221o", nullptr));
        label_5->setText(QCoreApplication::translate("instrumentUsart", "S\341\273\221 hi\341\273\207u", nullptr));
        label_3->setText(QCoreApplication::translate("instrumentUsart", "K\303\255 hi\341\273\207u/Model", nullptr));
        label_6->setText(QCoreApplication::translate("instrumentUsart", "H\341\272\241n \304\221\304\203ng ki\341\273\203m", nullptr));
        label_4->setText(QCoreApplication::translate("instrumentUsart", "Sai s\341\273\221 m\303\241y \304\221o", nullptr));
        pushButton->setText(QCoreApplication::translate("instrumentUsart", "Gi\341\272\245y ch\341\273\251ng nh\341\272\255n \304\221i k\303\250m", nullptr));
        label_7->setText(QCoreApplication::translate("instrumentUsart", "COM PORT", nullptr));
        label_8->setText(QCoreApplication::translate("instrumentUsart", "Baudrate", nullptr));
        label->setText(QCoreApplication::translate("instrumentUsart", "C\341\272\245u h\303\254nh m\303\241y \304\221o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class instrumentUsart: public Ui_instrumentUsart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUMENTUSART_H
