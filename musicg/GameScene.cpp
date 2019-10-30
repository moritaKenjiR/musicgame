#include "GameScene.h"
#include <DxLib.h>
#include "Input.h"
#include "Application.h"
#include "ResultScene.h"
#include "SceneMng.h"

constexpr int fade_interval = 60;

GameScene::GameScene(SceneMng& mng) :BaseScene(mng)
{
	_fadeCounter = 60;

	_updater = &GameScene::FadeinUpdate;
	_drawer = &GameScene::FadeDrawer;
}

GameScene::~GameScene()
{
}

void GameScene::Update(const Input & input)
{
	++_frame;
	(this->*_updater)(input);
}

void GameScene::Draw()
{
	GameDraw();
	(this->*_drawer)();
}

void GameScene::GameDraw()
{
}

void GameScene::FadeinUpdate(const Input &)
{
	if (--_fadeCounter <= 0)
	{
		_updater = &GameScene::WaitUpdate;
		_drawer = &GameScene::NormalDrawer;
	}
}

void GameScene::WaitUpdate(const Input & input)
{
	if (input.Ispressed(0, "ok") && !input.IsTriggered(0, "ok"))
	{
		_updater = &GameScene::FadeoutUpdate;
		_drawer = &GameScene::FadeDrawer;
	}
}

void GameScene::FadeoutUpdate(const Input &)
{
	if (++_fadeCounter >= fade_interval)
	{
		_mng.ChangeScene(std::make_unique<ResultScene>(_mng));
	}
}

void GameScene::FadeDrawer()
{
	auto wsize = Application::Instance().GetConfig().GetScreenSize();
	DrawString(100, 100, "GameScene", 0xffffff);

	auto blendval = _fadeCounter * 255 / fade_interval;
	SetDrawBlendMode(DX_BLENDMODE_MULA, blendval);
	DrawBox(0, 0, wsize.w, wsize.h, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GameScene::NormalDrawer()
{
	DrawString(100, 100, "GameScene", 0xffffff);
}
