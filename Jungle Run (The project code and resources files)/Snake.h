#pragma once

#include "GameObject.h"


class Snake :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the snake's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	static int S_count;

public:

	Snake(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the snaker by moving player to snake's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member(Essam)
	CellPosition GetStartPosition() const;	//A getter for the start positions(Essam)
	virtual ~Snake(); // Virtual destructor

	virtual void Save(ofstream &OutFile, OBJTYPE);
	
	virtual void Load(ifstream &Infile);
	static int GetCount();
	static void SetCount(int);
	virtual bool IsOverlapping(GameObject * newObj) const ; //checks for overlapping(Essam)

};