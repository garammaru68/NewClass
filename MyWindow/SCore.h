#pragma once
#include "SWindow.h"
#include "STimer.h"
#include "SInput.h"

class SCore : public SWindow
{
public:
	bool m_bGameRun;
public:
	virtual bool	Init() { return true; };
	virtual bool	Frame() { return true; };
	virtual bool	Render() { return true; };
	virtual bool	Release() { return true; };
private:
	bool	GameInit();
	bool	GameRelease();
	bool	GameRun();
public:
	bool Run();
};

