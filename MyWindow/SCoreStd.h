#pragma once
#include "SStd.h"
#define SGAME_START int APIENTRY wWindMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
#define SGAME_RUN	if (demo.SetWindow(hInstance)){demo.Run();}return 1;}
#define GAMERUN SGAME_START;SGAME_RUN;