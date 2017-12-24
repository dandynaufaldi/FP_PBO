#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include "wx\button.h"
#include "MultiFrame.h"

class EpilogPanel : public wxPanel
{
public:
	EpilogPanel(MultiFrame* parent);
	~EpilogPanel();
	void OnPaint(wxPaintEvent &event);
	void OnButtonQuitClick(wxCommandEvent& event);
	void LoadAssetBitmap();
	void PrintScore();
private:
	MultiFrame *parentFrame;
	wxBitmap *epilogPicture = nullptr;
	wxBitmap *buttonQuit;
	wxBitmap *hoverbuttonQuit;
	wxBitmapButton *wbuttonQuit;
	wxBitmap *score0 = nullptr;
	wxBitmap *score1 = nullptr;
	wxBitmap *score2 = nullptr;
	wxBitmap *score3 = nullptr;
	wxBitmap *score4 = nullptr;
	DECLARE_EVENT_TABLE()
};

