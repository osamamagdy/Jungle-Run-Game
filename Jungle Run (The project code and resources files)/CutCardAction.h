#pragma once

#include "Action.h"

class CutCardAction : public Action
{
	// [Action Parameters]
	int cardNumber;            // 1- the card number
	CellPosition Pos; // 2- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()
	
public:
	CutCardAction(ApplicationManager * pApp); // A Constructor
		
	virtual void ReadActionParameters(); // Reads CutCardAction action parameters (cardNumber, Pos)
	
	virtual void Execute(); // Creates a new Card Object of the specific Card Number 
	                        // sets this object in the clipboard withe the same parameters values (if any)
	                        // then deletes the original Card Object of its Cell
	
	virtual ~CutCardAction(); // A Virtual Destructor
};

