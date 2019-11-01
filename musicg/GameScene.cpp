#include "GameScene.h"
#include <DxLib.h>
#include "Input.h"
#include "Application.h"
#include "ResultScene.h"
#include "SceneMng.h"
#include "NormalNote.h"
#include "LongNote.h"
#include "Player.h"

constexpr int fade_interval = 60;

GameScene::GameScene(SceneMng& mng) :BaseScene(mng)
{
	_fadeCounter = 60;

	_updater = &GameScene::FadeinUpdate;
	_drawer = &GameScene::FadeDrawer;
	GameInit();
}

GameScene::~GameScene()
{
}

void GameScene::Update(const Input & input)
{
	++_frame;
	GameUpdate();
	(this->*_updater)(input);
}

void GameScene::Draw()
{
	GameDraw();
	
	(this->*_drawer)();
}

bool GameScene::GameInit()
{
	_notes.push_back(std::make_shared<NormalNote>(Position2f(640.0f, -120.0f)));
	_notes.push_back(std::make_shared<NormalNote>(Position2f(512.0f, -150.0f)));
	_notes.push_back(std::make_shared<NormalNote>(Position2f(640.0f, -180.0f)));
	_notes.push_back(std::make_shared<NormalNote>(Position2f(768.0f, -190.0f)));
	_notes.push_back(std::make_shared<NormalNote>(Position2f(640.0f, -200.0f)));

	_player = std::make_shared<Player>();
	return false;
}

void GameScene::GameUpdate()
{
	for (auto note : _notes)
	{
		note->Update();
	}
}

void GameScene::GameDraw()
{
	DrawLine(448, 0, 448, 720, 0xffffff);
	DrawLine(576, 0, 576, 720, 0xffffff);
	DrawLine(704, 0, 704, 720, 0xffffff);
	DrawLine(832, 0, 832, 720, 0xffffff);
	DrawLine(0, 688, 1280, 688, 0xc00000);
	for (auto note : _notes)
	{
		note->Draw();
	}
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
	
	if (input.Ispressed(0, "pause") && !input.IsTriggered(0, "pause"))
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
