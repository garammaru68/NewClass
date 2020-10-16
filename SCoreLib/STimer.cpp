#include "STimer.h"

int		g_iFPS;
float	g_fSecPerFrame;
float	g_fAccumulation;

bool STimer::Init()
{
	m_dwBeforeTick = timeGetTime();
	ZeroMemory(m_csBuffer, sizeof(TCHAR)* MAX_PATH);
	return true;
};

bool STimer::Frame()
{
	DWORD dwCurrentTick = timeGetTime();
	DWORD dwElapseTick = dwCurrentTick - m_dwBeforeTick;

	g_fSecPerFrame = m_fSecondPerFrame = dwElapseTick / 1000.0f;
	g_fAccumulation = m_fAccumulation += m_fSecondPerFrame;
	m_fFrameTime += m_fSecondPerFrame;

	if (m_fFrameTime > 1.0f)
	{
		g_iFPS = m_iFPS = m_dwFrameCnt;
		m_dwFrameCnt = 0;
		m_fFrameTime -= 1.0f;
	}

	m_dwFrameCnt++;
	m_dwBeforeTick = dwCurrentTick;
	return true;
}

bool STimer::Render()
{
	_stprintf_s(m_csBuffer, L"Timer:[%10.4f] FPS:[%d] %10.4f\n", 
		m_fAccumulation, m_iFPS, m_fSecondPerFrame);
	return true;
};

bool STimer::Release()
{
	return true;
}

STimer::STimer()
{
	m_iFPS				= 0;
	m_dwFrameCnt		= 0;
	m_fSecondPerFrame	= 0.0f;
	m_fAccumulation		= 0.0f;
	m_fFrameTime		= 0.0f;
}
STimer::~STimer()
{
}