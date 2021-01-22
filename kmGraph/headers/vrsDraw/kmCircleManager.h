/*
 * drawCircle.h
 *
 *  Created on: Jan 24, 2015
 *      Author: kytv
 */

#ifndef KMDRAWCIRCLE_H_
#define KMDRAWCIRCLE_H_

#include <map>
#include <math.h>
#define NUMOFPOINT_CIRCLE_NORMAL	50
#define NUMOFPOINT_CIRCLE_SMOOTH	100
#define NUMOFPOINT_CIRCLE_SMOOTHEST	150

//#define NUMOFPOINT_CIRCLE_NORMAL	1000
//#define NUMOFPOINT_CIRCLE_SMOOTH	1000
//#define NUMOFPOINT_CIRCLE_SMOOTHEST	1000

using namespace std;

class circleData {
public:
    circleData(int nNumofPoint) 
	{
        m_nNumOfPoints = nNumofPoint;
        m_fPoints = new float[3*m_nNumOfPoints];
        for(int i = 0; i < m_nNumOfPoints; i++){
            m_fPoints[3*i] = cos(2*M_PI/m_nNumOfPoints*i);
            m_fPoints[3*i + 1] = sin(2*M_PI/m_nNumOfPoints*i);
            m_fPoints[3*i + 2] = 0.0;
        }
    };

    ~circleData() {
        delete [] m_fPoints;
    };
private:
    int		m_nNumOfPoints;
    float*	m_fPoints;
public:
    virtual void draw(float x, float y, float fRadius, float fLineWidth, float color[3]);
    virtual void draw(float x, float y, float fRadius, float fLineWidth, float color[3],  float alpha);
    virtual void draw(float x, float y, float fRadiusX, float fRadiusY, float fLineWidth, float color[3]);
    virtual void draw(float x, float y, float fRadiusX, float fRadiusY, float fLineWidth, float color[3],  float alpha);

    virtual void draw_fill(float x, float y, float fRadius, float fLineWidth, float color[3]);
    virtual void draw_fill(float x, float y, float fRadius, float fLineWidth, float color[3],  float alpha);
    virtual void draw_fill(float x, float y, float fRadiusX, float fRadiusY, float fLineWidth, float color[3]);
    virtual void draw_fill(float x, float y, float fRadiusX, float fRadiusY, float fLineWidth, float color[3],  float alpha);
};

class kmCircleManager{
private:
    kmCircleManager();
public:
    virtual ~kmCircleManager();
public:
    static kmCircleManager*	getInstance() {
        static kmCircleManager instance;
		return &instance;
	}

	circleData*	getCircle(int numOfPoints);

	void drawCircle(float x, float y, int numOfPoint, float fRadius, float fLineWidth, float color[3]);
    void drawCircle_real(float x, float y, int numOfPoint, float fRadiusX, float fRadiusY, float fLineWidth, float color[3]);
    void drawCircle_real(float x, float y, float fRadiusX, float fRadiusY, float fLineWidth, float color[3]);

    void drawCircle_fill(float x, float y, float fRadius, float fLineWidth, float color[3]);
    void drawCircle_real_fill(float x, float y, float fRadiusX, float fRadiusY, float fLineWidth, float color[3]);
    void drawCircle_fill(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);
    void drawCircle_real_fill(float x, float y, float fRadiusX, float fRadiusY, float fLineWidth, float color[3], float alpha);

	void drawCircle(float x, float y, int numOfPoint, float fRadius, float fLineWidth, float color[3], float alpha);
	void drawCircle(float x, float y, float fRadius, float fLineWidth, float color[3]);
	void drawCircle(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);

	void drawCircle(float x, float y, int numOfPoint, float fRadius, float fLineWidth, float color[3], float fScale, bool bEnableZoom);
	void drawCircle(float x, float y, int numOfPoint, float fRadius, float fLineWidth, float color[3], float alpha, float fScale, bool bEnableZoom);

	void drawCircle(float x, float y, float fRadius, float fLineWidth, float color[3], float fScale, bool bEnableZoom);
	void drawCircle(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha, float fScale, bool bEnableZoom);

	void drawCircleNormal(float x, float y, float fRadius, float fLineWidth, float color[3]);
	void drawCircleNormal(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);
	void drawCircleSmooth(float x, float y, float fRadius, float fLineWidth, float color[3]);
	void drawCircleSmooth(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);
	void drawCircleSmoothest(float x, float y, float fRadius, float fLineWidth, float color[3]);
	void drawCircleSmoothest(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);
protected:
	std::map<int, circleData*>	m_mapCircle;
};


inline kmCircleManager* circleManager() {
    return kmCircleManager::getInstance();
}
#endif /* KMDRAWCIRCLE_H_ */
