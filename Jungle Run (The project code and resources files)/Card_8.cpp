#include "Card_8.h"
#include <fstream>        // Used to Write/Read into/from   external files


Card_8::Card_8 (const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	 // set the inherited cardNumber data member with the card number (8 here)
	Card ::SetCardNumber(8);
}

Card_8::~Card_8(void)
{
}

void Card_8::ReadCardParameters(Grid * pGrid)
{
	pGrid->PrintErrorMessage(" New card 8, if you step on it , you will be freezed for the next turn");

	 
}



//Virtual function to use in copy,cut,paste card actions 


Card * Card_8:: Get_My_Copy (CellPosition pos )
{
	Card * pCard = new Card_8(pos);

	return pCard;

}



void Card_8 ::Apply(Grid* pGrid, Player* pPlayer)
{

	pGrid->PrintErrorMessage("you won't be able to move the next turn click to continue");

	pPlayer=pGrid->GetCurrentPlayer();
	pPlayer->SetIsFreezed(true);

}
void Card_8::Save(ofstream &OutFile, OBJTYPE Type)
{
	if (Type == 2 && position.IsValidCell())    // Save Only if Obj Type sent is card (to make the saving process in the right order)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;     //Parameter-less so only end the current line
	}
}
void Card_8::Load(ifstream& Infile)
{
	// No Parameters
}