#include "CardFive.h"
#include <fstream>        // Used to Write/Read into/from   external files



CardFive::CardFive(const CellPosition & pos): Card(pos)
{
	cardNumber = 5;
}

void CardFive::ReadCardParameters(Grid * pGrid)
{
	// No Parameters
	pGrid->PrintErrorMessage("New card 5, if you step on it you go forward as many steps as the dice said in the previous roll");
	return;
}

//Virtual function to use in copy,cut,paste card actions 

Card* CardFive :: Get_My_Copy (CellPosition pos )
{
	Card * pCard = new CardFive (pos);

	return pCard ;

}




void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("#Super_Dice Reached(Card5). Click to move by same amount again");

	//Getting Current Position
	CellPosition pos = pPlayer->GetCell()->GetCellPosition();

	//Changing Position by the rolled dice so that it moves again
	pos.AddCellNum(abs(pPlayer->GetJustRolledDiceNum()));
	pGrid->UpdatePlayerCell(pPlayer, pos);

	//Applying Next effect
	if(pPlayer->GetCell()->GetGameObject()!=NULL) 
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid,pPlayer);
}

void CardFive::Save(ofstream& OutFile, OBJTYPE Type)
{

	if (Type == 2 && position.IsValidCell())    // Save Only if Obj Type sent is card (to make the saving process in the right order)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;     //Parameter-less so only end the current line
	}
}
void CardFive::Load(ifstream &Infile)
{
	// No Parameters
}

CardFive::~CardFive()
{
}
