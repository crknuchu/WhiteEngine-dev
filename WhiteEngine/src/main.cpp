#include "engine.h"
#include "spdlog/spdlog.h"
#include "scene.h"

int main() {
	Engine engine;

	engine.StartWindow();
	spdlog::info("Window started");

	engine.Initialize();
	spdlog::info("Engine initialized");
	

	spdlog::info("Engine is running");
	while (!engine.ShouldClose()) {
		engine.ProcessInput();
		engine.Update();
		engine.Render();
	}

	spdlog::info("Engine is shutting down");

	return 0;
}