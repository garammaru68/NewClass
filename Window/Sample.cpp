#include "Sample.h"

bool		Sample::Init()
{
	TCHAR  str[] = _T("NAME");
	TCHAR  str2[] = _T("NAME");
	_tcscpy(str, str2);
	return true;
};
bool		Sample::Frame()
{
	return true;
};
bool		Sample::Render()
{
	RECT rect;
	if (m_hOffScreenDC != NULL)
	{
		SetBkColor(m_hOffScreenDC, RGB(255, 0, 0));
		SetTextColor(m_hOffScreenDC, RGB(0, 0, 255));
		SetBkMode(m_hOffScreenDC, TRANSPARENT);
	}
	return true;
};
Sample::Sample()
{
}


Sample::~Sample()
{
}
int WINAPI wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR    lpCmdLine,
	int       nCmdShow)
{
	Sample sample;
	if (sample.SetWindow(hInstance, L"SampleWin", 800, 600))
	{
		sample.Run();
	}
}