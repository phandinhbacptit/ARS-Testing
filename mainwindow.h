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

    Ui::MainWindow *ui() const;
    void setUi(Ui::MainWindow *ui);

private slots:
//    void on_mBtCableTest_clicked();

    void on_btnMainExit_clicked();

private:
    Ui::MainWindow *mUi;
};

#endif // MAINWINDOW_H
