#include "MainPanel.h"
#include "Man.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#define TIMER_ID 2000

BEGIN_EVENT_TABLE(MainPanel , wxPanel)
EVT_PAINT(MainPanel::OnPaint)
EVT_TIMER(TIMER_ID, MainPanel::OnTimer)
<<<<<<< Updated upstream
=======
EVT_BUTTON(1001, MainPanel::OnButtonStartClick)
EVT_BUTTON(1002, MainPanel::OnButtonInstructionClick)
<<<<<<< HEAD
EVT_BUTTON(1003, MainPanel::OnButtonScoreClick)
=======
>>>>>>> master
EVT_BUTTON(1004, MainPanel::OnButtonCreditClick)
>>>>>>> Stashed changes
END_EVENT_TABLE()

MainPanel::MainPanel(MultiFrame * parent) : wxPanel(parent, wxID_ANY), parentFrame(parent)
{

	this->SetBackgroundColour(wxColour(*wxBLACK));
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	this->LoadAssetBitmap();
	timer = new wxTimer(this, TIMER_ID);
	wbuttonStart = new wxBitmapButton(this, 1001, *buttonStart, wxPoint(504, 335), wxDefaultSize, wxBORDER_NONE);
	wbuttonInstruction = new wxBitmapButton(this, 1002, *buttonInstruction, wxPoint(504, 430), wxDefaultSize, wxBORDER_NONE);
	wbuttonScore = new wxBitmapButton(this, 1003, *buttonScore, wxPoint(504, 526), wxDefaultSize, wxBORDER_NONE);
	wbuttonCredit = new wxBitmapButton(this, 1004, *buttonCredit, wxPoint(504, 621), wxDefaultSize, wxBORDER_NONE);

	wbuttonStart->SetBitmapCurrent(*hoverbuttonStart);
	wbuttonInstruction->SetBitmapCurrent(*hoverbuttonInstruction);
	wbuttonScore->SetBitmapCurrent(*hoverbuttonScore);
	wbuttonCredit->SetBitmapCurrent(*hoverbuttonCredit);
	timer->Start(60);
}

MainPanel::~MainPanel()
{
	timer->Stop();
	delete tempBitmap;
	delete spriteBitmap;
	delete timer;
	delete logo;
	delete buttonStart;
	delete buttonInstruction;
	delete buttonCredit;
	delete buttonScore;
	delete hoverbuttonStart;
	delete hoverbuttonInstruction;
	delete hoverbuttonCredit;
	delete hoverbuttonScore;
	delete wbuttonStart;
	delete wbuttonInstruction;
	delete wbuttonScore;
	delete wbuttonCredit;
}

void MainPanel::OnPaint(wxPaintEvent & event)
{
	wxBufferedPaintDC pdc(this);
	PrepareDC(pdc);
	static int counter = 0;
	if (tempBitmap != nullptr)
	{
		wxMemoryDC temp;
		wxMemoryDC dcSource;
		dcSource.SelectObject(*spriteBitmap);
		temp.SelectObject(*tempBitmap);
		temp.SetBackground(*wxTRANSPARENT_BRUSH);
		temp.Clear();
		temp.Blit(0, 0, 242, 300, &dcSource, (counter % 17) * 242, 0, wxCOPY, true);
		temp.SelectObject(wxNullBitmap);
		dcSource.SelectObject(wxNullBitmap);
		pdc.DrawBitmap(*tempBitmap, wxPoint(0, 380), true);
		pdc.DrawBitmap(*logo, wxPoint(274, 90), true);
		counter++;
	}
}

void MainPanel::OnTimer(wxTimerEvent & event)
{
	static int counter = 0;
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);

	if (spriteBitmap != nullptr && tempBitmap != nullptr)
	{
		Refresh();
	}
}

void MainPanel::LoadAssetBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	tempBitmap = new wxBitmap(242, 300);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\man.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	spriteBitmap = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\brasat.png");
	wxImage logoimg(fileLocation, wxBITMAP_TYPE_PNG);
	logo = new wxBitmap(logoimg);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\NormButton_Start.png");
	wxImage startimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonStart = new wxBitmap(startimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\NormButton_Instruction.png");
	wxImage insimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonInstruction = new wxBitmap(insimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\NormButton_Score.png");
	wxImage scoreimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonScore = new wxBitmap(scoreimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\NormButton_Credit.png");
	wxImage creditimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonCredit = new wxBitmap(creditimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\HoverButton_Start.png");
	wxImage hoverstartimage(fileLocation, wxBITMAP_TYPE_PNG);
	hoverbuttonStart = new wxBitmap(hoverstartimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\HoverButton_Instruction.png");
	wxImage hoverinsimage(fileLocation, wxBITMAP_TYPE_PNG);
	hoverbuttonInstruction = new wxBitmap(hoverinsimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\HoverButton_Score.png");
	wxImage hoverscoreimage(fileLocation, wxBITMAP_TYPE_PNG);
	hoverbuttonScore = new wxBitmap(hoverscoreimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\HoverButton_Credit.png");
	wxImage hovercreditimage(fileLocation, wxBITMAP_TYPE_PNG);
	hoverbuttonCredit = new wxBitmap(hovercreditimage);
}
<<<<<<< Updated upstream
=======

void MainPanel::OnButtonStartClick(wxCommandEvent& event)
{
<<<<<<< HEAD
	PlaySound(TEXT("ingame.wav"), NULL, SND_FILENAME | SND_ASYNC);
=======
>>>>>>> master
	parentFrame->ShowGamePanel();
}

void MainPanel::OnButtonInstructionClick(wxCommandEvent& event)
{
	parentFrame->ShowInstructionPanel();
}

void MainPanel::OnButtonCreditClick(wxCommandEvent& event)
{
	parentFrame->ShowCreditPanel();
<<<<<<< HEAD
}

void MainPanel::OnButtonScoreClick(wxCommandEvent& event)
{
	parentFrame->ShowHighScorePanel();
=======
>>>>>>> master
}
>>>>>>> Stashed changes
