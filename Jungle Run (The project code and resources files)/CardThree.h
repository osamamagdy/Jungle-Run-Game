#pragma once

#include "Card.h"

// [ Card_3 ] Summary:
// Its Apply() Function: Moving the player to a certain cell entered by the user in design mode 

class CardThree:	public Card
{
	
public:

	
    Card * Get_My_Copy (CellPosition pos );

	CardThree(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardThree which is: none

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
	virtual void Save(ofstream& OutFile, OBJTYPE Type);
	virtual void Load(ifstream& Infile);

	virtual ~CardThree(); // A Virtual Destructor
};

