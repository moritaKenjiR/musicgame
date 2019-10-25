#pragma once
#include <memory>
#include "Geometry.h"
class SceneMng;
class Input;

class Application
{
public:
	~Application();
	static Application& Instance()
	{
		static Application Instance;
		return Instance;
	}
	class Configure {
	public:
		Size GetScreenSize()const;
	};

	bool Initialize();
	void InitializeInput();
	void Run();
	void Terminate();
	
	Configure& GetConfig() { return _config; }
private:
	//生成、コピー、代入禁止
	Application();
	Application(const Application&);
	void operator=(const Application&);

	std::unique_ptr<SceneMng> _sceneMng;
	std::shared_ptr<Input> _input;
	Configure _config;
};

