/*
 * VrsDrawText.h
 *
 *  Created on: Feb 3, 2015
 *      Author: kytv
 */

#ifndef KmDrawText_H_
#define KmDrawText_H_

#include "kmDrawBase.h"
#include <string>

using namespace std;
class kmDrawText : public kmDrawBase
{
public:
    kmDrawText(int x, int y, const char* str);
    kmDrawText(int x, int y, const char* str, const char* strFontFace, int nFontSize);
    void setText(string& str) { m_strText = str;}
    string getText() {return m_strText;}
    virtual ~kmDrawText();
public:
	virtual void draw();
protected:
	string	m_strText;
	string 	m_strFontFaceName;
	int		m_nFontSize;
//	float	m_fX;
//	float	m_fY;
};

#endif /* KmDrawText_H_ */
