#pragma once
#include "Geometry.h"
#include "Option.h"


class BaseNote
{
public:
	BaseNote();
	BaseNote(const Position2f& pos);
	virtual ~BaseNote();
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	Position2f _pos;
	noteType _type;
};

