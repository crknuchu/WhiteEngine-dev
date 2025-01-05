#pragma once

class Application;
class Scene;
class GLFWwindow;

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
	void CreateScene();
	void DestroyScene();
	void Update();
	void CalculateDeltaTime();
	void ProcessKeyboardInput();

	static void CursorPositionCallback(GLFWwindow* window, double xposIn, double yposIn);

	Engine();
	~Engine();
};