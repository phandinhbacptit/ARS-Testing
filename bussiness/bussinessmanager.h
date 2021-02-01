#ifndef BUSSINESSMANAGER_H
#define BUSSINESSMANAGER_H


#include <QObject>
#include <QDebug>
#include <QMetaMethod>
#include <QPixmap>
#include <QDesktopWidget>
#include <QProcess>
#include <QMovie>

#include "mainwindow.h"
#include "testelectriccable.h"
#include "testmodule.h"
#include "userconfig.h"
#include "testrfcable.h"

#include "KDReports/KDReports.h"


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
