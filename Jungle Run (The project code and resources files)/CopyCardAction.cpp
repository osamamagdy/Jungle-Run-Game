#include "EditCardAction.h"
#include "CopyCardAction.h"
#include "Cell.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "Card_7.h"
#include "Card_8.h"
#include "Card_9.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include "ApplicationManager.h"

 CopyCardAction :: CopyCardAction(ApplicationManager *pApp) : Action(pApp)
{

	// Initializes the pManager pointer of Action with the passed pointer
}

 CopyCardAction :: ~CopyCardAction()
{
}

 void CopyCardAction::ReadActionParameters() 
{	
	//Getting a pointer to grid , input,output current objects

	Grid * pGrid =	pManager->GetGrid();
	Input * pIn= pGrid->GetInput();
	Output * pOut= pGrid->GetOutput();


	
	
	//gitting the needed parameter (the position of the card you need to copy)
	pOut->PrintMessage("Click on the card you want to copy");
	Pos=pIn->GetCellClicked();

	pOut->ClearStatusBar();

}

void CopyCardAction::Execute() 
{

	// The first line of any Action Execution is to read its parameter first

	this -> ReadActionParameters();

	// getter for the grid so we can read the current caards
	
	Grid * pGrid =	pManager->GetGrid();
	Card * pCard = pGrid->IsCard(Pos); 



	// if there is no card in the clicked cell the pointer will point to null
	if (pCard)
	{
		pCard->SetCount(pCard->GetCount() - 1);
		// A- Make the clipboard in the grid points to  a copy of the card pointed by "pCard" 
		pGrid->SetClipboard(pCard->Get_My_Copy(Pos));
	}
	// B- if there isn't any cards in the Cell, Print the appropriate error message on statusbar
	else 
	{
	pGrid->PrintErrorMessage("invalid cell (doesn't have cards)");
	}
	



	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the CopyCardAction


pGrid->PrintErrorMessage("Action was handled succesfully click to continue and choose another action");	

}