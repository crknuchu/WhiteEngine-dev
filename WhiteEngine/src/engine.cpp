#include "engine.h"
#include "application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "scene.h"
#include "input.h"

#include "spdlog/spdlog.h"

// This is a workaround for laptops with dual GPUs
#ifdef _WIN32
extern "C" {
	_declspec(dllexport) unsigned long AmdPowerXpressRequestHighPerformance = 0x00000001;
	_declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
#endif

Engine* Engine::instance{ nullptr };

void Engine::Initialize() {
	CreateScene();
	Input::Initialize(application->window);
}

bool Engine::IsRunning() const {
	return !ShouldClose();
}

int Engine::StartWindow() {
	if (application->Init()) {
		return -1;
	}
	return 0;
}

void Engine::Render() {
	scene->Draw();
	application->SwapBuffers();
}

void Engine::Update() {
	CalculateDeltaTime();
	glfwPollEvents();
}

void Engine::CalculateDeltaTime() {
	float currentFrame = static_cast<float>(glfwGetTime());
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void Engine::ProcessInput() {

	if (Input::IsKeyPressed(GLFW_KEY_ESCAPE)) {
		glfwSetWindowShouldClose(application->window, true);
	}

	if (Input::IsKeyPressed(GLFW_KEY_W) == GLFW_PRESS)
		scene->camera.ProcessKeyboard(FORWARD, deltaTime);
	if (Input::IsKeyPressed(GLFW_KEY_S) == GLFW_PRESS)
		scene->camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (Input::IsKeyPressed(GLFW_KEY_A) == GLFW_PRESS)
		scene->camera.ProcessKeyboard(LEFT, deltaTime);
	if (Input::IsKeyPressed(GLFW_KEY_D) == GLFW_PRESS)
		scene->camera.ProcessKeyboard(RIGHT, deltaTime);

	double xpos = 0;
	double ypos = 0;

	Input::GetMousePosition(xpos, ypos);

	//spdlog::info("xpos: {}, ypos: {}", xpos, ypos);
	//spdlog::info("lastX: {}, lastY: {}", scene->camera.lastX, scene->camera.lastY);

	if (scene->camera.firstMouse)
	{
		scene->camera.lastX = xpos;
		scene->camera.lastY = ypos;
		scene->camera.firstMouse = false;
	}

	double xoffset = xpos - scene->camera.lastX;
	double yoffset = scene->camera.lastY - ypos; // reversed since y-coordinates go from bottom to top

	scene->camera.lastX = xpos;
	scene->camera.lastY = ypos;
	
	scene->camera.ProcessMouseMovement(xoffset, yoffset);
	
	//why does the camera jump to a random spot the first time i move the mouse?
	//TODO: fix that
}

bool Engine::ShouldClose() const {
	return glfwWindowShouldClose(application->window) != 0;
}

Scene& Engine::CreateScene()
{
	if (scene != nullptr)
	{
		spdlog::warn("Scene already exists. Destroying old scene..");
		DestroyScene();
	}
	scene = new Scene();

	return *scene;
}

void Engine::DestroyScene()
{
	if (scene != nullptr)
	{
		delete scene;
		scene = nullptr;
	}
}

Engine::Engine() {
	instance = this;
	application = new Application(); // Allocate memory for Application
}

Engine::~Engine() {
	application->Terminate();
	delete application; // Free the allocated memory
}
