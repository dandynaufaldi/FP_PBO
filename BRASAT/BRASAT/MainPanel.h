#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include "wx\button.h"
#include "MultiFrame.h"
class Man;
class MainPanel : public wxPanel
{
public:
	MainPanel(MultiFrame* parent);
	~MainPanel();
	void OnPaint(wxPaintEvent &event);
	void OnTimer(wxTimerEvent &event);
<<<<<<< Updated upstream
=======
	void OnButtonStartClick(wxCommandEvent& event);
	void OnButtonInstructionClick(wxCommandEvent& event);
	void OnButtonCreditClick(wxCommandEvent& event);
<<<<<<< HEAD
	void OnButtonScoreClick(wxCommandEvent& event);
=======
>>>>>>> master


>>>>>>> Stashed changes
private:
	MultiFrame *parentFrame;
	Man *mainMan;
	wxBitmap *logo = nullptr;
	wxBitmap *buttonStart = nullptr;
	wxBitmap *buttonInstruction = nullptr;
	wxBitmap *buttonCredit = nullptr;
	wxBitmap *buttonScore = nullptr;
	wxBitmap *hoverbuttonStart = nullptr;
	wxBitmap *hoverbuttonInstruction = nullptr;
	wxBitmap *hoverbuttonCredit = nullptr;
	wxBitmap *hoverbuttonScore = nullptr;

	wxBitmap *tempBitmap = nullptr;
	wxBitmap *spriteBitmap = nullptr;
	wxTimer *timer;

	void LoadAssetBitmap();
	wxBitmapButton *wbuttonStart;
	wxBitmapButton *wbuttonInstruction;
	wxBitmapButton *wbuttonScore;
	wxBitmapButton *wbuttonCredit;
	DECLARE_EVENT_TABLE()
};

