#include "Player.h"
#include "Input.h"
#include <DxLib.h>


Player::Player()
{
	_nowLane = LaneType::C;
}



Player::~Player()
{
}


void Player::Update(const Input & input)
{
	if (input.Ispressed(0, "left") && !input.IsTriggered(0, "left"))
	{
		if (_nowLane == LaneType::C) _nowLane = LaneType::L;
		else if(_nowLane == LaneType::R) _nowLane = LaneType::C;
	}
	else if (input.Ispressed(0, "right") && !input.IsTriggered(0, "right"))
	{
		if (_nowLane == LaneType::L) _nowLane = LaneType::C;
		else if (_nowLane == LaneType::C) _nowLane = LaneType::R;
	}
}

void Player::Draw()
{
	switch (_nowLane)
	{
	case LaneType::L:
		DrawBox(448, 400, 576, 700, GetColor(150, 100, 100), true);
		break;
	case LaneType::C:
		DrawBox(576, 400, 704, 700, GetColor(150, 100, 100), true);
		break;
	case LaneType::R:
		DrawBox(704, 400, 832, 700, GetColor(150, 100, 100), true);
		break;
	default:
		break;
	}
}
