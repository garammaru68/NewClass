#include "SCore.h"
bool SCore::GameInit()
{
	m_bGameRun = true;
	g_Timer.Init();
	g_Input.Init();
	Init();
	return true;
}
bool SCore::GameRelease()
{
	Release();

	g_Timer.Release();
	g_Input.Release();
	return true;
}
bool SCore::GameRun()
{
	g_Timer.Frame();
	g_Input.Frame();

	Frame();

	Render();
	g_Timer.Render();
	g_Input.Render();

	Sleep(1);
	return true;
}
bool SCore::Run()
{
	GameInit();
	while (m_bGameRun)
	{
		if (MsgProcess() == false)
		{
			m_bGameRun = false;
		}
		else
		{
			GameRun();
		}
	}
	GameRelease();
	return true;
}
