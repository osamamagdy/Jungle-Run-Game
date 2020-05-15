#include "Card_7.h"
#include <time.h> // used to in srand to generate random numbers with different seed
#include <fstream>        // Used to Write/Read into/from   external files

Card_7::Card_7(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	// set the inherited cardNumber data member with the card number (7 here)
	Card::SetCardNumber(7);
}

Card_7::~Card_7(void)
{
}


//Virtual function to use in copy,cut,paste card actions 
Card* Card_7::Get_My_Copy(CellPosition pos)
{
	Card* pCard = new Card_7(pos);

	return pCard;
}


void Card_7::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("New card 7, if you step on it you will take another roll dice");
}

void Card_7::Apply(Grid* pGrid, Player* ThisPlayer)
{
	pGrid->PrintErrorMessage("You take another roll dice ");
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("Game Ended. Winner: Player" + to_string(pGrid->GetCurrentPlayer()->GetPlayerNum()));
	}
	else
	{
		if (true)
		{
			srand((int)time(NULL)); // time is for different seed each run
			int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
			if (((pGrid->GetCurrentPlayer())->GetIsPoisoned() == true) && (pGrid->GetCurrentPlayer()->GetPoisonCount() < 5))
			{
				pGrid->PrintErrorMessage("You are poisoned, click to continue");
				pGrid->PrintErrorMessage("Your actual Dice Value = " + to_string(diceNumber));
				diceNumber--;
				pGrid->GetCurrentPlayer()->IncrementPoisonCount();
			}
			// 3- Get the "current" player from pGrid

			pGrid->PrintErrorMessage("Dice Value = " + to_string(diceNumber) + ", click to continue");


			// 4- Move the currentPlayer using function Move of class player
			CellPosition pos = ThisPlayer->GetCell()->GetCellPosition();
			pos.AddCellNum(diceNumber);
			pGrid->UpdatePlayerCell(ThisPlayer, pos);

			//Applying Next effect
			if (ThisPlayer->GetCell()->GetGameObject() != NULL)
				(ThisPlayer->GetCell()->GetGameObject())->Apply(pGrid, ThisPlayer);


		}
		else
		{
			pGrid->PrintErrorMessage("You are prevented from rolling dice this turn, click to continue");
			ThisPlayer->SetIsFreezed(false);
			ThisPlayer->SetTurnCount(pGrid->GetCurrentPlayer()->GetTurnCount() + 1);
			pGrid->AdvanceCurrentPlayer();
			return;
		}
	}



}
void Card_7::Save(ofstream& OutFile, OBJTYPE Type)
{
	if (Type == 2 && position.IsValidCell())    // Save Only if Obj Type sent is card (to make the saving process in the right order)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;     //Parameter-less so only end the current line
	}
}
void Card_7::Load(ifstream& Infile)
{
	// No Parameters
}
