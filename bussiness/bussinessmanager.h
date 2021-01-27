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

public slots:
    void slt_exportCteReport();

    void slt_showCteInterface();
signals:

private:
    Ui::MainWindow *mUi;
    Ui::TestElectricCable *mCTE;

    TestElectricCable *mTestElectricalCable;

    KDReports::Report reportElectrical;
};

#endif // BUSSINESSMANAGER_H
