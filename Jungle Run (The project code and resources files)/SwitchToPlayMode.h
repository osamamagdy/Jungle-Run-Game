#include "Input.h"
#include "Output.h"
#include "Action.h"
#include "Grid.h"

class SwitchToPlayMode :
	public Action
{
public:
	SwitchToPlayMode(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SwitchToPlayMode();
};
