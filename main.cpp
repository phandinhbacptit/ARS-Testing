#include "mainwindow.h"
#include <QApplication>
#include "bussiness/bussinessmanager.h"
#include "testelectriccable.h"
#include <QtDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
//    LOGUTILS::initLogging();
    bussinessManager tBussinessManager;
    w.show();
    qDebug() << "init here";
    tBussinessManager.setup(w.ui());
    return a.exec();
}
