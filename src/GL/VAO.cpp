#include "VAO.h"
#include <iostream>

GL::VAO::VAO()
{
	// Генерируем массив вершин
	glGenVertexArrays(1, &mVao);
	// Обязательно сразу связываем его с GL,
	// иначе на видеокартах NVidia получим AV при попытке отрисовать массивы вершин
	bind();
};

void GL::VAO::bind()
{
	glBindVertexArray(mVao);
}

void GL::VAO::draw(GLsizei count)
{

	// Связываем текущий массив вершин с GL
	bind();
	
	// Загружаем в память видеокарты массив атрибутов вершин
	for (size_t i = 0; i < mBuffers.size(); i++) {
		glEnableVertexAttribArray(i);
	}

	// Рисуем
	glDrawArrays(GL_TRIANGLES, 0, count);

	// Выгружаем вершины из памяти
	for (size_t i = 0; i < mBuffers.size(); i++) {
		glDisableVertexAttribArray(i);
	}

}

// 1-компонентный массив
void GL::VAO::addVertexBufferObject(const std::vector<float>& data)
{
	// Создаём в массиве вершин новый объект (треугольник)
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 1, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

// 2-компонентный массив
void GL::VAO::addVertexBufferObject(const std::vector<glm::vec2>& data)
{
	// Создаём в массиве вершин новый объект (треугольник)
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

// 3-компонентный массив
void GL::VAO::addVertexBufferObject(const std::vector<glm::vec3>& data)
{
	// Создаём в массиве вершин новый объект (треугольник)
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

// 4-компонентный массив
void GL::VAO::addVertexBufferObject(const std::vector<glm::vec4>& data)
{
	// Создаём в массиве вершин новый объект (треугольник)
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec4), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

GL::VAO::~VAO()
{
	glDeleteBuffers(mBuffers.size(), mBuffers.data());
	glDeleteVertexArrays(1, &mVao);
};