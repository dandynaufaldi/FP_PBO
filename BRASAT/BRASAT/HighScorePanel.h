#pragma once
#include "wx\wx.h"
#include "MultiFrame.h"
class HighScorePanel : public wxPanel
{
public:
	HighScorePanel(MultiFrame* parent);
	~HighScorePanel();
private:
	MultiFrame *parentFrame;
};

