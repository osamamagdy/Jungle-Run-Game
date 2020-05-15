#include "AddCardAction.h"

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
AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{

	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	
	//Getting a pointer to grid , input,output current objects
	Grid * pGrid =	pManager->GetGrid();
	Input * pIn= pGrid->GetInput();
	Output * pOut= pGrid->GetOutput();

	//Getting the action nedded parameters (card number to be entered)

	pOut->PrintMessage("Enter the card number");
	cardNumber = pIn->GetInteger(pOut);

	//making the needed validation and guiding the user untill he enters the right number

	while (cardNumber<1||cardNumber>14)
	{   
		pOut->PrintMessage("Invalid number please enter a number between 1 - 14 ");
		cardNumber = pIn->GetInteger(pOut);
	}

	//getting the position we want to put the card in it

		pOut->PrintMessage("Click on the cell");

		cardPosition=pIn->GetCellClicked();
		
		//making one of the needed validation and guiding the user untill he clicks on the right cell 
		//(except the case of containing another game objects, it will be checked next to not breaking class res.) 


	while (cardPosition.GetCellNum()==99 || cardPosition.GetCellNum()==1 )
	{
		pOut->PrintMessage("invalid cell : the start cell and the end cell can't contain any cards, click on another cell");
		cardPosition=pIn->GetCellClicked();
	}
	
	pOut->ClearStatusBar();

}

void AddCardAction::Execute() 
{

	//reading action parameters first
	
	this -> ReadActionParameters();

	//Getting a pointer to the grid

	Grid * pGrid =	pManager->GetGrid();

	//creating a pointer to base class of all cards


	Card * pCard = NULL; 

	//making the pointer points to a new derived card class depending on the number entered by the user

	switch (cardNumber)
	{

	case -1 :
		pCard=NULL;
		break ;
	case 1:
		pCard = new CardOne(cardPosition);
		break;

	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);
		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new Card_7(cardPosition);
		break;
	case 8:
		pCard = new Card_8(cardPosition);
		break;
	case 9:
		pCard = new Card_9 (cardPosition);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	case 12:
		pCard = new CardTwelve(cardPosition);
		break;
	case 13:
		pCard = new CardThirteen(cardPosition);
		break;
	case 14:
		pCard = new CardFourteen(cardPosition);
		break;

	}

	// we check once more that the pointer is set successfully to a new object

	if (pCard)
	{
		
		//Reading card parameters as it is added for the first time

		pCard->ReadCardParameters(pGrid);


		//adding the card to the clicked cell (flase if it contains another object )

		if (pGrid->AddObjectToCell(pCard))
		{
			pCard->Draw(pGrid->GetOutput());
			

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction
		}
		else 
		{
			//count for savegrid usage
			pCard->SetCount(pCard->GetCount()-1);
			pGrid->PrintErrorMessage("invalid cell, click to continue");
		}
	}

	pGrid->PrintErrorMessage("Action was handled succesfully click to continue and choose another action");	


}