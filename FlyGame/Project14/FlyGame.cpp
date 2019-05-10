#include "FlyGame.h"
#include <Windows.h>
#include <chrono>
#include <thread>
#include <random>


FlyGame::FlyGame()
{

}

FlyGame::~FlyGame()
{

}






bool FlyGame::OnUserCreate()
{
	yellow.x = 5;
	yellow.y = 15;
	_blueFly.x = _blueFly.y = START_X;
	_blueFly.colour = FLY_COLOUR;
	_blueFly.symbol = 0x2666;
	_blueFly.direction = NULL;
	yellow.colour = ORANGEFROOT;
	yellow.symbol = 0x004A;
	return true;
}

void FlyGame::FlyMoving(int direction, float fElapsedTime) {
	if (direction == 0) {
		_blueFly.y -= _blueFly.speedSecond * fElapsedTime;
	}
	if (direction == 1) {
		_blueFly.x += _blueFly.speedSecond * fElapsedTime;
	}
	if (direction == 2) {
		_blueFly.y +=  _blueFly.speedSecond * fElapsedTime;
	}
	if (direction == 3) {
		_blueFly.x -= _blueFly.speedSecond * fElapsedTime;
	}

}

bool FlyGame::OnUserUpdate(float fElapsedTime)
{
	










	//__--__--__--__--__--__--__--__--__--__--__--__--__--__--__--
	bool isLeftKeyHeld_, isRightKeyHeld_, isUpKeyHeld_, isDownKeyHeld_;
	isUpKeyHeld_ = (m_keys[VK_UP].bHeld || m_keys[VK_UP].bPressed) ? true : false;
	isDownKeyHeld_ = (m_keys[VK_DOWN].bHeld || m_keys[VK_DOWN].bPressed) ? true : false;
	isLeftKeyHeld_ = (m_keys[VK_LEFT].bHeld || m_keys[VK_LEFT].bPressed) ? true : false;
	isRightKeyHeld_ = (m_keys[VK_RIGHT].bHeld || m_keys[VK_RIGHT].bPressed) ? true : false;
	// update everything
	if (isUpKeyHeld_){
		_blueFly.direction = 0;
	}
	if (isRightKeyHeld_) {
		_blueFly.direction = 1;
	}
	if (isDownKeyHeld_) {
		_blueFly.direction = 2;
	}
	if (isLeftKeyHeld_) {
		_blueFly.direction = 3;
	}
	
	FlyMoving(_blueFly.direction, fElapsedTime);

	if (_blueFly.x > ScreenWidth()-1) { _blueFly.x = 1; };
	if (_blueFly.y > ScreenHeight()-1) { _blueFly.y = 1; };
	if (_blueFly.x < 1) { _blueFly.x = ScreenHeight() - 2; };
	if (_blueFly.y < 1) { _blueFly.y = ScreenWidth() - 2; };
	
	
	if (floor(_blueFly.x) == yellow.x && floor(_blueFly.y) == yellow.y) {
		yellow.x = rand() % (ScreenHeight() - 3);
		yellow.x += 1;
		yellow.y = rand() % (ScreenWidth() - 3);
		yellow.y += 1;
		_score += 50;
	}

	// Draw the world
	RenderWorld();
	//this_thread::sleep_for(chrono::milliseconds(15));
	
	return true;
}

void FlyGame::RenderWorld()
{
	//convert keystates to strings ( 1 | 0 )
	wstring upKeyHeldState = to_wstring(m_keys[VK_UP].bHeld);
	wstring downKeyHeldState = to_wstring(m_keys[VK_DOWN].bHeld);
	wstring leftKeyHeldState = to_wstring(m_keys[VK_LEFT].bHeld);
	wstring rightKeyHeldState = to_wstring(m_keys[VK_RIGHT].bHeld);
	
	// grass drawing
	Fill(1, 1, ScreenWidth()-1, ScreenHeight()-1, PIXEL_SOLID, GROUND_COLOUR); //
	
	//key debugging0
	/*
	DrawString(0, 0, L"Key UP: " + upKeyHeldState, GROUND_COLOUR);
	DrawString(0, 1, L"Key DOWN: " + downKeyHeldState, GROUND_COLOUR);
	DrawString(0, 2, L"Key LEFT: " + leftKeyHeldState, GROUND_COLOUR);
	DrawString(0, 3, L"Key RIGHT: " + rightKeyHeldState, GROUND_COLOUR);
	*/
	Fill(0, ScreenHeight() - 1, 1, ScreenHeight() + 1, wchar_t(0x255A), BORDER_COLOUR);
	Fill(0, -1, 1, 1, wchar_t(0x2554), BORDER_COLOUR);
	Fill(ScreenWidth() - 1, 0, ScreenWidth(), 1, wchar_t(0x2557), BORDER_COLOUR);
	Fill(ScreenWidth() - 1, ScreenHeight() - 1, ScreenWidth(), ScreenHeight(), wchar_t(0x255D), BORDER_COLOUR);
	Fill(0, 1, 1, ScreenHeight() - 1, wchar_t(0x2551), BORDER_COLOUR);
	Fill(1, 0, ScreenWidth() - 1, 1, wchar_t(0x2550), BORDER_COLOUR);
	Fill(ScreenWidth() - 1, 1, ScreenWidth() + 1, ScreenHeight() - 1, wchar_t(0x2551), BORDER_COLOUR);
	Fill(1, ScreenHeight()-1, ScreenWidth() - 1, ScreenHeight() + 1, wchar_t(0x2550), BORDER_COLOUR);

	DrawString(2, 0, L"Score: " + to_wstring(_score), SCORE_COLOUR);
	// Draw the fly
	Draw(_blueFly.x, _blueFly.y, _blueFly.symbol, _blueFly.colour);
	Draw(yellow.x, yellow.y, yellow.symbol, yellow.colour);
}

