#pragma once


#if defined(__CYGWIN32__)
#define UNITY_INTERFACE_API __stdcall
#define UNITY_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WINAPI_FAMILY)
#define UNITY_INTERFACE_API __stdcall
#define UNITY_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(__MACH__) || defined(__ANDROID__) || defined(__linux__)
#define UNITY_INTERFACE_API
#define UNITY_INTERFACE_EXPORT
#else
#define UNITY_INTERFACE_API
#define UNITY_INTERFACE_EXPORT
#endif
//传入图像RawData进行打印
extern "C"  void UNITY_INTERFACE_EXPORT ImgPrint24(char * byte, int width, int height, bool isrgb);		//isrgb or is bgr
extern "C"  void UNITY_INTERFACE_EXPORT ImgPrint32(char * byte, int width, int height, bool isrgb);
//传入Unity EncodePng进行打印
extern "C" void UNITY_INTERFACE_EXPORT UnityImgPrint(void * dataPtr, size_t length);
extern "C" void UNITY_INTERFACE_EXPORT UnityImgPrintPath(char* dataPtr);