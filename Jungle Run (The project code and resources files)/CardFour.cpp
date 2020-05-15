#include "CardFour.h"
#include "Snake.h"
#include <fstream>        // Used to Write/Read into/from   external files

CardFour::CardFour (const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	 // set the inherited cardNumber data member with the card number (4 here)
	Card ::SetCardNumber(4);
}

CardFour::~CardFour(void)
{
}

//Virtual function to use in copy,cut,paste card actions 


Card* CardFour :: Get_My_Copy (CellPosition pos )
{
	Card * pCard = new CardFour (pos);	
	return pCard ;

}



void CardFour::ReadCardParameters(Grid * pGrid)
{
	// No Parameters
}

void CardFour ::Apply(Grid* pGrid, Player* pPlayer)
{
		//By Essam:
	CellPosition CurrentPosition = pPlayer->GetCell()->GetCellPosition();//the current position of the player
	if (pGrid->GetNextSnake(CurrentPosition) != NULL)//if there exists a snake ahead
	{
		CurrentPosition = (abs(pGrid->GetNextSnake(CurrentPosition)->GetStartPosition().GetCellNum()));//move the player to that position
		pGrid->PrintErrorMessage("Snakes ahead, ssssss");

		pGrid->UpdatePlayerCell(pPlayer, CurrentPosition);
		pGrid->PrintErrorMessage("You reached a Snake, click to continute");
		pGrid->UpdatePlayerCell(pPlayer, (abs(pGrid->GetNextSnake(CurrentPosition)->GetEndPosition().GetCellNum())));//let him slide through the snake
		if (pPlayer->GetCell()->GetGameObject() != NULL)//if there is a card, apply its action.
			(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
	}
	else
		pGrid->PrintErrorMessage("No Snakes ahead...");//No snakes ahead




}
void CardFour::Save(ofstream& OutFile, OBJTYPE Type)
{

	if (Type == 2 && position.IsValidCell())    // Save Only if Obj Type sent is card (to make the saving process in the right order)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;     //Parameter-less so only end the current line
	}
}

void CardFour::Load(ifstream& Infile)
{
	// No Parameters
}