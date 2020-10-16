#pragma once
#include <Windows.h>
#include <string>

class SWindow
{
public:
	// ¸â¹ö º¯¼ö
	HINSTANCE	m_hInstance;
	HWND		m_hWnd;
public:
	// ¸â¹ö ÇÔ¼ö
	bool SetWindow(HINSTANCE hInstance);
	bool Run();
public:
	SWindow();
	virtual ~SWindow();
};

