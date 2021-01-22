/*
 * VrsDrawLine.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef KmDrawLine_H_
#define KmDrawLine_H_

#include "kmDrawBase.h"
class kmDrawLine : public kmDrawBase
{
public:
    kmDrawLine(float x1, float y1, float x2, float y2);
    virtual ~kmDrawLine();
public:
	virtual void draw();
	void setOffsetX2(float fX) { m_fOffsetX2 = fX; }
	void setOffsetY2(float fY) { m_fOffsetY2 = fY; }
protected:
	float	m_arrLines[4];
	float	m_fOffsetX2;
	float	m_fOffsetY2;
};

#endif /* KmDrawLine_H_ */
