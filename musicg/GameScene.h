#pragma once
#include "BaseScene.h"
#include <memory>
#include <vector>
class BaseNote;
class SceneMng;
class Input;
class Player;

class GameScene :
	public BaseScene
{
public:
	GameScene(SceneMng& mng);
	~GameScene();
	void Update(const Input& input);
	void Draw();
	bool GameInit();
	void GameUpdate(const Input &);
	void GameDraw();
private:
	std::vector<std::shared_ptr<BaseNote>> _notes;
	std::shared_ptr<Player> _player;




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

