#ifndef TESTMECHANICAL_H
#define TESTMECHANICAL_H

#include <QWidget>

namespace Ui {
class TestMechanical;
}

class TestMechanical : public QWidget
{
    Q_OBJECT

public:
    explicit TestMechanical(QWidget *parent = 0);
    ~TestMechanical();

private:
    Ui::TestMechanical *ui;
};

#endif // TESTMECHANICAL_H
