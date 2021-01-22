/*
 * DecacDataModel.h
 *
 *  Created on: May 20, 2015
 *      Author: kytv
 */

#ifndef DECACDATAMODEL_H_
#define DECACDATAMODEL_H_
#include "BaseDataModel.h"
#include <map>
#include <vector>
#include <list>

class VrsDrawBase;
class widgetDecac;
class DecacDataModel : public BaseDataModel
{
public:
public:
	DecacDataModel(widgetDecac* pView);
	virtual ~DecacDataModel();

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
	widgetDecac*	m_pView;
	std::list <VrsDrawBase*>		m_listDrawObj;
	std::map <int, VrsDrawBase*>	m_mapDrawObj;
	std::map<long long, std::vector<float> > m_mapColor_RectPoints;
	std::list <VrsDrawBase*>		m_listRectObj;
};

#endif /* DECACDATAMODEL_H_ */
