#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	SetPosition(pos);
}


void GameObject::SetPosition (CellPosition pos) 
{
	if (pos.IsValidCell())
	position = pos; // Sets Position

}


CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}
bool GameObject::IsOverlapping(GameObject* newObj) const
{
	return false;	//a function to check for overlapping, (will be overridden)
}