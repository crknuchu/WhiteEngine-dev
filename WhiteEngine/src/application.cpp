#include "application.h"
#include "model.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"
#include "stb_image.h"

int Application::Init() {

    if (!glfwInit()) {
		spdlog::error("Failed to initialize GLFW");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (CreateWindow()) {
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		spdlog::error("Failed to initialize GLAD");
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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    LoadIcon();

    return 0;
}

void Application::LoadIcon() {
    int icon_width, icon_height, icon_channels;
    unsigned char* pixels = stbi_load("res/icon.png", &icon_width, &icon_height, &icon_channels, 4);

    GLFWimage images[1];
    images[0].width = icon_width;
    images[0].height = icon_height;
    images[0].pixels = pixels;

    glfwSetWindowIcon(window, 1, images);
}

void Application::SwapBuffers() {
    glfwSwapBuffers(window);
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




