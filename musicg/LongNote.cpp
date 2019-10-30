#include "LongNote.h"



LongNote::LongNote()
{
}

LongNote::LongNote(const Position2f & pos):BaseNote(pos)
{
	_type = noteType::Long;
}


LongNote::~LongNote()
{
}

void LongNote::Update()
{
}

void LongNote::Draw()
{
}
