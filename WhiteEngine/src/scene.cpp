#include "scene.h"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"
#include "model.h"
#include "shader.h"

Scene::Scene() {
	camera = new Camera(glm::vec3(0.0f, 0.0f, 5.0f));
	model = new Model("res/models/brick_cube/brick_cube.obj");
	shader = new Shader("res/shaders/vertex.vert", "res/shaders/fragment.frag");
}

//Scene::Scene(Camera camera, Model model, Shader shader) {
//	camera = camera;
//	model = model;
//	shader = shader;
//}

Scene::~Scene() {
	delete camera;
	delete model;
	delete shader;
}

void Scene::Draw() {
	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->Use();

	// view/projection transformations
	glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)800 / (float)600, 0.1f, 100.0f);
	glm::mat4 view = camera->GetViewMatrix();
	shader->setMat4("projection", projection);
	shader->setMat4("view", view);

	// render the loaded model
	glm::mat4 model1 = glm::mat4(1.0f);
	//model1 = glm::translate(model1, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
	//model1 = glm::scale(model1, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
	shader->setMat4("model", model1);
	model->Draw(*shader);
}