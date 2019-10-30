#pragma once
#include "Geometry.h"

enum class noteType
{
	Normal,
	Long,
	max,
};

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

