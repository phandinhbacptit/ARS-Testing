#ifndef KMguiTimer_H
#define KMguiTimer_H

#ifndef _WINDOWS
#include "rutil/rtime.h"
#endif
class kmGuiTimer
{
public:
    kmGuiTimer(float fTimeStep);
    void run();
    /*
     * unit is second
    */
    bool isDoneStep() { return m_bIsDoneStep; }
    float getTimeStep() { return m_fTimeStep; }
    void setTimeStep(float step) { m_fTimeStep = step; }
    float getCurrentTime() { return m_fTotalTimeStandart; }
    float getTotalTime() { return m_fTotalRealTime; }
    float getRunningTime();
    float getOutsideTimePRI() { return m_fOutsideTimePRI; }
    void resetTimer();
    double getNowTime_InSecond();
    float getRealCurrentStep(){ return m_fRealCurrenttep; }
    double getTimeNowInSecond();
private:
#ifndef _WINDOWS
    rtime::TimeStamp m_tBegin;
    rtime::TimeStamp m_tNow;
    rtime::TimeStamp m_tPrev;
    rtime::TimeStamp m_tOutSide;
#endif

	double m_dTimeBegin;
	double m_dTimeNow;
	double m_dTimePrev;
	double m_dTimeOutSide;
    /*
     * InSecond
    */
    //Fix step time
    float m_fTimeStep;
    //curTime - prevTime
    float m_fRealCurrenttep;
    float m_fCompensateTime;
    bool m_bIsDoneStep;
    float m_fTotalTimeStandart;
    float m_fTotalRealTime;
    float m_fOutsideTimePRI;
};

#endif // KMguiTimer_H
