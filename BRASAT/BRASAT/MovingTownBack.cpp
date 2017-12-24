#include "MovingTownBack.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include "wx\dynarray.h"
#include <wx\arrimpl.cpp>
#include <string>
using namespace std;

WX_DEFINE_OBJARRAY(TownBackArray);

MovingTownBack::MovingTownBack()
{
	this->townBackArray = new TownBackArray();
	loadBitmap();
}


MovingTownBack::~MovingTownBack()
{
	for (unsigned int i = 0; i < this->townBackArray->GetCount(); i++)
	{
		TownBack* obj = (*townBackArray)[i];
		delete obj;
	}
	delete townBackArray;
}

void MovingTownBack::checkArray()
{
	for (unsigned int i = 0; i < townBackArray->GetCount(); i++) {
		TownBack *temp = (*townBackArray)[i];
		temp->Move(25);
	}
	TownBack *temp=nullptr, *RR=nullptr, *last=nullptr;
	for (int i = 0; i < townBackArray->GetCount(); i++) {
		RR = (*townBackArray)[i];
		if (RR->getPosX() + RR->getWidth() < 0) { 
			temp = RR;
			break;
		}
	}
	for (int i = 0; i < townBackArray->GetCount(); i++) {
		RR = (*townBackArray)[i];
		if (RR->getPosX() + RR->getWidth() >1280 ) {
			last = RR;
		}
	}
	if (temp && last) {
		temp->setPosX(last->getPosX() + last->getWidth());
		wxMessageOutputDebug().Printf("Round Robin");
	}
}

void MovingTownBack::loadBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	int prevw = 0;
	for (int i = 1; i <= 8; i++) {
		TownBack *tmp = new TownBack();
		string filePath = "\\TownBack\\" + to_string(i) + ".png";
		tmp->setFilePath(filePath);
		tmp->loadBitmap();
		tmp->setHeight(tmp->getBitmap()->GetHeight());
		tmp->setWidth(tmp->getBitmap()->GetWidth());
		tmp->setPosX(prevw);
		wxMessageOutputDebug().Printf("prevw=%d", prevw);
		prevw += tmp->getWidth();
		townBackArray->Add(tmp);
	}
	wxMessageOutputDebug().Printf("Townback size = %d", townBackArray->GetCount());

}

void MovingTownBack::Draw(wxAutoBufferedPaintDC & dc)
{
	for (unsigned int i = 0; i < townBackArray->GetCount(); i++) {
		TownBack *temp = (*townBackArray)[i];
		temp->Draw(dc);
	}
}
