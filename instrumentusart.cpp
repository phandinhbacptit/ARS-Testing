#include "instrumentusart.h"
#include "ui_instrumentusart.h"

instrumentUsart::instrumentUsart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instrumentUsart)
{
    ui->setupUi(this);
}

instrumentUsart::~instrumentUsart()
{
    delete ui;
}
Ui::instrumentUsart *instrumentUsart::getUi() const
{
    return  ui;
}

void instrumentUsart::setUi(Ui::instrumentUsart *value)
{
    ui = value;
}
