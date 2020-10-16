#pragma once
#include "SCore.h"
class Sample : public SCore
{
public:
	bool		Init();
	bool		Frame();
	bool		Render();
public:
	Sample();
	virtual ~Sample();
};

