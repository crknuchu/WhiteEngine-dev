#include "engine.h"
#include "application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

Engine* Engine::instance{ nullptr };

void Engine::InitAll() {
    // Initialization code here
}

bool Engine::IsRunning() {
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

bool Engine::ShouldClose() {
    return glfwWindowShouldClose(application->window) != 0;
}

Engine::Engine() {
    instance = this;
    application = new Application(); // Allocate memory for Application
}

Engine::~Engine() {
    application->Terminate();
    delete application; // Free the allocated memory
}
