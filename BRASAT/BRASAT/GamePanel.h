#pragma once
#include "wx\wx.h"
#include "MultiFrame.h"
class GamePanel : public wxPanel
{
public:
	GamePanel(MultiFrame* parent);
	~GamePanel();
private:
	MultiFrame *parentFrame;
};

