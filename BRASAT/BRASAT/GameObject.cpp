#include "GameObject.h"
#include <wx/stdpaths.h>
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
	//wxImageHandler *pngLoader = new wxPNGHandler();
	//wxImage::AddHandler(pngLoader);

	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	wxString wfileLocation(filePath);
	fileLocation = wxFileName(fileLocation).GetPath() + wfileLocation;
	wxMessageOutputDebug().Output(fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	gameObject = new wxBitmap(image);
	if (gameObject == nullptr) wxMessageOutputDebug().Printf("Gagal baca file");
}

wxBitmap * GameObject::getBitmap()
{
	return gameObject;
}

bool GameObject::isCollide(GameObject * opponent)
{
	int absx = abs(this->getPosX() + this->getWidth() / 2 - (opponent->getPosX() + opponent->getWidth() / 2));
	int absy = abs(this->getPosY() + this->getHeight() / 2 - (opponent->getPosY() + opponent->getHeight() / 2));
	/*wxMessageOutputDebug().Printf("abs x %d abs y %d", absx, absy);
	wxMessageOutputDebug().Printf("Posx %d posy %d w %d h %d", this->getPosX(), this->getPosY(), this->getWidth(), this->getHeight());
	wxMessageOutputDebug().Printf("Posx %d posy %d w %d h %d", opponent->getPosX(), opponent->getPosY(), opponent->getWidth(), opponent->getHeight());
	wxMessageOutputDebug().Printf("");*/
	/*if (absx <= this->getWidth() + opponent->getWidth() && absx >= this->getWidth()/2 + opponent->getWidth()/2 && absy <= this->getHeight() + opponent->getHeight())
	return true;
	else if (absx <= this->getWidth() + opponent->getWidth() && absy <= this->getHeight() + opponent->getHeight() && absy >= this->getHeight()/2 + opponent->getHeight()/2)
	return true;*/
	if (absx < this->getWidth() / 2 + opponent->getWidth() / 2 /*&& absx >= this->getWidth() / 4 + opponent->getWidth() / 4*/ && absy < this->getHeight() / 2 + opponent->getHeight() / 2 && opponent->getPosX() + opponent->getWidth() > this->getPosX()) return true;
	//else if (absx <= this->getWidth() / 2 + opponent->getWidth() / 2 && absy >= this->getHeight() / 4 + opponent->getHeight() / 4 && absy <= this->getHeight() / 2 + opponent->getHeight() / 2) return true;
	else return false;
}
