#include "Sample.h"

int APIENTRY wWinMain(		// w�� ������ ���ڿ��� �����ڵ��� ��(LPWSTR)
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR    lpCmdLine,	// LP�� ������ ������
	int       nCmdShow)		// â�� ������� �����ΰ�
{
	Sample demo;
	if (demo.m_Window.SetWindow(hInstance))
	{
		demo.m_Window.Run();
		return 0;
	}
	return 1;
}