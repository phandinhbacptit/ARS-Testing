/*
 * globalVariable.h
 *
 *  Created on: Dec 20, 2014
 *      Author: kytv
 */

#ifndef GLOBALVARIABLE_H_
#define GLOBALVARIABLE_H_

#include "globals.h"
#include <math.h>
#include <string>
#include <iostream>
#include "buffRMarkTrue.h"
#include <vector>
#include <map>
#include <GL/gl.h>
//#include <qgl.h>
#include "guiRadar/headers/guiDefines.h"
#include "kmGraph/headers/kmWidgetChart.h"
using namespace std;

#define PLAYER_MODE_RAW		1
#define PLAYER_MODE_RECORD	2

enum ppiActive_t{
	ppi_srcc,
	ppi_lmcc
};

//enum stateChangeTRFS
//{
//    trfs_none,
//    trfs_configLoc,
//    trfs_loc_Zero,
//    trfs_loc_ZeroWait,
//    trfs_loc_ZeroFinish,
//    trfs_loc_Destination,
//    trfs_loc_DestinationWait,
//    trfs_loc_DestinationFinish
//};

enum stateChangeTRFS
{
    trfs_none,
    trfs_configLoc,
    trfs_connectTRFS,
    trfs_connectWait,
    trfs_stopServo,
    trfs_stopServoWait,
    trfs_setFullGate,
    trfs_setWaveForm,
    trfs_configLO2,
    trfs_configLO2Wait,
    trfs_loc_Zero,
    trfs_loc_ZeroWait,
    trfs_loc_ZeroFinish,
    trfs_loc_Destination,
    trfs_loc_DestinationWait,
    trfs_loc_DestinationFinish
};

enum heading_source {
    heading_manual,
    heading_isa,
    heading_ap,
    heading_hmr,
    heading_hil
};

enum gps_source {
    gps_manual,
    gps_isa,
    gps_ap,
    gps_simulation,
    gps_hil
};

enum eulerAngle_source
{
    eulerAngle_manual,
    eulerAngle_isa,
    eulerAngle_ap,
    eulerAngle_positioner,
    eulerAngle_hil
};

enum ppiView {
  ppi_2D,
    ppi_3D,
    ppi_lab
};

enum ps_trajectory {
    ps_sin_azi,
    ps_sin_elv,
    ps_sin_azi_elv,
    ps_azi,
    ps_elv,
    ps_azi_elv,
    ps_calib_azi,
    ps_calib_elv
};

enum homingViewerMode
{
    hm_fighting,
    hm_playbackRawFile,
    hm_playbackTelemetryFile
};

enum range_view {
    range_view_0km,
    range_view_5km,
    range_view_10km,
    range_view_15km,
    range_view_20km,
    range_view_30km,
    range_view_45km
};

enum waveForm
{
    wf_lfm,
    wf_bk3,
    wf_bk7,
    wf_bk13,
    wf_m63,
    wf_singlePulse,
    wf_singleTon
};

enum autochangeATT {
    autochangeATT_Simple,
    autochangeATT_AGC
};

enum searchingPriority
{
    prio_maxPower,
    prio_targetSize,
    prio_left,
    prio_right,
    prio_farest,
    prio_nearest
};

enum operationMode
{
    operationMode_Manual,
    operationMode_Fire,
    operationMode_AirPlane,
    operationMode_Hil,
    operationMode_TestDevice,
    operationMode_KCS_XX,
    operationMode_KCS_STH,
    operationMode_KCS_M2,
    operationMode_KCS_TKB,
    operationMode_KCS_TOP,
    operationMode_KCS_M1
};

enum tabWiget
{
    tab_main,
    tab_dsp,
    tab_servo,
    tab_config,
    tab_bite,
    tab_drfm
};

enum connectionMode {
    conn_GroundStation,
    conn_DownRate,
    conn_directEthernet
};

#define CTR_MOTIONPLAN_RIGHT_FIRST		0
#define CTR_MOTIONPLAN_ZICZAC			1
#define CTR_MOTIONPLAN_UP_FIRST			2
#define CTR_MOTIONPLAN_LEFT_FIRST		3
#define CTR_MOTIONPLAN_DOWN_FIRST		4

#define max_aoa_azimuth         4.5
#define max_aoa_elevation       4.5

class globalVariable {
public:
	globalVariable();
	virtual ~globalVariable();
public:
	float glCOLOR_BACKGROUND[3];
	float glCOLOR_AIR_ROUTE[3];
	float glCOLOR_AIR_CARF[3];
	float glCOLOR_DM_REGION[3];
	float glCOLOR_DM_BORDER[3];
	float glCOLOR_CIRCLE[3];
	float glCOLOR_SUB_CIRCLE[3];
	float glCOLOR_CIRCLE_OFFSET[3];
	float glCOLOR_OTHER[3];
	float glCOLOR_TEXT_COORDINATE[3];
	float glCOLOR_TEXT_DIADANH[3];
	float glCOLOR_TEXT_RADAR_CANHGIOI[3];
	float glCOLOR_TEXT_RADAR_DANDUONG[3];
	float glCOLOR_ENCODER[3];
	float glCOLOR_TARGET[3];
	float glCOLOR_TRIANGLE_FAN[3];
	float glCOLOR_MISSED_POINTS[3];
	float glCOLOR_TEXT_AXIS[3];

	float colorTarget_Friend[3];
	float colorTarget_Foe[3];
	float colorTarget_Sos1[3];
	float colorTarget_Sos2[3];
	float colorTarget_Alarm[3];
	float colorTarget_Undefined[3];

	float dataVideoPPI[2*4*AZIMUTH_SIZE*RANGE_MAX2];
	float colorVideoPPI[3*4*AZIMUTH_SIZE*RANGE_MAX2];

	static float dataVideoPPIPoint[2*AZIMUTH_SIZE*RANGE_MAX2];
	static float colorVideoPPIPoint[3*AZIMUTH_SIZE*RANGE_MAX2];
	static GLuint indices[4*(AZIMUTH_SIZE+4)*(RANGE_MAX2-1)];

    static float dataPowerSum[AZIMUTH_SIZE][RANGE_MAX2];
    static float dataPowerDiff[AZIMUTH_SIZE][RANGE_MAX2];
    static int dataDopler[RANGE_MAX2];

	static float powerSum[AZIMUTH_SIZE/2];
    static float powerDiff_Azi[AZIMUTH_SIZE/2];
    static float powerDiff_Elv[AZIMUTH_SIZE/2];
	static float powerReHor[AZIMUTH_SIZE/2];
    static float powerReVer[AZIMUTH_SIZE/2];
	static float errorSlopeAzi[AZIMUTH_SIZE/2];
	static float errorSlopeElv[AZIMUTH_SIZE/2];

//#define REPEATER
//	static float repeaterTrue[AZIMUTH_SIZE/2];
//	static float repeaterMeasured[AZIMUTH_SIZE/2];

#define REPEATER_SIZE	1500
	static float repeaterTrue[REPEATER_SIZE];
	static float repeaterMeasured[REPEATER_SIZE];

	static std::vector<float> vector_repeaterTrue;
	static std::vector<float> vector_repeater_Measured;

	static float currentRepeaterPosX;
	static float currentRepeaterPosY;
	static float currentMeasuredPosX;
	static float currentMeasuredPosY;

	static int rangeTracked;
	static int powerThres;
	static float dataHeatMapColor[8*64];
	static int colorHatMapSize;
	/*
	 * Monopulse: Angle of Arrival
	 * */
//	static float aoa_azimuth[8*(RANGE_MAX_CELL -1)];
//	static float aoa_elevation[8*(RANGE_MAX_CELL -1)];

	static int			nguongve;
	static float AScopeScale;

	//Encoder Angle: 0-->1023
	//int 		currentAziAngle;
	//int 		currentElevAngle;
	unsigned long 		m_nCurrentPlaying;
	int 		differentAngle;
	int 		northOffsetAngle;
	int 		baseEncodeAngle;
	int 		m_nPlayerMode;
	string 		m_strPlayFile;
	unsigned long	m_nRemainingTime;
	int 		m_nFindId;

	int			m_nMaxPower;
	int 		m_nMinPower;


	int			m_nPlayingRoundCount;
	bool		m_bDisplayHistory;
	ppiActive_t			m_nPpiActive;
	std::vector<GroupCenter*>	m_listSelectedGC;
	int			m_nPressedAzi;
	int			m_nPressedRange;
	int			m_nGroupMaxPower;
	static float colormapHeat[3*64];
	static float colormapHeatQuads[12*64];
    static bool 		m_bTestElevation;
    //static float m_fHeadhing;
//    static bool m_bEnableDrawHeadning;
//    static bool m_bEnableDrawDTMS;
//    static bool m_bEnableDrawVideo;
//    static bool m_bEnableDrawCluster;

	static float m_fGpsDistance;
    //static bool m_bViewTarget;
    static int m_nFirmwareVersion;
    static bool m_bViewPositioner;

	static bool m_bFpgaStarted;
	static float m_fPositionerAzi_Set;
	static float m_fPositionerElv_Set;

    static float m_fHexaPodAzi_Set;
    static float m_fHexaPodElv_Set;

	static int m_nSimulated_Range;
	static float isa_second;
	static float isa_week;
	static float isa_status;

    static float cr_grey[3];
    static float cr_red[3];
    static float cr_green[3];
    static float cr_yellow[3];
    static float cr_blue[3];
    static float cr_white[3];
    static float cr_cyan[3];
    static float cr_pink[3];
    static float cr_purple[3];
    static float cr_green2[3];
    static float cr_pink2[3];
    static float cr_red2[3];
    static float cr_blue2[3];
    static float cr_orange[3];

    static bool m_bDrawReElv;
    static bool m_bViewHILLamda;
    static float m_fDiffScale;

    static float m_fMaxPowerSum;
    static float m_fMaxPowerDiff;

    //Define Dynamic Range of RF Power
    const static float m_fMinRFPower;
    const static float m_fMaxRFPower;
    const static float m_fRFPowerRange;
    const static float m_fRFPowerOffset;

    static int m_nWaveForm;
    static int m_nPRI;
    static int m_nATT_70Mhz;
    static int m_nATT_1380Mhz;
    static int m_nPioSwRf;
    static bool m_bEnableLogRawFile;
    static bool m_bEnableLogCSV;

    static float ap_losRateY;
    static float ap_losRateZ;
    static float ap_vc;
    static float ap_range;
    static bool m_bAutoRotatePositioner;
    static bool m_bEnableBigGate;
    /*HEADING Source:
     * true: ISA
     * false: HMR
    */
    static heading_source m_eHeadingSource;

    /*GPS Source:
     * true: AutoPilot
     * false: ISA
    */
    static gps_source m_eGpsSource;

    /*
     * Hien thi tren man hinh SRCC (Isa, Ap, ...)
    */
    static eulerAngle_source m_eEulerAngle;
    /*
     * POSITIONER AUTORUN ORBIT
     *
    */
    static ps_trajectory m_ePsTrajectory;

    /*
     * TargetAngle(degree): Angle is calculate from GPS of Target
    */
    static float m_fTargetGpsAngle;

    static bool m_bDisplayGPSPath;

    /*
     * HPA MONITOR
    */
    static unsigned int hpa300_voltage;
    static unsigned int hpa300_current;
    static unsigned int hpa300_reflectpower;
    static unsigned int hpa300_forwardpower;
    static unsigned int hpa300_vswr;
    static unsigned int hpa300_temperature;
    static bool m_bConnectHIL;

    /*
     * OrgPulsePower
    */
    static float m_fOrgPulseSumPower;
    static float m_fOrgPulseDiffPower;

    static int m_nCurrentDoppler;
    static bool m_bViewWidgetControl;
    static bool m_bViewWidgetPower;
    static bool m_bViewWidgetTimeLine1;
    static bool m_bViewWidgetTracjectory;
    static bool m_bViewWidgetAScope;
    static bool m_bViewPPI;
    static bool m_bViewWidgetZoomPPI;
    static bool m_bViewWidgetTimeLine2;
//    static bool m_bViewListSkTarget;
//    static bool m_bViewListGpsTarget;
    static bool m_bViewBite;
    static bool m_nCurrentDisplay;

    static float m_fLamdaYRef;
    static float m_fLamdaZRef;
    static float m_fLosRateYRef;
    static float m_fLosRateZRef;
    static float m_fErrPsEncAzi;
    static float m_fErrPsEncElv;

    static float m_fMsgLoss;
    static int m_nMsgReceivedPerSecond;

    static bool m_bOnSearching1Mode;
    static bool m_bOnSearching2Mode;

    static ppiView m_ePPIView;
    static string m_strLogFileNamePrefix;
    static kmWidgetStyle m_eWidgetStyle;

    static homingViewerMode m_eHomingViewer;

    static float m_fErrLdaY;
    static float m_fErrLdaZ;

    static float m_fErrLRateY;
    static float m_fErrLRateZ;

    static float m_fMSELRateY;
    static float m_fMSELRateZ;

    static float m_fErrLRateY_Test;
    static float m_fErrLRateZ_Test;

    static float m_fErrEnc_Eps_Azi;
    static float m_fErrEnc_Eps_Elv;

    static float m_fErrGyrAngle_Eps_Azi;
    static float m_fErrGyrAngle_Eps_Elv;

    static float m_fErrGyrAngle_Enc_Azi;
    static float m_fErrGyrAngle_Enc_Elv;

    static float m_fErrPs_Eps_Azi;
    static float m_fErrPs_Eps_Elv;
    //static float m_fTargetHeading;
    static bool m_bSimulateAP;
    static range_view m_eRangeView;

    static int m_nGuiEarlyGate;
    static int m_nGuiLateGate;
    float m_fPeakPower;
    int m_nTagetRangeBin;
    std::map<int, std::string>  mapSeekerVersion;
    static bool m_bCheckPowerPeak;
    stateChangeTRFS m_eChangeTRFS;
    float m_fConfigTRFSRange;
    bool    m_bConfigTRFSSuccess;
    int m_nRangeInPeakPower;
    float m_fPowerInPeak;
    bool m_bConfigFreq;
    int m_nFreqControl;

    int m_nPlaybackYear;
    int m_nPlaybackMonth;
    int m_nPlaybackDay;
    int m_nPlaybackHour;
    int m_nPlaybackMinute;
    int m_nPlaybackSecond;
    int m_nPlaybackTime;
    bool m_bIsLoadPlaybackFile;

    bool USE_MQP;
    bool USE_AUTOTEST;
    bool USE_POSITIONER;
    bool USE_ISA;
    bool USE_AP;
    bool USE_HEXAPOD;
    bool USE_TRFS;
    bool USE_SEEKER;
    bool USE_VRA;
    bool USE_HIWL;
    bool USE_AIS;
    bool USE_HMR;
    bool USE_PTP;
    bool USE_DRFM;
    bool ENABLE_DRAW_WAYPOINTS;
    bool ENABLE_TURNON_HPA;
//    bool ENABLE_TEST_GYROSBIAS;
//    bool ENABLE_TEST_ATT;
public:
	void initialize();
	void releaseListGC();
};

#endif /* GLOBALVARIABLE_H_ */
