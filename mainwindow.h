#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "testelectriccable.h"
#include "testmodule.h"
#include "testrfcable.h"
#include "userconfig.h"

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

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::MainWindow *mUi;
    QCloseEvent *event;
    QString _currentText;

    void initCombobox(QString path, QString nameCombobox);
    void saveInformCombobox(QString DataSave, QString nameCobobox, QString path);
};

#endif // MAINWINDOW_H
