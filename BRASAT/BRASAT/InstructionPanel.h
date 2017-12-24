#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include "wx\button.h"
#include "MultiFrame.h"
class InstructionPanel : public wxPanel
{
public:
	InstructionPanel(MultiFrame* parent);
	~InstructionPanel();
	void OnInstructionPictureClick(wxCommandEvent& event);
private:
	MultiFrame *parentFrame;
	wxBitmap *instructionPicture = nullptr;

	void LoadAssetBitmap();
	wxBitmapButton *winstructionPicture;
	DECLARE_EVENT_TABLE()
};

