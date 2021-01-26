#include "bussiness/bussinessmanager.h"
#include "ui_mainwindow.h"
#include "ui_testelectriccable.h"
#include "ui_testmodule.h"
#include "ui_testrfcable.h"
#include "ui_testmechanical.h"

bussinessManager::bussinessManager(QObject *parent) : QObject(parent)
{
    qDebug() << "[Business] Constructor";
    mUi = NULL;
   // mCTE = NULL;
}

bussinessManager::~bussinessManager()
{
    qDebug() << "[Business] Destructor";
}

Ui::MainWindow *bussinessManager::ui() const
{
    return mUi;
}

void bussinessManager::setup(Ui::MainWindow *ui)
{
    if (ui != NULL) {

        this->mUi = ui;
    }
    qDebug() << "Running";
    //connect(mCTE->getUi()->btnExportCte, SIGNAL(clicked()), this, SLOT(slt_exportCteReport()));
    connect(mCTE->getUi()->btnRunCte, SIGNAL(clicked()), this, SLOT(slt_exportCteReport()));
    connect(mUi->btn_test, SIGNAL(clicked()), this, SLOT(slt_test()));
}

void bussinessManager::slt_exportCteReport()
{
    qDebug() << "Come here";
//    qDebug() << this->mUi->mLeNameExecutor->text();
}

void bussinessManager::slt_test()
{
    qDebug() << "here we click in mechanical button;";
//    QString text = mCTE->getUi()->btnExportCte->text();
//    qDebug() << text;
    mUi->label_15->setText("phandinhbac");
    mCTE->getUi()->label_116->setText("hello");
}
