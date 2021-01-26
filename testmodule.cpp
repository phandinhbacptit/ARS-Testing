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

void testModule::on_pushButton_12_clicked()
{
    this->close();
}
