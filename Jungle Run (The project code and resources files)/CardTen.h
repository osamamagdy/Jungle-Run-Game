#pragma once
#include "Card.h"
class CardTen: public Card
{
	static int CardPrice;
	static int Fee;
	static bool isSaved;   // flag used to save parameters of each card10-14 only once
	static Player *pOwner;    //the owner of the card	
	static bool isEntered;	  //determines if the user entered the parameters of the card or not
public:

	Card* CardTen :: Get_My_Copy (CellPosition pos );
    void EnableEdit ();
	CardTen(const CellPosition & pos);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid,Player *pPlayer);
	static void ResetCardOwner();                               //to be used in new game action
	~CardTen(void);
	void Save(ofstream &OutFile, OBJTYPE Type);
	static void SetSavedStatus(bool);
	static void SetEnteredStatus(bool);
	virtual void Load(ifstream&);

};

