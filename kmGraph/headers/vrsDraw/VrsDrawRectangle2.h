/*
 * VrsDrawRectangle2.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef VrsDrawRectangle2_H_
#define VrsDrawRectangle2_H_

#include "VrsDrawBase.h"
class VrsDrawRectangle2 : public VrsDrawBase
{
public:
	VrsDrawRectangle2(float fCenterLeftX, float fCenterLeftY, float fWidth, float fHeight);
	VrsDrawRectangle2(float fCenterLeftX, float fCenterLeftY, float fWidth, float fHeight, int nCharacteristic);
	virtual ~VrsDrawRectangle2();
	float* getPoints() { return m_fPoints; }
protected:
	float	m_fCenterX;
	float	m_fCenterY;
	float 	m_fWidth;
	float 	m_fHeight;
	float*	m_fPoints;
public:
	virtual void draw();
};

#endif /* VrsDrawRectangle2_H_ */
