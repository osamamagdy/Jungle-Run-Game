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
#include "CutCardAction.h"
 CutCardAction :: CutCardAction(ApplicationManager *pApp) : Action(pApp)
{

	// Initializes the pManager pointer of Action with the passed pointer
}

 CutCardAction :: ~CutCardAction()
{
}

 void CutCardAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	
	Grid * pGrid =	pManager->GetGrid();
	Input * pIn= pGrid->GetInput();
	Output * pOut= pGrid->GetOutput();

		cardNumber=-1; //using this to draw an embty cell after deleating the 
	
	// 2- Read the "Pos" parameter (its cell position) and set its data member

	pOut->PrintMessage("Click on the card you want to cut");
	Pos=pIn->GetCellClicked();

	pOut->ClearStatusBar();

}

void CutCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first

	this -> ReadActionParameters();

	


	// 2- getter for the grid so we can read the current caards
	
	Grid * pGrid =	pManager->GetGrid();
	Card * pCard = pGrid->IsCard(Pos); // points to the card object we need to cut
	Output * pOut = pGrid->GetOutput();

	// 3- if there is no card in the clicked cell the pointer will point to null
	if (pCard)
	{
		pCard->SetCount(pCard->GetCount() - 1);
		// A- Make the clipboard in the grid takes the "pCard" 
		pGrid->SetClipboard(pCard->Get_My_Copy(Pos));
		
		//B-then deleate the card from the cell
		
		pGrid->RemoveCardFromCell(Pos);

		//C-draw the empty the cell

		pOut->DrawCell(Pos);
	
	}

	// D- if there isn't any cards in the Cell, Print the appropriate error message on statusbar
	else 
	{
	pGrid->PrintErrorMessage("invalid cell (doesn't have cards)");
	}		
	// Here, the card is copied and removed the GameObject from its Cell, so we finished executing the CutCardAction
	
	
	pGrid->PrintErrorMessage("Action was handled succesfully click to continue and choose another action");	

}