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
#include <QDir>
#include <QTime>

#include "mainwindow.h"
#include "testelectriccable.h"
#include "testmodule.h"
#include "userconfig.h"
#include "testrfcable.h"

#include "qtCsv/include/qtcsv_global.h"
#include "qtCsv/include/stringdata.h"
#include "qtCsv/include/reader.h"
#include "qtCsv/include/writer.h"

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
    void createReport(KDReports::Report *report, QString typeTest, table part, QString mode);
    void createTable(KDReports::Report *report, QString Title, QString pathCsv);

    Ui::MainWindow  *ui() const;
    Ui::TestElectricCable *getGui() const;
    Ui::testModule *getGuiMte() const;
//    Ui::TestRfCable *getGui() const;

    void setupModule(Ui::testModule *ui);
    void setupRf(Ui::TestRfCable *ui);
    /*_______Add more___________*/
    void writeToCsvFile(defineCsv data);

public slots:

    void slt_enableTestProcess();

    void slt_exportCteReport();

    void slt_previewMteReport();
    void slt_exportMteReport();

    void slt_showCteInterface();
    /*____Cable test equipment___*/
    void slt_runCTE();
    void slt_logCTE();
    void slt_stopCTE();

    /*____Module test equipment___*/
    void slt_runMTE();
    void slt_logMTE();
    void slt_stopMTE();

    /*____RF test equipment___*/
    void slt_runRFTE();
    void slt_logRFTE();
    void slt_stopRFTE();

    /*___Connect Equipment____*/
    void slt_connDcPower();
    void slt_connDcLoad();
    void slt_connOsiloscope();
    void slt_connNoiseSource();
    void slt_connSpectumeAnalizer();
    void slt_connNetworkAnalizer();
    void slt_connWaveGeneration();
    void slt_connSignalGeneration();

    void slt_showMteInterface();
    void slt_showRfteInterface();

    void slt_resultTest(bool state);
    void slt_guidlefile();

signals:

private:
//    Ui::MainWindow *mUi;
    Ui::TestElectricCable *mCTE;
    Ui::testModule *mMTE;
    Ui::TestRfCable *mRFTE;
    Ui::MainWindow *mUi;

    TestElectricCable *mTestElectricalCable;
    testModule *mTestModule;
    TestRfCable *mTestRfCable;

    KDReports::Report *reportCTE;

    void createCableReport(KDReports::Report *report, QString nameCable);

    int cntRunCte = 0;
    int cntLogCte = 0;

    int cntRunMte = 0;
    int cntLogMte = 0;

    int cntRunRfte = 0;
    int cntLogRfte = 0;
    int stateCnDCPwr = 0, stateCnDCLoad = 0, stateCnOsl = 0, stateCnNoiseSrc = 0, stateCnSpecAnalizer = 0, stateCnNetAnalizer = 0, stateCnWaveGen = 0, stateCnSignGen= 0;
};

#endif // BUSSINESSMANAGER_H
