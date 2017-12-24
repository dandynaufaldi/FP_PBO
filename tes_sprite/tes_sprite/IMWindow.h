#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include "wx\button.h"

class ImageWindow : public wxWindow
{

public:
	ImageWindow(wxFrame *parent);
	~ImageWindow();
	void OnPaint(wxPaintEvent &event);
	void OnTimer(wxTimerEvent &event);
	void OnButtonClick(wxCommandEvent& event);

private:
	wxBitmap *potatoBitmap = nullptr;
	wxBitmap *spriteBitmap = nullptr;
	wxBitmap *logo = nullptr;
	wxBitmap *buttonStart = nullptr;
	wxBitmap *buttonInstruction = nullptr;
	wxBitmap *buttonCredit = nullptr;
	wxBitmap *buttonScore = nullptr;
	wxTimer *timer;
	DECLARE_EVENT_TABLE()
	void LoadAssetBitmap();
	wxBitmapButton *button1;
	wxBitmapButton *button2;
	wxBitmapButton *button3;
	wxBitmapButton *button4;
};