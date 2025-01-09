#include "assetmanager.h"
#include "model.h"
#include "shader.h"

AssetManager::AssetManager() {
}

AssetManager::~AssetManager() {
}

void AssetManager::LoadShader(const std::string& vertexPath, const std::string& fragmentPath, const std::string& name) {
	std::shared_ptr<Shader> shader = std::make_shared<Shader>(vertexPath.c_str(), fragmentPath.c_str());
	shaders[name] = shader;
}

void AssetManager::LoadModel(const std::string& path, const std::string& name) {
	std::shared_ptr<Model> model = std::make_shared<Model>(path.c_str());
	models[name] = model;
}

std::shared_ptr<Model> AssetManager::GetModel(const std::string& name) {
	return models[name];
}

std::shared_ptr<Shader> AssetManager::GetShader(const std::string& name) {
	return shaders[name];
}