#include "IMFrame.h"
#include "IMWindow.h"


ImageFrame::ImageFrame(const wxString & title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->window = new ImageWindow(this);
	this->SetInitialSize(wxSize(1280, 720));
}
