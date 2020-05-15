#include "CardThree.h"
#include "Ladder.h"
#include <fstream>        // Used to Write/Read into/from   external files
CardThree::CardThree (const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3;
}

CardThree::~CardThree(void)
{
}

//Virtual function to use in copy,cut,paste card actions 


Card * CardThree :: Get_My_Copy (CellPosition pos )
{
	Card * pCard = new CardThree (pos);

	return pCard ;
}

void CardThree::ReadCardParameters(Grid * pGrid)
{
	// No Parameters
}

void CardThree ::Apply(Grid* pGrid, Player* pPlayer)
{
	//By Essam:
		
	CellPosition CurrentPosition = pPlayer->GetCell()->GetCellPosition();//the current cell position of the player
	if (pGrid->GetNextLadder(CurrentPosition) != NULL) //if there exists a ladder ahead
	{
		CurrentPosition=(abs(pGrid->GetNextLadder(CurrentPosition)->GetStartPosition().GetCellNum()));//move the player to that position
   	pGrid->PrintErrorMessage("Ladder ahead, Up Up Up");
		pGrid->UpdatePlayerCell(pPlayer, CurrentPosition);	//now let him climb the ladder
		pGrid->PrintErrorMessage("You have reached a Ladder. Click to continue ...");
		pGrid->UpdatePlayerCell(pPlayer, abs(pGrid->GetNextLadder(CurrentPosition)->GetEndPosition().GetCellNum()));
		if (pPlayer->GetCell()->GetGameObject() != NULL)//just to take cards after climbing the ladder
			(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
	}
	else
			pGrid->PrintErrorMessage("No ladders ahead...");//No ladders ahead...


	
	

}
void CardThree::Save(ofstream& OutFile, OBJTYPE Type)
{

	if (Type == 2 && position.IsValidCell())    // Save Only if Obj Type sent is card (to make the saving process in the right order)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;     //Parameter-less so only end the current line
	}
}
void CardThree::Load(ifstream& Infile)
{
	// No Parameters
}