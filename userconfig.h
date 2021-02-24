#ifndef USERCONFIG_H
#define USERCONFIG_H

#include <QString>
//#include"kmGraph/headers/kmWidgetChart.h"

/*_____________Define enable/disable debug______*/


#define OK      1
#define FAIL    0

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

#define path_SMA_part1 "libKdReport/xml/Module/Adapter_SMA/SMA_part1.csv"
#define path_SMA_part2 "libKdReport/xml/Module/Adapter_SMA/SMA_part2.csv"

#define path_att_xband_part1 "libKdReport/xml/Module/Att_Xband/attXband_part1.csv"
#define path_att_xband_part2 "libKdReport/xml/Module/Att_Xband/attXband_part2.csv"

#define path_antena "libKdReport/xml/Module/Antena/Antena.csv"
#define path_filterIF "libKdReport/xml/Module/FilterIF/FilterIF.csv"
#define path_filterXband "libKdReport/xml/Module/Filter_XBAND/filterXband.csv"
#define path_filter_LORF  "libKdReport/xml/Module/Filter_LORF/FilterLORF.csv"
#define path_filter_LOIF  "libKdReport/xml/Module/Filter_LORF/FilterLOIF.csv"

#define path_SwAntena_part1 "libKdReport/xml/Module/SwAntena/swAntena_part1.csv"
#define path_SwAntena_part2 "libKdReport/xml/Module/SwAntena/swAntena_part2.csv"
#define path_SwAntena_part3 "libKdReport/xml/Module/SwAntena/swAntena_part3.csv"

#define path_limiterDiff "libKdReport/xml/Module/LimiterDiff/Limiter_diff.csv"
#define path_limiterSum "libKdReport/xml/Module/LimiterSum/Limiter_sum.csv"

#define path_test "/libKdReport/xml/Module/Circulator/Circulator_part1.csv"

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
    QString  namePart;

    QString  title1;
    QString  pathPart1;

    QString  title2;
    QString  pathPart2;

    QString  title3;
    QString  pathPart3;
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
    {},{},{},{},
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
    {},{},{},{},
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
    {},{},{},{},
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
static table Comparator {
    .namePart = "Comparator Module",
    .title1 = "1.1. Hệ số sóng đứng",
    .pathPart1 = path_Circulator_part1,

    .title2 = "1.2. Hệ số suy hao",
    .pathPart2 = path_Circulator_part2,

    .title3 = "1.3. Hệ số cách ly",
    .pathPart3 = path_Circulator_part3,
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
    {},
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
    {},
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
    {},{},{},{},{},{},
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
    {},{},{},{},
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
    {},{},{},
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
    {},{},{},{},
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
/*______________________________________________*/
static table Filter_LOIF {
    .namePart = "FilterLOIF Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_filter_LOIF,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
/*______________________________________________*/
static table Filter_LORF {
    .namePart = "FilterLORF Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_filter_LORF,

    .title2 = nullptr,
    .pathPart2 = nullptr,

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
    {},{},{},{},
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

static table Hpa {
    .namePart = "KDCS Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_filterXband,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
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
    {},{}, {},{},{},
};

static defineCsv csvSwAntena_part2
{
    .pathCsv = path_SwAntena_part2,
    .numColumn = 9,
    .numRow = 3,
    {"","9.3hZ","9.4hZ","9.5hZ","9.6hZ","Min","Max","Tiêu chuẩn","Đánh giá"},
    {"Cổng 1","","","","","","","≥ 60dB",""},
    {"Cổng 2","","","","","","","≥ 60dB",""},
    {},{}, {},{},{},
};

static defineCsv csvSwAntena_part3
{
    .pathCsv = path_SwAntena_part3,
    .numColumn = 5,
    .numRow = 2,
    {"","Sườn lên","Sườn xuống","Tiêu chuẩn","Đánh giá"},
    {"Tốc độ đáp ứng","","","≤ 1µs",""},
    {},{},{},{},{},{},
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
    {},{},
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
    {},{},
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
/*______________________________________________*/
static table LNA {
    .namePart = "LNA Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_limiterSum,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
/*______________________________________________*/
static table LO {
    .namePart = "LO Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_limiterSum,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
/*______________________________________________*/
static table TX {
    .namePart = "TX Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_limiterSum,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
/****************************************************************************/
/*______________________________________________*/
static table RX {
    .namePart = "RX Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_limiterSum,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
};
#endif // USERCONFIG_H
