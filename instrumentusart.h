#ifndef INSTRUMENTUSART_H
#define INSTRUMENTUSART_H

#include <QDialog>

namespace Ui {
class instrumentUsart;
}

class instrumentUsart : public QDialog
{
    Q_OBJECT

public:
    explicit instrumentUsart(QWidget *parent = nullptr);
    ~instrumentUsart();
    Ui::instrumentUsart *getUi() const;
    void setUi(Ui::instrumentUsart *value);

private:
    Ui::instrumentUsart *ui;
};

#endif // INSTRUMENTUSART_H
