#include "engine.h"
#include "application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "scene.h"

#include "spdlog/spdlog.h"

// This is a workaround for laptops with dual GPUs
#ifdef _WIN32
extern "C" {
    _declspec(dllexport) unsigned long AmdPowerXpressRequestHighPerformance = 0x00000001;
    _declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
#endif

Engine* Engine::instance{ nullptr };

void Engine::InitAll() {
    
}

bool Engine::IsRunning() const{
    glfwPollEvents();
    return !ShouldClose();
}

int Engine::StartWindow() {
    if (application->Init()) {
        return -1;
    }

    return 0;
}

void Engine::Render() {
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
