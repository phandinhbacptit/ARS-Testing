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
static table Circulator {
    .namePart = "Circulator Module",
    .title1 = "1.1. Hệ số sóng đứng",
    .pathPart1 = path_Circulator_part1,

    .title2 = "1.2. Hệ số suy hao",
    .pathPart2 = path_Circulator_part2,

    .title3 = "1.3. Hệ số cách ly",
    .pathPart3 = path_Circulator_part3,
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

static table AttXband {
    .namePart = "Adapter ATT Xband Module",
    .title1 = "1.1. Suy hao chưa điều khiển",
    .pathPart1 = path_att_xband_part1,

    .title2 = "1.2. Suy hao với mức điện áp điều khiển tần số 9.4Ghz",
    .pathPart2 = path_att_xband_part2,

    .title3 = nullptr,
    .pathPart3 = nullptr,
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

static table FilterIF {
    .namePart = "FilterIF Module",
    .title1 = "Kết quả đo kiểm",
    .pathPart1 = path_filterIF,

    .title2 = nullptr,
    .pathPart2 = nullptr,

    .title3 = nullptr,
    .pathPart3 = nullptr,
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
#endif // USERCONFIG_H
