/*
 * VrsImageManager.h
 *
 *  Created on: Jan 23, 2015
 *      Author: kytv
 */

#ifndef KmImageManager_H_
#define KmImageManager_H_

#include <map>
#include <string>

using namespace std;

struct IMANGE_T
{
	string 	FilePath;
    //GLuint	TextureId;
    unsigned int TextureId;
	int 	Width;
	int 	Height;
	bool	HasAlpha;
};

class kmImageManager {
private:
    kmImageManager();
public:
    virtual ~kmImageManager();
public:
    static kmImageManager* getInstance(){
        static kmImageManager instance;
		return &instance;
	}

	void setWindowWidth(int nVal) { m_nWindowWidth = nVal;}
	void setWindowHeight(int nVal) { m_nWindowHeight = nVal; }

	/*
	 * Draw Png Image
	 * x, y: top left position of imange
	 * windowWidth, windowHeight: Width and Height of Window that contains this image
	 * */
	void drawImage(IMANGE_T* pImage, float x, float y, int nWindowWidth, int nWindowHeight, float fScaleX = 1.0, float fScaleY = 1.0, bool bEnableZoom = false);
	void drawImage(const char* imgPath, bool hasAlpha,  float x, float y, int nWindowWidth, int nWindowHeight, float fScaleX = 1.0, float fScaleY = 1.0, bool bEnableZoom = false);

	//Must to set window Width and Height before Use this methods
	void drawImage(IMANGE_T* pImage, float x, float y, float fScaleX = 1.0, float fScaleY = 1.0, bool bEnableZoom = false);
	void drawImage(const char* imgPath, bool hasAlpha,  float x, float y, float fScaleX = 1.0, float fScaleY = 1.0, bool bEnableZoom = false);
	IMANGE_T* getImage(const char* imagePath, bool bHasAlpha = true);
protected:
	std::map<string, IMANGE_T*>	m_mapImages;

	//Width and Height of Window which contains images
	//For example: Width = 1080; height = 1080
	int	m_nWindowWidth;
	int m_nWindowHeight;
};

inline kmImageManager* imageManager(){
    return kmImageManager::getInstance();
}
#endif /* KmImageManager_H_ */
