#pragma once

struct GLFWwindow; //why?

class Application {

public:
	GLFWwindow* window{ nullptr };

	int Init();
	void SwapBuffers();
	void Terminate();
	int ShouldClose();

	Application() = default;
	~Application();
private:
	int CreateWindow();
};