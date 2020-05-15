#include "Grid.h"
#pragma once
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include "Player.h"
#include <fstream>        // Used to Write/Read into/from   external files
#include "Snake.h"

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}




Card * Grid::IsCard(CellPosition pos) const
{
	if (pos.IsValidCell())
	{
		return (CellList[pos.VCell()][pos.HCell()]->HasCard());
	}
	else
		return NULL;
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed
		delete CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}



void Grid::RemoveCardFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed
		delete CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard=pCard;
	PrintErrorMessage("The clipboard is set seuccesfully click to continue");
}


Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{

			if (CellList[i][j]->HasLadder() !=NULL) //checks for whether the cells contain a ladder object starting from a certain position going right and up.
				return CellList[i][j]->HasLadder(); //this may be NULL so check ahead
			///TODO: Check if CellList[i][j] has a ladder, if yes return it (Done:Essam)


		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake* Grid::GetNextSnake(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the snake in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			if (CellList[i][j]->HasSnake() != NULL)
				
				return CellList[i][j]->HasSnake(); // checks for whether the cells contain a snake object starting from a certain position going right and up.
			///TODO: Check if CellList[i][j] has a snake, if yes return it(Done:Essam)
			


		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}
void Grid::ResetGame()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i]->SetWallet(100);
		UpdatePlayerCell(PlayerList[i], CellPosition::GetCellPositionFromNum(1));
		PlayerList[i]->SetTurnCount(0);
		PlayerList[i]->ResetAttack();
	}
	currPlayerNumber = 0;
	SetEndGame(false);
	CardTen::ResetCardOwner();
	CardEleven::ResetCardOwner();
	CardTwelve::ResetCardOwner();
	CardThirteen::ResetCardOwner();
	CardFourteen::ResetCardOwner();
}

void Grid::SaveAll(ofstream &OutFile, OBJTYPE Type)
{
	// Save Obj Count 
	if (Type == 0)
	{
			OutFile << Ladder::GetCount() << endl;
	}
	if (Type == 1)
	{
			OutFile << Snake::GetCount() << endl;
	}
	if (Type == 2)
	{
			OutFile << Card::GetCount() << endl;
	}

	//Calling the save function to save game obj in each cell if any
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->GetGameObject()) // if empty cell (GetGameObject()==Null) --> No Save called
			{
				CellList[i][j]->GetGameObject()->Save(OutFile, Type);

			}
		}
	}
}



void Grid::SetIce(int playerNum)
{
	for (int i = 0; i < MaxPlayerCount; i++)
		if (PlayerList[i]->GetPlayerNum() == playerNum)
			PlayerList[i]->SetIsFreezed(true);
}
void Grid::SetFire(int playerNum)
{
	for (int i = 0; i < MaxPlayerCount; i++)
		if (PlayerList[i]->GetPlayerNum() == playerNum)
			PlayerList[i]->SetIsBurnt(true);
}
void Grid::SetPoison(int playerNum)
{
	for (int i = 0; i < MaxPlayerCount; i++)
		if (PlayerList[i]->GetPlayerNum() == playerNum)
			PlayerList[i]->SetIsPoisoned(true);
}
void Grid::SetLightning(Player *p)
{
	for (int i = 0; i < MaxPlayerCount; i++)
		if (PlayerList[i]->GetPlayerNum() != p->GetPlayerNum())   //apply the lightning for every player except the calling player
			PlayerList[i]->LightningAttack();
}

bool Grid :: IsOverlapping(GameObject * newObj) const
{

	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++) //goes through all cells to check for game objects(Essam)
		{
			if ((CellList[i][j]->GetGameObject()) != NULL)  //incase the cell has an object(Essam)
			{
				if((CellList[i][j]->GetGameObject())->IsOverlapping(newObj)) //check if its current object overlaps with the new object(Essam)
				{

					return true;
				}
			}
		}
	}
	return false ;
}
