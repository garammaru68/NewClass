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

ATOM MyRegisterClass(HINSTANCE hInstance, const WCHAR* szClassName)	// 윈도우 클래스를 운영체제에 등록합니다
{
	WNDCLASSEXW wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEXW));
	wcex.cbSize = sizeof(WNDCLASSEX);		// 클래스의 크기
	wcex.style = CS_HREDRAW | CS_VREDRAW;	// 가로 | 세로 그리겠다(DRAW)
	wcex.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wcex.lpfnWndProc = WndProc;			// 운영체제 ->윈도우프로시져(메세지큐) ->메세지 윈도우	// 윈도우 -> 윈도우지원함수 -> 운영체제
	wcex.hInstance = hInstance;
	wcex.lpszClassName = szClassName;
	return RegisterClassExW(&wcex);
}

int APIENTRY wWinMain(		// w가 붙으면 문자열이 유니코드라는 뜻(LPWSTR)
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR    lpCmdLine,	// LP가 붙으면 포인터
	int       nCmdShow)		// 창을 어떤식으로 띄울것인가
{
	// 예매
	MyRegisterClass(hInstance, L"KGCA1");
	if (!InitInstance(L"KGCA1", L"xxxxx", hInstance, nCmdShow))
	{
		return FALSE;
	}
	// 윈도우 생성
	MSG msg;
	while (1)
	{
		if (PeekMessage(&msg, g_hWnd, 0, 0, PM_REMOVE)) // WM_QUIT
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
			// 게임 로직이 돌아간다
		}
	}
	MessageBox(NULL, L"종료", L"sample", MB_OK);
	// MessageBoxA(NULL, L"test", L"sample", MB_OK);	// 멀티바이트
	// MessageBoxW(NULL, L"test", L"sample", MB_OK);	// 유니코드
}