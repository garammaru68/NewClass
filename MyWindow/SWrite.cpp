#include "SWrite.h"
#include "STimer.h"

void SWrite::push(SMsg msg)
{
	if (m_TextList.size() > 10)
	{
		m_TextList.pop_back();
	}
	m_TextList.insert(m_TextList.begin(), msg);
}
bool SWrite::Init()
{
	m_hScreenDC = GetDC(g_hWnd);
	m_hFont = CreateFont(30, 0, 0, FW_BOLD, 0, 0, 0, 0,
		DEFAULT_CHARSET, 0, 0, 0, 0,
		L"°íµñ");
	SelectObject(m_hScreenDC, m_hFont);
	return true;
}
bool SWrite::Render()
{
	if (m_hScreenDC != NULL)
	{
		//RECT rect;
		//GetClientRect(g_hWnd, &rect);
		SetBkColor(m_hScreenDC, RGB(255, 0, 0));
		SetTextColor(m_hScreenDC, RGB(0, 0, 255));
		//SetBkMode(m_hScreenDC, OPAQUE);
		for (int iMsg = 0; iMsg < m_TextList.size(); iMsg++)
		{
			DrawText(m_hScreenDC,
				m_TextList[iMsg].msg.c_str(),
				-1,
				&m_TextList[iMsg].rt,
				DT_LEFT);
			//TextOut(m_hScreenDC, 0, 0, 
			//	g_Timer.m_szBuffer, 
			//	_tcslen(g_Timer.m_szBuffer)-1);
		}
	}
	return true;
}
bool SWrite::Release()
{
	DeleteObject(m_hFont);
	ReleaseDC(g_hWnd, m_hScreenDC);
	return true;
}