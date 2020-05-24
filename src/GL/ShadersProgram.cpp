#include "ShadersProgram.h"
#include <iterator>
#include <iostream>
#include <fstream>

GL::ShadersProgram::ShadersProgram(const std::string& name)
{
	mProgram = glCreateProgram();
	// �������� ���� �������� - ���������� � ������������
	mVertexShader = loadShader("res/glsl/" + name + ".vert", GL_VERTEX_SHADER);
	mFragmentShader = loadShader("res/glsl/" + name + ".frag", GL_FRAGMENT_SHADER);
}

// �������� ������� �� ����� � �������� �����
GLuint GL::ShadersProgram::loadShader(const std::string& path, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	// �������� ���� ������� �� �����
	std::ifstream fis(path);
	std::string shaderCode = { std::istreambuf_iterator<char>(fis), std::istreambuf_iterator<char>() };

	// ������� ���� ������� � OpenGL
	const char* ch = shaderCode.c_str();
	// ��, ��� �� ��������� - ������� ��������� �� ��������� (char**)
	glShaderSource(shader, 1, &ch, nullptr);

	// �������� ��������� ����������
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	char buf[0x1000];
	GLsizei len;

	// ���� �����-�� ������ � ���� ����, ������� �� � �������
	glGetShaderInfoLog(shader, sizeof(buf), &len, buf);
	if (len > 0) {
		std::cout << "Failed to load shader '" << path << "': " << std::endl;
		std::cout << buf << std::endl;
	}

	return shader;
}

// �������� ��������. ���������� ������ ����� ���������� ���� ���������.
void GL::ShadersProgram::link()
{
	glAttachShader(mProgram, mVertexShader);
	glAttachShader(mProgram, mFragmentShader);
	glLinkProgram(mProgram);
}

// ��������� ������� ��������� ���������
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