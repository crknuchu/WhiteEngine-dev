#include "application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int Application::Init() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    if (CreateWindow()) {
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    return 0;
}

int Application::CreateWindow() {
    window = glfwCreateWindow(800, 600, "White Engine", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    return 0;
}

void Application::SwapBuffers() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int Application::ShouldClose() {
    return glfwWindowShouldClose(window);
}

void Application::Terminate() {
    glfwTerminate();
}

Application::~Application()
{

}