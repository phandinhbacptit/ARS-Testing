/*
 * drawHelpers.h
 *
 *  Created on: Jan 19, 2015
 *      Author: kytv
 */

#ifndef KMDRAWHELPERS_H_
#define KMDRAWHELPERS_H_
#include <string>
using namespace std;

namespace kmDrawOpenGL {
	float toAzimuth(float angleRad);
	float toAngle(float azimuthRad);
	/*
	 * DrawText with function glutBitmapCharacter
	 * nType is 0 --> 8 represented for
	 * GLUT_STROKE_ROMAN, GLUT_STROKE_MONO_ROMAN, GLUT_BITMAP_9_BY_15
	 * GLUT_BITMAP_8_BY_13, GLUT_BITMAP_TIMES_ROMAN_10, GLUT_BITMAP_TIMES_ROMAN_24,
	 * GLUT_BITMAP_HELVETICA_10, GLUT_BITMAP_HELVETICA_12, GLUT_BITMAP_HELVETICA_18, GLUT_BITMAP_HELVETICA_12
	 * */
    //void drawTextWithAngle_Bitmap(QGLWidget* parent, float angle, const  char* str, float red, float green, float blue, int fontType = 7);
    //void drawTextWithAngle_Bitmap(QGLWidget* parent, float angle, const  char* str, float red = 1.0, float green = 1.0, float blue = 0.0, int fontType = 7);

    void drawTextWithAngle_Bitmap(float angle, const  char* str, float red, float green, float blue, int fontType = 7);
	void drawTextWithAngle_Bitmap(float angle, const  char* str, float color[3], int fontType = 7);
    void drawTextWithAngle_Bitmap(float posX, float posY, float angle, const  char* str, float color[3], int fontType, int wgWidth, int wgHeight);
    void drawText_Bitmap(float x, float y, char* str, float red = 1.0, float green = 1.0, float blue = 0.0, int fontType = 7);
	void drawText_Bitmap(float x, float y, char* str, float color[3], int fontType = 7);

//    void drawText(float x, float y, const char* str, GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 0.0);
//    void drawText(float x, float y, const char* str, float color[3]);
//    void drawText(int nSize, float x, float y, const char* str, GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 0.0);
//    void drawText(const char* sFaceName, int nSize, float x, float y, const char* str, GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 0.0);

    void drawText(float x, float y, const char* str, float red = 1.0, float green = 1.0, float blue = 0.0);
    void drawText(float x, float y, const char* str, float color[3]);
    void drawText(int nSize, float x, float y, const char* str, float red = 1.0, float green = 1.0, float blue = 0.0);
    void drawText(const char* sFaceName, int nSize, float x, float y, const char* str, float red = 1.0, float green = 1.0, float blue = 0.0);
    void drawTextWithAngle(const char* sFaceName, int nSize, float x, float y, const char* str, float cr[3], float angle, int wgWidth, int wgHeight, int wgId);

    void drawRectangle(float fTopX, float fTopY, float fWidth, float fHeight, float fColor[3]);
    void drawRectangle(float fTopX, float fTopY, float fWidth, float fHeight, float fColor[3], float fAlpha);
	void drawRectangle2(float fTopLeftX, float fTopLeftY, float fBottomRightX, float fBottomRightY, float fColor[3], float fAlpha = 1.0);

	void drawRectangle_ByCenter(float fCenterX, float fCenterY, float fWidth, float fHeight, float fColor[3], float fAlpha);
	void drawRectangle_ByCenter(float fCenterX, float fCenterY, float fWidth, float fHeight, float fColor[3]);
	void drawRectLine_ByCenter(float fCenterX, float fCenterY, float fWidth, float fHeight, float fLineWidth, float fColor[3]);

	void drawRectangle_fixedSize(float fCenterX, float fCenterY, float fWidth, float fHeight, float fColor[3], float fAlpha, float fScale);
	void drawRectangle_fixedSize(float fCenterX, float fCenterY, float fWidth, float fHeight, float fColor[3], float fScale);
	void drawRectLine_fixedSize(float fCenterX, float fCenterY, float fWidth, float fHeight, float fLineWidth, float fColor[3], float fScale);

	void drawRectLine(float fTopX, float fTopY, float fWidth, float fHeight, float fColor[3], float fLineWidth = 1.0);
	void drawRectLine2(float fTopLeftX, float fTopLeftY, float fBottomRightX, float fBottomRightY, float fColor[3], float fLineWidth);
	//Draw Quad:
	//fCenterX, fCenterY: -1.0 -- > 1.0
	//fSize: 0.0 -->1.0
    //Tuy nhien khi Width va Height cua widget khong bang nhau thi ve khon duoc QUAD that su
	void drawQuad(float fCenterX, float fCenterY, float fSize, float red, float green, float blue);
	void drawQuad(float fCenterX, float fCenterY, float fSize, float color[3]);
	void drawQuad(float fCenterX, float fCenterY, float fSize, float red, float green, float blue, float alpha);
	void drawQuad(float fCenterX, float fCenterY, float fSize, float color[3], float alpha);	//Draw TriangleFan:
    //Co them ty le de hien thi dung QUAD
    void drawQuad_Real(float fCenterX, float fCenterY, float fSize, float color[3], float scaleW_vs_H);

	//Automaticlly adjust size to keep size on Global scale
	//Tu dong dieu chinh kich thuoc de luon hien thi mot view size tren man hinh, khong phu thuoc vao ty le zoom
    //Tuy nhien khi Width va Height cua widget khong bang nhau thi ve khon duoc QUAD that su
	void drawQuad_fixedSize(float fCenterX, float fCenterY, float fSize, float red, float green, float blue, float fScale);
	void drawQuad_fixedSize(float fCenterX, float fCenterY, float fSize, float color[3], float fScale);
	void drawQuad_fixedSize(float fCenterX, float fCenterY, float fSize, float red, float green, float blue, float alpha, float fScale);
	void drawQuad_fixedSize(float fCenterX, float fCenterY, float fSize, float color[3], float alpha, float fScale);	//Draw TriangleFan:
    //Gui dung ty le khi co W va H cua widget
    void drawQuad_fixedSize_real(float fCenterX, float fCenterY, float fSize, float color[3], float alpha, float fScale, float scale_W_vs_H);

	//start, stop: 0->360
	//radius, red, green, blue, alpha: 0.0-->1.0
	void drawTriangleFan(int start, int end, float radius, float red, float green, float blue, float alpha);
	void drawTriangleFan(int start, int end, float radius, float color[3], float alpha);
	void drawTriangleFan(float fPosX, float fPosY, int start, int end, float radius, float red, float green, float blue, float alpha);
	void drawTriangleFan(float fPosX, float fPosY, int start, int end, float radius, float color[3], float alpha);

    //Gui dung ty le khi co W va H cua widget
    //void drawTriangleFan_real(float fPosX, float fPosY, int start, int end, float radius, float color[3], float alpha, float scale_W_vs_H);
	void drawTriangleFan_Float(float start, float end, float radius, float color[3], float step);
	void drawTriangleFan_Float(float start, float end, float radius, float red, float green, float blue, float step);
	void drawTriangleFan_Float(float start, float end, float radius, float red, float green, float blue, float step, float alpha);
	void drawTriangleFan_Float(float start, float end, float radius, float color[3], float step, float alpha);

	//Angle: From 0-->360
	//Draw Filled Sector
	void drawSector_Filled(float startAngle, float endAngle, float startRadius, float endRadius, float red, float green, float blue, float alpha, float lineWidth);
	void drawSector_Filled(float startAngle, float endAngle, float startRadius, float endRadius, float color[3], float alpha, float lineWidth);
	void drawSector_Filled(float fCenterX, float fCenterY, int startAngle, int endAngle, float startRadius, float endRadius, float color[3], float alpha, float lineWidth);
	//Draw Line sector
	void drawSector(int startAngle, int endAngle, float startRadius, float endRadius, float red, float green, float blue);
	void drawSector(int startAngle, int endAngle, float startRadius, float endRadius, float color[3]);
	void drawSector(float fCenterX, float fCenterY, int startAngle, int endAngle, float startRadius, float endRadius, float red, float green, float blue);
	/*
	 * drawNewSector
	 * startAngle, endAngle: 0-->360
	 * startRadius, stopRadius: 0.0-->1.0 (stop> start)
	 * */
	void drawSector_New(float startAngle, float endAngle, float startRadius, float endRadius, float red, float green, float blue, float lineWidth);
	void drawSector_New(float startAngle, float endAngle, float startRadius, float endRadius, float color[3], float lineWidth);
	void drawSector_New(float fCenterX, float fCenterY, float startAngle, float endAngle, float startRadius, float endRadius, float red, float green, float blue, float lineWidth);

	//Draw Image
	void drawImage(const char* imgPath, bool hasAlpha,  float x, float y, int nWindowWidth, int nWindowHeight);
	void drawImage(const char* imgPath, bool hasAlpha,  float x, float y, int nWindowWidth, int nWindowHeight, float fScaleX, float fScaleY);

	//Draw Circle
	//NumofPoint: the point number to draw a circle. For example: 100
    /*
     * drawCircle:
     * drawCircle: Neu man hinh co width = height ==> Ve dung Circle, Neu khong se ve thanh elipse
     * Trong truong hop do phai goi ham  drawCircle_real voi scale_W_vs_H = width/height
     * De ve dung trong he Pixel su dung ham drawElipeLine
    */
	void drawCircle(float x, float y, int numofPoint, float fRadius, float fLineWidth, float color[3]);
	void drawCircle(float x, float y, int numofPoint, float fRadius, float fLineWidth, float color[3], float alpha);
	void drawCircle(float x, float y, float fRadius, float fLineWidth, float color[3]);
	void drawCircle(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);
    void drawCircle_real(float x, float y, float fRadius, float fLineWidth, float color[3], float scale_W_vs_H);

	void drawCircleNormal(float x, float y, float fRadius, float fLineWidth, float color[3]);
	void drawCircleNormal(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);
	void drawCircleSmooth(float x, float y, float fRadius, float fLineWidth, float color[3]);
	void drawCircleSmooth(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);
	void drawCircleSmoothest(float x, float y, float fRadius, float fLineWidth, float color[3]);
	void drawCircleSmoothest(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);
    //Giu tron khi W va H cuar widget khong bang nhau
    void drawCircle_fill(float x, float y, float fRadius, float fLineWidth, float color[3]);
    void drawCircle_fill(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha);
    void drawCircle_real_fill(float x, float y, float fRadius, float fLineWidth, float color[3], float scale_W_vs_H);
    void drawCircle_real_fill(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha, float scale_W_vs_H);

    void drawCircle_real(float x, float y, int numofPoint, float fRadius, float fLineWidth, float color[3], float scale_W_vs_H);
    void drawCircle_real(float x, float y, float fRadius, float fLineWidth, float color[3], float scale_W_vs_H);

	//Su dung khi muon giu nguyen kich thuoc cua hinh tron ma khong phu thuoc vao ty le zoom cua man hinh
	void drawCircle_fixedSize(float x, float y, int numofPoint, float fRadius, float fLineWidth, float color[3],float fScale);
	void drawCircle_fixedSize(float x, float y, int numofPoint, float fRadius, float fLineWidth, float color[3], float alpha,float fScale);
	void drawCircle_fixedSize(float x, float y, float fRadius, float fLineWidth, float color[3],float fScale);
	void drawCircle_fixedSize(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha,float fScale);
	void drawCircleNormal_fixedSize(float x, float y, float fRadius, float fLineWidth, float color[3],float fScale);
	void drawCircleNormal_fixedSize(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha,float fScale);
	void drawCircleSmooth_fixedSize(float x, float y, float fRadius, float fLineWidth, float color[3],float fScale);
	void drawCircleSmooth_fixedSize(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha,float fScale);
	void drawCircleSmoothest_fixedSize(float x, float y, float fRadius, float fLineWidth, float color[3],float fScale);
	void drawCircleSmoothest_fixedSize(float x, float y, float fRadius, float fLineWidth, float color[3], float alpha,float fScale);
	//Draw polyline
	/*
	 * Points: Contain single point of polyline
	 * */
	void drawPolyline(float* points, int nSize, float lineWidth, float color[3]);
	void drawPolyline(float* points, int nSize, float lineWidth, float color[3], float alpha);

	//Draw Polygon
	void drawPolygon(float* points, int nSize, float color[3]);
	void drawPolygon(float* points, int nSize, float color[3], float alpha);
    void drawPolygon_ByQuadStrip(float* points, int nSize, float color[3], float alpha);

	//DrawVBOPoint
	//nSize = sizeofArray(points)/2 = sizeofArray(color)/3
	//1. Draw as vertex points. The color is one
	void drawVBOPoints(float* points, int nSize, float color[3]);
	void drawVBOQuads(float* points, int nSize, float color[3]);
	//2. Draw as vertex points and vertex color
	void drawVBOPoints(float* points, float* color, int nSize);
	void drawVBOQuads(float points, float* color, int nSize);

	//Draw Lines
	/*
	 * chu y:?????????????????????
	 * De ve duoc duong line nho (lineWidth = 1.0) dung nhu mong muon thi
	 * phai goi mot ham drawLine dau tien ko co alpha, sau do goi cac line co alpha thi duoc
	 * Chua hieu ly do tai sao?????????????????????
	 * */
	void drawLine(float x1, float y1, float x2, float y2, float lineWidth, float color[3]);
	void drawLine(float x1, float y1, float x2, float y2, float lineWidth, float color[3], float alpha);
    void drawLineStrip(float* data, int size, float lineWidth, float color[3]);

	//Draw Points
	void drawPoints(float* points, int nSize, float color[3]);

    //Draw Dot lines by Line
	void drawDotLine(float x1, float y1, float x2, float y2, float dotWidth, float blankWidth, float lineWidth, float red, float green, float blue);
	void drawDotLine(float x1, float y1, float x2, float y2, float dotWidth, float blankWidth, float lineWidth, float cr[3]);

    //Draw Dot lines by Point
    void drawDotPoint(float x1, float y1, float x2, float y2, float pointSize, float blankWidth, float red, float green, float blue);
	void drawDotPoint(float x1, float y1, float x2, float y2, float pointSize, float blankWidth, float cr[3]);

	//Draw Dot with line and point
	void drawDotLineAndPoint(float x1, float y1, float x2, float y2, float pointSize, float blankWidth, float dotLenght, float cr[3]);
	//Draw Triangle
	/*
	 * radius: triangle_size
	 * */
	void drawTriAngle_Line(float glX, float glY, float lineWidth, float triangle_size, float cr[3], float alpha);
	void drawTriAngle_Fill(float glX, float glY, float triangle_size, float cr[3]);
    void drawTriAngle_Fill(float glX, float glY, float triangle_size, float cr[3], float alpha);

    //Draw triangle deu, giu duoc ty le khi W va H cuar widget khong bang nhau
    void drawTriAngle_Line_real(float glX, float glY, float lineWidth, float triangle_size, float cr[3], float scale_W_vs_H);
    void drawTriAngle_Fill_real(float glX, float glY, float triangle_size, float cr[3], float scale_W_vs_H);

	void drawTriAngle_Line(float glX, float glY, float lineWidth, float triangle_sizeX, float triangle_sizeY, float cr[3], float alpha);
	void drawTriAngle_Fill(float glX, float glY, float triangle_sizeX, float triangle_sizeY, float cr[3]);
    void drawTriAngle_Fill(float glX, float glY, float triangle_sizeX, float triangle_sizeY, float cr[3], float alpha);

    /*
     * draw Star
    */

    void drawStar_Line(float glX, float glY, float lineWidth, float starSize, float cr[3], float alpha);
    void drawStar_Fill(float glX, float glY, float starSize, float cr[3]);
    void drawStar_Fill(float glX, float glY, float starSize, float cr[3], float alpha);
    //Gui size khi W va H cuar widget khac nhau
    void drawStar_Fill_real(float glX, float glY, float starSize, float cr[3], float scale_W_vs_H);
    void drawStar_Line_real(float glX, float glY, float lineWidth, float starSize, float cr[3], float scale_W_vs_H);

    //void drawStar_Line(float glX, float glY, float lineWidth, float starSizeX, float starSizeY, float cr[3], float alpha);
    //void drawStar_Fill(float glX, float glY, float starSizeX, float starSizeY, float cr[3]);
    void convertQt2Gl(int nPointX, int nPointY, float& fPointX, float& fPointY, int wgWidth, int wgHeight);

    /*
     * draw in pixel unit(window, Qt window)
    */

    /*
     * draw Elipse voi don vi Pilxel
    */
    void drawElipeLine_pixel(int x, int y, int sizeX, int sizeY, float fLineWidth, float color[3], int wgWidth, int wgHeight, float scale = 1.0);
    void drawElipeFill_pixel(int x, int y, int sizeX, int sizeY, float color[3], int wgWidth, int wgHeight, float scale = 1.0);
	void drawElipeFill_pixel(int x, int y, int sizeX, int sizeY, float color[3], float alpha, int wgWidth, int wgHeight, float scale);
    void drawCircleLine_pixel(int x, int y, int radius, float lineWidth, float color[3], int wgWidth, int wgHeight, float scale = 1.0);
	void drawCircleFill_pixel(int x, int y, int radius, float color[3], float alpha, int wgWidth, int wgHeight, float scale = 1.0);
	void drawCircleFill_pixel(int x, int y, int radius, float color[3], float alpha, int wgWidth, int wgHeight, float scale);

    void drawRectangleLine_pixel(int x, int y, int sizeX, int sizeY, float fLineWidth, float color[3], int wgWidth, int wgHeight, float scale = 1.0);
    void drawRectangleFill_pixel(int x, int y, int sizeX, int sizeY, float color[3], int wgWidth, int wgHeight, float scale = 1.0);
    void drawRectangleFill_pixel(int x, int y, int sizeX, int sizeY, float color[3], int wgWidth, int wgHeight, float scale, float alfa);

    void drawLine_pixel(int x1, int y1, int x2, int y2, float fLineWidth, float color[3], int wgWidth, int wgHeight);
    void drawDotLine_pilxel(int x1, int y1, int x2, int y2, float lineWidth, float dotWidth, float blankWidth, float cr[3], int wgWidth, int wgHeight);

    void drawStarFill_pixel(int x, int y, float starSize, float cr[3], int wgWidth, int wgHeight, float scale = 1.0);
    void drawStarFill_pixel(int x, int y, float starSize, float cr[3], int wgWidth, int wgHeight, float scale, float alpha);
    void drawStarLine_pixel(int x, int y, float lineWidth, float starSize, float cr[3], int wgWidth, int wgHeight, float scale = 1.0);

    void drawText_pixel(int x, int y, const char* str, float color[3], int wgWidth, int wgHeight);
    void drawText_pixel(const char* sFaceName, int nSize, int x, int y, const char* str, float color[3], int wgWidth, int wgHeight);

    void drawTriangleFill_pixel(int x, int y, float starSize, float cr[3], int wgWidth, int wgHeight, float scale = 1.0);
    void drawTriangleFill_pixel(int x, int y, float starSize, float cr[3], int wgWidth, int wgHeight, float scale, float alpha);
    void drawTriangleLine_pixel(int x, int y, float lineWidth, float starSize, float cr[3], int wgWidth, int wgHeight, float scale = 1.0);
    void drawTriangleFill_pixel(int x, int y, float sizeX, float sizeY, float cr[3], int wgWidth, int wgHeight, float scale, float alpha);
    void drawTriangleLine_pixel(int x, int y, float lineWidth, float sizeX, float sizeY, float cr[3], int wgWidth, int wgHeight, float scale = 1.0);

    void drawPolyline_pixel(int* points, int nSize, float lineWidth, float color[3], int wgWidth, int wgHeight);
    //Draw Polygon
    void drawPolygon_pixel(int* points, int nSize, float color[3], int wgWidth, int wgHeight);
    void drawPolygon_pixel(int* points, int nSize, float color[3], int wgWidth, int wgHeight, float alpha);
    void drawPolygon_ByQuadStrip_pilxel(float* points, int nSize, float color[3], int wgWidth, int wgHeight, float alpha);

	void enableDrawSmooth(bool isSmooth);
}

#endif /* KMDRAWHELPERS_H_ */
