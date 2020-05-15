#pragma once

#include "Card.h"

// [ CardTwo ] Summary:
// Its Apply() Function: Increments the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardTwo : public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to increase from the player

public:
	
Card* Get_My_Copy (CellPosition pos );

	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
													  // by decreasing the player's wallet by the walletAmount data member
	virtual void Save(ofstream& OutFile, OBJTYPE Type);
	virtual void Load(ifstream&);

	virtual ~CardTwo(); // A Virtual Destructor
};

