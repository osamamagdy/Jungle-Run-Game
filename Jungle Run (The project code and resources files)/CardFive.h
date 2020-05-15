#pragma once
#include "Card.h"

class CardFive :
	public Card
{
public:
	CardFive(const CellPosition & pos);
	virtual void ReadCardParameters(Grid * pGrid); // It reads the parameters specific for each Card Type
												   // It is a virtual function (implementation depends on Card Type)
	
	Card * Get_My_Copy (CellPosition pos );



	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream &OutFile, OBJTYPE Type);
	virtual void Load(ifstream &Infile);

	~CardFive();
};

