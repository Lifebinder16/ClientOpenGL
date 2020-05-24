#pragma once
#include <string>
#include "../GL/AttachGL.h"

class Window
{
private:
	GLFWwindow* mWindow;
public:
	Window(const std::string& title, int width, int height);
	void setContextCurrent();
	void loop();
	~Window();
};

