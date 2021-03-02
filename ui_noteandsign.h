/********************************************************************************
** Form generated from reading UI file 'noteandsign.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEANDSIGN_H
#define UI_NOTEANDSIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_noteAndSign
{
public:
    QGridLayout *gridLayout_5;
    QDialogButtonBox *buttonBox;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QPushButton *btnAddNote;
    QComboBox *cbNoteModule;
    QTextEdit *teNoteReport;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QComboBox *pathSignExcutor;
    QToolButton *btnImportSignExcutor;
    QCheckBox *cbSignExecutor;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QComboBox *pathSignSupervisor;
    QToolButton *btnImportSignSupervisor;
    QCheckBox *cbSignSupervisor;
    QFrame *frame_5;
    QGridLayout *gridLayout_4;
    QLabel *label;

    void setupUi(QDialog *noteAndSign)
    {
        if (noteAndSign->objectName().isEmpty())
            noteAndSign->setObjectName(QString::fromUtf8("noteAndSign"));
        noteAndSign->resize(494, 352);
        noteAndSign->setStyleSheet(QString::fromUtf8("background-color: rgba(227,234,235);\n"
"\n"
""));
        gridLayout_5 = new QGridLayout(noteAndSign);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(2);
        gridLayout_5->setContentsMargins(0, 0, 0, -1);
        buttonBox = new QDialogButtonBox(noteAndSign);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
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

        gridLayout_5->addWidget(buttonBox, 2, 0, 1, 1, Qt::AlignRight);

        frame_3 = new QFrame(noteAndSign);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnAddNote = new QPushButton(frame_3);
        btnAddNote->setObjectName(QString::fromUtf8("btnAddNote"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnAddNote->sizePolicy().hasHeightForWidth());
        btnAddNote->setSizePolicy(sizePolicy1);
        btnAddNote->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 10pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	outline:none;\n"
"}"));

        gridLayout->addWidget(btnAddNote, 0, 0, 1, 1);

        cbNoteModule = new QComboBox(frame_3);
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->addItem(QString());
        cbNoteModule->setObjectName(QString::fromUtf8("cbNoteModule"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbNoteModule->sizePolicy().hasHeightForWidth());
        cbNoteModule->setSizePolicy(sizePolicy2);
        cbNoteModule->setStyleSheet(QString::fromUtf8("background-color: rgba(188,208,210);\n"
"border:none;"));

        gridLayout->addWidget(cbNoteModule, 0, 1, 1, 2);

        teNoteReport = new QTextEdit(frame_3);
        teNoteReport->setObjectName(QString::fromUtf8("teNoteReport"));
        teNoteReport->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:none;"));

        gridLayout->addWidget(teNoteReport, 1, 0, 1, 3);

        frame = new QFrame(frame_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(205,216,217);\n"
"border:none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pathSignExcutor = new QComboBox(frame);
        pathSignExcutor->setObjectName(QString::fromUtf8("pathSignExcutor"));
        sizePolicy2.setHeightForWidth(pathSignExcutor->sizePolicy().hasHeightForWidth());
        pathSignExcutor->setSizePolicy(sizePolicy2);
        pathSignExcutor->setStyleSheet(QString::fromUtf8("background-color: rgba(188,208,210);"));

        gridLayout_3->addWidget(pathSignExcutor, 0, 0, 1, 1);

        btnImportSignExcutor = new QToolButton(frame);
        btnImportSignExcutor->setObjectName(QString::fromUtf8("btnImportSignExcutor"));
        btnImportSignExcutor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 8pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	outline:none;\n"
"}"));

        gridLayout_3->addWidget(btnImportSignExcutor, 0, 1, 1, 1);

        cbSignExecutor = new QCheckBox(frame);
        cbSignExecutor->setObjectName(QString::fromUtf8("cbSignExecutor"));
        cbSignExecutor->setStyleSheet(QString::fromUtf8("QCheckBox{font: 87 9pt \"Sans\"; font: bold; background-color: none; color: rgb(49,67,100);}\n"
"QCheckBox::indicator::unchecked\n"
"{\n"
"	image: url(\":/Test/images/box/box_blank_small.png\");\n"
"}\n"
"QCheckBox::indicator::checked\n"
"{\n"
"	image: url(\":/Test/images/box/box_success_small.png\");\n"
"}\n"
"QCheckBox::hover\n"
"{\n"
"   background-color:rgba(179,192,217);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_3->addWidget(cbSignExecutor, 1, 0, 1, 2);


        gridLayout->addWidget(frame, 2, 0, 1, 2);

        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgba(205,216,217);\n"
"border:none;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pathSignSupervisor = new QComboBox(frame_2);
        pathSignSupervisor->setObjectName(QString::fromUtf8("pathSignSupervisor"));
        sizePolicy2.setHeightForWidth(pathSignSupervisor->sizePolicy().hasHeightForWidth());
        pathSignSupervisor->setSizePolicy(sizePolicy2);
        pathSignSupervisor->setStyleSheet(QString::fromUtf8("background-color: rgba(188,208,210);"));

        gridLayout_2->addWidget(pathSignSupervisor, 0, 0, 1, 1);

        btnImportSignSupervisor = new QToolButton(frame_2);
        btnImportSignSupervisor->setObjectName(QString::fromUtf8("btnImportSignSupervisor"));
        btnImportSignSupervisor->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"border-color: rgb(49, 67, 100);\n"
"color: rgb(49,67,100);\n"
"background-color: rgb(177,188,190); \n"
"font: 87 8pt \"Myriad Pro\";\n"
"font:bold;\n"
"outline:none;\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"   background-color:rgba(146,165,201);\n"
"  	outline:none;\n"
"}"));

        gridLayout_2->addWidget(btnImportSignSupervisor, 0, 1, 1, 1);

        cbSignSupervisor = new QCheckBox(frame_2);
        cbSignSupervisor->setObjectName(QString::fromUtf8("cbSignSupervisor"));
        cbSignSupervisor->setStyleSheet(QString::fromUtf8("QCheckBox{font: 87 9pt \"Sans\"; font: bold; background-color: none; color: rgb(49,67,100);}\n"
"QCheckBox::indicator::unchecked\n"
"{\n"
"	image: url(\":/Test/images/box/box_blank_small.png\");\n"
"}\n"
"QCheckBox::indicator::checked\n"
"{\n"
"	image: url(\":/Test/images/box/box_success_small.png\");\n"
"}\n"
"QCheckBox::hover\n"
"{\n"
"   background-color:rgba(179,192,217);\n"
"  	border:none;\n"
"  	outline:none;\n"
"}"));

        gridLayout_2->addWidget(cbSignSupervisor, 1, 0, 1, 2);


        gridLayout->addWidget(frame_2, 2, 2, 1, 1);


        gridLayout_5->addWidget(frame_3, 1, 0, 1, 1);

        frame_5 = new QFrame(noteAndSign);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgb(149,165,166);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(frame_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 87 10.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);;"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);


        gridLayout_5->addWidget(frame_5, 0, 0, 1, 1);


        retranslateUi(noteAndSign);
        QObject::connect(buttonBox, SIGNAL(accepted()), noteAndSign, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), noteAndSign, SLOT(reject()));

        QMetaObject::connectSlotsByName(noteAndSign);
    } // setupUi

    void retranslateUi(QDialog *noteAndSign)
    {
        noteAndSign->setWindowTitle(QCoreApplication::translate("noteAndSign", "Dialog", nullptr));
        btnAddNote->setText(QCoreApplication::translate("noteAndSign", "Add Note", nullptr));
        cbNoteModule->setItemText(0, QCoreApplication::translate("noteAndSign", "Adapter Circulator", nullptr));
        cbNoteModule->setItemText(1, QCoreApplication::translate("noteAndSign", "Adapter Comparator", nullptr));
        cbNoteModule->setItemText(2, QCoreApplication::translate("noteAndSign", "Adapter SMA", nullptr));
        cbNoteModule->setItemText(3, QCoreApplication::translate("noteAndSign", "Antena", nullptr));
        cbNoteModule->setItemText(4, QCoreApplication::translate("noteAndSign", "ATT Xband", nullptr));
        cbNoteModule->setItemText(5, QCoreApplication::translate("noteAndSign", "FilterIF", nullptr));
        cbNoteModule->setItemText(6, QCoreApplication::translate("noteAndSign", "Filter LOIF", nullptr));
        cbNoteModule->setItemText(7, QCoreApplication::translate("noteAndSign", "Filter LORF", nullptr));
        cbNoteModule->setItemText(8, QCoreApplication::translate("noteAndSign", "Filter Xband", nullptr));
        cbNoteModule->setItemText(9, QCoreApplication::translate("noteAndSign", "HPA", nullptr));
        cbNoteModule->setItemText(10, QCoreApplication::translate("noteAndSign", "Limiter Diff", nullptr));
        cbNoteModule->setItemText(11, QCoreApplication::translate("noteAndSign", "Limiter Sum", nullptr));
        cbNoteModule->setItemText(12, QCoreApplication::translate("noteAndSign", "LNA", nullptr));
        cbNoteModule->setItemText(13, QCoreApplication::translate("noteAndSign", "LO", nullptr));
        cbNoteModule->setItemText(14, QCoreApplication::translate("noteAndSign", "RX", nullptr));
        cbNoteModule->setItemText(15, QCoreApplication::translate("noteAndSign", "TX", nullptr));
        cbNoteModule->setItemText(16, QCoreApplication::translate("noteAndSign", "Switch Antena", nullptr));

        btnImportSignExcutor->setText(QCoreApplication::translate("noteAndSign", "...", nullptr));
        cbSignExecutor->setText(QCoreApplication::translate("noteAndSign", "Hi\341\273\207n ch\341\273\257 k\303\255 ng\306\260\341\273\235i th\341\273\261c hi\341\273\207n", nullptr));
        btnImportSignSupervisor->setText(QCoreApplication::translate("noteAndSign", "...", nullptr));
        cbSignSupervisor->setText(QCoreApplication::translate("noteAndSign", "HI\341\273\207n ch\341\273\257 k\303\255 ng\306\260\341\273\235i ki\341\273\203m tra", nullptr));
        label->setText(QCoreApplication::translate("noteAndSign", "\304\220\341\273\223ng \303\275 xu\341\272\245t b\303\241o c\303\241o nh\341\273\257ng m\341\273\245c \304\221\303\243 ch\341\273\215n?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class noteAndSign: public Ui_noteAndSign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEANDSIGN_H
