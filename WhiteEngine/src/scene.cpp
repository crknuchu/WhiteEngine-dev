#include "scene.h"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"
#include "model.h"
#include "shader.h"
#include "gameobject.h"
#include "spdlog/spdlog.h"

Scene::Scene() {
	camera = new Camera(glm::vec3(0.0f, 0.0f, 5.0f));
	model = new Model("res/models/brick_cube/brick_cube.obj");
	shader = new Shader("res/shaders/vertex.vert", "res/shaders/fragment.frag");
	gameobject = new GameObject(model, shader);
	gameobject->setRotation(glm::vec3(0.0f, 35.0f, 45.0f)); //test rotation
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
	glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)800 / (float)600, 0.1f, 100.0f); //TODO: change 800 and 600 to window width and height
	glm::mat4 view = camera->GetViewMatrix();
	shader->setMat4("projection", projection);
	shader->setMat4("view", view);

	// render the loaded model
	gameobject->draw();
}