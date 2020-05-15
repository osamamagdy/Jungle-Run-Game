#include "AddLadderAction.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	exit = false;	//a flag to check for validations
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}
//Zero arg constructor


void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	///TODO: Make the needed validations on the read parameters

		// The start cell should be before the end cell in the grid:
	if (startPos.GetCellNum() >= endPos.GetCellNum())
	{
		pOut->PrintMessage("The start cell should be before the end cell in the grid");
		exit = true;
		return;
	}
	// For simplicity, the start and end cell should be in the same column:
	if (startPos.HCell() != endPos.HCell())
	{
		pOut->PrintMessage("the start and end cell should be in the same column");
		exit = true;
		return;
	}
	
   //nor a cell in the last row:
	if (startPos.VCell() == 0)
	{
		pOut->PrintMessage("the start cell shouldn't be in the last row.");
		exit = true;
		return;
	}
	if (startPos.VCell() == 8 && startPos.HCell() == 0)
	{
		pOut->PrintMessage("the start cell shouldn't be in the first cell");
		exit = true;
		return;
	}
	

// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if (exit)
		return;	//checks for all of the previos validations(Essam)
	// Create a Ladder object with the parameters read from the user



	Grid * pGrid = pManager->GetGrid();
	Ladder * pLadder = new Ladder(startPos, endPos);

	if (pGrid->IsOverlapping(pLadder)) //Checks for overlapping(Essam)
	{
		pGrid->PrintErrorMessage("Overlapping Isn't allowed, please choose a different position");
		return;
	}
	/// We get a pointer to the Grid from the ApplicationManager
	else
	{

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pLadder);


		// if the GameObject cannot be added
		if (!added)
		{
			pLadder->SetCount(pLadder->GetCount() - 1);
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

	}
}