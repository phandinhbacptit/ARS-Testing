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

    reportElectrical.setDocumentName("Electrical Report");

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
