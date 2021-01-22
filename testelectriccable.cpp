#include "testelectriccable.h"
#include "ui_testelectriccable.h"
#include <QDesktopWidget>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QAction>
#include <QToolBar>
#include <QIcon>
#include <QFileDialog>
#include <QStandardPaths>
#include <QFileInfo>
#include "QPdfWidget"
#include "qmainwindow.h"
#include <QThread>
#include <QHBoxLayout>


TestElectricCable::TestElectricCable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestElectricCable)
{
    ui->setupUi(this);
    //setWindowIcon(QIcon(":/Test/icons/pdf.png"));

    m_pPdfWidget = new QPdfWidget(ui->pdfShow);
    QHBoxLayout *layoutPdfCableTest = new QHBoxLayout;
    layoutPdfCableTest->addWidget(m_pPdfWidget);
    layoutPdfCableTest->setContentsMargins(1,1,1,1);
    ui->pdfShow->setLayout(layoutPdfCableTest);
    ui->pdfShow->show();

}
TestElectricCable::~TestElectricCable()
{
    delete ui;
}
void TestElectricCable::on_btn_exit_clicked()
{
    this->close();
}

void TestElectricCable::loadFile(const QString &path)
{
    if (m_pPdfWidget->loadFile(path)) {
        // Update window title with the file name
        QFileInfo fi(path);
        setWindowTitle(fi.fileName());
    }
}

void TestElectricCable::createActions()
{
//    m_pOpenFileAction = new QAction(QIcon(":/icons/folder.png"), tr("&Open..."), this);
//    connect(m_pOpenFileAction, &QAction::triggered, this, &TestElectricCable::onOpenFile);
}
void TestElectricCable::createToolBar()
{
//    QToolBar *pToolBar = addToolBar(tr("File"));
//    pToolBar->setMovable(false);
//    pToolBar->addAction(m_pOpenFileAction);
}

void TestElectricCable::onOpenFile(QString path)
{
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open PDF file"),
//                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
//                                                    tr("PDF file (*.pdf)"));

    //QString fileName ("/GuidleFile/guideline.pdf");
    if (path.isEmpty()) {
        return;
    }

    loadFile(path);
}

void TestElectricCable::on_detail_cable1_clicked()
{
    onOpenFile(cable1);
}

void TestElectricCable::on_detail_cable2_clicked()
{
    onOpenFile(cable2);
}

void TestElectricCable::on_detail_cable3_clicked()
{
    onOpenFile(cable3);
}

void TestElectricCable::on_detail_cable4_clicked()
{
    onOpenFile(cable4);
}

void TestElectricCable::on_detail_cable5_clicked()
{
    onOpenFile(cable5);
}

void TestElectricCable::on_detail_cable6_clicked()
{
    onOpenFile(cable6);
}

void TestElectricCable::on_detail_cable9_clicked()
{
    onOpenFile(cable9);
}

void TestElectricCable::on_detail_cable10_clicked()
{
    onOpenFile(cable10);
}

void TestElectricCable::on_detail_cable11_clicked()
{
    onOpenFile(cable11);
}

void TestElectricCable::on_detail_cable12_clicked()
{
    onOpenFile(cable12);
}

void TestElectricCable::on_detail_cable13_clicked()
{
    onOpenFile(cable13);
}
