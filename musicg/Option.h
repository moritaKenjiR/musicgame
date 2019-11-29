#pragma once
#include "Geometry.h"

enum class LaneType {
	L,
	C,
	R,
	L_Over,
	R_Over,
	max
};

enum class noteType
{
	Normal,
	Long,
	Side_L,
	Side_R,
	max,
};

class Option
{
public:
	~Option();
	static Option& Instance()
	{
		static Option Instance;
		return Instance;
	}

	void Update();
	
	void SetLaneMovePos(int MovePos);
	Position2 GetOffset();
private:
	Option();
	Option(const Option&);
	void operator=(const Option&);

	int _nowLanePos;
	int _moveLanePos;
	Position2 _laneOffset;
};