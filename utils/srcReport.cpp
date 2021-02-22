#include "srcReport.h"
#include "QDebug"
#include "ui_mainwindow.h"
#include "ui_testelectriccable.h"
#include "ui_testmodule.h"
#include "ui_testrfcable.h"
#include "ui_testmechanical.h"

srcReport::srcReport()
{
    qDebug() << "[srcReport] Constructor";
    mbussiness = new bussinessManager();
}

srcReport::~srcReport()
{
    qDebug() << "[srcReport] Destructor";
}

void srcReport::creatHeader(KDReports::Report *report, QString typeTest, QString namepart)
{
    report->setHeaderBodySpacing( 10 ); // mm
    report->setFooterBodySpacing( 10 ); // mm

    KDReports::Header& header = report->header( KDReports::OddPages );

    KDReports::TextElement mainTitle("Test Report \t \t \t \t");
    mainTitle.setBold(true);
    mainTitle.setPointSize(30);

    QPixmap kdab( ":/Test/images/logo_vtx.png" );
    KDReports::ImageElement imageElement( kdab );
    imageElement.setWidth( 20, KDReports::Percent );

    header.addElement(mainTitle);
    header.addInlineElement(imageElement );
    header.addElement(KDReports::HLineElement());

    header.addElement(KDReports::TextElement("Type:"));
    header.addInlineElement(KDReports::TextElement(typeTest));
    header.addElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("Test Date: "));
    header.addVariable( KDReports::TextDate);
    header.addInlineElement(KDReports::TextElement("\t \t"));
    header.addInlineElement(KDReports::TextElement("RunNumber: "));
    if (typeTest == "Electrical Cable") {
        header.addElement(KDReports::TextElement("Name Cable: "));
    }
    else if (typeTest == "Module Test") {
        header.addElement(KDReports::TextElement("Name Module: "));
    }
    header.addInlineElement(KDReports::TextElement(namepart));
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("Test Time: "));
    header.addVariable( KDReports::TextTime);
    header.addInlineElement(KDReports::TextElement("\t \t \t"));
    header.addInlineElement(KDReports::TextElement("Place: "));
    //header.addInlineElement(KDReports::TextElement(mUi->mLeLocalTest->text()));
    header.addElement(KDReports::HLineElement());

    header.addElement(KDReports::TextElement("Excutor: "));
    //header.addInlineElement(KDReports::TextElement(mUi->mLeNameExecutor->text()));
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("ID Excutor: "));
    //header.addInlineElement(KDReports::TextElement(mUi->mLeIDExecutor->text()));
    header.addInlineElement(KDReports::TextElement("\t \t"));
    header.addInlineElement(KDReports::TextElement("WorkdPlace: "));
    //header.addInlineElement(KDReports::TextElement(mUi->mLeWorkExecutor->text()));

    header.addElement(KDReports::TextElement("Supervisor: "));
    //header.addInlineElement(KDReports::TextElement(mUi->mLeNameSupervisor->text()));
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("ID Supervisor: "));
   // header.addInlineElement(KDReports::TextElement(mUi->mLeIDSupervisor->text()));
    header.addInlineElement(KDReports::TextElement("\t \t"));
    header.addInlineElement(KDReports::TextElement("WorkdPlace: "));
    //header.addInlineElement(KDReports::TextElement(mUi->mLeWorkSupervisor->text()));
    header.addElement(KDReports::HLineElement());
}
