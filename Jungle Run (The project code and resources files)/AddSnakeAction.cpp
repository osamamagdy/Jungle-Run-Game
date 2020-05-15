
#pragma once
#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
	exit = false; 
	// Initializes the pManager pointer of Action with the passed pointer and declares a boolean as a flag to check for validations(Essam)
}

AddSnakeAction::~AddSnakeAction()
{
}// Zero Argument Constructor(Essam)


void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	// the number of taken blocks(Essam):



	///TODO: Make the needed validations on the read parameters(Essam)

		// The start cell should be before the end cell in the grid:
	if (startPos.GetCellNum() <= endPos.GetCellNum())
	{
		pOut->PrintMessage("The start cell should be after the end cell in the grid");
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
	if (startPos.VCell() == 8)
	{
		pOut->PrintMessage("the start cell shouldn't be in the first row.");
		exit = true;
		return;
	}

	if (startPos.VCell() == 0 && startPos.HCell() == 10)
	{
		pOut->PrintMessage("the start cell shouldn't be in the last cell");
		exit = true;
		return;
	}


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if (exit)
		return;//checks for all of the previos validations (Essam)
	// Create a Snake object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	if (pGrid->IsOverlapping(pSnake)) //Checks for overlapping (Essam)
	{
		pGrid->PrintErrorMessage("Overlapping Isn't allowed, please choose a different position");
		return;
	}
	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);
	//pSnake->Draw(pGrid->GetOutput());
	// if the GameObject cannot be added
	if (!added)
	{
		pSnake->SetCount(pSnake->GetCount()-1);
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction

}