#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_CARD,		// Add Card Action	
	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode
	COPY_CARD,		// Copy a card to clipboard
	CUT_CARD,		// Cut a card to clipboard
	PASTE_CARD,		// Paste a card from clipboard
	EDIT_CARD,		// Edit Card Parameters
	DELETE_GAME_OBJECT,	// Delete a laddder or a snake or a card
	SAVE_GRID,		// Save Current grid
	OPEN_GRID,		// Load a .txt saved grid

	//  [2] Actions of Play Mode

	ROLL_DICE,		// Roll Dice Action
	TO_DESIGN_MODE,	// Go to Design Mode
	NEW_GAME,		// New Game Action
	INPUT_DICE_VALUE,	// Enter dice value instead of rolling
	

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

	// enum for the save action:

enum OBJTYPE
{
	LADDER_TYPE,
	SNAKE_TYPE,
	CARD_TYPE,
	TYPE_COUNT
};
#endif