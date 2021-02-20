#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mUi(new Ui::MainWindow)
{
    mUi->setupUi(this);

    QRect tScreenGeometry = QApplication::desktop()->screenGeometry();
    int x = (tScreenGeometry.width() - this->width()) / 2;
    int y = (tScreenGeometry.height() - this->height()) / 2;

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->move(x, y);


//    mTestElectricCable = new TestElectricCable();
//    mTestModule = new testModule();
//    mTestRfCable = new TestRfCable();
}

MainWindow::~MainWindow()
{
    delete mUi;

//    if (mTestElectricCable != NULL) {
//        delete mTestElectricCable;
//        mTestElectricCable = NULL;
//    }
//    if (mTestModule != NULL) {
//        delete mTestModule;
//        mTestModule = NULL;
//    }
//    if (mTestRfCable != NULL) {
//        delete mTestRfCable;
//        mTestRfCable = NULL;
//    }
}

Ui::MainWindow *MainWindow::ui() const
{
    return mUi;
}

void MainWindow::setUi(Ui::MainWindow *ui)
{
   mUi = ui;
}
//void MainWindow::on_mBtCableTest_clicked()
//{
//    qDebug("Jump to test electric cable");
//    QRect tScreenGeometry = QApplication::desktop()->screenGeometry();
//    int x = (tScreenGeometry.width() - mTestElectricCable->width()) / 2;
//    int y = (tScreenGeometry.height() - mTestElectricCable->height()) / 2;

//    mTestElectricCable->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//    mTestElectricCable->move(x, y);
//    mTestElectricCable->show();

//}

void MainWindow::on_btnMainExit_clicked()
{
    this->close();
}

//void MainWindow::on_mBtModuleTest_clicked()
//{
//    QRect tScreenGeometry = QApplication::desktop()->screenGeometry();
//    int x = (tScreenGeometry.width() - mTestModule->width()) / 2;
//    int y = (tScreenGeometry.height() - mTestModule->height()) / 2;

//    mTestModule->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//    mTestModule->move(x, y);
//    mTestModule->show();
//}

//void MainWindow::on_mBtRfTest_clicked()
//{
//    QRect tScreenGeometry = QApplication::desktop()->screenGeometry();
//    int x = (tScreenGeometry.width() - mTestRfCable->width()) / 2;
//    int y = (tScreenGeometry.height() - mTestRfCable->height()) / 2;

//    mTestRfCable->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//    mTestRfCable->move(x, y);
//    mTestRfCable->show();
//}
