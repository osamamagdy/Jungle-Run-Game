#include "SaveGridAction.h"
#include "Grid.h"
#include "DEFS.h"
#include <fstream>        // Used to Write/Read into/from   external files
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include "Ladder.h"
#include "Snake.h"
SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
}
void SaveGridAction::ReadActionParameters()
{
	// Reading FileName to Open

	pManager->GetGrid()->PrintErrorMessage("Please Enter File Name.");

	FileName = pManager->GetGrid()->GetInput()->GetSrting(pManager->GetGrid()->GetOutput());
	FileName += ".txt";   // adding file extention to the name
	pManager->GetGrid()->GetOutput()->ClearStatusBar();

	pManager->GetGrid()->PrintErrorMessage("You Entered: " + FileName + ", Click to continue");
	pManager->GetGrid()->GetOutput()->ClearStatusBar();
}
void SaveGridAction::Execute()
{
	// Resetting save status of card10-14 to make their price and fees re-save-able   
	CardTen::SetSavedStatus(false);
	CardEleven::SetSavedStatus(false);
	CardTwelve::SetSavedStatus(false);
	CardThirteen::SetSavedStatus(false);
	CardFourteen::SetSavedStatus(false);

	// Getting file name
	ReadActionParameters();

	// Openning file to write into
	ofstream OutFile;
	OutFile.open(FileName);

	// Saving Ladders, Snakes then Cards Respectivly ..
	// Sending Obj Type To Specify Order
	pManager->GetGrid()->SaveAll(OutFile, LADDER_TYPE);
	pManager->GetGrid()->SaveAll(OutFile, SNAKE_TYPE);
	pManager->GetGrid()->SaveAll(OutFile, CARD_TYPE);

	// Closing File
	OutFile.close();
}

SaveGridAction::~SaveGridAction()
{
}
