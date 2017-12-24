#include "Obstacle.h"



Obstacle::Obstacle() : GameObject()
{
	this->setPosX(1300);
	this->setPosxY(530);
}


Obstacle::~Obstacle()
{
}

void Obstacle::Draw(wxAutoBufferedPaintDC & dc)
{
	dc.DrawBitmap(*gameObject, wxPoint(this->getPosX(), this->getPosY()), true);
}

void Obstacle::Move(int dif)
{
	this->setPosX(this->getPosX() + dif*this->direction);
}

void Obstacle::SetmoveAmount(int moveAmount)
{
	this->moveAmount = moveAmount;
}
