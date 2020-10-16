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
	//1. ������ Ŭ���� ��ü ���
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
	//2. ������ ����
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
//3. ������ �޼��� ����
bool SWindow::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // WM_QUIT
		{
			TranslateMessage(&msg); // Ű ����
			DispatchMessage(&msg);	// ���ν��� ����
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
			// ���� ������ ���ư���
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