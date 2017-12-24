#include "Laptop.h"

Laptop::Laptop() : Obstacle()
{
	this->setFilePath("\\obs_laptop.png");
	this->loadBitmap();
	this->setWidth(this->getBitmap()->GetWidth());
	this->setHeight(this->getBitmap()->GetHeight());
}


Laptop::~Laptop()
{
}
