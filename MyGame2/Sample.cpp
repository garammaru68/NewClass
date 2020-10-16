#include "Sample.h"

int APIENTRY wWinMain(		// w가 붙으면 문자열이 유니코드라는 뜻(LPWSTR)
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR    lpCmdLine,	// LP가 붙으면 포인터
	int       nCmdShow)		// 창을 어떤식으로 띄울것인가
{
	Sample demo;
	if (demo.m_Window.SetWindow(hInstance))
	{
		demo.m_Window.Run();
		return 0;
	}
	return 1;
}