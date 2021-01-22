/*
 * VrsTextManager.h
 *
 *  Created on: Jan 22, 2015
 *      Author: kytv
 */

#ifndef KmTextManager_H_
#define KmTextManager_H_

#ifdef __cpluscplus
extern "C" {
#endif

//#include "FTGL/ftgl.h"
#include <GL/glut.h>
#include <map>
#include <string>
#include <vector>
#include <list>
#include "kmDrawOpenGL.h"
#include "kminclude.h"

//#define DEFAULT_FONT_NAME 		"kmGraph/fonts/roboto/Roboto-Medium.ttf"
#define DEFAULT_FONT_NAME 		"Roboto-Medium"
#define DEFAULT_FONT_SIZE 		14

using namespace std;
class FTFont;

typedef map<string, FTFont*> FontList;
typedef FontList::const_iterator FontIter;

//class VrsTextGroup;
class kmTextManager
{
protected:
    kmTextManager();
public:
    virtual ~kmTextManager();
protected:
	FontList				fonts;
public:
    static 			kmTextManager* getInstance(){
        static kmTextManager instance;
		return &instance;
	}
public:
#ifdef _USE_VRSDRAW_TEXT
    FTFont* 	getFont(const char *filename, int size, bool isPixel = true, int wgId = 0);
	void 		drawText(int nFontSize, const char* str, float x, float y, GLfloat red, GLfloat green, GLfloat blue);
	void 		drawText(float x, float y, const char* str, GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 0.0);
	void 		drawText(FTFont* font, float x, float y, const char* str, GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 0.0);
	void 		drawText(const char* sFaceName, int nSize, float x, float y, const char* str, GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 0.0);
    void drawTextWithAngle(FTFont* font, float x, float y, const char* str, GLfloat red, GLfloat green, GLfloat blue, float angle, int wgWidth, int wgHeight);
    void drawTextWithAngle(const char* sFaceName, int nSize, float x, float y, const char* str, GLfloat red, GLfloat green, GLfloat blue, float angle, int wgWidth, int wgHeight, int wgId = 0);
    void getCharSize(const char* sFaceName, int nSize, int& width, int& height);
#endif
};

inline  kmTextManager* textManager(){
    return kmTextManager::getInstance();
}

#ifdef __cpluscplus
}
#endif

#endif /* KmTextManager_H_ */
