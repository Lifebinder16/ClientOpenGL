#include "Window.h"
#include "../GL/AttachGL.h"
#include "../GL/VAO.h"
#include "../GL/ShadersProgram.h"
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
		// Инициализация текущего контекста (setContextCurrent) всегда должна быть перед инициализацией GLEW !
		throw std::runtime_error("Could not initialize GLEW.");
	}
}

void Window::setContextCurrent()
{
	glfwMakeContextCurrent(mWindow);
}

void Window::loop()
{
	
	// Инициализируем массив вершин (VAO)
	GL::VAO vao;

	// Добавляем треугольник в массив
	vao.addVertexBufferObject({
			-1.0f, -1.0f, 0.0f,
	 1.0f, -1.0f, 0.0f,
	 0.0f,  1.0f, 0.0f
		});

	// Инициализация шейдеров
	GL::ShadersProgram shader("first");
	shader.bindAttribute(0, "position");
	shader.link();
	shader.use();
	
	// Рисуем всё в цикле, пока окно существует
	while (!glfwWindowShouldClose(mWindow)) {
		glClearColor(0, 0, 0, 1); // rgba
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