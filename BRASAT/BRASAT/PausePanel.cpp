#include "PausePanel.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <windows.h>
#include <mmsystem.h>

BEGIN_EVENT_TABLE(PausePanel, wxPanel)
EVT_BUTTON(9001, PausePanel::OnButtonResumeClick)
EVT_BUTTON(9002, PausePanel::OnButtonRestartClick)
EVT_BUTTON(9003, PausePanel::OnButtonQuitClick)
END_EVENT_TABLE()

PausePanel::PausePanel(MultiFrame * parent) : wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	/*wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);*/
	this->LoadAssetBitmap();

	wbuttonResume = new wxBitmapButton(this, 9001, *buttonResume, wxPoint(504, 290), wxDefaultSize, wxBORDER_NONE);
	wbuttonRestart = new wxBitmapButton(this, 9002, *buttonRestart, wxPoint(504, 385), wxDefaultSize, wxBORDER_NONE);
	wbuttonQuit = new wxBitmapButton(this, 9003, *buttonQuit, wxPoint(504, 481), wxDefaultSize, wxBORDER_NONE);

	wbuttonResume->SetBitmapCurrent(*hoverbuttonResume);
	wbuttonRestart->SetBitmapCurrent(*hoverbuttonRestart);
	wbuttonQuit->SetBitmapCurrent(*hoverbuttonQuit);
}

PausePanel::~PausePanel()
{
	delete buttonResume;
	delete buttonRestart;
	delete buttonQuit;
	delete wbuttonResume;
	delete wbuttonRestart;
	delete wbuttonQuit;
	delete hoverbuttonResume;
	delete hoverbuttonRestart;
	delete hoverbuttonQuit;
}

void PausePanel::LoadAssetBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\NormButton_Resume.png");
	wxImage resumeimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonResume = new wxBitmap(resumeimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\NormButton_Restart.png");
	wxImage restartimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonRestart = new wxBitmap(restartimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\NormButton_Quit.png");
	wxImage quitimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonQuit = new wxBitmap(quitimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\HoverButton_Resume.png");
	wxImage hoverresumeimage(fileLocation, wxBITMAP_TYPE_PNG);
	hoverbuttonResume = new wxBitmap(hoverresumeimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\HoverButton_Restart.png");
	wxImage hoverrestartimage(fileLocation, wxBITMAP_TYPE_PNG);
	hoverbuttonRestart = new wxBitmap(hoverrestartimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\HoverButton_Quit.png");
	wxImage hoverquitimage(fileLocation, wxBITMAP_TYPE_PNG);
	hoverbuttonQuit = new wxBitmap(hoverquitimage);
}

void PausePanel::OnButtonResumeClick(wxCommandEvent& event)
{
	this->parentFrame->setResSum(1);
	this->parentFrame->ShowGamePanel();
}

void PausePanel::OnButtonRestartClick(wxCommandEvent& event)
{
	this->parentFrame->setResSum(2);
	this->parentFrame->ShowGamePanel();
}

void PausePanel::OnButtonQuitClick(wxCommandEvent& event)
{
	PlaySound(TEXT("inmenu.wav"), NULL, SND_FILENAME | SND_ASYNC);
	parentFrame->ShowMainPanel();
}