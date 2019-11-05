#pragma once
#include "Option.h"
class Input;

class Player
{
public:
	Player();
	~Player();

	void Update(const Input&);
	void Draw();

private:
	LaneType _nowLane;
	const Input _input;
};

