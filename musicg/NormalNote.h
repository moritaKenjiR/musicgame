#pragma once
#include "BaseNote.h"

class NormalNote
	:public BaseNote
{
public:
	NormalNote();
	NormalNote(const Position2f& pos);
	~NormalNote();
	void Update()override final;
	void Draw()override final;
};

