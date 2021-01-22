/*
 * RadarPosition.h
 *
 *  Created on: Feb 19, 2014
 *      Author: baotrung
 */

#ifndef RadarPosition_H_
#define RadarPosition_H_

#include "guiDefines.h"
#include <string>
#include <iostream>
#include <QSettings>
#include <QString>
#include <QStringList>
using namespace std;

class RadarPosition
{
public:
	RadarPosition();
	void extractPositions();
	virtual ~RadarPosition();
	LOCATION_SET_T_ vitriRadaCanhGioi();
	LOCATION_SET_T_ vitriRadaDanDuong();
private:
	string m_fileName;
	void trungdoanRada(QSettings &settings, string groupName);
	//Format input string: A1.A2.A3 B1.B2.B3
	void getPosition(string inputString, double &latitude, double &longitude, float& verAlign, float& horAlign);
	LOCATION_SET_T_ m_vitriRadaCanhGioi;
	LOCATION_SET_T_ m_vitriRadaDanDuong;
};

#endif /* RadarPosition_H_ */
