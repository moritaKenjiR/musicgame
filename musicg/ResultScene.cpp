#include "ResultScene.h"
#include <DxLib.h>
#include "Input.h"
#include "Application.h"
#include "TitleScene.h"
#include "SceneMng.h"

constexpr int fade_interval = 60;

ResultScene::ResultScene(SceneMng& mng) :BaseScene(mng)
{
	_fadeCounter = 60;

	_updater = &ResultScene::FadeinUpdate;
	_drawer = &ResultScene::FadeDrawer;
}

ResultScene::~ResultScene()
{
}

void ResultScene::Update(const Input & input)
{
	++_frame;
	(this->*_updater)(input);
}

void ResultScene::Draw()
{
	(this->*_drawer)();
}

void ResultScene::FadeinUpdate(const Input &)
{
	if (--_fadeCounter <= 0)
	{
		_updater = &ResultScene::WaitUpdate;
		_drawer = &ResultScene::NormalDrawer;
	}
}

void ResultScene::WaitUpdate(const Input & input)
{
	if (input.Ispressed(0, "ok") && !input.IsTriggered(0, "ok"))
	{
		_updater = &ResultScene::FadeoutUpdate;
		_drawer = &ResultScene::FadeDrawer;
	}
}

void ResultScene::FadeoutUpdate(const Input &)
{
	if (++_fadeCounter >= fade_interval)
	{
		_mng.ChangeScene(std::make_unique<TitleScene>(_mng));
	}
}

void ResultScene::FadeDrawer()
{
	auto wsize = Application::Instance().GetConfig().GetScreenSize();
	DrawString(100, 100, "ResultScene", 0xffffff);

	auto blendval = _fadeCounter * 255 / fade_interval;
	SetDrawBlendMode(DX_BLENDMODE_MULA, blendval);
	DrawBox(0, 0, wsize.w, wsize.h, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void ResultScene::NormalDrawer()
{
	DrawString(100, 100, "ResultScene", 0xffffff);
}
