#pragma once
#include "Action.h"
class OpenGridAction :
	public Action
{
private:
	string FileName;
public:
	OpenGridAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~OpenGridAction();
};
