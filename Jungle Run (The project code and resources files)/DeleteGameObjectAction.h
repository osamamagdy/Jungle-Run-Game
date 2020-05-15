#include"Action.h"
#include"CellPosition.h"
#include"Output.h"
#include"Input.h"
#include"GameObject.h"

class DeleteGameObjectAction: public Action
{
	CellPosition Position;
public:
	DeleteGameObjectAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~DeleteGameObjectAction(void);
};

