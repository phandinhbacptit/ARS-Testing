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
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QFrame *line;
    QFrame *frame_4;
    QGridLayout *gridLayout;
    QPushButton *btnAddNote;
    QComboBox *cbNoteModule;
    QFrame *frame_3;
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
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *noteAndSign)
    {
        if (noteAndSign->objectName().isEmpty())
            noteAndSign->setObjectName(QString::fromUtf8("noteAndSign"));
        noteAndSign->resize(484, 352);
        noteAndSign->setStyleSheet(QString::fromUtf8("background-color: rgba(227,234,235);\n"
"\n"
""));
        gridLayout_4 = new QGridLayout(noteAndSign);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_2 = new QLabel(noteAndSign);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 87 10.5pt \"Sans\"; font:bold; background-color: none; color: rgb(49,67,100);"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 2);

        line = new QFrame(noteAndSign);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 1, 0, 1, 2);

        frame_4 = new QFrame(noteAndSign);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8(""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setContentsMargins(0, 5, 0, 0);
        btnAddNote = new QPushButton(frame_4);
        btnAddNote->setObjectName(QString::fromUtf8("btnAddNote"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAddNote->sizePolicy().hasHeightForWidth());
        btnAddNote->setSizePolicy(sizePolicy);
        btnAddNote->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        gridLayout->addWidget(btnAddNote, 0, 0, 1, 1);

        cbNoteModule = new QComboBox(frame_4);
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
        sizePolicy.setHeightForWidth(cbNoteModule->sizePolicy().hasHeightForWidth());
        cbNoteModule->setSizePolicy(sizePolicy);
        cbNoteModule->setStyleSheet(QString::fromUtf8("background-color: rgba(188,208,210);\n"
"border:none;"));

        gridLayout->addWidget(cbNoteModule, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 3);

        gridLayout_4->addWidget(frame_4, 2, 0, 1, 1);

        frame_3 = new QFrame(noteAndSign);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"border:none;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);

        gridLayout_4->addWidget(frame_3, 2, 1, 1, 1);

        teNoteReport = new QTextEdit(noteAndSign);
        teNoteReport->setObjectName(QString::fromUtf8("teNoteReport"));
        teNoteReport->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:none;"));

        gridLayout_4->addWidget(teNoteReport, 3, 0, 1, 2);

        frame = new QFrame(noteAndSign);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(205,216,217);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pathSignExcutor = new QComboBox(frame);
        pathSignExcutor->setObjectName(QString::fromUtf8("pathSignExcutor"));

        gridLayout_3->addWidget(pathSignExcutor, 0, 0, 1, 1);

        btnImportSignExcutor = new QToolButton(frame);
        btnImportSignExcutor->setObjectName(QString::fromUtf8("btnImportSignExcutor"));

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


        gridLayout_4->addWidget(frame, 4, 0, 1, 1);

        frame_2 = new QFrame(noteAndSign);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgba(205,216,217);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pathSignSupervisor = new QComboBox(frame_2);
        pathSignSupervisor->setObjectName(QString::fromUtf8("pathSignSupervisor"));

        gridLayout_2->addWidget(pathSignSupervisor, 0, 0, 1, 1);

        btnImportSignSupervisor = new QToolButton(frame_2);
        btnImportSignSupervisor->setObjectName(QString::fromUtf8("btnImportSignSupervisor"));

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


        gridLayout_4->addWidget(frame_2, 4, 1, 1, 1);

        buttonBox = new QDialogButtonBox(noteAndSign);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
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

        gridLayout_4->addWidget(buttonBox, 5, 1, 1, 1);


        retranslateUi(noteAndSign);
        QObject::connect(buttonBox, SIGNAL(accepted()), noteAndSign, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), noteAndSign, SLOT(reject()));

        QMetaObject::connectSlotsByName(noteAndSign);
    } // setupUi

    void retranslateUi(QDialog *noteAndSign)
    {
        noteAndSign->setWindowTitle(QCoreApplication::translate("noteAndSign", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("noteAndSign", "\304\220\341\273\223ng \303\275 xu\341\272\245t b\303\241o c\303\241o nh\341\273\257ng m\341\273\245c \304\221\303\243 ch\341\273\215n?", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class noteAndSign: public Ui_noteAndSign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEANDSIGN_H
