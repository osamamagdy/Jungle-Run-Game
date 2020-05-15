#include "DeleteGameObjectAction.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager *pApp):Action(pApp)
{
}
void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = this->pManager->GetGrid();
	Input *pIn=pGrid->GetInput();
	pGrid->PrintErrorMessage("Double Click on the cell that you want to delete object from");
	CellPosition CellClickTest;
	CellClickTest = pIn->GetCellClicked();
	while(CellClickTest.IsValidCell()==false)
	{
		pGrid->PrintErrorMessage("Invalid Cell, double click on the cell to continue");
		CellClickTest = pIn->GetCellClicked();
	}
	Position=CellClickTest;
}
void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = this->pManager->GetGrid();
	pGrid->RemoveObjectFromCell(Position);
}
DeleteGameObjectAction::~DeleteGameObjectAction(void)
{
}
