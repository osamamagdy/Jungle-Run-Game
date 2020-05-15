#pragma once

#include "Action.h"

class PasteCardAction : public Action
{
	// [Action Parameters]
	int cardNumber;            // 1- the card number
	CellPosition Pos; // 2- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()
	
public:
	PasteCardAction(ApplicationManager *pApp); // A Constructor
		
	virtual void ReadActionParameters(); // Reads PasteCardAction action parameters (Pos)
	
	virtual void Execute(); // Creates a new Card Object of the specific Card object similar to that in the clipboard
	                        // and Takes the Parameters of The clipboard (if any)
	                        // then Sets this Card Object to GameObject Pointer of its Cell
	
	virtual ~PasteCardAction(); // A Virtual Destructor
};

