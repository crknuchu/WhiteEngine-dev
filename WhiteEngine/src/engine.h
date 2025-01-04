#pragma once

class Application;
class Scene;

class Engine {
private:
	double deltaTime = 0;
	double lastFrame = 0;
public:
	static Engine* instance;
	Application* application;
	Scene* scene{ nullptr };

	int StartWindow();
	void Initialize();
	bool IsRunning() const;
	void Render();
	bool ShouldClose() const;
	Scene& CreateScene();
	void DestroyScene();
	void Update();
	void CalculateDeltaTime();
	void ProcessInput();

	Engine();
	~Engine();
};