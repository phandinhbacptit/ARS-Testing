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

    initCombobox(nameExcutorPath, "nameExcutor");
    initCombobox(idExcutorPath, "IDExcutor");
    initCombobox(workExcutorPath, "workExcutor");
    initCombobox(nameSupervisorPath, "nameSupervisor");
    initCombobox(idSupervisorPath, "IDSupervisor");
    initCombobox(workSupervisorPath, "workSupervisor");
    initCombobox(localTestPath, "localTest");

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

void MainWindow::on_btnMainExit_clicked()
{
    if (QMessageBox::Yes == QMessageBox::question(this, "Close confirm", "Thoát khỏi phần mềm kiểm tra các thành phần của ĐTD?", QMessageBox::Yes | QMessageBox::No)) {
        this->close();
    }
}

void MainWindow::initCombobox(QString path, QString nameCombobox)
{
    QString filePath = QDir::currentPath() + path;
    QStringList listItem;

    QList<QStringList> getData = QtCSV::Reader::readToList(filePath);

    if (getData.at(0).at(0) != NULL) {
        for (int i = 0; i < getData.at(0).size(); i++) {
            listItem << getData.at(0).at(i);
        }

        if (nameCombobox == "nameExcutor") {
            mUi->cbNameExcutor->addItems(listItem);
        }
        if (nameCombobox == "IDExcutor") {
            mUi->cbIDExcutor->addItems(listItem);
        }
        if (nameCombobox == "workExcutor") {
            mUi->cbWorkExcutor->addItems(listItem);
        }
        if (nameCombobox == "nameSupervisor") {
            mUi->cbNameSupervisor->addItems(listItem);
        }
        if (nameCombobox == "IDSupervisor") {
            mUi->cbIDSupervisor->addItems(listItem);
        }
        if (nameCombobox == "workSupervisor") {
            mUi->cbWorkSupervisor->addItems(listItem);
        }
        if (nameCombobox == "localTest") {
            mUi->cbLocalTest->addItems(listItem);
        }
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

    if (nameCobobox == "nameExecutor") {
        qDebug() << "Save current text of name Executor";
        if (_currentText != mUi->cbNameExcutor->currentText()) {
            strData.addRow(listItem);
            mUi->cbNameExcutor->addItem(mUi->cbNameExcutor->currentText());
            _currentText = mUi->cbNameExcutor->currentText();
            QtCSV::Writer::write(filePath, strData);
        }
    }
    if (nameCobobox == "IDExecutor") {
        qDebug() << "Save current text of ID Executor";
        if (_currentText != mUi->cbIDExcutor->currentText()) {
            strData.addRow(listItem);
            mUi->cbIDExcutor->addItem(mUi->cbIDExcutor->currentText());
            _currentText = mUi->cbIDExcutor->currentText();
            QtCSV::Writer::write(filePath, strData);
        }
    }
    if (nameCobobox == "workExecutor") {
        qDebug() << "Save current text of work Executor";
        if (_currentText != mUi->cbWorkExcutor->currentText()) {
            strData.addRow(listItem);
            mUi->cbWorkExcutor->addItem(mUi->cbWorkExcutor->currentText());
            _currentText = mUi->cbWorkExcutor->currentText();
            QtCSV::Writer::write(filePath, strData);
        }
    }
    if (nameCobobox == "nameSupervisor") {
        qDebug() << "Save current text of name Supervisor";
        if (_currentText != mUi->cbNameSupervisor->currentText()) {
            strData.addRow(listItem);
            mUi->cbNameSupervisor->addItem(mUi->cbNameSupervisor->currentText());
            _currentText = mUi->cbNameSupervisor->currentText();
            QtCSV::Writer::write(filePath, strData);
        }
    }
    if (nameCobobox == "IDSupervisor") {
        qDebug() << "Save current text of ID Supervisor";
        if (_currentText != mUi->cbIDSupervisor->currentText()) {
            strData.addRow(listItem);
            mUi->cbIDSupervisor->addItem(mUi->cbIDSupervisor->currentText());
            _currentText = mUi->cbIDSupervisor->currentText();
            QtCSV::Writer::write(filePath, strData);
        }
    }
    if (nameCobobox == "workSupervisor") {
        qDebug() << "Save current text of work supervisor";
        if (_currentText != mUi->cbWorkSupervisor->currentText()) {
            strData.addRow(listItem);
            mUi->cbWorkSupervisor->addItem(mUi->cbWorkSupervisor->currentText());
            _currentText = mUi->cbWorkSupervisor->currentText();
            QtCSV::Writer::write(filePath, strData);
        }
    }
    if (nameCobobox == "localTest") {
        qDebug() << "Save current text of local Test";
        if (_currentText != mUi->cbLocalTest->currentText()) {
            strData.addRow(listItem);
            mUi->cbLocalTest->addItem(mUi->cbLocalTest->currentText());
            _currentText = mUi->cbLocalTest->currentText();
            QtCSV::Writer::write(filePath, strData);
        }
    }

}
void MainWindow::on_toolButton_clicked()
{
//    initCombobox(nameExcutorPath, "nameExcutor");

}

void MainWindow::on_toolButton_2_clicked()
{
//    QString filePath = QDir::currentPath() + nameExcutorPath;
//    QStringList listItem;
//    QtCSV::StringData strData;


//    QList<QStringList> getData = QtCSV::Reader::readToList(filePath);
//    for (int i = 0; i < getData.at(0).size(); i++) {
//        listItem << getData.at(0).at(i);
//    }

////    if (_currentText != mUi->comboBox->currentText()) {
////        listItem << mUi->comboBox->currentText();
////        _currentText = mUi->comboBox->currentText();
////    }

//    strData.addRow(listItem);

//    QtCSV::Writer::write(filePath, strData);
}

void MainWindow::on_addNameExcutor_clicked()
{
    saveInformCombobox(mUi->cbNameExcutor->currentText(),"nameExecutor", nameExcutorPath);
}

void MainWindow::on_addNameSupervisor_clicked()
{
    saveInformCombobox(mUi->cbNameSupervisor->currentText(),"nameSupervisor", nameSupervisorPath);
}

void MainWindow::on_addLocalTest_clicked()
{
    saveInformCombobox(mUi->cbLocalTest->currentText(),"localTest", localTestPath);
}

void MainWindow::on_addIDExcutor_clicked()
{
    saveInformCombobox(mUi->cbIDExcutor->currentText(),"IDExecutor", idExcutorPath);
}

void MainWindow::on_addIDSupervisor_clicked()
{
    saveInformCombobox(mUi->cbIDSupervisor->currentText(),"IDSupervisor", idSupervisorPath);
}

void MainWindow::on_addWorkExcutor_clicked()
{
    saveInformCombobox(mUi->cbWorkExcutor->currentText(),"workExecutor", workExcutorPath);
}

void MainWindow::on_addWorkSupervisor_clicked()
{
    saveInformCombobox(mUi->cbWorkSupervisor->currentText(),"workSupervisor", workSupervisorPath);
}
