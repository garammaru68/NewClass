#ifndef KGCA
	#define KGCA
	#define _CRT_SECURE_NO_WARNINGS
	#include <Windows.h>	
	#include <tchar.h>
	#include <vector>
	#include <string>
	using namespace std;
	#pragma comment( lib, "winmm.lib")

	extern HWND		g_hWnd;
	extern RECT		g_rtClient;
	extern int		g_iFPS;
	extern float	g_fSecPerFrame;
	extern float	g_fAccumulation;
#endif
