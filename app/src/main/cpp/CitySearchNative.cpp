

/*************************** HEADER FILES ***************************/
#include <jni.h>
#include <string>

#include <stdlib.h>
#include <cityDef.h>
#include "aes.h"

#include <stdio.h>


/*************************** HEADER FILES ***************************/
#include <stdlib.h>
#include <memory.h>
#include "aes.h"

#include <stdio.h>


/*********************** FUNCTION DECLARATIONS **********************/
int citySearch(BYTE keyword[]);


/*********************** FUNCTION DEFINITIONS ***********************/

extern "C" JNIEXPORT jstring JNICALL
/**Java_com_example_gary_weatherjniapp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject ) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}*/

Java_com_example_gary_weatherjniapp_jni_CitySearchNative_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}



