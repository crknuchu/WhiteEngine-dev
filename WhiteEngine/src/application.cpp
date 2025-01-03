#include "application.h"
#include "model.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

#include <iostream>

int Application::Init() {

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (CreateWindow()) {
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    spdlog::info("GL version: {}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    spdlog::info("Device: {}, {}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)), reinterpret_cast<const char*>(glGetString(GL_RENDERER)));

    return 0;
}

int Application::CreateWindow() {

    window = glfwCreateWindow(screenWidth, screenHeight, windowTitle, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, GLFW_FrameBufferSizeCallback);
    
    return 0;
}

void Application::SwapBuffers() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int Application::ShouldClose() {
    return glfwWindowShouldClose(window);
}

void Application::Terminate() {
    glfwTerminate();
}

Application::~Application() {
	Terminate();
}

void Application::GLFW_FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}




