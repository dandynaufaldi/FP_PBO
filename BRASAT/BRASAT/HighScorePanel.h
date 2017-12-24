#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include "wx\button.h"
#include "MultiFrame.h"
class HighScorePanel : public wxPanel
{
public:
	HighScorePanel(MultiFrame* parent);
	~HighScorePanel();
	void OnPaint(wxPaintEvent &event);
	void OnGameBackClick(wxCommandEvent& event);
	void LoadAssetBitmap();
	void CheckHighScore();
	void PrintScore();
private:
	MultiFrame *parentFrame;
	wxBitmap *highscorePicture = nullptr;
	wxBitmap *score0 = nullptr;
	wxBitmap *score1 = nullptr;
	wxBitmap *score2 = nullptr;
	wxBitmap *score3 = nullptr;
	wxBitmap *score4 = nullptr;
	wxBitmap *gameBack = nullptr;
	wxBitmapButton *wgameBack;
	DECLARE_EVENT_TABLE()
};

