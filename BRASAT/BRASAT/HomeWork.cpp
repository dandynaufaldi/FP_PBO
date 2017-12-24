#include "Homework.h"



Homework::Homework() : Obstacle()
{
	this->setFilePath("\\obs_book.png");
	this->loadBitmap();
	this->setWidth(this->getBitmap()->GetWidth());
	this->setHeight(this->getBitmap()->GetHeight());
}

Homework::~Homework()
{
}
