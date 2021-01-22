#ifndef VINCLUDES_H
#define VINCLUDES_H

#include <GL/glut.h>
#include <QtGui>
#include <iostream>
#include <math.h>
#include "guiRadar/headers/VrsImageManager.h"
#include <GL/glext.h>
#include "globals.h"
#include "globalVariable.h"
//#include "serialConnection.h"
//#include "hilConnection.h"
//#include "vraconnection.h"
//#include "positionerConnection.h"
//#include "hpaConnection.h"
//#include "kgc/kgcSerialPort.h"
//#include "threadSimulator.h"
//#include "threadAis.h"
//#include "socketServant.h"
//#include "widgetMain.h"
//#include "threadMulticastReceiver.h"
//#include "logCSV.h"
//#include "SrccConfigContainer.h"
//#include "threadSocket.h"
//#include "threadProcessBuff.h"
//#include "threadUdpServer.h"
//#include "tlv/tlvGenValueCore.h"
//#include "monopulseProcessor.h"
//#include "seekerUtils.h"
//#include "seekerVersion.h"
//#include "dspConfigData.h"
//#include "srccPPI.h"
//#include "lmccPPI.h"
//#include "widgetAScope.h"
//#include "widgetSecvo.h"
//#include "widgetEncoder.h"
//#include "widgetPowerSum.h"
//#include "widgetAOAAzi.h"
//#include "widgetSeekerPlayer.h"
//#include "widgetAOAElv.h"
//#include "SrccConfigContainer.h"
//#include "widgetView.h"
//#include "widgetconfig.h"
//#include "widgetGymbal.h"
//#include "widgetEpsilon.h"
//#include "widgetTarget.h"
//#include "widgetBite.h"
//#include "buffPlayback.h"
//#include "buffTrack.h"
//#include "buffVideo.h"
//#include "buffData.h"
//#include "DPBlock.h"
//#include "DPSerializer.h"
//#include "buffRMarkTrue.h"
//#include "buffMark.h"
//#include "kgc/SimpleNMEA.h"
//#include "tlvGenValueCore.h"
//#include "vrsTlvValues.h"
//#include "glog/logging.h"
//#include "tlv/tlvValue.h"
//#include "guiRadar/headers/DrawHelpers.h"
//#include "guiRadar/headers/VrsUtils.h"
//#include "kmGraph/headers/kmWidgetChart.h"
//#include <string>
//#include <boost/array.hpp>
//#include <boost/asio.hpp>
//#include <boost/thread.hpp>
//#include "AsynTCPClient.h"
//#include <vector>
//#include <ostream>
//#include "ais/vdm_parse.h"
//#include <GL/freeglut.h>
//#include <QApplication>
//#include <QDesktopWidget>
//#include <algorithm>
//#include <fstream>
//#include "DPVideo.h"
//#include "DPMarkPoints.h"
//#include "DPDelayCombiner.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <dirent.h>
//#include <QMessageBox>
//#include <QFileInfo>
//#include <QDir>
//#include "rawEditor.h"
//#include <qfiledialog.h>
//#include <QStringList>
//#include <QString>
//#include <QToolBar>
//#include "dialogaddversk.h"
//#include <QFileDialog>
//#include <QAction>
//#include <QSlider>
//#include <sstream>
//#include <QMenu>
//#include <QPixmap>
//#include "Stream.h"
//#include "socketPositioner.h"
//#include "threadReadRepeater.h"
//#include "threadTMS.h"
////#include "threadDspClient.h"
//#include "DPSerializer.h"
//#include "tlvUtils.h"
//#include "widgetMqp.h"
//#include "socketMQP.h"
//#include "threadDeviceManager.h"
//#include "vtimer.h"
//#include "widgetDecac3d.h"
//#include "widgetLab3D.h"
//#include "trackingloopmodel.h"
//#include "threadAutomationTest.h"
//#include "f1956.h"
//#include "apSimulator.h"
//#include "socketHexaPod.h"
//#include "threadUdpHexaPod.h"
//#include "widgetDrfm.h"
//#include "rawFileLogger.h"
//#include "monopulseSimulator.h"
//#include "hmc629.h"
//#include "widgetPTP.h"
//#include "socketptp.h"
//#include "threadReadTelemetryFile.h"
//#include "widgetconfigparam.h"
//#include "configtms.h"
//#include "widgetafcp.h"
//#include "DialogConfigcontrol.h"

//using namespace std;
//extern dspConfigData g_dspData;
//extern flashConfigDsp flashDsp;
//extern dspConfigData g_dspData_TMS;
//extern apSimulator g_apSimulator;
//extern globalVariable g_variable;
//extern flashconfigCtr flashCtr;

//extern threadSimulator*	g_threadSimulator ;
//extern threadProcessBuff*	g_threadProcessBuff ;
//extern threadReadTelemetryFile*	g_pThreadReadTele;
//extern widgetMain*			g_pWgMain ;
//extern threadSocket 		g_threadSocket ;
//extern threadAutomationTest g_threadAutoTest;
//extern threadUdpServer		g_threadUdp ;
//extern threadUdpHexaPod		g_threadUdpHexapod ;
//extern threadMulticastReceiver g_threadMulticast;
//extern threadReadRepeater   g_threadRepeater;
//extern threadTMS            g_threadTMS;
////extern threadDspClient      g_threadDspClient;
//extern threadDeviceManager            g_threadDeviceMng;
//extern configTMS            g_threadAutoFindConfigParameter;

//extern logCSV		g_threadLogCSV;
//extern SrccConfigContainer configContainer;
//extern TRACK_SEC_FILT_T	tRSecFilters;
//extern tlvGenValueCore 	g_tlvGenValue;
////extern positionerConnection*	g_pPositionerConnection ;
//extern socketPositioner*	g_pPositionerConnection ;
//extern socketHexaPod*	g_pHexaPodConnection_ERTT ;
//extern socketHexaPod*	g_pHexaPodConnection_API ;
//extern hilConnection*		g_pHilConnection ;
//extern vraconnection* g_pHilConnectionVRA;
//extern float	g_fHisMarkTime;
//extern kgcSerialPort* g_pISA ;
//extern kgcSerialPort* g_pHMR ;
//extern kgcSerialPort* g_pDRFM ;// drfm

//extern threadAis   g_threadAIS;
//extern hpaConnection*	g_pHPA300 ;
//extern kgcSerialPort* g_pHPA150 ;
//extern socketServant* g_pSocketXLTH ;
//extern socketServant* g_pSocketTRFS ;
//extern serialConnection* g_pRepeaterConnection ;
//extern monopulseProcessor g_monopulse;
//extern monopulseSimulator g_monopulseSim;
//extern socketServant*	g_pPLCTcpClient;
//extern bool g_bConnectPLCSuccess;
//extern seekerInform g_seekerInform;
//extern bool g_bReceiveRepeater;
//extern devicesValue g_deviceValues;

//extern widgetSeekerPlayer*	 	g_pWgSkPlayer ;
//extern srccPPI*	 			g_pWgSrccPPI ;
//extern srccPPI*	 			g_pWgZoom;
//extern lmccPPI*				g_pLmccPPI ;
//extern widgetControl* 			g_pWgControl ;
//extern widgetConfigDsp* 		g_pWgConfigDsp ;
//extern widgetSecvo*	 		g_pWgServo ;
//extern widgetTarget*			g_pWgTarget ;
//extern widgetAOAElv*			g_pWgAoA_Elev ;
//extern widgetAScope*			g_pWgAScope ;
//extern widgetPowerSum*			g_pWgPowerSum ;
//extern widgetAOAAzi*			g_pWgAOAAzi ;
//extern widgetView*             g_pWgView ;
//extern widgetConfig*           g_pWgConfig ;
//extern widgetGymbal*            g_pWgTrajectory ;
//extern widgetEpsilon*          g_pWgTimeLine1 ;
////extern widgetMonitor*            g_pWgMonitor ;
//extern widgetBite*               g_pWgBite;
////extern kmWidgetChart*            g_pWgZoomPPI ;
//extern kmWidgetChart*            g_pWgTimeLine2;
//extern widgetMQP*              g_pWgMQP;
//extern WidgetDecac3d*          g_pWgDecac3D;
//extern WidgetLab3D*            g_pWgLab3D;
//extern  widgetDrfm*            g_pWgwidgetDrfm;
////extern widgetControlMQP*        g_pWgControlMQP;
//extern DPSerializer __serializer;
//extern seekerValue   g_seeker;

////extern float g_body.latitude;
////extern float g_body.longitude;
//extern float           target_latitude;
//extern float           target_longitude;
//extern bool g_bCheckEncoder;
//extern bool g_bConnectMQPSuccess;

//extern bool g_bConnectRandSSuccess;
//extern bool g_bConnectKeysightSuccess;

//extern socketMQP* g_pMQPsocketConn;
//extern widgetPTP*              g_pWgPTP;
//extern socketPTP*   g_pKeysightN9936A14Connection;
//extern socketPTP*   g_pRSFsvr136Connection;
//extern widgetConfigParam*      g_pWgConfigParam;
//extern WidgetAFCP*             g_pWgAFCP;

//extern guidanceParam g_isaGuidance_Fire;
//extern guidanceParam g_isaGuidance_NED;
//extern missileState g_isaState;

//extern guidanceParam g_apGuidance;
//extern missileState g_apState;

//extern std::vector<glPoint> listTestTarget;
////extern bool g_bTestHeliCopter;
//extern bodyParams g_body;
//extern f1956 g_f1956;
//extern hmc629 g_hmc629;
//extern trackingLoopModel g_trackingModel;
#endif // VINCLUDES_H
