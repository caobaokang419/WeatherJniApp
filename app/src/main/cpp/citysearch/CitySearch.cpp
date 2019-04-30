//
// Created by gary on 2019/4/29.
//

/*************************** HEADER FILES ***************************/
#include <jni.h>
#include <string>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "CityDef.h"

/****************************** MACROS（宏命令） ******************************/
// The least significant byte of the word is rotated to the end.
#define KE_ROTWORD(x) (((x) << 8) | ((x) >> 24))

#define TRUE  1
#define FALSE 0

/**************************** DATA TYPES ****************************/


/*********************** FUNCTION DECLARATIONS **********************/


/**************************** VARIABLES *****************************/


/*********************** FUNCTION DEFINITIONS ***********************/
int searchCity(BYTE keyword[])
{
    int adcode = 0;
	return adcode;
}

