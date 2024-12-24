#include "engine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

Engine* Engine::instance{ nullptr };

void Engine::InitAll() {
	
}

bool Engine::IsRunning() {
    glfwPollEvents();

    return !ShouldClose();
}

int Engine::StartWindow() {
    if (application.Init()) {
        return -1;
    }
    
    return 0;
}

void Engine::Render() {
    application.SwapBuffers();
}

bool Engine::ShouldClose()
{
    return glfwWindowShouldClose(application.window) != 0;
}

Engine::Engine()
{
    instance = this;
}

Engine::~Engine()
{
    application.Terminate();
}
