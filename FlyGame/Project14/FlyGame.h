#pragma once
#include "olcConsoleGameEngineOOP.h"

class FlyGame : public olcConsoleGameEngineOOP {

public:
	// A new type of data collection, the fly
	FlyGame();
	~FlyGame();
	void RenderWorld();
	struct Fly
	{
		int direction;
		float x;
		float y;
		float speedSecond = 15;
		int colour;
		wchar_t symbol;
	};
	struct FrootLoop
	{
		int x;
		int y;
		int colour;
		wchar_t symbol;
	};

protected:
	// private variables can feel bad at first, like using globals
	// Remember though, we're encapsulating them. Don't go ham though.
	// Create an instance of a Fly for our blue fly
	int _score;

	
	// FLY SETUP
	const int START_X = 5;
	const int FLY_COLOUR = BG_DARK_GREEN | FG_WHITE;
	const int GROUND_COLOUR = BG_DARK_BLUE | FG_DARK_GREEN;
	const int BORDER_COLOUR = BG_DARK_GREEN | FG_WHITE;
	const int SCORE_COLOUR = BG_DARK_GREEN | FG_WHITE;
	const int ORANGEFROOT = BG_DARK_GREEN | FG_YELLOW;
	//FROOT ORANGE SETUP


	Fly _blueFly;
	FrootLoop yellow;
	// Inherited via olcConsoleGameEngineOOP
	void FlyMoving(int direction, float fElapsedTime);
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;
};