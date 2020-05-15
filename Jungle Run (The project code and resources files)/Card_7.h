#pragma once

#include "Card.h"

// [ Card_7 ] Summary:
// Its Apply() Function: Giving the player another roll dice  

class Card_7:	public Card
{
	// Card_7 Parameters:
	
public:
	Card_7(const CellPosition & pos); // A Constructor takes card position

	
Card * Get_My_Copy (CellPosition pos );

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of Card_7 which is: none

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card_7 on the passed Player
	                                                  // by giving the player another roll dice

	virtual void Save(ofstream &OutFile, OBJTYPE Type);
	virtual void Load(ifstream& Infile);

	virtual ~Card_7(); // A Virtual Destructor
};

