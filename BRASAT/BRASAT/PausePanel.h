#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include "wx\button.h"
#include "MultiFrame.h"
class PausePanel : public wxPanel
{
public:
	PausePanel(MultiFrame* parent);
	~PausePanel();
	void OnButtonResumeClick(wxCommandEvent& event);
	void OnButtonRestartClick(wxCommandEvent& event);
	void OnButtonQuitClick(wxCommandEvent& event);
private:
	MultiFrame *parentFrame;
	wxBitmap *buttonResume = nullptr;
	wxBitmap *buttonRestart = nullptr;
	wxBitmap *buttonQuit = nullptr;
	wxBitmap *hoverbuttonResume = nullptr;
	wxBitmap *hoverbuttonRestart = nullptr;
	wxBitmap *hoverbuttonQuit = nullptr;

	void LoadAssetBitmap();
	wxBitmapButton *wbuttonResume;
	wxBitmapButton *wbuttonRestart;
	wxBitmapButton *wbuttonQuit;
	DECLARE_EVENT_TABLE()
};

