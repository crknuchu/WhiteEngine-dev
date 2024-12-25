#include "engine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>

int main() {

	Engine e;


	e.StartWindow();
	e.InitAll();

	while (e.IsRunning()) {
		e.Render();
	}

	return 0;
}
