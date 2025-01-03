#include "engine.h"
#include "spdlog/spdlog.h"

int main() {
	Engine engine;

	//engine.InitAll();
	spdlog::info("Engine initialized");
	spdlog::info("Engine window started");
	engine.StartWindow();


	spdlog::info("Engine is running");
	while (!engine.ShouldClose()) {
		engine.Render();
	}

	return 0;
}