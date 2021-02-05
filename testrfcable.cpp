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

TestRfCable::TestRfCable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestRfCable)
{
    ui->setupUi(this);

    int charHeight = (this->height()) / 2 - 80;
    int width = this->width() / 2;

    mTimeLineRf = new kmWidgetChart(ui->gRfSignal, width, charHeight);
    mTimeLineRf->setAxisXMinMax(0.0, 100.0);
    mTimeLineRf->setAxisYMinMax(0.0, 100.0);
    mTimeLineRf->setWidgetName("Timeline");
    mTimeLineRf->pauseTimeLine(false);
    mTimeLineRf->limitChartLenght(5000);
    mTimeLineRf->setUpdateDataFromChart(true);


    int a = 20;
    mTimeLineRf->addTimeLine(&a, "Timline1");
    mTimeLineRf->addTimeLine(&a, "Timline2");
    mTimeLineRf->addTimeLine(&a, "Timline3");
    mTimeLineRf->addTimeLine(&a, "Timline4");
    mTimeLineRf->addTimeLine(&a, "Timline5");
    mTimeLineRf->addTimeLine(&a, "Timline6");

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
    this->close();
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

void TestRfCable::loadFile1(const QString &path)
{
    if (m_pPdfWidget->loadFile(path)) {
        // Update window title with the file name
        QFileInfo fi(path);
        setWindowTitle(fi.fileName());
    }
}


int TestRfCable::onOpenFile1(QString path)
{
    if (path.isEmpty()) {
        return 0;
    }

    loadFile1(path);
    return 1;
}

void TestRfCable::on_detailRf1_clicked()
{

}

void TestRfCable::on_detailRf2_clicked()
{

}

void TestRfCable::on_detailRf3_clicked()
{

}

void TestRfCable::on_detailRf4_clicked()
{

}

void TestRfCable::on_detailRf5_clicked()
{

}

void TestRfCable::on_detailRf6_clicked()
{

}

void TestRfCable::on_detailRf7_clicked()
{

}

void TestRfCable::on_detailRf8_clicked()
{

}

void TestRfCable::on_detailRf9_clicked()
{

}

void TestRfCable::on_detailRf10_clicked()
{

}

void TestRfCable::on_detailRf11_clicked()
{

}

void TestRfCable::on_detailRf12_clicked()
{

}

void TestRfCable::on_detailRf13_clicked()
{

}

void TestRfCable::on_detailRf14_clicked()
{

}

void TestRfCable::on_detailRf15_clicked()
{

}

void TestRfCable::on_detailRf16_clicked()
{

}

void TestRfCable::on_detailRf17_clicked()
{

}

void TestRfCable::on_detailRf18_clicked()
{

}

void TestRfCable::on_detailRf19_clicked()
{

}

void TestRfCable::on_detailRf20_clicked()
{

}

void TestRfCable::on_detailRf21_clicked()
{

}

void TestRfCable::on_detailRf22_clicked()
{

}

void TestRfCable::on_detailRf23_clicked()
{

}

void TestRfCable::on_detailRf24_clicked()
{

}

void TestRfCable::on_detailRf25_clicked()
{

}

void TestRfCable::on_detailRf26_clicked()
{

}

void TestRfCable::on_detailRf27_clicked()
{

}

void TestRfCable::on_detailRf28_clicked()
{

}

void TestRfCable::on_detailRf29_clicked()
{

}

void TestRfCable::on_detailRf30_clicked()
{

}

void TestRfCable::on_detailRf31_clicked()
{

}
