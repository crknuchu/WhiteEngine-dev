#pragma once

//#include <vector>
class Model;
class Shader;
class Camera;
class GameObject;


class Scene {
private:
	
	////std::vector<Model> models;
	Model* model = nullptr;
	Shader* shader = nullptr;
	GameObject* gameobject = nullptr;

public:
	Camera* camera = nullptr;
	//Scene(Camera camera, Model model, Shader shader);
	void Draw();
	Scene();
	~Scene();
};