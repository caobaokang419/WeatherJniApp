package com.example.gary.weatherjniapp.jni;

public class CitySearchNative {
	static {
		try {
			System.loadLibrary("citysearch-native-lib");
		} catch (Throwable e) {
			e.printStackTrace();
		}
	}

	public static synchronized native String getStringFromJNI();

	public static synchronized native String searchCityFromJNI(String keyword);
}
