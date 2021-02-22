#ifndef SRCREPORT_H
#define SRCREPORT_H
#include "bussiness/bussinessmanager.h"

#include "KDReports/KDReports.h"
#include "KDReports/KDReportsReport.h"
#include "KDReports/KDReportsTableElement.h"
#include "KDReports/KDReportsChartElement.h"
#include "KDReports/KDReportsTextElement.h"
#include "KDReports/KDReportsHtmlElement.h"
#include "KDReports/KDReportsPreviewDialog.h"

class srcReport : public bussinessManager
{

public:
    explicit srcReport ();
    ~srcReport();
    void creatHeader(KDReports::Report *report, QString typeTest, QString namepart);
public slots:

private:
    bussinessManager *mbussiness;

};
#endif // SRCREPORT_H
