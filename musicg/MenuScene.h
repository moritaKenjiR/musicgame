#pragma once
#include "BaseScene.h"
class SceneMng;
class Input;

class MenuScene :
	public BaseScene
{
public:
	MenuScene(SceneMng& mng);
	~MenuScene();
	void Update(const Input& input);
	void Draw();

private:
	unsigned int _frame = 0;

	void FadeinUpdate(const Input&);
	void WaitUpdate(const Input&);
	void FadeoutUpdate(const Input&);

	void FadeDrawer();
	void NormalDrawer();

	void (MenuScene::*_updater)(const Input&);
	void (MenuScene::*_drawer)();

	int _fadeCounter;
};

