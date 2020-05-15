#include "AddCardAction.h"
#include "PasteCardAction.h"
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
PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{

	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters() 
{	
	// 1- Get a Pointer to the Input / Output Interfaces
	
	Grid * pGrid =	pManager->GetGrid();
	Input * pIn= pGrid->GetInput();
	Output * pOut= pGrid->GetOutput();


	// 2- Read the "Pos" parameter (its cell position) and set its data member
	pOut->PrintMessage("Click on the cell you want to paste the card in ");

	Pos=pIn->GetCellClicked();

		//making one of the needed validation and guiding the user untill he clicks on the right cell 
		//(except the case of containing another game objects, it will be checked next to not breaking class res.) 


	while (Pos.GetCellNum()==99 || Pos.GetCellNum()==1 )
	{
		pOut->PrintMessage("invalid cell : the start cell and the end cell can't contain any cards, click on another cell");
		Pos=pIn->GetCellClicked();
	}


	// 3- Clear status bar

	pOut->ClearStatusBar();

}

void PasteCardAction::Execute() 
{

	// 1- The first line of any Action Execution is to read its parameter first

	this -> ReadActionParameters();

	
	//	//Getting a pointer to the grid and output


    Grid * pGrid =	pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	
	//creating a pointer to base class of all cards

	
	Card * pCard = NULL ;


	//if the clipboard isn't empty

	if ((pGrid->GetClipboard()) != NULL  )
	   pCard = (pGrid->GetClipboard())->Get_My_Copy(Pos); ; // pCard will point to another card object similar to that in the clipboard


	//checks the pCard pointer,if it points to a card then we well add it to the cell 
	//(also we check if the card can be added to the cell)
	//depending on each case we print the approbiate error message
	if (pCard)
	{	
		if (pGrid->AddObjectToCell(pCard))
		{
			pCard->Draw(pGrid->GetOutput());
		}
		else
		{
			pOut->PrintMessage("invalid cell");
		}
	}

	else
	{
		pGrid->PrintErrorMessage("the clipboard doesn't contain any cards,click to continue");
	}


	pGrid->PrintErrorMessage("Action was handeled succesfully click to continue and choose another action");



	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction
}