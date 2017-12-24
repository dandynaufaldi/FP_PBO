#pragma once
#include "wx\wx.h"
#include "MultiFrame.h"
#include "wx\button.h"
#include "MultiFrame.h"

class Man;
class Obstacle;
class TownBack;
class MovingTownBack;
WX_DECLARE_OBJARRAY(Obstacle*, ObstacleArray);
class GamePanel : public wxPanel
{
public:
	GamePanel(MultiFrame* parent);
	~GamePanel();
	void setManJump(int flag);
	int getManJump();
	void setKeyDown(int flag);
	int getKeyDown();
	void OnTimer(wxTimerEvent &event);
	void OnKeyDown(wxKeyEvent &event);
	void OnKeyUp(wxKeyEvent &event);
	void OnPaint(wxPaintEvent &event);
	void EraseBackground(wxEraseEvent& WXUNUSED(event));
	void PrintScore(int score);
	void StartGame();
	void StopGame();
	void ResetGame();
private:
	MultiFrame *parentFrame;
	Man *man;
	Obstacle* curObs = nullptr;
	wxTimer *timer;
	wxBitmap *score0 = nullptr;
	wxBitmap *score1 = nullptr;
	wxBitmap *score2 = nullptr;
	wxBitmap *score3 = nullptr;
	wxBitmap *score4 = nullptr;
	int isKeyDown = 0;
	int isManJump = 0;
	bool isStarted;
	bool isPaused;
	bool isObsExist;
	long long score = 0;
	ObstacleArray* obstacleArray;
	MovingTownBack *movingTownBack;
	int angka;
	DECLARE_EVENT_TABLE()
};

