#include "bussiness/bussinessmanager.h"
#include "ui_mainwindow.h"
#include "ui_testelectriccable.h"
#include "ui_testmodule.h"
#include "ui_testrfcable.h"
#include "ui_testmechanical.h"

#include <QDesktopWidget>
#include <QDebug>

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

}

Ui::MainWindow *bussinessManager::ui() const
{
    return mUi;
}

Ui::TestElectricCable *bussinessManager::getGui() const
{
    return mCTE;
}

void bussinessManager::setup(Ui::MainWindow *ui)
{
    if (ui != NULL) {

        this->mUi = ui;
    }

    connect(mUi->mBtCableTest, SIGNAL(clicked()), this, SLOT(slt_showCteInterface()));
    qDebug() << "[Bussiness] Setup MainWindow";
}

void bussinessManager::setupELectric(Ui::TestElectricCable *ui)
{
    if(ui != NULL) {
        this->mCTE = ui;
    }
    connect(mCTE->btnExportCte, SIGNAL(clicked()), this, SLOT(slt_exportCteReport()));
    qDebug() << "[Bussiness] Setup gui CTE";
}

void bussinessManager::slt_exportCteReport()
{
        KDReports::Header& header = reportElectrical.header(KDReports::FirstPage);
        QPixmap kdab(":Test/images/logo_vtx.png");
        QPainter painter(&kdab);
        //painter.drawRect( 0, 0, kdab.width() - 1, kdab.height() - 1 );
        KDReports::ImageElement imageElement(kdab);
        imageElement.setWidth(30); // mm
        header.addElement(imageElement);
        header.addElement(KDReports::TextElement("Excutor: "));
        QString nameExcutor = mUi->mLeNameExecutor->text();
        qDebug() << nameExcutor;
    //    header.addElement(KDReports::TextElement"Reporter: ");
        header.addElement(KDReports::TextElement(nameExcutor));

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
