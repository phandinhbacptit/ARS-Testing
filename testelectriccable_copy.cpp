#include "testelectriccable.h"
#include "ui_testelectriccable.h"

TestElectricCable::TestElectricCable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestElectricCable)
{
    ui->setupUi(this);
    displayTree();
}

TestElectricCable::~TestElectricCable()
{
    delete ui;

}
void TestElectricCable::displayTree()
{/*
        QIcon icon_test;

        icon_uncheck           = QPixmap(":/Test/images/box/box_blank.png");
        icon_checked           = QPixmap(":/Test/images/box/box_success.png");
        icon_test              = QIcon (":/Test/images/box/box_blank.png");
        ui->treeWidget->setColumnCount(1);

        QStringList labels;
        labels <<"FileName";
        ui->treeWidget->setHeaderLabels(labels);

        QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
        root->setText(0, "RootFIle");
//        root->setCheckState(0, Qt::Unchecked);
       // root->setExpanded(1);
        ui->treeWidget->addTopLevelItem(root);
        ui->treeWidget->setItemWidget(root,2,new QPushButton("OK"));

        QTreeWidgetItem *child1 = new QTreeWidgetItem();
        child1->setText(0, "Child1 file");
        child1->setCheckState(0, Qt::Checked);
        root->addChild(child1);

        QTreeWidgetItem *child2 = new QTreeWidgetItem();
        child2->setText(0, "Child2 file");
        child2->setCheckState(0, Qt::Checked);
        root->addChild(child2);

        QTreeWidgetItem *child3 = new QTreeWidgetItem();
        child3->setText(0, "Child3 file");
        child3->setCheckState(0, Qt::Unchecked);
        root->addChild(child3);*/
}

/*
QCheckBox::indicator::unchecked
{
    image: url(":/Test/images/box/box_blank.png");
}
QCheckBox::indicator::checked
{
    image: url(":/Test/images/box/box_success.png");
}
*/

void TestElectricCable::on_btn_exit_clicked()
{
    this->close();
}
