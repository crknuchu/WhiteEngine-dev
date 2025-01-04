#include "GLFW/glfw3.h"
#include <unordered_map>
//class GLFWwindow;


class Input {
public:
    static void Initialize(GLFWwindow* window);
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
    static bool IsKeyPressed(int key);
    static bool IsMouseButtonPressed(int button);
    static void GetMousePosition(double& xpos, double& ypos);
};