#pragma once
#include "Action.h"
class SaveGridAction :
	public Action
{
private:
	string FileName;
public:
	SaveGridAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SaveGridAction();
};

