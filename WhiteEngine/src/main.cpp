#include "application.h"

int main() {

	Application a;

	a.Init();

	while (!a.ShouldClose()) {
		a.SwapBuffers();
	}

	a.Terminate();

	return 0;

	/*Engine e;

	e.StartWindow();
	e.InitAll();

	while (e.IsRunning()) {
		e.Render();
	}

	return 0;*/
}
