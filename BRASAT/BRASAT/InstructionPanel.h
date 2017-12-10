#pragma once
#include "wx\wx.h"
#include "MultiFrame.h"
class InstructionPanel : public wxPanel
{
public:
	InstructionPanel(MultiFrame* parent);
	~InstructionPanel();
private:
	MultiFrame *parentFrame;
};

