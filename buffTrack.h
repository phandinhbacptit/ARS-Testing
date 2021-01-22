/*
 * buffTrack.h
 *
 *  Created on:
 *      Author:
 */

#ifndef BUFFTRACK_H_
#define BUFFTRACK_H_

#include "globals.h"
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
//#include "Tracking/baseAlgorimth.h"
//#include "Tracking/Manager.h"
#include "boost/thread/mutex.hpp"

#define TRACKID_START					1000

struct IdentifyTarget {
    int a;
};
using namespace std;

class buffTrack
{
public:
	buffTrack();
	~buffTrack();
	static void setGlXy(float x, float ox, float y, float oy);
	static vector<int> getTrajIDs();
	static int getTrajCount();
	static int getTrajID(int idx);
	static int getTrajLen(int idx);
	static float getTrajX(int idx);
	static float getTrajY(int idx);
	static float* getTrajXYZ(int idx);
	static float* getTrajXYZReal(int idx);
	static VectorXy getTrajXY(int idx);
	static float getTrajV(int idx);
	static float getTrajHeading(int idx);
	static POINT_T getTrajRACov(int idx);
	static int getTrajTimeout(int idx);
	static L2TRACK_OBJ_REPORT_T getTrajReport(int idx);
	static bool isTrackAlive(int idx);
	static bool* getTrackColorIsWhite(int idx);
	static TARGET_T getTrajType(int idx);

	static int newTrack(int id = -1, bool bNotify = true);
	static void delTrack(int id, bool bNotify = true);
	static void updateTimeout(int id, int timeout);
	static void updateTrackData(int id, double realx, double realy, double x, double y, double v, bool imm, L2TRACK_OBJ_REPORT_T trajReport0, bool isSendVQ = false, bool isEstimated = true, bool bNotify = true);

	static int getFreeTrackID();
	static float* getTrajVelocityHistory(int idx);
    static void setIdentifyTarget(int id, IdentifyTarget it);
	static IdentifyTarget getIdentifyTarget(int id);

	static float getCurGLPosX(int idx);
	static float getCurGLPosY(int idx);
//	static void setFileRecordName();
	void enableRecord(bool enable);
	static void clearAll();

	static void setIdTop(int idx, int idtop, bool notify = true);
	static int getIdTop(int idx);
public:
	static bool						instanceFlagBT;
	//TRACK DATA
	static map<int, int>			mapFreeTrackID;
	static int						freeTrackIDCurr;
	static L2DATA_T					trajDataBuff;
	static vector<int>				trajIDs;
	static float					glScaleX;
	static float					glScaleY;
	static float 					glOffsetX;
	static float					glOffsetY;
	static int						g_CountToWriteRecord;
	bool 	getHide(int& traj0){return false;}

	static boost::mutex 					m_lock;
//	static void lock() { m_lock.lock(); }
//	static void unlock() { m_lock.unlock(); };

	static void lock();
	static void unlock();
};

#endif /* BUFFTRACK_H_ */
