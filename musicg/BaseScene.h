#pragma once
class SceneMng;
class Input;

class BaseScene
{
public:
	BaseScene(SceneMng& mng);
	virtual ~BaseScene();
	virtual void Update(const Input& input) = 0;
	virtual void Draw() = 0;
protected:
	SceneMng& _mng;
};

