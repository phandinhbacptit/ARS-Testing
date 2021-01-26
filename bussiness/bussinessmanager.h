#ifndef BUSSINESSMANAGER_H
#define BUSSINESSMANAGER_H

#include "mainwindow.h"
#include <QObject>
#include <QDebug>
#include <QMetaMethod>
#include <QPixmap>
#include <QDesktopWidget>
#include <QProcess>
#include <QMovie>
#include "testelectriccable.h"


class bussinessManager : public QObject
{
    Q_OBJECT
public:
    explicit bussinessManager(QObject *parent = 0);
    ~bussinessManager();
    void setup(Ui::MainWindow *ui);
    Ui::MainWindow  *ui() const;

public slots:
    void slt_exportCteReport();
    void slt_test();
signals:

private:
    Ui::MainWindow *mUi;
    //Ui::TestElectricCable *mCTE;
    TestElectricCable *mCTE = new TestElectricCable();
};

#endif // BUSSINESSMANAGER_H
