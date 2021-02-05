#ifndef TESTRFCABLE_H
#define TESTRFCABLE_H

#include <QWidget>
#include <QMainWindow>
#include <QString>

#include <QDesktopWidget>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "userconfig.h"

class QAction;
class QPdfWidget;

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
    void on_mCbRfAll_clicked(bool checked);
    void onOpenFile(QString path);

    void on_detailRf1_clicked();

    void on_detailRf2_clicked();

    void on_detailRf3_clicked();

    void on_detailRf4_clicked();

    void on_detailRf5_clicked();

    void on_detailRf6_clicked();

    void on_detailRf7_clicked();

    void on_detailRf8_clicked();

    void on_detailRf9_clicked();

    void on_detailRf10_clicked();

    void on_detailRf11_clicked();

    void on_detailRf12_clicked();

    void on_detailRf13_clicked();

    void on_detailRf14_clicked();

    void on_detailRf15_clicked();

    void on_detailRf16_clicked();

    void on_detailRf17_clicked();

    void on_detailRf18_clicked();

    void on_detailRf19_clicked();

    void on_detailRf20_clicked();

    void on_detailRf21_clicked();

    void on_detailRf22_clicked();

    void on_detailRf23_clicked();

    void on_detailRf24_clicked();

    void on_detailRf25_clicked();

    void on_detailRf26_clicked();

    void on_detailRf27_clicked();

    void on_detailRf28_clicked();

    void on_detailRf29_clicked();

    void on_detailRf30_clicked();

    void on_detailRf31_clicked();

public slots:

private:
    Ui::TestRfCable *ui;
    QPdfWidget *m_pPdfWidget;
    QAction *m_pOpenFileAction;



public:
    kmWidgetChart* mTimeLineRf;
};

#endif // TESTRFCABLE_H
