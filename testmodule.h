#ifndef TESTMODULE_H
#define TESTMODULE_H

#include <QWidget>
#include <userconfig.h>
#include <QMainWindow>
#include <QString>

#include <QDesktopWidget>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class QAction;
class QPdfWidget;

namespace Ui {
class testModule;
}

class testModule : public QWidget
{
    Q_OBJECT
protected:


public:
    explicit testModule(QWidget *parent = 0);
    ~testModule();
    Ui::testModule *getUi() const;
    void setUi(Ui::testModule *value);

private:
    Ui::testModule *ui;
    QPdfWidget *m_pPdfWidget;


signals:
    void signal_setpage(int numPage);

public:
//    kmWidgetChart* mTimeLine;

private slots:
    void onOpenFile(QString path);
    void on_mCbAll_clicked(bool checked);
    void on_mCbControl_all_clicked(bool checked);
    void on_mCbGyro_all_clicked(bool checked);
    void on_mCbMotor_all_clicked(bool checked);
    void on_mCbEnc_all_clicked(bool checked);
    void on_pushButton_12_clicked();
    void on_detailCtrXlth_clicked();
    void on_detailCtrBite_clicked();
    void on_detailCtrKdcs_clicked();
    void on_detailCtrGyro_clicked();
    void on_detailCtrEncAzi_clicked();
    void on_detailCtrEncElv_clicked();
    void on_detailCtrMotorAzi_2_clicked();
    void on_detailCtrMotorElv_clicked();
    void on_detailGyroAzi_clicked();
    void on_detailGyroElv_clicked();
    void on_detailEncAzi_clicked();
    void on_detailEncElv_clicked();
    void on_detailMotorAzi_clicked();
    void on_detailMotorElv_clicked();

    void slt_setpage(int numPage);
    void on_mCbControl_all_clicked();
    void on_mCbAapderCirculator_clicked(bool checked);
    void on_mCbAdapterComparator_clicked(bool checked);
    void on_mCbAdapterSMA_clicked(bool checked);
    void on_mCbAttXband_clicked(bool checked);
    void on_mCbHpa_clicked(bool checked);
    void on_mCbLimiter_clicked(bool checked);
    void on_mCbLna_clicked(bool checked);
    void on_mCbLo_clicked(bool checked);
    void on_mCbRx_clicked(bool checked);
    void on_mCbTx_clicked(bool checked);
    void on_All_clicked(bool checked);
};

#endif // TESTMODULE_H
