#ifndef TESTRFCABLE_H
#define TESTRFCABLE_H

#include <QWidget>
#include "userconfig.h"

namespace Ui {
class TestRfCable;
}

class TestRfCable : public QWidget
{
    Q_OBJECT

public:
    explicit TestRfCable(QWidget *parent = 0);
    ~TestRfCable();
    Ui::TestRfCable *getUi() const;
    void setUi(Ui::TestRfCable *value);
private slots:
    void on_pushButton_63_clicked();

private:
    Ui::TestRfCable *ui;

public:
    kmWidgetChart* mTimeLineRf;
};

#endif // TESTRFCABLE_H
