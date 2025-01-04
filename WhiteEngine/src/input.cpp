#include "input.h"
#include "camera.h"
#include "spdlog/spdlog.h"

static std::unordered_map<int, bool> keys;
static std::unordered_map<int, bool> mouse_buttons;
static double mouse_x;
static double mouse_y;

void Input::Initialize(GLFWwindow* window) {
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetMouseButtonCallback(window, MouseButtonCallback);
	glfwSetCursorPosCallback(window, CursorPositionCallback);
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		keys[key] = true;
	}
	else if (action == GLFW_RELEASE) {
		keys[key] = false;
	}
}

void Input::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
	mouse_x = xpos;
	mouse_y = ypos;
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		mouse_buttons[button] = true;
	}
	else if (action == GLFW_RELEASE) {
		mouse_buttons[button] = false;
	}
}

bool Input::IsKeyPressed(int key) {
	return keys[key];
}

bool Input::IsMouseButtonPressed(int button) {
	return mouse_buttons[button];
}

void Input::GetMousePosition(double& xpos, double& ypos) {
	xpos = mouse_x;
	ypos = mouse_y;
}


void Input::test(GLFWwindow* window, float deltaTime, Camera camera) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}


	if (Input::IsKeyPressed(GLFW_KEY_W) == GLFW_PRESS) {
		//spdlog::info("deltatime {}",deltaTime);
		camera.ProcessKeyboard(FORWARD, deltaTime);
	}
		
	if (Input::IsKeyPressed(GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (Input::IsKeyPressed(GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (Input::IsKeyPressed(GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);

	
}