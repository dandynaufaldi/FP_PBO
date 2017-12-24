#pragma once
#include "wx\wx.h"
#include "GameObject.h"
class TownBack : public GameObject
{
private:
	int moveAmount;
public:
	TownBack();
	~TownBack();
	void SetmoveAmount(int moveAmount);
	int GetmoveAmount();
	virtual void Move(int dif);
	virtual void Draw(wxAutoBufferedPaintDC &dc);
};

