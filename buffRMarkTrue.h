/*
 * buffRMarkTrue.h
 *
 *  Created on: Dec 18, 2011
 *      Author: CuongVT
 */

#ifndef BUFFRMARKTRUE_H_
#define BUFFRMARKTRUE_H_

//#include <QMutex>
#include <boost/thread.hpp>
#include "globals.h"

#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
class GroupCenter
{
public:
	int m_azi;
	int m_r;
	float m_x;
	float m_y;
	rtime::TimeStamp m_timeAppear;
	int noOfMark;
	int aziDiff;
	float m_xStart;
	float m_yStart;
	float m_xStop;
	float m_yStop;
	int fd;
	int fdMin;
	int fdMax;
	int id;
	int power;
	bool isMain;
	GroupCenter() {
		m_azi = -1;
		m_r = -1;
		m_x = 0;
		m_y = 0;
		isMain = false;
	};
	GroupCenter(int azi, int r) {
		m_azi = azi;
		m_r = r;
	}
public:
	double liveTime()
	{
		return (double)(rtime::Clock().now().getSeconds() - m_timeAppear.getSeconds())*pow(10.0, 3) + (rtime::Clock().now().getNanoseconds() - m_timeAppear.getNanoseconds())*pow(10.0, -6);
	}
};

typedef queue<GroupCenter> QueueGroupCenter;

typedef deque<GroupCenter> DeQueueGroupCenter;
class buffRMarkTrue{
public:
	buffRMarkTrue();
	~buffRMarkTrue();
	static int getAndEmptyRMBTLen();
	static L2MARK_P_V getDataToTmp(int rMBTLen);
	static void pop(int rMBTLen);
	static void push(int id, int azi, int r, int pulses, int fd, int fdMax, int fdMin, int aziDiff);
	static void pushMark(int id, int azi, int r, int power, int fd);
public:
	static bool instanceFlagBRMT;
	static L2MARK_P_V rawMarkBuffTrue;
	static int rawMarkBuffTrueLen;
public:
	static QueueGroupCenter m_queueGroupCenters;
public:
	static void ClearOldGroupCenters();
	static QueueGroupCenter GetGroupCenters();
	static void ClearGroupCenters();
	static GroupCenter getGroupCenterByClick(float tx, float ty, rtime::TimeStamp ttime);
	static void getListGC(float x1, float y1, float x2, float y2, std::vector<GroupCenter>& listOut);

	static std::vector<GroupCenter> getListGroupCenter();
	static std::vector<GroupCenter> m_listGroupCenter;
	static std::map<int, MARK_DISPLAY_T>	m_mapGroupCenter;
	static void setMainGroupCenter(int range, int azi);
    //static void setTarget(int range, int azi);
    static void setTarget(int range, float azi);
	static void removeTarget();
	static GroupCenter m_Target;
	static bool m_bIsFoundTarget;
};

#endif /* BUFFRMARKTRUE_H_ */
