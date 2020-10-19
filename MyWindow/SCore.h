#pragma once
#include "SWindow.h"
#include "STimer.h"
#include "SInput.h"

class SCore : public SWindow
{
public:
	STimer		m_Timer;
	SInput		m_Input;
	HDC			m_hScreenDC;
	HBITMAP		m_hOldBitmap;

	HDC			m_hOffScreenDC;
	HBITMAP		m_hOffScreenBitmap;
public:
	bool	GameRun();
	bool	GameInit();
	bool	GameFrame();
	bool	GameRender();
	bool	GameRelease();
	void	MsgEvent(MSG msg);

	bool	DrawDebug();
	bool	PeRender();
	bool	PostRender();
public:
	virtual bool	Init() { return true; }
	virtual bool	Frame() { return true; }
	virtual bool	Render() { return true; }
	virtual bool	Release() { return true; };
public:
	Score();
	virtual ~SCore();
};

