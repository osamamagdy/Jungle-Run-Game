#pragma once

#include "Action.h"

class EditCardAction : public Action
{
	// [Action Parameters]
	int cardNumber;            // 1- the card number
	CellPosition Pos; // 2- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()
	
public:
	EditCardAction(ApplicationManager * pApp); // A Constructor
		
	virtual void ReadActionParameters(); // Reads EditCardAction action parameters (cardNumber, Pos)
	
	virtual void Execute(); // Points to the  Card Object of the specific Card Number
	                        // and Reads the Parameters of This Card Number (if any)
	                        // then edits this Card Object to new parameters
	
	virtual ~EditCardAction(); // A Virtual Destructor
};

