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

#include <cmath>
#define PI 3.14159265

Scene::Scene() {
	setCamera(new Camera(glm::vec3(0.0f, 0.0f, 15.0f)));
	Model* model = new Model("res/models/brick_cube/brick_cube.obj"); //this need to be replaced with an asset manager
	shader = new Shader("res/shaders/vertex.vert", "res/shaders/fragment.frag");

	unsigned num = 10;
	unsigned radius = 5;
	for (int i = 1; i <= num; ++i) {
		// Calculate the angle for this point
		double angle = 2 * PI * i / num;

		// Calculate the x and y coordinates based on the angle
		double x = 0 + radius * cos(angle);
		double y = 0 + radius * sin(angle);

		GameObject* gameobject = new GameObject(model, shader);
		gameobject->setPosition(glm::vec3(x, y, 0.0f));
		gameobject->setRotation(glm::vec3(0.0f, i * 10.0f, i * 10.0f));
		gameobject->setScale(glm::vec3(i * 0.1f));
		addGameObject(gameobject);
	}
}

void Scene::addGameObject(GameObject* gameobject) {
	gameobjects.push_back(gameobject);
}

Scene::~Scene() {
	delete camera;
	delete shader;
}

void Scene::Draw() {
	// clear teh screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the shader
	shader->Use();

	// set camera view/projection transformations
	shader->setMat4("projection", camera->GetProjectionMatrix(800, 600)); //change 800, 600 to window width and height
	shader->setMat4("view", camera->GetViewMatrix());

	// render gameobjects
	for (auto& gameobject : gameobjects) {
		gameobject->draw();
	}
}

void Scene::Update() {
	/*for (auto& gameobject : gameobjects) {
		gameobject->update();
	}*/
}

void Scene::setCamera(Camera* camera) {
	this->camera = camera;
}