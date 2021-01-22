/*
 * MapDataModel.h
 *
 *  Created on: Jan 29, 2015
 *      Author: kytv
 */

#ifndef MapDataModel_H_
#define MapDataModel_H_

#include "VrsDocument.h"
#include "guiDefines.h"
#include <QWidget>

class widgetPPI;
class MapDataModel : public VrsDocument
{
public:
	MapDataModel(QWidget* parent);
	virtual ~MapDataModel();
public:
	virtual bool serialize(VrsArchive& ar, bool isStoring = false);

	GEOMETRY_T_&	getBorderData() { return m_listMapBorder; }
	POLYLINE_T_& getAirroute() { return m_listAirroutes; }
	GEOMETRY_T_& getRegionData() { return m_listMapregion; }
	LOCATION_SET_T_& getVitriSanbay() { return m_vitriSanbay; };
	LOCATION_SET_T_& getVitriRadarDanduong() { return m_vitriRadaDanDuong; }
	LOCATION_SET_T_& getVitriRadarCanhgioi() { return m_vitriRadaCanhGioi; }

	LOCATION_SET_T_& getVitriSanbayOrigin() { return m_vitriSanbayOrigin; };
	LOCATION_SET_T_& getVitriRadarDanduongOrigin() { return m_vitriRadaDanDuongOrigin; }
	LOCATION_SET_T_& getVitriRadarCanhgioiOrigin() { return m_vitriRadaCanhGioiOrigin; }
public:
	GEOMETRY_T_			m_listMapBorder;
	GEOMETRY_T_			m_listMapregion;
	POLYLINE_T_			m_listAirroutes;

	float				m_fLongitude;
	float 				m_fLatitude;
	float				m_fRadius;
	float 				m_fDeltaX_BB, m_fDeltaY_BB, m_fDeltaMax_BB;
	float				m_fCenterX, m_fCenterY;

	float 				m_fMapScale;
	BOUNDING_BOX_T_		boundingBox;

	LOCATION_SET_T_ 	m_vitriRadaDanDuong;
	LOCATION_SET_T_		m_vitriRadaCanhGioi;
	LOCATION_SET_T_		m_vitriSanbay;

	//Vi tri doc tu file, chua bien doi
	LOCATION_SET_T_ 	m_vitriRadaDanDuongOrigin;
	LOCATION_SET_T_		m_vitriRadaCanhGioiOrigin;
	LOCATION_SET_T_		m_vitriSanbayOrigin;

	widgetPPI*			m_pWidgetPPI;
public:
	float 					getMapScale();
	float 					getInitScale();
	pair<double, double> 	getOriginMap(double posRDX, double posRDY);
	void 					convertDisplayPosToGPSPos(LOCATION_T_ &locations);
	void 					convertRealPositionToDisplayPosition(LOCATION_SET_T_ &locations);
	void					convertGps2Gl(float fLong, float flat, float& fGlX, float& fGlY);
	void 					setPositionRadar(float radius, float fLong, float fLat);
	void 					initialize();

	widgetPPI*				getWidgetPPI();
};

#endif /* MapDataModel_H_ */
