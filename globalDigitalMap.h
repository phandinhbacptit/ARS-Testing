/*
 * globalDigitalMap.h
 *
 *  Created on: Apr 25, 2012
 *      Author: CUONGVT2
 */


#include <vector>
#include <map>
#include <string>
#include <QString>

using namespace std;
#ifndef GLOBALDIGITALMAP_H_
#define GLOBALDIGITALMAP_H_

#define SECOND_TO_METER							30.82
#define SECOND_TO_DEGREE						3600.0
#define KILOMETER_TO_METER						1000.0
#define RADIUS_EARTH							6371000	//m

#define HEIGHT_MAX								2805

#define POINT_MINIMUM_REGION					400
#define POINT_SCALE_REGION						15

#define	POINT_MINIMUM_BORDER					10000
#define	POINT_SCALE_BORDER						1

typedef struct{
	double 										BB_Xmin;
	double 										BB_Ymin;
	double 										BB_Xmax;
	double 										BB_Ymax;
}BOUNDING_BOX_T;

typedef pair<double,double>						POINT_T;	//x,y
typedef vector<POINT_T>							POLYGON_T;
typedef vector<POLYGON_T>						GEOMETRY_T;

typedef vector<POINT_T>							LINE_T;
typedef vector<LINE_T>							POLYLINE_T;

typedef struct {
	string 	name;
	QString qName;
	float 	coor_lat;
	float 	coor_lon;
	float	verAlignScale;
	float	horAlignScale;
}LOCATION_T;
typedef vector<LOCATION_T>						LOCATION_SET_T;

typedef enum{
	DM_BorderMap = 1,
	DM_RegionMap = 2,
	DM_AirRoute = 3
}DataMapType;

#endif /* GLOBALDIGITALMAP_H_ */
