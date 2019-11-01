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
	_pos.y += 4;
}

void NormalNote::Draw()
{
	DrawCircle(_pos.x, _pos.y, 32, 0xc03030);
}
