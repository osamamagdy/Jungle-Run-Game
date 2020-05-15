#pragma once

#include "Card.h"

// [ Card_8 ] Summary:
// Its Apply() Function: preventing the player from rolling the dice the next turn  

class Card_8:	public Card
{

public:
	Card_8(const CellPosition & pos); // A Constructor takes card position

	
 Card* Get_My_Copy (CellPosition pos );

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of Card_8 which is: none

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card_8 on the passed Player
	                                                  // by freezing the player for one turn
	virtual void Save(ofstream &OutFile, OBJTYPE Type);
	virtual void Load(ifstream& Infile);

	virtual ~Card_8(); // A Virtual Destructor
};
