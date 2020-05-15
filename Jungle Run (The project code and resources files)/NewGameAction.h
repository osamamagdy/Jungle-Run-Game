#include"Action.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTen.h"
class NewGameAction : public Action
{
public:
	NewGameAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~NewGameAction(void);
};

