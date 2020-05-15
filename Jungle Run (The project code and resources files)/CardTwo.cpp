#include "CardTwo.h"
#include "Output.h"
#include <fstream>        // Used to Write/Read into/from   external files
CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}

//Virtual function to use in copy,cut,paste card actions 

Card* CardTwo::Get_My_Copy(CellPosition pos)
{
	Card* pCard = new CardTwo(pos);

	((CardTwo*)pCard)->walletAmount = walletAmount;

	return pCard;

}


void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//Done By Essam:

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* PO = pGrid->GetOutput();
	PO->PrintMessage("New CardTwo: Enter its wallet amount ...");
	Input* PI = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it

	walletAmount = PI->GetInteger(PO);


	//    Don't forget to first print to a descriptive message to the user like:"New CardTwo: Enter its wallet amount ..."

	// [ Note ]:
	// In CardTwo, the only parameter of CardOne is the "walletAmount" value to increase to the player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	PO->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	//Done by Essam:
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);

}
void CardTwo::Save(ofstream& OutFile, OBJTYPE Type)
{
	if (Type == 2 && position.IsValidCell())    // Save Only if Obj Type sent is card (to make the saving process in the right order)
	{
		Card::Save(OutFile, Type);
		OutFile << " " << walletAmount << endl; //Save card Parameters
	}
}

void CardTwo::Load(ifstream& InFile)
{
	InFile >> walletAmount; // Read Parameter
}
