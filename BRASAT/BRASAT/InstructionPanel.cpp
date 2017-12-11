#include "InstructionPanel.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

BEGIN_EVENT_TABLE(InstructionPanel, wxPanel)
EVT_BUTTON(2001,InstructionPanel::OnInstructionPictureClick)
END_EVENT_TABLE()


InstructionPanel::InstructionPanel(MultiFrame * parent) : wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->LoadAssetBitmap();
	winstructionPicture = new wxBitmapButton(this, 2001, *instructionPicture, wxPoint(0, 0), wxDefaultSize, wxBORDER_NONE);

}

InstructionPanel::~InstructionPanel()
{
	delete winstructionPicture;
	delete instructionPicture;
}

void InstructionPanel::LoadAssetBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\tutorialframe.png");
	wxImage instructionimage(fileLocation, wxBITMAP_TYPE_PNG);
	instructionPicture = new wxBitmap(instructionimage);
}

void InstructionPanel::OnInstructionPictureClick(wxCommandEvent& event)
{
	parentFrame->ShowMainPanel();
}
