#include <windows.h>
HWND g_hWnd;
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

BOOL InitInstance(	const WCHAR* szWindowClass, 
					const WCHAR* szTitle, 
					HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd = CreateWindowW(
		szWindowClass, 
		szTitle, 
		WS_OVERLAPPEDWINDOW,
		0, 0, 800, 600, 
		nullptr, nullptr, 
		hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, SW_SHOWNORMAL); // nCmdShow
	//UpdateWindow(hWnd);
	g_hWnd = hWnd;
	return TRUE;
}

ATOM MyRegisterClass(HINSTANCE hInstance, const WCHAR* szClassName)	// ������ Ŭ������ �ü���� ����մϴ�
{
	WNDCLASSEXW wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEXW));
	wcex.cbSize = sizeof(WNDCLASSEX);		// Ŭ������ ũ��
	wcex.style = CS_HREDRAW | CS_VREDRAW;	// ���� | ���� �׸��ڴ�(DRAW)
	wcex.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wcex.lpfnWndProc = WndProc;			// �ü�� ->���������ν���(�޼���ť) ->�޼��� ������	// ������ -> �����������Լ� -> �ü��
	wcex.hInstance = hInstance;
	wcex.lpszClassName = szClassName;
	return RegisterClassExW(&wcex);
}

int APIENTRY wWinMain(		// w�� ������ ���ڿ��� �����ڵ��� ��(LPWSTR)
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR    lpCmdLine,	// LP�� ������ ������
	int       nCmdShow)		// â�� ������� �����ΰ�
{
	// ����
	MyRegisterClass(hInstance, L"KGCA1");
	if (!InitInstance(L"KGCA1", L"xxxxx", hInstance, nCmdShow))
	{
		return FALSE;
	}
	// ������ ����
	MSG msg;
	while (1)
	{
		if (PeekMessage(&msg, g_hWnd, 0, 0, PM_REMOVE)) // WM_QUIT
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
			// ���� ������ ���ư���
		}
	}
	MessageBox(NULL, L"����", L"sample", MB_OK);
	// MessageBoxA(NULL, L"test", L"sample", MB_OK);	// ��Ƽ����Ʈ
	// MessageBoxW(NULL, L"test", L"sample", MB_OK);	// �����ڵ�
}