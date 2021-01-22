#ifndef KM_CONFIGFILE_H
#define KM_CONFIGFILE_H
#include <string>
#include <vector>
#include <map>
using namespace std;
struct kmFileLineInfor
{
    string lineName;
    int mapIndex;
    int reserverdIndex;
    bool isReserved;
    bool isVisible;
    bool isActive;
    float color[3];
    float lineWidth;
    int lineStyle;
    int lineType;
    float scale;
    float offset;
    float scaleY;
    float offsetY;

    bool isEnum;
    std::map<int, string> m_mapEnum;
};
class kmChartHandler;
class kmConfigFile
{
public:
    kmConfigFile();

    kmChartHandler* m_pChartHandler;
    int m_nNumOfLine;
    int m_nVersion;
    std::vector<kmFileLineInfor>  m_listLineList;
    void setWidgetChart(kmChartHandler* pWidget) { m_pChartHandler = pWidget; }
    void setNumOfLine(int numOfLine) {m_nNumOfLine = numOfLine; }
    void addLineInfor(string name, int mapIndex, int reservedIndex, bool isReserved, bool isVisible, bool isActive, float* color);
    void addLineInfor(kmFileLineInfor& infor);
    void saveData(std::ofstream& file);
    void loadData(std::ifstream& file);
};

#endif // KM_CONFIGFILE_H
