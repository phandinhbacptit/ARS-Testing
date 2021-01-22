/*
 * VrsDrawCircle.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef KmDrawCircle_H_
#define KmDrawCircle_H_

#include "kmDrawBase.h"
#include <math.h>

class kmDrawCircle : public kmDrawBase
{
public:
    kmDrawCircle();
    kmDrawCircle(int nRadius);
    virtual ~kmDrawCircle();
public:
	virtual void draw();
    void setRadius(int nVal) {m_nRadius = nVal; }
protected:
    int		m_nRadius;
};

#endif /* KmDrawCircle_H_ */
