#include "CardEleven.h"
#include <fstream>        // Used to Write/Read into/from   external files

//initialization of static members
bool CardEleven::isSaved = false;
Player * CardEleven::pOwner=NULL;
int CardEleven::Fee=0;
int CardEleven::CardPrice=0;
bool CardEleven::isEntered=0;


void CardEleven :: EnableEdit ()
{
	isEntered = 0 ;
}


//Virtual function to use in copy,cut,paste card actions 


Card* CardEleven :: Get_My_Copy (CellPosition pos )
{
	Card * pCard = new CardEleven (pos);

	((CardEleven*)pCard)->pOwner = pOwner;
	
	((CardEleven*)pCard)->Fee = Fee;

	((CardEleven*)pCard)->CardPrice = CardPrice;
	
	((CardEleven*)pCard)->isEntered = isEntered;
	
	return pCard ;

}



CardEleven::CardEleven(const CellPosition & pos):Card(pos)
{
	cardNumber=11;
}
void CardEleven::ReadCardParameters(Grid * pGrid)
{
	if(!isEntered)                  //checks if the user entered the parameters or not
	{
		Output *pOut=pGrid->GetOutput();
		Input *pIn=pGrid->GetInput();
		pOut->ClearStatusBar();
		pGrid->PrintErrorMessage("Enter the price of the card number 11");
		CardPrice=pIn->GetInteger(pOut);
		while(CardPrice<=0)                 //validation on price
		{
			pGrid->PrintErrorMessage("Invalid Price, Enter a valid price");
			CardPrice=pIn->GetInteger(pOut);
		}
		pGrid->PrintErrorMessage("Enter the fee of the card number 11");
		Fee=pIn->GetInteger(pOut);
		while(Fee<=0)             //validation on fee
		{
			pGrid->PrintErrorMessage("Invalid Fee, Enter a valid Fee");
			Fee=pIn->GetInteger(pOut);
		}
		isEntered=true;            //sets the boolean to true to make the user enters the fee and the price only once
	}
}
void CardEleven::Apply(Grid* pGrid,Player *pPlayer)
{
	Output *pOut=pGrid->GetOutput();
	Input *pIn=pGrid->GetInput();
	Card::Apply(pGrid,pPlayer);
	if(pOwner==NULL)   //checks if the card is bought previously or not
	{
		pGrid->PrintErrorMessage("Do you want to buy Card 11 ? y/n");
		string answer=pIn->GetSrting(pOut);
		while((strcmp(answer.c_str(),"y")!=0)&&(strcmp(answer.c_str(),"n")!=0))    //validation on answer
		{
			pGrid->PrintErrorMessage("Do you want to buy Card 11 ? y/n");
			answer=pIn->GetSrting(pOut);
		}
		if(!(strcmp(answer.c_str(),"y")))                   //the player accepts to buy the card
		{  
			if(pPlayer->GetWallet()>=CardPrice)                  //checks if the player can buy the card or not
			{
				pOwner=pPlayer;
				pPlayer->SetWallet(pPlayer->GetWallet()-CardPrice);
				pGrid->PrintErrorMessage("You have sucessfully bought card 11, click to continue");
			}
			else
			{
				pGrid->PrintErrorMessage("You don't have enough coins to buy this card, click to continue");
				return;
			}
		}
		else
		{
			pGrid->PrintErrorMessage("You refused to buy this card, click to continue");
			return;
		}
	}
	else 
		if(pOwner!=pPlayer)                           //the card is bought and the passed player is not the owner
		{
			pGrid->PrintErrorMessage("You have reached a bought station, click to continue");
			pPlayer->SetWallet(pPlayer->GetWallet()-Fee);
			pOwner->SetWallet(pOwner->GetWallet()+Fee);
			return;
		}
		else                                   //the card is bought and the passed player is the owner
			pGrid->PrintErrorMessage("You have already bought card 11 previously, click to continue");
}
CardEleven::~CardEleven()
{

}
void CardEleven::ResetCardOwner()
{
	pOwner=NULL;
}
void CardEleven::Save(ofstream &OutFile, OBJTYPE Type)
{

	if (Type == 2 && position.IsValidCell())    // Save Only if Obj Type sent is card (to make the saving process in the right order)
	{
		Card::Save(OutFile, Type);
		if (isSaved)
			OutFile << endl;     //Parameter-less so only end the current line
		else
			OutFile << " " << CardPrice << " " << Fee << endl;        //Save card Parameters
		isSaved = true;
	}
}

// Setters to Write/Read Parameters only once as they are mutual
void CardEleven::SetSavedStatus(bool Save)
{
	isSaved = Save;
}
void CardEleven::SetEnteredStatus(bool Enter)
{
	isEntered = Enter;
}

void CardEleven::Load(ifstream& InFile)
{
	if (!isEntered)
	{
		InFile >> CardPrice >> Fee;
		isEntered = true;    //To Read Paramters only once as they ar the same for each card10-14
	}
}