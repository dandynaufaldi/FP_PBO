#include "CreditPanel.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

BEGIN_EVENT_TABLE(CreditPanel, wxPanel)
EVT_BUTTON(3001, CreditPanel::OnCreditPictureClick)
END_EVENT_TABLE()


CreditPanel::CreditPanel(MultiFrame * parent) : wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->LoadAssetBitmap();
	wcreditPicture = new wxBitmapButton(this, 3001, *creditPicture, wxPoint(0, 0), wxDefaultSize, wxBORDER_NONE);
}


CreditPanel::~CreditPanel()
{
	delete wcreditPicture;
	delete creditPicture;
}

void CreditPanel::LoadAssetBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\creditframe.png");
	wxImage creditimage(fileLocation, wxBITMAP_TYPE_PNG);
	creditPicture = new wxBitmap(creditimage);
}

void CreditPanel::OnCreditPictureClick(wxCommandEvent& event)
{
	parentFrame->ShowMainPanel();
}
