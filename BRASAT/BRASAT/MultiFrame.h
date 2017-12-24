#pragma once
#include "wx\wx.h"

class MainPanel;
class InstructionPanel;
class GamePanel;
class PausePanel;
class HighScorePanel;
class EpilogPanel;

class MultiFrame : public wxFrame
{
private:
	wxBoxSizer* boxSizer;
	MainPanel* mainPanel;
	InstructionPanel *instructionPanel;
	GamePanel* gamePanel;
	PausePanel* pausePanel;
	HighScorePanel* highScorePanel;
	EpilogPanel* epilogPanel;
<<<<<<< Updated upstream

=======
	CreditPanel* creditPanel;
<<<<<<< HEAD
	int ResSume=0;
=======

>>>>>>> master
>>>>>>> Stashed changes
	void fitWindowSize();
public:
	MultiFrame(const wxString &title);
	void InitComponents();
	void ShowMainPanel();
	void ShowInstructionPanel();
	void ShowPausePanel();
	void ShowHighScorePanel();
	void ShowEpilogPanel();
	~MultiFrame();
};

