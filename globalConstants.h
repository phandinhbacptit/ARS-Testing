/*
 * globalConstants.h
 *
 *  Created on: Apr 25, 2012
 *      Author: CUONGVT2
 */

#ifndef GLOBALCONSTANTS_H_
#define GLOBALCONSTANTS_H_

//CONSTANTS THREAD SOCKET
#define 		TS_RX_BUFF_SIZE					22000
//CONSTANTS THREAD PROCESS
#define 		TB_TIMEDIFF_UPDATE_TAMCHUM		0.5*SCAN_TIME*pow(10,3)/(1.0*AZIMUTH_SIZE)	// [ms]
#define 		TB_TIMEDIFF_ACCEPT_TAMCHUM      20.0*SCAN_TIME*pow(10,3)/(360.0)//25.0*SCAN_TIME*pow(10,3)/(1.0*AZIMUTH_SIZE)	// [ms] 8 degree
#define 		TB_TIMEDIFF_TIMEOUT_TAMCHUM		4.5*SCAN_TIME*pow(10,3)/(360.0)//12 azimuth
#define			TB_SAME_DISTANCE				0.5											// [cell - *150m]
//CONSTANTS THREAD ASSIGNMENT
#define 		SA_ELEVATION					5											// degree
//OLD
#define 		SCAN_TIME						10											// [s]
#define 		TIME_REMOVEMARKHIS				500											// [s]

#define			TRACK_DELETE_TIMEOUT			5.25*SCAN_TIME  								// [s]
#define         MARK_DELETE_TIMEOUT             12.5
#define 		VIDEO_TIMEOUT					2   										// [s]
#define         UPDATE_TIME						9.625//9.75   								// [s]
//NEW
#define 		SA_GNN_SOLVE_TIME				3.6*pow(10, 4)/36.0							// [ms]
#define 		SA_MAX_TRACK_ID					500//250											// maximum track per scan
#define 		SA_MAX_MARK_ID					1000										// maximum mark per scan
#define			SA_ANTENNA_ROTATION_SPEED		6											// []
#define			SA_SCAN_TIME					60 / SA_ANTENNA_ROTATION_SPEED				// [ms]
#define         SA_INSIDE_NEWTRACK				0.5*UPDATE_TIME*pow(10, 3)//5.0*pow(10, 3)
#define         SA_INSIDE_CONFIRM				0.5*UPDATE_TIME*pow(10, 3)
#define 		SA_INSIDE_CONFIRM_HAND			5.0*pow(10, 3)
#define 		SA_UPDATE_TIME					UPDATE_TIME*pow(10, 3)						// [ms]
#define 		SA_MARK_DELETE_TIMEOUT			MARK_DELETE_TIMEOUT*pow(10, 3)				// [ms]
#define 		SA_TRACK_DELETE_TIMEOUT			TRACK_DELETE_TIMEOUT*pow(10, 3)				// [ms]

#define			GL_VIDEO_THRESHOLD_MIN			POWER_MAX_VALUE / 8

#define			MAX_TRACK_LENGTH				1000//250//200
#define			GATE_SIZE_M2_P005				5.99
#define 		GATE_AXIS_FACTOR				0.95
#define			ALLOWED_ERROR					0.01
#define			NO_ASSIGN_PENALTY				0.0
#define 		DEFAULT_ASSIGN_VALUE 			100.0
#define 		IMPOSSIBLE_ASSIGN_VALUE 		-100.0
#define			SPEED0_THRESHOLD				1.0											// [m/s]
#define			SCAN_LOOP_ACCEPT				1

#define 		GRAPH_RANGE						4
#define 		CYCLE_DENSITY					360*3
#define			PPI_BUFF_SIZE					5*RANGE_MAX2*AZIMUTH_SIZE
#define 		PPI_DRAW_SIZE					RANGE_MAX2*AZIMUTH_SIZE / 8
#define         PPI_60_DEGREE					AZIMUTH_SIZE / 6
#define			PPI_ANGLE_MIN					AZIMUTH_SIZE - PPI_60_DEGREE
#define			PPI_TIME_FUNC					40											// [ms] 1s/25 = 40 ms
#define 		POWER_MAX_VALUE  				(1024*1024*512)//(1024*1024*16)
#define 		POWER_MIN_VALUE					1
#define 		E_CONSTANT						1000000.0
#define         POWER_MAX_THRESHOLD             120//512.0//384.0//32//130//256//210//256//288//320//512
//mimimum value to be draw
#define			POWER_GAIN						3.0

#define			RAW_MARK_SIZE					150
#define			RANGE_DIFF_1T					150.0   									// [m]
#define 		WINDOW_REAL_SCALE				0.8
#define 		WINDOW_HEIGHT_OFFSET			40
#define 		SILDER_MAX_VALUE				64

#define			BR_MAX_HISTORY					500
#define 		BR_VIDEO_MSG_SIZE				505

#define			MIN_NUM_MARKS					5//8
#define 		WV_TRACKTABLE_ROW				11
#define			PLAYBACK_SLIDER_LENGTH			200
#define			WAIT_CONFIRM_TIME				7000
#define 		POSITION_RESOLUTION 			10000  //	FOR TUTORIAL VIDEO

//TRACKING SECTOR FILTER
#define 		TRACK_SEC_FILTER_MAX			8

//cac tham so cho 3 vong/phut, anten quay cham
//lien quan den phan ve video - ben lmcc
//lien quan den phan tracking ben srcc
#define 		TB_TIMEDIFF_UPDATE_TAMCHUM_SLOW	0.5*SCAN_TIME_SLOW*pow(10,3)/(1.0*AZIMUTH_SIZE)	// [ms]
#define 		TB_TIMEDIFF_ACCEPT_TAMCHUM_SLOW 20.0*SCAN_TIME_SLOW*pow(10,3)/(360.0)			// [ms] 8 degree
#define 		SCAN_TIME_SLOW					20												// [s]
#define			TRACK_DELETE_TIMEOUT_SLOW		5.25*SCAN_TIME_SLOW  							// [s]
#define			MARK_DELETE_TIMEOUT_SLOW		22.5												// [s]
#define         UPDATE_TIME_SLOW				19.25//19.0//9.75
#define			SA_ANTENNA_ROTATION_SPEED_SLOW	3												// [s]
#define			SA_SCAN_TIME_SLOW				60 / SA_ANTENNA_ROTATION_SPEED					// [s]
#define         SA_INSIDE_NEWTRACK_SLOW			0.5*UPDATE_TIME_SLOW*pow(10, 3)//5.0*pow(10, 3)
#define         SA_INSIDE_CONFIRM_SLOW			0.5*UPDATE_TIME_SLOW*pow(10, 3)
#define 		SA_UPDATE_TIME_SLOW				UPDATE_TIME_SLOW*pow(10, 3)						// [ms]
#define 		SA_MARK_DELETE_TIMEOUT_SLOW		MARK_DELETE_TIMEOUT_SLOW*pow(10, 3)				// [ms]
#define 		SA_TRACK_DELETE_TIMEOUT_SLOW	TRACK_DELETE_TIMEOUT_SLOW*pow(10, 3)			// [ms]

#define			SCALEX_RANGEMAX		(1.0 / RANGE_MAX2)

#endif /* GLOBALCONSTANTS_H_ */
