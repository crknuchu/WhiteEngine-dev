//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include "stb_image.h"

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>

//#include "shader.h"
//#include "camera.h"

#include <iostream>
#include "engine.h"

int main()
{
	Engine e;

	e.StartWindow();
	e.InitAll();

	while (e.IsRunning())
	{
		e.Render();
	}

	return 0;
}

