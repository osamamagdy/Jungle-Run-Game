#include "SpecialAttack.h"


SpecialAttack::SpecialAttack()
{
	Reset();
}
void SpecialAttack::Reset()
{
	testIce=0;
	testFire=0;
	testPoison=0;
	testLightning=0;
}
void SpecialAttack::SetAttackType(Player* p,Grid *pGrid)
{
	Output * pOut=pGrid->GetOutput();
	Input * pIn=pGrid->GetInput();
	int playerNum;
	string type;
	pGrid->PrintErrorMessage("Choose the type of the attack:'I' for Ice, 'F' for Fire, 'P' for Poison, 'L' for Lightning");
	type=pIn->GetSrting(pOut);

	//validation on type

	while(((strcmp(type.c_str(),"I"))!=0)&&((strcmp(type.c_str(),"F"))!=0)&&((strcmp(type.c_str(),"P"))!=0)&&((strcmp(type.c_str(),"L"))!=0))
	{
		pGrid->PrintErrorMessage("Invalid answer, click to enter a new answer");
		type=pIn->GetSrting(pOut);
	}

	//Ice

	if(!(strcmp(type.c_str(),"I")))
	{
		if(!testIce)			//checks if the player used Ice attack or not
		{
			pGrid->PrintErrorMessage("Enter the player number that you want to Freeze");
			playerNum=pIn->GetInteger(pOut);
			pOut->ClearStatusBar();
			while(!(p->CheckPlayerNumber(playerNum)))			//validation on entered number
			{
				pGrid->PrintErrorMessage("Invalid player number, click to enter another number");
				playerNum=pIn->GetInteger(pOut);
			}
			testIce=true;
			Ice(playerNum,pGrid);
		}
		else
		{
			pGrid->PrintErrorMessage("You have already used this special attack once, click to continue");
			SetAttackType(p,pGrid);
		}
	}

	//Fire

	if(!(strcmp(type.c_str(),"F")))
	{
		if(!testFire)			//checks if the player used Fire attack or not
		{
			pGrid->PrintErrorMessage("Enter the player number that you want to burn");
			playerNum=pIn->GetInteger(pOut);
			pOut->ClearStatusBar();
			while(!(p->CheckPlayerNumber(playerNum)))	//validation on entered number
			{
				pGrid->PrintErrorMessage("Invalid player number, click to enter another number");
				playerNum=pIn->GetInteger(pOut);
			}
			testFire=true;
			Fire(playerNum,pGrid);
		}
		else
		{
			pGrid->PrintErrorMessage("You have already used this special attack once, click to continue");
			SetAttackType(p,pGrid);
		}
	}

	//Poison

	if(!(strcmp(type.c_str(),"P")))
	{
		if(!testPoison)				//checks if the player used Poison attack or not
		{
			pGrid->PrintErrorMessage("Enter the player number that you want to poison");
			playerNum=pIn->GetInteger(pOut);
			pOut->ClearStatusBar();
			while(!(p->CheckPlayerNumber(playerNum)))	
			{
				pGrid->PrintErrorMessage("Invalid player number, click to enter another number");
				playerNum=pIn->GetInteger(pOut);
			}
			testPoison=true;
			Poison(playerNum,pGrid);
		}
		else
		{
			pGrid->PrintErrorMessage("You have already used this special attack once, click to continue");
			SetAttackType(p,pGrid);
		}
	}

	//Lightning

	if(!(strcmp(type.c_str(),"L")))
	{
		if(!testLightning)			//checks if the player used Lightning attack or not
		{
			testLightning=true;
			Lightning(pGrid,p);
		}
		else
		{
			pGrid->PrintErrorMessage("You have already used this special attack once, click to continue");
			SetAttackType(p,pGrid);
		}
	}
}
void SpecialAttack::Ice(int playerNum,Grid *pGrid)
{
	pGrid->SetIce(playerNum);
}
void SpecialAttack::Fire(int playerNum,Grid *pGrid)
{
	pGrid->SetFire(playerNum);
}
void SpecialAttack::Poison(int playerNum,Grid *pGrid)
{
	pGrid->SetPoison(playerNum);
}
void SpecialAttack::Lightning(Grid *pGrid,Player *p)
{
	pGrid->SetLightning(p);
}
SpecialAttack::~SpecialAttack(void)
{
}
