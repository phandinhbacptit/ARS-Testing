/*
 * VrsDrawImage.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef KmDrawImage_H_
#define KmDrawImage_H_
#include "kmImageManager.h"
#include "kmDrawBase.h"
#include <string>
using namespace std;

class kmDrawImage: public kmDrawBase {
public:
    kmDrawImage(const char* strFile, bool hasAlpha, float fPosX, float fPosY);
    virtual ~kmDrawImage();
public:
	virtual void draw();
	string	m_strFileName;
	IMANGE_T*	m_pImage;
	bool	m_bHasAlpha;
	float	m_fPosX;
	float 	m_fPosY;
};

#endif /* KmDrawImage_H_ */
