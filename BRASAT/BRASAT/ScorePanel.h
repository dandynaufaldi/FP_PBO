#pragma once
#include "wx\wx.h"

class MainPanel;
class InstructionPanel;
class GamePanel;
class PausePanel;
class HighScorePanel;
class EpilogPanel;
class CreditPanel;
class ScorePanel
{
private:
	wxBoxSizer* boxSizer;
	MainPanel* mainPanel;
	InstructionPanel *instructionPanel;
	GamePanel* gamePanel;
	PausePanel* pausePanel;
	HighScorePanel* highScorePanel;
	EpilogPanel* epilogPanel;
	CreditPanel* creditPanel;
	void fitWindowSize();
public:
	ScorePanel(const wxString &title);
	~ScorePanel();
};

