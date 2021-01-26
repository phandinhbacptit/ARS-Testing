#include "testmechanical.h"
#include "ui_testmechanical.h"

TestMechanical::TestMechanical(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestMechanical)
{
    ui->setupUi(this);
}

TestMechanical::~TestMechanical()
{
    delete ui;
}

Ui::TestMechanical *TestMechanical::getUi() const
{
    return ui;
}

void TestMechanical::setUi(Ui::TestMechanical *value)
{
    ui = value;
}
