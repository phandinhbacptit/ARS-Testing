#ifndef KMkmChartData_H
#define KMkmChartData_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "kminclude.h"
#include "muParser.h"
using namespace mu;
using namespace std;

/*
 * kmPoint which is point set for line data and time data
*/
struct kmPoint
{
    //x, y: Value, which is raw value
    float x;
    float y;
    float time;
    bool isDrawed;
    bool isVisible;

    float xRef;
    float yRef;

    float xGl;
    float yGl;
    float distance;

    float scale;
    float offset;

    string lineName;
    int lineID;
    int elementIdx;

    bool m_bIsEnum;
    string m_strEnumValue;

    void setX(double val) {x = val;}
    void setY(double val) {y = val;}
};

/*
 * kmGLPoint is: -1 ->1
*/
struct kmGLPoint
{
    float x;
    float y;
    void setX(float val) {x = val;}
    void setY(float val) {y = val;}
};

/*
 * kmPixelPoint: integer
*/
struct kmPixelPoint
{
    int x;
    int y;
    void setX(int val) {x = val;}
    void setY(int val) {y = val;}
};

enum kmWidgetStyle {
    kmStyle_black,
    kmStyle_white
};

enum kmDataType
{
    kmData_int,
    kmData_float,
    kmData_double,
    kmData_bool,
    kmData_long
};

enum kmLineStyle
{
    kmStyle_solid,
    kmStyle_Dot1,
    kmStyle_Dot2,
    kmStyle_Dot3,
    kmStyle_Dot4,
    kmStyle_Dot5,
    kmStyle_barLine,
    kmStyle_barFill,
    kmStyle_stepLeft,
    kmStyle_stepMiddle,
    kmStyle_stepRight
};

enum kmLineType
{
    kmLine_Nones,
    kmLine_Time,
    kmLine_Fixed,//Array with lenght = n, array size = 2*n, automate calculate X position when drawing
    kmLine_XY,
    kmLine_Formular,
    kmLine_Fixed2,//Array with lenght = 2*n, array size = 2*n, automate calculate X, Y outside of library
	kmLine_FormularMuparser
};

enum kmFormularType
{
    kmFormular_sum,
    kmFormular_sub,
    kmFormular_multiple,
    kmFormular_divide
};


struct kmChartLine
{
	string name;
	kmstring name_;
    float color[3];
    bool m_bVisible;
    //Visible and Active ==>visible
    //Visible: enable on Legend
    //Active: Draw ...
    bool m_bActive;
    float m_fLineWidth;

    /*
     * DataScale and DataOffset is used for display
     * displayValue = realValue*m_fDataScale + m_fDataOffset;
     * in ListData, the values are still realValue
    */
    float m_fDataScale;
    float m_fDataOffset;
    //float m_fTimeScale;

    /*
     * used in formular line
     * formularLine = line1*m_fOperant1Scale + line2*m_fOperant2Scale + m_fFormularOffset
    */
    float m_fOperant1Scale;
    float m_fOperant2Scale;
    float m_fFormularOffset;
    /*
     * unique Id of line
    */
    int id;
    /*
     * O trong che do ve Line theo XY Mode (2 gia tri), khong co truc thoi gian
     * thi them Scale va Type cho bien con lai
     *     //scale and offset value
     *  displayed_Value= realValue*scale + offset
    */
    float m_fDataScaleY;
    float m_fDataOffsetY;
    /*
     * Draw Time Line
    */
    void *pData;

    /*
     * O trong che do ve Line theo XY Mode (2 gia tri), khong co truc thoi gian
     * thi them Scale va Type cho bien con lai
     * Can them 1 bien nua cung duoc update gia tri
    */
    void *pDataY;
    /*
     * datatype: int, float, double, long, bool ...
    */
    kmDataType   eDataType;

    /*
     * Incase Formular Line
     * Line 1
    */
    kmChartLine *pLine1;

    /*
     * Incase Formular Line
     * Line 2
     *
    */
    kmChartLine *pLine2;

	/*
	* muParser formular
	*/
	//string m_strMuFormular;
	kmstring m_strMuFormular;

	/*
	* Incase: MuFormular
	*/
	std::vector<kmChartLine*> m_listLine;
    /*
     * Incase Formular Line
     * Formular for Line 1 and Line 2
     * For example: value = Line1 + Line2 ==> eFormular = formular_sum
    */
    kmFormularType eFormular;
    /*
     * O trong che do ve Line theo XY Mode (2 gia tri), khong co truc thoi gian
     * thi them Scale va Type cho bien con lai
    */
    kmDataType   eDataTypeY;
    //std::vector<float>   lineData;
    std::vector<float>   lineData;
    std::vector<float>   timeData;
    /*
     * Draw Array
     * line_fixed: arrGraph contain: 2*arrLenght elements
     * line_fixed2: arrGraph contain: arrLenght elements (2*n)
     *
    */
    float *arrGraph;
    int arrLenght;
    /*
     * int Time_Line: use minValue, maxValue for Y_Axis
     * int XY_Line: use minValue, maxValue for X_Axis, minValueY, maxValueY for YAxis
     * it is used in autoScale to re_scale the graph for min, value values
    */
    /*
     * value is represented for XAxis
     * valueY is represented for Yaxis
    */
    float minValue;
    float maxValue;
    float minValueY;
    float maxValueY;

    /*
     * it is limited value,
     * which values is out of limit --> do not update to the list
    */
    float m_fLimitedMinX;
    float m_fLimitedMaxX;
    float m_fLimitedMinY;
    float m_fLimitedMaxY;

    kmLineType m_eLineType;
    //Index which is the current index of other lines when add a new reserved line
    int m_nOffsetIndex;

    bool m_bIsReserved;
    int m_nReservedId;

    /*
     * Baseline Value is used in draw line as polygon with alpha
     * Baseline is the compliment point for polygon
    */
    float m_fBaseLineValue;
    kmLineStyle m_eStyle;

    /*
     * is Enum
    */
    bool m_bIsEnum;
    std::map<int, std::string> m_mapEnum;

    /*
    * is reserved
    */
    //bool m_bIsReserved;
    kmChartLine()
    {
        m_eLineType = kmLine_Time;
        m_eStyle = kmStyle_solid;
        eDataType = kmData_float;
        eDataTypeY = kmData_float;
        m_fLineWidth = 1.0;

        /*
         * value is represented for XAxis
         * valueY is represented for Yaxis
        */
        minValue = 1000.0;
        maxValue = -1000.0;

        minValueY = 1000.0;
        maxValueY = -1000.0;
        m_fDataScale = 1.0;
        m_fDataScaleY = 1.0;
        m_fDataOffset = 0.0;
        m_fDataOffsetY = 0.0;
        id = 0;
        m_nOffsetIndex = 0;

        m_fLimitedMinX = -1000000.0;
        m_fLimitedMaxX = 1000000.0;
        m_fLimitedMinY  = -1000000.0;
        m_fLimitedMaxY  = 1000000.0;

        m_bIsReserved = false;
        m_nReservedId = -1;
        m_fOperant1Scale = 1.0;
        m_fOperant2Scale = 1.0;
        m_fFormularOffset = 0.0;
        m_fBaseLineValue = 0.0;
        m_bActive = true;
        m_bIsEnum = false;
        m_mapEnum.clear();
        //m_fTimeScale = 1.0;
        m_bIsReserved = false;
    }
};

class kmChartData
{
    friend class widgetChart;
public:
   kmChartData();
   ~kmChartData();
   void setDataLength(int val){m_nDataLenght = val;}
   int getDataLength() {return m_nDataLenght;}
public:
   /*
    * chartID: store the current ID of last line
    */
    int m_nChartId;
    /*
     * chartID: store the current ID of last reserved line
     */
    int m_nReservedChartId;

    /*
     * the maximun lenght of line data
     * if data is pushed over the lenght --> increase the m_nDataLenght and set reserve for listData
    */
    int m_nDataLenght;

    /*
     * store the current size of lengthiest line
    */
    int m_nCurrentTimeIndex;


    /*
     * limit the size of line (for example 100000 elements) for lighting using
    */
    int m_nLimitedSize;

    /*
     * limit the size of line (2*m_nLimitedLenght elements) for lighting using
    */
    bool m_bLitmitedLineSize;

    /*
     * store the min and max of lines
    */

    float m_fMinX;
    float m_fMaxX;
    float m_fMinY;
    float m_fMaxY;

    /*
     * limit the value, if data out of range ==> do not update
    */
    float m_fUnderLimitX;
    float m_fUnderLimitY;
    float m_fUperLimitX;
    float m_fUperLimitY;
public:
    /*
     * store lines
    */
    std::map<int,kmChartLine* > m_mapChart;
    std::map<int,kmChartLine* > m_mapReservedLines;
public:
    kmChartLine* addReserdvedLine(void* pData, float* color, string name, kmDataType type = kmData_float, float scale = 1.0, float offset = 0.0);
    kmChartLine* addTimeLine(void* pData, float* color, string name, kmDataType type = kmData_float, float scale = 1.0, float offset = 0.0);
    kmChartLine* addTimeLineFromReserved(kmChartLine* pLine);
    kmChartLine* addXYLine(void* pDataX, void* pDataY, float* color, string name, kmDataType typeX = kmData_float, kmDataType typeY = kmData_float, float scaleX = 1.0, float scaleY = 1.0, float limitedMinX = -1000, float limitedMaxX = 1000, float limitedMinY = -1000, float limitedMaxY = 1000, float offsetX = 0.0, float offsetY = 0.0);
    kmChartLine* addXYLine(int line1, int line2, float* color);
    /*
     * AddFixedLine
     * pData contain: 2*arrLenght elements
    */
    kmChartLine* addArrayLine(float* pData, float* color, string name, int nLenght);
    /*
     * AddFixedLine
     * pData contain: arrLenght elements
    */
    kmChartLine* addArrayLine2(float* pData, float* color, string name, int nLenght);
    kmChartLine* addFormularLine(int line1, int line2, string name, kmFormularType eFormular, float* color, float scale1, float scale2, float offset);
	kmChartLine* addFormularMuParser(string name, kmstring strFormular, std::vector<kmChartLine*>& listLine, float* color);

    /*
     * addline from function: Derivative, Integration
    */
    kmChartLine* addDerivativeLine(kmChartLine* pLine, float* color, string name);
    kmChartLine* addIntegrationLine(kmChartLine* pLine, float* color, string name);
    kmChartLine* addLowPassFilterLine(kmChartLine* pLine, float* color, string name, float cutoffFreq);
    kmChartLine* addHighPassFilterLine(kmChartLine* pLine, float* color, string name, float cutoffFreq);
    kmChartLine* addKalmanFilterLine(kmChartLine* pLine, float* color, string name, float p, float q, float r);
    kmChartLine* addTestLine(kmChartLine* pLine, float* color, string name, float p1, float p2, float p3, float p4);
    kmChartLine* addTestLineFrom2Line(kmChartLine* pLine1, kmChartLine* pLine2, string name, float* color, float p1, float p2, float p3, float p4);

    kmChartLine* handleAddNewLine(kmChartLine* pLine, float* color, string name);
    void removeLine(string name);
    void removeLine(kmChartLine* pLine);
    kmChartLine* getLine(string name);
    kmChartLine* getLine(int idx);
    kmChartLine* getReseredLine(int idx);
    bool removeReseredLine(int idx);

    void removeAllLine();
    void enableLine(int index, bool bEnable);
    void enableLine(string name, bool bEnable);
    void updateData(float time = 0);
    void updateData(kmChartLine* pLine, float time);
    void clearAllLine();
    void changeColor(string name, float *color);
    int getCurrentIndex();

    void setLimitDataRange(float minX, float maxX, float minY, float maxY) { m_fUnderLimitX = minX; m_fUperLimitX = maxX; m_fUnderLimitY = minY; m_fUperLimitY = maxY;}
    void setLimitDataRangeX(float minX, float maxX) { m_fUnderLimitX = minX; m_fUperLimitX = maxX;}
    void setLimitDataRangeY(float minY, float maxY) { m_fUnderLimitY = minY; m_fUperLimitY = maxY;}

	//class kmChartHandler;
	//kmChartHandler* m_pChartHandler;
	//class Parser;
    bool m_bIsUpdateReservedLine;
	Parser* m_pParser;
};


#endif // KMkmChartData_H
