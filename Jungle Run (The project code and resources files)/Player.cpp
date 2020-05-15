#include "Player.h"
#include "GameObject.h"
#include"SpecialAttack.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	Attack=new SpecialAttack;
	ResetAttack();
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,cellColor);
}

// ====== Game Functions ======





void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)

	if((isBurnt)&&(FireCount<=3))      //checks if the player is burnt
	{
		pGrid->PrintErrorMessage("You are burnt, click to continue");
		wallet-=20;
		FireCount++;
	}
	if(FireCount>3)                    //resets the fire count after three times
	{
		isBurnt=0;
		FireCount=0;
	}
	turnCount++;
	justRolledDiceNum=diceNumber;
	if(turnCount%3==0)       
	{
		string answer;
		if(countAttacks<2)           //the player has only two attacks
		{
			pGrid->PrintErrorMessage("Do you wish to launch a special attack instead of recharging? y/n");
			answer=pGrid->GetInput()->GetSrting(pGrid->GetOutput());
			while((strcmp(answer.c_str(),"y")!=0)&&(strcmp(answer.c_str(),"n"))!=0)    //validation on answer
			{
				pGrid->PrintErrorMessage("Invalid answer, enter 'y' or 'n'");
				answer=pGrid->GetInput()->GetSrting(pGrid->GetOutput());
			}
			if(!(strcmp(answer.c_str(),"y")))            //the user accepts to launch attack
			{
				countAttacks++;
				Attack->SetAttackType(this,pGrid);   
				turnCount=0;
				return;
			}
		}
		if(!(strcmp(answer.c_str(),"n"))||(countAttacks>=2))             //the user refuses to launch attack or he used 2 attacks
		{
			pGrid->GetOutput()->ClearStatusBar();
			wallet+=justRolledDiceNum*10;
			turnCount=0;
			pGrid->PrintErrorMessage(to_string(justRolledDiceNum*10)+" Coins are added to Player Number "+to_string(playerNum)+", click to continue");
			return;
		}
	}
	CellPosition pos=(pCell->GetCellPosition());
	pos.AddCellNum(diceNumber);
	if(wallet>0)				//the player can move only if he has at least 1 coin
	{
		pGrid->UpdatePlayerCell(this,pos);
		if(pCell->GetGameObject()!=NULL)        
			(pCell->GetGameObject())->Apply(pGrid,this);
	}
	else
		pGrid->PrintErrorMessage("You can't move while your wallet is less than or equal zero, click to continue");
	if(pos.GetCellNum()==99)				//checks if the game is ended or not
		pGrid->SetEndGame(true);
}
void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
void Player::SetIsFreezed(bool test)
{
	isFreezed=test;
}
bool Player::GetIsFreezed()
{
	return isFreezed;
}
void Player::SetIsBurnt(bool test)
{
	isBurnt=test;
}
void Player::LightningAttack()
{
	wallet-=20;
}
void Player::SetIsPoisoned(bool test)
{
	isPoisoned=test;
}
bool Player::GetIsPoisoned()
{
	return isPoisoned;
}
void Player::IncrementPoisonCount()
{
	PoisonCount++;
	if(PoisonCount>=5)
	{
		PoisonCount=0;
		isPoisoned=false;
	}
}
int Player::GetPoisonCount()
{
	return PoisonCount;
}
int Player::GetPlayerNum()const
{
	return playerNum;
}
void Player::ResetAttack()
{
	countAttacks=0;
	FireCount=0;
	PoisonCount=0;
	isBurnt=0;
	isFreezed=0;
	isPoisoned=0;
	Attack->Reset();
}
void Player::SetTurnCount(int t)
{
	if(t<3)
		turnCount=t;
	else
		turnCount=0;
}
bool Player::CheckPlayerNumber(int playerNumber)
{
	if((playerNumber==playerNum)||(playerNumber>MaxPlayerCount-1)||(playerNumber<0))	
		return false;
	else
		return true;
}
int Player::GetJustRolledDiceNum()
{
	return justRolledDiceNum;
}