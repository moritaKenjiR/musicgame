#pragma once
#include "BaseScene.h"
class SceneMng;
class Input;

class GameScene :
	public BaseScene
{
public:
	GameScene(SceneMng& mng);
	~GameScene();
	void Update(const Input& input);
	void Draw();

private:
	unsigned int _frame = 0;

	void FadeinUpdate(const Input&);
	void WaitUpdate(const Input&);
	void FadeoutUpdate(const Input&);

	void FadeDrawer();
	void NormalDrawer();

	void (GameScene::*_updater)(const Input&);
	void (GameScene::*_drawer)();

	int _fadeCounter;
};

