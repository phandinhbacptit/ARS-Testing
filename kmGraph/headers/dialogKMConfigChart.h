#ifndef DIALOGCONFIGCHART_H
#define DIALOGCONFIGCHART_H

#include <QDialog>
#include <QColorDialog>
#include <vector>
#include <map>
#include <QComboBox>
#include "kmChartHandler.h"

namespace Ui {
class dialogKMConfigChart;
}


enum kmSelectedItem
{
    kmManual,
    kmDropPin,
    kmLinePoint,
    kmLastPoint,
    kmMark,
    kmPeak
};

class kmWidgetChart;
class kmChartLine;
class dialogKMConfigChart : public QDialog
{
    Q_OBJECT

public:
    //explicit dialogKMConfigChart(QWidget *parent = 0, kmWidgetChart* pChart = 0);
    explicit dialogKMConfigChart(QWidget *parent = 0, kmChartHandler* pHandler = 0);
    ~dialogKMConfigChart();

private slots:
    void on_pbOk_clicked();

    void on_pbColor_clicked();

    void on_pbColor_2_clicked();

    void on_pbColor_3_clicked();

    void on_pbColor_4_clicked();

    void on_pbColor_5_clicked();

    void on_pbColor_6_clicked();

    void on_pbColor_7_clicked();

    void on_pbColor_8_clicked();

    void on_pbColor_9_clicked();

    void on_pbColor_10_clicked();

    void on_pbColor_11_clicked();

    void on_pbColor_12_clicked();

    void on_pbColor_13_clicked();

    void on_pbColor_14_clicked();

    void on_pbColor_15_clicked();

    void setLineColor(kmChartLine* line, QWidget* pb);

    void on_pbBackGroundColor_clicked();

    //void on_pbBigGridColor_clicked();

    //void on_pbSmallGridColor_clicked();

    //void on_pbAxisColor_clicked();

    //void on_pbTextBigGridCr_clicked();

    //void on_pbTextSmallGridText_clicked();

    void on_pbBorderColor_clicked();

    //void on_pbAxisTextColor_clicked();

    void on_pbTitleTextColor_clicked();

    void on_pbApply_clicked();

    void on_cbWidgetStyle_currentIndexChanged(int index);

    void on_pbApply_2_clicked();

    void on_pbOk_2_clicked();

    void on_pbColor_16_clicked();

    void on_pbColor_17_clicked();

    void on_pbColor_18_clicked();

    void on_pbColor_19_clicked();

    void on_pbColor_20_clicked();

    void on_pbColor_21_clicked();

    void on_pbColor_22_clicked();

    void on_pbColor_23_clicked();

    void on_pbColor_24_clicked();

    void on_pbColor_25_clicked();

    void on_pbColor_26_clicked();

    void on_pbColor_27_clicked();

    void on_pbColor_28_clicked();

    void on_pbColor_29_clicked();

    void on_pbColor_30_clicked();

    void on_pbColor_31_clicked();

    void on_pbColor_32_clicked();

    void on_pbColor_33_clicked();

    void on_pbColor_34_clicked();

    void on_pbColor_35_clicked();

    void on_pbColor_36_clicked();

    void on_pbColor_37_clicked();

    void on_pbColor_38_clicked();

    void on_pbColor_39_clicked();

    void on_pbColor_40_clicked();

    void on_pbColor_41_clicked();

    void on_pbColor_42_clicked();

    void on_pbColor_43_clicked();

    void on_pbColor_44_clicked();

    void on_pbColor_45_clicked();

    void on_pbColor_46_clicked();

    void on_pbColor_47_clicked();

    void on_pbColor_48_clicked();

    void on_pbColor_49_clicked();

    void on_pbColor_50_clicked();

    void on_pbSum2Line_clicked();

    void on_pbSub2Line_clicked();

    void on_pbMultipe2Line_clicked();

    void on_pbDivide2Line_clicked();

    void on_pbAddReservedLine_clicked();

    void on_pbRemoveLine_clicked();

    void on_pbDropPinFontColor_clicked();

    //void on_pbMarkPointFontColor_clicked();

    //void on_pbLastPointFontColor_clicked();

    void on_pbDownRate_clicked();

    void on_pbChartBackGroundColor_clicked();

    void on_cbPoint_currentIndexChanged(int index);

    void on_pbDropPinFill_clicked();

    void on_pbDropPinLine_clicked();

    void on_pbSetIcon_clicked();

    void on_cbDropPinTextView_currentIndexChanged(int index);

    void on_pbLegendLineColor_clicked();

    void on_pbLegendFillColor_clicked();

    void on_pbTextBigGridCr_2_clicked();

    void on_pbAxisXMainLineColor_clicked();

    void on_pbAxisXSmallLineColor_clicked();

    void on_pbAxisXMainTextColor_clicked();

    void on_pbAxisXSmallTextColor_clicked();

    void on_pbAxisYMainLineColor_clicked();

    void on_pbAxisYSmallLineColor_clicked();

    void on_pbAxisYMainTextColor_clicked();

    void on_pbAxisYSmallTextColor_clicked();

    void on_pbAddXYLine_clicked();

    void on_pbAddFormularLine_clicked();

    void on_cbCurrentLine_currentIndexChanged(int index);

    //void on_pbClearFormular_clicked();

    void on_cbCustomeFunc_currentIndexChanged(int index);

    void on_cbLinePage_currentIndexChanged(int index);

    void on_pbLineNextPage_clicked();

    void on_pbLInePrevPage_clicked();

//    void on_cbAxisXNameFont_currentIndexChanged(int index);

//    void on_cbAxisXNameFontSize_currentIndexChanged(int index);

    void on_pbAxisXNameTextColor_clicked();

//    void on_cbAxisYNameFont_currentIndexChanged(int index);

//    void on_cbAxisYNameFontSize_currentIndexChanged(int index);

    void on_pbAxisYNameTextColor_clicked();

    void on_pbCalFunc_clicked();

    void on_pbShowAllLine_clicked();

    void on_pbHideAllLine_clicked();

    void on_pbCalFunc_2_clicked();

    void on_pbApply_3_clicked();

    void on_pbOk_3_clicked();

    void on_cbCurrentLine_Enum_currentIndexChanged(int index);

    //void on_pbEnumClear_clicked();

    void on_pbEnumAdd_clicked();

    void on_pbUpRate_clicked();

    void on_pbRulerColor_clicked();

    void on_pbAddIcon_clicked();

    void on_pbRemoveIcon_clicked();

    void on_pbSetManualIcon_clicked();

    void on_cbListManualIcon_currentIndexChanged(int index);

    void on_pbApply_4_clicked();

    void on_pbOk_4_clicked();

    void on_pbMerge_clicked();

    void on_pbAddTextFile_clicked();

    void on_pbShowAllLine_2_clicked();

    void on_pbHideAllLine_2_clicked();

    void on_pbCheckAllReserved_clicked();

    void on_pbUnCheckAllReserved_clicked();

    void on_pbCheckAllTimeLine_clicked();

    void on_pbUnCheckAllTimeLine_clicked();

    void on_cbLineFunc_currentIndexChanged(int index);

    void on_pbCheckAllTimeLine_2_clicked();

    void on_pbUnCheckAllTimeLine_2_clicked();

    void on_pbApply_5_clicked();

    void on_pbOk_5_clicked();

    void on_pbExport_clicked();

    void onTimer();
    void on_pbOpenDir_clicked();

    void on_pbFindMinMax_clicked();

    void on_pbManualColor_clicked();

public:
    kmWidgetChart* m_pWgChart;
private:
    void show30To40(bool show);
    void show40To50(bool show);
    void setupLinePages();
    void updateLineForComboBox();
    void updateReserverLine();
    Ui::dialogKMConfigChart *ui;
    kmChartHandler* m_pChartHandler;
    QTimer* 				m_pTimer;
    bool m_bStartExportImage;
    float lineWith1;
    float cr_red1;
    float cr_green1;
    float cr_blue1;
    bool m_bVisible1;

    float lineWith2;
    float cr_red2;
    float cr_green2;
    float cr_blue2;
    bool m_bVisible2;

    float lineWith3;
    float cr_red3;
    float cr_green3;
    float cr_blue3;
    bool m_bVisible3;

    float lineWith4;
    float cr_red4;
    float cr_green4;
    float cr_blue4;
    bool m_bVisible4;

    float lineWith5;
    float cr_red5;
    float cr_green5;
    float cr_blue5;
    bool m_bVisible5;

    float lineWith6;
    float cr_red6;
    float cr_green6;
    float cr_blue6;
    bool m_bVisible6;

    float lineWith7;
    float cr_red7;
    float cr_green7;
    float cr_blue7;
    bool m_bVisible7;

    float lineWith8;
    float cr_red8;
    float cr_green8;
    float cr_blue8;
    bool m_bVisible8;

    float lineWith9;
    float cr_red9;
    float cr_green9;
    float cr_blue9;
    bool m_bVisible9;

    float lineWith10;
    float cr_red10;
    float cr_green10;
    float cr_blue10;
    bool m_bVisible10;

    float lineWith11;
    float cr_red11;
    float cr_green11;
    float cr_blue11;
    bool m_bVisible11;

    float lineWith12;
    float cr_red12;
    float cr_green12;
    float cr_blue12;
    bool m_bVisible12;

    float lineWith13;
    float cr_red13;
    float cr_green13;
    float cr_blue13;
    bool m_bVisible13;

    float lineWith14;
    float cr_red14;
    float cr_green14;
    float cr_blue14;
    bool m_bVisible14;

    float lineWith15;
    float cr_red15;
    float cr_green15;
    float cr_blue15;
    bool m_bVisible15;

    float cr_exportR;
    float cr_exportG;
    float cr_exportB;
    std::vector<int>    m_listNewLines;
    std::map<int, int> m_mapCombobox_LineId;
    std::map<int, int> m_mapTree_ReservedLineId;
    std::map<int, int> m_mapTree_TimeLineId;
    std::vector<kmChartLine*>   m_listExportAlways;
    std::vector<kmChartLine*>   m_listExportLineByLine;
    int m_nExportIdx;
    //std::map<int, int> m_mapTree_ExportAlwaysId;
    std::map<int, int> m_mapTree_ExportId;
    //std::map<int, int> m_mapTree_ExportLineByLineId;

    kmSelectedItem m_eSelectedItem;
    float m_crPointFill[3];
    float m_crPointLine[3];
    float m_crPointText[3];

    void updateUIForIconSelected(kmIcon& icon);
    void updateDataForIconSelected(kmIcon& icon);

    int m_nNumOfLinePage;
    int m_nCurLinePage;
    std::vector<int>    m_listMuVar;
    bool firstInit;

    void updateTextInform(kmTextInform& text, QComboBox* cbName, QComboBox* cbSize);

    void setTextInform(kmTextInform& text, QComboBox* cbName, QComboBox* cbSize);

    bool m_bFirtChangeCombo;

    int m_nSizeTimeLine;
};

#endif // DIALOGCONFIGCHART_H
