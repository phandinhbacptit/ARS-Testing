#include "testmodule.h"
#include "ui_testmodule.h"
//#include "globalVariable.h"

testModule::testModule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testModule)
{
    ui->setupUi(this);
    int charHeight = (this->height()) / 2 - 92;
    int width = this->width() / 2;

    mTimeLine = new kmWidgetChart(ui->m_graphdata, width, charHeight);
    mTimeLine->setAxisXMinMax(0.0, 100.0);
    mTimeLine->setAxisYMinMax(0.0, 100.0);
    mTimeLine->setWidgetName("Timeline");
    mTimeLine->pauseTimeLine(false);
    mTimeLine->limitChartLenght(5000);
    mTimeLine->setUpdateDataFromChart(true);

    int a = 20;
    mTimeLine->addTimeLine(&a, "Timline1");
    mTimeLine->addTimeLine(&a, "Timline2");
    mTimeLine->addTimeLine(&a, "Timline3");
    mTimeLine->addTimeLine(&a, "Timline4");
    mTimeLine->addTimeLine(&a, "Timline5");
    mTimeLine->addTimeLine(&a, "Timline6");
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
}
