#pragma once

#include "Action.h"

class CopyCardAction : public Action
{
	// [Action Parameters]
	int cardNumber;            // 1- the card number
	CellPosition Pos; // 2- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()
	
public:
	CopyCardAction(ApplicationManager * pApp); // A Constructor
		
	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters (cardNumber, Pos)
	
	virtual void Execute();// Creates a new Card Object of the specific Card Number 
	                        // sets this object in the clipboard withe the same parameters values (if any)
	
	virtual ~CopyCardAction(); // A Virtual Destructor
};

