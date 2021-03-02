#include "instrumentehernet.h"
#include "ui_instrumentehernet.h"

instrumentEhernet::instrumentEhernet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instrumentEhernet)
{
    ui->setupUi(this);
}

instrumentEhernet::~instrumentEhernet()
{
    delete ui;
}

Ui::instrumentEhernet *instrumentEhernet::getUi() const
{
    return  ui;
}

void instrumentEhernet::setUi(Ui::instrumentEhernet *value)
{
    ui = value;
}
