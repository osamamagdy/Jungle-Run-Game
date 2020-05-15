#include "InputDiceValueAction.h"
#include "Grid.h"
#include "Player.h"


InputDiceValueAction::InputDiceValueAction(ApplicationManager *pApp): Action(pApp)
{
	diceValue = 0; //defualt value
}

void InputDiceValueAction::ReadActionParameters()
{
	// Asking the User for a valid dice value in 1-6 range
	do
	{
		pManager->GetGrid()->PrintErrorMessage("Please enter a dice value between 1-6");
		diceValue = ((pManager->GetGrid())->GetInput())->GetInteger((pManager->GetGrid())->GetOutput());
	} while (diceValue > 6 || diceValue < 1);
}

void InputDiceValueAction::Execute()
{

	// Getting Grid Pointer
	Grid * ThisGrid = pManager->GetGrid();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (ThisGrid->GetEndGame())
	{
		ThisGrid->PrintErrorMessage("Game Ended. Winner: Player" + to_string(ThisGrid->GetCurrentPlayer()->GetPlayerNum()));
	}
	//  If Game is still in action:
	else
	{
		Player * ThisPlayer = ThisGrid->GetCurrentPlayer();  // Pointer to current player
		if((ThisGrid->GetCurrentPlayer())->GetIsFreezed()==false)   //checks if the player is freezed
		{

			ReadActionParameters(); // Getting "Input"ed dice value
			if(((ThisGrid->GetCurrentPlayer())->GetIsPoisoned()==true)
				&&(ThisGrid->GetCurrentPlayer()->GetPoisonCount()<5)) //checks if the player is poisoned
			{
				ThisGrid->PrintErrorMessage("You are poisoned, click to continue");
				ThisGrid->PrintErrorMessage("Your actual Dice Value = "+to_string(diceValue));
				diceValue--;
				ThisGrid->GetCurrentPlayer()->IncrementPoisonCount();
			}
			// Move the currentPlayer using function Move of class player
			ThisPlayer->Move(ThisGrid, diceValue); 

			// Advance the current player number of pGrid
			ThisGrid->AdvanceCurrentPlayer();
		}
		else
		{
			ThisGrid->PrintErrorMessage("You are prevented from rolling dice this turn, click to continue");
			ThisPlayer->SetIsFreezed(false);                    //unfreeze the player after being freezed
			ThisPlayer->SetTurnCount(ThisPlayer->GetTurnCount()+1);  //increments the turn count of the freezed player
			ThisGrid->AdvanceCurrentPlayer();
			return;
		}
	}
}

InputDiceValueAction::~InputDiceValueAction()
{
}
