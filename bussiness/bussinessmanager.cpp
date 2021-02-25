#include "bussiness/bussinessmanager.h"
#include "ui_mainwindow.h"
#include "ui_testelectriccable.h"
#include "ui_testmodule.h"
#include "ui_testrfcable.h"
#include "ui_testmechanical.h"
#include "utils/logutils.h"

bussinessManager::bussinessManager(QObject *parent) : QObject(parent)
{
    qDebug() << "[Bussiness] Constructor";
    mUi = NULL;
//    reportElectrical = NULL;
    //mCTE = NULL;

//    reportElectrical.setDocumentName("Electrical Report");
}
bussinessManager::~bussinessManager()
{
    qDebug() << "[Bussiness] Destructor";

    if (mTestElectricalCable != NULL) {
       delete mTestElectricalCable;
       mTestElectricalCable = NULL;
    }

    if (mTestModule != NULL) {
       delete mTestModule;
       mTestModule = NULL;
    }

    if (mTestRfCable != NULL) {
       delete mTestRfCable;
       mTestRfCable = NULL;
    }

//    if (reportElectrical != NULL) {
//        delete reportElectrical;
//        reportElectrical = NULL;
//    }

}

Ui::MainWindow *bussinessManager::ui() const
{
    return mUi;
}

Ui::TestElectricCable *bussinessManager::getGui() const
{
    return mCTE;
}

Ui::testModule *bussinessManager::getGuiMte() const
{
    return mMTE;
}

//Ui::TestRfCable *bussinessManager::getGui() const
//{
//    return mRFTE;
//}


void bussinessManager::setup(Ui::MainWindow *ui)
{
    if (ui != NULL) {

        this->mUi = ui;
    }
    connect(mUi->mLeNameExecutor, SIGNAL(textChanged(QString)), this, SLOT(slt_enableTestProcess()));
    connect(mUi->mLeIDExecutor, SIGNAL(textChanged(QString)), this, SLOT(slt_enableTestProcess()));
    connect(mUi->mLeWorkExecutor, SIGNAL(textChanged(QString)), this, SLOT(slt_enableTestProcess()));
    connect(mUi->mLeNameSupervisor, SIGNAL(textChanged(QString)), this, SLOT(slt_enableTestProcess()));
    connect(mUi->mLeIDSupervisor, SIGNAL(textChanged(QString)), this, SLOT(slt_enableTestProcess()));
    connect(mUi->mLeWorkSupervisor, SIGNAL(textChanged(QString)), this, SLOT(slt_enableTestProcess()));
    connect(mUi->mLeLocalTest, SIGNAL(textChanged(QString)), this, SLOT(slt_enableTestProcess()));

    connect(mUi->mBtCableTest, SIGNAL(clicked()), this, SLOT(slt_showCteInterface()));
    connect(mUi->mBtModuleTest, SIGNAL(clicked()), this, SLOT(slt_showMteInterface()));
    connect(mUi->mBtRfTest, SIGNAL(clicked()), this, SLOT(slt_showRfteInterface()));

    qDebug() << "[Bussiness] Setup MainWindow";
}

void bussinessManager::setupELectric(Ui::TestElectricCable *ui)
{
    if(ui != NULL) {
        this->mCTE = ui;
    }
    connect(mCTE->btnExportCte, SIGNAL(clicked()), this, SLOT(slt_exportCteReport()));
    connect(mCTE->btnRunCte, SIGNAL(clicked()), this, SLOT(slt_runCTE()));
    connect(mCTE->btnLogCte, SIGNAL(clicked()), this, SLOT(slt_logCTE()));
    connect(mCTE->btnStopCte, SIGNAL(clicked()), this, SLOT(slt_stopCTE()));

    connect(mCTE->mCbCable1, SIGNAL(clicked(bool)), this, SLOT(slt_resultTest(bool)));
    connect(mTestElectricalCable, &TestElectricCable::sign_checkAllCable, this, &bussinessManager::slt_resultTest, Qt::UniqueConnection);
    qDebug() << "[Bussiness] Setup gui CTE";
}

void bussinessManager::setupModule(Ui::testModule *ui)
{
    if(ui != NULL) {
        this->mMTE = ui;
    }
    connect(mMTE->btnRunMte, SIGNAL(clicked()), this, SLOT(slt_runMTE()));
    connect(mMTE->btnLogMte, SIGNAL(clicked()), this, SLOT(slt_logMTE()));
    connect(mMTE->btnStopMte, SIGNAL(clicked()), this, SLOT(slt_stopMTE()));
    connect(mMTE->btnPreviewMte, SIGNAL(clicked()), this, SLOT(slt_previewMteReport()));
    connect(mMTE->btnExportMte, SIGNAL(clicked()), this, SLOT(slt_exportMteReport()));

    connect(mMTE->btnDcPwr, SIGNAL(clicked()), this, SLOT(slt_connDcPower()));
    connect(mMTE->btnDcLoad, SIGNAL(clicked()), this, SLOT(slt_connDcLoad()));
    connect(mMTE->btnOscil, SIGNAL(clicked()), this, SLOT(slt_connOsiloscope()));
    connect(mMTE->btnNoiseSrc, SIGNAL(clicked()), this, SLOT(slt_connNoiseSource()));
    connect(mMTE->btnWaveGen, SIGNAL(clicked()), this, SLOT(slt_connWaveGeneration()));
    connect(mMTE->btnSignGen, SIGNAL(clicked()), this, SLOT(slt_connSignalGeneration()));
    connect(mMTE->btnNetAnalizer, SIGNAL(clicked()), this, SLOT(slt_connNetworkAnalizer()));
    connect(mMTE->btnSpecAnalizer, SIGNAL(clicked()), this, SLOT(slt_connSpectumeAnalizer()));
    connect(mMTE->btnGuidleMte, SIGNAL(clicked()), this, SLOT(slt_guidlefile()));

    qDebug() << "[Bussiness] Setup gui MTE";
}

void bussinessManager::setupRf(Ui::TestRfCable *ui)
{
    if(ui != NULL) {
        this->mRFTE = ui;
    }
    connect(mRFTE->btnRunRfte, SIGNAL(clicked()), this, SLOT(slt_runRFTE()));
    connect(mRFTE->btnLogRfte, SIGNAL(clicked()), this, SLOT(slt_logRFTE()));
    connect(mRFTE->btnStopRfte, SIGNAL(clicked()), this, SLOT(slt_stopRFTE()));
    qDebug() << "[Bussiness] Setup gui RFTE";
}
void bussinessManager::createTable(KDReports::Report *report, QString Title, QString pathCsv)
{
    const QColor titleElementColor( 204, 204, 255 );
    KDReports::TextElement tableTitleElement(Title);
    tableTitleElement.setBold( true );
    tableTitleElement.setFont(QFont("Sans-serif"));
    report->addElement( tableTitleElement, Qt::AlignLeft, titleElementColor );
    TableModel R_Cable;
    R_Cable.setDataHasVerticalHeaders(false);
    R_Cable.loadFromCSV(pathCsv);
    KDReports::AutoTableElement autoTableElement1( &R_Cable );
    autoTableElement1.setWidth( 100, KDReports::Percent );
    report->addElement( autoTableElement1 );
    report->addVerticalSpacing(5);
}
void bussinessManager::createReport(KDReports::Report *report, QString typeTest, table part, QString mode)
{
    report->setHeaderBodySpacing(1); // mm
    report->setFooterBodySpacing(1); // mm
    report->defaultFont();

    KDReports::Header& header = report->header( KDReports::OddPages );

    KDReports::TextElement mainTitle("Test Report \t \t \t");
    mainTitle.setBold(true);
    mainTitle.setPointSize(30);
    mainTitle.setFont(QFont( "Sans-serif"));

    QPixmap kdab( ":/Test/images/logo_vtx.png" );
    KDReports::ImageElement imageElement( kdab );
    imageElement.setWidth( 20, KDReports::Percent );

    header.addElement(mainTitle);
    header.addInlineElement(imageElement );
    header.addElement(KDReports::HLineElement());

    header.addElement(KDReports::TextElement("Type: "));
    if (typeTest == "CTE") {
        header.addInlineElement(KDReports::TextElement("Kiểm tra cáp điện"));
    }
    else if (typeTest == "MTE") {
        header.addInlineElement(KDReports::TextElement("Kiểm tra module"));
    }
    header.addInlineElement(KDReports::TextElement("\t \t"));
    header.addInlineElement(KDReports::TextElement("Test Date: "));
    header.addVariable( KDReports::TextDate);
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("RunNumber: "));
    if (typeTest == "CTE") {
        header.addElement(KDReports::TextElement("Name Cable: "));
    }
    else if (typeTest == "MTE") {
        header.addElement(KDReports::TextElement("Name Module: "));
    }
    header.addInlineElement(KDReports::TextElement(part.namePart));
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("Test Time: "));
    header.addVariable( KDReports::TextTime);
    header.addInlineElement(KDReports::TextElement("\t \t \t"));
    header.addInlineElement(KDReports::TextElement("Place: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeLocalTest->text()));
    header.addElement(KDReports::HLineElement());

    header.addElement(KDReports::TextElement("Excutor: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeNameExecutor->text()));
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("ID Excutor: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeIDExecutor->text()));
    header.addInlineElement(KDReports::TextElement("\t \t"));
    header.addInlineElement(KDReports::TextElement("WorkdPlace: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeWorkExecutor->text()));

    header.addElement(KDReports::TextElement("Supervisor: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeNameSupervisor->text()));
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("ID Supervisor: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeIDSupervisor->text()));
    header.addInlineElement(KDReports::TextElement("\t \t"));
    header.addInlineElement(KDReports::TextElement("WorkdPlace: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeWorkSupervisor->text()));
    header.addElement(KDReports::HLineElement());



    if (part.title1 != NULL) {
        createTable(report, part.title1, part.pathPart1);
    }
    if (part.title2 != NULL) {
        createTable(report, part.title2, part.pathPart2);
    }
    if (part.title3 != NULL) {
        createTable(report, part.title3, part.pathPart3);
    }
    if (part.title4 != NULL) {
        createTable(report, part.title4, part.pathPart4);
    }
    if (part.title5 != NULL) {
        createTable(report, part.title5, part.pathPart5);
    }
    if (part.title6 != NULL) {
        createTable(report, part.title6, part.pathPart6);
    }
    if (part.title7 != NULL) {
        createTable(report, part.title7, part.pathPart7);
    }
    qDebug() << "Export " + part.namePart + " report";


    report->footer().addElement(KDReports::HLineElement());
    KDReports::TextElement footerText;
    footerText << "Report of " + part.namePart + " trên ĐTD VCM-01, TT Đầu tự dẫn, Viện HKVT";
    footerText.setPointSize(8);
    report->footer().addElement( footerText, Qt::AlignCenter );

    KDReports::TableElement tableFooter;
    tableFooter.setHeaderRowCount(2);
    tableFooter.setPadding(0);
    tableFooter.setBorder(0);
    QColor headerColor("#DADADF");

    QDate _current = QDate::currentDate();
    //qDebug() << " Date: " + QString::number(_current.day());

    KDReports::Cell& topSupervisor = tableFooter.cell(0, 0);
    topSupervisor.addInlineElement(KDReports::TextElement(" \t \t \t \t \t  "));

    KDReports::Cell& topExcutor = tableFooter.cell(0,1 );
    topExcutor.addElement(KDReports::TextElement(mUi->mLeLocalTest->text() +
                                                 ", Ngày " + QString::number(_current.day()) +
                                                 " tháng " + QString::number(_current.month()) +
                                                 " năm " + QString::number(_current.year())
                                                 ), Qt::AlignHCenter);
    topExcutor.addInlineElement(KDReports::TextElement("\t \t \t "));


    tableFooter.cell(1,0).addElement(KDReports::TextElement("Người thực hiện"), Qt::AlignCenter);
    tableFooter.cell(1,0).addElement(KDReports::TextElement("(Ký, họ tên)"), Qt::AlignCenter);
    tableFooter.cell(1,0).addElement(KDReports::TextElement("               "), Qt::AlignCenter);
    tableFooter.cell(1,0).addElement(KDReports::TextElement("               "), Qt::AlignCenter);
    tableFooter.cell(1,0).addElement(KDReports::TextElement("               "), Qt::AlignCenter);
    tableFooter.cell(1,0).addElement(KDReports::TextElement("               "), Qt::AlignCenter);
    tableFooter.cell(1,0).addElement(KDReports::TextElement(mUi->mLeNameExecutor->text()),
                                     Qt::AlignCenter);

    tableFooter.cell(1,1).addElement(KDReports::TextElement("Người giám sát"), Qt::AlignCenter);
    tableFooter.cell(1,1).addElement(KDReports::TextElement("(Ký, họ tên)"), Qt::AlignCenter);
    tableFooter.cell(1,1).addElement(KDReports::TextElement("               "), Qt::AlignCenter);
    tableFooter.cell(1,1).addElement(KDReports::TextElement("               "), Qt::AlignCenter);
    tableFooter.cell(1,1).addElement(KDReports::TextElement("               "), Qt::AlignCenter);
    tableFooter.cell(1,1).addElement(KDReports::TextElement("               "), Qt::AlignCenter);
    tableFooter.cell(1,1).addElement(KDReports::TextElement(mUi->mLeNameSupervisor->text()), Qt::AlignCenter);
    report->addElement(tableFooter);

    if (mode == "AutoSave") {
        if (!QDir("report/module").exists()) {
          QDir().mkdir("report/module");
        }

        report->exportToFile("Report_" + part.namePart +
                             QTime::currentTime().toString("_hh.mm.ss") +
                             QDate::currentDate().toString("_dd.MM.yyyy"), NULL);
    }

    else if (mode == "Preview") {
        KDReports::PreviewDialog preview(reportCTE);
        preview.exec();
    }
}

void bussinessManager::createCableReport(KDReports::Report *report, QString nameCable)
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

    header.addElement(KDReports::TextElement(" \t \t"));
    header.addInlineElement(KDReports::TextElement("Test Date: "));
    header.addVariable( KDReports::TextDate);
    header.addInlineElement(KDReports::TextElement("\t \t"));
    header.addInlineElement(KDReports::TextElement("RunNumber: "));
    header.addElement(KDReports::TextElement("Name Cable: "));
    header.addInlineElement(KDReports::TextElement(nameCable));
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("Test Time: "));
    header.addVariable( KDReports::TextTime);
    header.addInlineElement(KDReports::TextElement("\t \t \t"));
    header.addInlineElement(KDReports::TextElement("Place: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeLocalTest->text()));
    header.addElement(KDReports::HLineElement());

    header.addElement(KDReports::TextElement("Excutor: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeNameExecutor->text()));
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("ID Excutor: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeIDExecutor->text()));
    header.addInlineElement(KDReports::TextElement("\t \t"));
    header.addInlineElement(KDReports::TextElement("WorkdPlace: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeWorkExecutor->text()));

    header.addElement(KDReports::TextElement("Supervisor: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeNameSupervisor->text()));
    header.addInlineElement(KDReports::TextElement("\t"));
    header.addInlineElement(KDReports::TextElement("ID Supervisor: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeIDSupervisor->text()));
    header.addInlineElement(KDReports::TextElement("\t \t"));
    header.addInlineElement(KDReports::TextElement("WorkdPlace: "));
    header.addInlineElement(KDReports::TextElement(mUi->mLeWorkSupervisor->text()));
    header.addElement(KDReports::HLineElement());

    const QColor titleElementColor( 204, 204, 255 );
    KDReports::TextElement tableTitleElement( "Resistance" );
    tableTitleElement.setBold( true );
    report->addElement( tableTitleElement, Qt::AlignLeft, titleElementColor );
    TableModel R_Cable;
    R_Cable.setDataHasVerticalHeaders(false);
    R_Cable.loadFromCSV(":/libKdReport/xml/ElectricCable/R_" + nameCable + ".csv");
    KDReports::AutoTableElement autoTableElement1( &R_Cable );
    autoTableElement1.setWidth( 100, KDReports::Percent );
    report->addElement( autoTableElement1 );
    report->addVerticalSpacing( 5 );

    KDReports::TextElement tableTitleElement2( "Insulation Resistance" );
    tableTitleElement2.setBold( true );
    report->addElement( tableTitleElement2, Qt::AlignLeft, titleElementColor );
    TableModel IR_Cable;
    IR_Cable.setDataHasVerticalHeaders(false);
    IR_Cable.loadFromCSV(":/libKdReport/xml/ElectricCable/IR_" + nameCable + ".csv");
    KDReports::AutoTableElement autoTableElement2( &IR_Cable );
    autoTableElement1.setWidth( 100, KDReports::Percent );
    report->addElement(autoTableElement2 );

//    qDebug() << "Export"  "report";
//    report->exportToFile("report" + nameCable, NULL);


//    KDReports::PreviewDialog preview(report );
//    preview.exec();

}
void bussinessManager::slt_exportCteReport()
{
    reportCTE = new KDReports::Report();
    createCableReport(reportCTE, "Cable1");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable2");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable3");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable4");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable5");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable6");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable9");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable10");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable11");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable12");

//    reportCTE = new KDReports::Report();
//    createCableReport(reportCTE, "Cable13");

}

void bussinessManager::slt_previewMteReport()
{
    if (mMTE->mCbAapderCirculator->checkState() != 0) {
        qDebug() << "Export circulator report";
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Circulator, "Preview");
    }
    if (mMTE->mCbAdapterComparator->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Comparator, "Preview" );
    }
    if (mMTE->mCbAdapterSMA->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Adapter_SMA, "Preview");
    }
    if (mMTE->mCbAttXband->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", AttXband, "Preview");
    }
    if (mMTE->mCbAntena->checkState() != 0) {
        qDebug() << "Export Antena report";
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Antena, "Preview");
    }
    if (mMTE->mCbFilterIf->checkState() != 0) {
        qDebug() << "Export FIlter if report";
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", FilterIF, "Preview");
    }
    if (mMTE->mCbFilterLOIF->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Filter_LOIF, "Preview");
    }
    if (mMTE->mCbFilterLORF->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Filter_LORF, "Preview");
    }
    if (mMTE->mCbFilterXband->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", FilterXband, "Preview");
    }
    if (mMTE->mCbHpa->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Hpa, "Preview");
    }
    if (mMTE->mCbSwAntena->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", SwAntena, "Preview");
    }
    if (mMTE->mCbLimiterSum->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", LimiterSum, "Preview");
    }
    if (mMTE->mCbLimiterDiff->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", LimiterDiff, "Preview");
    }
    if (mMTE->mCbLna->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", LNA, "Preview");
    }
    if (mMTE->mCbLo->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", LO, "Preview");
    }
    if (mMTE->mCbTx->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", TX, "Preview");
    }
    if (mMTE->mCbRx->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", RX, "Preview");
    }
}
void bussinessManager::slt_exportMteReport()
{
    if (mMTE->mCbAapderCirculator->checkState() != 0) {
        qDebug() << "Export circulator report";
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Circulator, "AutoSave");
    }
    if (mMTE->mCbAdapterComparator->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Comparator, "AutoSave" );
    }
    if (mMTE->mCbAdapterSMA->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Adapter_SMA, "AutoSave");
    }
    if (mMTE->mCbAttXband->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", AttXband, "AutoSave");
    }
    if (mMTE->mCbAntena->checkState() != 0) {
        qDebug() << "Export Antena report";
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Antena, "AutoSave");
    }
    if (mMTE->mCbFilterIf->checkState() != 0) {
        qDebug() << "Export FIlter if report";
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", FilterIF, "AutoSave");
    }
    if (mMTE->mCbFilterLOIF->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Filter_LOIF, "AutoSave");
    }
    if (mMTE->mCbFilterLORF->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Filter_LORF, "AutoSave");
    }
    if (mMTE->mCbFilterXband->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", FilterXband, "AutoSave");
    }
    if (mMTE->mCbHpa->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", Hpa, "AutoSave");
    }
    if (mMTE->mCbSwAntena->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", SwAntena, "AutoSave");
    }
    if (mMTE->mCbLimiterSum->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", LimiterSum, "AutoSave");
    }
    if (mMTE->mCbLimiterDiff->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", LimiterDiff, "AutoSave");
    }
    if (mMTE->mCbLna->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", LNA, "AutoSave");
    }
    if (mMTE->mCbLo->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", LO, "AutoSave");
    }
    if (mMTE->mCbTx->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", TX, "AutoSave");
    }
    if (mMTE->mCbRx->checkState() != 0) {
        reportCTE = new KDReports::Report();
        createReport(reportCTE, "MTE", RX, "AutoSave");
    }
}

void bussinessManager::slt_showCteInterface()
{
    mTestElectricalCable = new TestElectricCable();

    qDebug("Jump to test electric cable");
    QRect tScreenGeometry = QApplication::desktop()->screenGeometry();
    int x = (tScreenGeometry.width() - mTestElectricalCable->width()) / 2;
    int y = (tScreenGeometry.height() - mTestElectricalCable->height()) / 2;

    mTestElectricalCable->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mTestElectricalCable->move(x, y);
    mTestElectricalCable->show();

    setupELectric(mTestElectricalCable->getUi());
}

void bussinessManager::slt_showMteInterface()
{
    mTestModule = new testModule();

    qDebug("Jump to test electric cable");
    QRect tScreenGeometry = QApplication::desktop()->screenGeometry();
    int x = (tScreenGeometry.width() - mTestModule->width()) / 2;
    int y = (tScreenGeometry.height() - mTestModule->height()) / 2;

    mTestModule->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mTestModule->move(x, y);
    mTestModule->show();

    setupModule(mTestModule->getUi());
}

void bussinessManager::slt_showRfteInterface()
{
    mTestRfCable = new TestRfCable();

    qDebug("Jump to test electric cable");
    QRect tScreenGeometry = QApplication::desktop()->screenGeometry();
    int x = (tScreenGeometry.width() - mTestRfCable->width()) / 2;
    int y = (tScreenGeometry.height() - mTestRfCable->height()) / 2;

    mTestRfCable->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mTestRfCable->move(x, y);
    mTestRfCable->show();

    setupRf(mTestRfCable->getUi());
}
/**
  * @brief  This function is used to check validates data in all linedit user must fill before start
  * @note
  * @param  None
  * @retval None
***/
void bussinessManager::slt_enableTestProcess()
{
    bool state(true);

    state &= !mUi->mLeNameExecutor->text().isEmpty();
    state &= !mUi->mLeIDExecutor->text().isEmpty();
    state &= !mUi->mLeWorkExecutor->text().isEmpty();
    state &= !mUi->mLeNameSupervisor->text().isEmpty();
    state &= !mUi->mLeIDSupervisor->text().isEmpty();
    state &= !mUi->mLeWorkSupervisor->text().isEmpty();
    state &= !mUi->mLeLocalTest->text().isEmpty();

    if (state == OK) {
        mUi->mBtCableTest->setEnabled(1);
        mUi->mBtModuleTest->setEnabled(1);
        mUi->mBtRfTest->setEnabled(1);
        mUi->mBtMechanicalTest->setEnabled(1);

        mUi->mlElectricCable->setStyleSheet("color: rgb(49, 62, 70); font-family: Sans Serif; font-size: 14pt; font:bold;");
        mUi->mlModule->setStyleSheet("color: rgb(49, 62, 70); font-family: Sans Serif; font-size: 14pt; font:bold;");
        mUi->mlRfCable->setStyleSheet("color: rgb(49, 62, 70); font-family: Sans Serif; font-size: 14pt; font:bold;");
        mUi->mlMechanical->setStyleSheet("color: rgb(49, 62, 70); font-family: Sans Serif; font-size: 14pt; font:bold;");

        mUi->mBtCableTest->setStyleSheet("QPushButton{background-color: rgba(207,215,216, 255);outline: none;border-image: url(:/Test/images/electric_cable_test.png);}QPushButton::hover{background-color:rgba(176,188,189);}");
        mUi->mBtModuleTest->setStyleSheet("QPushButton{background-color: rgba(207,215,216, 255);outline: none;border-image: url(:/Test/images/module_test.png);}QPushButton::hover{background-color:rgba(176,188,189);}");
        mUi->mBtRfTest->setStyleSheet("QPushButton{background-color: rgba(207,215,216, 255);outline: none;border-image: url(:/Test/images/rf_cable_test.png);}QPushButton::hover{background-color:rgba(176,188,189);}");
        mUi->mBtMechanicalTest->setStyleSheet("QPushButton{background-color: rgba(207,215,216, 255);outline: none;border-image: url(:/Test/images/mechanical_test.png);}QPushButton::hover{background-color:rgba(176,188,189);}");
    }
    else {
        mUi->mBtCableTest->setEnabled(0);
        mUi->mBtModuleTest->setEnabled(0);
        mUi->mBtRfTest->setEnabled(0);
        mUi->mBtMechanicalTest->setEnabled(0);

        mUi->mlElectricCable->setStyleSheet("color: rgb(170, 186, 198); font-family: Sans Serif; font-size: 14pt; font:bold;");
        mUi->mlModule->setStyleSheet("color: rgb(170, 186, 198); font-family: Sans Serif; font-size: 14pt; font:bold;");
        mUi->mlRfCable->setStyleSheet("color: rgb(170, 186, 198); font-family: Sans Serif; font-size: 14pt; font:bold;");
        mUi->mlMechanical->setStyleSheet("color: rgb(170, 186, 198); font-family: Sans Serif; font-size: 14pt; font:bold;");

        mUi->mBtCableTest->setStyleSheet("QPushButton{background-color:rgba(207, 215, 216, 255);outline: none;border-image: url(:/Test/images/electric_cable_test_disable.png);}");
        mUi->mBtModuleTest->setStyleSheet("QPushButton{background-color:rgba(207, 215, 216, 255);outline: none;border-image: url(:/Test/images/module_test_disable.png);}");
        mUi->mBtRfTest->setStyleSheet("QPushButton{background-color:rgba(207, 215, 216, 255);outline: none;border-image: url(:/Test/images/rf_cable_test_disable.png);}");
        mUi->mBtMechanicalTest->setStyleSheet("QPushButton{background-color:rgba(207, 215, 216, 255);outline: none;border-image: url(:/Test/images/mechanical_test_disable.png);}");
    }
}
/*____________Slot CTE________________________________________________________ */
void bussinessManager::slt_runCTE(){
    cntRunCte++;

    if (cntRunCte == 1) {
        mCTE->btnStopCte->setEnabled(true);
        qDebug() << "[Bussiness] Run process test electrical cable";
        mCTE->btnRunCte->setText(" Pause");
        mCTE->btnRunCte->setIcon(QIcon(":/Test/images/button/pause_icon.png"));

    }
    else if (cntRunCte == 2) {
        mCTE->btnStopCte->setEnabled(true);
        qDebug() << "[Bussiness] Pause process test electrical cable";
        mCTE->btnRunCte->setText("Resume");
        mCTE->btnRunCte->setIcon(QIcon(":/Test/images/button/resum_icon.png"));
    }
    else {
        cntRunCte = 0;
        qDebug() << "[Bussiness] Resume process test electrical cable";
        mCTE->btnRunCte->setText("   Run");
        mCTE->btnRunCte->setIcon(QIcon(":/Test/images/button/start_icon_3.png"));
    }
    mCTE->btnRunCte->setIconSize(QSize(20, 20));
}
void bussinessManager::slt_logCTE()
{
    QString logColor;
    cntLogCte++;
    if ((cntLogCte % 2) != 0) {
        qDebug() << "[Bussiness] Start log test electrical cable";
        logColor = QString ("background-color: rgb(146, 165, 201); outline: none; border: none; ");
        mCTE->btnLogCte->setStyleSheet(logColor);
        LOGUTILS::initLogging(logFolderElectricalCable);
    }
    else {
        qDebug() << "[Bussiness] Stop log test electrical cable";
        logColor = QString ("background-color: rgb(200, 200, 200);  outline: none; border: none;");
        mCTE->btnLogCte->setStyleSheet(logColor);
        LOGUTILS::stopLogging();
    }
}
void bussinessManager::slt_stopCTE()
{
    mCTE->btnStopCte->setEnabled(false);
    cntRunCte = 2;
    slt_runCTE();
}
/*____________Slot MTE________________________________________________________ */
void bussinessManager::slt_runMTE()
{

    cntRunMte++;
    qDebug() << "cntRunMte: " + QString::number(cntRunMte);

    if (cntRunMte == 1) {
        mMTE->btnStopMte->setEnabled(true);
        qDebug() << "[Bussiness] Run process test module";
        mMTE->btnRunMte->setText(" Pause");
        mMTE->btnRunMte->setIcon(QIcon(":/Test/images/button/pause_icon.png"));
    }
    else if (cntRunMte == 2) {
        mMTE->btnStopMte->setEnabled(true);
        qDebug() << "[Bussiness] Pause process test module";
        mMTE->btnRunMte->setText("Resume");
        mMTE->btnRunMte->setIcon(QIcon(":/Test/images/button/resum_icon.png"));
    }
    else {
        cntRunMte = 0;
        qDebug() << "[Bussiness] Resume process test module";
        mMTE->btnRunMte->setText("Run");
        mMTE->btnRunMte->setIcon(QIcon(":/Test/images/button/start_icon_3.png"));
    }
}
void bussinessManager::slt_logMTE()
{
    QString logColor;

    cntLogMte++;
    if ((cntLogMte % 2) != 0) {
        qDebug() << "[Bussiness] Start log test module";
        logColor = QString ("background-color: rgb(146, 165, 201); outline: none; border: none; ");
        mMTE->btnLogMte->setStyleSheet(logColor);
        LOGUTILS::initLogging(logFolderModule);
    }
    else {
        qDebug() << "[Bussiness] Stop log test module";
        logColor = QString ("background-color: rgb(200, 200, 200);  outline: none; border: none;");
        mMTE->btnLogMte->setStyleSheet(logColor);
        LOGUTILS::stopLogging();
    }
}

void bussinessManager::slt_stopMTE()
{
    mMTE->btnStopMte->setEnabled(false);
    cntRunMte = 2;
    slt_runMTE();
}
/*____________Slot RFTE________________________________________________________ */
void bussinessManager::slt_runRFTE()
{
    cntRunRfte++;

    if (cntRunRfte == 1) {
        mRFTE->btnStopRfte->setEnabled(true);
        qDebug() << "[Bussiness] Run process test RF cable";
        mRFTE->btnRunRfte->setText("Stop");
        mRFTE->btnRunRfte->setIcon(QIcon(":/Test/images/button/pause_icon.png"));
    }
    else if (cntRunRfte == 2) {
        mRFTE->btnStopRfte->setEnabled(true);
        qDebug() << "[Bussiness] Pause process  test RF cable";
        mRFTE->btnRunRfte->setText("Stop");
        mRFTE->btnRunRfte->setIcon(QIcon(":/Test/images/button/resum_icon.png"));
    }
    else {
        cntRunRfte = 0;
        qDebug() << "[Bussiness] Resume process test RF cable";
        mRFTE->btnRunRfte->setText("Run");
        mRFTE->btnRunRfte->setIcon(QIcon(":/Test/images/button/start_icon_3.png"));
    }
}
void bussinessManager::slt_logRFTE()
{
    QString logColor;

    cntLogRfte++;
    if ((cntLogRfte % 2) != 0) {
        qDebug() << "[Bussiness] Start log test RF cable";
        logColor = QString ("background-color: rgb(146, 165, 201); outline: none; border: none; ");
        mRFTE->btnLogRfte->setStyleSheet(logColor);
        LOGUTILS::initLogging(logFolderRfCable);
    }
    else {
        qDebug() << "[Bussiness] Stop log test RF cable";
        logColor = QString ("background-color: rgb(200, 200, 200);  outline: none; border: none;");
        mRFTE->btnLogRfte->setStyleSheet(logColor);
        LOGUTILS::stopLogging();
    }
}

void bussinessManager::slt_stopRFTE()
{
    mRFTE->btnStopRfte->setEnabled(false);
    cntRunRfte = 2;
    slt_runRFTE();
}
/*________________________________________________________________________________________*/

void bussinessManager::slt_resultTest(bool state)
{
//    if (state == true) {
//        reportElectrical.associateTextValue("resultCable", QString::fromUtf8("PASS"));
//    }
//    else {
//        reportElectrical.associateTextValue("resultCable", QString::fromUtf8("FAIL"));
//    }
}


/*_____________Connect Equipment_________________________________________________________*/
void bussinessManager::slt_connDcPower()
{
    QString connectColor;
    /*
    Write code connect here, return stateconnect to stateCnDcPwr
    */
    stateCnDCPwr++;
   if (stateCnDCPwr == CONNECTED) {
        qDebug() << "[Bussiness] Connected to DC power";
        mMTE->btnDcPwr->setIcon(QIcon(":/Test/images/button/connect.png"));
        connectColor = QString ("background-color: rgba(146,165,201); outline: none; border: none; color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold;");
    }
    else if (stateCnDCPwr ==  DISCONNECTED) {
        stateCnDCPwr = 0;
        qDebug() << "[Bussiness] Disconnected to DC power";
        mMTE->btnDcPwr->setIcon(QIcon(":/Test/images/button/disconnected.svg"));  
        connectColor = QString ("background-color: rgb(177,188,190); outline: none; border: none; color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold;");
    }
    mMTE->btnDcPwr->setStyleSheet(connectColor);
}

void bussinessManager::slt_connDcLoad()
{
    QString connectColor;
    /*
    Write code connect here, return stateconnect to stateCnDCLoad
    */
    stateCnDCLoad++;
   if (stateCnDCLoad == CONNECTED) {
        qDebug() << "[Bussiness] Connected to DC Loader";
        mMTE->btnDcLoad->setIcon(QIcon(":/Test/images/button/connect.png"));
        connectColor = QString ("background-color: rgba(146,165,201); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    else if (stateCnDCLoad ==  DISCONNECTED) {
        stateCnDCLoad = 0;
        qDebug() << "[Bussiness] Disconnected to DC Loader";
        mMTE->btnDcLoad->setIcon(QIcon(":/Test/images/button/disconnected.svg"));
        connectColor = QString ("background-color: rgb(177,188,190); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    mMTE->btnDcLoad->setStyleSheet(connectColor);
}

void bussinessManager::slt_connOsiloscope()
{
    QString connectColor;
    /*
    Write code connect here, return stateconnect to stateCnOsl
    */
    stateCnOsl++;
   if (stateCnOsl == CONNECTED) {
        qDebug() << "[Bussiness] Connected to Osciloscope";
        mMTE->btnOscil->setIcon(QIcon(":/Test/images/button/connect.png"));
        connectColor = QString ("background-color: rgba(146,165,201); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    else if (stateCnOsl ==  DISCONNECTED) {
        stateCnOsl = 0;
        qDebug() << "[Bussiness] Disconnected to Osciloscope";
        mMTE->btnOscil->setIcon(QIcon(":/Test/images/button/disconnected.svg"));
        connectColor = QString ("background-color: rgb(177,188,190); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    mMTE->btnOscil->setStyleSheet(connectColor);
}

void bussinessManager::slt_connNoiseSource()
{
    QString connectColor;
    /*
    Write code connect here, return stateconnect to stateCnNoiseSrc
    */
    stateCnNoiseSrc++;
   if (stateCnNoiseSrc == CONNECTED) {
        qDebug() << "[Bussiness] Connected to Noise Source";
        mMTE->btnNoiseSrc->setIcon(QIcon(":/Test/images/button/connect.png"));
        connectColor = QString ("background-color: rgba(146,165,201); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    else if (stateCnNoiseSrc ==  DISCONNECTED) {
        stateCnNoiseSrc = 0;
        qDebug() << "[Bussiness] Disconnected to Noise Source";
        mMTE->btnNoiseSrc->setIcon(QIcon(":/Test/images/button/disconnected.svg"));
        connectColor = QString ("background-color: rgb(177,188,190); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    mMTE->btnNoiseSrc->setStyleSheet(connectColor);
}

void bussinessManager::slt_connWaveGeneration()
{
    QString connectColor;
    /*
    Write code connect here, return stateconnect to stateCnWaveGen
    */
    stateCnWaveGen++;
   if (stateCnWaveGen == CONNECTED) {
        qDebug() << "[Bussiness] Connected to Wave generator";
        mMTE->btnWaveGen->setIcon(QIcon(":/Test/images/button/connect.png"));
        connectColor = QString ("background-color: rgba(146,165,201); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    else if (stateCnWaveGen ==  DISCONNECTED) {
        stateCnWaveGen = 0;
        qDebug() << "[Bussiness] Disconnected to Wave generator ";
        mMTE->btnWaveGen->setIcon(QIcon(":/Test/images/button/disconnected.svg"));
        connectColor = QString ("background-color: rgb(177,188,190); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    mMTE->btnWaveGen->setStyleSheet(connectColor);
}

void bussinessManager::slt_connSignalGeneration()
{
    QString connectColor;
    /*
    Write code connect here, return stateconnect to stateCnSignGen
    */
    stateCnSignGen++;
   if (stateCnSignGen == CONNECTED) {
        qDebug() << "[Bussiness] Connected to Signal Generation";
        mMTE->btnSignGen->setIcon(QIcon(":/Test/images/button/connect.png"));
        connectColor = QString ("background-color: rgba(146,165,201); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    else if (stateCnSignGen ==  DISCONNECTED) {
        stateCnSignGen = 0;
        qDebug() << "[Bussiness] Disconnected to Signal Generation";
        mMTE->btnSignGen->setIcon(QIcon(":/Test/images/button/disconnected.svg"));
        connectColor = QString ("background-color: rgb(177,188,190); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    mMTE->btnSignGen->setStyleSheet(connectColor);
}
void bussinessManager::slt_connNetworkAnalizer()
{
    QString connectColor;
    /*
    Write code connect here, return stateconnect to stateCnNetAnalizer
    */
    stateCnNetAnalizer++;
   if (stateCnNetAnalizer == CONNECTED) {
        qDebug() << "[Bussiness] Connected to Network Analizer";
        mMTE->btnNetAnalizer->setIcon(QIcon(":/Test/images/button/connect.png"));
        connectColor = QString ("background-color: rgba(146,165,201); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    else if (stateCnNetAnalizer ==  DISCONNECTED) {
        stateCnNetAnalizer = 0;
        qDebug() << "[Bussiness] Disconnected to Network Analizer";
        mMTE->btnNetAnalizer->setIcon(QIcon(":/Test/images/button/disconnected.svg"));
        connectColor = QString ("background-color: rgb(177,188,190); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    mMTE->btnNetAnalizer->setStyleSheet(connectColor);
}

void bussinessManager::slt_connSpectumeAnalizer()
{
    QString connectColor;
    /*
    Write code connect here, return stateconnect to stateCnSpecAnalizer
    */
    stateCnSpecAnalizer++;
   if (stateCnSpecAnalizer == CONNECTED) {
        qDebug() << "[Bussiness] Connected to Spectum Analizer";
        mMTE->btnSpecAnalizer->setIcon(QIcon(":/Test/images/button/connect.png"));
        connectColor = QString ("background-color: rgba(146,165,201); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    else if (stateCnSpecAnalizer ==  DISCONNECTED) {
        stateCnSpecAnalizer = 0;
        qDebug() << "[Bussiness] Disconnected to Spectum ANalizer";
        mMTE->btnSpecAnalizer->setIcon(QIcon(":/Test/images/button/disconnected.svg"));
        connectColor = QString ("background-color: rgb(177,188,190); outline: none; border: none;color: rgb(49,67,100);font-family:Myriad Pro; font-size: 8pt; font:bold; ");
    }
    mMTE->btnSpecAnalizer->setStyleSheet(connectColor);
}

 /*___________Function add more____________*/
/*
"","9.3hZ","9.4hZ"," ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"
"Cổng 1",,,,,,,"VSWR ≤ 1.4",
"Cổng 2",,,,,,,"VSWR ≤ 1.4",
"Cổng 3",,,,,,,"VSWR ≤ 1.4",
*/
void bussinessManager::writeToCsvFile(defineCsv data)
{
      QStringList strList;
      QtCSV::StringData strData;
      int _numRow = 0;


      for(int j= 0; j < data.numColumn; j++) {
        strList << data.header[j];
      }
      strData.addRow(strList);
      strList.clear();
      _numRow++;

      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row1[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;

      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row2[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row3[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row4[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row5[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row6[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row7[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row8[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row9[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row10[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row11[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row12[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row13[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row14[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row15[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
      _numRow++;
      if (data.numRow > _numRow) {
          for(int j= 0; j < data.numColumn; j++) {
            strList << data.row16[j];
          }
          strData.addRow(strList);
          strList.clear();
      }
    QString _filepath = QDir::currentPath() + "/" + data.pathCsv;
    QtCSV::Writer::write(_filepath, strData);
}

void bussinessManager::slt_guidlefile()
{
//    qDebug() << "Come here";
//    csvCirculator_part1.row1[2] = "10";
//    csvCirculator_part1.row1[3] = "20";
//    writeToCsvFile(csvCirculator_part1);
//    writeToCsvFile(csvCirculator_part2);
//    writeToCsvFile(csvCirculator_part3);

//      csvSMA_part1.row1[2] = "30";
//      csvSMA_part1.row1[3] = "50";
//      writeToCsvFile(csvSMA_part1);
//      writeToCsvFile(csvSMA_part2);
//    csvAntena.row1[2] = "10";
//    writeToCsvFile(csvAntena);

//      csvAttXband_part1.row1[2] = "30";
//      csvAttXband_part1.row1[3] = "50";
//      writeToCsvFile(csvAttXband_part1);
//      writeToCsvFile(csvAttXband_part2);

//        csvFilterXband.row1[3] = "50";
//        writeToCsvFile(csvFilterXband);

//        csvLimiterSum.row1[3] = "10";
//        csvLimiterSum.row1[4] = "20";
//        writeToCsvFile(csvLimiterSum);

//     csvSwAntena_part2.row1[2] = "10";
//     csvSwAntena_part2.row1[3] = "20";
//     writeToCsvFile(csvSwAntena_part1);
//     writeToCsvFile(csvSwAntena_part2);
//     writeToCsvFile(csvSwAntena_part3);

//       writeToCsvFile(csvComparator_part1);
//       writeToCsvFile(csvComparator_part2);
//       writeToCsvFile(csvComparator_part3);
//       writeToCsvFile(csvComparator_part4);
//       writeToCsvFile(csvComparator_part5);
//       writeToCsvFile(csvComparator_part6);
//       writeToCsvFile(csvComparator_part7);

//    writeToCsvFile(csvFilter_LOIF_part1);
//    writeToCsvFile(csvFilter_LOIF_part2);

    writeToCsvFile(csvHPA_part1);
    writeToCsvFile(csvHPA_part2);
    writeToCsvFile(csvHPA_part3);
    writeToCsvFile(csvHPA_part4);
    writeToCsvFile(csvHPA_part5);
    writeToCsvFile(csvHPA_part6);
}
