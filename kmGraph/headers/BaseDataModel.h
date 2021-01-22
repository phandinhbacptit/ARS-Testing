/*
 * BaseDataModel.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef BaseDataModel_H_
#define BaseDataModel_H_

#include <QRect>

class VrsDrawBase;

class BaseDataModel {
public:
	BaseDataModel();
	virtual ~BaseDataModel();
public:
	virtual float getScaleX(){ return 1.0; };
	virtual float getScaleY(){ return 1.0; };
	virtual float getTranslateX(){ return 1.0; };
	virtual float getTranslateY(){ return 1.0; };
	virtual float getWindowWidth(){ return 1.0; };
	virtual float getWindowHeight(){ return 1.0; };
	virtual	void addDrawObject(VrsDrawBase* pObj){};
};

#endif /* BaseDataModel_H_ */
