//
// Created by gary on 2019/4/29.
//

/*************************** HEADER FILES ***************************/
#include <jni.h>
#include <string>
#include <stdio.h>

#include "citysearch/CityDef.h"

/*********************** FUNCTION DECLARATIONS **********************/
int searchCity(BYTE keyword[]);


/*********************** FUNCTION DEFINITIONS ***********************/
/*extern "C" JNIEXPORT jstring JNICALL
Java_com_example_gary_weatherjniapp_jni_CitySearchNative_stringFromJNI(
        JNIEnv* env,
        jobject) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}*/

JNIEXPORT jstring JNICALL getString( JNIEnv* env, jobject thiz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring JNICALL searchCity( JNIEnv* env, jobject thiz, jstring keyword) {
    std::string hello = "city code from C++";
    return env->NewStringUTF(hello.c_str());
}


/*
* Register several native methods for one class.
*/
static int registerNativeMethods(JNIEnv* env, const char* className,JNINativeMethod* gMethods, int numMethods)
{
  jclass clazz;
  clazz = (*env)->FindClass(env, className);
  if (clazz == NULL){
    return JNI_FALSE;
  }

  if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0)
  {
    LOGE("register nativers error");
    return JNI_FALSE;
  }

  return JNI_TRUE;
}

static const char *classPathName = "com/example/gary/weatherjniapp/jni";

/*
* Register native methods for all classes we know about.
*
* returns JNI_TRUE on success.
*/
static int registerNatives(JNIEnv* env){
 if (!registerNativeMethods(env, classPathName,methods, sizeof(methods) / sizeof(methods[0]))) {
  return JNI_FALSE;
 }

 return JNI_TRUE;
}

static JNINativeMethod methods[] = {
 {"getStringFromJNI", "()Ljava/lang/String", (void*)getString },
 {"searchCityFromJNI", "(Ljava/lang/String;)Ljava/lang/String;", (void*)searchCity },
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
	JNIEnv* env = NULL;
	if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		return -1;
	}

	jclass clazz = (*env)->FindClass(env, TARGET_CLASS);
	if (!clazz) {
		return -1;
	}
	//这里就是关键了，把本地函数和一个java类方法关联起来。不管之前是否关联过，一律把之前的替换掉！
	if ((*env)->RegisterNatives(env, clazz, gMethods,
			sizeof(gMethods) / sizeof(gMethods[0])) != JNI_OK) {
		return -1;
	}

	return JNI_VERSION_1_4;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
	JNIEnv* env = NULL;
	if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		return;
	}
}