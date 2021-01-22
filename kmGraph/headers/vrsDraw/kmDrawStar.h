/*
 * VrsDrawStar.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef KmDrawStar_H_
#define KmDrawStar_H_

#include "kmDrawBase.h"
#include <math.h>

class kmDrawStar : public kmDrawBase
{
public:
    kmDrawStar();
    kmDrawStar(int nRadius);
    virtual ~kmDrawStar();
public:
	virtual void draw();
};

#endif /* KmDrawStar_H_ */
