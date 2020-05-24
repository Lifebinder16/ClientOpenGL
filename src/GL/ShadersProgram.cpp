#include "ShadersProgram.h"
#include <iterator>
#include <iostream>
#include <fstream>

GL::ShadersProgram::ShadersProgram(const std::string& name)
{
	mProgram = glCreateProgram();
	// Загрузка двух шейдеров - вершинного и фрагментного
	mVertexShader = loadShader("res/glsl/" + name + ".vert", GL_VERTEX_SHADER);
	mFragmentShader = loadShader("res/glsl/" + name + ".frag", GL_FRAGMENT_SHADER);
}

// Загрузка шейдера из файла с заданным типом
GLuint GL::ShadersProgram::loadShader(const std::string& path, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	// Загрузка кода шейдера из файла
	std::ifstream fis(path);
	std::string shaderCode = { std::istreambuf_iterator<char>(fis), std::istreambuf_iterator<char>() };

	// Экспорт кода шейдера в OpenGL
	const char* ch = shaderCode.c_str();
	// Да, тут всё правильно - передаём указатель на указатель (char**)
	glShaderSource(shader, 1, &ch, nullptr);

	// Получить результат компиляции
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	char buf[0x1000];
	GLsizei len;

	// Если какие-то записи в логе есть, выводим их в консоль
	glGetShaderInfoLog(shader, sizeof(buf), &len, buf);
	if (len > 0) {
		std::cout << "Failed to load shader '" << path << "': " << std::endl;
		std::cout << buf << std::endl;
	}

	return shader;
}

// Линковка шейдеров. Происходит строго после объявления всех атрибутов.
void GL::ShadersProgram::link()
{
	glAttachShader(mProgram, mVertexShader);
	glAttachShader(mProgram, mFragmentShader);
	glLinkProgram(mProgram);
}

// Активация текущей шейдерной программы
void GL::ShadersProgram::use()
{
	glUseProgram(mProgram);
}

void GL::ShadersProgram::bindAttribute(GLuint index, const std::string& name)
{
	glBindAttribLocation(mProgram, index, name.c_str());
}

GL::ShadersProgram::~ShadersProgram()
{
	glDeleteProgram(mProgram);
}