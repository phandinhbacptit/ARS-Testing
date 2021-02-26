#include "noteandsign.h"
#include "ui_noteandsign.h"

noteAndSign::noteAndSign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::noteAndSign)
{
    ui->setupUi(this);
}

noteAndSign::~noteAndSign()
{
    delete ui;
}

Ui::noteAndSign *noteAndSign::getUi() const
{
    return  ui;
}

void noteAndSign::setUi(Ui::noteAndSign *value)
{
    ui = value;
}
