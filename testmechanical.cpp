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
