#include "Wallet.h"



Wallet::Wallet() : Obstacle()
{
	this->setFilePath("\\obs_wallet.png");
	this->loadBitmap();
	this->setWidth(this->getBitmap()->GetWidth());
	this->setHeight(this->getBitmap()->GetHeight());
}


Wallet::~Wallet()
{
}
