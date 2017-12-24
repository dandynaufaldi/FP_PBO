#include "EpilogPanel.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

BEGIN_EVENT_TABLE(EpilogPanel, wxPanel)
EVT_BUTTON(5001, EpilogPanel::OnButtonQuitClick)
EVT_PAINT(EpilogPanel::OnPaint)
END_EVENT_TABLE()

EpilogPanel::EpilogPanel(MultiFrame * parent) : wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->LoadAssetBitmap();
	wbuttonQuit = new wxBitmapButton(this, 5001, *buttonQuit, wxPoint(505, 570), wxDefaultSize, wxBORDER_NONE);
	this->PrintScore();

	wbuttonQuit->SetBitmapCurrent(*hoverbuttonQuit);
}

EpilogPanel::~EpilogPanel()
{
	delete wbuttonQuit;
	delete buttonQuit;
	delete epilogPicture;
	delete score0;
	delete score1;
	delete score2;
	delete score3;
	delete score4;
}

void EpilogPanel::OnPaint(wxPaintEvent& event)
{
	wxPaintDC pdc(this);
	if (epilogPicture != nullptr)
	{
		pdc.DrawBitmap(*epilogPicture, wxPoint(0, 0), true);
	}
	if (score0 != nullptr)
	{
		pdc.DrawBitmap(*score0, wxPoint(655, 150), true);
	}
	if (score1 != nullptr)
	{
		pdc.DrawBitmap(*score1, wxPoint(685, 150), true);
	}
	if (score2 != nullptr)
	{
		pdc.DrawBitmap(*score2, wxPoint(715, 150), true);
	}
	if (score3 != nullptr)
	{
		pdc.DrawBitmap(*score3, wxPoint(745, 150), true);
	}
	if (score4 != nullptr)
	{
		pdc.DrawBitmap(*score4, wxPoint(775, 150), true);
	}
}

void EpilogPanel::LoadAssetBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\epilogframe.png");
	wxImage epilogimage(fileLocation, wxBITMAP_TYPE_PNG);
	epilogPicture = new wxBitmap(epilogimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\NormButton_Quit.png");
	wxImage quitimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonQuit = new wxBitmap(quitimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\HoverButton_Quit.png");
	wxImage hoverquitimage(fileLocation, wxBITMAP_TYPE_PNG);
	hoverbuttonQuit = new wxBitmap(hoverquitimage);
}

void EpilogPanel::PrintScore()
{
	string fString;
	ifstream myfile;
	int stringSize, zero;
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\score.txt");
	wxMessageOutputDebug().Output(fileLocation);
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

void EpilogPanel::OnButtonQuitClick(wxCommandEvent& event)
{
	PlaySound(TEXT("inmenu.wav"), NULL, SND_FILENAME | SND_ASYNC);
	parentFrame->ShowMainPanel();
}
