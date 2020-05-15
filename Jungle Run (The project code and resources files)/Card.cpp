#include "Card.h"
#include <fstream>        // Used to Write/Read into/from   external files

using namespace std;

//Initializing Snakes Count
int Card::C_count = 0;

Card::Card(const CellPosition& pos) : GameObject(pos) // sets the cell position of the GameObject
{
	C_count++;
}


//Virtual function to use in copy,cut,paste card actions 

Card* Card::Get_My_Copy(CellPosition pos)
{
	return NULL;

}

void Card::EnableEdit()
{
}


void Card::SetCardNumber(int cnum)
{
	if ((cnum >= 1) && (cnum <= 14))
		cardNumber = cnum; // needs validation
	else
		cardNumber = -1;
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid* pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, OBJTYPE Type)
{
	// Saving Position and CardNumber (will be called in all cards)
	int cellnum = position.GetCellNum();
	OutFile << cardNumber << " " << cellnum;
}
void Card::Load(ifstream& Infile)
{
}

// Count Getter and Setter (for Saving)
int Card::GetCount()
{
	return C_count;
}
void Card::SetCount(int count)
{
	C_count = count;
}

Card::~Card()
{
	C_count--;
}
