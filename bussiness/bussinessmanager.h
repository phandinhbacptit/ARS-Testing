#ifndef BUSSINESSMANAGER_H
#define BUSSINESSMANAGER_H


#include <QObject>
#include <QDebug>
#include <QPixmap>
#include <QMovie>
#include <QProcess>
#include <QDebug>
#include <QString>
#include <QMetaMethod>
#include <TableModel.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QAbstractTableModel>
#include <QPrintDialog>
#include <QMessageBox>
#include <QFile>

#include "mainwindow.h"
#include "testelectriccable.h"
#include "testmodule.h"
#include "userconfig.h"
#include "testrfcable.h"

#include "KDReports/KDReports.h"
#include "KDReports/KDReportsReport.h"
#include "KDReports/KDReportsTableElement.h"
#include "KDReports/KDReportsChartElement.h"
#include "KDReports/KDReportsTextElement.h"
#include "KDReports/KDReportsHtmlElement.h"
#include "KDReports/KDReportsPreviewDialog.h"


class bussinessManager : public QObject
{
    Q_OBJECT
public:
    explicit bussinessManager(QObject *parent = 0);
    ~bussinessManager();
    void setup(Ui::MainWindow *ui);
    void setupELectric(Ui::TestElectricCable *ui);

    Ui::MainWindow  *ui() const;
    Ui::TestElectricCable *getGui() const;
    Ui::testModule *getGuiMte() const;
//    Ui::TestRfCable *getGui() const;

    void setupModule(Ui::testModule *ui);
    void setupRf(Ui::TestRfCable *ui);
public slots:

    void slt_enableTestProcess();

    void slt_exportCteReport();

    void slt_showCteInterface();
    void slt_runCTE();
    void slt_logCTE();

    void slt_runMTE();
    void slt_logMTE();

    void slt_runRFTE();
    void slt_logRFTE();

    void slt_showMteInterface();
    void slt_showRfteInterface();

    void slt_resultTest(bool state);

signals:

private:
    Ui::MainWindow *mUi;
    Ui::TestElectricCable *mCTE;
    Ui::testModule *mMTE;
    Ui::TestRfCable *mRFTE;

    TestElectricCable *mTestElectricalCable;
    testModule *mTestModule;
    TestRfCable *mTestRfCable;

    KDReports::Report reportElectrical;

    int cntRunCte = 0;
    int cntLogCte = 0;

    int cntRunMte = 0;
    int cntLogMte = 0;

    int cntRunRfte = 0;
    int cntLogRfte = 0;
};

#endif // BUSSINESSMANAGER_H
