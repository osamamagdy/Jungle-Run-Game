#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{


	// == Here are some guideline steps (numbered below) to implement this function ==


	// -- If not ended, do the following --:

	// Getting Grid Pointer
	Grid * pGrid = pManager->GetGrid();

	// Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("Game Ended. Winner: Player" + to_string(pGrid->GetCurrentPlayer()->GetPlayerNum()));
	}
	//  If Game is still in action:
	else 
	{
		Player * ThisPlayer = pGrid->GetCurrentPlayer(); 			//Get the "current" player from pGrid
		if((pGrid->GetCurrentPlayer())->GetIsFreezed()==false)        //checks if the player is freezed (from card 8 or special attack)
		{
			// Generate a random number from 1 to 6 --> This step is done for you

			srand((int)time(NULL));               // time is for different seed each run
			int diceNumber = 1 + rand() % 6;     // from 1 to 6 --> should change seed
			if(((pGrid->GetCurrentPlayer())->GetIsPoisoned()==true)&&(pGrid->GetCurrentPlayer()->GetPoisonCount()<5))    //checks if the the player is posioned
			{
				pGrid->PrintErrorMessage("You are poisoned, click to continue");
				pGrid->PrintErrorMessage("Your actual Dice Value = "+to_string(diceNumber));
				diceNumber--;
				pGrid->GetCurrentPlayer()->IncrementPoisonCount();
			}
			// Showing DiceRoll 
			pGrid->PrintErrorMessage("Dice Value = "+ to_string(diceNumber)+", click to continue");


			// Move the currentPlayer using function Move of class player

			ThisPlayer->Move(pGrid, diceNumber);

			// Advance the current player number of pGrid
			pGrid->AdvanceCurrentPlayer();


		}
		else               //the player is already freezed
		{
			pGrid->PrintErrorMessage("You are prevented from rolling dice this turn, click to continue");
			ThisPlayer->SetIsFreezed(false);                                          //unfreeze the player after being freezed
			ThisPlayer->SetTurnCount(ThisPlayer->GetTurnCount()+1);   //increments the turn count of the freezed player
			pGrid->AdvanceCurrentPlayer();
			return;
		}
	}
}
RollDiceAction::~RollDiceAction()
{
}
