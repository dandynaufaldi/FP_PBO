#pragma once
#include "wx\wx.h"
#include "MultiFrame.h"
class PausePanel : public wxPanel
{
public:
	PausePanel(MultiFrame* parent);
	~PausePanel();
private:
	MultiFrame *parentFrame;
};

