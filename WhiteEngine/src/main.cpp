#include "engine.h"
#include "spdlog/spdlog.h"

int main() {
	spdlog::info("© 2024 crknuchu. All rights reserved.");

	Engine engine;

	engine.StartWindow();
	spdlog::info("Window started");

	engine.Initialize();
	spdlog::info("Engine initialized");
	

	spdlog::info("Engine is running");
	while (!engine.ShouldClose()) {
		engine.ProcessKeyboardInput();
		engine.Update();
		engine.Render();
	}

	spdlog::info("Engine is shutting down");

	return 0;
}