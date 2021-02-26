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
