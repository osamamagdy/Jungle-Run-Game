#pragma once

#include "Card.h"

// [ Card_4 ] Summary:
// Its Apply() Function: Moving the player to a certain cell entered by the user in design mode  

class CardFour:	public Card
{

public:
	CardFour(const CellPosition & pos); // A Constructor takes card position

	Card * Get_My_Copy (CellPosition pos );



	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardFour which is: cell number

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player
	                                                  
	virtual ~CardFour(); // A Virtual Destructor
	virtual void Save(ofstream& OutFile, OBJTYPE Type);
	virtual void Load(ifstream&);
};

