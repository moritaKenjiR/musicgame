#include "MenuScene.h"
#include <DxLib.h>
#include "Input.h"
#include "Application.h"
#include "GameScene.h"
#include "SceneMng.h"

constexpr int fade_interval = 60;

MenuScene::MenuScene(SceneMng& mng) :BaseScene(mng)
{
	_fadeCounter = 60;

	_updater = &MenuScene::FadeinUpdate;
	_drawer = &MenuScene::FadeDrawer;
}

MenuScene::~MenuScene()
{
}

void MenuScene::Update(const Input & input)
{
	++_frame;
	(this->*_updater)(input);
}

void MenuScene::Draw()
{
	(this->*_drawer)();
}

void MenuScene::FadeinUpdate(const Input &)
{
	if (--_fadeCounter <= 0)
	{
		_updater = &MenuScene::WaitUpdate;
		_drawer = &MenuScene::NormalDrawer;
	}
}

void MenuScene::WaitUpdate(const Input & input)
{
	if (input.Ispressed(0, "ok") && !input.IsTriggered(0, "ok"))
	{
		_updater = &MenuScene::FadeoutUpdate;
		_drawer = &MenuScene::FadeDrawer;
	}
}

void MenuScene::FadeoutUpdate(const Input &)
{
	if (++_fadeCounter >= fade_interval)
	{
		_mng.ChangeScene(std::make_unique<GameScene>(_mng));
	}
}

void MenuScene::FadeDrawer()
{
	auto wsize = Application::Instance().GetConfig().GetScreenSize();
	DrawString(100, 100, "MenuScene", 0xffffff);

	auto blendval = _fadeCounter * 255 / fade_interval;
	SetDrawBlendMode(DX_BLENDMODE_MULA, blendval);
	DrawBox(0, 0, wsize.w, wsize.h, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void MenuScene::NormalDrawer()
{
	DrawString(100, 100, "MenuScene", 0xffffff);
}
