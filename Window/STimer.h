#pragma once
#include "SStd.h"

class STimer
{
public:
	TCHAR	m_csBuffer[MAX_PATH];
	int		m_iFPS;
	float	m_fSecondPerFrame;
	float	m_fAccumulation;

	DWORD	m_dwBeforeTick;
	float	m_fFrameTime;
	DWORD	m_dwFrameCnt;
public:
	bool	Init();
	bool	Frame();
	bool	Render();
	bool	Release();
public:
	STimer();
	virtual ~STimer();
};

