#pragma once

#include <vector>

class Model;
class Shader;
class Camera;
class GameObject;

class Scene {
private:
	std::vector<GameObject*> gameobjects;
	Model* model = nullptr; //this need to be replaced with an asset manager
	Shader* shader = nullptr;

public:
	Camera* camera = nullptr;
	//Scene(Camera camera, Model model, Shader shader);
	void Draw();
	void Update();
	Scene();
	~Scene();

	void addGameObject(GameObject* gameobject);
	//void addLight(std::shared_ptr<Light> light);
	void setCamera(Camera* camera);
};