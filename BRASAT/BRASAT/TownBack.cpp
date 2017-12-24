#include "TownBack.h"



TownBack::TownBack() : GameObject()
{
	setPosxY(0);
}


TownBack::~TownBack()
{
}

void TownBack::SetmoveAmount(int moveAmount)
{
	this->moveAmount = moveAmount;
}

int TownBack::GetmoveAmount()
{
	return this->moveAmount;
}

void TownBack::Move(int dif)
{
	this->setPosX(this->getPosX() - dif);
}

void TownBack::Draw(wxAutoBufferedPaintDC & dc)
{
	dc.DrawBitmap(*gameObject, wxPoint(this->getPosX(), this->getPosY()), true);
}
