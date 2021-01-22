/*
 * VrsDrawBase.h
 *
 *  Created on: Feb 2, 2015
 *      Author: kytv
 */

#ifndef KmDrawBase_H_
#define KmDrawBase_H_

#define VRSDRAW_CIRCLE  0
#define VRSDRAW_LINE  1
#define VRSDRAW_RECTANGLE  2
#define VRSDRAW_IMAGE  3
#define VRSDRAW_TEXT    4
#define VRSDRAW_TRIANGLE    5
#define VRSDRAW_STAR    6
#define VRSDRAW_GROUP    7

#include <string>
enum vrsShapeType
{
    vrsShape_fill,
    vrsShape_line,
    vrsShape_fillAndLine
};
/*
 * VRSBase is base class of draw obj
 * It used unit in Pixel==> so window from 0-width; 0-height
*/

class kmDrawBase
{
public:
    kmDrawBase(int nType);
    virtual ~kmDrawBase();
public:
	virtual void draw();
    void setPosX(int nVal) {m_nPosX = nVal; }
    void setPosY(int nVal) {m_nPosY = nVal; }
    void setWidgetWidth(int nVal) {m_nWigetWidth = nVal; }
    void setWidgetHeight(int nVal) {m_nWigetHeight = nVal; }
    int getZOrder() {return m_nZOrder; }
    void setScale(float fVal) {m_fScale = fVal; }
    float getScale() {return m_fScale; }
    void setTextOffset(float xVal, float yVal) {m_nOffsetTextX = xVal; m_nOffsetTextY = yVal; }
    void setText(std::string& str) { m_strText = str; }
    void setSizeX(int val) {m_nSizeX = val; }
    void setSizeY(int val) {m_nSizeY = val; }
    void setShapeType(vrsShapeType type) {m_eShapeType = type; }
    void setFillColor(float r, float g, float b) { m_fCrFill[0] = r; m_fCrFill[1] = g; m_fCrFill[2] = b;}
    void setLineColor(float r, float g, float b) { m_fCrLine[0] = r; m_fCrLine[1] = g; m_fCrLine[2] = b;}
    void setTextColor(float r, float g, float b) { m_fCrText[0] = r; m_fCrText[1] = g; m_fCrText[2] = b;}
protected:
    bool                m_bIsDrawText;
	int				 	m_nCharacter;
	int					m_nType;
	int					m_nZOrder;

    float				m_fCrLine[3];
	float				m_fCrFill[3];
	float				m_fCrText[3];

    float				m_fAlpha;
	bool				m_bEnableAlpha;
	float				m_fLineWidth;
	int					m_nId;
    int 				m_nOffsetTextX;
    int     			m_nOffsetTextY;
    float               m_fScale;
    std::string         m_strText;
    vrsShapeType        m_eShapeType;
    int m_nPosX;
    int m_nPosY;
    int m_nWigetWidth;
    int m_nWigetHeight;
    int m_nSizeX;
    int m_nSizeY;

private:
	static	int			g_nUniqueId;
};

#endif /* KmDrawBase_H_ */
