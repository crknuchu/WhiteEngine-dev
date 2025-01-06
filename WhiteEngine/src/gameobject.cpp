#include "gameobject.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

GameObject::GameObject(Model* model, Shader* shader) {
	modelMatrix = glm::mat4(1.0f);
	this->model = model;
	this->shader = shader;
	position = glm::vec3(0.0f);
	rotation = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);
}

GameObject::GameObject() {
	modelMatrix = glm::mat4(1.0f);
	model = nullptr;
	shader = nullptr;
	position = glm::vec3(0.0f);
	rotation = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);
}

GameObject::~GameObject() {
}

void GameObject::draw() {


	shader->setMat4("model", getModelMatrix());
	model->Draw(*shader);
}

void GameObject::update() {
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	modelMatrix = glm::scale(modelMatrix, scale);
	setModelMatrix(modelMatrix);
}


glm::mat4 GameObject::getModelMatrix() const {
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
	modelMatrix = glm::scale(modelMatrix, scale);
	return modelMatrix;
}

void GameObject::setModelMatrix(const glm::mat4& newModelMatrix) {
	modelMatrix = newModelMatrix;
}