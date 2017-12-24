#include "HighScorePanel.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

BEGIN_EVENT_TABLE(HighScorePanel, wxPanel)
EVT_PAINT(HighScorePanel::OnPaint)
EVT_BUTTON(7001, HighScorePanel::OnGameBackClick)
END_EVENT_TABLE()

HighScorePanel::HighScorePanel(MultiFrame * parent) : wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->LoadAssetBitmap();
	this->CheckHighScore();
	this->PrintScore();
	wgameBack = new wxBitmapButton(this, 7001, *gameBack, wxPoint(10, 10), wxDefaultSize, wxBORDER_NONE);
}

HighScorePanel::~HighScorePanel()
{
	delete highscorePicture;
	delete score0;
	delete score1;
	delete score2;
	delete score3;
	delete score4;
	delete wgameBack;
	delete gameBack;
}

void HighScorePanel::OnPaint(wxPaintEvent& event)
{
	wxPaintDC pdc(this);
	if (highscorePicture != nullptr)
	{
		pdc.DrawBitmap(*highscorePicture, wxPoint(0, 0), true);
	}
	if (score0 != nullptr)
	{
		pdc.DrawBitmap(*score0, wxPoint(565, 347), true);
	}
	if (score1 != nullptr)
	{
		pdc.DrawBitmap(*score1, wxPoint(595, 347), true);
	}
	if (score2 != nullptr)
	{
		pdc.DrawBitmap(*score2, wxPoint(625, 347), true);
	}
	if (score3 != nullptr)
	{
		pdc.DrawBitmap(*score3, wxPoint(655, 347), true);
	}
	if (score4 != nullptr)
	{
		pdc.DrawBitmap(*score4, wxPoint(685, 347), true);
	}
}

void HighScorePanel::LoadAssetBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\highscoreframe.png");
	wxImage highscoreimage(fileLocation, wxBITMAP_TYPE_PNG);
	highscorePicture = new wxBitmap(highscoreimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\gameback.png");
	wxImage gameback(fileLocation, wxBITMAP_TYPE_PNG);
	gameBack = new wxBitmap(gameback);
}

void HighScorePanel::CheckHighScore()
{
	ifstream score, highscore;
	ofstream highscorefix;
	string scoretext, highscoretext;
	int scoreval, highscoreval;

	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\highscore.txt");
	string textLocation = string(fileLocation.mb_str());
	highscore.open(textLocation);
	getline(highscore, highscoretext);
	highscoreval = stoi(highscoretext);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\score.txt");
	textLocation = string(fileLocation.mb_str());
	score.open(textLocation);
	getline(score, scoretext);
	scoreval = stoi(scoretext);

	highscore.close();
	score.close();

	if (scoreval > highscoreval)
	{
		wxStandardPaths &stdPaths = wxStandardPaths::Get();
		wxString fileLocation = stdPaths.GetExecutablePath();
		fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\highscore.txt");
		textLocation = string(fileLocation.mb_str());
		highscorefix.open(textLocation);
		highscorefix << scoretext;
		highscorefix.close();
	}
}

void HighScorePanel::PrintScore()
{
	string fString;
	ifstream myfile;
	int stringSize,zero;
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\highscore.txt");
	//wxMessageOutputDebug().Output(fileLocation);
	string textLocation = string(fileLocation.mb_str());
	myfile.open(textLocation);
	getline(myfile, fString);
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
	myfile.close();
}

void HighScorePanel::OnGameBackClick(wxCommandEvent& event)
{
	parentFrame->ShowMainPanel();
}