#include "vIncludes.h"

float           target_latitude = 21.0;
float           target_longitude = 105.0;
bool            g_bCheckEncoder = false;

apSimulator g_apSimulator;
dspConfigData g_dspData;
flashConfigDsp flashDsp;
dspConfigData g_dspData_TMS;
monopulseProcessor g_monopulse;
monopulseSimulator g_monopulseSim;
globalVariable g_variable;
flashconfigCtr flashCtr;

threadSimulator*	g_threadSimulator = NULL;
threadProcessBuff*	g_threadProcessBuff = NULL;
threadReadTelemetryFile*	g_pThreadReadTele = NULL;
widgetMain*			g_pWgMain = NULL;
threadSocket 		g_threadSocket;
threadUdpServer		g_threadUdp;
threadUdpHexaPod	g_threadUdpHexapod ;
threadMulticastReceiver g_threadMulticast;
threadReadRepeater   g_threadRepeater;
threadTMS           g_threadTMS;
//threadDspClient     g_threadDspClient;
threadDeviceManager g_threadDeviceMng;
threadAutomationTest g_threadAutoTest;
configTMS           g_threadAutoFindConfigParameter;

logCSV              g_threadLogCSV;
SrccConfigContainer configContainer;
TRACK_SEC_FILT_T	tRSecFilters;
tlvGenValueCore 	g_tlvGenValue;
socketPositioner*	g_pPositionerConnection = NULL;
socketHexaPod*	g_pHexaPodConnection_ERTT = NULL;
socketHexaPod*	g_pHexaPodConnection_API = NULL;
hilConnection*		g_pHilConnection = NULL;
vraconnection*		g_pHilConnectionVRA = NULL;
float               g_fHisMarkTime = 	10000.0;
kgcSerialPort*      g_pISA = NULL;
kgcSerialPort*      g_pHMR = NULL;
kgcSerialPort*      g_pDRFM = NULL;// drfm
threadAis           g_threadAIS;
hpaConnection*      g_pHPA300 = NULL;
kgcSerialPort*      g_pHPA150 = NULL;
socketServant*      g_pSocketXLTH = NULL;
socketServant*      g_pSocketTRFS = NULL;
serialConnection*   g_pRepeaterConnection = NULL;
socketServant*      g_pPLCTcpClient = NULL;
bool g_bConnectPLCSuccess = false;
bool g_bReceiveRepeater = true;

widgetSeekerPlayer*	 	g_pWgSkPlayer = NULL;
srccPPI*	 			g_pWgSrccPPI = NULL;
srccPPI*	 			g_pWgZoom = NULL;
lmccPPI*				g_pLmccPPI = NULL;
widgetControl* 			g_pWgControl = NULL;
widgetConfigDsp* 		g_pWgConfigDsp = NULL;
widgetSecvo*	 		g_pWgServo = NULL;
widgetTarget*			g_pWgTarget = NULL;
widgetAOAElv*			g_pWgAoA_Elev = NULL;
widgetAScope*			g_pWgAScope = NULL;
widgetPowerSum*			g_pWgPowerSum = NULL;
widgetAOAAzi*			g_pWgAOAAzi = NULL;
widgetView*             g_pWgView = NULL;
widgetConfig*           g_pWgConfig = NULL;
widgetGymbal*            g_pWgTrajectory = NULL;
widgetEpsilon*          g_pWgTimeLine1 = NULL;
//widgetMonitor*          g_pWgMonitor = NULL;
//kmWidgetChart*            g_pWgZoomPPI = NULL;
kmWidgetChart*            g_pWgTimeLine2 = NULL;
widgetMQP*              g_pWgMQP = NULL;
socketMQP*              g_pMQPsocketConn = NULL;
WidgetDecac3d*          g_pWgDecac3D = NULL;
WidgetLab3D*            g_pWgLab3D = NULL;
widgetBite*             g_pWgBite = NULL;
widgetDrfm*            g_pWgwidgetDrfm = NULL;
//widgetControlMQP*       g_pWgControlMQP = NULL;
widgetPTP*            g_pWgPTP =NULL;
widgetConfigParam*      g_pWgConfigParam = NULL;
WidgetAFCP*             g_pWgAFCP = NULL;

socketPTP*  g_pKeysightN9936A14Connection = NULL;
socketPTP*  g_pRSFsvr136Connection = NULL;

bool                    g_bConnectMQPSuccess = false;
bool                    g_bConnectRandSSuccess = false;
bool                    g_bConnectKeysightSuccess = false;

DPSerializer            __serializer;

guidanceParam           g_isaGuidance_Fire;
guidanceParam           g_isaGuidance_NED;
missileState            g_isaState;

guidanceParam           g_apGuidance;
missileState            g_apState;

std::vector<glPoint>    listTestTarget;
//bool                    g_bTestHeliCopter = false;

seekerInform            g_seekerInform;
devicesValue            g_deviceValues;
seekerValue             g_seeker;
bodyParams              g_body;
trackingLoopModel       g_trackingModel;
f1956                   g_f1956;
hmc629                  g_hmc629;
