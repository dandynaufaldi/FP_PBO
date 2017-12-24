#include "wx/wxprec.h" 
#include "MultiFrame.h"  

#ifndef WX_PRECOMP 
#include "wx/wx.h" 
#endif  

class MyApp : public wxApp {
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

DECLARE_APP(MyApp)

bool MyApp::OnInit() {
	MultiFrame *frame = new MultiFrame("Window Switcher");
	frame->Show(true);
	return true;
}