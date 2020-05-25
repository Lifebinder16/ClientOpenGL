#include <iostream>
#include "GLFW/GLFW.h"
#include "GLFW/Window.h"

int main()
{

	try {
		GLFW glfw;
		Window w("Client3D", 800, 600);
		w.loop();
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error occured: " << e.what() << std::endl;
		return -1;
	}

	return 0;

}