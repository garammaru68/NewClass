#pragma once
#include <Windows.h>
#include <string>

class SWindow
{
public:
	// ��� ����
	HINSTANCE	m_hInstance;
	HWND		m_hWnd;
public:
	// ��� �Լ�
	bool SetWindow(HINSTANCE hInstance);
	bool Run();
public:
	SWindow();
	virtual ~SWindow();
};

