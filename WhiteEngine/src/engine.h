#pragma once

class Application;

class Engine {
private:

public:
	static Engine* instance;
	Application* application;

	int StartWindow();
	void InitAll();
	bool IsRunning();
	void Render();
	bool ShouldClose();
	
	Engine();
	~Engine();
};