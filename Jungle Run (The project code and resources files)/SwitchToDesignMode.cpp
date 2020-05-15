#include "SwitchToDesignMode.h"



SwitchToDesignMode::SwitchToDesignMode(ApplicationManager *pApp): Action(pApp)
{
}
void SwitchToDesignMode::ReadActionParameters()
{
	return;
	//no parameters to read
}
void SwitchToDesignMode::Execute()
{
	// Getting Grid Pointer
	Grid* pGrid = this->pManager->GetGrid();
	pGrid->GetOutput()->CreateDesignModeToolBar(); 
	pManager->ExecuteAction(NEW_GAME);   // Reset Player Info
}

SwitchToDesignMode::~SwitchToDesignMode()
{
}
