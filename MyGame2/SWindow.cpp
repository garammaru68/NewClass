#include "SWindow.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0); // WM_QUIT
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
bool SWindow::SetWindow(HINSTANCE hInstance)
{
	m_hInstance = hInstance;
	//1. 윈도우 클래스 객체 등록
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = m_hInstance;
	wc.lpszClassName = L"KGCAWINDOW";
	if (RegisterClassEx(&wc) == 0)
	{
		return false;
	}
	//2. 윈도우 생성
	m_hWnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		L"KGCAWINDOW",
		L"MyGame2",
		WS_OVERLAPPEDWINDOW,
		400, 300, 800, 600,
		nullptr, nullptr,
		hInstance, nullptr);
	if (m_hWnd == NULL)
	{
		return false;
	}
	ShowWindow(m_hWnd, SW_SHOW);
	return true;
}
//3. 윈도우 메세지 루프
bool SWindow::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // WM_QUIT
		{
			TranslateMessage(&msg); // 키 번역
			DispatchMessage(&msg);	// 프로시져 전달
			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			std::wstring msg;
			msg = L"\n";
			msg += std::to_wstring(iCount++);
			OutputDebugString(msg.c_str());
			// 게임 로직이 돌아간다
		}
	}
	return true;
}
SWindow::SWindow()
{

}
SWindow::~SWindow()
{

}