#pragma once
#include "Input.h"
#include "Grid.h"
#include "Output.h"
#include "Action.h"
class SwitchToDesignMode :
	public Action
{
public:
	SwitchToDesignMode(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SwitchToDesignMode();
};

