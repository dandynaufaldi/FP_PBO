#include "Man.h"
#include <wx\arrimpl.cpp>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <string>
using namespace std;
WX_DEFINE_OBJARRAY(ManArray);
Man::Man() : GameObject()
{
	//this->setFilePath("\\man.png");
	this->setPosX(50);
	this->setPosxY(380);
	this->setWidth(161);
	this->setHeight(200);
	this->manArray = new ManArray();
	this->loadBitmap();
	tempBitmap = new wxBitmap(161, 200);
	
}


Man::~Man()
{
	delete tempBitmap;
	for (unsigned int i = 0; i < this->manArray->GetCount(); i++)
	{
		wxBitmap* obj = (*manArray)[i];
		delete obj;
	}
	delete manArray;
}

void Man::Draw(wxAutoBufferedPaintDC & dc, int counter)
{
	//static int letjump = 0;
	//if (manMove == 0) letjump = counter;
	wxBitmap *temp = (*manArray)[counter % 17];
	dc.DrawBitmap(*temp, wxPoint(this->getPosX(), this->getPosY()), true);
	/*wxMemoryDC temp;
	wxMemoryDC dcSource;
	dcSource.SelectObject(*gameObject);
	temp.SelectObject(*tempBitmap);
	temp.SetBackground(*wxTRANSPARENT_BRUSH);
	temp.Clear();
	temp.Blit(0, 0, 242, 300, &dcSource, (counter % 17) * 242, 0, wxCOPY, true);
	temp.SelectObject(wxNullBitmap);
	dcSource.SelectObject(wxNullBitmap);
	dc.DrawBitmap(*tempBitmap, wxPoint(this->getPosX(), this->getPosY()), true);*/
}

void Man::Move(int dif)
{
	//wxMessageOutputDebug().Printf("Man pos = %d manmove=%d", getPosY(), getmanMove());
	if (this->getPosY() + dif*this->direction <= this->maxY) {
		direction = 1;
		this->SetmanMove(2);
		this->setPosxY(this->maxY);
	}
	else if (this->getPosY() + dif*this->direction >= this->minY) {
		this->setPosxY(this->minY);
	}
	else this->setPosxY(this->getPosY() + dif*this->direction);
	//wxMessageOutputDebug().Printf("New Man pos = %d manmove=%d", getPosY(), getmanMove());
	//if (this->getPosY() < this->maxY) this->setPosxY(this->maxY);
	//if (this->getPosY() > this->minY) this->setPosxY(this->minY);
}

void Man::SetmanMove(int flag)
{
	this->manMove = flag;
	if (manMove == 0) direction = -1;
}

void Man::SetmoveAmount(int moveAmount)
{
	this->moveAmount = moveAmount;
}

int Man::getDirection()
{
	return this->direction;
}


int Man::getmanMove()
{
	return this->manMove;
}

void Man::setDirection(int dir)
{
	this->direction = dir;
}

void Man::loadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	string filePath;
	for (int i = 0; i < 17; i++) {
		if (i==0) filePath = "\\Man\\" + to_string(i) + ".png";
		else filePath = "\\" + to_string(i) + ".png";
		wxString wfileLocation(filePath);
		fileLocation = wxFileName(fileLocation).GetPath() + wfileLocation;
		wxMessageOutputDebug().Output(fileLocation);
		wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
		wxBitmap* tmp = new wxBitmap(image);
		manArray->Add(tmp);
	}
}
