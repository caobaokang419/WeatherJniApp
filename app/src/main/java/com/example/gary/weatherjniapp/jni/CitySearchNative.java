package com.panxw.aes.jni;

public class CitySearchNative {
	static {
		try {
			System.loadLibrary("citysearch-native-lib");
		} catch (Throwable e) {
			e.printStackTrace();
		}
	}

	public native String stringFromJNI();
}
