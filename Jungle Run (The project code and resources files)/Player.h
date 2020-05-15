#pragma once

#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
class SpecialAttack;

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	// player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	// and reset again when reached 3
	// it is used to indicate when to move and when to add to your wallet


	SpecialAttack *Attack;  //each player has an attack 'Aggregation'

	int countAttacks;       //to calculate how many attacks each player used 'max:2'

	bool isFreezed;         //determine if the player is freezed or not

	bool isBurnt;           //determine if the player is burnt or not

	int FireCount;          //to check if the player's wallet decreased only three times

	bool isPoisoned;        //determine if the player is poisoned or not

	int PoisonCount;		//to check if the player's dice decreased only five times

public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount

	void SetTurnCount(int t);           //to be used in new game action and in ice special attack

	int GetJustRolledDiceNum();
	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	// and Applies the Game Object's effect (if any) of the end reached cell 
	// for example, if the end cell contains a ladder, take it

	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, // for example: P0(wallet, turnCount)
	
	int GetPlayerNum() const;

	void SetIsFreezed(bool test);					   //to be called in Grid

	bool GetIsFreezed();							  //to check if the player is freezed 

	void SetIsBurnt(bool test);                       //to be called in Grid

	void LightningAttack();                           //to be called in Grid

	void SetIsPoisoned(bool test);                    //to be called in Grid

	bool GetIsPoisoned();                             //to check if the player is poisoned or not

	void IncrementPoisonCount();                      //used to increase poison count untill it reaches 5

	int GetPoisonCount();							  //getter for poison count

	void ResetAttack();                               //to be used in new game action

	bool CheckPlayerNumber(int playerNumber);		 //to be used in special attack class
};