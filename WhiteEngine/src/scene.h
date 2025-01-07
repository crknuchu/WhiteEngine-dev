#pragma once

#include <vector>

class Model;
class Shader;
class Camera;
class GameObject;
enum Camera_Movement;

class Scene {
private:
	std::vector<GameObject*> gameobjects;
	Shader* shader = nullptr;

public:
	Camera* camera = nullptr; //this should be private but in engine i call camera to update its location

	void Draw();
	void Update();
	Scene();
	~Scene();

	void addGameObject(GameObject* gameobject);
	//void addLight(std::shared_ptr<Light> light);
	void setCamera(Camera* camera);
};