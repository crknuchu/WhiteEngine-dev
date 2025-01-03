#pragma once

class Application;
class Scene;

class Engine {
private:

public:
	static Engine* instance;
	Application* application;
	Scene* scene{ nullptr };

	int StartWindow();
	void InitAll();
	bool IsRunning() const;
	void Render();
	bool ShouldClose() const;
	Scene& CreateScene();
	void DestroyScene();
	
	Engine();
	~Engine();
};