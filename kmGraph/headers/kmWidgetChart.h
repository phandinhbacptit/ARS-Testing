#ifndef KMwidgetChart_H
#define KMwidgetChart_H

#include "kmGraph/headers/kmDrawOpenGL.h"
#include "kmGraph/headers/kmChartData.h"
#include "kmGraph/headers/kmGuiTimer.h"
#include "kmGraph/headers/kmChartHandler.h"
#include <QTimer>
#include <iostream>
#include <QMenu>
#include "kmConfigFile.h"
#include <QtGui>
#include <QGLWidget>
#include <QFileDialog>
#include <QPoint>

class kmWidgetChart : public QGLWidget
{
public:
    Q_OBJECT
public:
    explicit kmWidgetChart(QWidget* parent, int nWidth, int nHeight);
    virtual ~kmWidgetChart();
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    virtual void resizeEvent(QResizeEvent* event);
    //Overwrite from QWidget
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    friend class dialogKMConfigChart;
    friend class kmConfigFile;
public slots:
    virtual void ShowContextMenu(const QPoint& pos);
public:
    kmChartHandler* m_pChartHandler;
protected:
    QMenu mymenu;
    virtual void onDraw();
    virtual void drawAxis();
    virtual void drawXAxis();
    virtual void drawYAxis();
    virtual void drawDropPins();
    virtual void drawMarkPoints();
    virtual void drawRuler();
    virtual void drawListRuler();
    virtual void drawMouseZoomCrop();
    virtual void drawChart();
    virtual void drawChart_TimeLines();
    virtual void drawChart_FixedLines();
    virtual void drawChart_FixedLines_2();
    virtual void drawChart_XYLines();
    virtual void drawLegend();
    virtual void saveImage();
    virtual void saveImageAs();
    virtual void saveImage(string strFile);
    virtual void showHideWidgetControl() {}
    virtual void hideWidget(){}

    void zoomDynamicY(float scale, float orgY);
    void moveUp(float);
    void moveDown(float);
    virtual void zoomInAxisX(); //Zoom +
    virtual void zoomOutAxisX(); //Zoom -
    virtual void drawSelectAxis();
    virtual void zoomToFitX();
    virtual void zoomToFitY();
    virtual void handleZoomCrop();
    virtual void handleDrag();

    bool removeDroppedPin(float deltaX, float deltaY);
    bool addDroppedPin();

    void addMarkPoint(float x, float y);
    void removeMarkPoint(float x, float y);
    void removeAllMarkPoints();
    void resetTimeLineColor();
    /*
     * utility functions
    */
    void setGLData(float* arr, int element, float glX, float glY);
    void convertGl2Value(float glX, float glY, float& valueX, float& valueY);
    void convertValue2Gl(float valueX, float valueY, float& glX, float& glY);
    bool findClosestElement(std::vector<float>& listData, float minValue, int& minElement, int&begin, int& end);
    void addRuler(bool viewX, bool viewY);
    void removeAllRuler();
    void cutLineBetween2Rulers();
    void cutLineFromLeft();
    void cutLineFromRight();

    void cutLineFromLeft_Mouse();
    void cutLineFromRight_Mouse();
public:
    virtual void handleSaveDataToFile(char* fileName);
    virtual void handleSaveDataToCSV(char* fileName, bool bJustVisibleLine);
    virtual void saveDataToFile();
    virtual void saveAsDataToFile(bool isOnlyVisibleLine = false);
    virtual void openDataFromFile();
    virtual void openCSVFile();
    virtual void saveDataToCsvFile(bool bJustVisibleLine);

    /*
     * save and load configuration file (Set for show/hide lines)
    */

    virtual void saveConfigFile();
    virtual void loadConfigFile();
    virtual void saveAsConfigFile();
    virtual void openFromConfigFile();
    virtual void defaultConfig();
//    virtual void handleSaveConfigFile(const char* fileName);
//    virtual void handleLoadConfigFile(const char* fileName);

    virtual void handleSaveConfigFile(std::ofstream& file);
    virtual void handleLoadConfigFile(std::ifstream& file);
    void squareChart();
    /*
     * autogenerate color for visible line,
    */
    void autoGenerateColor();
    /*
     * Down  the DataRate
    */
    void downDataRate(int rate);
    void setAutoScale(bool val){m_pChartHandler->m_bEnableAutoScale = val;}
    void autoScale();
    virtual void resetTimeLine();
    virtual void refreshLines();

    void setHeight(int height) { m_pChartHandler->m_nHeight = height; }
    void setWidth(int width) { m_pChartHandler->m_nWidth = width; }
    void changeColor(string name, float* color);
    void setChartLenght(int nVal) { m_pChartHandler->m_nChartLenght = nVal; }
    void setAxisXMax(float valX);
    void setAxisXMinMax(float valMin, float valMax);
    void setAxisYMinMax(float valMin, float valMax);
    float* getColor(int); //1:blue - 2:green - 3:gray  - 4:red - 5:yellow - Default:white
    virtual void setAxisXInform(float fMin, float fMax, float fNumOfBigPoint, float fNumOfSmallPoint, const char* sName, float fOrg = -0.98, float fOrgOffset = 0.05 );
    virtual void setAxisYInform(float fMin, float fMax, float fNumOfBigPoint, float fNumOfSmallPoint, const char* sName, float fOrg = -0.98, float fOrgOffset = 0.05 );
    /*
     * limit the size of grapth lines
    */
    void setLitmittedLineSize(int limitSize);
    void enableLimitLineSize(bool bEnable);
    void updateData();
    bool isUpdateFromChart() {return m_pChartHandler->m_bUpdateDataFromChart;}
    void setUpdateDataFromChart(bool bVal) { m_pChartHandler->m_bUpdateDataFromChart = bVal; }
    void limitChartLenght(int nVal) { m_pChartHandler->m_chartData.m_nLimitedSize = nVal; }

    void setWidgetName(const std::string& name);
    std::string getWidgetName();
    kmChartLine* addReservedLine(void* pData, string name, kmDataType type = kmData_float, float scale = 1.0, float offset = 0.0);
    kmChartLine* addTimeLineFromReserved(kmChartLine* pLine);
    kmChartLine* addTimeLine(void* pData, float* color, string name, kmDataType type = kmData_float, float scale = 1.0, float offset = 0.0);
    kmChartLine* addTimeLine(void* pData, string name, kmDataType type = kmData_float, float scale = 1.0, float offset = 0.0);
    kmChartLine* addXYLine(void* pDataX, void* pDataY, float* color, string name, kmDataType typeX = kmData_float, kmDataType typeY = kmData_float, float scaleX = 1.0, float scaleY = 1.0, float minX = -1000, float maxX = 1000, float minY = -1000, float maxY = 1000, float offsetX = 0.0, float offsetY = 0.0);
    kmChartLine* addXYLine(void* pDataX, void* pDataY, string name, kmDataType typeX = kmData_float, kmDataType typeY = kmData_float, float scaleX = 1.0, float scaleY = 1.0, float minX = -1000, float maxX = 1000, float minY = -1000, float maxY = 1000, float offsetX = 0.0, float offsetY = 0.0);
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
    void removeAllLine();
    void removeLine(string name);
    void enableLine(int index, bool bEnable);
    kmChartLine* getLine(string name);
    kmChartLine* getLine(int idx);
    /*
    */
    void setupWidgetStyle(kmWidgetStyle style) { m_pChartHandler->setupWidgetStyle(style); }

    bool isPauseTimeLine() { return m_pChartHandler->m_bPauseTimeLine; }
    void pauseTimeLine(bool bPause);
    void hideAllLine();
    /*
     * getMapData
    */
    std::map<int,kmChartLine* >& getLineMap() { return m_pChartHandler->m_chartData.m_mapChart;}
//    kmChartData& getChartData(kmChartData& chartData) { return m_pChartHandler->m_chartData;}
    kmLineType getChartType() { return m_pChartHandler->m_eChartType; }
    void setChartType(kmLineType type) { m_pChartHandler->m_eChartType = type; }

    void setViewPointIcons(bool bVal) { m_pChartHandler->m_bViewPointIcons = bVal; }
    bool isViewPointIcons() { return m_pChartHandler->m_bViewPointIcons;}

    void setViewLineIcons(bool bVal) { m_pChartHandler->m_bViewLineIcons = bVal; }
    bool isViewLineIcons() { return m_pChartHandler->m_bViewLineIcons;}

    kmIcon* addIcon(kmIcon icon);
    kmLineIcon* addLineIcon(kmLineIcon icon);
    kmIcon* getIcon(string name);
    kmIcon* getIcon(int index);
    kmLineIcon* getLineIcon(string name);
    kmLineIcon* getLineIcon(int index);

    /*
     * Limit the data Range, sothat if data is out of range then do not update Data
    */
    void setLimitDataRange(float minX, float maxX, float minY, float maxY) { m_pChartHandler->m_chartData.m_fUnderLimitX = minX; m_pChartHandler->m_chartData.m_fUperLimitX = maxX;
                                                                         m_pChartHandler->m_chartData.m_fUnderLimitY = minY; m_pChartHandler->m_chartData.m_fUperLimitY = maxY;}
    void setLimitDataRangeX(float minX, float maxX) { m_pChartHandler->m_chartData.m_fUnderLimitX = minX; m_pChartHandler->m_chartData.m_fUperLimitX = maxX;}
    void setLimitDataRangeY(float minY, float maxY) { m_pChartHandler->m_chartData.m_fUnderLimitY = minY; m_pChartHandler->m_chartData.m_fUperLimitY = maxY;}
};

#endif // KMwidgetChart_H
