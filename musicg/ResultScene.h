#pragma once
#include "BaseScene.h"
class SceneMng;
class Input;

class ResultScene :
	public BaseScene
{
public:
	ResultScene(SceneMng& mng);
	~ResultScene();
	void Update(const Input& input);
	void Draw();

private:
	unsigned int _frame = 0;

	void FadeinUpdate(const Input&);
	void WaitUpdate(const Input&);
	void FadeoutUpdate(const Input&);

	void FadeDrawer();
	void NormalDrawer();

	void (ResultScene::*_updater)(const Input&);
	void (ResultScene::*_drawer)();

	int _fadeCounter;
};

