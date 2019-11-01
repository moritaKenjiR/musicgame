#pragma once
#include "Option.h"

class Player
{
public:
	Player();
	~Player();

	void Update();
	void Draw();

private:
	LaneType _nowLane;
};

