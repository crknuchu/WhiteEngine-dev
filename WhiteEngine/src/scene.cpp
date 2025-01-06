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
	setCamera(new Camera(glm::vec3(0.0f, 0.0f, 5.0f)));
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

	// set the shader
	shader->Use();

	// set camera view/projection transformations
	shader->setMat4("projection", camera->GetProjectionMatrix(800, 600)); //change 800, 600 to window width and height
	shader->setMat4("view", camera->GetViewMatrix());

	// render the loaded model
	gameobject->draw();
}

void Scene::Update() {
	//gameobject->update();
}

void Scene::setCamera(Camera* camera) {
	this->camera = camera;
}