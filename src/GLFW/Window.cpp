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

	// Добавляем треугольник в массив (его вершины)
	vao.addVertexBufferObject({
		{0, 0.5f, 0},
		{-0.5f, -0.5f, 0},
		{0.5f,  -0.5f, 0}
		});

	// Матрица цветов для каждой вершины (r, g, b)
	vao.addVertexBufferObject({
		{1, 0, 0}, // красный
		{0, 1, 0}, // зелёный
		{0, 0, 1}  // синий
		});

	// Инициализация шейдеров
	GL::ShadersProgram shader("first");
	shader.bindAttribute(0, "position");
	shader.bindAttribute(1, "color");
	shader.link();
	shader.use();
	
	// Рисуем всё в цикле, пока окно существует

	float anim = 0.f;

	while (!glfwWindowShouldClose(mWindow)) {

		anim += 0.03;

		// Передаём текущее значение "кадра" как переменную в шейдер
		// только используем синус и подправим его немного, чтобы значения были от 0 до 1.
		// тогда треугольник не будет засвечиваться, а будем именно появляться и исчезать
		shader.setFloat("animation", glm::sin(anim) * 0.5f + 0.5f);

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