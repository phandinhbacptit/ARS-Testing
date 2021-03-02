#ifndef USERCONFIG_H
#define USERCONFIG_H

#include <QString>
//#include"kmGraph/headers/kmWidgetChart.h"

/*_____________Define enable/disable debug______*/


#define OK      1
#define FAIL    0

/* Define path contain update information of combobox*/

#define nameExcutorPath "/inform/nameExecutor.csv"
#define idExcutorPath "/inform/idExecutor.csv"
#define workExcutorPath "/inform/workExecutor.csv"
#define nameSupervisorPath "/inform/nameSupervisor.csv"
#define idSupervisorPath "/inform/idSupervisor.csv"
#define workSupervisorPath "/inform/workSupervisor.csv"
#define localTestPath "/inform/localTest.csv"

/* Define path contain information of instrument*/
#define insEthernetPath "/instrument/instrumentEthernet.csv"
#define insUsartPath "/instrument/instrumentUsart.csv"

/* Electrical cable design document path*/

#define cable1 "GuidleFile/electricCable/Getting started.pdf"
#define cable2 "GuidleFile/electricCable/Cable2.pdf"
#define cable3 "GuidleFile/electricCable/Cable3.pdf"
#define cable4 "GuidleFile/electricCable/Cable4.pdf"
#define cable5 "GuidleFile/electricCable/Cable5.pdf"
#define cable6 "GuidleFile/electricCable/Cable6.pdf"
#define cable9 "GuidleFile/electricCable/Cable9.pdf"
#define cable10 "GuidleFile/electricCable/Cable10.pdf"
#define cable11 "GuidleFile/electricCable/Cable11-12.pdf"
#define cable12 "GuidleFile/electricCable/Cable11-12.pdf"
#define cable13 "GuidleFile/electricCable/Cable13.pdf"

/* RF cable design document path*/

#define cableRf1 "GuidleFile/RfCable/CableRF1.pdf"
#define cableRf2 "GuidleFile/RfCable/CableRF2.pdf"
#define cableRf3 "GuidleFile/RfCable/CableRF3.pdf"
#define cableRf4 "GuidleFile/RfCable/CableRF4.pdf"
#define cableRf5 "GuidleFile/RfCable/CableRF5.pdf"
#define cableRf6 "GuidleFile/RfCable/CableRF6.pdf"
#define cableRf7 "GuidleFile/RfCable/CableRF7.pdf"
#define cableRf8 "GuidleFile/RfCable/CableRF8.pdf"
#define cableRf9 "GuidleFile/RfCable/CableRF9.pdf"
#define cableRf10 "GuidleFile/RfCable/CableRF10.pdf"
#define cableRf11 "GuidleFile/RfCable/CableRF11.pdf"
#define cableRf12 "GuidleFile/RfCable/CableRF12.pdf"
#define cableRf13 "GuidleFile/RfCable/CableRF13.pdf"
#define cableRf14 "GuidleFile/RfCable/CableRF14.pdf"
#define cableRf15 "GuidleFile/RfCable/CableRF15.pdf"
#define cableRf16 "GuidleFile/RfCable/CableRF16.pdf"
#define cableRf17 "GuidleFile/RfCable/CableRF17.pdf"
#define cableRf18 "GuidleFile/RfCable/CableRF18.pdf"
#define cableRf19 "GuidleFile/RfCable/CableRF19.pdf"
#define cableRf20 "GuidleFile/RfCable/CableRF20.pdf"
#define cableRf21 "GuidleFile/RfCable/CableRF21.pdf"
#define cableRf22 "GuidleFile/RfCable/CableRF22.pdf"
#define cableRf23 "GuidleFile/RfCable/CableRF23.pdf"
#define cableRf24 "GuidleFile/RfCable/CableRF24.pdf"
#define cableRf25 "GuidleFile/RfCable/CableRF25.pdf"
#define cableRf26 "GuidleFile/RfCable/CableRF26.pdf"
#define cableRf27 "GuidleFile/RfCable/CableRF27.pdf"
#define cableRf28 "GuidleFile/RfCable/CableRF28.pdf"
#define cableRf29 "GuidleFile/RfCable/CableRF29.pdf"
#define cableRf30 "GuidleFile/RfCable/CableRF30.pdf"
#define cableRf31 "GuidleFile/RfCable/CableRF31.pdf"

/*________________Define path report file_________*/

#define path_Circulator_part1 "libKdReport/xml/Module/Circulator/Circulator_part1.csv"
#define path_Circulator_part2 "libKdReport/xml/Module/Circulator/Circulator_part2.csv"
#define path_Circulator_part3 "libKdReport/xml/Module/Circulator/Circulator_part3.csv"

#define path_Comparator_part1   "libKdReport/xml/Module/Comparator/Comparator_part1.csv"
#define path_Comparator_part2   "libKdReport/xml/Module/Comparator/Comparator_part2.csv"
#define path_Comparator_part3   "libKdReport/xml/Module/Comparator/Comparator_part3.csv"
#define path_Comparator_part4   "libKdReport/xml/Module/Comparator/Comparator_part4.csv"
#define path_Comparator_part5   "libKdReport/xml/Module/Comparator/Comparator_part5.csv"
#define path_Comparator_part6   "libKdReport/xml/Module/Comparator/Comparator_part6.csv"
#define path_Comparator_part7   "libKdReport/xml/Module/Comparator/Comparator_part7.csv"

#define path_SMA_part1 "libKdReport/xml/Module/Adapter_SMA/SMA_part1.csv"
#define path_SMA_part2 "libKdReport/xml/Module/Adapter_SMA/SMA_part2.csv"

#define path_att_xband_part1 "libKdReport/xml/Module/Att_Xband/attXband_part1.csv"
#define path_att_xband_part2 "libKdReport/xml/Module/Att_Xband/attXband_part2.csv"

#define path_antena "libKdReport/xml/Module/Antena/Antena.csv"
#define path_filterIF "libKdReport/xml/Module/FilterIF/FilterIF.csv"
#define path_filterXband "libKdReport/xml/Module/Filter_XBAND/filterXband.csv"

#define path_filter_LORF_part1  "libKdReport/xml/Module/Filter_LORF/FilterLORF_part1.csv"
#define path_filter_LORF_part2  "libKdReport/xml/Module/Filter_LORF/FilterLORF_part2.csv"

#define path_filter_LOIF_part1  "libKdReport/xml/Module/Filter_LOIF/FilterLOIF_part1.csv"
#define path_filter_LOIF_part2  "libKdReport/xml/Module/Filter_LOIF/FilterLOIF_part2.csv"

#define path_HPA_part1  "libKdReport/xml/Module/HPA/csvHPA_part1.csv"
#define path_HPA_part2  "libKdReport/xml/Module/HPA/csvHPA_part2.csv"
#define path_HPA_part3  "libKdReport/xml/Module/HPA/csvHPA_part3.csv"
#define path_HPA_part4  "libKdReport/xml/Module/HPA/csvHPA_part4.csv"
#define path_HPA_part5  "libKdReport/xml/Module/HPA/csvHPA_part5.csv"
#define path_HPA_part6  "libKdReport/xml/Module/HPA/csvHPA_part6.csv"

#define path_SwAntena_part1 "libKdReport/xml/Module/SwAntena/swAntena_part1.csv"
#define path_SwAntena_part2 "libKdReport/xml/Module/SwAntena/swAntena_part2.csv"
#define path_SwAntena_part3 "libKdReport/xml/Module/SwAntena/swAntena_part3.csv"

#define path_limiterDiff "libKdReport/xml/Module/LimiterDiff/Limiter_diff.csv"
#define path_limiterSum "libKdReport/xml/Module/LimiterSum/Limiter_sum.csv"

#define path_LNA_part1  "libKdReport/xml/Module/LNA/csvLNA_part1.csv"
#define path_LNA_part23  "libKdReport/xml/Module/LNA/csvLNA_part2.csv"

#define path_LO_part1   "libKdReport/xml/Module/LO/csvLO_part1.csv"
#define path_LO_part2   "libKdReport/xml/Module/LO/csvLO_part2.csv"
#define path_LO_part3   "libKdReport/xml/Module/LO/csvLO_part3.csv"
#define path_LO_part4   "libKdReport/xml/Module/LO/csvLO_part4.csv"

#define path_RX_part1  "libKdReport/xml/Module/RX/csvRX_part1.csv"
#define path_RX_part23  "libKdReport/xml/Module/RX/csvRX_part23.csv"
#define path_RX_part4  "libKdReport/xml/Module/RX/csvRX_part4.csv"

#define path_TX_part1   "libKdReport/xml/Module/TX/csvTX_part1.csv"
#define path_TX_part2   "libKdReport/xml/Module/TX/csvTX_part2.csv"
#define path_TX_part3   "libKdReport/xml/Module/TX/csvTX_part3.csv"
#define path_TX_part4   "libKdReport/xml/Module/TX/csvTX_part4.csv"
#define path_TX_part5   "libKdReport/xml/Module/TX/csvTX_part5.csv"
#define path_TX_part6   "libKdReport/xml/Module/TX/csvTX_part6.csv"



/*______________Define name folder logfile__________*/
const QString logFolderElectricalCable = "logs/logsElectricCable";
const QString logFolderRfCable = "logs/logsRfCable";
const QString logFolderModule = "logs/logsModule";
const QString logFolderMechanical = "logs/logsMechanical";

/* Define State connect equipment */
#define IDEAL           0
#define CONNECTED       1
#define DISCONNECTED    2

struct table
{
    QString namePart;

    QString  title1;
    QString  pathPart1;

    QString  title2;
    QString  pathPart2;

    QString  title3;
    QString  pathPart3;

    QString  title4;
    QString  pathPart4;

    QString  title5;
    QString  pathPart5;

    QString  title6;
    QString  pathPart6;

    QString  title7;
    QString  pathPart7;

    QString stringNote;
    bool    isNote;
};

#define maxLengthBuf 15
struct defineCsv
{
    QString pathCsv;
    int numColumn;
    int numRow;
    QString header[maxLengthBuf];
    QString row1[maxLengthBuf];
    QString row2[maxLengthBuf];
    QString row3[maxLengthBuf];
    QString row4[maxLengthBuf];
    QString row5[maxLengthBuf];
    QString row6[maxLengthBuf];
    QString row7[maxLengthBuf];
    QString row8[maxLengthBuf];
    QString row9[maxLengthBuf];
    QString row10[maxLengthBuf];
    QString row11[maxLengthBuf];
    QString row12[maxLengthBuf];
    QString row13[maxLengthBuf];
    QString row14[maxLengthBuf];
    QString row15[maxLengthBuf];
    QString row16[maxLengthBuf];
};

static table Cable2 {
    .namePart = "Cable2",
    .title1 = "Resistance",
    .pathPart1 =  ":/libKdReport/xml/ElectricCable/R_Cable2.csv",

    .title2 = "Insulation Resistance",
    .pathPart2 =  ":/libKdReport/xml/ElectricCable/IR_Cable2.csv",

    .title3 = nullptr,
    .pathPart3 = nullptr,
};

/*____________________Define module property___________________*/
static defineCsv csvCirculator_part1
{
    .pathCsv = path_Circulator_part1,
    .numColumn = 9,
    .numRow = 4,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"Cổng 1","","","","","","","VSWR ≤ 1.4", ""},
    {"Cổng 2","","","","","","","VSWR ≤ 1.4", ""},
    {"Cổng 3","","","","","","","VSWR ≤ 1.4", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvCirculator_part2
{
    .pathCsv = path_Circulator_part2,
    .numColumn = 9,
    .numRow = 4,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"S21","","","","","","","≤ 0.5dB", ""},
    {"S32","","","","","","","≤ 0.5dB", ""},
    {"S13","","","","","","","≤ 0.5dB", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvCirculator_part3
{
    .pathCsv = path_Circulator_part3,
    .numColumn = 9,
    .numRow = 4,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"S12","","","","","","","≥ 20dB", ""},
    {"S23","","","","","","","≥ 20dB", ""},
    {"S31","","","","","","","≥ 20dB", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},
};

static table Circulator {
    .namePart = "Circulator Module",
    .title1 = "1.1. Hệ số sóng đứng",
    .pathPart1 = path_Circulator_part1,

    .title2 = "1.2. Hệ số suy hao",
    .pathPart2 = path_Circulator_part2,

    .title3 = "1.3. Hệ số cách ly",
    .pathPart3 = path_Circulator_part3,
};
/****************************************************************************/
static defineCsv csvComparator_part1
{
    .pathCsv = path_Comparator_part1,
    .numColumn = 9,
    .numRow = 4,
    {"VSWR","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"Cổng tổng","","","","","","","≤ 1.5", ""},
    {"Cổng hiệu ngang","","","","","","","≤ 1.5", ""},
    {"Cổng hiệu đứng","","","","","","","≤ 1.5", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvComparator_part2
{
    .pathCsv = path_Comparator_part2,
    .numColumn = 9,
    .numRow = 5,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"S51","","","","","","","6 ± 1dB", ""},
    {"S52","","","","","","","6 ± 1dB", ""},
    {"S53","","","","","","","6 ± 1dB", ""},
    {"S54","","","","","","","6 ± 1dB", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvComparator_part3
{
    .pathCsv = path_Comparator_part3,
    .numColumn = 9,
    .numRow = 5,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"S61","","","","","","","6 ± 1dB", ""},
    {"S62","","","","","","","6 ± 1dB", ""},
    {"S63","","","","","","","6 ± 1dB", ""},
    {"S64","","","","","","","6 ± 1dB", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvComparator_part4
{
    .pathCsv = path_Comparator_part4,
    .numColumn = 9,
    .numRow = 5,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"S71","","","","","","","6 ± 1dB", ""},
    {"S72","","","","","","","6 ± 1dB", ""},
    {"S73","","","","","","","6 ± 1dB", ""},
    {"S74","","","","","","","6 ± 1dB", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvComparator_part5
{
    .pathCsv = path_Comparator_part5,
    .numColumn = 9,
    .numRow = 5,
    {"","9.3hZ  ","9.4hZ  ","9.5hZ  ","9.6hZ  ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"S51","","","","","","","|Φ51 – Φ52|= 0 ± 10 && |Φ51 – Φ53|=0±10 ", ""},
    {"S52","","","","","","","|Φ51 – Φ54|= 0 ± 10 && |Φ52 – Φ53|=0±10", ""},
    {"S53","","","","","","","|Φ52 – Φ54|= 0 ± 10", ""},
    {"S54","","","","","","","|Φ53 – Φ54|= 0 ± 10", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvComparator_part6
{
    .pathCsv = path_Comparator_part6,
    .numColumn = 9,
    .numRow = 5,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"S61","","","","","","","|Φ61 – Φ62|= 180 ± 10", ""},
    {"S62","","","","","","","|Φ61 – Φ63|= 180 ± 10", ""},
    {"S63","","","","","","","|Φ61 – Φ64|= 0 ± 10", ""},
    {"S64","","","","","","","|Φ62 – Φ63|= 0 ± 10", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvComparator_part7
{
    .pathCsv = path_Comparator_part7,
    .numColumn = 9,
    .numRow = 5,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"S71","","","","","","","|Φ71 – Φ72|= 0 ± 10", ""},
    {"S72","","","","","","","|Φ73 – Φ74|= 0 ± 10", ""},
    {"S73","","","","","","","|Φ71 – Φ73|= 180 ± 10", ""},
    {"S74","","","","","","","|Φ71 – Φ74|= 180 ± 10", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},
};
static table Comparator {
    .namePart = "Comparator Module",
    .title1 = "1.1. Hệ số sóng đứng",
    .pathPart1 = path_Comparator_part1,

    .title2 = "1.2.Mức chia - Cổng tổng (Cổng 5)",
    .pathPart2 = path_Comparator_part2,

    .title3 = "1.3. Mức chia - Cổng hiệu ngang (Cổng 6)",
    .pathPart3 = path_Comparator_part3,

    .title4 = "1.4. Mức chia - Cổng hiệu đứng (Cổng 7)",
    .pathPart4 = path_Comparator_part4,

    .title5 = "1.5. Hệ số pha - Cổng tổng (Cổng 5)",
    .pathPart5 = path_Comparator_part5,

    .title6 = "1.6. Hệ số pha - Cổng hiệu ngang (Cổng 6)",
    .pathPart6 = path_Comparator_part6,

    .title7 = "1.7. Hệ số pha - Cổng hiệu đứng (Cổng 7)",
    .pathPart7 = path_Comparator_part7,
};
/****************************************************************************/
static defineCsv csvSMA_part1
{
    .pathCsv = path_SMA_part1,
    .numColumn = 9,
    .numRow = 7,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"Tx","","","","","","","VSWR ≤ 1.2", ""},
    {"∑Rx+","","","","","","","VSWR ≤ 1.2", ""},
    {"ΔAzi","","","","","","","VSWR ≤ 1.2", ""},
    {"ΔElv","","","","","","","VSWR ≤ 1.2", ""},
    {"ATT1","","","","","","","VSWR ≤ 1.2", ""},
    {"ATT2","","","","","","","VSWR ≤ 1.2", ""},
    {},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvSMA_part2
{
    .pathCsv = path_SMA_part2,
    .numColumn = 9,
    .numRow = 7,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"Tx","","","","","","","≤ 0.5dB", ""},
    {"∑Rx+","","","","","","","≤ 0.5dB", ""},
    {"ΔAzi","","","","","","","≤ 0.5dB", ""},
    {"ΔElv","","","","","","","≤ 0.5dB", ""},
    {"ATT1","","","","","","","≤ 0.5dB", ""},
    {"ATT2","","","","","","","≤ 0.5dB", ""},
    {},{},{},{},{},{},{},{},{},{},
};
static table Adapter_SMA {
    .namePart = "Adapter SMA Module",
    .title1 = "1.1. Hệ số sóng đứng",
    .pathPart1 = path_SMA_part1,

    .title2 = "1.2. Hệ số suy hao",
    .pathPart2 = path_SMA_part2,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
static defineCsv csvAttXband_part1
{
    .pathCsv = path_att_xband_part1,
    .numColumn = 9,
    .numRow = 2,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"ATT Tổng","","","","","","","≤ 1.5dB", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvAttXband_part2
{
    .pathCsv = path_att_xband_part2,
    .numColumn = 5,
    .numRow = 4,
    {"Suy hao diode từng tầng","Điện áp (V)","Suy hao","Tiêu chuẩn","Đánh giá"},
    {"D1","","","≤ 10 ± 1dB", ""},
    {"D2","","","≤ 20 ± 1dB", ""},
    {"D3","","","≤ 20 ± 1dB", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},
};
static table AttXband {
    .namePart = "ATT Xband Module",
    .title1 = "1.1. Suy hao chưa điều khiển",
    .pathPart1 = path_att_xband_part1,

    .title2 = "1.2. Suy hao với mức điện áp điều khiển tần số 9.4Ghz",
    .pathPart2 = path_att_xband_part2,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
static defineCsv csvAntena
{
    .pathCsv = path_antena,
    .numColumn = 9,
    .numRow = 5,
    {"WSWR","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"Cổng 1","","","","","","","VSWR ≤ 1.5", ""},
    {"Cổng 2","","","","","","","VSWR ≤ 1.5", ""},
    {"Cổng 3","","","","","","","VSWR ≤ 1.5", ""},
    {"Cổng 4","","","","","","","VSWR ≤ 1.5", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},
};
static table Antena {
    .namePart = "Antena Module",
    .title1 = "Kết quả đo VSWR",
    .pathPart1 = path_antena,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
static defineCsv csvFilterIF
{
    .pathCsv = path_filterIF,
    .numColumn = 6,
    .numRow = 4,
    {"STT","Suy hao 70Mhz (Marker1 ≤ 6dB)","Marker1 (Mhz)","Marker2 (Mhz)","Dai thong 3dB (≤ 5Mhz)","Đánh giá"},
    {"1","","","","",},
    {"STT","Suy hao 70Mhz (Marker1 ≤ 6dB)","Marker1 (Mhz)","Marker2 (Mhz)","Dai thong 3dB (≤ 3.5Mhz)","Đánh giá"},
    {"1","","","","",},
    {},{},{},{},{},{},{},{},{},{},{},{},{},
};
static table FilterIF {
    .namePart = "FilterIF Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_filterIF,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
static defineCsv csvFilter_LOIF_part1
{
    .pathCsv = path_filter_LOIF_part1,
    .numColumn = 7,
    .numRow = 2,
    {"Điểm marker","Marker 1 tại 1220MHz (≤-35dB)",
        "Marker 2 tại 1420MHz (≤-35dB)",
        "Marker 3 tại 1120MHz (≤-55dB)",
        "Marker 4 tại 1520MHz (≤-55dB)",
        "Đánh giá"},
    {"Giá trị","","","","", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvFilter_LOIF_part2
{
    .pathCsv = path_filter_LOIF_part2,
    .numColumn = 4,
    .numRow = 2,
    {"Điểm marker","Marker 5 tại 1300MHz (≥-2dB)","Marker 6 tại 1340MHz (≥-2dB)","Đánh giá"},
    {"Giá trị","","",""},
    {},{},{},{},{},{},
};
static table Filter_LOIF {
    .namePart = "FilterLOIF Module",
    .title1 = "1.1 Kết quả đo kiểm suy hao dải chắn",
    .pathPart1 = path_filter_LOIF_part1,

    .title2 = "1.2 Kết quả đo kiểm suy hao dải thông",
    .pathPart2 = path_filter_LOIF_part2,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
static defineCsv csvFilter_LORF_part1
{
    .pathCsv = path_filter_LORF_part1,
    .numColumn = 7,
    .numRow = 2,
    {"Điểm marker","Marker 2 tại 7810MHz (≤-2.5dB)",
        "Marker 3 tại 7910MHz (≤-2.5dB)",
        "Marker 4 tại 8010MHz (≤-2.5dB)",
        "Marker 5 tại 8110MHz (≤-2.5dB)",
        "Marker 6 tại 8210MHz (≤-2.5dB)",
        "Đánh giá"},
    {"Giá trị","","","","", "", ""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvFilter_LORF_part2
{
    .pathCsv = path_filter_LORF_part2,
    .numColumn = 4,
    .numRow = 2,
    {"Điểm marker","Marker 1 tại 7510MHz (≤-55dB)","Marker 7 tại 8510MHz (≤-55dB)","Đánh giá"},
    {"Giá trị","","",""},
    {},{},{},{},{},{},
};
static table Filter_LORF {
    .namePart = "FilterLORF Module",
    .title1 = "1.1 Kết quả đo kiểm suy hao dải thông 1",
    .pathPart1 = path_filter_LORF_part1,

    .title2 = "1.2 Kết quả đo kiểm suy hao dải thông 2",
    .pathPart2 = path_filter_LORF_part2,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
static defineCsv csvFilterXband
{
    .pathCsv = path_filterXband,
    .numColumn = 5,
    .numRow = 4,
    {"STT","Tham số","Chỉ tiêu kĩ thuật","Kết quả đo","Đánh giá"},
    {"1","Tần số lọc","9200-9600 Mhz","",""},
    {"2","Suy hao","≤ 0.8dB","",""},
    {"3","Hệ số sóng đứng","≤ 1.25","",""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},
};
static table FilterXband {
    .namePart = "FilterXband Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_filterXband,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
static defineCsv csvHPA_part1
{
    .pathCsv = path_HPA_part1,
    .numColumn = 7,
    .numRow = 17,
    {"STT","Pin (dBm)","Pout đỉnh (dBm)","Pout trung bình (dBm)","Độ sụt đỉnh xung (dB)","Chỉ tiêu","Đánh giá"},
    {"1","-10",},
    {"2","-9",},
    {"3","-8",},
    {"4","-7",},
    {"5","-6",},
    {"6","-5",},
    {"7","-4",},
    {"8","-3",},
    {"9","-2",},
    {"10","-1",},
    {"11","0",},
    {"12","1",},
    {"13","2",},
    {"14","3",},
    {"15","4",},
    {"16","5"},
};
static defineCsv csvHPA_part2
{
    .pathCsv = path_HPA_part2,
    .numColumn = 9,
    .numRow = 2,
    {"Tần số","9.2 GHz","9.2 GHz","9.3 GHz","9.4 GHz","9.5 GHz","9.6 GHz","Chỉ tiêu","Đánh giá"},
    {"Mức hài",},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},{}
};

static defineCsv csvHPA_part3
{
    .pathCsv = path_HPA_part3,
    .numColumn = 9,
    .numRow = 17,
    {"STT","Pin (dBm)",
        "Pout tại 9.2Ghz (dBm)",
        "Pout tại 9.3Ghz (dBm)",
        "Pout tại 9.4Ghz (dBm)",
        "Pout tại 9.5Ghz (dBm)",
        "Pout tại 9.6Ghz (dBm)",
        "Chỉ tiêu",
        "Đánh giá"},
    {"1","-10",},
    {"2","-9",},
    {"3","-8",},
    {"4","-7",},
    {"5","-6",},
    {"6","-5",},
    {"7","-4",},
    {"8","-3",},
    {"9","-2",},
    {"10","-1",},
    {"11","0",},
    {"12","1",},
    {"13","2",},
    {"14","3",},
    {"15","4",},
    {"16","5"},
};
static defineCsv csvHPA_part4
{
    .pathCsv = path_HPA_part4,
    .numColumn = 6,
    .numRow = 11,
    {"STT","Độ rộng xung (us)",
        "Chu kỳ lặp xung (us)",
        "Công suất đầu ra (dBm)",
        "Chỉ tiêu",
        "Đánh giá"},
    {"1","0.5","100",},
    {"2","1","100",},
    {"3","3","100",},
    {"4","5","100",},
    {"5","7","100",},
    {"6","9","100",},
    {"7","11","100",},
    {"8","13","100",},
    {"9","20","200",},
    {"10","64","650",},
    {},{},{},{},{},{}
};

static defineCsv csvHPA_part5
{
    .pathCsv = path_HPA_part5,
    .numColumn = 7,
    .numRow = 6,
    {"STT","Điện áp (V)",
        "Công suất đầu ra (dBm)",
        "Dòng ăn (A)",
        "Công suất tiêu thụ (W)",
        "Chỉ tiêu",
        "Đánh giá"},
    {"1","39",},
    {"2","39.5",},
    {"3","40",},
    {"4","40.5",},
    {"5","41",},
    {},{},{},{},{},{},{},{},{},{},{}
};

static defineCsv csvHPA_part6
{
    .pathCsv = path_HPA_part6,
    .numColumn = 9,
    .numRow = 2,
    {"Tần số","9.2 GHz","9.2 GHz","9.3 GHz","9.4 GHz","9.5 GHz","9.6 GHz","Chỉ tiêu","Đánh giá"},
    {"H/số trích công suất (dB)",},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},{}
};

static table Hpa {
    .namePart = "KDCS Module",
    .title1 = "1.Kết quả đo kiểm đặc tuyến Pout/Pin, điểm P1DB, Gain, Độ sụt đỉnh xung, Dải tuyến tính",
    .pathPart1 = path_HPA_part1,

    .title2 = "2. Kết quả đo kiểm mức hài module KDCS",
    .pathPart2 = path_HPA_part2,

    .title3 = "3. Kết quả đo dải tần hoạt động module KDCS",
    .pathPart3 = path_HPA_part3,

    .title4 = "4. Kết quả đo độ rộng xung cao tần module KDCS",
    .pathPart4 = path_HPA_part4,

    .title5 = "5. Kết quả đo nguồn cấp và công suất tiêu thụ",
    .pathPart5 = path_HPA_part5,

    .title6 = "6. Kết quả đo kiểm giá trị hệ số trích công suất",
    .pathPart6 = path_HPA_part6,



};
/****************************************************************************/
static defineCsv csvSwAntena_part1
{
    .pathCsv = path_SwAntena_part1,
    .numColumn = 9,
    .numRow = 3,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"Cổng 1","","","","","","","≤ 2dB",""},
    {"Cổng 2","","","","","","","≤ 2dB",""},
    {},{}, {},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvSwAntena_part2
{
    .pathCsv = path_SwAntena_part2,
    .numColumn = 9,
    .numRow = 3,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"Cổng 1","","","","","","","≥ 60dB",""},
    {"Cổng 2","","","","","","","≥ 60dB",""},
    {},{}, {},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvSwAntena_part3
{
    .pathCsv = path_SwAntena_part3,
    .numColumn = 5,
    .numRow = 2,
    {"","Sườn lên","Sườn xuống","Tiêu chuẩn","Đánh giá"},
    {"Tốc độ đáp ứng","","","≤ 1µs",""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},{},
};

static table SwAntena {
    .namePart = "SwAntena Module",
    .title1 = "1.1. Hệ số suy hao",
    .pathPart1 = path_SwAntena_part1,

    .title2 = "1.2 Hệ số cách ly",
    .pathPart2 = path_SwAntena_part2,

    .title3 = "1.3. Tốc độ đáp ứng",
    .pathPart3 = path_SwAntena_part3,
};
/****************************************************************************/
static defineCsv csvLimiterDiff
{
    .pathCsv = path_limiterDiff,
    .numColumn = 8,
    .numRow = 6,
    {"STT","Tần số (Mhz)","Suy hao cáp RF1 (dB)","Suy hao cáp RF2 (dB)","Suy hao (≥1dB)","Max Power output (≤10dBm)","Max Power input (≤30dBm)","Đánh giá"},
    {"1","9200"},
    {"2","9300"},
    {"3","9400"},
    {"4","9500"},
    {"5","9600"},
    {},{},{},{},{},{},{},{},{},{},{},
};
static table LimiterDiff {
    .namePart = "LimiterDiff Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_limiterDiff,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
static defineCsv csvLimiterSum
{
    .pathCsv = path_limiterSum,
    .numColumn = 8,
    .numRow = 6,
    {"STT","Tần số (Mhz)","Suy hao cáp RF1 (dB)","Suy hao cáp RF2 (dB)","Suy hao (≥1dB)","Max Power output (≤15dBm)","Max Power input (≤34dBm)","Đánh giá"},
    {"1","9200"},
    {"2","9300"},
    {"3","9400"},
    {"4","9500"},
    {"5","9600"},
    {},{},{},{},{},{},{},{},{},{},{},
};
static table LimiterSum {
    .namePart = "LimiterSum Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_limiterSum,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
static defineCsv csvLNA_part1
{
    .pathCsv = path_LNA_part1,
    .numColumn = 8,
    .numRow = 3,
    {"Cable/Tần số","9.2(Ghz)","9.3(Ghz)","9.4(Ghz)","9.5(Ghz)","9.6(Ghz)","Chỉ tiêu","Đánh giá"},
    {"RF1"},
    {"RF2"},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvLNA_part23
{
    .pathCsv = path_LNA_part23,
    .numColumn = 9,
    .numRow = 5,
    {"STT","Tham số / Tần số","9.2(Ghz)","9.3(Ghz)","9.4(Ghz)","9.5(Ghz)","9.6(Ghz)","Chỉ tiêu","Đánh giá"},
    {"1","Hệ số khuếch đại","","","","","","≥30dB",""},
    {"2","Hệ số nhiễu tạp âm","","","","","","≤1.5dB",""},
    {"3","Công suất tối đa đầu ra","","","","","","≥10dBm",""},
    {"4","Công suất tối đa đầu vào","","","","","","≤10dBm",""},
    {},{},{},{},{},{},{},{},{},{},{},{},
};

static table LNA {
    .namePart = "LNA Module",
    .title1 = "1.1 Kết quả đo kiểm suy hao cáp",
    .pathPart1 = path_LNA_part1,

    .title2 = "1.2 Kết quả đo kiểm LNA kênh tổng",
    .pathPart2 = path_LNA_part23,

    .title3 = "1.3 Kết quả đo kiểm LNA kênh hiệu",
    .pathPart3 = path_LNA_part23,
};
/****************************************************************************/
static defineCsv csvLO_part1
{
    .pathCsv = path_LO_part1,
    .numColumn = 9,
    .numRow = 8,
    {"STT","Công suất đầu ra/Tần số (Mhz)","7810","7910","8010","8110","8210","Chỉ tiêu","Đánh giá"},
    {"1","Giá trị đo được RF+","","","","","","-",""},
    {"2","Giá trị đo được RF","","","","","","-",""},
    {"3","Giá trị đo được RF-","","","","","","-",""},
    {"4", "Suy hao cáp","","","","","","-",""},
    {"5", "Giá trị sau bù suy hao RF+","","","","","","≥ 0dBm",""},
    {"6", "Giá trị sau bù suy hao RF","","","","","","≥ 4dBm",""},
    {"7", "Giá trị sau bù suy hao RF-","","","","","","≥ 0dBm",""},
};

static defineCsv csvLO_part2
{
    .pathCsv = path_LO_part2,
    .numColumn = 9,
    .numRow = 3,
    {"STT","Tham số/Tần số (Mhz)","7810","7910","8010","8110","8210","Chỉ tiêu","Đánh giá"},
    {"1","Mức hài","","","","","","≤ -45dBc",""},
    {"2","Phase noise @100kHz offset","","","","","","≤ -75dBc/Hz",""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvLO_part3
{
    .pathCsv = path_LO_part3,
    .numColumn = 5,
    .numRow = 8,
    {"STT","Công suất đầu ra/Tần số","1320 Mhz","Chỉ tiêu","Đánh giá"},
    {"1","G/trị đo được RF+","","≥0 dBm",""},
    {"2","G/trị đo được RF","","≥0 dBm",""},
    {"3","G/trị đo được RF-","","≥0 dBm",""},
    {"4", "Suy hao cáp","","≥0 dBm",""},
    {"5", "Giá trị sau bù suy hao RF+","","≥0 dBm",""},
    {"6", "Giá trị sau bù suy hao RF","","≥0 dBm",""},
    {"7", "Giá trị sau bù suy hao RF-","","","≥0 dBm",""},
};

static defineCsv csvLO_part4
{
    .pathCsv = path_LO_part4,
    .numColumn = 5,
    .numRow = 3,
    {"STT","Tham số/Tần số","1320 Mhz","Chỉ tiêu","Đánh giá"},
    {"1","Mức hài","","≤ -45dBc",""},
    {"2","Phase noise @100kHz offset","","≤ -75dBc/Hz",""},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},
};
static table LO {
    .namePart = "LO Module",
    .title1 = "1. Kết quả kiểm tra bộ dao động ngoại sao cao tần \n 1.1. Kết quả công suất đầu ra",
    .pathPart1 = path_LO_part1,

    .title2 = "1.2. Kêt quả đo kiểm Mức hài và Phase noise",
    .pathPart2 = path_LO_part2,

    .title3 = "2. Kết quả kiểm tra bộ dao động ngoại sao trung tần \n 2.1. Kết quả công suất đầu ra",
    .pathPart3 = path_LO_part3,

    .title4 = "2.2. Kêt quả đo kiểm Mức hài và Phase noise",
    .pathPart4 = path_LO_part4,
};
/****************************************************************************/
static defineCsv csvTX_part1
{
    .pathCsv = path_TX_part1,
    .numColumn = 9,
    .numRow = 3,
    {"STT","Cable/Tần số","9.2(Ghz)","9.3(Ghz)","9.4(Ghz)","9.5(Ghz)","9.6(Ghz)","Chỉ tiêu","Đánh giá"},
    {"1","RF1"},
    {"2","RF2"},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvTX_part2
{
    .pathCsv = path_TX_part2,
    .numColumn = 5,
    .numRow = 3,
    {"STT","Cable/Tần số","70 Mhz","Chỉ tiêu","Đánh giá"},
    {"1","IF1"},
    {"2","IF2"},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvTX_part3
{
    .pathCsv = path_TX_part3,
    .numColumn = 5,
    .numRow = 2,
    {"STT","Cable/Tần số","1320 Mhz","Chỉ tiêu","Đánh giá"},
    {"1","LO1"},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvTX_part4
{
    .pathCsv = path_TX_part4,
    .numColumn = 9,
    .numRow = 2,
    {"STT","Cable/Tần số (Mhz)","7810","7910","8010","8110","8210","Chỉ tiêu","Đánh giá"},
    {"1","LO2"},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvTX_part5
{
    .pathCsv = path_TX_part5,
    .numColumn = 9,
    .numRow = 3,
    {"STT","Tham số/Tần số","9.2Ghz","9.3Ghz","9.4Ghz","9.5Ghz","9.6Ghz","Chỉ tiêu","Đánh giá"},
    {"1","Công suất tín hiệu ra (dBm)"},
    {"2", "Mức hài (dBc)"},
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvTX_part6
{
    .pathCsv = path_TX_part6,
    .numColumn = 14,
    .numRow = 7,
    {"STT",
        "Tín hiệu",
        "Xung đơn",
        "Mã Barker3",
        "Mã Barker7",
        "Mã Barker13",
        "Mã M63",
        "Xung 0.5us",
        "Xung 5us",
        "Xung 10us",
        "Xung 20us",
        "Xung 40us",
        "Xung 64us",
        "Đánh giá"},
    {"","Tần số/ Chu kì lặp","100us","100us","100us","100us","430us","100us","100us","100us","200us","300us","450us", "-"},
    {"1","9200 Mhz"},
    {"2","9300 Mhz"},
    {"3","9400 Mhz"},
    {"4","9500 Mhz"},
    {"5","9600 Mhz"},
    {},{},{},{},{},{},{},{},{},{},
};

static table TX {
    .namePart = "TX Module",
    .title1 = "1.Kết quả đo kiểm suy hao cáp \n 1.1. Cáp RF",
    .pathPart1 = path_TX_part1,

    .title2 = "1.2. Cáp IF",
    .pathPart2 = path_TX_part2,

    .title3 = "1.3 Cáp LO1",
    .pathPart3 = path_TX_part3,

    .title4 = "1.4 Cáp LO2",
    .pathPart4 = path_TX_part4,

    .title5 = "2. Kết quả đo kiểm các chỉ tiêu module TX \n 2.1. Công suất đầu ra, mức hài",
    .pathPart5 = path_TX_part5,

    .title6 = "2.2. Độ rộng xung, mã tín hiệu",
    .pathPart6 = path_TX_part6,
};
/****************************************************************************/
static defineCsv csvRX_part1
{
    .pathCsv = path_RX_part1,
    .numColumn = 9,
    .numRow = 5,
    {"STT","Cable/Tần số","9.2(Ghz)","9.3(Ghz)","9.4(Ghz)","9.5(Ghz)","9.6(Ghz)","Chỉ tiêu","Đánh giá"},
    {"1","RF"},
    {"2","LO1"},
    {"3","LO2"},
    {"4","IF1+IF2"},
    {},{},{},{},{},{},{},{},{},{},{},{},
};

static defineCsv csvRX_part23
{
    .pathCsv = path_RX_part23,
    .numColumn = 9,
    .numRow = 7,
    {"STT","Tham số/Tần số","9.2(Ghz)","9.3(Ghz)","9.4(Ghz)","9.5(Ghz)","9.6(Ghz)","Chỉ tiêu","Đánh giá"},
    {"1","Nền nhiễu", "","","","","","≤ -43dBm",""},
    {"2","Công suất thu được", "","","","","","-",""},
    {"3","Hệ số khuếch đại", "","","","","","≥ 35±1dB",""},
    {"4","Công suất tối đa đầu ra", "","","","","","≤16dBm",""},
    {"5","Hệ số tạp", "","","","","","≤20dBm",""},
    {"6", "Công suất tối đa đầu vào", "","","","","","≤5dBm",""},
    {},{},{},{},{},{},{},{},{},{},
};
static defineCsv csvRX_part4
{
    .pathCsv = path_RX_part4,
    .numColumn = 7,
    .numRow = 16,
    {"STT",
        "Tần số (Mhz)",
        "C/suất trước đk suy hao (dB)",
        "Mức suy hao (dB)",
        "K/quả sau đk suy hao (dB)",
        "Sai số điều khiển suy hao (≤ 0.5dB)",
        "Đánh giá"},
    {"1","9200","","10","","",""},
    {"2","9200","","20","","",""},
    {"3","9200","","30","","",""},
    {"4","9300","","10","","",""},
    {"5","9300","","20","","",""},
    {"6","9300","","30","","",""},
    {"7","9400","","10","","",""},
    {"8","9400","","20","","",""},
    {"9","9400","","30","","",""},
    {"10","9500","","10","","",""},
    {"11","9500","","20","","",""},
    {"12","9500","","30","","",""},
    {"13","9600","","10","","",""},
    {"14","9600","","20","","",""},
    {"15","9600","","30","","",""},
};

static table RX {
    .namePart = "RX Module",
    .title1 = "1.1. Kết quả đo kiểm suy hao cáp cao tần",
    .pathPart1 = path_RX_part1,

    .title2 = "1.2. Kết quả đo các tham số của kênh tổng",
    .pathPart2 = path_RX_part23,

    .title3 = "1.3. Kết quả đo các tham số của kênh hiệu",
    .pathPart3 = path_RX_part23,

    .title4 = "1.4. Kết quả điều khiển suy hao IF",
    .pathPart4 = path_RX_part4,
};
#endif // USERCONFIG_H
