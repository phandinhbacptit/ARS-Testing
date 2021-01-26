#include "testrfcable.h"
#include "ui_testrfcable.h"

TestRfCable::TestRfCable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestRfCable)
{
    ui->setupUi(this);

    int charHeight = (this->height()) / 2 - 92;
    int width = this->width() / 2 - 120;

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
