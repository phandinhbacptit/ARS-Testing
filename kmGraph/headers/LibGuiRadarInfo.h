/*
 * LibGuiRadarInfo.h
 *
 *  Created on: Apr 4, 2015
 *      Author: kientt9
 */

#ifndef LIBGUIRADARINFO_H_
#define LIBGUIRADARINFO_H_

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class LibGuiRadarInfo
{
public:
	LibGuiRadarInfo();
	virtual ~LibGuiRadarInfo();
private:
	static string GetSvnRevisionNumber();
	static string GetSvnRevisionDate();
	static string GetLibraryVersion();
public:
	static string GetVersionString();
};

#endif /* LIBGUIRADARINFO_H_ */
