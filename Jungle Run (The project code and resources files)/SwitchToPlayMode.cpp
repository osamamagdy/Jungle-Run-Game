#include "SwitchToPlayMode.h"



SwitchToPlayMode::SwitchToPlayMode(ApplicationManager *pApp) : Action(pApp)
{
}
void SwitchToPlayMode::ReadActionParameters()
{
	return;
	//no parameters to read
}
void SwitchToPlayMode::Execute()
{
	// Getting Grid Pointer
	Grid* pGrid = this->pManager->GetGrid();
	pGrid->GetOutput()->CreatePlayModeToolBar(); 
	pManager->ExecuteAction(NEW_GAME);  // Reset Player Info
}


SwitchToPlayMode::~SwitchToPlayMode()
{
}
