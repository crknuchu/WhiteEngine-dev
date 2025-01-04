#include "engine.h"
#include "spdlog/spdlog.h"
#include "scene.h"

int main() {
	Engine engine;

	engine.StartWindow();
	spdlog::info("Window started");

	engine.InitAll();
	//spdlog::info("Engine initialized");
	
	auto& scene = engine.CreateScene();

	spdlog::info("Engine is running");
	while (!engine.ShouldClose()) {
		engine.Render();
		scene.Draw();
	}

	spdlog::info("Engine is shutting down");

	return 0;
}