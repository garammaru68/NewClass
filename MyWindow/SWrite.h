#pragma once
#include "SStd.h"

struct SMsg
{
	RECT rt;
	wstring msg;
};
class SWrite
{
private:
	HFONT	m_hFont;
	HDC		m_hScreenDC;
	std::vector<SMsg> m_TextList;
public:
	void push(SMsg msg);
public:
	bool Init();
	bool Render();
	bool Release();
};

