/*
 * VrsDrawTriangle.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef KmDrawTriangle_H_
#define KmDrawTriangle_H_

#include "kmDrawBase.h"
#include <math.h>

class kmDrawTriangle : public kmDrawBase
{
public:
    kmDrawTriangle(int centerX, int centerY, int sizeX, int sizeY);
    kmDrawTriangle(int nRadius);
    virtual ~kmDrawTriangle();
public:
	virtual void draw();
};

#endif /* KmDrawTriangle_H_ */
