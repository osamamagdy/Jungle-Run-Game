#pragma once

#include "Card.h"

// [ Card_9 ] Summary:
// Its Apply() Function: Moving the player to a certain cell entered by the user in design mode  
// Its Parameters: The cell number --> put it as a "data member" and read it in ReadCardParameters()

class Card_9:	public Card
{
	// CardOne Parameters:
	int moved_to_cell_num; // the cell number we move the player to it.

public:
	Card_9(const CellPosition & pos); // A Constructor takes card position


	
	Card * Card_9 :: Get_My_Copy (CellPosition pos );



	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of Card_9 which is: cell number

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card_9 on the passed Player
	                                                  // by moving the player to the cell number
	void Save(ofstream &OutFile, OBJTYPE Type);
	virtual void Load(ifstream&);

	virtual ~Card_9(); // A Virtual Destructor
};

