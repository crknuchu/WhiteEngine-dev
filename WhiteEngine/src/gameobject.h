#pragma once

#include "model.h"
#include "shader.h"

class GameObject {
private:
	Model* model = nullptr;
	Shader* shader = nullptr;
	glm::vec3 position = glm::vec3(0.0f);
	glm::vec3 rotation = glm::vec3(0.0f);
	glm::vec3 scale = glm::vec3(1.0f);
	glm::mat4 modelMatrix = glm::mat4(1.0f);;

public:
	GameObject(Model* model, Shader* shader);
	GameObject();
	~GameObject();

	//GameObject* parent = nullptr; maybe add later?

	void draw();
	void update();

	void setPosition(const glm::vec3& newPosition) { position = newPosition; }
	void setRotation(const glm::vec3& newRotation) { rotation = newRotation; }
	void setScale(const glm::vec3& newScale) { scale = newScale; }

	inline glm::vec3 getPosition() const { return position; }
	inline glm::vec3 getRotation() const { return rotation; }
	inline glm::vec3 getScale() const { return scale; }

	glm::mat4 getModelMatrix() const;
	void setModelMatrix(const glm::mat4& newModelMatrix);
};