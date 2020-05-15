#pragma once
#include"Player.h"
#include"Grid.h"


class SpecialAttack 
{
	bool testIce;				//to determine if the player used Ice once or not
	bool testFire;				//to determine if the player used Fire once or not
	bool testPoison;			//to determine if the player used Poison once or not
	bool testLightning;			//to determine if the player used Lightning once or not
public:
	SpecialAttack();
	void SetAttackType(Player *p,Grid * pGrid);		//Specify the type of attack and then call the appropiate fuction
	void Ice(int playerNum,Grid *pGrid);			//to apply Ice
	void Fire(int playerNum,Grid *pGrid);			//to apply Fire
	void Poison(int playerNum,Grid *pGrid);			//to apply Poison	
	void Lightning(Grid *pGrid,Player *p);			//to apply Lightning
	void Reset();
	~SpecialAttack(void);
};

