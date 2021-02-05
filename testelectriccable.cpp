#include "testelectriccable.h"
#include "ui_testelectriccable.h"
#include <QDesktopWidget>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QAction>
#include <QToolBar>
#include <QIcon>
#include <QFileDialog>
#include <QStandardPaths>
#include <QFileInfo>
#include "QPdfWidget"
#include "qmainwindow.h"
#include <QThread>
#include <QHBoxLayout>


TestElectricCable::TestElectricCable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestElectricCable)
{
    ui->setupUi(this);
    //setWindowIcon(QIcon(":/Test/icons/pdf.png"));

    m_pPdfWidget = new QPdfWidget(ui->pdfShow);
    QHBoxLayout *layoutPdfCableTest = new QHBoxLayout;
    layoutPdfCableTest->addWidget(m_pPdfWidget);
    layoutPdfCableTest->setContentsMargins(1,1,1,1);
    ui->pdfShow->setLayout(layoutPdfCableTest);
    ui->pdfShow->show();
}
TestElectricCable::~TestElectricCable()
{
    delete ui;
}

Ui::TestElectricCable *TestElectricCable::getUi() const
{
    return ui;
}

void TestElectricCable::setUi(Ui::TestElectricCable *value)
{
    ui = value;
}

void TestElectricCable::on_btn_exit_clicked()
{
    this->close();
}

void TestElectricCable::loadFile(const QString &path)
{
    if (m_pPdfWidget->loadFile(path)) {
        // Update window title with the file name
        QFileInfo fi(path);
        setWindowTitle(fi.fileName());
    }
}

void TestElectricCable::createActions()
{
//    m_pOpenFileAction = new QAction(QIcon(":/icons/folder.png"), tr("&Open..."), this);
//    connect(m_pOpenFileAction, &QAction::triggered, this, &TestElectricCable::onOpenFile);
}
void TestElectricCable::createToolBar()
{
//    QToolBar *pToolBar = addToolBar(tr("File"));
//    pToolBar->setMovable(false);
//    pToolBar->addAction(m_pOpenFileAction);
}

void TestElectricCable::onOpenFile(QString path)
{
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open PDF file"),
//                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
//                                                    tr("PDF file (*.pdf)"));

    //QString fileName ("/GuidleFile/guideline.pdf");
    if (path.isEmpty()) {
        return;
    }

    loadFile(path);
}

void TestElectricCable::on_detail_cable1_clicked()
{
    onOpenFile(cable1);
}

void TestElectricCable::on_detail_cable2_clicked()
{
    onOpenFile(cable2);
}

void TestElectricCable::on_detail_cable3_clicked()
{
    onOpenFile(cable3);
}

void TestElectricCable::on_detail_cable4_clicked()
{
    onOpenFile(cable4);
}

void TestElectricCable::on_detail_cable5_clicked()
{
    onOpenFile(cable5);
}

void TestElectricCable::on_detail_cable6_clicked()
{
    onOpenFile(cable6);
}

void TestElectricCable::on_detail_cable9_clicked()
{
    onOpenFile(cable9);
}

void TestElectricCable::on_detail_cable10_clicked()
{
    onOpenFile(cable10);
}

void TestElectricCable::on_detail_cable11_clicked()
{
    onOpenFile(cable11);
}

void TestElectricCable::on_detail_cable12_clicked()
{
    onOpenFile(cable12);
}

void TestElectricCable::on_detail_cable13_clicked()
{
    onOpenFile(cable13);
}

//void TestElectricCable::on_btnExportCte_clicked()
//{
//    KDReports::Header& header = reportElectrical.header(KDReports::FirstPage);
//    QPixmap kdab(":Test/images/logo_vtx.png");
//    QPainter painter(&kdab);
//    //painter.drawRect( 0, 0, kdab.width() - 1, kdab.height() - 1 );
//    KDReports::ImageElement imageElement(kdab);
//    imageElement.setWidth(30); // mm
//    header.addElement(imageElement);
//    header.addElement(KDReports::TextElement("This header should be on the first page."
//                                               " The kdab logo should be 50mm wide and 24mm high." ));

////    header.addElement(KDReports::TextElement"Reporter: ");
////    header.addVariable

//    KDReports::PreviewDialog preview(&reportElectrical);
//    preview.setDefaultSaveDirectory(QDir::homePath());
//    preview.exec();
//}
/**
  * @brief  This function is used to check state of Checkbox ALL cable to checked/unchecked all cable
  * @note
  * @param  checked - true: all cable was checked
  *                   false: all cable unchecked
  * @retval None
***/
void TestElectricCable::on_mCbAllCable_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbCable1->setChecked(true);
        ui->mCbCable2->setChecked(true);
        ui->mCbCable3->setChecked(true);
        ui->mCbCable4->setChecked(true);
        ui->mCbCable5->setChecked(true);
        ui->mCbCable6->setChecked(true);
        ui->mCbCable9->setChecked(true);
        ui->mCbCable10->setChecked(true);
        ui->mCbCable11->setChecked(true);
        ui->mCbCable12->setChecked(true);
        ui->mCbCable13->setChecked(true);
    }
    else {

        ui->mCbCable1->setChecked(false);
        ui->mCbCable2->setChecked(false);
        ui->mCbCable3->setChecked(false);
        ui->mCbCable4->setChecked(false);
        ui->mCbCable5->setChecked(false);
        ui->mCbCable6->setChecked(false);
        ui->mCbCable9->setChecked(false);
        ui->mCbCable10->setChecked(false);
        ui->mCbCable11->setChecked(false);
        ui->mCbCable12->setChecked(false);
        ui->mCbCable13->setChecked(false);
    }
    emit sign_checkAllCable(checked);
}
/**
  * @brief  This function is used to check state of Checkbox ALL to checked/unchecked all Rearpannel router
  * @note
  * @param  checked - true: all rearpannel router was checked
  *                   false: all rearpannel router unchecked
  * @retval None
***/
void TestElectricCable::on_mCbAllRear_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbAll_Pwr00B->setChecked(true);
        ui->mCbCtr_All->setChecked(true);
        ui->mCbLoIF_all->setChecked(true);
        ui->mCbLoRF_All->setChecked(true);
        ui->mCbRxSum_all->setChecked(true);
        ui->mCbRxDiff_all->setChecked(true);
        ui->mCbAll_Pwr00B->setChecked(true);
        ui->mCbAll_AttDivider->setChecked(true);
        ui->mCbKdcs_Pwr02->setChecked(true);
        ui->mCbTx_power01A->setChecked(true);
        ui->mCbXLTHPwr_pwr01B->setChecked(true);
    }
    else {
        ui->mCbAll_Pwr00B->setChecked(false);
        ui->mCbCtr_All->setChecked(false);
        ui->mCbLoIF_all->setChecked(false);
        ui->mCbLoRF_All->setChecked(false);
        ui->mCbRxSum_all->setChecked(false);
        ui->mCbRxDiff_all->setChecked(false);
        ui->mCbAll_Pwr00B->setChecked(false);
        ui->mCbAll_AttDivider->setChecked(false);
        ui->mCbKdcs_Pwr02->setChecked(false);
        ui->mCbTx_power01A->setChecked(false);
        ui->mCbXLTHPwr_pwr01B->setChecked(false);
    }
    on_mCbCtr_All_clicked(checked);
    on_mCbRxDiff_all_clicked(checked);
    on_mCbRxSum_all_clicked(checked);
    on_mCbLoIF_all_clicked(checked);
    on_mCbLoRF_All_clicked(checked);
    on_mCbAll_AttDivider_clicked(checked);
    on_mCbAll_Pwr00B_clicked(checked);
    emit sign_checkAllRear(checked);
}
/**
  * @brief  This function is used to check state of Checkbox "CONTROL_R - ALL" to checked/unchecked all control router
  * @note
  * @param  checked - true: All control router was checked
  *                   false: All control router unchecked
  * @retval None
***/
void TestElectricCable::on_mCbCtr_All_clicked(bool checked)
{
    qDebug() << checked;
    if (checked == true) {
        ui->mCbCtr_enc->setChecked(true);
        ui->mCbCtr_gyro->setChecked(true);
        ui->mCbCtr_motor->setChecked(true);
        ui->mCbCtr_pwr02->setChecked(true);
        ui->mCbCtr_gpio1A->setChecked(true);
        ui->mCbCtr_pwr01B->setChecked(true);
        ui->mCbCtr_pwr01A->setChecked(true);
    }
    else {
        ui->mCbCtr_enc->setChecked(false);
        ui->mCbCtr_gyro->setChecked(false);
        ui->mCbCtr_motor->setChecked(false);
        ui->mCbCtr_pwr02->setChecked(false);
        ui->mCbCtr_gpio1A->setChecked(false);
        ui->mCbCtr_pwr01B->setChecked(false);
        ui->mCbCtr_pwr01A->setChecked(false);
    }
}

/**
  * @brief  This function is used to check state of Checkbox "RX_DIFF_R - ALL" to checked/unchecked all Rx diff router
  * @note
  * @param  checked - true: All Rx Diff router was checked
  *                   false: All Rx Diff router unchecked
  * @retval None
***/
void TestElectricCable::on_mCbRxDiff_all_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbRxDiff_gpio0A->setChecked(true);
        ui->mCbRxDiff_pwr01A->setChecked(true);
    }
    else {
        ui->mCbRxDiff_gpio0A->setChecked(false);
        ui->mCbRxDiff_pwr01A->setChecked(false);
    }
}
/**
  * @brief  This function is used to check state of Checkbox "RX_SUM_R - ALL" to checked/unchecked all Rx_SUM_R router
  * @note
  * @param  checked - true: All Rx_SUM_R router was checked
  *                   false: All Rx_SUM_R router unchecked
  * @retval None
***/
void TestElectricCable::on_mCbRxSum_all_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbRxSum_gpioA->setChecked(true);
        ui->mCbRxSum_pwr01A->setChecked(true);
    }
    else {
        ui->mCbRxSum_gpioA->setChecked(false);
        ui->mCbRxSum_pwr01A->setChecked(false);
    }
}
/**
  * @brief  This function is used to check state of Checkbox "LO_IF_R - ALL" to checked/unchecked all LO_IF_R router
  * @note
  * @param  checked - true: All LO_IF_R router was checked
  *                   false: All LO_IF_R router unchecked
  * @retval None
***/
void TestElectricCable::on_mCbLoIF_all_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbLoIF_gpio0A->setChecked(true);
        ui->mCbLoIF_gpio0B->setChecked(true);
        ui->mCbLoIF_gpio1A->setChecked(true);
    }
    else {
        ui->mCbLoIF_gpio0A->setChecked(false);
        ui->mCbLoIF_gpio0B->setChecked(false);
        ui->mCbLoIF_gpio1A->setChecked(false);
    }
}

/**
  * @brief  This function is used to check state of Checkbox "LO_IF_R - ALL" to checked/unchecked all LO_RF_R router
  * @note
  * @param  checked - true: All LO_RF_R router was checked
  *                   false: All LO_RF_R router unchecked
  * @retval None
***/
void TestElectricCable::on_mCbLoRF_All_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbLoRF_gpio0A->setChecked(true);
        ui->mCbLoRF_gpio0B->setChecked(true);
        ui->mCbLoRF_gpio1A->setChecked(true);
    }
    else {
        ui->mCbLoRF_gpio0A->setChecked(false);
        ui->mCbLoRF_gpio0B->setChecked(false);
        ui->mCbLoRF_gpio1A->setChecked(false);
    }
}
/**
  * @brief  This function is used to check state of Checkbox "ATT_DIVIDER_TX_R - ALL" to checked/unchecked all ATT_DIVIDER_TX_R router
  * @note
  * @param  checked - true: All ATT_DIVIDER_TX_R router was checked
  *                   false: All ATT_DIVIDER_TX_R router unchecked
  * @retval None
***/
void TestElectricCable::on_mCbAll_AttDivider_clicked(bool checked)
{
    if (checked == true) {
        ui->mCbAttDivider_pwr0A->setChecked(true);
        ui->mCbAttDivider_gpio0A->setChecked(true);
    }
    else {
        ui->mCbAttDivider_pwr0A->setChecked(false);
        ui->mCbAttDivider_gpio0A->setChecked(false);
    }
}
/**
  * @brief  This function is used to check state of Checkbox "ALL - POWER00_B_R " to checked/unchecked all POWER00_B_R router
  * @note
  * @param  checked - true: All POWER00_B_R router was checked
  *                   false: All POWER00_B_R router unchecked
  * @retval None
***/
void TestElectricCable::on_mCbAll_Pwr00B_clicked(bool checked)
{
    if (checked == true) {
        ui->mCb27V_Pwr00B->setChecked(true);
        ui->mCbGND_Pwr00B->setChecked(true);
    }
    else {
        ui->mCb27V_Pwr00B->setChecked(false);
        ui->mCbGND_Pwr00B->setChecked(false);
    }
}
