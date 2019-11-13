#include "NormalNote.h"
#include <DxLib.h>
#include "Option.h"

NormalNote::NormalNote()
{
}

NormalNote::NormalNote(const Position2f & pos) :BaseNote(pos)
{
	_type = noteType::Normal;
}


NormalNote::~NormalNote()
{
}

void NormalNote::Update()
{
	_pos.y += 16;
}

void NormalNote::Draw()
{
	DrawOval(_pos.x, _pos.y,32, 12, 0xc03030,true);
}
