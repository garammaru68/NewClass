#pragma once
#include <Windows.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#pragma comment(lib, "Winm.lib")
using namespace std;

struct SKeyMap
{
	bool m_bFront;
	bool m_bLeft;
	bool m_bRight;
	bool m_bBack;
	bool m_bAttack;
	bool m_bJump;
	bool m_bHangul;
	bool m_bCapsLock;
	bool m_bNumLock;
};
static SKeyMap g_KeyMap;
extern float g_fGameTimer;
extern float g_fSecondPerFrame;
extern HWND g_hWnd;

template<class S>
class SSingleton
{
public:
	static S& GetInstance()
	{
		static S theSingle;
		return theSingle;
	}
};