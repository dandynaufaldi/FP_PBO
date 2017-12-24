#include "MultiFrame.h"
#include "MainPanel.h"
#include "InstructionPanel.h"
#include "PausePanel.h"
#include "GamePanel.h"
#include "HighScorePanel.h"
#include "EpilogPanel.h"
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
#include "CreditPanel.h"
<<<<<<< HEAD
#include <windows.h>
#include <mmsystem.h>
=======
>>>>>>> master
>>>>>>> Stashed changes
=======
#include "CreditPanel.h"
>>>>>>> master


MultiFrame::MultiFrame(const wxString & title) : wxFrame(NULL, wxID_ANY, title)
{
	this->InitComponents();
}

void MultiFrame::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->mainPanel = new MainPanel(this);
	this->mainPanel->Show(false);
	this->boxSizer->Add(mainPanel, 1, wxEXPAND, 0);

	this->instructionPanel = new InstructionPanel(this);
	this->instructionPanel->Show(false);
	this->boxSizer->Add(instructionPanel, 1, wxEXPAND, 0);

	this->gamePanel = new GamePanel(this);
	this->gamePanel->Show(false);
	this->boxSizer->Add(gamePanel, 1, wxEXPAND, 0);
	
	this->pausePanel = new PausePanel(this);
	this->pausePanel->Show(false);
	this->boxSizer->Add(pausePanel, 1, wxEXPAND, 0);
	
	this->highScorePanel = new HighScorePanel(this);
	this->highScorePanel->Show(false);
	this->boxSizer->Add(highScorePanel, 1, wxEXPAND, 0);
	
	this->epilogPanel = new EpilogPanel(this);
	this->epilogPanel->Show(false);
	this->boxSizer->Add(epilogPanel, 1, wxEXPAND, 0);

	this->creditPanel = new CreditPanel(this);
	this->creditPanel->Show(false);
	this->boxSizer->Add(creditPanel, 1, wxEXPAND, 0);

	SetSizer(boxSizer);

	ShowMainPanel();
}

void MultiFrame::ShowMainPanel()
{
	this->mainPanel->Show(true);
	this->gamePanel->Show(false);
	this->pausePanel->Show(false);
	this->highScorePanel->Show(false);
	this->epilogPanel->Show(false);
	this->instructionPanel->Show(false);
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
	this->creditPanel->Show(false);
<<<<<<< HEAD
	fitWindowSize();
}
=======
=======
	this->creditPanel->Show(false);
>>>>>>> master

	fitWindowSize();
}

void MultiFrame::ShowGamePanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(true);
	this->pausePanel->Show(false);
	this->highScorePanel->Show(false);
	this->epilogPanel->Show(false);
	this->instructionPanel->Show(false);
	this->creditPanel->Show(false);
<<<<<<< HEAD
>>>>>>> master
>>>>>>> Stashed changes
=======
>>>>>>> master

	fitWindowSize();
}

void MultiFrame::ShowInstructionPanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(false);
	this->pausePanel->Show(false);
	this->highScorePanel->Show(false);
	this->epilogPanel->Show(false);
	this->instructionPanel->Show(true);
	this->creditPanel->Show(false);

	fitWindowSize();
}

void MultiFrame::ShowPausePanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(false);
	this->pausePanel->Show(true);
	this->highScorePanel->Show(false);
	this->epilogPanel->Show(false);
	this->instructionPanel->Show(false);
	this->creditPanel->Show(false);

	fitWindowSize();
}

void MultiFrame::ShowHighScorePanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(false);
	this->pausePanel->Show(false);
	this->highScorePanel->Show(true);
	this->epilogPanel->Show(false);
	this->instructionPanel->Show(false);
	this->creditPanel->Show(false);

	fitWindowSize();
}

void MultiFrame::ShowEpilogPanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(false);
	this->pausePanel->Show(false);
	this->highScorePanel->Show(false);
	this->epilogPanel->Show(true);
	this->instructionPanel->Show(false);
	this->creditPanel->Show(false);

	fitWindowSize();
}

void MultiFrame::ShowCreditPanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(false);
	this->pausePanel->Show(false);
	this->highScorePanel->Show(false);
	this->epilogPanel->Show(false);
	this->instructionPanel->Show(false);
	this->creditPanel->Show(true);

	fitWindowSize();
}

MultiFrame::~MultiFrame()
{
	delete mainPanel;
	delete gamePanel;
	delete pausePanel;
	delete highScorePanel;
	delete instructionPanel;
	delete epilogPanel;
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
	delete creditPanel;
<<<<<<< HEAD
}

int MultiFrame::getResSum()
{
	return this->ResSume;
}

void MultiFrame::setResSum(int flag)
{
	this->ResSume = flag;
=======
>>>>>>> master
>>>>>>> Stashed changes
=======
	delete creditPanel;
>>>>>>> master
}

void MultiFrame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(1280, 720));
	this->Layout();
}