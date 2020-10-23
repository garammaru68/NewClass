#include "SWindow.h"
HWND		g_hWnd = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
bool SWindow::MsgProcess()
{
	while (PeekMessage(&m_msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&m_msg);
		DispatchMessage(&m_msg);
		if (m_msg.message == WM_QUIT)
		{
			return false;
		}
	}
	return true;
}
bool SWindow::SetWindow(HINSTANCE hInstance)
{
	m_hInstance = hInstance;

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpfnWndProc = WndProc;
	wc.hInstance = m_hInstance;
	wc.lpszClassName = L"KGCAWINDOW";
	if (RegisterClassEx(&wc) == 0)
	{
		return false;
	}

	m_hWnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		L"KGCAWINDOW",
		L"MyGame2",
		WS_OVERLAPPEDWINDOW,
		300, 300, 800, 600,
		nullptr, nullptr,
		m_hInstance, nullptr);

	if (m_hWnd == NULL)
	{
		return false;
	}
	g_hWnd = m_hWnd;
	ShowWindow(m_hWnd, SW_SHOW);

	return true;
}
SWindow::SWindow()
{
	ZeroMemory(&m_msg, sizeof(MSG));
}
SWindow::~SWindow()
{
}