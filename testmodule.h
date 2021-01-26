#ifndef TESTMODULE_H
#define TESTMODULE_H

#include <QWidget>
#include <userconfig.h>

namespace Ui {
class testModule;
}

class testModule : public QWidget
{
    Q_OBJECT
protected:


public:
    explicit testModule(QWidget *parent = 0);
    ~testModule();
    Ui::testModule *getUi() const;
    void setUi(Ui::testModule *value);

private:
    Ui::testModule *ui;

public:
    kmWidgetChart* mTimeLine;

private slots:
    void on_pushButton_12_clicked();
};

#endif // TESTMODULE_H
