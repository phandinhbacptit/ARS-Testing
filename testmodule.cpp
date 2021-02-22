#include "testmodule.h"
#include "ui_testmodule.h"
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

testModule::testModule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testModule)
{
    ui->setupUi(this);
//    int charHeight = (this->height()) / 2 - 92;
//    int width = this->width() / 2;

//    mTimeLine = new kmWidgetChart(ui->m_graphdata, width, charHeight);
//    mTimeLine->setAxisXMinMax(0.0, 100.0);
//    mTimeLine->setAxisYMinMax(0.0, 100.0);
//    mTimeLine->setWidgetName("Timeline");
//    mTimeLine->pauseTimeLine(false);
//    mTimeLine->limitChartLenght(5000);
//    mTimeLine->setUpdateDataFromChart(true);

//    int a = 20;
//    mTimeLine->addTimeLine(&a, "Timline1");
//    mTimeLine->addTimeLine(&a, "Timline2");
//    mTimeLine->addTimeLine(&a, "Timline3");
//    mTimeLine->addTimeLine(&a, "Timline4");
//    mTimeLine->addTimeLine(&a, "Timline5");
//    mTimeLine->addTimeLine(&a, "Timline6");

    m_pPdfWidget = new QPdfWidget(ui->pdfModuleShow);
    QHBoxLayout *layoutPdfCableTest = new QHBoxLayout;
    layoutPdfCableTest->addWidget(m_pPdfWidget);
    layoutPdfCableTest->setContentsMargins(0,1,0,1);
    ui->pdfModuleShow->setLayout(layoutPdfCableTest);
    ui->pdfModuleShow->show();

    connect(this, SIGNAL(signal_setpage(int)), this, SLOT(slt_setpage(int)));
}

void testModule::slt_setpage(int numPage)
{
    m_pPdfWidget->setPage(numPage);
}
void testModule::onOpenFile(QString path)
{
    qDebug() << path;
    if (path.isEmpty()) {
        qDebug() << "Empty path";
        return;
    }
    if (m_pPdfWidget->loadFile(path)) {
        QFileInfo fi(path);
        setWindowTitle(fi.fileName());
    }
}

Ui::testModule *testModule::getUi() const
{
    return ui;
}

void testModule::setUi(Ui::testModule *value)
{
    ui = value;
}

testModule::~testModule()
{
    delete ui;
}


void testModule::on_mCbAll_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbGyro_all->setChecked(true);
        ui->mCbEnc_all->setChecked(true);
        ui->mCbMotor_all->setChecked(true);
        ui->mCbControl_all->setChecked(true);
    }
    else {
        ui->mCbGyro_all->setChecked(false);
        ui->mCbEnc_all->setChecked(false);
        ui->mCbMotor_all->setChecked(false);
        ui->mCbControl_all->setChecked(false);
    }
    on_mCbControl_all_clicked(checked);
    on_mCbGyro_all_clicked(checked);
    on_mCbMotor_all_clicked(checked);
    on_mCbEnc_all_clicked(checked);
}

void testModule::on_mCbControl_all_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbControl_gyro->setChecked(true);
        ui->mCbControl_bite->setChecked(true);
        ui->mCbControl_xlth->setChecked(true);
        ui->mCbControl_kdcs->setChecked(true);
        ui->mCbControl_encAzi->setChecked(true);
        ui->mCbControl_encElv->setChecked(true);
        ui->mCbControl_MotorElv->setChecked(true);
        ui->mCbControl_motorAzi->setChecked(true);
    }
    else {
        ui->mCbControl_gyro->setChecked(false);
        ui->mCbControl_bite->setChecked(false);
        ui->mCbControl_xlth->setChecked(false);
        ui->mCbControl_kdcs->setChecked(false);
        ui->mCbControl_encAzi->setChecked(false);
        ui->mCbControl_encElv->setChecked(false);
        ui->mCbControl_MotorElv->setChecked(false);
        ui->mCbControl_motorAzi->setChecked(false);
    }
}

void testModule::on_mCbGyro_all_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbGyro_azi->setChecked(true);
        ui->mCbGyro_elv->setChecked(true);
    }
    else {
        ui->mCbGyro_azi->setChecked(false);
        ui->mCbGyro_elv->setChecked(false);
    }
}

void testModule::on_mCbMotor_all_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbMotor_azi->setChecked(true);
        ui->mCbMotor_elv->setChecked(true);
    }
    else {
        ui->mCbMotor_azi->setChecked(false);
        ui->mCbMotor_elv->setChecked(false);
    }
}

void testModule::on_mCbEnc_all_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbEnc_azi->setChecked(true);
        ui->mCbEnc_elv->setChecked(true);
    }
    else {
        ui->mCbEnc_azi->setChecked(false);
        ui->mCbEnc_elv->setChecked(false);
    }
}

void testModule::on_pushButton_12_clicked()
{
    this->close();
    LOGUTILS::stopLogging();
}

void testModule::on_detailCtrXlth_clicked()
{
    qDebug() << "[TestModule] Selected detail Control and XLTH";
    onOpenFile(cable1);
}

void testModule::on_detailCtrBite_clicked()
{

    qDebug() << "[TestModule] Selected detail Control and BITE";
    emit signal_setpage(20);
}

void testModule::on_detailCtrKdcs_clicked()
{
    emit signal_setpage(30);
    qDebug() << "[TestModule] Selected detail Control and KDCS";
}

void testModule::on_detailCtrGyro_clicked()
{
    emit signal_setpage(10);
    qDebug() << "[TestModule] Selected detail Control and GYROSCOPE";
}

void testModule::on_detailCtrEncAzi_clicked()
{

    qDebug() << "[TestModule] Selected detail Control and Encoder Azi";
}

void testModule::on_detailCtrEncElv_clicked()
{

    qDebug() << "[TestModule] Selected detail Control and Encoder Elv";
}

void testModule::on_detailCtrMotorAzi_2_clicked()
{

    qDebug() << "[TestModule] Selected detail Control and Motor Azi";
}

void testModule::on_detailCtrMotorElv_clicked()
{

    qDebug() << "[TestModule] Selected detail Control and Motor Elv";
}

void testModule::on_detailGyroAzi_clicked()
{

    qDebug() << "[TestModule] Selected detail module GyroAzi";
}

void testModule::on_detailGyroElv_clicked()
{

    qDebug() << "[TestModule] Selected detail module GYroElv";
}

void testModule::on_detailEncAzi_clicked()
{

    qDebug() << "[TestModule] Selected detail module EncoderAzi";
}

void testModule::on_detailEncElv_clicked()
{

    qDebug() << "[TestModule] Selected detail module EncoderElv";
}

void testModule::on_detailMotorAzi_clicked()
{

    qDebug() << "[TestModule] Selected detail module motorAzi";
}

void testModule::on_detailMotorElv_clicked()
{

    qDebug() << "[TestModule] Selected detail module motorElv";
}

void testModule::on_mCbControl_all_clicked()
{

}

void testModule::on_mCbAapderCirculator_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbCirculator_part1->setChecked(true);
        ui->mCbCirculator_part2->setChecked(true);
    }
    else {
        ui->mCbCirculator_part1->setChecked(false);
        ui->mCbCirculator_part2->setChecked(false);
    }
}

void testModule::on_mCbAdapterComparator_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbComparator_part1->setChecked(true);
        ui->mCbComparator_part2->setChecked(true);
    }
    else {
        ui->mCbComparator_part1->setChecked(false);
        ui->mCbComparator_part2->setChecked(false);
    }

}

void testModule::on_mCbAdapterSMA_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbSMA_part1->setChecked(true);
        ui->mCbSMA_part2->setChecked(true);
    }
    else {
        ui->mCbSMA_part1->setChecked(false);
        ui->mCbSMA_part2->setChecked(false);
    }
}

void testModule::on_mCbAttXband_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbXband_part1->setChecked(true);
        ui->mCbXband_part2->setChecked(true);
    }
    else {
        ui->mCbXband_part1->setChecked(false);
        ui->mCbXband_part2->setChecked(false);
    }
}

void testModule::on_mCbHpa_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbHpa_part1->setChecked(true);
        ui->mCbHpa_part2->setChecked(true);
        ui->mCbHpa_part3->setChecked(true);
        ui->mCbHpa_part4->setChecked(true);
        ui->mCbHpa_part5->setChecked(true);
        ui->mCbHpa_part6->setChecked(true);
        ui->mCbHpa_part7->setChecked(true);
    }
    else {
        ui->mCbHpa_part1->setChecked(false);
        ui->mCbHpa_part2->setChecked(false);
        ui->mCbHpa_part3->setChecked(false);
        ui->mCbHpa_part4->setChecked(false);
        ui->mCbHpa_part5->setChecked(false);
        ui->mCbHpa_part6->setChecked(false);
        ui->mCbHpa_part7->setChecked(false);
    }
}

void testModule::on_mCbLimiter_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbLimiter_part1->setChecked(true);
        ui->mCbLimiter_part2->setChecked(true);
        ui->mCbLimiter_part3->setChecked(true);
    }
    else {
        ui->mCbLimiter_part1->setChecked(false);
        ui->mCbLimiter_part2->setChecked(false);
        ui->mCbLimiter_part3->setChecked(false);
    }
}

void testModule::on_mCbLna_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbLna_part1->setChecked(true);
        ui->mCbLna_part2->setChecked(true);
        ui->mCbLna_part3->setChecked(true);
    }
    else {
        ui->mCbLna_part1->setChecked(false);
        ui->mCbLna_part2->setChecked(false);
        ui->mCbLna_part3->setChecked(false);
    }
}

void testModule::on_mCbLo_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbLo_part1->setChecked(true);
        ui->mCbLo_part2->setChecked(true);
        ui->mCbLo_part3->setChecked(true);
    }
    else {
        ui->mCbLo_part1->setChecked(false);
        ui->mCbLo_part2->setChecked(false);
        ui->mCbLo_part3->setChecked(false);
    }
}

void testModule::on_mCbRx_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbRx_part1->setChecked(true);
        ui->mCbRx_part2->setChecked(true);
        ui->mCbRx_part3->setChecked(true);
    }
    else {
        ui->mCbRx_part1->setChecked(false);
        ui->mCbRx_part2->setChecked(false);
        ui->mCbRx_part3->setChecked(false);
    }
}

void testModule::on_mCbTx_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbTx_part1->setChecked(true);
        ui->mCbTx_part2->setChecked(true);
        ui->mCbTx_part3->setChecked(true);
    }
    else {
        ui->mCbTx_part1->setChecked(false);
        ui->mCbTx_part2->setChecked(false);
        ui->mCbTx_part3->setChecked(false);
    }
}

void testModule::on_All_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbAntena->setChecked(true);
        ui->mCbFilterIf->setChecked(true);
        ui->mCbFilterLOIF->setChecked(true);
        ui->mCbFilterLORF->setChecked(true);
        ui->mCbFilterXband->setChecked(true);
        ui->mCbTx->setChecked(true);
        ui->mCbRx->setChecked(true);
        ui->mCbLo->setChecked(true);
        ui->mCbLna->setChecked(true);
        ui->mCbLimiter->setChecked(true);
        ui->mCbHpa->setChecked(true);
        ui->mCbAapderCirculator->setChecked(true);
        ui->mCbAdapterComparator->setChecked(true);
        ui->mCbAdapterSMA->setChecked(true);
        ui->mCbAttXband->setChecked(true);
    }
    else {
        ui->mCbAntena->setChecked(false);
        ui->mCbFilterIf->setChecked(false);
        ui->mCbFilterLOIF->setChecked(false);
        ui->mCbFilterLORF->setChecked(false);
        ui->mCbFilterXband->setChecked(false);
        ui->mCbTx->setChecked(false);
        ui->mCbRx->setChecked(false);
        ui->mCbLo->setChecked(false);
        ui->mCbLna->setChecked(false);
        ui->mCbLimiter->setChecked(false);
        ui->mCbHpa->setChecked(false);
        ui->mCbAapderCirculator->setChecked(false);
        ui->mCbAdapterComparator->setChecked(false);
        ui->mCbAdapterSMA->setChecked(false);
        ui->mCbAttXband->setChecked(false);
    }
    on_mCbAapderCirculator_clicked(checked);
    on_mCbAdapterComparator_clicked(checked);
    on_mCbAdapterSMA_clicked(checked);
    on_mCbAttXband_clicked(checked);
    on_mCbHpa_clicked(checked);
    on_mCbLimiter_clicked(checked);
    on_mCbLna_clicked(checked);
    on_mCbLo_clicked(checked);
    on_mCbRx_clicked(checked);
    on_mCbTx_clicked(checked);
}
