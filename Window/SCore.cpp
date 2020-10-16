#include "SCore.h"
bool SCore::GameInit()
{
	m_Timer.Init();

	m_hScreenDC = GetDC(m_hWnd);

	m_hOffScreenDC = CreateCompatibleDC(m_hScreenDC);
	m_hOffScreenBitmap = CreateCompatibleBitmap(
		m_hScreenDC,
		m_rtClient.right,
		m_rtClient.bottom);
	m_hOldBitmap = (HBITMAP)SelectObject(m_hOffScreenDC, m_hOffScreenBitmap);

	Init();
	return true;
}
bool SCore::GameRelease()
{
	Release();
	SelectObject(m_hOffScreenDC, m_hOldBitmap);
	ReleaseDC(m_hWnd, m_hScreenDC);
	m_Timer.Release();
	return true;
}
bool SCore::GameFrame()
{
	m_Timer.Frame();
	Frame();
	return true;
}
bool SCore::PreRender()
{
	COLORREF bkColor = RGB(255, 255, 255);
	HBRUSH hbrBack = CreateSolidBrush(bkColor);
	SelectObject(m_hOffScreenDC, hbrBack);
	PatBlt(m_hOffScreenDC, 0, 0, m_rtClient.right, m_rtClient.bottom, PATCOPY);
	return true;
}
bool SCore::PostRender()
{
	BitBlt(m_hScreenDC, m_rtClient.left, m_rtClient.top, m_rtClient.right, m_rtClient.bottom,
		m_hOffScreenDC, 0, 0, SRCCOPY);
	return true;
}
bool SCore::DrawDebug()
{
	RECT rect;
	if (m_hOffScreenDC != NULL)
	{
		GetClientRect(m_hWnd, &rect);
		SetBkColor(m_hOffScreenDC, RGB(255, 0, 0));
		SetTextColor(m_hOffScreenDC, RGB(0, 0, 255));
		SetBkMode(m_hOffScreenDC, TRANSPARENT);

		DrawText(m_hOffScreenDC, m_Timer.m_csBuffer, -1,
			&rect, DT_LEFT | DT_VCENTER);
	}
	return true;
}
bool SCore::GameRender()
{
	PreRender();
	Render();
	m_Timer.Render();
	DrawDebug();
	PostRender();
	return true;
}
bool SCore::GameRun()
{
	GameFrame();
	GameRender();
	return true;
}
void SCore::MsgEvent(MSG msg)
{
}

SCore::SCore()
{
}
SCore::~SCore()
{
}