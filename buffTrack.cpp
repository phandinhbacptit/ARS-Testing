/*
 * buffTrack.cpp
 *
 *  Created on: Dec 18, 2011
 *      Author: CuongVT
 */
#include "buffTrack.h"
#include <algorithm>
#include <set>
#include <QTime>
#include <qdatastream.h>
#include <qbytearray.h>
#include <qbuffer.h>
#include "threadProcessBuff.h"

using namespace std;
int g_numDeletedTrackNoiseGrid = 0;
int g_totalTrackCount = 0;

bool buffTrack::instanceFlagBT = false;
map<int, int> buffTrack::mapFreeTrackID;
int	buffTrack::freeTrackIDCurr = TRACKID_START;
L2DATA_T buffTrack::trajDataBuff;
vector<int>	buffTrack::trajIDs;
//1.0 / (RANGE_MAX2), 0.0f, 1.0 / (RANGE_MAX2), 0.0f
float buffTrack::glScaleX = 1.0 / (RANGE_MAX2);
float buffTrack::glScaleY = 1.0 / (RANGE_MAX2);
float buffTrack::glOffsetX = 0.0f;
float buffTrack::glOffsetY = 0.0f;
int	 buffTrack::g_CountToWriteRecord = 0;

#define MAX_NUM_LOOP_LOST_SEND_TO_VQ 	3
#define COUNT_TO_WRITE_RECORD	5

volatile static bool g_bReceivedAllTrack = false;
boost::mutex buffTrack::m_lock;
//volatile bool buffTrack::g_bReceivedAllTrack = false;
buffTrack::buffTrack()
{
	int i;
	mapFreeTrackID.clear();
	trajIDs.clear();
	mapFreeTrackID.clear();
	for(i = 0; i < SA_MAX_TRACK_ID; i++) mapFreeTrackID.insert(pair<int, int>(i + TRACKID_START, i + TRACKID_START));
	freeTrackIDCurr = SA_MAX_TRACK_ID + TRACKID_START;
}

buffTrack::~buffTrack(){
	instanceFlagBT = false;
}

void buffTrack::setGlXy(float x, float ox, float y, float oy){ glScaleX = x; glScaleY = y; glOffsetX = ox; glOffsetY = oy; };
vector<int> buffTrack::getTrajIDs(){
	return trajIDs;
};
int buffTrack::getTrajCount(){ return trajIDs.size(); };
int buffTrack::getTrajID(int idx)
{
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajid;

	return -1;
};
int buffTrack::getTrajLen(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajlen;

	return -1;
};
//float buffTrack::getTrajX(int idx){ return (trajDataBuff[idx].trajxyz[3*trajDataBuff[idx].trajlen - 3] - glOffsetX)/glScaleX; };
//float buffTrack::getTrajY(int idx){ return (trajDataBuff[idx].trajxyz[3*trajDataBuff[idx].trajlen - 2] - glOffsetY)/glScaleY; };
float buffTrack::getTrajX(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajxyz[3*trajDataBuff[idx].trajlen - 3];

	return -1.0;
};
float buffTrack::getTrajY(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajxyz[3*trajDataBuff[idx].trajlen - 2];

	return -1.0;
};
float* buffTrack::getTrajXYZ(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajxyz;

	return NULL;
};
float* buffTrack::getTrajXYZReal(int idx){

	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajrealxyz;

	return NULL;
};
VectorXy buffTrack::getTrajXY(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajReport.xy;

	VectorXy xy;
	return xy;
};
float buffTrack::getTrajV(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajv;

	return -1;
};
float buffTrack::getTrajHeading(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return toAngleVTC(itFind->second.trajReport.heading);

	return -1;
};

POINT_T buffTrack::getTrajRACov(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return make_pair(itFind->second.trajReport.roR, trajDataBuff[idx].trajReport.roA);

	return POINT_T();
};
int buffTrack::getTrajTimeout(int idx)
{
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajtimeout;

	return -1;
};
L2TRACK_OBJ_REPORT_T buffTrack::getTrajReport(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajReport;

	return L2TRACK_OBJ_REPORT_T();
};
TARGET_T buffTrack::getTrajType(int idx){
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.trajType;

	return TARGET_T();
};

bool buffTrack::isTrackAlive(int idx){
	if(trajDataBuff.find(idx) != trajDataBuff.end()) return true;
	return false;
};
float buffTrack::getCurGLPosX(int idx)
{
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.curGLPosX;

	return -1;
};
float buffTrack::getCurGLPosY(int idx)
{
	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
	if( itFind != trajDataBuff.end())
		return itFind->second.curGLPosY;

	return -1;
};
IdentifyTarget buffTrack::getIdentifyTarget(int idx){

//	L2DATA_T::iterator itFind = trajDataBuff.find(idx);
//	if( itFind != trajDataBuff.end())
//		return itFind->second.identifyTarget;

	return IdentifyTarget();
}
int buffTrack::newTrack(int id, bool bNotify)
{
//	//std::cout << "newTrack: " << id << endl;
//	g_totalTrackCount++;

//	L2DATA_OBJ_T l2D;
//	l2D.trajlen = 0;
//	l2D.trajid = id;
//	l2D.trajidtop = 0;
//	l2D.trajidrec = id;
//	l2D.trajtimeout = 0;
//	l2D.identifyTarget = IT_Consumer;
//	l2D.trajType = TG_UNDEFINED;

//	lock();
//	trajDataBuff.insert(L2DATA_P(id, l2D));
//	trajIDs.push_back(id);
//	unlock();
	return id;
};
void buffTrack::delTrack(int idx, bool bNotify){

	printf("%s TRACK Deleted: ID=%d\n", QTime::currentTime().toString("[hh:mm:ss]").toStdString().c_str(), idx);
	std::cout << "buffTrack::delTrack: " << trajDataBuff.size() << "; "<< trajIDs.size() << endl;

	lock();
	int trajIdRec = trajDataBuff[idx].trajidrec;
	vector<int>::iterator tIDit = find(trajIDs.begin(), trajIDs.end(), idx);
	trajDataBuff.erase(idx);
	unlock();
	if(tIDit != trajIDs.end())trajIDs.erase(tIDit);
	mapFreeTrackID.insert(pair<int, int>(freeTrackIDCurr, freeTrackIDCurr));freeTrackIDCurr++;
	TRACK_REC_OBJ_T tmp;
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime ( &rawtime );
//	tmp.id = idx - TRACKID_START;
	tmp.id = trajIdRec;
	tmp.type = 0;
	tmp.status = 0; // delete track
	tmp.time[0] = timeinfo->tm_hour;
	tmp.time[1] = timeinfo->tm_min;
	tmp.time[2] = timeinfo->tm_sec;
	tmp.time[3] = timeinfo->tm_mday;
	tmp.time[4] = timeinfo->tm_mon + 1;
	tmp.time[5] = timeinfo->tm_year + 1900;
	tmp.data[0] = 0.0; 		/* x */
	tmp.data[1] = 0.0;
	tmp.data[2] = 0.0;
	tmp.v		= 0.0;
	tmp.roR		= 0.0;
	tmp.roA		= 0.0;
	tmp.heading = 0.0;
	tmp.filterState = fsCV;
	tmp.trajTimeOut = 0;
};

void buffTrack::updateTimeout(int id, int timeout){
	L2DATA_T::iterator it = trajDataBuff.find(id);
	it->second.trajtimeout = timeout;
};

void buffTrack::updateTrackData(int idx, double realx, double realy, double x, double y, double v, bool imm, L2TRACK_OBJ_REPORT_T trajReport0, bool isSendVQ, bool isEstimated, bool bNotify)
{
	int aziDegree = trajReport0.azimuth * 360.0 / (2*M_PI);
	int rangeKm = trajReport0.range * 300.0 / 2000.0;

	lock();
	int len = trajDataBuff[idx].trajlen;
	if(len >= MAX_TRACK_LENGTH) return;
	trajDataBuff[idx].trajxyz[3*len] 			= x;						 	//x
	trajDataBuff[idx].trajxyz[3*len + 1] 		= y; 							//y
	trajDataBuff[idx].trajxyz[3*len + 2] 		= 0.0; 		  					//z
	trajDataBuff[idx].trajrealxyz[3*len] 		= realx; 						//realx
	trajDataBuff[idx].trajrealxyz[3*len + 1] 	= realy; 						//realy
	trajDataBuff[idx].trajrealxyz[3*len + 2] 	= 0.0; 		  					//realz
	trajDataBuff[idx].trajv = v*RANGE_DIFF_1T;									//v[m/s]
	trajDataBuff[idx].trajVelocityHistory[len] = v*RANGE_DIFF_1T;
	trajDataBuff[idx].trajReport = trajReport0;
	trajDataBuff[idx].isWhite[len] = isEstimated;

	trajDataBuff[idx].curGLPosX = (float)realx/2000;
	trajDataBuff[idx].curGLPosY = (float)realy/2000;
	trajDataBuff[idx].trajType = trajReport0.trajType;
	trajDataBuff[idx].trajlen++;
	unlock();
	static set<int> deletedIds;

//	TRACKHAND_OBJ_T th;
//	th.a = trajReport0.azimuth * 360.0 / (2*M_PI);
//	th.r = trajReport0.range * 300.0 / 2000.0;
//	th.id = idx;
//	th.time = rtime::Clock().now();
//	th.type = tHDel;
//	Manager::instance()->setManualTrackingMode(MTM_DeleteTarget);
//	float range = th.r * BaseAlgorimth::KmToMeter;
//	float angle = th.a / BaseAlgorimth::RadToDeg;
//	Point manualPosition = BaseAlgorimth::polarToDecart(range, rtracker::toAngle(angle));
//	Manager::instance()->setPositionManualTracking(manualPosition);
//	cout << "NoiseGrid DelTrack: " << idx << "\t(" << th.a << ", " << th.r << ")" << endl;
//
//	if(deletedIds.find(idx) == deletedIds.end())
//	{
//		g_numDeletedTrackNoiseGrid++;
//		deletedIds.insert(idx);
//	}
}

int buffTrack::getFreeTrackID(){
	int freeID = -1;
	if(mapFreeTrackID.size() > 0){
		freeID = mapFreeTrackID.begin()->first;
		mapFreeTrackID.erase(freeID);
	}
	return freeID;
}

bool* buffTrack::getTrackColorIsWhite(int idx)
{
	if(trajDataBuff.find(idx) != trajDataBuff.end())
		return trajDataBuff[idx].isWhite;

	return false;
}

void buffTrack::enableRecord(bool enable)
{
//	flag_recording = enable;
}

void buffTrack::clearAll(){
//	for(int i = 0; i < trajDataBuff.size(); i++){
//		mapFreeTrackID.insert(pair<int, int>(freeTrackIDCurr, freeTrackIDCurr));freeTrackIDCurr++;
//	}

	lock();
	trajDataBuff.clear();
	trajIDs.clear();
	unlock();
}

//chi duoc gan 1 lan
void buffTrack::setIdTop(int idx, int idtop, bool bNotify){
//	if(bNotify){
//		if(configContainer.ENABLE_AUTO_SYNC){
//			socketServant servant(configContainer.IP_CORE_SERVER, configContainer.PORT_CORE_BACKDOOR);
//			if(servant.connect()){
//				std::cout << RED << "buffTrack::setIdTop Connect CORE success"<< idx << "; "<< idtop << RESET_COLOR << endl;
//
//				BYTE_T header;
//				int nLenghtMsg = 3;
//				StreamOut oStream;
//				DataSerializer sr(oStream.stream());
//				sr << idx;
//				sr << idtop;
//				QByteArray byteArray = oStream.data();
//				BYTE_T body(byteArray.constBegin(), byteArray.constEnd());
//
//				nLenghtMsg = 3 + body.size();
//				header.push_back(AssignTopMessage);
//				header.push_back(nLenghtMsg >> 8);
//				header.push_back(nLenghtMsg);
//
//				body.insert(body.begin(), header.begin(), header.end());
//				servant.sendCmd(body);
//
//			}else{
//				std::cout << RED << "Connect CORE failed" << RESET_COLOR << endl;
//			}
//		} else {
//			L2DATA_T::iterator it = trajDataBuff.find(idx);
//			if(it != trajDataBuff.end()){
//				if(it->second.trajidtop > 0) return;//chi nhap 1 lan
//				it->second.trajidtop = idtop;
//				it->second.trajidrec = (idtop << 22) + it->second.trajid;
//				m_xPrinter.xcout() << "setIdTop: " << idx << "\t" << idtop << "\t" << it->second.trajidrec << endl;
//			}
//		}
//	}
//	else {
//		L2DATA_T::iterator it = trajDataBuff.find(idx);
//		if(it != trajDataBuff.end()){
//			if(it->second.trajidtop > 0) return;//chi nhap 1 lan
//			it->second.trajidtop = idtop;
//			it->second.trajidrec = (idtop << 22) + it->second.trajid;
//			m_xPrinter.xcout() << "setIdTop: " << idx << "\t" << idtop << "\t" << it->second.trajidrec << endl;
//		}
//	}
}

float* buffTrack::getTrajVelocityHistory(int idx)
{
	if(trajDataBuff.find(idx) != trajDataBuff.end())
		return trajDataBuff[idx].trajVelocityHistory;

	return NULL;
}

int buffTrack::getIdTop(int idx){
	L2DATA_T::iterator it = trajDataBuff.find(idx);
	if(it != trajDataBuff.end()) return it->second.trajidtop;
	return -1;
}

void buffTrack::setIdentifyTarget(int id, IdentifyTarget it)
{
    //trajDataBuff[id].identifyTarget = it;
}

void buffTrack::lock()
{
	//threadProcessBuff::lock();
}
void buffTrack::unlock() {
	//threadProcessBuff::unlock();
};
