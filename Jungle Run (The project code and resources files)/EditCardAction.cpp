#include "EditCardAction.h"
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
 EditCardAction :: EditCardAction(ApplicationManager *pApp) : Action(pApp)
{

	// Initializes the pManager pointer of Action with the passed pointer
}

 EditCardAction :: ~EditCardAction()
{
}

 void EditCardAction::ReadActionParameters() 
{	

	
	// 1- Get a Pointer to the Input / Output Interfaces
	
	Grid * pGrid =	pManager->GetGrid();
	Input * pIn= pGrid->GetInput();
	Output * pOut= pGrid->GetOutput();


	
	
	// 2- Read the "Pos" parameter (its cell position) and set its data member

	pOut->PrintMessage("Click on the card you want to edit");
	Pos=pIn->GetCellClicked();

	pOut->ClearStatusBar();

}

void EditCardAction::Execute() 
{

	
	// 1- The first line of any Action Execution is to read its parameter first

	this -> ReadActionParameters();

	


	// 2- getter for the grid so we can read the current caards
	
	Grid * pGrid =	pManager->GetGrid();
	Card * pCard = pGrid->IsCard(Pos); // points to the card object we need to edit
	
	// 3- if there is no card in the clicked cell the pointer will point to null
	if (pCard)
	{
		
		//A-We enable the editting of the card parameters (must be done in cards 10-14 as they all have static parameters )

		pCard->EnableEdit();

		
		// B- Make the "pCard" reads its card parameters again : ReadCardParameters(), It is virtual and depends on the card type

		pCard->ReadCardParameters(pGrid);
	}
	// C- if there isn't any cards in the Cell, Print the appropriate error message on statusbar
	else 
	{
	pGrid->PrintErrorMessage("invalid cell (doesn't have cards)");
	}
	



	// Here, the card is editted , so we finished executing the EditCardAction


pGrid->PrintErrorMessage("Action was handled succesfully click to continue and choose another action");	

}