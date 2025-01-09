#pragma once

#include <unordered_map>
#include <memory>
#include <string>

class Model;
class Shader;

class AssetManager {
private:
	//std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
	std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
	std::unordered_map<std::string, std::shared_ptr<Model>> models;
public:
	AssetManager();
	~AssetManager();

	void LoadShader(const std::string& vertexPath, const std::string& fragmentPath, const std::string& name);
	void LoadModel(const std::string& path, const std::string& name);
	
	std::shared_ptr<Shader> GetShader(const std::string& name);
	std::shared_ptr<Model> GetModel(const std::string& name);
};