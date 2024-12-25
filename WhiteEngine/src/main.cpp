#include "engine.h"

int main() {

	Engine e;

	e.StartWindow();
	e.InitAll();

	while (e.IsRunning()) {
		e.Render();
	}

	return 0;
}
