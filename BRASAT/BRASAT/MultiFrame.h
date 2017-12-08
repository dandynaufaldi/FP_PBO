#pragma once
#include "wx\wx.h"

class MainPanel;
class GamePanel;
class PausePanel;
class HighScorePanel;
class EpilogPanel;

class MultiFrame : public wxFrame
{
private:
	wxBoxSizer* boxSizer;
	MainPanel* mainPanel;
	GamePanel* gamePanel;
	PausePanel* pausePanel;
	HighScorePanel* highScorePanel;
	EpilogPanel* epilogPanel;

	void fitWindowSize();
public:
	MultiFrame(const wxString &title);
	void InitComponents();
	void ShowMainPanel();
	void ShowPausePanel();
	void ShowHighScorePanel();
	void SHowEpilogPanel();
	~MultiFrame();
};

