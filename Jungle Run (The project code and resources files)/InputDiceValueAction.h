#pragma once
#include "Action.h"

class InputDiceValueAction : public Action
{
private:
	int diceValue; // only parameter to be read
public:
	InputDiceValueAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual ~InputDiceValueAction();
};

