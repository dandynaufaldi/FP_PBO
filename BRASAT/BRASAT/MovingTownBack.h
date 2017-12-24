#pragma once
#include "wx\wx.h"
#include "TownBack.h"
WX_DECLARE_OBJARRAY(TownBack*, TownBackArray);
class MovingTownBack
{
private:
	TownBackArray *townBackArray;
public:
	MovingTownBack();
	~MovingTownBack();
	void checkArray();
	void loadBitmap();
	virtual void Draw(wxAutoBufferedPaintDC &dc);
};

