#include "Ladder.h"
#include "Player.h"
#include "Cell.h"
#include <fstream>        // Used to Write/Read into/from   external files
#include "Snake.h"

//Initializing Ladders Count
int Ladder::L_count = 0;

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	L_count++;
	///TODO: Do the needed validation
	position = startCellPos ;

}


void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	//Done by Essam:
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a Ladder. Click to continue ...");
	

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	if (pPlayer->GetCell()->GetGameObject() != NULL)//moves the player to the position and applies the card action if there is a card.
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}
CellPosition Ladder::GetStartPosition() const
{
	return position;
}
void Ladder::Save(ofstream &OutFile, OBJTYPE Type)
{
	// Saving only if ObjType is Ladder (to be saved in the right order)
	if (position.IsValidCell() && endCellPos.IsValidCell() && Type == 0)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
}

void Ladder::Load(ifstream &Infile)
{

}

Ladder::~Ladder()
{
	L_count--;
}

// Count Getter and Setter (for Saving)
int Ladder::GetCount()
{
	return L_count;
}
void Ladder::SetCount(int count)
{
	L_count = count;
}


bool Ladder :: IsOverlapping(GameObject * newObj) const
{
	//Done by Essam and Osama <3
	Ladder*pLadder=dynamic_cast<Ladder *>(newObj);
	
	Snake * pSnake = dynamic_cast<Snake * > (newObj);
	//dynamic casting the new object to be added to snake/ladder types
	if(pLadder!=NULL)//incase  the object is indeed a snake/ladder
	{
		if(position.HCell()==newObj->GetPosition().HCell())//incase the new object is in the same collumn as the snake/ladder
	{
		int NewStart=newObj->GetPosition().VCell();
		int NewEnd=((Ladder *)newObj)->GetEndPosition().VCell();//getting the starts/ends of the new snake/ladder and see if they interfere witht he old one
		if( NewEnd > position.VCell() || NewStart < endCellPos.VCell() )
		{
			return false;
		}
		else
		{
			
			pLadder->SetCount(pLadder->GetCount() - 1);
			return true ;//return true incase they do
		}

		}
	}

	else if (pSnake!= NULL)
	{
		if (((endCellPos.HCell()==pSnake->GetPosition().HCell()) && (endCellPos.VCell()==pSnake->GetPosition().VCell()))  
			||  ( (  this->GetPosition().HCell() == pSnake->GetEndPosition().HCell()  )   &&   ( this->GetPosition().VCell() == pSnake->GetEndPosition().VCell() )  )  )
		{//preventing the overlap of a ladder with a snake of the same size
			pSnake->SetCount(pSnake->GetCount() - 1);
			return true ;
		}


		
	}


	


	return false ;//No overlapping

}