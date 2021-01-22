/*
 * globalConfigs.h
 *
 *  Created on: Jul 17, 2012
 *      Author: dungnb2
 */

#ifndef GLOBALCONFIGS_H_
#define GLOBALCONFIGS_H_

typedef enum{
	cMarkEnable = 0,
	cMarkDisable
}CMarkType;
typedef enum{
	khoiCoreLMCC = 0,
	khoiCoreSRCC,
	khoiCoreMulti,
	khoiHienThiLMCC,
	khoiHienThiSRCC,
	khoiHienThiMulti,
	khoiTestLMCC,
	khoiTestSRCC,
	khoiTestMulti
}BlockModeType;


#endif /* GLOBALCONFIGS_H_ */
