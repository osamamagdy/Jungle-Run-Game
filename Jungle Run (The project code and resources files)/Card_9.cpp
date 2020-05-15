#include "Card_9.h"
#include <fstream>        // Used to Write/Read into/from   external files

Card_9::Card_9 (const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	 // set the inherited cardNumber data member with the card number (1 here)
	Card ::SetCardNumber(9);
}

Card_9::~Card_9(void)
{
}



//Virtual function to use in copy,cut,paste card actions 

Card * Card_9 :: Get_My_Copy (CellPosition pos )
{
	Card * pCard = new Card_9 (pos);

	((Card_9*)pCard)->moved_to_cell_num = this->moved_to_cell_num;

	return pCard ;

}



void Card_9::ReadCardParameters(Grid * pGrid)
{
	
	
	

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	Input * pIn =  pGrid->GetInput();
	Output * pOut = pGrid->GetOutput();


	// 2- Read an Integer from the user using the Input class and set the cell number parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New Card_9: Enter the cell number ..."
	 
	pOut->PrintMessage("New card_9 : please enter the cell number you want the player to move to it ");



	//getting the number of the cell we want the palyer to move to it

	moved_to_cell_num= pIn->GetInteger(pOut); 

	//Checks that the entered number is a valid number in the grid
	while (moved_to_cell_num>99 || moved_to_cell_num<1)
	{
		pGrid ->PrintErrorMessage("Invalid input click to continue (Enter another number)");
		moved_to_cell_num= pIn->GetInteger(pOut);
	}
	// [ Note ]:
	// In Card_9, the only parameter of Card_9 is the "cell number" value to move the player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar

	pOut->ClearStatusBar();
}

void Card_9 ::Apply(Grid* pGrid, Player* pPlayer)
{
		
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply (pGrid,pPlayer);
	// 2- Move the player of pPlayer to the cell number entered by the user
	pGrid->UpdatePlayerCell(  pPlayer  ,  position.GetCellPositionFromNum(moved_to_cell_num)   ) ;

	//Applying Next effect
	if (pPlayer->GetCell()->GetGameObject() != NULL)
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
}

void Card_9::Save(ofstream &OutFile, OBJTYPE Type)
{
	if (Type == 2 && position.IsValidCell())    // Save Only if Obj Type sent is card (to make the saving process in the right order)
	{
		Card::Save(OutFile, Type);
		OutFile << " " << moved_to_cell_num << endl;  //Save card Parameters
	}
}

void Card_9::Load(ifstream& InFile)
{
	InFile >> moved_to_cell_num;   // Read Parameter
}
