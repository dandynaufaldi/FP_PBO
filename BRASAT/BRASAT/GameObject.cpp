#include "GameObject.h"
#include <wx/stdpaths.h>
<<<<<<< HEAD
<<<<<<< Updated upstream
#include <wx/filename.h>


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	delete gameObject;
}

void GameObject::setPosX(int posX)
{
	this->posX = posX;
	
}

int GameObject::getPosX()
{
	return this->posX;
}

void GameObject::setPosxY(int posY)
{
	this->posY = posY;
}

int GameObject::getPosY()
{
	return this->posY;
}

void GameObject::setWidth(int width)
{
	this->width = width;
=======
=======
>>>>>>> master
#include <wx/filename.h>


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	delete gameObject;
}

void GameObject::setPosX(int posX)
{
	this->posX = posX;
<<<<<<< HEAD
<<<<<<< HEAD

=======
	
>>>>>>> master
=======
	
>>>>>>> master
}

int GameObject::getPosX()
{
	return this->posX;
}

void GameObject::setPosxY(int posY)
{
	this->posY = posY;
}

int GameObject::getPosY()
{
	return this->posY;
}

void GameObject::setWidth(int width)
{
	this->width = width;
<<<<<<< HEAD
>>>>>>> Stashed changes
=======
>>>>>>> master
}

int GameObject::getWidth()
{
	return this->width;
}

void GameObject::setHeight(int height)
{
	this->height = height;
}

int GameObject::getHeight()
{
	return this->height;
}

void GameObject::setFilePath(std::string filePath)
{
	this->filePath = filePath;
}

void GameObject::loadBitmap()
{
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);

	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	wxString wfileLocation(filePath);
	fileLocation = wxFileName(fileLocation).GetPath() + wfileLocation;

	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	gameObject = new wxBitmap(image);
}

bool GameObject::isCollide(GameObject * opponent)
{
	int absx = abs(this->getPosX() - opponent->getPosX());
	int absy = abs(this->getPosY() - opponent->getPosY());
	if (absx <= this->getWidth() + opponent->getWidth() && absx >= this->getWidth()/2 + opponent->getWidth()/2 && absy <= this->getHeight() + opponent->getHeight())
		return true;
	else if (absx <= this->getWidth() + opponent->getWidth() && absy <= this->getHeight() + opponent->getHeight() && absy >= this->getHeight()/2 + opponent->getHeight()/2)
		return true;
	else return false;
}
