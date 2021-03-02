#ifndef INSTRUMENTEHERNET_H
#define INSTRUMENTEHERNET_H

#include <QDialog>

namespace Ui {
class instrumentEhernet;
}

class instrumentEhernet : public QDialog
{
    Q_OBJECT

public:
    explicit instrumentEhernet(QWidget *parent = nullptr);
    ~instrumentEhernet();
    Ui::instrumentEhernet *getUi() const;
    void setUi(Ui::instrumentEhernet *value);

private:
    Ui::instrumentEhernet *ui;
};

#endif // INSTRUMENTEHERNET_H
