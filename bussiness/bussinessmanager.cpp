#include "bussiness/bussinessmanager.h"
#include "ui_mainwindow.h"
#include "ui_testelectriccable.h"
#include "ui_testmodule.h"
#include "ui_testrfcable.h"
#include "ui_testmechanical.h"


bussinessManager::bussinessManager(QObject *parent) : QObject(parent)
{
    qDebug() << "[Bussiness] Constructor";
    mUi = NULL;
    //mCTE = NULL;


    reportElectrical.setDocumentName("Electrical Report");

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
    qDebug() << "[Bussiness] Setup gui MTE";
}

void bussinessManager::setupRf(Ui::TestRfCable *ui)
{
    if(ui != NULL) {
        this->mRFTE = ui;
    }
    connect(mRFTE->btnRunRfte, SIGNAL(clicked()), this, SLOT(slt_runRFTE()));
    connect(mRFTE->btnLogRfte, SIGNAL(clicked()), this, SLOT(slt_logRFTE()));
    qDebug() << "[Bussiness] Setup gui RFTE";
}

void bussinessManager::slt_exportCteReport()
{
    reportElectrical.associateTextValue("title_element", "TEST REPORT");

    reportElectrical.associateTextValue("table1_title", "Resistance");
    reportElectrical.associateTextValue("table2_title", "Insulation Resistance");
    reportElectrical.associateImageValue("image_system", QPixmap(":/Test/images/logo_vtx.png"));

    reportElectrical.associateTextValue("name_excutor", mUi->mLeNameExecutor->text());
    reportElectrical.associateTextValue("id_excutor", mUi->mLeIDExecutor->text());
    reportElectrical.associateTextValue("work_excutor", mUi->mLeWorkExecutor->text());

    reportElectrical.associateTextValue("name_supervisor", mUi->mLeNameSupervisor->text());
    reportElectrical.associateTextValue("id_supervisor", mUi->mLeIDSupervisor->text());
    reportElectrical.associateTextValue("work_supervisor", mUi->mLeWorkSupervisor->text());

    reportElectrical.associateTextValue("nameCable", QString::fromUtf8("Cable1"));


    TableModel table1;
    table1.setDataHasVerticalHeaders(false);
    table1.loadFromCSV(":/File/libKdReport/xml/table1.csv");
    reportElectrical.associateModel(QLatin1String("table1"), &table1);
    TableModel table2;
    table2.setDataHasVerticalHeaders(false);
    table2.loadFromCSV(":/File/libKdReport/xml/table2.csv");
    reportElectrical.associateModel(QLatin1String("table2"), &table2);

    QFile reportFile(":/File/libKdReport/xml/PriceList.xml");
    if (!reportFile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(0, QObject::tr("Warning"), QObject::tr("Could not open report description file 'PriceList.xml'. Please start this program from the PriceListXML directory." ) );
    }

    KDReports::ErrorDetails details;
    if(!reportElectrical.loadFromXML(&reportFile, &details)) {
        QMessageBox::warning(0, QObject::tr("Warning"), QObject::tr("Could not parse report description file:\n%1" ).arg(details.message()) );
        reportFile.close();
    }

    KDReports::PreviewDialog preview(&reportElectrical);
    preview.setDefaultSaveDirectory(QDir::homePath());
    preview.exec();
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
    if ((cntRunCte % 2) != 0) {
        qDebug() << "[Bussiness] Run process test electrical cable";
        mCTE->btnRunCte->setText("Stop");
        mCTE->btnRunCte->setIcon(QIcon(":/Test/images/button/Stop_icon.png"));
    }
    else {
        qDebug() << "[Bussiness] Stop test electrical cable";
        mCTE->btnRunCte->setText("Run");
        mCTE->btnRunCte->setIcon(QIcon(":/Test/images/button/start_icon_3.png"));
    }
}
void bussinessManager::slt_logCTE()
{
    QString logColor;

    cntLogCte++;
    if ((cntLogCte % 2) != 0) {
        qDebug() << "[Bussiness] Start log test electrical cable";
        logColor = QString ("background-color: rgb(146, 165, 201); outline: none; border: none; ");
        mCTE->btnLogCte->setStyleSheet(logColor);
    }
    else {
        qDebug() << "[Bussiness] Stop log test electrical cable";
        logColor = QString ("background-color: rgb(200, 200, 200);  outline: none; border: none;");
        mCTE->btnLogCte->setStyleSheet(logColor);
    }
}
/*____________Slot MTE________________________________________________________ */
void bussinessManager::slt_runMTE()
{
    cntRunMte++;
    if ((cntRunMte % 2) != 0) {
        qDebug() << "[Bussiness] Run process test module";
        mMTE->btnRunMte->setText("Stop");
        mMTE->btnRunMte->setIcon(QIcon(":/Test/images/button/Stop_icon.png"));
    }
    else {
        qDebug() << "[Bussiness] Stop test module";
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
    }
    else {
        qDebug() << "[Bussiness] Stop log test module";
        logColor = QString ("background-color: rgb(200, 200, 200);  outline: none; border: none;");
        mMTE->btnLogMte->setStyleSheet(logColor);
    }
}
/*____________Slot RFTE________________________________________________________ */
void bussinessManager::slt_runRFTE()
{
    cntRunRfte++;
    if ((cntRunRfte % 2) != 0) {
        qDebug() << "[Bussiness] Run process test RF cable";
        mRFTE->btnRunRfte->setText("Stop");
        mRFTE->btnRunRfte->setIcon(QIcon(":/Test/images/button/Stop_icon.png"));
    }
    else {
        qDebug() << "[Bussiness] Stop test RF cable";
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
    }
    else {
        qDebug() << "[Bussiness] Stop log test RF cable";
        logColor = QString ("background-color: rgb(200, 200, 200);  outline: none; border: none;");
        mRFTE->btnLogRfte->setStyleSheet(logColor);
    }
}

void bussinessManager::slt_resultTest(bool state)
{
    if (state == true) {
        reportElectrical.associateTextValue("resultCable", QString::fromUtf8("PASS"));
    }
    else {
        reportElectrical.associateTextValue("resultCable", QString::fromUtf8("FAIL"));
    }
}


