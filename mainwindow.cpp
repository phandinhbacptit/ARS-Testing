#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QCloseEvent>
#include <QDir>
#include <QString>

#include "qtCsv/include/qtcsv_global.h"
#include "qtCsv/include/stringdata.h"
#include "qtCsv/include/reader.h"
#include "qtCsv/include/writer.h"

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

    mUi->cbNameExcutor->setEditable(true);
    mUi->cbNameSupervisor->setEditable(true);
    mUi->cbIDExcutor->setEditable(true);
    mUi->cbIDSupervisor->setEditable(true);
    mUi->cbWorkExcutor->setEditable(true);
    mUi->cbWorkSupervisor->setEditable(true);
    mUi->cbLocalTest->setEditable(true);

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
    if (QMessageBox::Yes == QMessageBox::question(this, "Close confirm", "Thoát khỏi phần mềm kiểm tra các thành phần của ĐTD?", QMessageBox::Yes | QMessageBox::No)) {
        this->close();
    }
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

void MainWindow::initCombobox(QString path, QString nameCombobox)
{
    QString filePath = QDir::currentPath() + path;
    QStringList listItem;

    QList<QStringList> getData = QtCSV::Reader::readToList(filePath);
    for (int i = 0; i < getData.at(0).size(); i++) {
        listItem << getData.at(0).at(i);
    }
    if (nameCombobox == "nameExcutor") {
//        mUi->comboBox->addItems(listItem);
    }
}

void MainWindow::saveInformCombobox(QString DataSave, QString nameCobobox, QString path)
{
    QString filePath = QDir::currentPath() + path;
    QStringList listItem;
    QtCSV::StringData strData;

    QList<QStringList> getData = QtCSV::Reader::readToList(filePath);
    for (int i = 0; i < getData.at(0).size(); i++) {
        listItem << getData.at(0).at(i);
    }
    listItem << DataSave;

//    if (nameCobobox == "nameExcutor") {
//        if (_currentText != mUi->comboBox->currentText()) {
//            strData.addRow(listItem);
////            _currentText = mUi->comboBox->currentText();
//        }
//    }

    QtCSV::Writer::write(filePath, strData);
}
void MainWindow::on_toolButton_clicked()
{
    initCombobox(nameExcutorPath, "nameExcutor");

}

void MainWindow::on_toolButton_2_clicked()
{
    QString filePath = QDir::currentPath() + nameExcutorPath;
    QStringList listItem;
    QtCSV::StringData strData;


    QList<QStringList> getData = QtCSV::Reader::readToList(filePath);
    for (int i = 0; i < getData.at(0).size(); i++) {
        listItem << getData.at(0).at(i);
    }

//    if (_currentText != mUi->comboBox->currentText()) {
//        listItem << mUi->comboBox->currentText();
//        _currentText = mUi->comboBox->currentText();
//    }

    strData.addRow(listItem);

    QtCSV::Writer::write(filePath, strData);
}
