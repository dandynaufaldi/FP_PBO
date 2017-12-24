#pragma once
#include "wx\wx.h"
#include "MultiFrame.h"
class EpilogPanel : public wxPanel
{
public:
	EpilogPanel(MultiFrame* parent);
	~EpilogPanel();
private:
	MultiFrame *parentFrame;
};

