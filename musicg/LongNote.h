#pragma once
#include "BaseNote.h"
class LongNote :
	public BaseNote
{
public:
	LongNote();
	LongNote(const Position2f& pos);
	~LongNote();
	void Update()override final;
	void Draw()override final;
};

