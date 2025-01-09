#pragma once

#include <memory>

class Application;
class Scene;
class GLFWwindow;

class Engine {
private:
	double deltaTime = 0;
	double lastFrame = 0;
public:
	std::unique_ptr<Application> application{ nullptr };
	std::unique_ptr<Scene> scene{ nullptr };

	void CreateWindow();
	void Initialize();
	bool IsRunning() const;
	void Render();
	bool ShouldClose() const;
	void CreateScene();
	void Update();
	void CalculateDeltaTime();
	void ProcessKeyboardInput();

	static void CursorPositionCallback(GLFWwindow* window, double xposIn, double yposIn);

	Engine();
	~Engine();
};