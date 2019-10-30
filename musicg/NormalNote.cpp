#include "NormalNote.h"
#include <DxLib.h>


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
}

void NormalNote::Draw()
{
	DrawCircle(_pos.x, _pos.y, 10, 0xc03030);
}
