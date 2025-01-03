#pragma once

struct GLFWwindow;

class Application {

public:
	GLFWwindow* window{ nullptr };
	const unsigned int screenWidth{ 800 };
	const unsigned int screenHeight{ 600 };
	const char* windowTitle{ "White Engine" };

	int Init();
	void SwapBuffers();
	void Terminate();
	int ShouldClose();

	Application() = default;
	~Application();

private:
	int CreateWindow();
	static void GLFW_FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
};