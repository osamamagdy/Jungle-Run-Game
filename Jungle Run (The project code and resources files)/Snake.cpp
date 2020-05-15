#include "Snake.h"
#include "Cell.h"
#include "Player.h"
#include "Ladder.h"
#include <fstream>        // Used to Write/Read into/from   external files
#include "Grid.h"
class Grid ;

//Initializing Snakes Count
int Snake::S_count = 0;

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	S_count++;
	///TODO: Do the needed validation...Validation hena wala hnak wla eh...
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}



void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	//Done by Essam:

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");//Include Output.h
	//a3ml include lel output wla eh...
	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);//updates the position of the player and apply any card actions
	if (pPlayer->GetCell()->GetGameObject() != NULL)
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);

}
//trivals:
CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

CellPosition Snake::GetStartPosition() const
{
	return position;
}


void Snake::Save(ofstream &OutFile, OBJTYPE Type)
{
	// Saving only if ObjType is Snake (to be saved in the right order)
	if (position.IsValidCell() && endCellPos.IsValidCell() && Type == 1)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
}

void Snake::Load(ifstream &Infile)
{

}

Snake::~Snake()
{
	S_count--;
}

// Count Getter and Setter (for Saving)
int Snake::GetCount()
{
	return S_count;
}

void Snake::SetCount(int count)
{
	S_count = count;
}
bool Snake::IsOverlapping(GameObject * newObj) const
{
	//Done by Essam and Osama <3 
	Snake*pSnake = dynamic_cast<Snake *>(newObj);
	Ladder*pLadder = dynamic_cast<Ladder *>(newObj);
	//dynamic casting the new object to be added to snake/ladder types
	if (pSnake != NULL)//incase  the object is indeed a snake/ladder
	{
		if (position.HCell() == newObj->GetPosition().HCell())//incase the new object is in the same collumn as the snake/ladder
		{
			{
				int NewStart = newObj->GetPosition().VCell();
				int NewEnd = ((Snake *)newObj)->GetEndPosition().VCell(); // getting the starts / ends of the new snake / ladder and see if they interfere witht he old one
				
		if( NewEnd <position.VCell() || NewStart>endCellPos.VCell() )  
		{
			return false ;
		}
		else
		{
			
			pSnake->SetCount(pSnake->GetCount() - 1);
			return true ;//return true incase they do
		}

			}
		}

	}
		else if (pLadder != NULL)
		{
			if (((this->GetPosition().HCell() == pLadder->GetEndPosition().HCell()) && (this->GetPosition().VCell() == pLadder->GetEndPosition().VCell())) 
				|| ((endCellPos.HCell() == pLadder->GetPosition().HCell()) && (endCellPos.VCell() == pLadder->GetPosition().VCell())))
			{
				
				pLadder->SetCount(pLadder->GetCount() - 1);
				return true;//preventing the overlap of a snake with a ladder of the same size
			}

		}

		return false;
		//No overlapping
	
}