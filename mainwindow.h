#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "testelectriccable.h"
#include "testmodule.h"
#include "testrfcable.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_mBtCableTest_clicked();

    void on_btnMainExit_clicked();

    void on_mBtModuleTest_clicked();

    void on_mBtRfTest_clicked();

private:
    Ui::MainWindow *ui;
    TestElectricCable *mTestElectricCable;
    testModule *mTestModule;
    TestRfCable *mTestRfCable;
};

#endif // MAINWINDOW_H
