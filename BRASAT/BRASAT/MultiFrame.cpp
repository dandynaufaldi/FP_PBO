#include "MultiFrame.h"
#include "MainPanel.h"
#include "InstructionPanel.h"
#include "PausePanel.h"
#include "GamePanel.h"
#include "HighScorePanel.h"
#include "EpilogPanel.h"
#include "CreditPanel.h"


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
	this->creditPanel->Show(false);

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
	delete creditPanel;
}

void MultiFrame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(1280, 720));
	this->Layout();
}