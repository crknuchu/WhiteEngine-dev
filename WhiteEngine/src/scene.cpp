#include "scene.h"

#include "camera.h"
#include "model.h"
#include "shader.h"
#include "gameobject.h"
#include "assetmanager.h"

#include "spdlog/spdlog.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <memory>
#include <cmath>

const float PI = 3.14159265;
int index = 0;
float cx = 0.0f;
float cy = 0.0f;
float rotationSpeed = 10.0f;
float angle = 0.0f;

void rotatePoint(float& x, float& y, float cx, float cy, float theta) {
	// Translate point to origin
	float translatedX = x - cx;
	float translatedY = y - cy;

	// Rotate point
	float rotatedX = translatedX * cos(theta) - translatedY * sin(theta);
	float rotatedY = translatedX * sin(theta) + translatedY * cos(theta);

	// Translate point back
	x = rotatedX + cx;
	y = rotatedY + cy;
}

Scene::Scene() {
	AssetManager assetManager;
	assetManager.LoadModel("res/models/brick_cube/brick_cube.obj", "brick_cube");
	assetManager.LoadShader("res/shaders/vertex.vert", "res/shaders/fragment.frag", "shader");

	setCamera(new Camera(glm::vec3(0.0f, 0.0f, 15.0f)));

	sceneShader = assetManager.GetShader("shader");

	unsigned num = 10;
	unsigned radius = 5;
	for (int i = 1; i <= num; ++i) {
		// Calculate the angle for this point
		double angle = 2 * PI * i / num;

		// Calculate the x and y coordinates based on the angle
		double x = 0 + radius * cos(angle);
		double y = 0 + radius * sin(angle);

		GameObject* gameobject = new GameObject(assetManager.GetModel("brick_cube"), assetManager.GetShader("shader"));
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
}

void Scene::Draw() {
	// clear teh screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the shader
	sceneShader->Use();

	// set camera view/projection transformations
	sceneShader->setMat4("projection", camera->GetProjectionMatrix(800, 600)); //change 800, 600 to window width and height
	sceneShader->setMat4("view", camera->GetViewMatrix());

	// render gameobjects
	for (auto& gameobject : gameobjects) {
		gameobject->draw();
	}
}

void Scene::Update(double deltaTime) {
		angle = rotationSpeed * deltaTime;

		// Convert angle to radians
		float theta = angle * PI / 180.0f;

		// Update positions of all rectangles
		for (auto& gameobject : gameobjects) {
			glm::vec3 position = gameobject->getPosition();
			rotatePoint(position.x, position.y, cx, cy, theta);
			gameobject->setPosition(position);
			//rectangle.setRotation(angle);
		}
}

void Scene::setCamera(Camera* camera) {
	this->camera = camera;
}