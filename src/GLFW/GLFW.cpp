#include "GLFW.h"
#include <stdexcept>
#include "../GL/AttachGL.h"

GLFW::GLFW()
{
	if (!glfwInit()) {
		throw std::runtime_error("Could not initialize GLFW.");
	}
}

GLFW::~GLFW()
{
	glfwTerminate();
}