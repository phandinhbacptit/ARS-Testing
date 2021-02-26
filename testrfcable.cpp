#include "testrfcable.h"
#include "ui_testrfcable.h"

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
#include <QDebug>
#include "utils/logutils.h"

TestRfCable::TestRfCable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestRfCable)
{
    ui->setupUi(this);

//    int charHeight = (this->height()) / 2 - 80;
//    int width = this->width() / 2;

//    mTimeLineRf = new kmWidgetChart(ui->gRfSignal, width, charHeight);
//    mTimeLineRf->setAxisXMinMax(0.0, 100.0);
//    mTimeLineRf->setAxisYMinMax(0.0, 100.0);
//    mTimeLineRf->setWidgetName("Timeline");
//    mTimeLineRf->pauseTimeLine(false);
//    mTimeLineRf->limitChartLenght(5000);
//    mTimeLineRf->setUpdateDataFromChart(true);

//    int a = 20;
//    mTimeLineRf->addTimeLine(&a, "Timline1");
//    mTimeLineRf->addTimeLine(&a, "Timline2");
//    mTimeLineRf->addTimeLine(&a, "Timline3");
//    mTimeLineRf->addTimeLine(&a, "Timline4");
//    mTimeLineRf->addTimeLine(&a, "Timline5");
//    mTimeLineRf->addTimeLine(&a, "Timline6");

    m_pPdfWidget = new QPdfWidget(ui->pdfRfShow);
    QHBoxLayout *layoutPdfRfCableTest = new QHBoxLayout;
    layoutPdfRfCableTest->addWidget(m_pPdfWidget);
    layoutPdfRfCableTest->setContentsMargins(1,1,1,1);
    ui->pdfRfShow->setLayout(layoutPdfRfCableTest);
    ui->pdfRfShow->show();
}

Ui::TestRfCable *TestRfCable::getUi() const
{
    return ui;
}
void TestRfCable::setUi(Ui::TestRfCable *value)
{
    ui = value;
}
TestRfCable::~TestRfCable()
{
    delete ui;
}

void TestRfCable::on_pushButton_63_clicked()
{
    if (QMessageBox::Yes == QMessageBox::question(this, "Close confirm", "Thoát khỏi Tab kiểm tra các cáp RF trên ĐTD?", QMessageBox::Yes | QMessageBox::No)) {
        this->close();
        LOGUTILS::stopLogging();
    }
}

void TestRfCable::on_mCbRfAll_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbCableRf1->setChecked(true);
        ui->mCbCableRf2->setChecked(true);
        ui->mCbCableRf3->setChecked(true);
        ui->mCbCableRf4->setChecked(true);
        ui->mCbCableRf5->setChecked(true);
        ui->mCbCableRf6->setChecked(true);
        ui->mCbCableRf7->setChecked(true);
        ui->mCbCableRf8->setChecked(true);
        ui->mCbCableRf9->setChecked(true);
        ui->mCbCableRf10->setChecked(true);
        ui->mCbCableRf11->setChecked(true);
        ui->mCbCableRf12->setChecked(true);
        ui->mCbCableRf13->setChecked(true);
        ui->mCbCableRf14->setChecked(true);
        ui->mCbCableRf15->setChecked(true);
        ui->mCbCableRf16->setChecked(true);
        ui->mCbCableRf17->setChecked(true);
        ui->mCbCableRf18->setChecked(true);
        ui->mCbCableRf19->setChecked(true);
        ui->mCbCableRf20->setChecked(true);
        ui->mCbCableRf21->setChecked(true);
        ui->mCbCableRf22->setChecked(true);
        ui->mCbCableRf23->setChecked(true);
        ui->mCbCableRf24->setChecked(true);
        ui->mCbCableRf25->setChecked(true);
        ui->mCbCableRf26->setChecked(true);
        ui->mCbCableRf27->setChecked(true);
        ui->mCbCableRf28->setChecked(true);
        ui->mCbCableRf29->setChecked(true);
        ui->mCbCableRf30->setChecked(true);
        ui->mCbCableRf31->setChecked(true);
    }
    else {
        ui->mCbCableRf1->setChecked(false);
        ui->mCbCableRf2->setChecked(false);
        ui->mCbCableRf3->setChecked(false);
        ui->mCbCableRf4->setChecked(false);
        ui->mCbCableRf5->setChecked(false);
        ui->mCbCableRf6->setChecked(false);
        ui->mCbCableRf7->setChecked(false);
        ui->mCbCableRf8->setChecked(false);
        ui->mCbCableRf9->setChecked(false);
        ui->mCbCableRf10->setChecked(false);
        ui->mCbCableRf11->setChecked(false);
        ui->mCbCableRf12->setChecked(false);
        ui->mCbCableRf13->setChecked(false);
        ui->mCbCableRf14->setChecked(false);
        ui->mCbCableRf15->setChecked(false);
        ui->mCbCableRf16->setChecked(false);
        ui->mCbCableRf17->setChecked(false);
        ui->mCbCableRf18->setChecked(false);
        ui->mCbCableRf19->setChecked(false);
        ui->mCbCableRf20->setChecked(false);
        ui->mCbCableRf21->setChecked(false);
        ui->mCbCableRf22->setChecked(false);
        ui->mCbCableRf23->setChecked(false);
        ui->mCbCableRf24->setChecked(false);
        ui->mCbCableRf25->setChecked(false);
        ui->mCbCableRf26->setChecked(false);
        ui->mCbCableRf27->setChecked(false);
        ui->mCbCableRf28->setChecked(false);
        ui->mCbCableRf29->setChecked(false);
        ui->mCbCableRf30->setChecked(false);
        ui->mCbCableRf31->setChecked(false);
    }
}


/**
  * @brief  This function is used to Open PDF Guilde file
  * @note
  * @param  path - path load pdf show in display area
  * @retval 0 - if file is empty
  *         1 - if read file Successfull
***/
void TestRfCable::onOpenFile(QString path)
{
    if (path.isEmpty()) {
        return;
    }
    if (m_pPdfWidget->loadFile(path)) {
        // Update window title with the file name
        QFileInfo fi(path);
        setWindowTitle(fi.fileName());
    }
}

void TestRfCable::on_detailRf1_clicked()
{
    onOpenFile(cableRf1);
    qDebug() << "Select cable1";
}

void TestRfCable::on_detailRf2_clicked()
{
    onOpenFile(cableRf2);
    qDebug() << "Select cable2";
}

void TestRfCable::on_detailRf3_clicked()
{
    onOpenFile(cableRf3);
    qDebug() << "Select cable3";
}

void TestRfCable::on_detailRf4_clicked()
{
    onOpenFile(cableRf4);
    qDebug() << "Select cable4";
}

void TestRfCable::on_detailRf5_clicked()
{
    onOpenFile(cableRf5);
}

void TestRfCable::on_detailRf6_clicked()
{
    onOpenFile(cableRf6);
}

void TestRfCable::on_detailRf7_clicked()
{
    onOpenFile(cableRf7);
}

void TestRfCable::on_detailRf8_clicked()
{
    onOpenFile(cableRf8);
}

void TestRfCable::on_detailRf9_clicked()
{
    onOpenFile(cableRf9);
}

void TestRfCable::on_detailRf10_clicked()
{
    onOpenFile(cableRf10);
}

void TestRfCable::on_detailRf11_clicked()
{
    onOpenFile(cableRf11);
}

void TestRfCable::on_detailRf12_clicked()
{
    onOpenFile(cableRf12);
}

void TestRfCable::on_detailRf13_clicked()
{
    onOpenFile(cableRf13);
}

void TestRfCable::on_detailRf14_clicked()
{
    onOpenFile(cableRf14);
}

void TestRfCable::on_detailRf15_clicked()
{
    onOpenFile(cableRf15);
}

void TestRfCable::on_detailRf16_clicked()
{
    onOpenFile(cableRf16);
}

void TestRfCable::on_detailRf17_clicked()
{
    onOpenFile(cableRf17);
}

void TestRfCable::on_detailRf18_clicked()
{
    onOpenFile(cableRf18);
}

void TestRfCable::on_detailRf19_clicked()
{
    onOpenFile(cableRf19);
}

void TestRfCable::on_detailRf20_clicked()
{
    onOpenFile(cableRf20);
}

void TestRfCable::on_detailRf21_clicked()
{
    onOpenFile(cableRf21);
}

void TestRfCable::on_detailRf22_clicked()
{
    onOpenFile(cableRf22);
}

void TestRfCable::on_detailRf23_clicked()
{
    onOpenFile(cableRf23);
}

void TestRfCable::on_detailRf24_clicked()
{
    onOpenFile(cableRf24);
}

void TestRfCable::on_detailRf25_clicked()
{
    onOpenFile(cableRf25);
}

void TestRfCable::on_detailRf26_clicked()
{
    onOpenFile(cableRf26);
}

void TestRfCable::on_detailRf27_clicked()
{
    onOpenFile(cableRf27);
}

void TestRfCable::on_detailRf28_clicked()
{
    onOpenFile(cableRf28);
}

void TestRfCable::on_detailRf29_clicked()
{
    onOpenFile(cableRf29);
}

void TestRfCable::on_detailRf30_clicked()
{
    onOpenFile(cableRf30);
}

void TestRfCable::on_detailRf31_clicked()
{
    onOpenFile(cableRf31);
}
