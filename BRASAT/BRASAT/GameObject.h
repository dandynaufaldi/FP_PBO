#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include <string>
class GameObject
{
private:
	int posX;
	int posY;
	int width;
	int height;
	std::string filePath;
	wxBitmap *gameObject = nullptr;
public:
	GameObject();
	~GameObject();
	void setPosX(int posX);
	int getPosX();
	void setPosxY(int posY);
	int getPosY();
	void setWidth(int width);
	int getWidth();
	void setHeight(int height);
	int getHeight();
	void setFilePath(std::string filePath);
	virtual void loadBitmap();
	virtual void Draw(wxBufferedPaintDC &dc)=0;
	bool isCollide(GameObject *opponent);
};

