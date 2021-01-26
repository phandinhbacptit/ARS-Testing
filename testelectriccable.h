#ifndef TESTELECTRICCABLE_H
#define TESTELECTRICCABLE_H

#include <QWidget>
#include <QMainWindow>
#include <QString>

#include <QDesktopWidget>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "userconfig.h"
#include "KDReports/KDReports.h"

class QAction;
class QPdfWidget;

namespace Ui {
class TestElectricCable;
}

class TestElectricCable : public QWidget
{
    Q_OBJECT

public:
    explicit TestElectricCable(QWidget *parent = 0);
    ~TestElectricCable();
    int x, y;
    Ui::TestElectricCable *getUi() const;
    void setUi(Ui::TestElectricCable *value);

public slots:
    void loadFile(const QString &path);



private slots:
    void on_btn_exit_clicked();
    void onOpenFile(QString path);

    void on_detail_cable1_clicked();

    void on_detail_cable2_clicked();

    void on_detail_cable3_clicked();

    void on_detail_cable4_clicked();

    void on_detail_cable5_clicked();

    void on_detail_cable6_clicked();

    void on_detail_cable9_clicked();

    void on_detail_cable10_clicked();

    void on_detail_cable11_clicked();

    void on_detail_cable12_clicked();

    void on_detail_cable13_clicked();

//    void on_btnExportCte_clicked();

private:
    Ui::TestElectricCable *ui;

    QPixmap icon_uncheck, icon_checked;

    void createActions();
    void createToolBar();
    QAction *m_pOpenFileAction;
    QPdfWidget *m_pPdfWidget;

    KDReports::Report reportElectrical;


};

#endif // TESTELECTRICCABLE_H
