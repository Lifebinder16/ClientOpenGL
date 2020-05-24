#include "Window.h"
#include "../GL/AttachGL.h"
#include "../GL/VAO.h"
#include <stdexcept>

Window::Window(const std::string& title, int width, int height)
{
	mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!mWindow) {
		throw std::runtime_error("Could not initialize window.");
	}
	setContextCurrent();
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		// ������������� �������� ��������� (setContextCurrent) ������ ������ ���� ����� �������������� GLEW !
		throw std::runtime_error("Could not initialize GLEW.");
	}
}

void Window::setContextCurrent()
{
	glfwMakeContextCurrent(mWindow);
}

void Window::loop()
{
	
	// �������������� ������ ������ (VAO)
	GL::VAO vao;

	// ��������� ����������� � ������
	vao.addVertexBufferObject({
			-1.0f, -1.0f, 0.0f,
	 1.0f, -1.0f, 0.0f,
	 0.0f,  1.0f, 0.0f
		});
	
	// ������ �� � �����, ���� ���� ����������
	while (!glfwWindowShouldClose(mWindow)) {
		glClearColor(0.3, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		vao.draw(3);
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}

}

Window::~Window()
{
	glfwDestroyWindow(mWindow);
}