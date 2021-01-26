#include "mainwindow.h"
#include <QApplication>
#include "bussiness/bussinessmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    bussinessManager tBussinessManager;
    w.show();

    tBussinessManager.setup(w.ui());
    return a.exec();
}
