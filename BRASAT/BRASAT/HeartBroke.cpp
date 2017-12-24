#include "HeartBroke.h"



HeartBroke::HeartBroke() : Obstacle()
{
	this->setFilePath("\\obs_heartbroke.png");
	this->loadBitmap();
	this->setWidth(this->getBitmap()->GetWidth());
	this->setHeight(this->getBitmap()->GetHeight());
}


HeartBroke::~HeartBroke()
{
}
