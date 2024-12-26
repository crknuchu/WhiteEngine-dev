#pragma once

class Application;

class Engine {
private:

public:
	static Engine* instance;
	Application* application;

	int StartWindow();
	void InitAll();
	bool IsRunning() const;
	void Render();
	bool ShouldClose() const;
	
	Engine();
	~Engine();
};