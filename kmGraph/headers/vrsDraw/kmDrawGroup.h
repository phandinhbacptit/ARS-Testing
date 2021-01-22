/*
 * VrsDrawGroup.h
 *
 *  Created on: Feb 4, 2015
 *      Author: kytv
 */

#ifndef KmDrawGroup_H_
#define KmDrawGroup_H_

#include "kmDrawBase.h"
#include <list>
using namespace std;

class kmDrawGroup : public kmDrawBase
{
public:
    kmDrawGroup();
    virtual ~kmDrawGroup();
public:
	virtual	void addObject(kmDrawBase* pBase);
	virtual void removeObject(kmDrawBase* pBase);
	virtual void draw();
protected:
	std::list <kmDrawBase*>& getListDrawObject() { return m_listDrawObj; };
	std::list <kmDrawBase*>		m_listDrawObj;
};

#endif /* KmDrawGroup_H_ */
