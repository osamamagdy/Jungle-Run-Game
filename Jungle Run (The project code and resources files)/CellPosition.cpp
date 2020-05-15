#include "CellPosition.h"
#include "UI_Info.h"
CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	// Validation 
	if((v<9)&&(v>=0))
	{
		vCell=v;
		return true;
	}
	// Default Value -1
	else
	{
		vCell = -1;
		return false;
	}
}

bool CellPosition::SetHCell(int h) 
{
	// Validation 
	if((h<11)&&(h>=0))
	{
		hCell=h;
		return true;
	}
	// Default Value -1
	else
	{
		hCell = -1;
		return false;
	}
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	// Validation 
	if((vCell>=0)&&(vCell<9)&&(hCell>=0)&&(hCell<11))
		return true;
	else
		return false;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	if(cellPosition.IsValidCell()==true)
	{
		int cellNum;
		cellNum=(8-cellPosition.VCell())*10+(cellPosition.HCell()+9-cellPosition.VCell());
		return cellNum;
	}
	else 
		return 0;
	// this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	/// TODO: Implement this function as described in the .h file
	if ((cellNum>=1)&&(cellNum<=99))
	{
		position.SetVCell((99-cellNum)/11);
		position.SetHCell((cellNum-1)%11);
	}
	return position;
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
}

void CellPosition::AddCellNum (int addedNum)
{

	/// TODO: Implement this function as described in the .h file
	int cellNum=GetCellNumFromPosition(*this);
	cellNum = (addedNum + GetCellNum() > 99)? 99 : addedNum + GetCellNum();

	CellPosition newpos = CellPosition::GetCellPositionFromNum(cellNum);
	
	hCell=newpos.HCell(); 
	vCell=newpos.VCell();

	// Note: this function updates the data members (vCell and hCell) of the calling object

}