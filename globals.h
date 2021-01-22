/*
 * globals.h
 *
 *  Created on:
 */

#ifndef GLOBALS_H____
#define GLOBALS_H____

#include <vector>
#include "boost/date_time/posix_time/posix_time.hpp"
using namespace std;

using boost::posix_time::ptime;
using boost::date_time::microsec_clock;


/* Kalman implementation */
#include "rtracker/rtracker_types.h"
#include "rtracker/rtracker_vector.h"
#include "rtracker/rtracker_coords.h"
#include "rtracker/rtracker_math.h"
#include "rtracker/rtracker_kalmanfilter.h"
#include "globalConstants.h"
#include "globalDigitalMap.h"
#include "globalConfigs.h"
using namespace rtracker;
#include <boost/asio.hpp>

#define 		TB_TIMEDIFF_UPDATE_TAMCHUM		0.5*SCAN_TIME*pow(10,3)/(1.0*AZIMUTH_SIZE)	// [ms]
//#define 		TB_TIMEDIFF_ACCEPT_TAMCHUM      20.0*SCAN_TIME*pow(10,3)/(360.0)//25.0*SCAN_TIME*pow(10,3)/(1.0*AZIMUTH_SIZE)	// [ms] 8 degree
#define 		TB_TIMEDIFF_ACCEPT_TAMCHUM      20.0*SCAN_TIME*pow(10,3)/(360.0)//25.0*SCAN_TIME*pow(10,3)/(1.0*AZIMUTH_SIZE)	// [ms] 8 degree
#define 		TB_TIMEDIFF_TIMEOUT_TAMCHUM		4.5*SCAN_TIME*pow(10,3)/(360.0)//12 azimuth
#define			TB_SAME_DISTANCE				0.5											// [cell - *150m]
//CONSTANTS THREAD ASSIGNMENT
#define 		SA_ELEVATION					5											// degree
//OLD
#define 		SCAN_TIME						3											// [s]

using boost::asio::ip::tcp;

#define		CURRENT_PTIME						(boost::date_time::microsec_clock<ptime>::local_time())
//#define		CURRENT_TIME_OFFSET(baseTime)		((CURRENT_PTIME - baseTime).total_milliseconds())
#define		CURRENT_TIME_OFFSET(baseTime)		((CURRENT_PTIME - baseTime).total_microseconds())

#define		CURRENT_TIME_OFFSET_IN_SECONDS(baseTime)		((CURRENT_PTIME - baseTime).total_microseconds() / 1000000)

//#define 	RTIME_DIFF_IN_MS(newTime, oldTime)	(newTime - oldTime).getSeconds()*pow(10, 3) + (newTime - oldTime).getMilliseconds() + (newTime - oldTime).getMicroseconds()*pow(10, -3)
#define 	RTIME_DIFF_IN_MS(newTime, oldTime)	(newTime - oldTime).getMilliseconds()

#define RED  							"\033[22;31m"
#define RESET_COLOR 					"\e[m"

//BYTE
typedef vector<unsigned char>					BYTE_T;
typedef vector<BYTE_T>							BYTE_2T;
//U32_BYTES
#define 		U32_FIRST_BYTE					0xff000000
#define 		U32_SECOND_BYTE					0x00ff0000
#define 		U32_THIRD_BYTE					0x0000ff00
#define 		U32_FOURTH_BYTE					0x000000ff

// PPIPlot
#define DegToRad								3.14159265/180.0
#define	 TimeScan								10//second

#define	 TIME_UPDATE							30//100//milisecond
#define TIME_REPORT								5000 //milisecond

typedef struct{
	float 										xppi0;
	float 										yppi0;
	float                                      	xra0;
	float										yra0;
	float 										p0;
	float                                       pe0;

	float 										x_75, x_150, x_300;
	float										y_75, y_150, y_300;
	float										xra_75, xra_150, xra_300;
}VIDEO_POINT_T;

typedef struct
{
	int azi;
	int r;
	bool isCmap;
	int	power;
	int fd;
} MARK_DISPLAY;
typedef vector<MARK_DISPLAY> MARK_DISPLAY_T;

typedef struct{
	int id;
	int azi;
	int range;
	int fd;
	int power;
} Hit;
typedef vector<Hit> HitVector;

typedef struct{
    int											range;
    int											a_start;		//BAT DAU TAM CHUM
    int											a_stop;			//KET THUC TAM CHUM
    int											fd;				//TAN SO DOPPLER
    int											key;            //tu khoa phan biet, vi du cap (a, fd)
    bool										processed;		//da thuc hien xong
    rtime::TimeStamp							time;
    rtime::TimeStamp							timeEnd;
    int 										pulses;
    int fdMax;
    int fdMin;
    MARK_DISPLAY_T								displayMarks;
    int 										m_markGroupId;
    HitVector									hits;
}L2MARK_OBJ_T;

typedef enum{
	TG_UNDEFINED = 0,
	TG_FRIEND,
	TG_FOE,
	TG_SOS1,
	TG_SOS2,
	TG_ALARM1
} TARGET_T;


typedef vector <L2MARK_OBJ_T>					L2MARK_T;
typedef pair <int, L2MARK_OBJ_T> 				L2MARK_P;
typedef vector <L2MARK_P>						L2MARK_P_V;

typedef enum{
	fsCV = 0,
	fsManuever
}FilterStateType;
typedef struct{
	VectorXy									xy;				//Target's lastest position
    CoordsWgs84									gps;			//Target's lastest gps
    CovarianceXy								xycov;
	rtracker::real								range, azimuth; //Target's range, azimuth
	VectorXy 									velocity;		//Target's velocity
	rtracker::real								heading, speed;	//Target's heading, speech
//	pair<real, real>							racov;
	rtracker::real								roR;
	rtracker::real								roA;
	FilterStateType								filterState;
	//iff data
	//target's type
	//conuntry's code
	TARGET_T									trajType;
}L2TRACK_OBJ_REPORT_T;

typedef enum{
	tsNewTrack = 0,
	tsConfirm,
	tsMiss
}TrackStateType;
typedef struct{
    ConstantVelocityKf*							cvKF;	   		//CV, CA KALMAN FILTER
    ImmXyFilter*								immF;	   		//IMM WITH CV & AU MODEL
    ImmXyFilterv2*								immFv2;			//IMM WITH CV & TU & TR MODEL
    rtime::TimeStamp							startTime;		//TRACK'S START TIME
    int 										trajID;			//TRACK'S ID
    int											numLoop;		//NUMBER OF PASSED ARRIVAL
    int											missed;			//NUMBER OF MISSED ARRIVAL
    TrackStateType 								state;			//0: new track, 1: confirmed, 2 predicted
    //L2TRACK_OBJ_REPORT_T						trajReport;
    rtime::TimeStamp							estimateTime;	//ESTIMATE's TIME
    rtime::TimeStamp							predictTime;	//PREDICT'S TIME
    //DEBUG - DELTA RANGE - SMOOTH ANGLE
    rtracker::real								deltaR;			//MOVED RANGE FOR DETECT SLOW
    rtracker::real								smoothA;		//SMOOTHED ANGLE SAVE IN
    FilterStateType								filterS;

    //NEWS FOR OPTIMAL
    L2TRACK_OBJ_REPORT_T						trajReport;
    bool										imm;

    //223 tracking
    bool										init;			//IS THIS TRACK CONFIRM?
    bool										confirm;		//IS THIS TRACK CONFIRM?
    int											confspecs[3];

    //store history of beginning track
    vector<L2TRACK_OBJ_REPORT_T>				initialHistoryTrajectory;

    //
    bool										fake;
    int											fd;
    TARGET_T									trajType;
}L2TRACK_OBJ_T;

typedef map <int, L2TRACK_OBJ_T> 				L2TRACK_T;
typedef pair <int, L2TRACK_OBJ_T>   			L2TRACK_P;

typedef struct{
	VectorXy 									xY;				//MARK'S XY POSITION
	Matrix<2, 2> 								xYCov;			//MARK'S XX COVARIANCE
	rtime::TimeStamp							time;			//MARK'S TIME
	int											fd;
}GNN_MARK_OBJ_T;
typedef map<int, GNN_MARK_OBJ_T>				GNN_MARK_T;
typedef pair<int, GNN_MARK_OBJ_T>				GNN_MARK_P;

typedef vector<vector<rtracker::real> >			VALUEMATRIX_T;
typedef struct{
	int											gnnClusterID;	//CLUSTER'S ID
	vector<int>									trackIDs;		//INSIDE TRACKS'S ID
	vector<int>									markIDs;		//INSIDE MARKS'S ID
	rtime::TimeStamp							clusterTime;	//CLUSTER'S CREATE TIME
}GNN_CLUSTER_OBJ_T;
typedef map<int, GNN_CLUSTER_OBJ_T>				GNN_CLUSTER_T;
typedef pair<int, GNN_CLUSTER_OBJ_T>			GNN_CLUSTER_P;

typedef struct{
	float										trajxyz[3*MAX_TRACK_LENGTH];		//TRACK'S FILTERED POSITION
	float										trajrealxyz[3*MAX_TRACK_LENGTH];	//TRACK'S ORIGNAL POSITION
	float										trajv;								//TRACK'S VELOCITY
	int											trajlen;							//TRACK's LENGTH
	int											trajid;								//TRACK's ID
	int 										trajtimeout;						//TIMEOUT PERIOD
	L2TRACK_OBJ_REPORT_T						trajReport;							//TRACK'S REPORT DATA (XY, COV, V, HEADING)
	bool										isWhite[MAX_TRACK_LENGTH];
	float										trajVelocityHistory[MAX_TRACK_LENGTH];
	//bo sung them id da top va id de ghi vao sao luu
	//da top dung de gui
	unsigned int								trajidtop;//10 bit
	unsigned int								trajidrec;//32 bit
    //IdentifyTarget								identifyTarget;

	float										curGLPosX;
	float										curGLPosY;
	bool										hide;
	TARGET_T									trajType;
}L2DATA_OBJ_T;

typedef map<int, TrackStateType>				TRACKID_OBJ_T;

typedef map<int, L2DATA_OBJ_T>					L2DATA_T;
typedef pair<int, L2DATA_OBJ_T>					L2DATA_P;


typedef struct{
	unsigned int								id;
	unsigned char								type;
	bool										status;
	unsigned int								time[6];	// hour; minute; second; day; month; year (moc thoi gian 1900)
	float										data[3];
	//unsigned char								globalStt;  // RADAR STATUS
	float										v;
	float										roR;
	float										roA;
	float										heading;
	FilterStateType								filterState;
	int											trajTimeOut;
	//TARGET_T									trajType;
}TRACK_REC_OBJ_T;
typedef vector<TRACK_REC_OBJ_T>					TRACK_REC_T;

typedef struct{
	unsigned int								id;
	bool										status;
	unsigned char								time[3];
	float										data[3];
	//unsigned char								globalStt;  // RADAR STATUS
	float										v;
	float										roR;
	float										roA;
	float										heading;
	FilterStateType								filterState;
}TrackRc;


typedef struct{
	unsigned int								id;
	unsigned char 							 	type;
	bool										status;
	unsigned char								time[3];
	float										data[3];
}TrackRc_old;

typedef enum{
	ANTEN_PHASE =0,
	ANTEN_SPEED,
	FREQ,
	MODULATION_SIGNAL,
	PAM_POWER,
	NEAR_THRESHOLD,
	FAR_THRESHOLD,
	SIGNAL_POWER,
	EXTEND_PARA,
	GPS_LOCATION,
	NEW_RECORD_SESSION = 255
}PARA_RECORD;


struct bodyParams {
    float roll;
    float pitch;
    float yaw;
    float p;
    float q;
    float r;
    float latitude;
    float longitude;
    float height;
    float vX;
    float vY;
    float vZ;
    float aX;
    float aY;
    float aZ;
    float attackAngle;

    bodyParams() {
        latitude = 21.0484;
        longitude = 106.8913;
    }
};

//BUFF REPORT PART
#define 		VIDEO_SIZE_EXPECTED				(5 + RANGE_MAX2*2)*AZIMUTH_SIZE
typedef struct{
	unsigned int 								loopID;
	rtracker::real								rateTrans;
	rtracker::real								videoLost;
	rtracker::real								dataLost;
	unsigned int								newMark;
	unsigned int								totalMark;
	unsigned int 								newTrack;
	unsigned int								totalTrack;
	unsigned int								newFA;
	unsigned int								totalFA;
	map<int,L2TRACK_OBJ_REPORT_T> 				trackInfo;
}REPORT_OBJ_T;
typedef vector<REPORT_OBJ_T>					REPORT_T;


//DEFINE FSM (FINITE STATE MACHINE) FOR
typedef boost::shared_ptr<tcp::socket> 			boost_socket_ptr;
typedef enum{
	ssStop = 0,
	ssRetry,
	ssConnected
}SocketStateType;

typedef enum{
	ssServerRetry = 0,
	ssServerListen
}SocketServerStateType;

typedef enum{
	mpRadarOff = 0,
	mpInitial,
	mpStandby,
	mpReady,
	mpRotate,
	mpOperate,
	mpOffline,
	mpSimReady,
	mpSimRotate,
	mpSimOperate
}MainProgramStateType;


//// FORWARD TO SRCC
typedef struct {
	unsigned char 	commandID;
	unsigned short 	id;
}NEW_TRACK_STR;

//typedef vector<NEW_TRACK_STR> NEW_TRACK_VEC_T;

typedef struct {
	unsigned char 	commandID;
	unsigned short 	id;
	float 			realx;
	float 			realy;
	float 			x;
	float 			y;
	float 			v;
	float			h;
	float			ror;
	float			roa;
}UPDATE_TRACK_STR;

//typedef vector<UPDATE_TRACK_STR> UPDATE_TRACK_VEC_T;

typedef struct {
	unsigned char 	commandID;
	unsigned short 	id;
}DEL_TRACK_STR;

//typedef vector<DEL_TRACK_STR> DEL_TRACK_VEC_T;

typedef struct {
	unsigned char 	commandID;
	unsigned short 	id;
	unsigned char 	timeout;
}TIMEOUT_STR;

//typedef vector<TIMEOUT_STR> TIMEOUT_VEC_T;


typedef struct {
	unsigned char		commandID;
	unsigned short		length;
	BYTE_T				msg;
}CONTROL_STR;

typedef struct {
	unsigned char		commandID;
	float 				socketRate;
	float 				videoLost;
	unsigned short		newMark;
	unsigned short		totalMark;
	unsigned short 	newTrack;
	unsigned short		totalTrack;
	unsigned short		newFA;
	unsigned short		totalFA;
}REPORT_STR;


typedef struct {
	unsigned char  	commandID;
	unsigned short 	length;
	unsigned char   	newTnum;
	unsigned char		updateTnum;
	unsigned char		timeoutTnum;
	unsigned char		delTnum;
	BYTE_2T				msg;
}TRACK_MSG_T;

typedef enum {
    FightingMessage = 18,
    SeekerInformMessage = 19,
    PowerMessage = 0xA4,
    DevicesMessage = 0xA5
}TypeMessage;

#define NEW_MSG_LENGTH			sizeof(NEW_TRACK_STR)
#define UPDATE_MSG_LENGTH		sizeof(UPDATE_TRACK_STR)
#define TIMEOUT_MSG_LENGTH		sizeof(TIMEOUT_STR)
#define DELETE_MSG_LENGTH		sizeof(DEL_TRACK_STR)
#define REPORT_MSG_LENGTH		sizeof(REPORT_STR)

typedef struct {
	unsigned char  	commandID;
	unsigned short 	length;
	unsigned char   	newTnum;
	unsigned char		updateTnum;
	unsigned char		timeoutTnum;
	unsigned char		delTnum;
}TRACK_MSG_T_2;


typedef enum{
//	tANTEN = 1,   ////
//	tPROCESSOR = 2,
//	tRECEIVER1,
//	tRECEIVER2,
//	tSW,
//	tGENERATOR,
//	tTAPLO,
////	tDDS = 3,
////	tPOWER,
////	tTRANSMITTER,
////	tRECEIVER,
//	tCORE,
//	tPAM
////	tGLOBAL
	HWID_ANTEN = 1,
	HWID_SIGNAL_PROCESSING = 2,
	HWID_RECEIVER_1 = 3,
	HWID_RECEIVER_2 = 4,
	HWID_HF_SWITCH = 5,
	HWID_GENERATOR_1 = 6,
	HWID_CONSOLE_TAPLO_1 = 7,
	HWID_CORE = 8,
	HWID_POWER_AMPLIFIER = 9,
	HWID_GENERATOR_2 = 10,
	HWID_CONSOLE_TAPLO_2 = 11,
	HWID_PHASE = 12,
	HWID_SIGNAL_PROCESSING_2 = 13,
	HWID_GPS = 14,
	HWID_CCM = 15,
	HWID_RECEIVER_3 = 16,
	HWID_GENERATOR_3 = 17,
	HWID_IFF = 18
}HARDWARE_ID;


/*HWID_ANTEN = 1,
HWID_SIGNAL_PROCESSING = 2,
HWID_RECEIVER_1 = 3,
HWID_RECEIVER_2 = 4,
HWID_HF_SWITCH = 5,
HWID_GENERATOR = 6,
HWID_CONSOLE_TAPLO = 7,
HWID_CORE = 8,
HWID_POWER_AMPLIFIER = 9*/

typedef enum{
	tALL = 1,
	tPAM = 2,
	tRX1 = 3,
	tRX2 = 4,
	tDSP1 = 5,
	tDSP2 = 6,
	tTrack1 = 7,
	tTrack2 = 8,
	tREC,
	tVQ,
	tVIKO,
	tCore,
	tSQL,
	tWeb,
	tHFSW,
	tGen1,
	tGen2,
	tChienDau,
	tHuanLuyen,
	tGiamSat,
	tCaiDat
}HWBLOCK_ID;

typedef enum{
	hwDISCONNECTED =0,
	hwOK,
	hwERROR,
	hwWANING
}HARDWARE_STATUS;

typedef struct{
	unsigned short			port;
	HARDWARE_STATUS			status;
}SERVICE_OBJ_T;

typedef struct{
	HARDWARE_ID				id;
	string					ip;
	vector<SERVICE_OBJ_T>	service;
}HARDWARE_OBJ_T;

typedef enum{
	tThresDetect = 1,
    tThresCFAR = 2,
    tMTI = 3,
    tObjectOut = 4,
    tCode = 5,
//  tTest = 6, //TESTING
    tThresDetect2 = 6,
//    tWorking = 7,
//    tThresDetect3 = 8,
//    tThresDetect4 = 9

    tTxSector = 9,//cau hinh phat re quat tren DDS
    tDoplerBank = 11,
//    tThresDetect4 = 9
    tThresDetect3 = 13,
    tThresDetect4 = 14
}TypeDSPCtr;//control

typedef map<HARDWARE_ID, BYTE_T> CONTROL_BLOCK_T;
typedef pair<HARDWARE_ID, BYTE_T> CONTROL_BLOCK_P;

typedef map<int, L2MARK_OBJ_T>	RAW_MARK_BUFF_T;
typedef map<int, RAW_MARK_BUFF_T>	L2MARK_BUFF_T;
typedef enum{
	ctrNONE =0,
	ctrANTEN_PHASE,
	ctrANTEN_SPEED,
	ctrFREQ,
	ctrMODULATION_SIGNAL,
	ctrPAM_ONOFF,
	ctrNEAR_THRESHOLD,
	ctrFAR_THRESHOLD,
	ctrSIGNAL_POWER
}CTR_CONFIRM;

//
enum HFS{
	HFS_111 = 0x0000,
	HFS_112 = 0x63C0,
	HFS_121 = 0x4CC0,
	HFS_122 = 0xEFC0,
	HFS_211 = 0x3F00,
	HFS_212 = 0x9CC0,
	HFS_221 = 0x73C0,
	HFS_222 = 0xD000
};

//bam ban tu dong bang tay
typedef enum{
	// Binh thuong
	tHNone = 0,

	// Bam tu dong
	tHAdd,
	tHAssign,
	tHDel,

	// Sector filter
	tSFAdd,
	tSFDel,

	// Do khoang cach
	tCDMea,

	// Simulate track
	tSTrAdd,
	tSTrDel,

	// Simulate sector noise
	tSSecAdd,
	tSSecDel,


	// Vung bat tot (Good Area)
	tGAAdd,
	tGADel,


	// Phat theo re quat
	tRQ1_start,
	tRQ1_end,
	tRQ2_start,
	tRQ2_end

}TypeTrackHand;

typedef struct{
	rtime::TimeStamp	time;
	TypeTrackHand 		type;
	int			  		id;
	float		  		r;
	float 		  		a;
}TRACKHAND_OBJ_T;
typedef vector<TRACKHAND_OBJ_T> TRACKHAND_T;

typedef struct{
	int 	x;
	int		y;
}MOUSE;


template <class T>
struct MOUSE_T{
	T	x;
	T	y;
	void operator = (const MOUSE_T& src){
		x = src.x;
		y= src.y;
	}
	MOUSE_T(const MOUSE_T& src){
		x = src.x;
		y= src.y;
	}
	MOUSE_T(){
		x= 0;
		y = 0;
	}
};
//RADAR OPERATION MODE
typedef enum{
	opModeIdle = 0,		//pause all threads
	opModeDat,			//start socket, pause simulator
	opModeRec, 			//pause socket, simulator
	opModeSim, 			//start simulator , pause socket
	opModeDatRot,		//rotate antena
	opModeDatTxOn,		//on pam
	opModeRecPlay,		//play rec
	opModeSimPlay,
	opModeErr
}TypeOperatorMode;


typedef struct{
	float 		startR;
	float		stopR;
	float 		startA;
	float 		stopA;
	int 		direction; //+/-1
}TRACK_SEC_FILT_OBJ_T;
typedef map<int, TRACK_SEC_FILT_OBJ_T> TRACK_SEC_FILT_T;

typedef struct{
	float 			nx, nxDeg, nxMin, nxSec;
	float			ey, eyDeg, eyMin, eySec;
	int				yy, nn, dd, hh, mm, ss;//time
	vector<string>	rdIPs;
	vector<string> 	schIPs;
	string 			schPort;
	vector<string> 	schNets;
	vector<string>	schGWs;
}GPS_TIME_SCH_T;

typedef vector<unsigned char>	BYTE_VECTOR;

typedef struct{
	string macAddr;
	string netMask;
	string gwIp;
	string portSer;
	string switchIP;
	string switchPort;
	int mucastID;//0-1-2-//
}BLOCK_NET_INFO_T;
typedef map<string, BLOCK_NET_INFO_T> BLOCK_NET_T;

typedef struct{
	string netND1;
	string netND2;
	string mdmDial;
	string mdmADSL;
	string optND1;
	string optND2;
	string optVIKO;
	string optVQ;
}BKN_INFO_T;


#define UTF8_QSTRING(text)	QObject::trUtf8(text)

typedef enum
{
	VDT_Track = 1,
	VDT_Mark = 2
}VRS_DATA_TYPE;

typedef struct{
	int 	vid;
	string  name;
//	QString uname;
	string	network;
	string  netmask;
	int		mask;
	string  gateway;
	int 	port;
	int		servertype;
	int 	datatype;
	int 	tcpip;
	int 	protocol;
}OCON_OBJ_T;
typedef map<string, OCON_OBJ_T> OCON_T;
typedef pair<string, OCON_OBJ_T> OCON_P;

enum TrackSyncCommand
{
	TSC_NewTrack,
	TSC_DelTrack,
	TSC_UpdateTrack,
	TSC_AllTrack,
	TSC_SelFilter,
	TSC_ClearScreen,
	TSC_AssignTop
};

struct glPoint {
    float x;
    float y;
};

#define IMAGE_RADAR_STATION			"icons/icon_tramradar.png"
#define IMAGE_AIR_PLANE				"icons/icon_sanbay.png"
#define IMAGE_LOGO					"logo.png"
#define IMAGE_LEGEND				"legend.png"
#define IMAGE_BACKGROUND			"bak_1080x1080.png"

#define HOMING_RADAR
#ifdef HOMING_RADAR
	#define			RANGE_MAX_CELL					300 //(True RANGE MAX VALUE OF DSP)
	#define 		MAX_MARK_HISTORY_VIEW_TIME		1500000.0
	#define			RANGE_MAX_MET					45000.0
    #define			RANGE_MAX2						295
#else
	#define			RANGE_MAX_CELL					2400 //(True RANGE MAX VALUE OF DSP)
	#define 		MAX_MARK_HISTORY_VIEW_TIME		1500000.0
	#define			RANGE_MAX_MET					300000.0
	#define			RANGE_MAX2						400//400//430//502//500//250//2000//250
#endif

#define COLOR_MAP_HEAT
//LMCC
#define			MAX_RANGE_REGION_1				5	// 50 km
#define			MAX_RANGE_REGION_2				15	// 150 km
#define			RANGE_NEAR_FAR					110
#define 		AZIMUTH_SIZE					1024
#define 		AZIMUTH_SIZE_RAW				8192

//#define SK_STATUS_STARTING			0x00000000
//#define SK_STATUS_READY				0x00010000
//#define SK_STATUS_SEARCHING1		0x00030000
//#define SK_STATUS_SEARCHING2		0x00070000
//#define SK_STATUS_DETECTED			0x000F0000
//#define SK_STATUS_TRACKED			0x001F0000
//#define SK_STATUS_SLEEP				0x003F0000

//#define SK_STATUS_STARTING			0x00000000
//#define SK_STATUS_READY				0x00010000
//#define SK_STATUS_SEARCHING1		0x00030000
//#define SK_STATUS_SEARCHING2		0x00070000
//#define SK_STATUS_DETECTED			0x000F0000
//#define SK_STATUS_TRACKED			0x001F0000
//#define SK_STATUS_SLEEP				0x003F0000

#define SK_STATUS_STARTING			0x00000000
#define SK_STATUS_READY				0x00010000
#define SK_STATUS_SEARCHING1		0x00030000
#define SK_STATUS_SEARCHING2		0x00070000
#define SK_STATUS_DETECTED_S1			0x002F0000
#define SK_STATUS_TRACKED_S1			0x004F0000
#define SK_STATUS_SLEEP_S1				0x003F0000
#define SK_STATUS_DETECTED_S2			0x000F0000
#define SK_STATUS_TRACKED_S2			0x001F0000
#define SK_STATUS_SLEEP_S2				0x006F0000

#define SK_STATUS_TESTING			0x00080000
#define SK_STATUS_FINISHTEST		0x00090000

#define DV_STATUS_HPA				0x00000008
#define DV_STATUS_LO1				0x00000004
#define DV_STATUS_LO2				0x00000002
#define DV_STATUS_SECVO				0x00000001

#define AP_CMD_SEARCHING1			0x00000001
#define AP_CMD_SEARCHING2			0x00000002
#define AP_CMD_SEFTTEST_WITH_TARGET				0x00000004
#define AP_CMD_SEFTTEST_WITHOUT_TARGET				0x00000008
#define AP_CMD_SEFTTEST_HPA				0x00000010

#define MQP_WIDTH_VIEW   4.0
#define MQP_HEIGHT_VIEW  1.5

#define MQP_WIDTH   4.0
#define MQP_HEIGHT  2.0

enum motionDirection
{
    direction_none,
    direction_left,
    direction_right,
    direction_up,
    direction_down
};

#endif /* GLOBALS_H____ */
