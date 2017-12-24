#include "GamePanel.h"
#include "Man.h"
#include "Wallet.h"
#include "HeartBroke.h"
#include "Homework.h"
#include "Laptop.h"
#include "TownBack.h"
#include "MovingTownBack.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx\arrimpl.cpp>
#include <wx/listimpl.cpp>
#include <wx/dcbuffer.h>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

#define TIMER_ID 2001

WX_DEFINE_OBJARRAY(ObstacleArray);
//WX_DEFINE_OBJARRAY(TownBackArray);

BEGIN_EVENT_TABLE(GamePanel, wxPanel)
EVT_PAINT(GamePanel::OnPaint)
EVT_KEY_DOWN(GamePanel::OnKeyDown)
EVT_KEY_UP(GamePanel::OnKeyUp)
EVT_TIMER(TIMER_ID, GamePanel::OnTimer)
END_EVENT_TABLE()

GamePanel::GamePanel(MultiFrame * parent) : wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->SetWindowStyle(wxWANTS_CHARS);
	this->SetBackgroundColour(wxColour(*wxBLACK));

	this->obstacleArray = new ObstacleArray();
	this->movingTownBack = new MovingTownBack();

	Wallet* wallet = new Wallet();
	Laptop* laptop = new Laptop();
	Homework* homework = new Homework();
	HeartBroke* heartbroke = new HeartBroke();

	this->obstacleArray->Add(wallet);
	this->obstacleArray->Add(laptop);
	this->obstacleArray->Add(homework);
	this->obstacleArray->Add(heartbroke);

	this->curObs = (*obstacleArray)[0];
	isObsExist = false;
	man = new Man();

	isStarted = false;
	isPaused = false;
	this->angka = 0;
	timer = new wxTimer(this, TIMER_ID);
	//timer->Start(60);
}

GamePanel::~GamePanel()
{
	timer->Stop();
	delete timer;
	delete man;
	for (unsigned int i = 0; i < this->obstacleArray->GetCount(); i++)
	{
		Obstacle* obj = (*obstacleArray)[i];
		delete obj;
	}
	delete obstacleArray;
	delete movingTownBack;
	delete score0;
	delete score1;
	delete score2;
	delete score3;
	delete score4;

}

void GamePanel::setManJump(int flag)
{
	this->isManJump = flag;
}

int GamePanel::getManJump()
{
	return this->isManJump;
}

void GamePanel::setKeyDown(int flag)
{
	this->isKeyDown = flag;
}

int GamePanel::getKeyDown()
{
	return this->isKeyDown;
}

void GamePanel::OnTimer(wxTimerEvent & event)
{
	static int counter = 0;
	//wxMessageOutputDebug().Printf("wxTimer event gamepanel %d.", counter);
	if (man->isCollide(curObs)) {
		StopGame();
		parentFrame->ShowEpilogPanel();
		
	}

	if (counter == 20) isObsExist = true;
	if (curObs != nullptr && counter > 20) {
		if (curObs->getPosX() + curObs->getWidth() < 0) {
			Obstacle *temp = curObs;
			temp->setPosX(1300);
			srand(time(NULL));
			int idx = rand() % 4;
			curObs = (*obstacleArray)[idx];
		}
		curObs->Move(25);
	}
	if (man != nullptr) {
		if (man->getPosY() >= 380 && man->getmanMove() == 2) {
			man->SetmanMove(0);
		}
		if (this->getKeyDown()) man->setDirection(-1);
		if (isManJump > 0 || man->getmanMove()>0) man->Move(20);
	}
	movingTownBack->checkArray();
	counter++;
	Refresh();
	Update();
}

void GamePanel::OnKeyDown(wxKeyEvent & event)
{
	if (!(this->getKeyDown())) {
		this->setKeyDown(1);
		int key = event.GetKeyCode();
		if (key == WXK_UP || key == WXK_SPACE) {
			wxMessageOutputDebug().Printf("keyup / spacebar pressed");
			this->setManJump(1);
			man->SetmanMove(1);
			wxMessageOutputDebug().Printf("manjump=%d manmove=%d", getManJump(), man->getmanMove());
		}
		else if (key == WXK_ESCAPE) {
			this->isPaused = 1;
			timer->Stop();
			parentFrame->ShowPausePanel();
		}
	}
}

void GamePanel::OnKeyUp(wxKeyEvent & event)
{
	if (this->getKeyDown()) {
		this->setKeyDown(0);
		if (isManJump) isManJump = 0;
	}
}

void GamePanel::OnPaint(wxPaintEvent & event)
{
	static int counter = 0;
	this->angka++;
	this->PrintScore(angka);
	wxAutoBufferedPaintDC pdc(this);
	PrepareDC(pdc);
	pdc.SetBrush(*wxBLACK_BRUSH);
	pdc.SetPen(*wxBLACK_PEN);
	wxRect rect(wxPoint(0, 0), GetClientSize());
	//gambar background putih
	pdc.DrawRectangle(rect);
	movingTownBack->Draw(pdc);

	//if (man->getBitmap()->IsOk()) {
	man->Draw(pdc, counter);
	counter++;
	//}
	//if (curObs != nullptr && isObsExist) {
	curObs->Draw(pdc);
	//}

	if (score0 != nullptr)
	{
		pdc.DrawBitmap(*score0, wxPoint(1080, 30), true);
	}
	if (score1 != nullptr)
	{
		pdc.DrawBitmap(*score1, wxPoint(1110, 30), true);
	}
	if (score2 != nullptr)
	{
		pdc.DrawBitmap(*score2, wxPoint(1140, 30), true);
	}
	if (score3 != nullptr)
	{
		pdc.DrawBitmap(*score3, wxPoint(1170, 30), true);
	}
	if (score4 != nullptr)
	{
		pdc.DrawBitmap(*score4, wxPoint(1200, 30), true);
	}
}


void GamePanel::EraseBackground(wxEraseEvent & WXUNUSED)
{
}


void GamePanel::PrintScore(int score)
{
	string fString;
	//ifstream myfile;
	int stringSize, zero;
	//wxStandardPaths &stdPaths = wxStandardPaths::Get();
	//wxString fileLocation = stdPaths.GetExecutablePath();
	//fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\score.txt");
	//wxMessageOutputDebug().Output(fileLocation);
	//string textLocation = string(fileLocation.mb_str());
	//myfile.open(textLocation);
	//getline(myfile, fString);
	fString = to_string(score);
	stringSize = fString.size();
	zero = 5 - stringSize;
	fString.resize(5);
	if (zero != 0)
	{
		for (int i = stringSize - 1; i >= 0; i--) fString[i + zero] = fString[i];
		for (int i = 0; i < zero; i++) fString[i] = '0';
	}
	for (int i = 0; i < 5; i++) {
		wxStandardPaths &stdPaths = wxStandardPaths::Get();
		wxString fileLocation = stdPaths.GetExecutablePath();
		if (fString[i] == '0') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\0.png");
		else if (fString[i] == '1') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\1.png");
		else if (fString[i] == '2') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\2.png");
		else if (fString[i] == '3') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\3.png");
		else if (fString[i] == '4') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\4.png");
		else if (fString[i] == '5') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\5.png");
		else if (fString[i] == '6') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\6.png");
		else if (fString[i] == '7') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\7.png");
		else if (fString[i] == '8') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\8.png");
		else if (fString[i] == '9') fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\9.png");
		wxImage scoreimage(fileLocation, wxBITMAP_TYPE_PNG);
		if (i == 0) score0 = new wxBitmap(scoreimage);
		else if (i == 1) score1 = new wxBitmap(scoreimage);
		else if (i == 2) score2 = new wxBitmap(scoreimage);
		else if (i == 3) score3 = new wxBitmap(scoreimage);
		else if (i == 4) score4 = new wxBitmap(scoreimage);
	}
	//myfile.close();
}

void GamePanel::StartGame()
{
	if (IsShown() && timer!=nullptr) timer->Start(60);
}

void GamePanel::StopGame()
{
	if (!IsShown() && timer != nullptr) timer->Stop();
}

void GamePanel::ResetGame()
{
	if (this->curObs) curObs->setPosX(1300);
	this->curObs = (*obstacleArray)[0];
	this->man->setPosxY(380);
	//this->curObs->setPosX(1300);
	timer->Stop();
}
