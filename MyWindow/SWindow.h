#pragma once
#include "SStd.h"

class SWindow
{
public:
	HINSTANCE	m_hInstance;
	HWND		m_hWnd;
	MSG			m_msg;
public:
	bool	SetWindow(HINSTANCE hInstance);
	bool	MsgProcess();
public:
	SWindow();
	virtual ~SWindow();
};