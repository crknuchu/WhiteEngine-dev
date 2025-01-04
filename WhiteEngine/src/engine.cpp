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

float lastX = 800 / 2.0f;
float lastY = 600 / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void Engine::InitAll() {
	Input::Initialize(application->window);
}

bool Engine::IsRunning() const{
    return !ShouldClose();
}

int Engine::StartWindow() {
    if (application->Init()) {
        return -1;
    }

    return 0;
}

void Engine::Render() {
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;


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

	double xpos, ypos;
	Input::GetMousePosition(xpos, ypos);
	scene->camera.ProcessMouseMovement(xpos, ypos, true);

    application->SwapBuffers();
}

bool Engine::ShouldClose() const{
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
