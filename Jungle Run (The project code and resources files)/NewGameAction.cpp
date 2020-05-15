#include "NewGameAction.h"


NewGameAction::NewGameAction(ApplicationManager *pApp) : Action(pApp)
{
}
void NewGameAction::ReadActionParameters()
{
	return;
	//no parameters to read
}
void NewGameAction::Execute()
{
	Grid* pGrid = this->pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->ClearStatusBar();
	pGrid->ResetGame();
}
NewGameAction::~NewGameAction(void)
{
}
