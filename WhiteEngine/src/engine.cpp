#include "engine.h"
#include "application.h"
#include "scene.h"
#include "camera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

// This is a workaround for laptops with dual GPUs
#ifdef _WIN32
extern "C" {
	_declspec(dllexport) unsigned long AmdPowerXpressRequestHighPerformance = 0x00000001;
	_declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
#endif

void Engine::Initialize() {
	CreateWindow();
	CreateScene();
	//this need to be changed
	glfwSetWindowUserPointer(application->window, this);
	glfwSetCursorPosCallback(application->window, CursorPositionCallback);
}

bool Engine::IsRunning() const {
	return !ShouldClose();
}

void Engine::CreateWindow() {
	application = std::make_unique<Application>();
	if (application->Init())
		spdlog::error("Window failed to start");
}

void Engine::Render() {
	scene->Draw();
	application->SwapBuffers();
}

void Engine::Update() {
	CalculateDeltaTime();
	scene->Update(deltaTime);
	glfwPollEvents();
}

void Engine::CalculateDeltaTime() {
	float currentFrame = static_cast<float>(glfwGetTime());
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

bool Engine::ShouldClose() const {
	return glfwWindowShouldClose(application->window) != 0;
}

void Engine::CreateScene()
{
	scene = std::make_unique<Scene>();
}


Engine::Engine() {
	
}

Engine::~Engine() {

}

void Engine::CursorPositionCallback(GLFWwindow* window, double xposIn, double yposIn)
{
	// is there a better way to do this?
	Engine* engine = static_cast<Engine*>(glfwGetWindowUserPointer(window));

	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (engine->scene->camera->firstMouse)
	{
		engine->scene->camera->lastX = xpos;
		engine->scene->camera->lastY = ypos;
		engine->scene->camera->firstMouse = false;
	}

	float xoffset = xpos - engine->scene->camera->lastX;
	float yoffset = engine->scene->camera->lastY - ypos; // reversed since y-coordinates go from bottom to top

	engine->scene->camera->lastX = xpos;
	engine->scene->camera->lastY = ypos;

	engine->scene->camera->ProcessMouseMovement(xoffset, yoffset);
}

void Engine::ProcessKeyboardInput() {

	if (glfwGetKey(application->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(application->window, true);

	if (glfwGetKey(application->window, GLFW_KEY_W) == GLFW_PRESS)
		scene->camera->ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(application->window, GLFW_KEY_S) == GLFW_PRESS)
		scene->camera->ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(application->window, GLFW_KEY_A) == GLFW_PRESS)
		scene->camera->ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(application->window, GLFW_KEY_D) == GLFW_PRESS)
		scene->camera->ProcessKeyboard(RIGHT, deltaTime);
}
