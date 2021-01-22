/*
 * vrsUtils.h
 *
 *  Created on: Jan 27, 2015
 *      Author: kytv
 */

#ifndef KMUTILS_H_
#define KMUTILS_H_

#include <string>
#include <vector>
using namespace std;
namespace kmUtils
{
    const char* float2Char(float fVal, int nDecal);
	string float2Str(float fVal, int nDecal);
    string float2Str(float fVal, int nDecal, int& outDelcal);
    /*
     * from float: 12.123456
     * nDecal = 1, return 12.1
     * nDecal = 2, return 12.12
     * nDecal = 3, return 12.123
    */
    float convertFloat(float fVal, int nDecal);
    /*
     * find the mean number after float point .
     * for example: s = 0.5400
     * output: s= 0.54, return 2
    */
    int morphNumericString(char* s, int n);

    /*
     * calculate std function
    */
    float calStandardDeviation(float* listVal, int size);
    float calMean(float* listVal, int size);
    float calCovariant(float* listVal, int size);
    //float calStandardDeviation(std::vector<float>& listVal);
};

#endif /* KMUTILS_H_ */
