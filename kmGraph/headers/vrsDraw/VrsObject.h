/*
 * VrsObject.h
 *
 *  Created on: Jan 27, 2015
 *      Author: kytv
 */

#ifndef VrsObject_H_
#define VrsObject_H_

#include "VrsArchive.h"

class VrsObject {
public:
	VrsObject();
	virtual ~VrsObject();
public:
	virtual void serialize(VrsArchive& ar)= 0;
};

#endif /* VrsObject_H_ */
