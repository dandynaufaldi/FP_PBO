#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include "wx\button.h"
#include "MultiFrame.h"
class CreditPanel : public wxPanel
{
public:
	CreditPanel(MultiFrame* parent);
	~CreditPanel();
	void OnCreditPictureClick(wxCommandEvent& event);
private:
	MultiFrame *parentFrame;
	wxBitmap *creditPicture = nullptr;

	void LoadAssetBitmap();
	wxBitmapButton *wcreditPicture;
	DECLARE_EVENT_TABLE()
};

