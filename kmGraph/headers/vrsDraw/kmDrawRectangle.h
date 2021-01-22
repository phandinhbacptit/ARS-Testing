/*
 * VrsDrawRectangle.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef KmDrawRectangle_H_
#define KmDrawRectangle_H_

#include "kmDrawBase.h"
class kmDrawRectangle : public kmDrawBase
{
public:
    kmDrawRectangle(int centerX, int centerY, int sizeX, int sizeY);
    virtual ~kmDrawRectangle();
public:
	virtual void draw();
};

#endif /* KmDrawRectangle_H_ */
