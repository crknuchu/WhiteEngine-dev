#pragma once

//#include <vector>
class Model;
class Shader;
class Camera;
class GameObject;


class Scene {
private:
	
	// std::vector<GameObject*> gameobjects;
	Model* model = nullptr;
	Shader* shader = nullptr;
	GameObject* gameobject = nullptr;

public:
	Camera* camera = nullptr;
	//Scene(Camera camera, Model model, Shader shader);
	void Draw();
	void Update();
	Scene();
	~Scene();

	//void addGameObject(std::shared_ptr<GameObject> gameobject);
	//void addLight(std::shared_ptr<Light> light);
	void setCamera(Camera* camera);
};