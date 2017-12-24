#include "IMWindow.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#define TIMER_ID 2000
BEGIN_EVENT_TABLE(ImageWindow, wxWindow)
EVT_PAINT(ImageWindow::OnPaint)
EVT_TIMER(TIMER_ID, ImageWindow::OnTimer)
END_EVENT_TABLE()

ImageWindow::ImageWindow(wxFrame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	//load	PNGHandler	untuk	membaca	file	PNG.
	wxImageHandler *jpegLoader = new wxPNGHandler();
	wxImage::AddHandler(jpegLoader);
	//load	image
	this->LoadAssetBitmap();
	timer = new wxTimer(this, TIMER_ID);
	button1 = new wxBitmapButton(this, 1001, *buttonStart, wxPoint(504, 335), wxDefaultSize, wxBORDER_NONE);
	button2 = new wxBitmapButton(this, 1002, *buttonInstruction, wxPoint(504, 430), wxDefaultSize, wxBORDER_NONE);
	button3 = new wxBitmapButton(this, 1003, *buttonScore, wxPoint(504, 526), wxDefaultSize, wxBORDER_NONE);
	button4 = new wxBitmapButton(this, 1004, *buttonCredit, wxPoint(504, 621), wxDefaultSize, wxBORDER_NONE);
	timer->Start(40);
}
ImageWindow::~ImageWindow()
{
	delete potatoBitmap;
	timer->Stop();
	delete spriteBitmap;
}
void ImageWindow::LoadAssetBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	spriteBitmap = new wxBitmap(242, 300);

	fileLocation = wxFileName(fileLocation).GetPath() +	wxT("\\man_sprite.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	potatoBitmap = new wxBitmap(image);
	
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\brasat.png");
	wxImage logoimg(fileLocation, wxBITMAP_TYPE_PNG);
	logo = new wxBitmap(logoimg);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\StartButton.png");
	wxImage startimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonStart = new wxBitmap(startimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\InsButton.png");
	wxImage insimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonInstruction = new wxBitmap(insimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\HighScoreButton.png");
	wxImage scoreimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonScore = new wxBitmap(scoreimage);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\CreditButton.png");
	wxImage creditimage(fileLocation, wxBITMAP_TYPE_PNG);
	buttonCredit = new wxBitmap(creditimage);
}
void ImageWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	static int counter = 0;
	if (spriteBitmap != nullptr)
	{
		wxMemoryDC temp;
		wxMemoryDC dcSource;
		dcSource.SelectObject(*potatoBitmap);
		temp.SelectObject(*spriteBitmap);
		temp.SetBackground(*wxTRANSPARENT_BRUSH);
		temp.Clear();
		temp.Blit(0, 0, 242, 300, &dcSource, (counter%17) * 242, 0, wxCOPY, true);
		temp.SelectObject(wxNullBitmap);
		dcSource.SelectObject(wxNullBitmap);
		pdc.DrawBitmap(*spriteBitmap, wxPoint(0, 380), true);
		pdc.DrawBitmap(*logo, wxPoint(274, 90), true);
		counter++;


	}
}

void ImageWindow::OnTimer(wxTimerEvent & event)
{
	static int counter = 0;
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);

	if (spriteBitmap != nullptr && potatoBitmap != nullptr)
	{
		Refresh();
	}
}
