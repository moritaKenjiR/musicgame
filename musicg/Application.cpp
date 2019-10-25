#include "Application.h"
#include <DxLib.h>
#include "SceneMng.h"
#include "Input.h"

constexpr int default_window_width = 1280;
constexpr int default_window_height = 720;

bool Application::Initialize()
{
	if (DxLib_Init() == -1) return false;
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowText("musicg");
	SetGraphMode(_config.GetScreenSize().w, _config.GetScreenSize().h, 16);
	ChangeWindowMode(true);
	
	_sceneMng = std::make_unique<SceneMng>();
	_input = std::make_shared<Input>();
	InitializeInput();
}


void Application::InitializeInput()
{
	_input->AddCommand(0, "left", 0, KEY_INPUT_LEFT);
	_input->AddCommand(0, "right", 0, KEY_INPUT_RIGHT);
	_input->AddCommand(0, "up", 0, KEY_INPUT_UP);
	_input->AddCommand(0, "down", 0, KEY_INPUT_DOWN);
	_input->AddCommand(0, "jump", 0, KEY_INPUT_Z);
	_input->AddCommand(0, "ok", 0, KEY_INPUT_RETURN);
	_input->AddCommand(0, "pause", 0, KEY_INPUT_P);
	_input->AddCommand(0, "forward", 0, KEY_INPUT_Q);
	_input->AddCommand(0, "back", 0, KEY_INPUT_E);
	_input->AddCommand(0, "rotate", 0, KEY_INPUT_R);

	for (int i = 0; i < _input->GetConnectedPadCount(); ++i)
	{
		_input->AddCommand(i, "left", 1 + i, PAD_INPUT_LEFT);
		_input->AddCommand(i, "right", 1 + i, PAD_INPUT_RIGHT);
		_input->AddCommand(i, "up", 1 + i, PAD_INPUT_UP);
		_input->AddCommand(i, "down", 1 + i, PAD_INPUT_DOWN);
		_input->AddCommand(i, "ok", 1 + i, PAD_INPUT_8);
		_input->AddCommand(i, "pause", 1 + i, PAD_INPUT_7);
		_input->AddCommand(i, "jump", 1 + i, PAD_INPUT_1);
	}
}

void Application::Run()
{
	while (ProcessMessage() == 0)
	{
		ClsDrawScreen();
		_input->Update();
		_sceneMng->Update(*_input);
		ScreenFlip();
	}
}

void Application::Terminate()
{
}

Application::Application()
{
}


Application::~Application()
{
}

Size Application::Configure::GetScreenSize() const
{
	return { default_window_width,default_window_height };
}
