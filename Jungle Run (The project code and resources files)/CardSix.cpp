#include "CardSix.h"
#include <fstream>        // Used to Write/Read into/from   external files


CardSix::CardSix(const CellPosition & pos): Card(pos)
{
	cardNumber = 6;

}

//Virtual function to use in copy,cut,paste card actions 


Card* CardSix :: Get_My_Copy (CellPosition pos )
{
	Card * pCard = new CardSix (pos);
	
	return pCard ;

}




void CardSix::ReadCardParameters(Grid * pGrid)
{
	// No Parameters
	pGrid->PrintErrorMessage("New card 6, if you step on it you go back as many steps as the dice said in the previous roll");
	return;
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("Card 6 Reached. Click to move back by same amount :P");

	//Getting Current Position
	CellPosition pos = pPlayer->GetCell()->GetCellPosition();

	//Changing Position by (-)tive the rolled dice so that it moves backward
	pos.AddCellNum(-1 * abs(pPlayer->GetJustRolledDiceNum()));
	pGrid->UpdatePlayerCell(pPlayer, pos);

	//Applying Next effect
	if (pPlayer->GetCell()->GetGameObject() != NULL)
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
}

void CardSix::Save(ofstream &OutFile, OBJTYPE Type)
{
	if (Type == 2 && position.IsValidCell())    // Save Only if Obj Type sent is card (to make the saving process in the right order)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;     //Parameter-less so only end the current line
	}
}
void CardSix::Load(ifstream &Infile)
{
	// No Parameters
}

CardSix::~CardSix()
{
}
