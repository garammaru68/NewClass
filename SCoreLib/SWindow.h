#pragma once
#include "SStd.h"

class SWindow
{
public:
	HWND		m_hWnd;
	HINSTANCE	m_hInstance;
	RECT		m_rtWindow;
	RECT		m_rtClient;
public:
	void	CenterWindow();
	bool	SetWindow(HINSTANCE hInstance, TCHAR* pTtileName = L"Sample", int iWidth = 800, int iHeight = 600);
	bool	Run();
	bool	Release();
	virtual bool	GameRun() { return true; };
	virtual void	MsgEvent(MSG msg) {};
	virtual bool	GameInit() { return true; };
	virtual bool	GameRelease() { return true; };
public:
	SWindow();
	virtual ~SWindow();
};

