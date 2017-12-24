#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
private:
	int direction = -1;
	int moveAmount = 20;

public:
	Obstacle();
	~Obstacle();
	virtual void Draw(wxAutoBufferedPaintDC &dc);
	virtual void Move(int dif);
	void SetmoveAmount(int moveAmount);
};

