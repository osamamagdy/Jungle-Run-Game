#include "OpenGridAction.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "Card_7.h"
#include "Card_8.h"
#include "Card_9.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include <fstream>        // Used to Write/Read into/from   external files



OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
}
void OpenGridAction::ReadActionParameters()
{
	// Reading FileName to Open

	pManager->GetGrid()->PrintErrorMessage("Please Enter File Name.");

	FileName = pManager->GetGrid()->GetInput()->GetSrting(pManager->GetGrid()->GetOutput());
	FileName += ".txt";  // adding file extention to the name
	pManager->GetGrid()->GetOutput()->ClearStatusBar();

	pManager->GetGrid()->PrintErrorMessage("You Entered: " + FileName + ", Click to continue");
	pManager->GetGrid()->GetOutput()->ClearStatusBar();
}
void OpenGridAction::Execute()
{
	// Resetting read status of card10-14 to make their price and fees mutual  
	CardTen::SetEnteredStatus(false);
	CardEleven::SetEnteredStatus(false);
	CardTwelve::SetEnteredStatus(false);
	CardThirteen::SetEnteredStatus(false);
	CardFourteen::SetEnteredStatus(false);

	// Getting file name
	ReadActionParameters();

	// Clearing Current Grid
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			pManager->GetGrid()->RemoveObjectFromCell(CellPosition(i, j));
		}
	}

	// Openning file to read from
	ifstream InFile;
	InFile.open(FileName);

	// declaring a count varible to for Ladders' count, Snakes and Cards
	int count = 0;

	// Reading Ladder Count 
	InFile >> count;

	// Adding Ladders
	for (int i = 0; i < count; i++)
	{
		// Reading Start and End Position
		int Start = 0, End = 0;
		InFile >> Start >> End;

		// Creating CellPosition Objs and using them to Construct Ladder Obj
		CellPosition* StartPos = new CellPosition(Start);
		CellPosition* EndPos = new CellPosition(End);
		Ladder* Load = new Ladder(*StartPos, *EndPos);

		// Adding Ladder Obj to Respictive cell
		pManager->GetGrid()->AddObjectToCell(Load);
	}

	// Reading Snakes Count 
	InFile >> count;

	// Adding Snakes 
	for (int i = 0; i < count; i++)
	{
		// Reading Start and End Position
		int Start = 0, End = 0;
		InFile >> Start >> End;

		// Creating CellPosition Objs and using them to Construct Snake Obj
		CellPosition* StartPos = new CellPosition(Start);
		CellPosition* EndPos = new CellPosition(End);
		Snake* Load = new Snake(*StartPos, *EndPos);

		// Adding Snake Obj to Respictive cell
		pManager->GetGrid()->AddObjectToCell(Load);
	}

	// Adding Cards
	InFile >> count;
	for (int i = 0; i < count; i++)
	{
		// Reading CardNum and Position
		int CardNum = 0, Pos = 0;
		InFile >> CardNum >> Pos;

		// Creating CellPosition Obj and using it to Construct BaseCard Obj 
		// Decrementing Cards Count as a reaction to being incremented by constructor 
		CellPosition* StartPos = new CellPosition(Pos);
		Card* pCard = new Card(Pos);
		Card::SetCount(Card::GetCount() - 1);

		// Using CardNum to Construct a specific drevied card obj
		pCard->SetCardNumber(CardNum);
		switch (CardNum)
		{
		case 1:
			pCard = new CardOne(Pos);
			break;
		case 2:
			pCard = new CardTwo(Pos);
			break;
		case 3:
			pCard = new CardThree(Pos);
			break;
		case 4:
			pCard = new CardFour(Pos);
			break;
		case 5:
			pCard = new CardFive(Pos);
			break;
		case 6:
			pCard = new CardSix(Pos);
			break;
		case 7:
			pCard = new Card_7(Pos);
			break;
		case 8:
			pCard = new Card_8(Pos);
			break;
		case 9:
			pCard = new Card_9(Pos);
			break;
		case 10:
			pCard = new CardTen(Pos);
			break;
		case 11:
			pCard = new CardEleven(Pos);
			break;
		case 12:
			pCard = new CardTwelve(Pos);
			break;
		case 13:
			pCard = new CardThirteen(Pos);
			break;
		case 14:
			pCard = new CardFourteen(Pos);
			break;
		}

		// using load function of card if it has any parameters
		pCard->Load(InFile);

		// Adding Card Obj to Respictive cell
		pManager->GetGrid()->AddObjectToCell(pCard);
	}
	// closing file
	InFile.close();
}

OpenGridAction::~OpenGridAction()
{
}
