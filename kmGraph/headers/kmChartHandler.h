#ifndef KMCHARTHANDLER_H
#define KMCHARTHANDLER_H
#include <iostream>
//#include <string.h>
//#include <iostream>
//#include <ostream>
//#include <istream>
//#include <fstream>
#include <string>

#include "kmGraph/headers/kmChartData.h"
#include "kmGraph/headers/kmGuiTimer.h"
#include "kmGraph/headers/kmConfigFile.h"
#include "muParser.h"

#define DEG_2_RAD 				0.01745329252
#define RAD_2_DEG 				57.295779513
//#define EarthRadius             6371000
#define EarthRadius             6378137
#define CONSTANT_COS 		 	5967538.518//EarthRadius*cosine(orgLat);

using namespace mu;
enum kmMouseEvent
{
	kmMouseLeft,
	kmMouseMiddle,
	kmMouseRight,
	kmMouseLeftDouble,
	kmMouseMiddileDouble,
	kmMouseRightDouble,
	kmMouseWheelUp,
	kmMouseWheelDown,
	kmMouseNone
};

enum kmCursorShape
{
	km_ArrowCursor,
	km_UpArrowCursor,
	km_CrossCursor,
	km_WaitCursor,
	km_IBeamCursor,
	km_SizeVerCursor,
	km_SizeHorCursor,
	km_SizeBDiagCursor,
	km_SizeFDiagCursor,
	km_SizeAllCursor,
	km_BlankCursor,
	km_SplitVCursor,
	km_SplitHCursor,
	km_PointingHandCursor,
	km_ForbiddenCursor,
	km_WhatsThisCursor,
	km_BusyCursor,
	km_OpenHandCursor,
	km_ClosedHandCursor,
	km_DragCopyCursor,
	km_DragMoveCursor,
	km_DragLinkCursor,
	km_LastCursor = 23,
	km_BitmapCursor = 24,
	km_CustomCursor = 25
};

enum kmAxisStyle
{
	kmAxis_Text_Horizontal,
	kmAxis_Text_Inclide30deg,
	kmAxis_Text_Inclide45deg,
	kmAxis_Text_Inclide60deg,
	kmAxis_Text_Inclide90deg,
	kmAxis_Text_Inclide120deg,
	kmAxis_Text_Inclide135deg,
	kmAxis_Text_Inclide150deg
};

enum kmTimeFormat {
	kmTime_second,
	kmTime_yearmonthday,
	kmTime_hourmin,
	kmTime_hourminsec,
	kmTime_minsec
};


enum kmAxisLineStyle {
	kmAxisLine_solid,
	kmAxisLine_dotPoint,
	kmAxisLine_dotLine,
	kmAxisLine_dotLineandPoint,

};

struct kmTextInform
{
	int m_nFontSize;
	string m_strFontname;
	float color[3];
	int charWidth;
	int charHeight;

	kmTextInform() {
		m_nFontSize = 13;
		m_strFontname = string("arial");
		charWidth = 15;
		charHeight = 20;
		color[0] = 1.0;
		color[1] = 1.0;
		color[2] = 1.0;
	}
	kmTextInform(kmTextInform& src) {
		m_nFontSize = src.m_nFontSize;
		m_strFontname = src.m_strFontname;
		charWidth = src.charWidth;
		charHeight = src.charHeight;
		color[0] = src.color[0];
		color[1] = src.color[1];
		color[2] = src.color[2];
	}
};

struct kmLineInform
{
	float m_fLineWidth;
	float color[3];
	kmAxisLineStyle m_eLineType;
};

struct kmFillInform
{
	float m_fAlpha;
	float color[3];
};


enum mouseDrag
{
    drag_none,
    drag_chart,
    drag_ruler,
    drag_legend,
    drag_widgetName,
    drag_customize
};

struct kmAxisInform_T
{
	float min;//MinData
	float max; //MaxData
	float minFixedLineDefault;//Gia tri duoc set up ban dau, ko thay doi trong tat ca qua trinh
	float maxFixedLineDefault;//Gia tri duoc set up ban dau, ko thay doi trong tat ca qua trinh
	float minTimeLineDefault;//Gia tri duoc set up ban dau, ko thay doi trong tat ca qua trinh
	float maxTimeLineDefault;//Gia tri duoc set up ban dau, ko thay doi trong tat ca qua trinh
	float lenght;
	float step;
	int numofBigPoint; // So diem chia lon
	int numofSmallPoint; //So diem chia nho
	float origin; //Goc toa do
	float originOffset;//Tai diem goc toa do, hien thi lech di mot doan offset de tranh trung voi truc con lai
	std::string name; //Ten cua truc toa do
	bool isViewName;

	kmAxisStyle m_eStyle;
	kmTimeFormat m_eTimeFormat;
	int m_nPosX;
	int m_nPosY;

	bool m_bMainGridView;
	bool m_bMainGridViewText;
	bool m_bSmallGridView;
	bool m_bSmallGridViewText;
	float m_fMainGridLineWidth;
	float m_fSmallGridLineWidth;
	float m_fMainGridAlpha;
	float m_fSmallGridAlpha;
	float m_fMainGridSeparator;
	float m_fSmallGridSeparator;
	kmAxisLineStyle m_eMainGridLineStyle;
	kmAxisLineStyle m_eSmallGridLineStyle;
	float m_crMainGrid[3];
	float m_crSmallGrid[3];
	int m_nDotLengh1;
	int m_nDotLengh2;

	kmTextInform m_tTextMain;
	kmTextInform m_tTextSmall;
	kmTextInform m_tTextName;

	kmAxisInform_T()
	{
		min = 0;
		max = 100;
		minFixedLineDefault = 0;
		maxFixedLineDefault = 360;
		minTimeLineDefault = 0;
		maxTimeLineDefault = 100.0;
		lenght = max - min;
		numofBigPoint = 1;
		numofSmallPoint = 10;
		name = "";
		origin = -0.95;
		originOffset = 0.05;
		step = 0.1;
		isViewName = false;
		m_tTextMain.m_nFontSize = 13;
		m_eStyle = kmAxis_Text_Horizontal;
		m_eTimeFormat = kmTime_second;
		m_nPosX = 0;
		m_nPosY = 0;

		m_bMainGridView = true;
		m_bMainGridViewText = true;
		m_bSmallGridView = false;
		m_bSmallGridViewText = false;
		m_fMainGridLineWidth = 1.0;
		m_fSmallGridLineWidth = 1.0;
		m_fMainGridAlpha = 0.0;
		m_fSmallGridAlpha = 0.0;
		m_fMainGridSeparator = 5;
		m_fSmallGridSeparator = 5;
		m_eMainGridLineStyle = kmAxisLine_dotPoint;
		m_eSmallGridLineStyle = kmAxisLine_dotPoint;
		m_crMainGrid[0] = 65.0 / 255.0;
		m_crMainGrid[1] = 68.0 / 255.0;
		m_crMainGrid[2] = 54.0 / 255.0;

		m_crSmallGrid[0] = 65.0 / 255.0;
		m_crSmallGrid[1] = 68.0 / 255.0;
		m_crSmallGrid[2] = 54.0 / 255.0;
		m_nDotLengh1 = 10;
		m_nDotLengh2 = 5;

		m_tTextMain.charWidth = 13;
		m_tTextMain.charHeight = 20;
		m_tTextSmall.charWidth = 13;
		m_tTextSmall.charHeight = 20;
		m_tTextName.charWidth = 30;
		m_tTextName.charHeight = 25;
		m_tTextName.m_nFontSize = 14;

	}

	kmAxisInform_T(float fMin, float fMax, float fNumOfBigPoint, float fNumOfSmallPoint, const char* sName, float fOrg, float fOrgOffset, float valueStep = 0.01, float minDefault = 0, float maxDefault = 100)
	{
		min = fMin;
		max = fMax;
		minFixedLineDefault = min;
		maxFixedLineDefault = max;
		minTimeLineDefault = minDefault;
		maxTimeLineDefault = maxDefault;
		//lenght = maxTimeLine - minTimeLine;
		lenght = max - min;

		numofBigPoint = fNumOfBigPoint;
		numofSmallPoint = fNumOfSmallPoint;
		name = std::string(sName);
		origin = fOrg;
		originOffset = fOrgOffset;
		step = valueStep;
		isViewName = false;
		m_tTextMain.m_nFontSize = 13;
		m_eStyle = kmAxis_Text_Horizontal;
		m_eTimeFormat = kmTime_second;
		m_nPosX = 0;
		m_nPosY = 0;

		m_bMainGridView = true;
		m_bMainGridViewText = true;
		m_bSmallGridView = false;
		m_bSmallGridViewText = false;
		m_fMainGridLineWidth = 1.0;
		m_fSmallGridLineWidth = 1.0;
		m_fMainGridAlpha = 0.0;
		m_fSmallGridAlpha = 0.0;
		m_fMainGridSeparator = 5;
		m_fSmallGridSeparator = 5;
		m_eMainGridLineStyle = kmAxisLine_dotPoint;
		m_eSmallGridLineStyle = kmAxisLine_dotPoint;
		m_crMainGrid[0] = 65.0 / 255.0;
		m_crMainGrid[1] = 68.0 / 255.0;
		m_crMainGrid[2] = 54.0 / 255.0;

		m_crSmallGrid[0] = 65.0 / 255.0;
		m_crSmallGrid[1] = 68.0 / 255.0;
		m_crSmallGrid[2] = 54.0 / 255.0;
		m_nDotLengh1 = 10;
		m_nDotLengh2 = 5;

		m_tTextMain.charWidth = 13;
		m_tTextMain.charHeight = 20;
		m_tTextSmall.charWidth = 13;
		m_tTextSmall.charHeight = 20;
		m_tTextName.charWidth = 30;
		m_tTextName.charHeight = 25;
	}

	void setCurrentMinMax(float fMin, float fMax)
	{
		min = fMin; max = fMax;
		lenght = fMax - fMin;
	}

	void resetFixedLine() {
		min = minFixedLineDefault;
		max = maxFixedLineDefault;
		lenght = max - min;
	}

	void resetTimeLine()
	{
		min = minTimeLineDefault;
		max = maxTimeLineDefault;
		lenght = max - min;
	}
	void setFixedLineDefault(float minDefault, float maxDefault)
	{
		minFixedLineDefault = minDefault;
		maxFixedLineDefault = maxDefault;
	}
	void setTimeLineDefault(float minDefault, float maxDefault) {
		minTimeLineDefault = minDefault;
		maxTimeLineDefault = maxDefault;
	}
};

enum kmAxisAction
{
	kmAxis_Action_None,
	kmAxis_Action_Drag,
	kmAxis_Action_ZoomBothSide
};

enum kmMouseMoveHandler
{
	kmMouseMoveNone,
	kmMouseMoveZoomCrop,
	kmMouseMoveDrag
};

struct kmRulerInform
{
	float xPos;
	float yPos;
	bool viewX;
	bool viewY;
    int timeIdx;
    bool isDrag;
};

enum kmPointType
{
	kmPoint_rectangle,
	kmPoint_circle,
	kmPoint_triangle,
	kmPoint_star,
	kmPoint_elipse,
	kmPoint_customized
};

/*
* kmValue_Data: it will depend on m_tAzisX, m_tAxisY max, min value
* kmValue_OpenGL: from -1.0 and 1.0 on opengl coOrdinate
* kmValue_Pixel: From 0 to width, height on Screen coOrdinate
*/
enum kmValueType
{
	kmValue_Data,
	kmValue_OpenGL,
	kmValue_Pixel
};

enum kmTextView
{
	kmText_Value,
	kmText_Time,
	kmText_TimeValue,
	kmText_TimeValueXValueY
};

struct kmDataTime
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

enum kmRulerStyle
{
    kmRuler_LongLine,
    kmRuler_ShortLine,
    kmRuler_Point
};

class kmDrawBase;
struct kmIcon
{
	kmPointType shapeType;
	float width;//In pixel
	float height;//In pixel
	kmTextInform m_tText;
	kmLineInform m_tLine;
	kmFillInform m_tFill;

	int fontType;
	bool isDrawText;
	bool isDrawLine;
	float isDrawFill;
	bool isCustomizedText;
	float textOffsetX;
	float textOffsetY;
	int decimalNumX;
	int decimalNumY;
	kmValueType valueType;
	string name;
	int index;
	kmTextView textView;
	kmDrawBase* drawObj;
	/*
	* it it not used in a group of icon
	* it is just used in Icon manager
	*/
	double valueX;
	double valueY;
	float time;
	char customizedText[256];

	/*
	* noOfCharInText
	*/
	int noOfCharX;
	int noOfCharY;

	/*
	* autoScale Iconshape size when zoom axisX and Y
	*/
	bool m_bAutoResize;
    bool isView;
	kmIcon()
	{
		shapeType = kmPoint_rectangle;
		valueType = kmValue_Data;
		isCustomizedText = false;
		textView = kmText_Value;
		width = 5;
		height = 5;
		m_tFill.color[0] = 0.0;
		m_tFill.color[1] = 1.0;
		m_tFill.color[2] = 0.0;
		m_tLine.color[0] = 0.0;
		m_tLine.color[1] = 1.0;
		m_tLine.color[2] = 0.0;
		m_tText.color[0] = 0.0;
		m_tText.color[1] = 1.0;
		m_tText.color[2] = 0.0;
        m_tFill.m_fAlpha = 1.0;
		m_tLine.m_fLineWidth = 1.0;

		isDrawText = false;
		isDrawFill = true;
		isDrawLine = false;
        isView = true;
		fontType = 0;
		m_tText.m_nFontSize = 10;
		m_tText.m_strFontname = string("arial");
		textOffsetX = 7.5;
		textOffsetY = 4;
		decimalNumX = 3;
		decimalNumY = 3;
        name = "Icon";
		time = 0;
		for (int i = 0; i < 256; ++i) {
			customizedText[i] = '\0';
		}
		noOfCharX = 0;
		noOfCharY = 0;
		valueX = 0;
		valueY = 0;
		m_bAutoResize = false;
	}

	kmIcon(kmIcon& src)
	{
		shapeType = src.shapeType;
		width = src.width;
		height = src.height;
		for (int i = 0; i< 3; ++i)
		{
			m_tFill.color[i] = src.m_tFill.color[i];
			m_tLine.color[i] = src.m_tLine.color[i];
			m_tText.color[i] = src.m_tText.color[i];
		}
		m_tFill.m_fAlpha = src.m_tFill.m_fAlpha;
		m_tLine.m_fLineWidth = src.m_tLine.m_fLineWidth;;
		m_tText.m_nFontSize = src.m_tText.m_nFontSize;
		fontType = src.fontType;
		m_tText.m_strFontname = src.m_tText.m_strFontname;
		isDrawText = src.isDrawText;
		isDrawLine = src.isDrawLine;
		isCustomizedText = src.isCustomizedText;
		isDrawFill = src.isDrawFill;
		textOffsetX = src.textOffsetX;
		textOffsetY = src.textOffsetY;
		decimalNumX = src.decimalNumX;
		decimalNumY = src.decimalNumY;
		valueType = src.valueType;
		valueX = src.valueX;
		valueY = src.valueY;
		m_bAutoResize = src.m_bAutoResize;
		//customizedText = src.customizedText;
		index = src.index;
		name = src.name;
		textView = src.textView;
		//std::memcpy(customizedText, src.customizedText, sizeof(src.customizedText));
		for (int i = 0; i < 256; ++i) {
			customizedText[i] = src.customizedText[i];
		}
		time = src.time;
		drawObj = src.drawObj;
		noOfCharX = src.noOfCharX;
		noOfCharY = src.noOfCharY;
        isView = src.isView;
	}
};

struct kmLineIcon
{
	kmValueType valueType;
	int lineWidth;
	float colorLine[3];
	kmIcon firstIcon;
	kmIcon secondIcon;
	bool isDrawFirstPoint;
	bool isDrawLastPoint;
	bool isDrawLine;
    bool isView;
	string name;
	int index;
    kmLineIcon()
    {
		lineWidth = 1.0;
		valueType = kmValue_Data;
		colorLine[0] = 0.0;
		colorLine[1] = 1.0;
		colorLine[2] = 0.0;
		name = "";
	}

	kmLineIcon(kmLineIcon& src) :
		firstIcon(src.firstIcon),
		secondIcon(src.secondIcon)
	{
		valueType = src.valueType;
		lineWidth = src.lineWidth;
		for (int i = 0; i< 3; ++i) {
			colorLine[i] = src.colorLine[i];
		}
		isDrawFirstPoint = src.isDrawFirstPoint;
		isDrawLastPoint = src.isDrawLastPoint;
		isDrawLine = src.isDrawLine;
		index = src.index;
		name = src.name;
        isView = src.isView;
	}
};

struct kmRect {
	float kmRect_top;
	float kmRect_bottom;
	float kmRect_left;
	float kmRect_right;
};

class kmChartHandler
{
public:
	//kmChartHandler();
	explicit kmChartHandler(int nWidth, int nHeight);
	~kmChartHandler();
public:
	virtual void onDraw();
	virtual void drawAxis();
	virtual void drawXAxis();
	virtual void drawYAxis();
	virtual void drawDropPins();
//    virtual void drawIconMin();
//    virtual void drawIconMax();
	virtual void drawMarkPoints();
	virtual void drawRuler();
	virtual void drawListRuler();
	virtual void drawMouseZoomCrop();
	virtual void drawWidgetName();
	virtual void drawMousePos();
	virtual void drawBorder();
	virtual void drawMargin();
	virtual void drawChart();
	virtual void drawChart_TimeLines();
	virtual void drawChart_BarChart();
	virtual void drawChart_FixedLines();
	virtual void drawChart_FixedLines_2();
	virtual void drawChart_XYLines();
	//virtual void drawLinePoints();
	virtual void drawLegend();
    virtual void drawLegendOnRuler(int timeIdx, float glX, float glY);

    int findTimeIndexWithinChart(kmChartLine* pLine, float xValue);
	//valueX, valueY: Is line value
	virtual void drawPoint(kmIcon& icon, float valueX, float valueY);
	//virtual void drawPoint(kmIcon& icon, double valueX, double valueY);
	virtual void drawIcon(kmIcon& icon);
	virtual void drawLineIcon(kmLineIcon& line);
	void drawListIcons();
	void drawListLineIcons();

	virtual void showHideWidgetControl() {}
	virtual void hideWidget(){}
	void autoScale();
	void zoomInY(float scale);
	void zoomOutY(float scale);
	void zoomDynamicY(float scale, float orgY);
	void moveUp(float);
	void moveDown(float);
	void onSize(int cx, int cy);
	kmChartLine* addReservedLine(void* pData, string name, kmDataType type = kmData_float, float scale = 1.0, float offset = 0.0);
	kmChartLine* addTimeLineFromReserved(kmChartLine* pLine);
	kmChartLine* addTimeLine(void* pData, float* color, string name, kmDataType type = kmData_float, float scale = 1.0, float offset = 0.0);
	kmChartLine* addTimeLine(void* pData, string name, kmDataType type = kmData_float, float scale = 1.0, float offset = 0.0);
	kmChartLine* addXYLine(void* pDataX, void* pDataY, float* color, string name, kmDataType typeX = kmData_float, kmDataType typeY = kmData_float, float scaleX = 1.0, float scaleY = 1.0, float minX = -1000, float maxX = 1000, float minY = -1000, float maxY = 1000, float offsetX = 0.0, float offsetY = 0.0);
	kmChartLine* addXYLine(void* pDataX, void* pDataY, string name, kmDataType typeX = kmData_float, kmDataType typeY = kmData_float, float scaleX = 1.0, float scaleY = 1.0, float minX = -1000, float maxX = 1000, float minY = -1000, float maxY = 1000, float offsetX = 0.0, float offsetY = 0.0);
	kmChartLine* addXYLine(int line1, int line2);

	/*
	* AddFixedLine(ArrayLine
	* pData contain: 2*nLenght elements
	*
	*/
	void addArrayLine(float* pData, float* color, string name, int nLenght);
	void addArrayLine(float* pData, string name, int nLenght);
	/*
	* AddFixedLine(ArrayLine
	* pData contain: 2*nLenght elements
	*
	*/
	void addArrayLine2(float* pData, float* color, string name, int nLenght);
	void addArrayLine2(float* pData, string name, int nLenght);
	kmChartLine* formular2Line(int idx1, string line1, int idx2, string line2, kmFormularType eFormular, float scale1, float scale2, float offset);
	//kmChartLine* addFormularLine(string name, string strFomular, int line);
	kmChartLine* addFormularLine(kmstring name, kmstring strFomular, std::vector<int>& listLine);
	kmChartLine* addDerivativeLine(string name, int idx);
	kmChartLine* addIntegrationLine(string name, int idx);
	kmChartLine* addLowPasFilterLine(string name, int idx, float cutoffFreq);
	kmChartLine* addHighPasFilterLine(string name, int idx, float cutoffFreq);
    kmChartLine* addKalmanFilterLine(string name, int idx, float p, float q, float r);
    kmChartLine* addTestLine(string name, int idx, float p1, float p2, float p3, float p4);
    kmChartLine* addTestLineFrom2Line(string name, int idx1, int idx2, float p1, float p2, float p3, float p4);

	void removeAllLine();
	void removeLine(string name);
	void removeLine(kmChartLine* line);
	void enableLine(int index, bool bEnable);
	kmChartLine* getLine(string name);
	kmChartLine* getLine(int idx);
	void changeColor(string name, float* color);
	void setChartLenght(int nVal) { m_nChartLenght = nVal; }
	void setAutoScale(bool val){ m_bEnableAutoScale = val; cntScale = 0; }

	void setAxisXMax(float valX);
	void setAxisXMinMax(float valMin, float valMax);
	void setAxisYMinMax(float valMin, float valMax);
	//void setVirtualAxis(float minX, float maxX, float minY, float maxY);
	float* getColor(int); //1:blue - 2:green - 3:gray  - 4:red - 5:yellow - Default:white
	void stopTimeLine();
	void startTimeLine() { m_bStartRunning = true; }
	void pauseTimeLine(bool bPause);
	void hideAllLine();
    void showAllLine();
    void viewFullTime();
	virtual void setAxisXInform(float fMin, float fMax, float fNumOfBigPoint, float fNumOfSmallPoint, const char* sName, float fOrg = -0.98, float fOrgOffset = 0.05);
	virtual void setAxisYInform(float fMin, float fMax, float fNumOfBigPoint, float fNumOfSmallPoint, const char* sName, float fOrg = -0.98, float fOrgOffset = 0.05);

	/*
	* limit the size of grapth lines
	*/
	void setLitmittedLineSize(int limitSize);
	int getLitmittedLineSize() { return m_chartData.m_nLimitedSize; }
	void enableLimitLineSize(bool bEnable);
	bool isLimitLineSize() { return m_chartData.m_bLitmitedLineSize; }

	void setBackgroundColor(float red, float green, float blue) { m_fCrBackGround[0] = red; m_fCrBackGround[1] = green; m_fCrBackGround[2] = blue; }
	void setChartColor(float red, float green, float blue) { m_fCrChart[0] = red; m_fCrChart[1] = green; m_fCrChart[2] = blue; }
	//void setAxisColor(float red, float green, float blue) { m_fCrAxis[0] = red; m_fCrAxis[1] = green; m_fCrAxis[2] = blue; }
	//void setAxisBigTextColor(float red, float green, float blue) { m_fCrTextAxisBig[0] = red; m_fCrTextAxisBig[1] = green; m_fCrTextAxisBig[2] = blue; }
	//void setAxisSmallTextColor(float red, float green, float blue) { m_fCrTextAxisSmall[0] = red; m_fCrTextAxisSmall[1] = green; m_fCrTextAxisSmall[2] = blue; }
	//void setSmallGridColor(float red, float green, float blue) { m_fCrGridSmall[0]= red; m_fCrGridSmall[1] = green; m_fCrGridSmall[2] = blue; }
	//void setBigGridColor(float red, float green, float blue) { m_fCrGridBig[0]= red; m_fCrGridBig[1] = green; m_fCrGridBig[2] = blue; }
	void setBorderColor(float red, float green, float blue) { m_fCrBorder[0] = red; m_fCrBorder[1] = green; m_fCrBorder[2] = blue; }
//	void setAllColor(float backGround[3], float axis[3], float axisBigText[3], float axisSmallText[3])
//	{
//		for (int i = 0; i< 3; ++i){
//			m_fCrBackGround[i] = backGround[i];
//		}
//	}

	//void saveImage(char *fileName);
	//void saveImageAs();

	kmAxisInform_T& getAxisX() { return m_tAxisX; }
	kmAxisInform_T& getAxisY() { return m_tAxisY; }
	/*
	* fMin, fMax: Gia tri min, max hien thi len truc toa do (vi du : 0.0 --> 360.0)
	*fNumOfBigPoint: So khoang chia chinh tren truc toa do
	*fNumOfSmallPoint: So khoang chia nho theo tung khoang chia chinh
	*sName: Ten cua truc toa do
	*fOrg: Goc toa do cua
	*fOrgOffset: Tai diem goc toa do, hien thi lech di mot doan offset de tranh trung voi truc con lai
	* */
	void setBigFontName(const char* strFont);
	void setSmallFontName(const char* strFont);
	void setBigFontSize(int nVal);
	void setSmallFontSize(int nVal);
	//void setBigGridLineWidth(float fVal) { m_fBigGridLineWidth = fVal; }
	//void setSmallGridLineWidth(float fVal) { m_fSmallGridLineWidth = fVal; }
	//void enableBigGrid(bool bVal) { m_bViewBigGrid = bVal; }
	//void enableSmallGrid(bool bVal) { m_bViewSmallGrid = bVal; }

	void setWidgetName(const std::string& name) { m_strWidgetName = name; }
	std::string getWidgetName() { return m_strWidgetName; }

	void setNamePos(float x, float y) { m_fNamePosX = x; m_fNamePosY = y; }
	float getNamePosX() { return m_fNamePosX; }
	float getNamePosY() { return m_fNamePosY; }

	int getWidth() { return m_nWidth; }
	int getHeight() { return m_nHeight; }
	void setWidth(int width) { m_nWidth = width; }
	void setHeight(int height) { m_nHeight = height; }
	float getScaleX() { return 1.0; }
	float getScaleY() { return 1.0; }

	void setNameColor(float r, float g, float b) { m_crName[0] = r; m_crName[1] = g; m_crName[2] = b; }

//	void enableDisplayPeak(bool bVal) { m_bViewPeak = m_bViewPeak; }
	bool isDisplayPeak() { return m_bViewPeak; }

	void setLabelXFloatPointNumber(int val) { m_nLabelXFloatPointNumner = val; }
	void setLabelYFloatPointNumber(int val) { m_nLabelYFloatPointNumner = val; }
	void setupWidgetStyle(kmWidgetStyle style);
	void convertQt2Gl(int qtX, int qtY, float& glX, float& glY);
	void convertGl2Qt(float glX, float glY, int& qtX, int& qtY);

	//Overwrite from QWidget
	void mousePressEvent(kmMouseEvent event);
	void mouseMoveEvent(kmMouseEvent event);
	void mouseReleaseEvent(kmMouseEvent event);
	void mouseDoubleClickEvent();
	void wheelEvent(kmMouseEvent event, float value);

	void updateData();
	void appendDataWithTime(kmChartLine* pLine, float value, float time);
	void appendDataWithTime(kmChartLine* pLine, float valueX, float valueY, float time);
	void appendDataWithoutTime(kmChartLine* pLine, float value);
	void appendDataWithoutTime(kmChartLine* pLine, float valueX, float valueY);
public:
	virtual void zoomInAxisX(); //Zoom +
	virtual void zoomOutAxisX(); //Zoom -
	virtual void resetTimeLine();

	virtual void refreshLines();
	virtual void drawSelectAxis();
	virtual void zoomToFitX();
	virtual void zoomToFitY();
	virtual void handleZoomCrop();
	virtual void handleDrag();
	bool isOverRanger(float dataIn);
	bool removeDroppedPin(float deltaX, float deltaY);
	bool addDroppedPin();

	void addMarkPoint(float x, float y);
	void removeMarkPoint(float x, float y);
	void removeAllMarkPoints();
	void resetTimeLineColor();

    virtual void handleSaveDataToFile(char* fileName, bool isOnlyVisibleLine = false);
	//virtual void handleSaveDataToCSV(char* fileName, bool bJustVisibleLine);
	void handleSaveDataToCSV(char* fileName, bool bJustVisibleLine, const char* tok = ",");
	virtual void saveDataToFile();
    virtual void saveAsDataToFile(const char* fileName, bool isOnlyVisibleLine = false);
	virtual void openDataFromFile(const char* fileName);
	virtual void openCSVFile(const char* fileName);
    virtual void addCSVFile(const char* fileName);
	virtual void saveDataToCsvFile(const char* fileName, bool bJustVisibleLine, const char* tok = ",");

	/*
	* save and load configuration file (Set for show/hide lines)
	*/

//	virtual void saveConfigFile();
    virtual void loadConfigFile();
//	virtual void saveAsConfigFile(const char* fileName);
//	virtual void openFromConfigFile(const char* fileName);
	virtual void defaultConfig();
//	virtual void handleSaveConfigFile(const char* fileName);
//	virtual void handleLoadConfigFile(const char* fileName);

    virtual void handleSaveConfigFile(std::ofstream& file);
    virtual void handleLoadConfigFile(std::ifstream& file);
	/*
	* utility functions
	*/
	void setGLData(float* arr, int element, float glX, float glY);
	void convertGl2Value(float glX, float glY, float& valueX, float& valueY);
	void convertValue2Gl(float valueX, float valueY, float& glX, float& glY);
	void convertQt2Value(int qtX, int qtY, float& valueX, float& valueY);
	void convertValue2Qt(float valueX, float valueY, int& qtX, int& qtY);
	bool findClosestElement(std::vector<float>& listData, float minValue, int& minElement, int&begin, int& end);
	void addRuler(bool viewX, bool viewY);
	void removeAllRuler();
	void cutLineBetween2Rulers();
    void cutLineFromLeft();
    void cutLineFromRight();
    void cutLineFromLeft_Mouse();
    void cutLineFromRight_Mouse();
	void squareChart();

    void mergeLines(int id);
	/*
	* find numberOfDecimal for YAxis
	*/
	void findYAxisDecimalNumber();
	/*
	* find numberOfDecimal for XAxis
	*/
	void findXAxisDecimalNumber();

	/*
	* autogenerate color for visible line,
	*/
	void autoGenerateColor();
	/*
	* Down  the DataRate
	*/
	void downDataRate(int rate);

	/*
	*
	*/
	void setCursor(kmCursorShape cursor);

	/*
	* Equal scale so that: (maxAxisX - minAxisX)/width() = (maxAxisY - minAxisY)/height()
	*/
	void equalScaleAxisXandY();


	void resizeChartBorder();
	void resizeChartBorder(int offsetL, int offsetBt, int offsetR, int offsetT);

	/*
	* draw Select rect
	*/
	void drawSelectRect(kmRect& rc);
	void drawLine(float x1, float y1, float x2, float y2, kmAxisLineStyle eLineStyle, float lineWidth, float lineLen, float blankLen, float* cr);

	float getAxisTextAngle(kmAxisStyle style);
protected:
	int m_nWgId;
	int prevVisibleLineCnt;
	int prevColumn;
	bool prevViewNameY;
	float prevLenght;
	bool prevViewNameX;
	int prevLegendPosX;
	int prevLegendPosY;
	static float cr_grey[3];
	static float cr_red[3];
	static float cr_green[3];
	static float cr_yellow[3];
	static float cr_blue[3];
	static float cr_white[3];
	static float cr_cyan[3];
	static float cr_pink[3];
	static float cr_black[3];
	int cntScale;
	float* m_drawData;//[2*m_nChartLenght];
	bool		m_bPressing;
	int         m_nVisibleLineCount;
	/*
	* calculate number of lines for fitting color to line
	*/
	int m_nTimeLineCount;
	int m_nArrayLineCount;
	/*
	* calculate minX, maxX, minY, maxY value during draw
	* and use this for autoscale
	*/
	float m_fMinDrawXValue;
	float m_fMaxDrawXValue;
	float m_fMinDrawYValue;
	float m_fMaxDrawYValue;

	float m_fXMaxValueSelected;
	float m_fXMinValueSelected;
	float m_fXLenghtSelected;
	float m_fYMaxValueSelected;
	float m_fYMinValueSelected;
	float m_fYLenghtSelected;
	/*
	* on draw time line --> define element index to draw
	*/
	int m_nMinElement;
	int m_nMaxElement;
	kmConfigFile m_configFile;

	/*
	* View Square Chart
	*/
	float m_fOldOrgX;
	float m_fOldOrgY;
	float m_fOldMaxX;
	float m_fOldMaxY;
	kmGuiTimer m_timerGui;
	kmGuiTimer m_timer10Hz;
	/*
	* calculate number of characters of widgetName
	*/
	int m_nNumOfNameChar;
	float prevTime__;
	int downRateCnt;
	//std::map<kmChartLine*, kmRect>  m_mapLegendPos;
public:
    bool m_bSelectAxisX;
    bool m_bSelectAxisY;
    float m_fGlMousePressX;
    float m_fGlMousePressY;
    float m_fGlMouseMoveX;
    float m_fGlMouseMoveY;
    float m_fGlMouseReleaseX;
    float m_fGlMouseReleaseY;
	//Automatically fit color for lines
	bool m_bAutoGenerateColor;
	/*
	* list of Ruler
	*/
	std::vector<kmRulerInform> m_listRuler;
	int m_nAutoScaleOffsetTop;
	int m_nAutoScaleOffsetBottom;
	int m_nAutoScaleOffsetLeft;
	int m_nAutoScaleOffsetRight;
	//bool m_bNeedUpdateLegendPos;
	int numberIndexs;
	bool m_bEnableAutoScale;
	//Use in AutoScale
	unsigned int m_nChartLenght;
	kmChartData   m_chartData;
	/*
	* pauseTimeLine --> do not update data
	*/
	bool m_bPauseTimeLine;
	bool m_bFirstRunningTimeline;
	bool m_bStartRunning;
	float m_fTotalTimeLine;
	/*
	* chartType: Line_Fixed, Line_Time, Line_XY ...
	*/
	kmLineType   m_eChartType;
	kmMouseMoveHandler m_eMouseMoveHandler;
	std::vector<kmPoint> m_listDroppedPins;
	bool m_bDrawLinePoints;
	bool m_bDrawDataFromFile;

	/*
	* logChart file name
	*/
	string m_strDataFileName;
	bool m_bEnableDrawRuler;
	/*
	* number of floating point of dropped pins
	*/
	int m_nDecimaNumberPinX;
	int m_nDecimaNumberPinY;

	/*
	* dropped pin information
	*/
	/*
	* Radius around the press point to add new Droppin
	* is In pixel (Qt cooordinate)
	* deltaX*deltaX + deltaY * deltaY < m_fDropPinRadius
	*/
	float m_fDropPinRadius;

	/*
	* use when drawing line points
	*/
	//Use for maximum update data rate: 1000Hz
	//Normaly is 100Hz
	bool m_bHightUpdateDataRate;
	//Trigger is used for outside(On/Off for implement in user software
    bool m_bEnableReservedMenu;
    int m_nReservedNumber;
	bool m_bReservedTrigger1;
	bool m_bReservedTrigger2;
	bool m_bReservedTrigger3;
	bool m_bReservedTrigger4;
	bool m_bReservedTrigger5;
    bool m_bReservedTrigger6;
    bool m_bReservedTrigger7;
    bool m_bReservedTrigger8;
    bool m_bReservedTrigger9;
    bool m_bReservedTrigger10;
	/*
	* EnableDrawFullPoint: --> dont use m_nMaxPointToDraw
	*/
	bool m_bEnableDrawFullPoint;
	/*
	* It is used for optimising draw when listdata Size of very huge
	*/
	int m_nMaxPointToDraw;
	/*
	* EnableTrueTypeFont: use Roboto font
	* others use bitmap
	*/
	bool m_bEnableTrueTypeFont;
	/*
	* mark points (unit: as X axis and Y Axis), which are add from outSide
	*/
	std::vector<kmPoint> m_listMarkPoints;

	bool m_bViewMouseZoomCrop;
	bool m_bViewAxisBorderX;
	bool m_bViewAxisBorderY;
	/*
	* choose kind of inform to display Dropped Pin
	*/
	bool m_bViewText_PinTime;
	bool m_bViewText_PinValue;
	bool m_bViewMarkPoints;
	bool m_bViewMousePos;
	bool m_bViewLegend;
	bool m_bViewLineAsPolygon;
	bool 			m_bViewWidgetName;
	//bool			m_bViewBigGrid;
	//bool			m_bViewSmallGrid;
	/*
	* enable draw tail: draw last point of a line
	*/
	bool m_bViewLastPoint;
	bool m_bViewLastPointText;
	/*
	* Hien thi gia tri Peak
	*/
	bool m_bViewPeak;

	/*
	* Hien thi cac customixed icons
	*/
	bool m_bViewPointIcons;
	bool m_bViewLineIcons;

	/*
	* update axisX when update Data
	*/
	bool m_bEnableUpdateAxisX;
	bool m_bIsSquareChart;
	bool m_bIsElasticAxisX;
	/*
	* calculate Data sample rate
	*/
	float m_fDataRate;
	int m_nDownDataRate;
	/*
	* UpdateData by OnTimer of WidgetChart
	*/
	bool m_bUpdateDataFromChart;

	/*
	* draw line as PolyGon
	*/
	float m_fPolygonAlpha;
	/*
	* from widgetDecac
	*/
	int			MOUSE_OFFSET_X;
	int			MOUSE_OFFSET_Y;

	int 			m_nWidth;
	int 			m_nHeight;
	float 			m_fCrBackGround[3];
	float 			m_fCrChart[3];
	float			m_fCrBorder[3];
	kmTextInform m_tWidgetName;
	/*
	* Is Used in outside lib: Additional Information for example widgetPower (K, KVer)
	*/
	float			m_fCrInfor[3];
	float			m_fCrSelectAxis[3];

	int             m_nTitleFontType;
	int             m_nAxisFontType;

	kmAxisInform_T	m_tAxisX;
	kmAxisInform_T	m_tAxisY;

	/*
	* kick thuoc cua CHART
	*/
	float 			m_fMarginOrgX;
	float			m_fMarginOrgY;
	float 			m_fMarginMaxX;
	float			m_fMarginMaxY;
	float			m_fOrgGlX;
	float			m_fOrgGlY;
	float			m_fMaxGlX;
	float			m_fMaxGlY;

	//std::string 	m_strBigFontName;
	//std::string 	m_strSmallFontName;
	//int				m_nBigFontSize;
	//int 			m_nSmallFontSize;

	//float			m_fBigGridLineWidth;
	//float			m_fSmallGridLineWidth;
	//float			m_fBigGridAlpha;
	//float			m_fSmalGridlAlpha;

	float 			m_fNamePosX;
	float 			m_fNamePosY;
	float			m_crName[3];
	std::string		m_strWidgetName;
	/*
	* So chu so thap phan hien thi tren cac truc toa do
	*/
	int m_nLabelXFloatPointNumner;
	int m_nLabelYFloatPointNumner;

	/*
	* process mouse action
	*/
	kmPixelPoint		m_ptMousePress;
	kmPixelPoint		m_ptMouseRelease;
	kmPixelPoint		m_ptMouseMove;
	kmAxisAction        m_eAxisAction;
	/*
	* define OrgQt will define OrgGL
	*/
	int m_nChartOffsetLeft;
	int m_nChartOffsetBottom;

	/*
	* distance from boundary to
	*/
	int m_nChartOffsetRight;
	int m_nChartOffsetTop;

	/*
	* position from the bottom right
	* unit: piexel (qt coordinate)
	*/
	float m_fTextMousePosX;
	float m_fTextMousePosY;

	kmWidgetStyle m_eWidgetStyle;
	kmWidgetStyle getWidgetStyle() { return m_eWidgetStyle; }
	kmCursorShape m_cursor;

	/*
	* iCon type
	*/
	kmIcon m_iconDropPin;
	kmIcon m_iconMark;
	kmIcon m_iconLastPoint;
	kmIcon m_iconPeak;
	kmIcon m_iconLinePoint;
	kmIcon m_iconMousePos;
	std::vector<kmIcon*> m_listKmIcon;
	std::vector<kmLineIcon*> m_listKmLine;
	std::vector<kmIcon*> m_listManualIcon;
    std::vector<kmIcon*> m_listManualLineIcon;
	/*
	* store time chart
	*/
	kmDataTime m_dateTime;

	/*
	* Name position
	*/
	int m_nNamePosX;
	int m_nNamePosY;
	int m_nLegendPosX;
	int m_nLegendPosY;
	int m_nLegendNoOfColumn;

	kmTextInform m_tLegendText;
	kmLineInform m_tLegendLine;
	kmFillInform m_tLegendFill;

	kmRect m_rcLegend;
	kmRect m_rcWidgetName;
	bool m_bViewLegendBorder;
	bool m_bViewLegendFill;
    //bool m_bIsSelectLegend;
	int m_nLegendLineLenght;
	int m_nLegendClmSeparator;
	int m_nLegendRowSeparator;


	/*
	* config the sepect rect size
	*/
	int m_nSelectRectSizeX;
	int m_nSelectRectSizeY;
	/*
	* config the select rect color
	*/
	float m_crSelectRect[3];
	/*
	* the point when mouse press to drag
	*/
	int m_nSelectRectPointX;
	int m_nSelectRectPointY;
	/*
	* store the position before selected
	*/
	int m_nSelectRectPosX;
	int m_nSelectRectPosY;
    //bool m_bIsSelectWidgetName;
	std::map<kmChartLine*, kmRect> m_mapLegendRc;
	int m_nCurrentLineSize;
	bool m_bEnableDrawSmooth;

	float m_fTimeScale;
    float m_fTimeOffset;
	double testMUParser;
	Parser m_parser;
	//ParserInt m_parser;
    float m_fLastPointMargin;

    /*
     * draw mouse move position
    */
    int m_nDrawMouseMovePosX;
    int m_nDrawMouseMovePosY;

    /*
     * enable scale total or just scale out
    */
    bool m_bAutoScaleBothSide;

    /*
     * For reserved on menu context
    */
    string m_strMenuReservedName;
    string m_strTrigger1;
    string m_strTrigger2;
    string m_strTrigger3;
    string m_strTrigger4;
    string m_strTrigger5;
    string m_strTrigger6;
    string m_strTrigger7;
    string m_strTrigger8;
    string m_strTrigger9;
    string m_strTrigger10;

    /*
     *
    */
    bool m_bEnableDraw;

    kmRulerStyle m_eRulerStyle;
    int m_nRulerLenghtHor;
    int m_nRulerLenghtVer;
    float m_crRuler[3];

    bool m_bDrawInformOnRuler;
    bool m_bDrawMousePosOnRuler;
    bool m_bViewIconMin;
    bool m_bViewIconMax;
    kmIcon m_iconMin;
    kmIcon m_iconMax;
    mouseDrag   m_eMouseDrag;
};

#endif // KMCHARTHANDLER_H
