/*
 * PpiDataModel.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef PpiDataModel_H_
#define PpiDataModel_H_

#include "BaseDataModel.h"
#include <list>
#include <map>
#include <vector>

class widgetBasePPI;
class VrsDrawBase;
class PpiDataModel : public BaseDataModel
{
public:
	PpiDataModel(widgetBasePPI* pView);
	virtual ~PpiDataModel();

public:
	virtual float getScaleX();
	virtual float getScaleY();
	virtual float getTranslateX();
	virtual float getTranslateY();
	virtual	void addDrawObject(VrsDrawBase* pBase);
	virtual void removeDrawObject(VrsDrawBase* pBase);

	virtual float getWindowWidth();
	virtual float getWindowHeight();

	virtual void clearAll();
	VrsDrawBase* getObjById(int nId);
	std::list <VrsDrawBase*>& getListDrawObject();
	std::map<long long, std::vector<float> >& getMap_Color_RectPoints() { return m_mapColor_RectPoints; }
protected:
	widgetBasePPI*	m_pView;
	std::list <VrsDrawBase*>		m_listDrawObj;
	std::map <int, VrsDrawBase*>	m_mapDrawObj;
	std::map<long long, std::vector<float> > m_mapColor_RectPoints;
	std::list <VrsDrawBase*>		m_listRectObj;
};

#endif /* PpiDataModel_H_ */
