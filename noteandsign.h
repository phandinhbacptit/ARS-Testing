#ifndef NOTEANDSIGN_H
#define NOTEANDSIGN_H

#include <QDialog>

namespace Ui {
class noteAndSign;
}

class noteAndSign : public QDialog
{
    Q_OBJECT

public:
    explicit noteAndSign(QWidget *parent = nullptr);
    ~noteAndSign();
    Ui::noteAndSign *getUi() const;
    void setUi(Ui::noteAndSign *value);


private:
    Ui::noteAndSign *ui;
};

#endif // NOTEANDSIGN_H
