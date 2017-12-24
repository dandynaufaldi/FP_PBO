#pragma once
#include "GameObject.h"
WX_DECLARE_OBJARRAY(wxBitmap*, ManArray);
class Man : public GameObject
{
private:
	int direction = -1;
	int manMove = 0;
	int maxY = 250;
	int minY = 450;
	int moveAmount = 20;
	wxBitmap *tempBitmap = nullptr;
	ManArray *manArray;
public:
	Man();
	~Man();
	virtual void Draw(wxAutoBufferedPaintDC &dc, int counter);
	virtual void Move(int dif);
	void SetmanMove(int flag);
	void SetmoveAmount(int moveAmount);
	int getDirection();
	int getmanMove();
	void setDirection(int dir);
	void loadBitmap();
};

