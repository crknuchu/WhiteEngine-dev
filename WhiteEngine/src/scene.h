#pragma once

#include "camera.h"
#include "model.h"
#include "shader.h"
//#include <vector>


class Scene {
private:
	Camera camera;
	////std::vector<Model> models;
	Model model;
	Shader shader;
	
public:
	//Scene(Camera camera, Model model, Shader shader);
	void Draw();
	Scene();
	~Scene();
};